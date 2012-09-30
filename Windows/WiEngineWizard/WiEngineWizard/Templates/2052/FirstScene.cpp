#include "stdafx.h"

FirstScene::FirstScene() {    
    wyLabel* label = wyLabel::make("Welcome to WiEngine", SP(20), BOLD, WY_DEFAULT_FONT);
    label->setPosition(wyDevice::winWidth / 2, wyDevice::winHeight / 2);
    addChildLocked(label);
}

FirstScene::~FirstScene() {
}
