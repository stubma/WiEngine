-- 脚本的输入参数
-- layer, 是wyLayer对象
-- callback, 是动画回调结构指针

-- create sprite
local sprite = wySprite:make(wyTexture2D:makePNG(wyUtils:getResId("R.drawable.grossini")))
sprite:setPosition(wyDevice.winWidth / 2, wyDevice.winHeight / 2)
layer:addChildLocked(sprite)

-- 创建一个提示label, 这个label是全局变量, 之后会被C++端代码获得
hint = wyLabel:make("callback display label", wyUtils:resolveSp(20))
hint:setPosition(wyDevice.winWidth / 2, 100);
layer:addChildLocked(hint);

-- create animation
local animation = wyAnimation:make(0)
animation:addFrame(0.2, wyTexture2D:makePNG(wyUtils:getResId("R.drawable.grossini_dance_01")))
animation:addFrame(0.2, wyTexture2D:makePNG(wyUtils:getResId("R.drawable.grossini_dance_02")))
animation:addFrame(0.2, wyTexture2D:makePNG(wyUtils:getResId("R.drawable.grossini_dance_03")))
animation:addFrame(0.2, wyTexture2D:makePNG(wyUtils:getResId("R.drawable.grossini_dance_04")))
animation:addFrame(0.2, wyTexture2D:makePNG(wyUtils:getResId("R.drawable.grossini_dance_05")))
animation:addFrame(0.2, wyTexture2D:makePNG(wyUtils:getResId("R.drawable.grossini_dance_06")))
animation:addFrame(0.2, wyTexture2D:makePNG(wyUtils:getResId("R.drawable.grossini_dance_07")))
animation:addFrame(0.2, wyTexture2D:makePNG(wyUtils:getResId("R.drawable.grossini_dance_08")))
animation:addFrame(0.2, wyTexture2D:makePNG(wyUtils:getResId("R.drawable.grossini_dance_09")))
animation:addFrame(0.2, wyTexture2D:makePNG(wyUtils:getResId("R.drawable.grossini_dance_10")))
animation:addFrame(0.2, wyTexture2D:makePNG(wyUtils:getResId("R.drawable.grossini_dance_11")))
animation:addFrame(0.2, wyTexture2D:makePNG(wyUtils:getResId("R.drawable.grossini_dance_12")))
animation:addFrame(0.2, wyTexture2D:makePNG(wyUtils:getResId("R.drawable.grossini_dance_13")))
animation:addFrame(0.2, wyTexture2D:makePNG(wyUtils:getResId("R.drawable.grossini_dance_14")))

-- set animation callback
animation:setCallback(callback, nil)

-- create animate
local animate = wyAnimate:make(animation)

-- run action
sprite:runAction(animate)