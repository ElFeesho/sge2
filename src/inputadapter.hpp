#pragma once

class InputAdapter
{
public:
    virtual ~InputAdapter() {}

    virtual bool shouldQuit() = 0;

    virtual int mouseX() = 0;
    virtual int mouseY() = 0;

    virtual bool mouseDown(int button) = 0;
};
