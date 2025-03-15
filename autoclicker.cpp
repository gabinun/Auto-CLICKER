#include <windows.h>
#include <atomic>

std::atomic<bool> clicking(false);
HHOOK keyboardHook;

LRESULT CALLBACK KeyboardProc(int n, WPARAM w, LPARAM l) {
    if (((KBDLLHOOKSTRUCT*)l)->vkCode == VK_OEM_3) {
        if (w == WM_KEYDOWN) clicking = !clicking;
        return 1;
    }
    return CallNextHookEx(0, n, w, l);
}

int main() {
    keyboardHook = SetWindowsHookEx(WH_KEYBOARD_LL, KeyboardProc, 0, 0);
    MSG msg;
    while (true) {
        if (clicking) {
            mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
            mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
            Sleep(5);
        } else {
            Sleep(50);
        }
        while (PeekMessage(&msg, 0, 0, 0, PM_REMOVE)) DispatchMessage(&msg);
    }
}
