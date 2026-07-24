#include "termographics/camera.hpp"
#include <gtest/gtest.h>

TEST(CameraTestSuite, Constructor_IntendedUse_SavesDataCorrectly)
{
    termg::Vector3I camera_pos(30, 12, 51);
    float camera_yaw = 543534.61f;
    float camera_pitch = 881080.23f;
    termg::Camera camera(camera_pos, camera_yaw, camera_pitch);

    EXPECT_EQ(camera.get_pos().x, camera_pos.x);
    EXPECT_EQ(camera.get_pos().y, camera_pos.y);
    EXPECT_EQ(camera.get_pos().z, camera_pos.z);
    
    float current_yaw = camera.get_rotation().yaw;
    float current_pitch = camera.get_rotation().pitch;

    EXPECT_TRUE(termg::Camera::MAX_YAW >= current_yaw && current_yaw >= termg::Camera::MIN_YAW);
    EXPECT_TRUE(termg::Camera::MAX_PITCH >= current_pitch && current_pitch >= termg::Camera::MIN_PITCH);
}