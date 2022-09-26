@echo off

cl -D_HAS_EXCEPTIONS=0 -GR- -std:c++17 -nologo -Od -DDEBUG_BUILD -Z7 -FC -W4 -D -wd4100 -wd4065 -wd4201 -wd4189 -wd4996 -wd4530 -wd4505 -wd4100 tests.cpp -link user32.lib -out:tests.exe