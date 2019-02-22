#pragma once
#include "ReadInfo.h"

#include <d3d9.h>
#include <d3dx9.h>
#pragma comment(lib, "d3d9.lib")
#pragma comment(lib, "d3dx9.lib")

#include <dwmapi.h>
#pragma comment(lib, "dwmapi.lib")





class Math
{
public:
    ReadMem Read;
    float Get3DDistance(Vec3 BonePos, Vec3 EyePos);
    Vec3 CalcAngle(Vec3 Src, Vec3 Dir);

    //bool WorldToScreen(Vec3 pos, Vec2 &screen, float matrix[16], int windowWidth, int windowHeight);

    bool WorldToScreen(Vec3 pos, Vec2 &screen, float matrix[16], int windowWidth, int windowHeight);







};
