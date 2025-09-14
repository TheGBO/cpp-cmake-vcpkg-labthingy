// SineWave.hpp
// Header file for the sine wave class, the names
// are as clear as possible, or at leas I think so.
#pragma once
#include <cmath>
#include <vector>

#include "Constants.hpp"
#include "raylib.h"

class SineWave
{
   private:
    // I don't do this in other programming languages like C#, I just use
    // camelCase for private member, however C++ has some goofy ways
    // of handling members and it gets slightly confusing to me, so
    // I added this m_Prefix thing to distinguish them as clearly as I could.
    float m_Amplitude;
    float m_Frequency;
    float m_Phase;
    float m_PhaseSpeed;
    float m_RgbBuffer[3];
    Color m_Color;

    std::vector<Vector2> m_WavePoints;

   public:
    SineWave(float amplitude, float frequency, float phase, float phaseSpeed,
             Color color);

    void Update(float elapsedTime, int screenWidth, int screenHeight,
                int step = 2);
    void Draw() const;

    float& Amplitude();
    float& Frequency();
    float& Phase();
    float& PhaseSpeed();
    float* RgbColor();

    void SyncColorFromRgb();
};
