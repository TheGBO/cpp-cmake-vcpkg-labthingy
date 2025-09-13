#include <fmt/core.h>
#include <raylib.h>

int main() {
    fmt::println("Hello, raylib + fmt!");

    InitWindow(800, 600, "Raylib Window Example");

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("Hello, raylib!", 190, 200, 20, LIGHTGRAY);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
