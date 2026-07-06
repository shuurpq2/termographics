#pragma once

#include "termographics/vector3i.hpp"
#include <memory>

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

    void set_pos(Vector3I new_pos) { m_pos = std::move(new_pos); }

    int get_rotation_angle() { return m_rot_angle; }

    void set_rotation_angle(int new_angle) { m_rot_angle = new_angle; }

    void add_rotation_angle(int delta) { m_rot_angle += delta; }
};

}