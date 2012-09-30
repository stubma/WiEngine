-- layer由wyLua::setGlobal传入
layer = _G["layer"]

-- 创建button的sprite
normal = wySprite:make(wyTexture2D:makePNG(wyUtils:getResId("R.drawable.btn_send_score_normal")))
pressed = wySprite:make(wyTexture2D:makePNG(wyUtils:getResId("R.drawable.btn_send_score_pressed")))

-- 创建wyTargetSelector, layer就是我们的事件处理对象
ts = wyTargetSelector:make_v(layer, 1)

-- 创建button
button = wyButton:make(normal, pressed, nil, nil, nil, ts)

-- 放置到屏幕中央
button:setPosition(wyDevice.winWidth / 2, wyDevice.winHeight / 2)
layer:addChildLocked(button)