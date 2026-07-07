#pragma once

#include "termographics/vector3i.hpp"
#include <memory>
#include <math.h>

namespace termg
{

class Camera
{
private:
    Vector3I m_pos = Vector3I(0, 0, 0);
    int m_yaw = 0;

    inline int normalize_yaw(int angle) { return (angle % 360 + 360) % 360; }
    // TODO: pitch
public:
    Camera(Vector3I pos = Vector3I(0, 0, 0), int yaw = 0) : m_pos(pos), m_yaw(normalize_yaw(yaw)) {}

    Vector3I get_pos() { return m_pos; }

    void set_pos(Vector3I new_pos) { m_pos = std::move(new_pos); }

    int get_yaw() { return m_yaw; }

    void set_yaw(int angle) { m_yaw = normalize_yaw(angle); }

    void add_yaw(int delta) { m_yaw = normalize_yaw(m_yaw + delta); }
};

}