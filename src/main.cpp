#include <fmt/core.h>
#include <raylib.h>
#include "WindowProperties.hpp"
#include "imgui.h"
#include "rlImGui.h"
#include <vector>

int main() {
    int frequency = 10;
    int amplitude = 5;

    struct WindowProperties properties = {
        800,
        600
    };

    fmt::println("INITIALIZED THE THINGAMAJACKSON");

    InitWindow(properties.windowWidth, properties.windowHeight, "THE THINGAMAJACKSON");

    rlImGuiSetup(true);
    while (!WindowShouldClose())
    {

        BeginDrawing();
        ClearBackground(RAYWHITE);

        for (int i = 0; i < properties.windowWidth; i++)
        {

            float yDisplacement = sin(i * frequency * 2 * PI/properties.windowWidth) * amplitude;
            DrawPixel(i, properties.windowHeight/2 + yDisplacement, RED);
        }

        rlImGuiBegin();
        ImGui::SetNextWindowPos(ImVec2(0, 0));
        ImGui::SetNextWindowSize(ImVec2(250, 150));
        ImGui::Begin("THE THINGAMAJACKSON", nullptr, ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse);
        ImGui::SliderInt("amplitude", &amplitude, -100, 100);
        ImGui::SliderInt("frequency", &frequency, 0, 100);

        ImGui::End();
        rlImGuiEnd();
        EndDrawing();
    }
    rlImGuiShutdown();
    CloseWindow();
    return 0;
}
