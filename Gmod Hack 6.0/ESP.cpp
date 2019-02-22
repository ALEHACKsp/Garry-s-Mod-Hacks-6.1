#include "ESP.h"


void ESP::GetPlayerList()
{

    NumPlayers = ReadMemory.ReadNumberOfPlayers();
    PlayerCount = 0;



    for (int i = 0; i < NumPlayers; i++)
    {
        ReadMemory.GetEntityAddress(i);
        ReadMemory.GetPlayerInfo();

        if (ReadMemory.EntityBase == NULL)
            continue;
        if (ReadMemory.PlayerInfo.m_iHealth < 1 || ReadMemory.PlayerInfo.m_iHealth > 500)
            continue;
        if (ReadMemory.EntityBase == ReadMemory.LocalPlayer)
            continue;

        Players[PlayerCount] = ReadMemory.EntityBase;
        PlayerCount += 1;
    }
}

void ESP::GetWindowSize()
{

    GetWindowRect(ReadMemory.GetWindowHandle("Garry's Mod"), &GameWindow);

    Width = GameWindow.right - GameWindow.left;
    Height = GameWindow.bottom - GameWindow.top;

}


