//
// Created by Iscander on 01.04.2019.
//

#ifndef ROM_FIRMWARE_WIN_MAIN_H
#define ROM_FIRMWARE_WIN_MAIN_H

typedef char byte_t;

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int rom_CreateWindow(HINSTANCE, int);

#endif //ROM_FIRMWARE_WIN_MAIN_H
