#pragma once
#include<windows.h>
#include "DXSample.h"

static WCHAR szWindowClass[] = L"DesktopApp";
static WCHAR szTitle[] = L"Windows Desktop Guided Tour Application";

class Win32Application{
public:
	static int Run(DXSample* pSample,HINSTANCE hInstance, int nCmdShow);
	static HWND GetHwnd() { return m_hwnd; }
protected:
	static LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
private:
	static HWND m_hwnd;
};

