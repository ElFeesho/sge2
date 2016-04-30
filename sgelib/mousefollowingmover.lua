function createMouseFollowingMover(offsetX, offsetY)
	return {
		_x = Input.mouseX(),
		_y = Input.mouseY(),

		update = function(self)
			self._x = self._x + (Input:mouseX()-self._x)/32
			self._y = self._y + (Input:mouseY()-self._y)/32
		end,

		x = function(self)
			return self._x - offsetX
		end,

		y = function(self)
			return self._y - offsetY
		end
	}
end
