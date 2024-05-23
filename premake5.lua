outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "LibLogLaugh"
    location "LibLogLaugh"
    kind "StaticLib"
    language "c++"
    cppdialect "C++20"
    staticruntime "on"

   
	targetdir ("bin/" .. outputdir.. "/%{prj.name}")
	objdir ("bin/int/" .. outputdir ..  "/%{prj.name}")
    files
    {
        "include/**.h",
        "include/**.cpp"
    }



    filter "system:windows"
        systemversion "latest"
        defines "LOG_WINDWS"


    filter "configurations:Debug"
        defines "LLLDEB"
        runtime "Debug"
        symbols "on"

    filter "configurations:Release"
        defines "LLLREL"
        runtime "Release"
        symbols "on"

