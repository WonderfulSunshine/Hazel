﻿#pragma once
#include "Hazel/Window.h"

#include <GLFW/glfw3.h>

namespace Hazel
{
    class WindowsWindow : public Window
    {
    public:
        WindowsWindow(const Windowprops& props);
        virtual ~WindowsWindow();

        void OnUpdate() override;

        inline unsigned int GetHeight() const override { return m_Data.Height; }
        inline unsigned int GetWidth() const override { return m_Data.Width; }

        inline virtual void* GetNativeWindow() const { return m_Window; }
        inline void SetEventCallback(const EventCallbackFn& callback) override { m_Data.EventCallback = callback; }
        void SetVSync(bool enabled) override;
        bool IsVSync() const override;

    private:
        virtual void Init(const Windowprops& props);
        virtual void ShutDown();

    private:
        GLFWwindow* m_Window;

        struct WindowData
        {
            std::string Title;
            unsigned int Width, Height;
            bool VSync;
            EventCallbackFn EventCallback;
        };

        WindowData m_Data;
    };
}
