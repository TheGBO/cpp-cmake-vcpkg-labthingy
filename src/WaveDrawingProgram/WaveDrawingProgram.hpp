// WaveDrawingProgram.hpp
#pragma once
#include <vector>
#include <memory>
#include "raylib.h"
#include "SineWave.hpp"
#include "imgui.h"
#include "rlImGui.h"
#include "fmt/core.h"
#include "WaveGuiSettings.hpp"
#include "imgui-knobs.h"

void ProcessWaves();
void CreateWave();
void RunWaveDrawingProgram();