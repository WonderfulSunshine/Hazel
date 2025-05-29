workspace "Hazel"
    architecture "x64"
    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }

    outputdir ="%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"
project "Hazel"
    location "Hazel"
    kind "SharedLib"
    language "C++"
    buildoptions { "/utf-8" }  -- 构建选项，设置文件编码为 UTF-8
    targetdir ("bin/" .. outputdir .."/%{prj.name}")
    objdir ("bin-int/" .. outputdir .."/%{prj.name}")

    files
    {

        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "%{prj.name}/vendor/spdlog/include"
    }

    filter "system:windows"
        cppdialect "c++17"
        staticruntime "On"
        systemversion "10.0"


        defines
        {
            "HZ_PLATFORM_WINDOWS",
            "HZ_BUILD_DLL"
        }



        postbuildcommands 
        {
             "{MKDIR} ../bin/" .. outputdir .. "/SandboxApp",
            ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/SandboxApp")  
        }


     
    filter "configurations:Debug"
        defines "HZ_DEBUG"
        symbols "On"
        
    filter "configurations:Release"
        defines "HZ_Release"
        optimize "On"
        
    filter "configurations:Dist"
        defines "HZ_Dist"
        optimize "On"


project "SandBoxApp"
        kind "ConsoleApp"  
        location "SandBoxApp"
        language "C++"
        
    buildoptions { "/utf-8" }  -- 构建选项，设置文件编码为 UTF-8
        targetdir ("bin/" .. outputdir .."/%{prj.name}")
        objdir ("bin-int/" .. outputdir .."/%{prj.name}")
        files
            {

                "%{prj.name}/src/**.h",
                "%{prj.name}/src/**.cpp"
            }

            includedirs
            {
                "Hazel/vendor/spdlog/include",
                "Hazel/src"
            }
             links 
             {
                "Hazel"
             }
            filter "system:windows"
                cppdialect "c++17"
                staticruntime "On"
                systemversion "latest"
            defines
                {
                    "HZ_PLATFORM_WINDOWS"
                }


                filter "configurations:Debug"
                    defines "HZ_DEBUG"
                    symbols "On"
                    
                filter "configurations:Release"
                    defines "HZ_Release"
                    optimize "On"
                    
                filter "configurations:Dist"
                    defines "HZ_Dist"
                    optimize "On"

