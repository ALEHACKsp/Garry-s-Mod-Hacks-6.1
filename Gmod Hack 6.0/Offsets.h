#pragma once
#include <Windows.h>


struct Offsets
{
    const DWORD BonesX{ 0x0C };
    const DWORD BonesY{ 0x1C };
    const DWORD BonesZ{ 0x2C };
    const DWORD BonesBase{ 0x13E8 };
    const DWORD EyePos{ 0xF0 };
    const DWORD LoopDistance{ 0x10 };

    // Base addresses
    const DWORD EntityList{ 0x69479C };
    const DWORD PlayerBase{ 0x678954 };
    const DWORD NumOfPlayers{ 0x6743B4 }; // Engine
    const DWORD PlayerNameList{ 0x716938 };


    // Angle Addresses
    const DWORD VecAngleX{ 0x4E05F4 }; //Engine, writable 
    const DWORD VecAngleY{ 0x4E05F8 }; //Engine, writable
    const DWORD ViewMatrix{ 0x6144E8 }; // correct vm

    //Players Offsets
    const DWORD VecOriginX{ 0x260 };
    const DWORD VecOriginY{ 0x264 };
    const DWORD VecOriginZ{ 0x268 };
    const DWORD Health{ 0x90 };
    const DWORD MaxHealth{ 0x94 };
    const DWORD LifeState{ 0x8F };
    const DWORD TeamNum{ 0x9C };

    const DWORD MaxPlayersInGame{ 0x4CFD7C }; //Engine, the max allowed players to the server
};

