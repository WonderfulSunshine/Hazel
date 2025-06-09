#include <Hazel.h>

#include "glm/fwd.hpp"
#include "glm/ext/matrix_clip_space.hpp"
#include "glm/gtx/transform.hpp"



                         
                         

class ExampleLayer : public Hazel::Layer
{
public:
    ExampleLayer() : Layer("Example")
    {
        
    }

    void OnUpdate() override
    {
        HZ_Client_Info("ExampleLayer::Update");


        if (Hazel::Input::IsKeyPressed(HZ_KEY_TAB))
        {
            HZ_Client_Info("Tab Key Is Pressed");
        }
    }

    void OnEvent(Hazel::Event& event) override
    {
   //     HZ_Client_TRACE("{0}", event.ToString());


         if (event.GetEventType()==Hazel::EventType::KeyPressed)
         {

             Hazel::KeyPressedEvent & e=(Hazel::KeyPressedEvent &)event;

              if (e.GetKeyCode() == HZ_KEY_TAB)
              {

                  HZ_Client_TRACE("A键按下(event)");
              }
             HZ_Client_TRACE("{0}",(char)e.GetKeyCode());
         }

        
    }
};

class Sandbox : public Hazel::Application
{
public:
    Sandbox()
    {
        PushLayer(new ExampleLayer());

        PushOverlay(new Hazel::ImGuiLayer());
    }

    ~Sandbox()
    {
    }
};


Hazel::Application* Hazel::CreateApplication()
{
    return new Sandbox();
}
