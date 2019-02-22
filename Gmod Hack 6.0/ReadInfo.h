#pragma once
#include <Windows.h>
#include "EntityInfo.h"
#include "Offsets.h"
#include "GrabProcessInfo.h"


#include <d3d9.h>
#include <d3dx9.h>
#pragma comment(lib, "d3d9.lib")
#pragma comment(lib, "d3dx9.lib")

#include <dwmapi.h>
#pragma comment(lib, "dwmapi.lib")

class ReadMem
{
public:

    ReadMem()
    {
        GetPlayerAddress();
    }

    ProccessInformation PI;
    Offsets Offset;
    C_LocalPlayer PlayerInfo;
    C_LocalPlayer CurrentEntityInfo;
    EntityInfo Entity;

    // Vectors for the Aimbot
    Vec3 MyCoords;
    Vec3 MyEyePos;
    Vec3 EnemyBoneCoords[60];
    Vec3 AngleToEnemy;
    Vec3 EnemyCoords;

    float x, y;
    float NewDistance = 0.0;
    float OldDistance = 999999.0;
    DWORD EntityBase;
    DWORD LocalPlayer;


    void GetPlayerAddress();
    void GetEntityAddress(int EntNum);
    void GetPlayerInfo();
    void GetCurrentEntInfo(DWORD Entity);
    void ReadLocalOrigin();
    int ReadNumberOfPlayers();
    void GetViewMatrix();
    HWND GetWindowHandle(LPCSTR WindowName);
    HDC GetWindowHDC(HWND WindowHandle);
};








