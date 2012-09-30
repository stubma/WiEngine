//
//  FirstScene.cpp
//  ___PROJECTNAME___
//
//  Created by ___FULLUSERNAME___ on ___DATE___.
//  Copyright ___YEAR___ ___ORGANIZATIONNAME___. All rights reserved.
//

#include "FirstScene.h"
#include "WiEngine.h"

FirstScene::FirstScene() {    
    wyLabel* label = wyLabel::make("Welcome to WiEngine", SP(20), BOLD, WY_DEFAULT_FONT);
    label->setPosition(wyDevice::winWidth / 2, wyDevice::winHeight / 2);
    addChildLocked(label);
}

FirstScene::~FirstScene() {
}