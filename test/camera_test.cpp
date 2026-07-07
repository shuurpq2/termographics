#include "termographics/camera.hpp"
#include <gtest/gtest.h>

TEST(CameraTestSuite, Constructor_IntendedUse_SavesDataCorrectly)
{
    termg::Vector3I camera_pos(30, 12, 51);
    int camera_yaw = 543534;
    termg::Camera camera(camera_pos, camera_yaw);

    EXPECT_EQ(camera.get_pos().x, camera_pos.x);
    EXPECT_EQ(camera.get_pos().y, camera_pos.y);
    EXPECT_EQ(camera.get_pos().z, camera_pos.z);
    EXPECT_TRUE(camera.get_yaw() >= 0 && camera.get_yaw() < 360);
}