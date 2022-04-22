//Copyright 2022 Labinskaya Marina
#include "vector3d.h"

Vector3d::Vector3d(): data{ 0.0, 0.0, 0.0 } {}

Vector3d::Vector3d(double x, double y, double z): data { x, y, z } {}

Vector3d::Vector3d(const Vector3d& v) : data{v[0], v[1], v[2]} {}

double& Vector3d::operator[](double idx)
{
	if (idx < 0 || idx > 2)
		throw std::out_of_range("Expression: vector subscript out of range.");
	return data[idx];
}
const double& Vector3d::operator[](double idx) const
{
	if (idx < 0 || idx > 2)
		throw std::out_of_range("Expression: vector subscript out of range.");
	return data[idx];
}

double Vector3d::getNorm()
{
	return std::sqrt(data[0] * data[0] + data[1] * data[1] + data[2] * data[2]);
}

Vector3d Vector3d::getNormalization()
{
	double norm = this->getNorm();
	Vector3d res(data[0] / norm, data[1] / norm, data[2] / norm);
	return res;
}

bool operator ==(const Vector3d& v1, const Vector3d& v2)
{
	if (v1[0] == v2[0] && v1[1] == v2[1] && v1[2] == v2[2])
		return true;
	else 
		return false;
}