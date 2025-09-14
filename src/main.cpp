#include "Main.hpp"

int main() {
    fmt::println("INITIALIZED THE THINGAMAJACKSON");
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(800, 600, "THE THINGAMAJACKSON");
    
    SetTargetFPS(60);
    rlImGuiSetup(true);

    SineWave* acWave = new SineWave(120, 60, 0, 0, GREEN);

    while (!WindowShouldClose())
    {
        ImVec2 proportions = ImVec2(350, GetScreenHeight());
        elapsedTime += GetFrameTime();
        if(((int)elapsedTime % 1) == 0){
            //fmt::println("Elapsed time: {}", floor(elapsedTime));
            //doesn't work as expected lol
        }
        
        BeginDrawing();
        ClearBackground(BLACK);
        
        //generate wave points
        //draw waves and stuff
        acWave->Update(elapsedTime, GetScreenWidth(), GetScreenHeight());
        acWave->Draw();

        rlImGuiBegin();
        ImGui::SetNextWindowPos(ImVec2(0, 0));
        ImGui::SetNextWindowSize(proportions);
        ImGui::Begin("THE THINGAMAJACKSON", nullptr, ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoCollapse);
        
        ImGui::SliderFloat("Amplitude", &acWave->Amplitude(), 0.0f, GetScreenHeight() / 2.0f);
        ImGui::SliderFloat("Frequency", &acWave->Frequency(), 0.1f, 200.0f, "%.1f", ImGuiSliderFlags_Logarithmic);
        ImGui::SliderFloat("Phase (deg)", &acWave->Phase(), 0.0f, 360.0f);
        ImGui::SliderFloat("Phase Speed", &acWave->PhaseSpeed(), -10.0f, 10.0f);

        ImGui::End();
        rlImGuiEnd();
        EndDrawing();
    }
    rlImGuiShutdown();
    CloseWindow();
    return 0;
}
