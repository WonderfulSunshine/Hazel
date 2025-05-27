#pragma once
#include <memory>
#include"Core.h"

#include "spdlog/spdlog.h"

namespace Hazel {

	class HAZEL_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClinetLogger() { return s_CLientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_CLientLogger;
	};



 }
// Core Log Macos
#define HZ_CORE_ERROR(...)	 ::Hazel::Log::GetCoreLogger()->error(__VA_ARGS__)
#define HZ_CORE_WARN(...)	 ::Hazel::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define HZ_CORE_INFO(...)    ::Hazel::Log::GetCoreLogger()->info(__VA_ARGS__)
#define HZ_CORE_TRACE(...)   ::Hazel::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define HZ_CORE_FATAL(...)   ::Hazel::Log::GetCoreLogger()->fatal(__VA_ARGS__)
 

// Client Log Macos
#define HZ_Client_ERROR(...)	::Hazel::Log::GetClinetLogger()->error(__VA_ARGS__)
#define HZ_Client_WARN(...)	    ::Hazel::Log::GetClinetLogger()->warn(__VA_ARGS__)
#define HZ_Client_Info(...)	    ::Hazel::Log::GetClinetLogger()->info(__VA_ARGS__)
#define HZ_Client_TRACE(...)    ::Hazel::Log::GetClinetLogger()->trace(__VA_ARGS__)
#define HZ_Client_FATAL(...)    ::Hazel::Log::GetClinetLogger()->fatal(__VA_ARGS__)