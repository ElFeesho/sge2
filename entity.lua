function newEntity()
	return {
		_x = 0,
		_y = 0,
		_w = 0,
		_h = 0,
		_colour = 0x00000000,

		x = function(self, newValue)
			if (newValue ~= nil) then
				self._x = newValue
			end
			return self._x
		end,

		y = function(self, newValue)
			if (newValue ~= nil) then
				self._y = newValue
			end
			return self._y
		end,

		w = function(self, newValue)
			if (newValue ~= nil) then
				self._w = newValue
			end
			return self._w
		end,

		h = function(self, newValue)
			if (newValue ~= nil) then
				self._h = newValue
			end
			return self._h
		end,

		colour = function(self, newValue)
			if (newValue ~= nil) then
				self._colour = newValue
			end
			return self._colour
		end,

		draw = function(self)
			Graphics.drawRect(self._x, self._y, self._w, self._h, self._colour)
		end
	}
end
