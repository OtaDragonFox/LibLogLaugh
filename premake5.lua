workspace "LiveLoveLog"
    architecture "x64"
    startproject "LiveLoveLog"
    toolset "v142"
    configurations 
    {
        "Debug",
        "Release"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "LiveLoveLog"
    location "LiveLoveLog"
    kind "StaticLib"
    language "c++"
    cppdialect "C++20"
    staticruntime "on"

   
	targetdir ("bin/" .. "/%{prj.name}")
	objdir ("bin/int/" ..  "/%{prj.name}")
    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    defines
    {

    }

    includedirs
    {
        "%{prj.name}/src/"
    }

    filter "system:windows"
        systemversion "latest"


    filter "configurations:Debug"
        defines "LLLDEB"
        runtime "Debug"
        symbols "on"

    filter "configurations:Release"
        defines "LLLREL"
        runtime "Release"
        symbols "on"


project "example"
    location "example"
    kind "ConsoleApp"
    language "c++"
    cppdialect "C++20"
    staticruntime "on"


	targetdir ("bin/" .. "/%{prj.name}")
	objdir ("bin/int/" ..  "/%{prj.name}")
    
    files
    {
        "%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "LiveLoveLog/src"

    }
    links
    {
        "LiveLoveLog"
    }


    filter "system:windows"
    systemversion "latest"

    filter "configurations:Debug"
        runtime "Debug"
        symbols "on"

    filter "configurations:Release"
        runtime "Release"
        symbols "on"