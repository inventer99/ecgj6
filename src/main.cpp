extern int game_main();

#if defined(GAME_PLATFORM_LINUX) || defined(GAME_PLATFORM_MACOS) || defined(_DEBUG)

int main(int argc, char* argv[]) {
    game_main();
}

#elif defined(GAME_PLATFORM_WINDOWS)

#include <windows.h>


INT WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR lpCmdLine, INT nCmdShow) {
    return game_main();
}

#endif
