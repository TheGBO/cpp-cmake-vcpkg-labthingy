// WaveDrawingProgram.hpp
#pragma once
#include <memory>
#include <vector>

#include "SineWave.hpp"
#include "WaveGuiSettings.hpp"
#include "fmt/core.h"
#include "imgui-knobs.h"
#include "imgui.h"
#include "raylib.h"
#include "rlImGui.h"

void ProcessWaves();
void CreateWave();
void RunWaveDrawingProgram();