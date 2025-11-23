#include <windows.h>

LRESULT CALLBACK WindowProc(HWND, UINT, WPARAM, LPARAM);

int WINAPI wWinMain(HINSTANCE hInst, HINSTANCE hPrevHinst, LPWSTR arguments, int nCmdShow){

    WNDCLASSW wc = {0};

    wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
    wc.hCursor = LoadCursor(NULL, IDC_HAND);
    wc.hInstance = hInst;
    wc.lpszClassName = L"WindowClass";
    wc.lpfnWndProc = WindowProc;

    if(!RegisterClassW(&wc)){
        return -1;
    }
    
    CreateWindowW(L"WindowClass", L" Finestra", WS_OVERLAPPEDWINDOW | WS_VISIBLE, 100 ,100, 500, 500, NULL, NULL, NULL, NULL);

    MSG msg = {0};

    while(GetMessage(&msg, NULL, 0, 0) ){
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}

LRESULT CALLBACK WindowProc(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp){

    switch(msg){
        case WM_DESTROY :
            PostQuitMessage(0);
            break;
            
    }
    return DefWindowProcW(hWnd, msg, wp, lp);
}