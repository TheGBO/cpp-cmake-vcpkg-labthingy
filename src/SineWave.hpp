#pragma once
#include "Includes.hpp"

class SineWave
{
private:
    float m_Amplitude;
    float m_Frequency;
    float m_Phase;
    float m_PhaseSpeed;
    Color m_Color;

    std::vector<Vector2> m_WavePoints;

public:
    SineWave(float amplitude, float frequency, float phase, float phaseSpeed, Color color);

    void Update(float elapsedTime, int screenWidth, int screenHeight, int step = 2);
    void Draw() const;

    float& Amplitude();
    float& Frequency();
    float& Phase();
    float& PhaseSpeed();
};
