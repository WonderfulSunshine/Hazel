#pragma once
#include "Core.h"
#include "Events/Event.h"
#include "Window.h"
#include "Events/ApplicationEvent.h"


#include "Hazel/LayerStack.h"

namespace Hazel
{
    class HAZEL_API Application
    {
    public:
        Application();

        virtual ~Application();

        void Run();

        bool OnWindowClose(WindowCloseEvent& e);

        void PushLayer(Layer* layer);

        void PushOverlay(Layer* layer);

        void OnEvent(Event& e);

        inline static  Application& Get() { return *s_Instance; }

        inline  Window& GetWindow() { return *m_Window; } 

    private:
        std::unique_ptr<Window> m_Window;

        bool m_Running = true;

        LayerStack m_LayerStack;

        static Application* s_Instance;
    };


    Application* CreateApplication();
}
