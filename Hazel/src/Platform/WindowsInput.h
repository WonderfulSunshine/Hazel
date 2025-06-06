#pragma once
#include "Hazel/Input.h"


namespace Hazel
{
    class WindowsInput : public Input
    {
    protected:
        virtual bool
        IsKeyPressedImpl(int keycode) override;
        virtual bool IsMouseButtonPressedImpl(int button) override;
        std::pair<float, float> GetMousePositionImpl() override;
        float GetMouseXimpl() override;
        float GetMouseYImpl() override;
    };
}
