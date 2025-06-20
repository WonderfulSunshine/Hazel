﻿#include "hzpch.h"
#include "WindowsInput.h"

#include "WindowsWindow.h"
#include "Hazel/Application.h"

namespace Hazel
{
    Input* Input::s_Instance = new WindowsInput();


    bool WindowsInput::IsKeyPressedImpl(int keycode)
    {
        auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());


        auto state = glfwGetKey(window, keycode);

        return state == GLFW_PRESS || state == GLFW_REPEAT;
    }


    bool WindowsInput::IsMouseButtonPressedImpl(int button)
    {
        auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
        auto state = glfwGetMouseButton(window, button);
        return state == GLFW_PRESS;
    }


    std::pair<float, float> WindowsInput::GetMousePositionImpl()
    {
        auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
        double xPos, yPos;

        glfwGetCursorPos(window, &xPos, &yPos);

        // ReSharper disable once CppCStyleCast
        return {(float)xPos, (float)yPos};
    }

    float WindowsInput::GetMouseXimpl()
    {
        auto [x,y] = GetMousePositionImpl();

        return x;
    }

    float WindowsInput::GetMouseYImpl()
    {
        auto [x,y] = GetMousePositionImpl();

        return y;
    }
}
