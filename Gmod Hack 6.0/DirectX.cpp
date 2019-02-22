#include "DirectX.h"

IDirect3D9Ex* p_Object = 0;
IDirect3D9Ex* p_Object2 = 0;
IDirect3DDevice9Ex* p_Device = 0;
IDirect3DDevice9Ex* p_Device2 = 0;
D3DPRESENT_PARAMETERS p_Params;



ID3DXLine* p_Line;
ID3DXFont* pFontSmall = 0;
ESP t;

int DirectXInit(HWND hWnd)
{
    if (FAILED(Direct3DCreate9Ex(D3D_SDK_VERSION, &p_Object)))
        exit(1);
    if(FAILED(Direct3DCreate9Ex(D3D_SDK_VERSION, &p_Object2)))
        exit(1);


    ZeroMemory(&p_Params, sizeof(p_Params));
    p_Params.Windowed = TRUE;
    p_Params.SwapEffect = D3DSWAPEFFECT_DISCARD;
    p_Params.hDeviceWindow = hWnd;
    p_Params.MultiSampleQuality = D3DMULTISAMPLE_NONE;
    p_Params.BackBufferFormat = D3DFMT_A8R8G8B8;
    p_Params.BackBufferWidth = Width;
    p_Params.BackBufferHeight = Height;
    p_Params.EnableAutoDepthStencil = TRUE;
    p_Params.AutoDepthStencilFormat = D3DFMT_D16;

    if (FAILED(p_Object->CreateDeviceEx(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hWnd, D3DCREATE_HARDWARE_VERTEXPROCESSING, &p_Params, 0, &p_Device)))
        exit(1);
    if (FAILED(p_Object2->CreateDeviceEx(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hWnd, D3DCREATE_HARDWARE_VERTEXPROCESSING, &p_Params, 0, &p_Device2)))
        exit(1);


    if (!p_Line)
        D3DXCreateLine(p_Device, &p_Line);

    D3DXCreateFont(p_Device, 18, 0, 0, 0, false, DEFAULT_CHARSET, OUT_CHARACTER_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH, "Calibri", &pFontSmall);



    return 0;
}


int Render()
{
    p_Device->BeginScene();
    p_Device->Clear(0, 0, D3DCLEAR_TARGET, 0, 1.0f, 0);
    if (tWnd == GetForegroundWindow())
    {
        if (GetAsyncKeyState(VK_ADD))
            t.bESP = !t.bESP;
        // Check if ESP is set to true then loop through entites
        if (t.bESP)
        {
            t.ReadMemory.ReadLocalOrigin();
            t.ReadMemory.GetViewMatrix();
            for (int c = 0; c < t.PlayerCount; c++)
            {
                t.ReadMemory.GetCurrentEntInfo(t.Players[c]);
                if (t.ReadMemory.CurrentEntityInfo.m_iHealth > 0 && t.ReadMemory.CurrentEntityInfo.m_iHealth < 1000)
                {
                    if (t.math.WorldToScreen(t.ReadMemory.CurrentEntityInfo.m_VecOrigin, t.ScreenCoords, t.ReadMemory.Entity.ViewMatrix, t.Width, t.Height))
                    {
                        t.Distance = t.math.Get3DDistance(t.ReadMemory.CurrentEntityInfo.m_VecOrigin, t.ReadMemory.MyCoords);
                        t.BoxWidth = 18100 / t.Distance;
                        t.BoxHeight = 36000 / t.Distance;
                        DrawBox(t.ScreenCoords.x - (t.BoxWidth / 2), t.ScreenCoords.y - t.BoxHeight, t.BoxWidth, t.BoxHeight, 0, 255, 50, 50, 255);
                    }
                }
            }
            DrawShadowString((char*)"ESP: ON", 10, 15, 0, 255, 0, pFontSmall);
        }
        if (!t.bESP)
        {
            DrawShadowString((char*)"ESP: OFF", 10, 15, 255, 255, 255, pFontSmall);
        }
        //text with shadow
        DrawShadowString((char*)"Gmod Hacks 6.1", 5, 0, 240, 240, 250, pFontSmall);

        
        //crosshair
        FillRGB(Width / 2 - 22, Height / 2, 44, 1, 255, 0, 0, 255);
        FillRGB(Width / 2, Height / 2 - 22, 1, 44, 255, 0, 0, 255);

        if (t.ReadMemory.ReadNumberOfPlayers() < t.NumPlayers || t.ReadMemory.ReadNumberOfPlayers() > t.NumPlayers)
        {
            t.GetPlayerList();
        }
    }

    p_Device->EndScene();
    p_Device->PresentEx(0, 0, 0, 0, 0);
    Sleep(1);
    return 0;
}
/*
int DrawMenu()
{
    p_Device2->BeginScene();
    p_Device2->Clear(0, 0, D3DCLEAR_TARGET, 0, 1.0f, 0);

    if (tWnd == GetForegroundWindow())
    {
        DrawShadowString((char*)"ESP", 5, 5, 0, 255, 0, pFontSmall);



    }
    p_Device2->EndScene();
    p_Device2->PresentEx(0, 0, 0, 0, 0);
    return 0;
}
*/
void CleanDirectX()
{
    p_Object->Release();
    p_Device->Release();
    p_Line->Release();
    pFontSmall->Release();
}

