#include "SineWave.hpp"

SineWave::SineWave(float amplitude, float frequency, float phase, float phaseSpeed, Color color)
    : m_Amplitude(amplitude), m_Frequency(frequency),
      m_Phase(phase), m_PhaseSpeed(phaseSpeed), m_Color(color) {}

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
