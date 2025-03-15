#include <iostream>
#include <windows.h>
#include <atomic>

std::atomic<bool> clicking(false);

int main() {
    while (true) {
        if (GetAsyncKeyState(VK_OEM_3) & 1) {
            clicking = !clicking;
            Sleep(200); // Prevent key spam
        }
        if (GetAsyncKeyState(VK_ESCAPE) & 1) {
            break;
        }
        if (clicking.load()) {
            mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
            mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
            Sleep(5);  // Faster clicks
        } else {
            Sleep(50); // Reduce CPU usage when idle
        }
    }
    return 0;
}
