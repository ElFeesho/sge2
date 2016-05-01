function createRect(startX, startY, startW, startH, startColour)
	
	local rect = {
		_x = startX,
		_y = startY,
		_w = startW,
		_h = startH,
		_colour = startColour,

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
	return rect
end
