#pragma once

#if  HZ_PLATFORM_WINDOWS
extern Hazel::Application* Hazel::CreateApplication();


int main(int argc, char** argv) {
	printf("Hello Fanker Engine \n");
	auto app = Hazel::CreateApplication(); 
	app->Run(); 
	delete app; 
	}
#endif //  