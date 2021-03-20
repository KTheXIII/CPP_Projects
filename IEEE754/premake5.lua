project "IEEE754"
    kind "ConsoleApp"
    language "C++"
    staticruntime "on"
    cppdialect "C++17"

    targetdir("%{wks.location}/bin/%{cfg.buildcfg}/%{prj.name}")
    objdir("%{wks.location}/obj/%{cfg.buildcfg}/%{prj.name}")

    files {
        "src/**.h",
        "src/**.hpp",
        "src/**.cpp",
    }

    includedirs {
        "src"
    }

    filter "configurations:Debug"
        runtime "Debug"
        symbols "On"

    filter "configurations:Release"
        runtime "Release"
        optimize "On"
