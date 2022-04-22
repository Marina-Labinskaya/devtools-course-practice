// Copyright 2022 Labinskaya Marina
#ifndef MODULES_VECTOR3D_OPERATIONS_INCLUDE_VECTOR3D_H_
#define MODULES_VECTOR3D_OPERATIONS_INCLUDE_VECTOR3D_H_

#include <vector>
#include <random>

class Vector3d {
 protected:
    std::vector<double> data;
 public:
    Vector3d();
    Vector3d(double x, double y, double z);
    double& operator[](double idx);
    const double& operator[](double idx) const;
    double getNorm();
    Vector3d getNormalization();
};

bool operator ==(const Vector3d& v1, const Vector3d& v2);
double scalar_mult(const Vector3d& v1, const Vector3d& v2);
Vector3d vector_mult(const Vector3d& v1, const Vector3d& v2);
#endif  // MODULES_VECTOR3D_OPERATIONS_INCLUDE_VECTOR3D_H_
