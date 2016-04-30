
function createPerpetualMover(startX, startY, xstep, ystep, maxX, maxY)
	return {
		_x = startX,
		_y = startY,
		update = function(self)
			self._x = self._x + xstep
			self._y = self._y + ystep

			if (self._y > maxY) then
				self._y = 0
			end
			if (self._x > maxX) then
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
