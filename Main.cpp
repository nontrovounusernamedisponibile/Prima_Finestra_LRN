#include <windows.h>

int WINAPI wWinMain(HINSTANCE hInst, HINSTANCE hPrevHinst, LPWSTR args, int nCmdShow){

    MessageBoxW(NULL, L"Hello World" , L"Finestra" , MB_OK);

    return 0;
}