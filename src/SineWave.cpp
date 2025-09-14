//SineWave.cpp
//Definitions for the SineWave.hpp class
#include "SineWave.hpp"


SineWave::SineWave(float amplitude, float frequency, float phase, float phaseSpeed, Color color)
    : m_Amplitude(amplitude), m_Frequency(frequency),
      m_Phase(phase), m_PhaseSpeed(phaseSpeed), m_Color(color) 
    {
        m_RgbBuffer[0] = m_Color.r / 255.0f;
        m_RgbBuffer[1] = m_Color.g / 255.0f;
        m_RgbBuffer[2] = m_Color.b / 255.0f;
    }

void SineWave::Update(float elapsedTime, int screenWidth, int screenHeight, int step)
{
    int segments = screenWidth / step;
    m_WavePoints.resize(segments + 1);

    for (int i = 0; i <= segments; i++)
    {
        float x = static_cast<float>(i * step);
        float phi = (m_Phase * DEG2RAD) + elapsedTime * m_PhaseSpeed;
        float omega = m_Frequency * TAU / static_cast<float>(screenWidth);
        float y = m_Amplitude * sin(x * omega + phi);

        m_WavePoints[i] = {x, screenHeight / 2.0f + y};
    }
}

void SineWave::Draw() const
{
    for (size_t i = 1; i < m_WavePoints.size(); i++)
    {
        DrawLineV(m_WavePoints[i - 1], m_WavePoints[i], m_Color);
    }
}

float& SineWave::Amplitude() { return m_Amplitude; }
float& SineWave::Frequency() { return m_Frequency; }
float& SineWave::Phase() { return m_Phase; }
float& SineWave::PhaseSpeed() { return m_PhaseSpeed; }
float* SineWave::RgbColor()
{
    m_RgbBuffer[0] = m_Color.r / 255.0f;
    m_RgbBuffer[1] = m_Color.g / 255.0f;
    m_RgbBuffer[2] = m_Color.b / 255.0f;
    return m_RgbBuffer;
}

void SineWave::SyncColorFromRgb()
{
    // Convert ImGui format (0.0-1.0) back to raylib Color (0-255)
    m_Color.r = static_cast<unsigned char>(m_RgbBuffer[0] * 255.0f);
    m_Color.g = static_cast<unsigned char>(m_RgbBuffer[1] * 255.0f);
    m_Color.b = static_cast<unsigned char>(m_RgbBuffer[2] * 255.0f);
}