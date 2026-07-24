#pragma once

#include "termographics/vector3i.hpp"
#include <memory>
#include <cmath>
#include <algorithm>

namespace termg
{

class Camera
{
private:
    struct Rotation
    {
        float yaw;
        float pitch;
    };

public:
    static constexpr float MAX_YAW = 180.0f;
    static constexpr float MIN_YAW = -180.0f;
    static constexpr float MAX_PITCH = 90.0f;
    static constexpr float MIN_PITCH = -90.0f;

    Camera(Vector3I pos = Vector3I(0, 0, 0), float yaw = 0, float pitch = 0) : m_pos(pos), m_rotation({normalize_yaw(yaw), normalize_pitch(pitch)}) {}

    Vector3I get_pos() { return m_pos; }
    void set_pos(Vector3I new_pos) { m_pos = std::move(new_pos); }

    Rotation get_rotation() { return m_rotation; }
    void set_rotation(int yaw, int pitch) { set_yaw(yaw); set_pitch(pitch); }
    void set_yaw(int angle) { m_rotation.yaw = normalize_yaw(angle); }
    void add_yaw(int delta) { m_rotation.yaw = normalize_yaw(m_rotation.yaw + delta); }
    void set_pitch(int angle) { m_rotation.pitch = normalize_pitch(angle); }
    void add_pitch(int delta) { m_rotation.pitch = normalize_pitch(m_rotation.pitch + delta); }

private:
    Vector3I m_pos = Vector3I(0, 0, 0);
    Rotation m_rotation = {.yaw=0.0f, .pitch=0.0f};

    inline float normalize_yaw(float angle)
    {
        angle = std::fmod(angle, 360.0f);

        if (angle >= MAX_YAW) angle -= 360.0f;
        else if (angle < MIN_YAW) angle += 360.0f;

        return angle;
    }
    inline float normalize_pitch(float angle) { return std::min(std::max(angle, MIN_PITCH), MAX_PITCH); }
};

}