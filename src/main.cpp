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
    SetTargetFPS(60);
    rlImGuiSetup(true);
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        
        std::vector<Vector2> points;
        int segments = properties.windowWidth;


        for (int i = 0; i <= segments; i++)
        {

            float x = (float)i;
            //x = t
            //y = A sin(omega * x)
            float omega = frequency * 2*PI/properties.windowWidth;
            float y = amplitude * sin(x * omega);

            points.push_back({x, properties.windowHeight/2 + y});
        }

        for (size_t i = 1; i < points.size(); i++)
        {
            DrawLineV(points[i-1], points[i], RED);
        }
        

        rlImGuiBegin();
        ImGui::SetNextWindowPos(ImVec2(0, 0));
        ImGui::SetNextWindowSize(ImVec2(250, 150));
        ImGui::Begin("THE THINGAMAJACKSON", nullptr, ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse);
        ImGui::SliderInt("amplitude", &amplitude, -properties.windowHeight/2, properties.windowHeight/2);
        ImGui::SliderInt("frequency", &frequency, 0, 300);

        ImGui::End();
        rlImGuiEnd();
        EndDrawing();
    }
    rlImGuiShutdown();
    CloseWindow();
    return 0;
}
