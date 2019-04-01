#include <iostream>

#ifdef WIN32
#include <windows.h>
#include "windows/win_main.h"
#include "WindowsCoordinates.h"

int CALLBACK WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR lpCmdLine, int nCmdShow)
{
    if(rom_CreateWindow(hInst, nCmdShow))
        MessageBox(NULL, "Creating Windows Error", sAppName, MB_ICONERROR | MB_OK);
    return 0;
}


#else //for other OS
//
#endif