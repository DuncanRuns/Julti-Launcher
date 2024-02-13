#include <windows.h>
#include <stdio.h>
#include <string.h>

int main() {
    WIN32_FIND_DATA findFileData;
    HANDLE hFind = FindFirstFile("Julti*.jar", &findFileData);

    if (hFind == INVALID_HANDLE_VALUE) {
        MessageBox(NULL, "No Julti jar was found!", "Error", MB_ICONERROR | MB_OK);
        return 1;
    }

    char* filename = findFileData.cFileName;
    FindClose(hFind);

    char command[1024];
    snprintf(command, sizeof(command), "javaw -jar \"%s\"", filename);

    STARTUPINFO si = { sizeof(STARTUPINFO) };
    PROCESS_INFORMATION pi;

    // CreateProcess parameters for hiding the console window
    si.dwFlags |= STARTF_USESHOWWINDOW;
    si.wShowWindow = SW_HIDE;

    if (CreateProcess(NULL, command, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi)) {
        WaitForSingleObject(pi.hProcess, INFINITE);
        CloseHandle(pi.hProcess);
        CloseHandle(pi.hThread);
    } else {
        return 1;
    }

    return 0;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    return main();
}