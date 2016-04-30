Graphics.openScreen(640, 480)

dofile("rectdrawable.lua")

function createStarField() 
	local starField = {
		stars = {},
		init = function(self)
			for i = 0, 100 do
				self.stars[i] = newRect()
				self.stars[i]:w(4)
				self.stars[i]:h(4)
				self.stars[i]:colour(0xffffffff)
				self.stars[i]:x(math.random(640)-2)
				self.stars[i]:y(math.random(480)-2)
			end
		end,

		update = function(self)
			for _, star in ipairs(self.stars) do
				star:draw()
			end
		end
	}
	starField:init()
	return starField
end

local blockEntity = newRect()
blockEntity:w(25)
blockEntity:h(25)
blockEntity:colour(0x88ff8800)

local bg = newRect()
bg:w(Graphics.width())
bg:h(Graphics.height())
bg:colour(0x0088ffff)

local starField = createStarField()

function update()
	bg:draw()

	starField:update()
	blockEntity:x(Input.mouseX()-12)
	blockEntity:y(Input.mouseY()-12)

	if(Input.mouseButton() == 1) then
		blockEntity:colour(0x88ff0088)
	else
		blockEntity:colour(0x88ff8888)
	end

	blockEntity:draw()

end

