Graphics.openScreen(640, 480)

dofile("entity.lua")

local blockEntity = newEntity()
blockEntity:w(25)
blockEntity:h(25)
blockEntity:colour(0x88ff8800)

local bg = newEntity()
bg:w(Graphics.width())
bg:h(Graphics.height())
bg:colour(0x0088ffff)

function update()
	bg:draw()

	blockEntity:x(Input.mouseX()-12)
	blockEntity:y(Input.mouseY()-12)

	if(Input.mouseButton() == 1) then
		blockEntity:colour(0x88ff0088)
	else
		blockEntity:colour(0x88ff8888)
	end

	blockEntity:draw()

end

