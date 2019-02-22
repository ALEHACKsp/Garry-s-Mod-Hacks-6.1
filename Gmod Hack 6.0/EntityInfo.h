#pragma once
#include <Windows.h>


#include <d3d9.h>
#include <d3dx9.h>
#pragma comment(lib, "d3d9.lib")
#pragma comment(lib, "d3dx9.lib")

#include <dwmapi.h>
#pragma comment(lib, "dwmapi.lib")


struct Vec3
{
    float x, y, z;
};

struct Vec4
{
    float x, y, z, w;
};

struct Vec2
{
    float x, y;
};


class C_LocalPlayer
{
public:
    char _0x0000[144];
    __int32 m_iHealth; //0x0090 
    __int32 m_iMaxHealth; //0x0094 
    char _0x0098[504];
    Vec3 m_VecOrigin; //0x0290 
    char _0x029C[164];

};//Size=0x0340

struct EntityInfo
{
    float ViewMatrix[16];
};

