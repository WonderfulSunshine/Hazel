#include "hzpch.h"
#include "Log.h"
#include "spdlog/sinks/stdout_color_sinks.h"
 
namespace Hazel {
 
	std::shared_ptr<spdlog::logger> Log::s_CoreLogger; 
	std::shared_ptr<spdlog::logger> Log::s_CLientLogger; 

	  void    Log::Init() { 


			spdlog::set_pattern("%^[%T] %n: %v%$");
			s_CoreLogger = spdlog::stdout_color_mt("HAZEL");
			s_CoreLogger->set_level(spdlog::level::trace); 

			s_CLientLogger = spdlog::stdout_color_mt("APP");
			s_CLientLogger->set_level(spdlog::level::trace);
	}; 
}