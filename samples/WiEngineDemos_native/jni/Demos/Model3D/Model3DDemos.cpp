#include "Model3DDemos.h"
#include "common.h"
#include "WiEngine.h"
#include <stdio.h>

namespace Lua {
    class wyPODTestLayer : public wyLayer {
    public:
    	wyPODTestLayer() {
            wyModel* model = wyPODModel::make(RES("R.raw.scene"));
            wyModelNode* n = wyModelNode::make(model);
            addChildLocked(n);
            
            // dump info
            n->getModel()->dump();
        }

        virtual ~wyPODTestLayer() {
        }
    };
}

using namespace Lua;

DEMO_ENTRY_IMPL(model3d, PODTest);
