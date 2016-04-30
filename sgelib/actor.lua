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
