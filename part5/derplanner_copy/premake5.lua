solution "derplanner"
    platforms { "x64", "x32" }
    configurations { "release", "debug" }
    language "C++"

    flags { "NoPCH", "NoRTTI", "FatalWarnings" }
    warnings "Extra"
    objdir ".build/obj"

    configuration "debug"
        flags "Symbols"

    configuration "release"
        optimize "Speed"
        defines { "NDEBUG" }

    configuration { "debug", "x32" }
        targetdir "bin/x32/debug"

    configuration { "release", "x32" }
        targetdir "bin/x32/release"

    configuration { "debug", "x64" }
        targetdir "bin/x64/debug"

    configuration { "release", "x64" }
        targetdir "bin/x64/release"


    project "derplanner-compiler"
        kind "StaticLib"
        flags { "NoExceptions" }
        files { "source/compiler/*.cpp" }
        includedirs { "include" }

    project "derplanner-runtime"
        kind "StaticLib"
        flags { "NoExceptions" }
        files { "source/runtime/*.cpp" }
        includedirs { "include" }

    project "derplannerc"
        kind "ConsoleApp"
        files { "compiler/*.cpp" }
        includedirs { "include" }
        links { "derplanner-compiler" }
        configuration { "vs*" }
            defines { "_CRT_SECURE_NO_WARNINGS" }
        configuration {}

    project "deps-unittestpp"
        kind "StaticLib"
        files { "deps/unittestpp/src/*.cpp" }
        configuration { "linux or macosx" }
            files { "deps/unittestpp/src/Posix/*.cpp" }
        configuration { "vs*" }
            defines { "_CRT_SECURE_NO_WARNINGS" }
        configuration { "vs*" }
            files { "deps/unittestpp/src/Win32/*.cpp" }
        configuration {}

    project "tests"
        kind "ConsoleApp"
        files { "test/*.cpp" }
        includedirs { "deps/unittestpp", "include", "source" }
        links { "deps-unittestpp", "derplanner-compiler", "derplanner-runtime" }
        configuration { "vs*" }
            defines { "_CRT_SECURE_NO_WARNINGS" }
        configuration {}

    project "example-travel"
        kind "ConsoleApp"
        files { "examples/travel.main.cpp", "examples/travel.cpp" }
        includedirs { "include" }
        links { "derplanner-runtime" }

    project "example-blocks"
        kind "ConsoleApp"
        files { "examples/blocks.main.cpp", "examples/blocks.cpp" }
        includedirs { "include" }
        links { "derplanner-runtime" }

    project "example-travel2"
        kind "ConsoleApp"
        files { "examples/travel2.main.cpp", "examples/travel2.cpp" }
        includedirs { "include" }
        links { "derplanner-runtime" }

    project "hanoi"
        kind "ConsoleApp"
        files { "examples/hanoi.main.cpp", "examples/hanoi.cpp" }
        includedirs { "include" }
        links { "derplanner-runtime" }
