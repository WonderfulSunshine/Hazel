#pragma once
#include "Core.h"
#include "Events/Event.h"
#include "Window.h"
#include "Events/ApplicationEvent.h"

namespace Hazel
{
    class HAZEL_API Application
    {
    public:
        Application();
        virtual ~Application();
        void Run();
        bool OnWindowClose(WindowCloseEvent& e);

        void  OnEvent(Event& e )  ; 
    private:
        std::unique_ptr<Window> m_Window ;
        bool m_Running = true;  
    };
    

    Application* CreateApplication();
}
