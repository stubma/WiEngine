/**
 * OpenAL cross platform audio library
 * Copyright (C) 2010 by Chris Robinson
 * This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Library General Public
 *  License as published by the Free Software Foundation; either
 *  version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 *  License along with this library; if not, write to the
 *  Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 *  Boston, MA  02111-1307, USA.
 * Or go to http://www.gnu.org/copyleft/lgpl.html
 */

#if ANDROID

#include "config.h"
#include <stdlib.h>
#include <stdbool.h>
#include <jni.h>
#include <pthread.h>
#include "alMain.h"
#include "AL/al.h"
#include "AL/alc.h"
#include "wyLog.h"

static const ALCchar android_device[] = "Android Default";

extern JavaVM* gVM;
extern JNIEnv* getEnv();

static int s_bufferSizeInSamples;
static int s_bufferSizeInBytes;

static jclass jclass_Director = NULL;
static jclass jclass_AudioManager = NULL;
static jobject jobject_Looper = NULL;
static jmethodID jmethodID_Looper_quit;
static jobject jobject_AudioTrack = NULL;
static jmethodID jmethodID_AudioTrack_write;
static jarray jarray_Buffer = NULL;
static pthread_t s_thread = 0;
static ALCdevice* s_device = NULL;

#define STREAM_MUSIC 3
#define CHANNEL_CONFIGURATION_MONO 2
#define CHANNEL_CONFIGURATION_STEREO 3
#define ENCODING_PCM_8BIT 3
#define ENCODING_PCM_16BIT 2
#define MODE_STREAM 1

void onWiSoundPeriodicNotification() {
	if(jobject_AudioTrack && s_device) {
		JNIEnv* env = getEnv();
		void* buffer = (*env)->GetPrimitiveArrayCritical(env, jarray_Buffer, NULL);
		aluMixData(s_device, buffer, s_bufferSizeInSamples);
		(*env)->ReleasePrimitiveArrayCritical(env, jarray_Buffer, buffer, 0);
		(*env)->CallIntMethod(env, jobject_AudioTrack, jmethodID_AudioTrack_write, jarray_Buffer, 0, s_bufferSizeInBytes);
	}
}

static void* thread_function(void* arg) {
	JNIEnv* env = getEnv();

	// get device
	ALCdevice* device = (ALCdevice*)arg;
	s_device = device;

	// prepare loop
	jclass jclass_Looper = (*env)->FindClass(env, "android/os/Looper");
	jmethodID jmethodID_Looper_prepare = (*env)->GetStaticMethodID(env, jclass_Looper, "prepare", "()V");
	jmethodID jmethodID_Looper_myLooper = (*env)->GetStaticMethodID(env, jclass_Looper, "myLooper", "()Landroid/os/Looper;");
	jmethodID jmethodID_Looper_loop = (*env)->GetStaticMethodID(env, jclass_Looper, "loop", "()V");
	jmethodID_Looper_quit = (*env)->GetMethodID(env, jclass_Looper, "quit", "()V");
	(*env)->CallStaticVoidMethod(env, jclass_Looper, jmethodID_Looper_prepare);
	jobject_Looper = (*env)->CallStaticObjectMethod(env, jclass_Looper, jmethodID_Looper_myLooper);

	// init audio track
	jclass jclass_AudioTrack = (*env)->FindClass(env, "android/media/AudioTrack");
	jmethodID jmethodID_AudioTrack_init = (*env)->GetMethodID(env, jclass_AudioTrack, "<init>", "(IIIIII)V");
	jmethodID jmethodID_AudioTrack_getMinBufferSize = (*env)->GetStaticMethodID(env, jclass_AudioTrack, "getMinBufferSize", "(III)I");
	jmethodID jmethodID_AudioTrack_play = (*env)->GetMethodID(env, jclass_AudioTrack, "play", "()V");
	jmethodID jmethodID_AudioTrack_stop = (*env)->GetMethodID(env, jclass_AudioTrack, "stop", "()V");
	jmethodID jmethodID_AudioTrack_release = (*env)->GetMethodID(env, jclass_AudioTrack, "release", "()V");
	jmethodID_AudioTrack_write = (*env)->GetMethodID(env, jclass_AudioTrack, "write", "([BII)I");
	jmethodID jmethodID_AudioTrack_setPositionNotificationPeriod = (*env)->GetMethodID(env, jclass_AudioTrack, "setPositionNotificationPeriod", "(I)I");
	jmethodID jmethodID_AudioTrack_setPlaybackPositionUpdateListener = (*env)->GetMethodID(env, jclass_AudioTrack, "setPlaybackPositionUpdateListener", "(Landroid/media/AudioTrack$OnPlaybackPositionUpdateListener;)V");

	// init audio manager
	jmethodID jmethodID_AudioManager_init = (*env)->GetMethodID(env, jclass_AudioManager, "<init>", "()V");

	// create audio track
	int sampleRateInHz = device->Frequency;
	int channelConfig = ChannelsFromDevFmt(device->FmtChans) == 1 ? CHANNEL_CONFIGURATION_MONO : CHANNEL_CONFIGURATION_STEREO;
	int audioFormat = BytesFromDevFmt(device->FmtType) == 1 ? ENCODING_PCM_8BIT : ENCODING_PCM_16BIT;
	s_bufferSizeInBytes = (*env)->CallStaticIntMethod(env, jclass_AudioTrack, jmethodID_AudioTrack_getMinBufferSize, sampleRateInHz, channelConfig, audioFormat);
	s_bufferSizeInSamples = s_bufferSizeInBytes / FrameSizeFromDevFmt(device->FmtChans, device->FmtType);
	jobject_AudioTrack = (*env)->NewObject(env, jclass_AudioTrack, jmethodID_AudioTrack_init,
			STREAM_MUSIC, sampleRateInHz, channelConfig, audioFormat, s_bufferSizeInBytes, MODE_STREAM);

	// create audio manager which implements position listener
	jobject jobject_AudioManager = (*env)->NewObject(env, jclass_AudioManager, jmethodID_AudioManager_init);

	// set period notification
	(*env)->CallVoidMethod(env, jobject_AudioTrack, jmethodID_AudioTrack_setPositionNotificationPeriod, s_bufferSizeInBytes / 8);
	(*env)->CallVoidMethod(env, jobject_AudioTrack, jmethodID_AudioTrack_setPlaybackPositionUpdateListener, jobject_AudioManager);

	// create buffer
	jarray_Buffer = (*env)->NewByteArray(env, s_bufferSizeInBytes);

	// play
	(*env)->CallVoidMethod(env, jobject_AudioTrack, jmethodID_AudioTrack_play);

	// write init data so that audio track will star to play and trigger notification
	onWiSoundPeriodicNotification();

	// loop
	(*env)->CallStaticVoidMethod(env, jclass_Looper, jmethodID_Looper_loop);

	// release audio track
    (*env)->CallVoidMethod(env, jobject_AudioTrack, jmethodID_AudioTrack_stop);
    (*env)->CallVoidMethod(env, jobject_AudioTrack, jmethodID_AudioTrack_release);
	jobject_AudioTrack = NULL;

	// nullify device
	s_device = NULL;

	detachEnv();
}

static ALCboolean android_open_playback(ALCdevice *device, const ALCchar *deviceName) {
    // check device name
    if (!deviceName)
        deviceName = android_device;
    else if (strcmp(deviceName, android_device) != 0)
        return ALC_FALSE;

	// create extra data
    device->szDeviceName = strdup(deviceName);

    // load some class, can't do it in sub thread
    JNIEnv* env = getEnv();
    if(!jclass_Director) {
		jclass_Director = (*env)->FindClass(env, "com/wiyun/engine/nodes/Director");
		jclass_Director = (*env)->NewGlobalRef(env, jclass_Director);
    }
    if(!jclass_AudioManager) {
    	jclass_AudioManager = (*env)->FindClass(env, "com/wiyun/engine/sound/AudioManager");
    	jclass_AudioManager = (*env)->NewGlobalRef(env, jclass_AudioManager);
    }

    return ALC_TRUE;
}

static void android_close_playback(ALCdevice *device) {
    JNIEnv* env = getEnv();

    if(jclass_Director) {
    	(*env)->DeleteGlobalRef(env, jclass_Director);
    	jclass_Director = NULL;
    }
    if(jclass_AudioManager) {
    	(*env)->DeleteGlobalRef(env, jclass_AudioManager);
    	jclass_AudioManager = NULL;
    }
}

static ALCboolean android_reset_playback(ALCdevice *device) {
    SetDefaultWFXChannelOrder(device);
    pthread_create(&s_thread, NULL, thread_function, device);

    return ALC_TRUE;
}

static void android_stop_playback(ALCdevice *device) {
    if(s_thread != 0 && jobject_Looper) {
    	JNIEnv* env = getEnv();
    	(*env)->CallVoidMethod(env, jobject_Looper, jmethodID_Looper_quit);
        pthread_join(s_thread, NULL);
        s_thread = 0;
        jobject_Looper = NULL;
    }
}

static const BackendFuncs android_funcs = {
    android_open_playback,
    android_close_playback,
    android_reset_playback,
    android_stop_playback,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL
};

void alc_android_init(BackendFuncs *func_list) {
    *func_list = android_funcs;
}

void alc_android_deinit(void) {
}

void alc_android_probe(int type) {
    if (type == DEVICE_PROBE)
        AppendDeviceList(android_device);
    else if (type == ALL_DEVICE_PROBE)
        AppendAllDeviceList(android_device);
}

#endif // #if ANDROID