#pragma once

#if  HZ_PLATFORM_WINDOWS

extern Hazel::Application* Hazel::CreateApplication();

int main(int argc, char** argv) {

	Hazel::Log::Init();

	int a = 5; 
	 HZ_CORE_WARN("Initialized Log !!!!"); 
	 HZ_Client_Info("hello!Var = {0}", a);
	// HZ_Client_Fanker("hello ! var={0}", a);
	//spdlog::info("hello! Var={}", a);
	auto app = Hazel::CreateApplication(); 
	app->Run(); 
	delete app; 
	}
#endif //  