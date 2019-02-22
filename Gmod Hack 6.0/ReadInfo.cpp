#include "ReadInfo.h"

void ReadMem::GetPlayerAddress()
{
    ReadProcessMemory(PI.GameHandle, (LPVOID)(PI.ClientModule + Offset.PlayerBase), &LocalPlayer, sizeof(DWORD), NULL);
}

void ReadMem::GetEntityAddress(int EntNum)
{
    ReadProcessMemory(PI.GameHandle, (LPVOID)(PI.ClientModule + Offset.EntityList + (EntNum * Offset.LoopDistance)), &EntityBase, sizeof(DWORD), NULL);
}

int ReadMem::ReadNumberOfPlayers()
{
    int Players = 0;
    ReadProcessMemory(PI.GameHandle, (LPVOID)(PI.ClientModule + Offset.NumOfPlayers), &Players, sizeof(int), NULL);
    return Players;
}

void ReadMem::GetPlayerInfo()
{
    ReadProcessMemory(PI.GameHandle, (LPVOID)(EntityBase), &PlayerInfo, sizeof(C_LocalPlayer), NULL);
}

void ReadMem::GetCurrentEntInfo(DWORD Entity)
{

    ReadProcessMemory(PI.GameHandle, (LPVOID)(Entity), &CurrentEntityInfo, sizeof(C_LocalPlayer), NULL);
}

void ReadMem::ReadLocalOrigin()
{
    ReadProcessMemory(PI.GameHandle, (LPVOID)(LocalPlayer + Offset.VecOriginX), &MyCoords, sizeof(float[3]), NULL);
}

void ReadMem::GetViewMatrix()
{
    ReadProcessMemory(PI.GameHandle, (LPVOID)(PI.EngineModule + Offset.ViewMatrix), &Entity.ViewMatrix, sizeof(float[16]), NULL);
}

HWND ReadMem::GetWindowHandle(LPCSTR WindowName)
{
    HWND Window;
    Window = FindWindowA(0, WindowName);
    return Window;
}

HDC ReadMem::GetWindowHDC(HWND WindowHandle)
{

    HDC MyHDC = GetDC(WindowHandle);

    return MyHDC;
}


