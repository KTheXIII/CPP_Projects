workspace "CPP_Projects"
    architecture "x64"

    startproject "HelloWorld"

    configurations {
        "Debug",
        "Release"
    }

include "HelloWorld"
include "HelloPI"