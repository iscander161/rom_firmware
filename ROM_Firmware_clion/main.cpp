#include <iostream>
#ifdef WIN32
#include <windows.h>
#include "windows/win_main.h"
#elif
#include <>
#endif


int main()
{
    rom_CreateWindow();
    return 0;
}