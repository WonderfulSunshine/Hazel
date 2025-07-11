﻿#pragma once


#include "hzpch.h"
#include "Hazel/Core.h"
#include "Hazel/Events/Event.h"


namespace Hazel
{
    struct Windowprops
    {
        std::string Title;
        unsigned int Width;
        unsigned int Height;

        Windowprops(const std::string& title = "Hazel Engine", unsigned int width = 1280,
                    unsigned int height = 720): Title(title), Width(width), Height(height)
        {
        } 
    };


    class HAZEL_API Window
    {
    public:
        using EventCallbackFn = std::function<void (Event&)>;


        virtual ~Window() {}

        virtual void OnUpdate() =0;
        virtual unsigned int GetWidth() const = 0;
        virtual unsigned int GetHeight() const = 0;


        //Windows Attributes 

        virtual void SetEventCallback(const EventCallbackFn& callback) =0;
		virtual void SetVSync(bool enabled) = 0;
		virtual bool IsVSync() const = 0;
        // in Windows Parent Define Func

        virtual void * GetNativeWindow() const = 0 ; 

        static Window* Create(const Windowprops& props = Windowprops());
    };
}
