#include "hzpch.h"
#include "Application.h"
#include "Hazel/Events/ApplicationEvent.h"
#include "Hazel/Log.h"
#include <GLFW/glfw3.h>
#include "glad/glad.h"

namespace Hazel
{
#define BIND_EVENT_FN(x) std::bind(&Application::x ,this,std::placeholders::_1)


     Application * Application::s_Instance = nullptr ; 
    
    Application::Application()
    {

        HZ_CORE_ASSERT(!s_Instance , "Applicaiton alread exists !" ) ;
        
        s_Instance =this ;
        
        m_Window = std::unique_ptr<Window>(Window::Create());

        m_Window->SetEventCallback(BIND_EVENT_FN(OnEvent));

 
    }

    Application::~Application()
    {
    };

    void Application::OnEvent(Event& e)
    {
        EventDispatcher dispatcher(e);
        dispatcher.DispatchEvent<WindowCloseEvent>(BIND_EVENT_FN(OnWindowClose));

        HZ_CORE_INFO("{0}", e.ToString());


        for (auto it = m_LayerStack.end(); it != m_LayerStack.begin();)
        {
            (*--it)->OnEvent(e);
            if (e.m_handled)
                break;
        }
    }

    void Application::Run()
    {
        while (m_Running)
        {
            glClearColor(1, 0, 1, 1);
            glClear(GL_COLOR_BUFFER_BIT);
            for (Layer* layer : m_LayerStack)
                layer->OnUpdate();

            m_Window->OnUpdate();
        }
    }

    bool Application::OnWindowClose(WindowCloseEvent& e)
    {
        m_Running = false;
        return true;
    }

    void Application::PushLayer(Layer* layer)
    {
        m_LayerStack.PushLayer(layer);
        layer->OnAttach();
    }

    void Application::PushOverlay(Layer* layer)
    {
        m_LayerStack.PushOverLay(layer);
        
        layer->OnAttach();
    }
}
