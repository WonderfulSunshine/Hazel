workspace "Hazel"
    architecture "x64"
    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }

    outputdir ="%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

    IncludeDir = {} 
    IncludeDir["GLFW"] = "Hazel/vendor/GLFW/include"
    IncludeDir["Glad"] = "Hazel/vendor/Glad/include"
    IncludeDir["ImGui"] = "Hazel/vendor/imgui"
    IncludeDir["glm"] = "Hazel/vendor/glm"
    
    include "Hazel/vendor/GLFW"
    include "Hazel/vendor/Glad"
    include "Hazel/vendor/imgui"

project "Hazel"
    location "Hazel"
    
    kind "SharedLib"
    language "C++"
    buildoptions { "/utf-8" }  -- 构建选项，设置文件编码为 UTF-8
    targetdir ("bin/" .. outputdir .."/%{prj.name}")
    objdir ("bin-int/" .. outputdir .."/%{prj.name}")

    pchheader "hzpch.h"
    pchsource "Hazel/src/hzpch.cpp"

    files
    {

        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp",
        -- 可以不用包含hpp文件
		"%{prj.name}/vendor/glm/glm/**.hpp",
		"%{prj.name}/vendor/glm/glm/**.inl"
    }

    includedirs
    { 
        "%{prj.name}/src",
        "%{prj.name}/vendor/spdlog/include",
        "%{IncludeDir.GLFW}",
         "%{IncludeDir.Glad}",
         "%{IncludeDir.ImGui}",
          "%{IncludeDir.glm}"-- 包含目录
    }


       links 
             {
                "GLFW",
                "Glad",
                "ImGui" ,
                "opengl32.lib"
             }

    filter "system:windows"
        cppdialect "c++17"
        staticruntime "On"
        systemversion "10.0"


        defines
        {
            "HZ_PLATFORM_WINDOWS",
            "HZ_BUILD_DLL",
            "GLFW_INCLUDE_NONE"
        }



        postbuildcommands 
        {
             "{MKDIR} ../bin/" .. outputdir .. "/SandboxApp",
            ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/SandboxApp")  
        }


     
    filter "configurations:Debug"
        defines "HZ_DEBUG"
        buildoptions "/MDd"
        symbols "On"
        
    filter "configurations:Release"
        defines "HZ_Release" 
        buildoptions "/MD"
        optimize "On"
        
    filter "configurations:Dist"
        defines "HZ_Dist"
        buildoptions "/MD"
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
                "Hazel/src",
                "%{IncludeDir.glm}"
            }
             links 
             {
                "GLFW",
                "opengl32.lib",
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
                    buildoptions "/MDd"
                    symbols "On"
                    
                filter "configurations:Release"
                    defines "HZ_Release"
                     buildoptions "/MD"
                    optimize "On"
                    
                filter "configurations:Dist"
                    defines "HZ_Dist"
                    buildoptions "/MD"
                    optimize "On"

staticruntime	"Off"