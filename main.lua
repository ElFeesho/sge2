Graphics.openScreen(640, 480)

dofile("sgelib/rectdrawable.lua")
dofile("sgelib/actor.lua")
dofile("sgelib/perpetualmover.lua")
dofile("sgelib/mousefollowingmover.lua")

function createStar(startX, startY, depth)
	starDrawable = newRect(startX, startY, depth, depth, 0xffffffff)
	mover = createPerpetualMover(startX, startY, 0, 0.1 * depth, 640, 480)	
	return createActor(starDrawable, mover)
end

function createStarField() 
	local starField = {
		stars = {},
		init = function(self)
			for i = 0, 100 do
				self.stars[i] = createStar(math.random(640)-2, math.random(480)-2, math.random(1, 3))
			end
		end,

		update = function(self)
			for _, star in ipairs(self.stars) do
				star:update()
				star:draw()
			end
		end
	}
	starField:init()
	return starField
end

function createShip()
	return createActor(newRect(0, 0, 25, 25, 0xff0000ff), createMouseFollowingMover(12.5, 12.5))
end

local ship = createShip()

local bg = newRect(0, 0, Graphics.width(), Graphics.height(), 0x000000ff)

local starField = createStarField()

function update()
	bg:draw()

	starField:update()

	ship:update()
	ship:draw()

end

