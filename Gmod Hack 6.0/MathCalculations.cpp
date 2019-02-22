#include "MathCalculations.h"

float Math::Get3DDistance(Vec3 BonePos, Vec3 EyePos)
{
    float x1, y1, z1;

    x1 = pow(BonePos.x - EyePos.x, 2.0f);
    y1 = pow(BonePos.y - EyePos.y, 2.0f);
    z1 = pow(BonePos.z - EyePos.z, 2.0f);

    float value = x1 + y1 + z1;
    float distance = sqrt(value);

    return distance;
}

Vec3 Math::CalcAngle(Vec3 Src, Vec3 Dir)
{
    Vec3 AngleHolder;

    AngleHolder.x = Dir.x - Src.x;
    AngleHolder.y = Dir.y - Src.y;
    AngleHolder.z = Dir.z - Src.z;
    float Magnitude = sqrt(AngleHolder.x * AngleHolder.x + AngleHolder.y * AngleHolder.y + AngleHolder.z * AngleHolder.z);

    Vec3 AngleToEntity;
    AngleToEntity.y = atan2(AngleHolder.y, AngleHolder.x) * 180 / 3.14f;
    AngleToEntity.x = -atan2(AngleHolder.z, Magnitude) * 180 / 3.14f;
    AngleToEntity.z = 0.0f;


    return AngleToEntity;
}

bool Math::WorldToScreen(Vec3 pos, Vec2 &screen, float matrix[16], int windowWidth, int windowHeight)
{
    //Matrix-vector Product, multiplying world(eye) coordinates by projection matrix = clipCoords
    Vec4 clipCoords;
    clipCoords.x = pos.x*matrix[0] + pos.y*matrix[1] + pos.z*matrix[2] + matrix[3];
    clipCoords.y = pos.x*matrix[4] + pos.y*matrix[5] + pos.z*matrix[6] + matrix[7];
    clipCoords.z = pos.x*matrix[8] + pos.y*matrix[9] + pos.z*matrix[10] + matrix[11];
    clipCoords.w = pos.x*matrix[12] + pos.y*matrix[13] + pos.z*matrix[14] + matrix[15];

    if (clipCoords.w < 0.1f)
        return false;

    //perspective division, dividing by clip.W = Normalized Device Coordinates
    Vec3 NDC;
    NDC.x = clipCoords.x / clipCoords.w;
    NDC.y = clipCoords.y / clipCoords.w;
    NDC.z = clipCoords.z / clipCoords.w;

    screen.x = (windowWidth / 2 * NDC.x) + (NDC.x + windowWidth / 2);
    screen.y = -(windowHeight / 2 * NDC.y) + (NDC.y + windowHeight / 2);
    return true;
}







/*bool Math::WorldToScreen(Vec3 pos, Vec2 & screen, float matrix[16], int windowWidth, int windowHeight)
{


    Vec4 clipCoords;
    clipCoords.x = pos.x*matrix[0] + pos.y*matrix[1] + pos.z*matrix[2] + matrix[3];
    clipCoords.y = pos.x*matrix[4] + pos.y*matrix[5] + pos.z*matrix[6] + matrix[7];
    clipCoords.z = pos.x*matrix[8] + pos.y*matrix[9] + pos.z*matrix[10] + matrix[11];
    clipCoords.w = pos.x*matrix[12] + pos.y*matrix[13] + pos.z*matrix[14] + matrix[15];

    if (clipCoords.w < 0.1f)
        return false;


    Vec3 NDC;
    NDC.x = clipCoords.x / clipCoords.w;
    NDC.y = clipCoords.y / clipCoords.w;
    NDC.z = clipCoords.z / clipCoords.w;

    screen.x = (windowWidth / 2 * NDC.x) + (NDC.x + windowWidth / 2);
    screen.y = -(windowHeight / 2 * NDC.y) + (NDC.y + windowHeight / 2);
    return true;
}


*/


