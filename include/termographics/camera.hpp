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
    int m_rotation_angle = 0;

    inline int normalize_rotation_angle(int angle) { return (angle % 360 + 360) % 360; }
    
public:
    Camera(Vector3I pos = Vector3I(0, 0, 0), int rotation_angle = 0) : m_pos(pos), m_rotation_angle(normalize_rotation_angle(rotation_angle)) {}

    Vector3I get_pos() { return m_pos; }

    void set_pos(Vector3I new_pos) { m_pos = std::move(new_pos); }

    int get_rotation_angle() { return m_rotation_angle; }

    void set_rotation_angle(int new_angle) { m_rotation_angle = normalize_rotation_angle(new_angle); }

    void add_rotation_angle(int delta) { m_rotation_angle = normalize_rotation_angle(m_rotation_angle + delta); }
};

}