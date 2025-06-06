#pragma once
#include "Hazel/Layer.h"

#include"Hazel/Events/KeyEvent.h"
#include"Hazel/Events/ApplicationEvent.h"

#include"Hazel/Events/MouseEvent.h"

namespace Hazel

{
    class WindowResizeEvent;

    class HAZEL_API ImGuiLayer : public Layer
    {
    public:
        ImGuiLayer();
        ~ImGuiLayer();
        
        void OnAttach();
        void OnDetach();
        void OnUpdate();
        void OnEvent(Event& event);

    private:
        bool OnMouseButtonPressedEvent(MouseButtonPressedEvent& e);

        bool OnMouseButtonReleasedEvent(MouseButtonReleasedEvent& e);

        bool OnMouseMovedEvent(MouseMoveEvent& e);

        bool OnMouseScrolledEvent(MouseScrollEvent& e);

        bool OnKeyPressedEvent(KeyPressedEvent& e);
        
        bool OnKeyReleasedEvent(KeyReleasedEvent& e);


        bool OnWindowResizeEvent(WindowResizeEvent& e);

        //void OnKeyTypedEvent(KeyTypedEvent& e);


    private:
        float m_Time = 0.0f;
    };
}
