#include "stdafx.h"
#include "D3D12HelloWindow.h"
#include "Win32Application.h"





_Use_decl_annotations_
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE, LPSTR, int nCmdShow){
    DXSample pSample;
    return Win32Application::Run(&pSample,hInstance, nCmdShow);
}