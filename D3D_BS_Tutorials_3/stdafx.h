#pragma once
#include <windows.h>
#include "../include/directx/d3dx12.h"
#include <dxgi1_6.h>
#include <D3Dcompiler.h>
#include <DirectXMath.h>

#pragma region WindodwPart
//´°¿Ú¾ä±ú
HWND hwnd = NULL;

// name of the window (not the title)
auto WindowName = L"BzTutsApp";

// title of the window
auto WindowTitle = L"Bz Window";

// width and height of the window
int Width = 800;
int Height = 600;

// is window full screen?
bool FullScreen = false;

// create a window
bool InitializeWindow(HINSTANCE hInstance,
    int ShowWnd,
    int width, int height,
    bool fullscreen);

// main application loop
void mainloop();

// callback function for windows messages
LRESULT CALLBACK WndProc(HWND hWnd,
    UINT msg,
    WPARAM wParam,
    LPARAM lParam);
#pragma endregion WindodwPart


#pragma region D3DPart
// direct3d stuff
const int frameBufferCount = 3; // number of buffers we want, 2 for double buffering, 3 for tripple buffering

ID3D12Device* device; // direct3d device

IDXGISwapChain3* swapChain; // swapchain used to switch between render targets

ID3D12CommandQueue* commandQueue; // container for command lists

ID3D12DescriptorHeap* rtvDescriptorHeap; // a descriptor heap to hold resources like the render targets

ID3D12Resource* renderTargets[frameBufferCount]; // number of render targets equal to buffer count

ID3D12CommandAllocator* commandAllocator[frameBufferCount]; // we want enough allocators for each buffer * number of threads (we only have one thread)

ID3D12GraphicsCommandList* commandList; // a command list we can record commands into, then execute them to render the frame

ID3D12Fence* fence[frameBufferCount];    // an object that is locked while our command list is being executed by the gpu. We need as many 
                                         //as we have allocators (more if we want to know when the gpu is finished with an asset)

HANDLE fenceEvent; // a handle to an event when our fence is unlocked by the gpu

UINT64 fenceValue[frameBufferCount]; // this value is incremented each frame. each fence will have its own value

int frameIndex; // current rtv we are on

int rtvDescriptorSize; // size of the rtv descriptor on the device (all front and back buffers will be the same size)

// function declarations
bool InitD3D(); // initializes direct3d 12

void Update(); // update the game logic

void UpdatePipeline(); // update the direct3d pipeline (update command lists)

void Render(); // execute the command list

void Cleanup(); // release com ojects and clean up memory

void WaitForPreviousFrame(); // wait until gpu is finished with command list
#pragma endregion D3DPart


// we will exit the program when this becomes false
bool Running = true;

// this will only call release if an object exists (prevents exceptions calling release on non existant objects)
#define SAFE_RELEASE(p) { if ( (p) ) { (p)->Release(); (p) = 0; } }