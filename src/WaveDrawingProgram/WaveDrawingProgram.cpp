// WaveDrawingProgram.cpp
// This is the program that draws waves, I am considering making it
// inherit some sort of abstract program class in the future as it could
// benefit from polymorphism (If this words means what I think it does)
#include "WaveDrawingProgram.hpp"

std::vector<std::unique_ptr<SineWave>> waves;
float elapsedTime;
int currentWaveIndex;
WaveGuiSettings guiSettings;

void ProcessWaves()
{
    for (auto& wave : waves)
    {
        wave->Update(elapsedTime, GetScreenWidth(), GetScreenHeight());
        wave->Draw();
    }
}

void CreateWave()
{
    // GetRandomValue()
    unsigned char r = GetRandomValue(0, 255);
    unsigned char g = GetRandomValue(0, 255);
    unsigned char b = GetRandomValue(0, 255);

    Color randomColor = Color({r, g, b, 255});

    float randomAmplitude =
        GetRandomValue(guiSettings.minAmplitude, guiSettings.maxAmplitude);
    float randomFrequency =
        GetRandomValue(guiSettings.minFrequency, guiSettings.maxFrequency);
    float randomPhase =
        GetRandomValue(guiSettings.minPhase, guiSettings.maxPhase);
    std::unique_ptr<SineWave> waveToBeAdded = std::make_unique<SineWave>(
        randomAmplitude, randomFrequency, randomPhase, 0, randomColor);
    waves.push_back(std::move(waveToBeAdded));
    currentWaveIndex = waves.size() - 1;
}

void UpdateGuiSettings()
{
    guiSettings.minAmplitude = 0;
    guiSettings.maxAmplitude = GetScreenHeight() / 2.0f;
    guiSettings.minFrequency = 0;
    guiSettings.maxFrequency = 128.0f;
    guiSettings.minPhase = 0;
    guiSettings.maxPhase = 360.0f;
    guiSettings.minPhaseSpeed = -100.0f;
    guiSettings.maxPhaseSpeed = 100.0f;
}

void RunWaveDrawingProgram()
{
    fmt::println("INITIALIZED THE THINGAMAJACKSON");

    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(800, 600, "THE THINGAMAJACKSON :: WAVE DRAWING EDITION");

    SetTargetFPS(60);
    rlImGuiSetup(true);
    UpdateGuiSettings();
    CreateWave();

    while (!WindowShouldClose())
    {
        ImVec2 proportions = ImVec2(350, GetScreenHeight());
        elapsedTime += GetFrameTime();

        BeginDrawing();
        ClearBackground(BLACK);
        // draw waves and stuff
        ProcessWaves();

        rlImGuiBegin();
        ImGui::SetNextWindowPos(ImVec2(0, 0));
        ImGui::SetNextWindowSize(proportions);
        ImGui::Begin("THE THINGAMAJACKSON", nullptr,
                     ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoCollapse);

        // set the guiSettings parameters.
        UpdateGuiSettings();

        if (!waves.empty())
        {
            SineWave* currentWave =
                waves[currentWaveIndex].get();  // raw pointer for convenience
            // wave index
            ImGui::SliderInt("Selected wave", &currentWaveIndex, 0,
                             waves.size() - 1);
            // amplitude
            ImGui::SliderFloat("Amplitude", &currentWave->Amplitude(),
                               guiSettings.minAmplitude,
                               guiSettings.maxAmplitude, "%.1f");
            // frequency
            ImGui::SliderFloat("Frequency", &currentWave->Frequency(),
                               guiSettings.minFrequency,
                               guiSettings.maxFrequency, "%.1f",
                               ImGuiSliderFlags_Logarithmic);
            // phase
            float phase = currentWave->Phase();
            if (ImGuiKnobs::Knob("Phase", &phase, guiSettings.minPhase,
                                 guiSettings.maxPhase, 15.0f, "%.1f deg",
                                 ImGuiKnobFlags_ValueTooltip))
            {
                currentWave->Phase() = phase;
            }
            ImGui::SliderFloat("Phase Speed", &currentWave->PhaseSpeed(),
                               guiSettings.minPhaseSpeed,
                               guiSettings.maxPhaseSpeed, "%.1f",
                               ImGuiSliderFlags_Logarithmic);
            // color
            if (ImGui::ColorEdit3("RGB", currentWave->RgbColor()))
            {
                currentWave->SyncColorFromRgb();
            }
            if (ImGui::Button("Create Wave"))
            {
                CreateWave();
            }
        }

        ImGui::End();
        rlImGuiEnd();
        EndDrawing();
    }
    rlImGuiShutdown();
    CloseWindow();
}