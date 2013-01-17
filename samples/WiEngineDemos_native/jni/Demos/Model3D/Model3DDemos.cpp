#include "Model3DDemos.h"
#include "common.h"
#include "WiEngine.h"
#include <stdio.h>
#include "PVRTModelPOD.h"

namespace Lua {
    class wyPODTestLayer : public wyLayer {
    public:
    	wyPODTestLayer() {
            CPVRTModelPOD pod;
            size_t len;
            char* raw = wyUtils::loadRaw(RES("R.raw.scene"), &len);
            pod.ReadFromMemory(raw, len);
            wyFree(raw);
            if(pod.IsLoaded()) {
                LOGD("mesh: %d, material: %d, texture: %d, light: %d", pod.nNumMesh, pod.nNumMaterial, pod.nNumTexture, pod.nNumLight);
            }
        }

        virtual ~wyPODTestLayer() {
        }
    };
}

using namespace Lua;

DEMO_ENTRY_IMPL(model3d, PODTest);
