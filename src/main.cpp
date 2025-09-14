#include "Main.hpp"

std::vector<std::unique_ptr<SineWave>> waves;

void ProcessWaves(){
    for(auto& wave : waves){
        wave->Update(elapsedTime, GetScreenWidth(), GetScreenHeight());
        wave->Draw();
    }
}

void CreateWave(){
    waves.push_back(std::make_unique<SineWave>(120, 60, 0, 0, GREEN));
    currentWaveIndex = waves.size()-1;
}

int main() {
    fmt::println("INITIALIZED THE THINGAMAJACKSON");
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(800, 600, "THE THINGAMAJACKSON");
    
    SetTargetFPS(60);
    rlImGuiSetup(true);

    CreateWave();

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
        //draw waves and stuff
        ProcessWaves();

        rlImGuiBegin();
        ImGui::SetNextWindowPos(ImVec2(0, 0));
        ImGui::SetNextWindowSize(proportions);
        ImGui::Begin("THE THINGAMAJACKSON", nullptr, ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoCollapse);
        
        if (!waves.empty()) {
            SineWave* currentWave = waves[currentWaveIndex].get(); // raw pointer for convenience
            ImGui::SliderInt("Selected wave", &currentWaveIndex, 0, waves.size() - 1);
            ImGui::SliderFloat("Amplitude", &currentWave->Amplitude(), 0.0f, GetScreenHeight() / 2.0f);
            ImGui::SliderFloat("Frequency", &currentWave->Frequency(), 0.1f, 200.0f, "%.1f", ImGuiSliderFlags_Logarithmic);
            ImGui::SliderFloat("Phase (deg)", &currentWave->Phase(), 0.0f, 360.0f);
            ImGui::SliderFloat("Phase Speed", &currentWave->PhaseSpeed(), -10.0f, 10.0f);
            if(ImGui::ColorEdit3("RGB", currentWave->RgbColor())){
                currentWave->SyncColorFromRgb();
            }
            if(ImGui::Button("Create Wave")){
                CreateWave();
            }
        }

        ImGui::End();
        rlImGuiEnd();
        EndDrawing();
    }
    rlImGuiShutdown();
    CloseWindow();
    return 0;
}
