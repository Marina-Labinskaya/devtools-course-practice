// Copyright 2022 Labinskaya Marina
#include "../include/vector3d.h"
#include <gtest.h>

TEST(Vector3d, can_create_vector3d_without_parameters)
{
    ASSERT_NO_THROW(Vector3d v);
}

TEST(Vector3d, can_create_vector3d_with_parameters)
{
    ASSERT_NO_THROW(Vector3d(1.0, 2.0, 3.0));
}

TEST(Vector3d, can_create_copy_vector3d)
{
    //Arrange & Act
    Vector3d v;
    ASSERT_NO_THROW(Vector3d v2 = v);
}

TEST(Vector3d, copy_vector3d_is_equal_his_parent)
{
    //Arrange & Act
    Vector3d v;
    Vector3d v2 = v;

    //Assert
    EXPECT_EQ(v, v2);
}

TEST(Vector3d, can_get_coords)
{
    //Arrange & Act
    Vector3d v(1.0, 2.0, 3.0);

    //Assert
    EXPECT_DOUBLE_EQ(v[1], 2.0);
}

TEST(Vector3d, can_set_coords)
{
    //Arrange
    Vector3d v;

    //Act
    v[2] = 1.5;

    //Assert
    EXPECT_DOUBLE_EQ(v[2], 1.5);
}

TEST(Vector3d, cant_get_coords_out_of_range)
{
    //Arrange & Act
    Vector3d v(1.0, 2.0, 3.0);

    //Assert
    ASSERT_ANY_THROW(v[3]);
}

TEST(Vector3d, cant_set_coords_out_of_range)
{
    //Arrange & Act
    Vector3d v(1.0, 2.0, 3.0);

    //Assert
    ASSERT_ANY_THROW(v[3] = 1.0);
}

TEST(Vector3d, can_get_norm_of_vector3d)
{
    //Arrange
    Vector3d v(2.0, 6.0, 3.0);

    //Act
    double norm = v.getNorm();

    //Assert
    EXPECT_NEAR(norm, 7, 1e-9);
}

TEST(Vector3d, can_detect_equal_vectors3d)
{
    //Arrange
    Vector3d v(2.0, 6.0, 3.0);
    Vector3d v2 = v;

    //Assert
    EXPECT_TRUE(v == v2);
}

TEST(Vector3d, can_detect_not_equal_vectors3d)
{
    //Arrange
    Vector3d v(2.0, 6.0, 3.0);
    Vector3d v2(2.0, 6.1, 3.0);

    //Assert
    EXPECT_FALSE(v == v2);
}

TEST(Vector3d, can_get_normalization_of_not_null_vector3d)
{
    //Arrange
    Vector3d v(2.0, 6.0, 3.0);
    Vector3d expect_res(2.0 / 7.0, 6.0 / 7.0, 3.0 / 7.0);
	
    //Act
    Vector3d normalization = v.getNormalization();

    //Assert
    EXPECT_EQ(normalization, expect_res);
}

TEST(Vector3d, cant_get_normalization_of_null_vector3d)
{
    //Arrange & Act
    Vector3d v;

    //Assert
    ASSERT_ANY_THROW(v.getNormalization());
}

TEST(Vector3d, can_calculate_scalar_mult)
{
    //Arrange
    Vector3d v1(3.0, 4.5, 2.0);
    Vector3d v2(1.5, -1.0, 1.0);

    //Act
    double res_of_scalar_mult = scalar_mult(v1, v2);

    //Assert
    EXPECT_DOUBLE_EQ(res_of_scalar_mult, 2.0);
}

TEST(Vector3d, can_calculate_vector_mult)
{
    //Arrange
    Vector3d v1(3.0, 4.0, 2.0);
    Vector3d v2(1.0, -1.0, 1.0);
    Vector3d expect_res(6.0, -1.0, -7.0);

    //Act
    Vector3d res_of_vector_mult = vector_mult(v1, v2);

    //Assert
    EXPECT_EQ(res_of_vector_mult, expect_res);
}