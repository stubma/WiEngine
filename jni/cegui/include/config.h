/* cegui/include/config.h.  Generated from config.h.in by configure.  */
/* cegui/include/config.h.in.  Generated from configure.ac by autoheader.  */

/* Define to enable bidirectional text support in CEGUI */
/* #undef CEGUI_BIDI_SUPPORT */

/* Defines the suffix appended to output binaries. */
/* #undef CEGUI_BUILD_SUFFIX */

/* Set this to the default ImageCodec to be used (CoronaImageCodec,
   DevILImageCodec FreeImageImageCode, SILLYImageCodec, TGAImageCodec,
   STBImageCodec). */
#define CEGUI_DEFAULT_IMAGE_CODEC WiEngineImageCodec

/* Set this to the default XMLParser to be used (XercesParser, ExpatParser,
   LibxmlParser or TinyXMLParser). */
#define CEGUI_DEFAULT_XMLPARSER ExpatParser

/* Define if output names have an added suffix. */
/* #undef CEGUI_HAS_BUILD_SUFFIX */

/* Define to enable possible use of CEGUI::DefaultLogger. */
#define CEGUI_HAS_DEFAULT_LOGGER /**/

/* Define to enable freetype 2 font support in CEGUI */
#define CEGUI_HAS_FREETYPE /**/

/* Defined when the resource provider with minizip support is built. */
/* #undef CEGUI_HAS_MINIZIP_RESOURCE_PROVIDER */

/* Define to enable PCRE regular expression support in CEGUI */
/* #undef CEGUI_HAS_PCRE_REGEX */

/* Define if shared libraries have a version suffix. */
#define CEGUI_HAS_VERSION_SUFFIX /**/

/* Defines irrlicht SDK version. 14 is 1.4 or 1.5.x and 16 is 1.6 or later. */
/* #undef CEGUI_IRR_SDK_VERSION */

/* Define if your OIS uses the older numKeyboards like APIs rather than the
   newer getNumberOfDevices API */
/* #undef CEGUI_OLD_OIS_API */

/* Define to have the DirectFB CEGUI renderer available in the samples */
/* #undef CEGUI_SAMPLES_USE_DIRECTFB */

/* Define to have a GTK2 based dialog used for renderer selection in the
   samples */
/* #undef CEGUI_SAMPLES_USE_GTK2 */

/* Define to have the Irrlicht CEGUI renderer available in the samples */
/* #undef CEGUI_SAMPLES_USE_IRRLICHT */

/* Define to have the Ogre renderer available in the samples */
/* #undef CEGUI_SAMPLES_USE_OGRE */

/* Define to have the OpenGL CEGUI renderer available in the samples (requires
   glut) */
/* #undef CEGUI_SAMPLES_USE_OPENGL */

/* Set this to the name of the tinyxml.h file */
#define CEGUI_TINYXML_H "ceguitinyxml/tinyxml.h"

/* Set this if your tiny xml version is 2.6 or higher */
/* #undef CEGUI_TINYXML_HAS_2_6_API */

/* Set this to the name of the tinyxml namespace */
#define CEGUI_TINYXML_NAMESPACE CEGUITinyXML

/* Define to use external fribidi lib. */
/* #undef CEGUI_USE_FRIBIDI */

/* Define to use embedded minibidi lib. */
/* #undef CEGUI_USE_MINIBIDI */

/* Defines the shared library version suffix. */
#define CEGUI_VERSION_SUFFIX "0.7.7"

/* Define to 1 if you have the `alarm' function. */
#define HAVE_ALARM 1

/* Define to 1 if you have the `atexit' function. */
#define HAVE_ATEXIT 1

/* define if the Boost::Python library is available */
/* #undef HAVE_BOOST_PYTHON */

/* Define to 1 if you have the <dlfcn.h> header file. */
#define HAVE_DLFCN_H 1

/* Define to 1 if you have the `floor' function. */
#define HAVE_FLOOR 1

/* Define to 1 if you have the <inttypes.h> header file. */
#define HAVE_INTTYPES_H 1

/* Define to 1 if you have the `dl' library (-ldl). */
#define HAVE_LIBDL 1

/* Define to 1 if you have the `pthread' library (-lpthread). */
#define HAVE_LIBPTHREAD 1

/* Define to 1 if you have the <limits.h> header file. */
#define HAVE_LIMITS_H 1

/* Define to 1 if you have the <locale.h> header file. */
#define HAVE_LOCALE_H 1

/* Define to 1 if you have the <malloc.h> header file. */
/* #undef HAVE_MALLOC_H */

/* Define to 1 if you have the `memchr' function. */
#define HAVE_MEMCHR 1

/* Define to 1 if you have the `memmove' function. */
#define HAVE_MEMMOVE 1

/* Define to 1 if you have the <memory.h> header file. */
#define HAVE_MEMORY_H 1

/* Define to 1 if you have the `memset' function. */
#define HAVE_MEMSET 1

/* Define to 1 if you have the `pow' function. */
#define HAVE_POW 1

/* Define to 1 if the system has the type `ptrdiff_t'. */
#define HAVE_PTRDIFF_T 1

/* Define to 1 if you have the <Python.h> header file. */
#define HAVE_PYTHON_H 1

/* Define to 1 if you have the `regcomp' function. */
#define HAVE_REGCOMP 1

/* Define to 1 if you have the `setlocale' function. */
#define HAVE_SETLOCALE 1

/* Define to 1 if you have the `sqrt' function. */
#define HAVE_SQRT 1

/* Define to 1 if stdbool.h conforms to C99. */
#define HAVE_STDBOOL_H 1

/* Define to 1 if you have the <stddef.h> header file. */
#define HAVE_STDDEF_H 1

/* Define to 1 if you have the <stdint.h> header file. */
#define HAVE_STDINT_H 1

/* Define to 1 if you have the <stdlib.h> header file. */
#define HAVE_STDLIB_H 1

/* Define to 1 if you have the `strchr' function. */
#define HAVE_STRCHR 1

/* Define to 1 if you have the `strcoll' function and it is properly defined.
   */
#define HAVE_STRCOLL 1

/* Define to 1 if you have the `strcspn' function. */
#define HAVE_STRCSPN 1

/* Define to 1 if you have the `strerror' function. */
#define HAVE_STRERROR 1

/* Define to 1 if you have the `strftime' function. */
#define HAVE_STRFTIME 1

/* Define to 1 if you have the <strings.h> header file. */
#define HAVE_STRINGS_H 1

/* Define to 1 if you have the <string.h> header file. */
#define HAVE_STRING_H 1

/* Define to 1 if you have the `strpbrk' function. */
#define HAVE_STRPBRK 1

/* Define to 1 if you have the `strtoul' function. */
#define HAVE_STRTOUL 1

/* Define to 1 if you have the <sys/stat.h> header file. */
#define HAVE_SYS_STAT_H 1

/* Define to 1 if you have the <sys/time.h> header file. */
#define HAVE_SYS_TIME_H 1

/* Define to 1 if you have the <sys/types.h> header file. */
#define HAVE_SYS_TYPES_H 1

/* Define to 1 if you have the <unistd.h> header file. */
#define HAVE_UNISTD_H 1

/* zlib is available */
/* #undef HAVE_ZLIB */

/* Define to 1 if the system has the type `_Bool'. */
#define HAVE__BOOL 1

/* Define to the sub-directory in which libtool stores uninstalled libraries.
   */
#define LT_OBJDIR ".libs/"

/* Name of package */
#define PACKAGE "CEGUI"

/* Define to the address where bug reports for this package should be sent. */
#define PACKAGE_BUGREPORT "http://mantis.cegui.org.uk/"

/* Define to the full name of this package. */
#define PACKAGE_NAME "CEGUI"

/* Define to the full name and version of this package. */
#define PACKAGE_STRING "CEGUI 0.7.7"

/* Define to the one symbol short name of this package. */
#define PACKAGE_TARNAME "CEGUI"

/* Define to the home page for this package. */
#define PACKAGE_URL ""

/* Define to the version of this package. */
#define PACKAGE_VERSION "0.7.7"

/* Define to 1 if you have the ANSI C header files. */
#define STDC_HEADERS 1

/* Define to 1 if you can safely include both <sys/time.h> and <time.h>. */
#define TIME_WITH_SYS_TIME 1

/* Define to 1 if your <sys/time.h> declares `struct tm'. */
/* #undef TM_IN_SYS_TIME */

/* Version number of package */
#define VERSION "0.7.7"

/* Define to 1 if the X Window System is missing or not being used. */
#define X_DISPLAY_MISSING 1

/* Define to empty if `const' does not conform to ANSI C. */
/* #undef const */

/* Define to `__inline__' or `__inline' if that's what the C compiler
   calls it, or to nothing if 'inline' is not supported under any name.  */
#ifndef __cplusplus
/* #undef inline */
#endif

/* Define to `unsigned int' if <sys/types.h> does not define. */
/* #undef size_t */

/* Define to empty if the keyword `volatile' does not work. Warning: valid
   code using `volatile' can become incorrect without. Disable with care. */
/* #undef volatile */
