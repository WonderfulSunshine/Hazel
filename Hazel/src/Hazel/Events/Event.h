#include "hzpch.h"
#pragma once 
#include "Hazel/Core.h"

namespace Hazel {

	 
	enum class EventType {


		None = 0,
		WindowsClose , WindowResize,WindowFocus,WindowLostFocus, WindowMoved , 
		AppTick,AppUpdate,AppRender,KeyTyped,
		KeyPressed,KeyReleased,
		MouseButtonPressed,MouseButtonReleased,MouseMoved,MouseScrolled
	 };



	enum EventCategory
	{
		None = 0, 
		EventCategoryApplication		= BIT(0),
		EventCategoryInput				= BIT(1),
		EventCategoryKeyBoard			= BIT(2),
		EventCategoryMouse				= BIT(3),
		EventCategoryMouseButton		= BIT(4),

	};

	#define  EVENT_CLASS_TYPE(type) static EventType GetStaticType(){ return EventType::##type;} \
									virtual EventType GetEventType()const override{return GetStaticType();}\
									virtual const char* GetName()const override{return #type ; }
	#define  EVENT_CLASS_CATEGORY(category) virtual int GetCategoryFlags() const override{return category;}

	 
	class   HAZEL_API  Event 
	{
		friend class EventDispatcher; 
	public :
		virtual ~Event() = default;
		virtual EventType GetEventType() const = 0; 

		virtual const char* GetName() const = 0; 

		virtual int GetCategoryFlags() const = 0;  

		virtual std::string ToString() const { return GetName(); }
	 
		inline virtual bool IsInCategory(EventCategory category) {
			return GetCategoryFlags() & category;
		}  
	//protected:
		bool m_handled = false; 
	};



	class   EventDispatcher {

		template<typename T>
		using EventFunc = std::function<bool(T&)>; 

	public:
		EventDispatcher(Event & event) :m_Event(event) {}

		template<typename T>
		bool DispatchEvent(EventFunc<T> Func) {

			if (m_Event.GetEventType() == T::GetStaticType()) {

				m_Event.m_handled = Func(*(T*)&m_Event);
				return true;
			}
			return false;
		}
	private:
		Event& m_Event;

	};


	inline std::ostream& operator<<(std::ostream& os, const Event& event) {
		return os << event.ToString(); 
	}
	



}