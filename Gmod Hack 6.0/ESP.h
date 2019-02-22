#pragma once
#include "ReadInfo.h"
#include "MathCalculations.h"
#include "EntityInfo.h"

#include <d3d9.h>
#include <d3dx9.h>
#pragma comment(lib, "d3d9.lib")
#pragma comment(lib, "d3dx9.lib")

#include <dwmapi.h>
#pragma comment(lib, "dwmapi.lib")




struct ESP
{

    ESP()
    {
        GetWindowSize();
        GetPlayerList();
    }


    Math math;
    ReadMem ReadMemory;
    RECT GameWindow;

    Vec2 ScreenCoords;
    DWORD Players[50];
    int PlayerCount = 0;
    int NumPlayers = 0;
    int Width, Height;
    bool bESP = false;

    void GetPlayerList();
    void GetWindowSize();
    float Distance;
    float BoxWidth;
    float BoxHeight;



};
