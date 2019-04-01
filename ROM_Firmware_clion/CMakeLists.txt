cmake_minimum_required(VERSION 3.13)
project(ROM_Firmware)

set(CMAKE_CXX_STANDARD 17)

add_executable(ROM_Firmware main.cpp windows/win_main.h windows/win_main.cpp WindowsCoordinates.h)