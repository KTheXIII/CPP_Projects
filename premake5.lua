workspace "CPP_Projects"
    architecture "x64"

    startproject "HelloWorld"

    configurations {
        "Debug",
        "Release"
    }


-- All platform
include "HelloWorld"
include "HelloPI"
include "IEEE754"
include "Unicode"

-- Platform specific projects

-- Exclude Windows
if os.host() ~= "windows" then
  include "HelloMatrix"
end
