//
// Created by Iscander on 01.04.2019.
//


#include <iostream>
#include <windows.h>
#include "win_main.h"
#include "../WindowsCoordinates.h"

WNDCLASSEX  cWcex;
HINSTANCE   hInst;
HWND        hWnd;


int xCenter = (GetSystemMetrics(SM_CXSCREEN) - nWindowWidth) / 2;
int yCenter = (GetSystemMetrics(SM_CYSCREEN) - nWindowHeight) / 2;

int rom_CreateWindow(HINSTANCE hInstance, int nCmdShow)
{
    cWcex.cbSize         = sizeof(WNDCLASSEX);
    cWcex.style          = CS_HREDRAW | CS_VREDRAW;
    cWcex.lpfnWndProc    = WndProc;
    cWcex.cbClsExtra     = 0;
    cWcex.cbWndExtra     = 0;
    cWcex.hInstance      = hInstance;
    cWcex.hIcon          = LoadIcon(hInstance, IDI_APPLICATION);
    cWcex.hCursor        = LoadCursor(NULL, IDC_ARROW);
    cWcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW);
    cWcex.lpszMenuName   = NULL;
    cWcex.lpszClassName  = sAppName;
    cWcex.hIconSm        = LoadIcon(cWcex.hInstance, IDI_APPLICATION);
    if (!RegisterClassEx(&cWcex))
    {
        MessageBox(NULL,
                   "Call to RegisterClassEx failed!",
                   "Windows Desktop Guided Tour",
                   NULL);
        return 1;
    }
    hInst = hInstance;
    hWnd = CreateWindow(sAppName, sAppName,
            WS_VISIBLE | WS_OVERLAPPEDWINDOW,
            xCenter, yCenter, nWindowWidth, nWindowHeight,
            NULL, NULL, hInstance, NULL
    );
    if (!hWnd)
    {
        MessageBox(NULL, "Call to CreateWindow failed!",
                   "Windows Desktop Guided Tour", NULL);
        return 1;
    }
    ShowWindow(hWnd, nCmdShow);
    UpdateWindow(hWnd);
    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return (int) msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
        case WM_DESTROY:
            PostQuitMessage(0);
            break;
        default:
            return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}