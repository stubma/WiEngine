function allwords ()
  local pos = 1           -- current position in the line
  return function ()      -- iterator function
    while line do         -- repeat while there are lines
      local s, e = string.find(line, "%w+", pos)
      if s then           -- found a word?
        pos = e + 1       -- next position is after this word
        return string.sub(line, s, e)     -- return the word
      else
        break
      end
    end
    return nil            -- no more lines: end of traversal
  end
end

-- split words and combine
local words = ""
for word in allwords() do
	if words == "" then
		words = word
	else
		words = words .. "\n" .. word
	end
end

-- output to a label
local font = wyBitmapFont:loadFont(wyUtils:getResId("R.raw.bitmapfont"), BFF_HGE)
local label = wyBitmapFontLabel:make(font, words)
label:setPosition(wyDevice.winWidth / 2, wyDevice.winHeight / 2)
label:setColor(wyc3b(0, 255, 0))
layer:addChildLocked(label)