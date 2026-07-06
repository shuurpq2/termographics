#pragma once

#include "termographics/vector3i.hpp"

namespace termg
{

class Camera
{
private:
    Vector3I m_pos = Vector3I(0, 0, 0);
    int m_rot_angle = 0;

public:
    Camera(Vector3I pos = Vector3I(0, 0, 0), int rotation_angle = 0) : m_pos(pos), m_rot_angle(rotation_angle) {}

    Vector3I get_pos() { return m_pos; }
    int get_rotation_angle() { return m_rot_angle; }
};

}