Graphics.openScreen(640, 480)

dofile("rectdrawable.lua")

function createPerpetualMover(startX, startY, xstep, ystep)
	return {
		_x = startX,
		_y = startY,
		update = function(self)
			self._x = self._x + xstep
			self._y = self._y + ystep

			if (self._y > 480) then
				self._y = 0
			end
			if (self._x > 640) then
				self._x = 0
			end
		end,

		x = function(self)
			return self._x
		end,

		y = function(self)
			return self._y
		end
	}
end

function createActor(actorDrawable, actorMover)
	actor = {
		drawable = actorDrawable,
		mover = actorMover,

		update = function(self)
			self.mover:update()
			self.drawable:x(self.mover:x())
			self.drawable:y(self.mover:y())
		end,

		draw = function(self)
			self.drawable:draw()
		end
	}
	return actor
end

function createStar(startX, startY, depth)
	starDrawable = newRect()
	starDrawable:x(startX)
	starDrawable:y(startY)
	starDrawable:colour(0xffffffff)
	starDrawable:w(depth)
	starDrawable:h(depth)
	mover = createPerpetualMover(startX, startY, 0, 0.1 * depth)	
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

local blockEntity = newRect()
blockEntity:w(25)
blockEntity:h(25)
blockEntity:colour(0x88ff8800)

local bg = newRect()
bg:w(Graphics.width())
bg:h(Graphics.height())
bg:colour(0x000000ff)

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

