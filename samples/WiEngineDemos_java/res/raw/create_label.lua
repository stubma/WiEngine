-- 创建一个label
local label = wyLabel:make("Hello World", wyUtils:resolveSp(30))

-- 设置label到屏幕中间, 注意成员的引用是wyDevice.winWidth, 不是wyDevice.winWidth, 比较容易搞错
label:setPosition(wyDevice.winWidth / 2, wyDevice.winHeight / 2)

-- layer由wyLua::setGlobal传入
-- 添加到layer中
layer:addChildLocked(label)