/*!
 * @file maths.cpp
 * @brief Implementation file for the nonmember maths functions.
 * @author George McDonagh */


// Local includes

#include "maths\maths.h"


float engine::maths::degrees(float radians)
{
	return radians * 180.0f / MATH_PI;
}

float engine::maths::radians(float degrees)
{
	return degrees * MATH_PI / 180.0f;
}

engine::maths::Vec2 engine::maths::normalize(const Vec2& vec2)
{
	return vec2 / vec2.magnitude();
}

engine::maths::Vec3 engine::maths::normalize(const Vec3& vec3)
{
	return vec3 / vec3.magnitude();
}

engine::maths::Vec4 engine::maths::normalize(const Vec4& vec4)
{
	return vec4 / vec4.magnitude();
}

float engine::maths::dot(const Vec3& vec3a, const Vec3& vec3b)
{
	return vec3a.x() * vec3b.x() + vec3a.y() * vec3b.y() + vec3a.z() * vec3b.z();
}

engine::maths::Vec3 engine::maths::cross(const Vec3& vec3a, const Vec3& vec3b)
{
	return Vec3(
		vec3a.y() * vec3b.z() - vec3a.z() * vec3b.y(),
		vec3a.z() * vec3b.x() - vec3a.x() * vec3b.z(),
		vec3a.x() * vec3b.y() - vec3a.y() * vec3b.x());
}

engine::maths::Mat2 engine::maths::identityMat2()
{
	return Mat2();
}

engine::maths::Mat3 engine::maths::identityMat3()
{
	return Mat3();
}

engine::maths::Mat4 engine::maths::identityMat4()
{
	return Mat4();
}

engine::maths::Mat4 engine::maths::translation(const Vec3& t)
{
	return Mat4(
		1.0f,  0.0f,  0.0f,  0.0f,
		0.0f,  1.0f,  0.0f,  0.0f,
		0.0f,  0.0f,  1.0f,  0.0f,
		t.x(), t.y(), t.z(), 1.0f);
}

engine::maths::Mat4 engine::maths::scale(const Vec3& s)
{
	return Mat4(
		s.x(), 0.0f,  0.0f,  0.0f,
		0.0f,  s.y(), 0.0f,  0.0f,
		0.0f,  0.0f,  s.z(), 0.0f,
		0.0f,  0.0f,  0.0f,  1.0f);
}

engine::maths::Mat4 engine::maths::rotationX(float x)
{
	x = radians(x);
	return Mat4(
		1.0f,  0.0f,   0.0f,   0.0f,
		0.0f,  cos(x), sin(x), 0.0f,
		0.0f, -sin(x), cos(x), 0.0f,
		0.0f,  0.0f,   0.0f,   1.0f);
}

engine::maths::Mat4 engine::maths::rotationY(float y)
{
	y = radians(y);
	return Mat4(
		cos(y), 0.0f, -sin(y), 0.0f,
		0.0f,	1.0f,  0.0f,   0.0f,
		sin(y), 0.0f,  cos(y), 0.0f,
		0.0f,   0.0f,  0.0f,   1.0f);
}

engine::maths::Mat4 engine::maths::rotationZ(float z)
{
	z = radians(z);
	return Mat4(
		 cos(z),  sin(z), 0.0f, 0.0f,
		-sin(z),  cos(z), 0.0f, 0.0f,
		 0.0f,    0.0f,   1.0f, 0.0f,
		 0.0f,    0.0f,   0.0f, 1.0f);
}

engine::maths::Mat4 engine::maths::rotation(const Vec3& r)
{
	return rotationZ(r.z()) * rotationY(r.y()) * rotationX(r.x());
}

engine::maths::Mat2 engine::maths::inverse(const Mat2& mat2)
{
	return (1.0f / mat2.determinant()) * Mat2(mat2(1, 1), -mat2(0, 1), -mat2(1, 0), mat2(0, 0));
}

engine::maths::Mat3 engine::maths::inverse(const Mat3& mat3)
{
	return (1.0f / mat3.determinant()) * transpose(Mat3(
		 maths::Mat2(mat3(1, 1), mat3(1, 2), mat3(2, 1), mat3(2, 2)).determinant(),
		-maths::Mat2(mat3(1, 0), mat3(1, 2), mat3(2, 0), mat3(2, 2)).determinant(),
		 maths::Mat2(mat3(1, 0), mat3(1, 1), mat3(2, 0), mat3(2, 1)).determinant(),

		-maths::Mat2(mat3(0, 1), mat3(0, 2), mat3(2, 1), mat3(2, 2)).determinant(),
		 maths::Mat2(mat3(0, 0), mat3(0, 2), mat3(2, 0), mat3(2, 2)).determinant(),
		-maths::Mat2(mat3(0, 0), mat3(0, 1), mat3(2, 0), mat3(2, 1)).determinant(),

		 maths::Mat2(mat3(0, 1), mat3(0, 2), mat3(1, 1), mat3(1, 2)).determinant(),
		-maths::Mat2(mat3(0, 0), mat3(0, 2), mat3(1, 0), mat3(1, 2)).determinant(),
		 maths::Mat2(mat3(0, 0), mat3(0, 1), mat3(1, 0), mat3(1, 1)).determinant()));
}

engine::maths::Mat4 engine::maths::inverse(const Mat4& mat4)
{
	return (1.0f / mat4.determinant()) * transpose(Mat4(
		 Mat3(mat4(1, 1), mat4(1, 2), mat4(1, 3), mat4(2, 1), mat4(2, 2), mat4(2, 3), mat4(3, 1), mat4(3, 2), mat4(3, 3)).determinant(),
		-Mat3(mat4(1, 0), mat4(1, 2), mat4(1, 3), mat4(2, 0), mat4(2, 2), mat4(2, 3), mat4(3, 0), mat4(3, 2), mat4(3, 3)).determinant(),
		 Mat3(mat4(1, 0), mat4(1, 1), mat4(1, 3), mat4(2, 0), mat4(2, 1), mat4(2, 3), mat4(3, 0), mat4(3, 1), mat4(3, 3)).determinant(),
		-Mat3(mat4(1, 0), mat4(1, 1), mat4(1, 2), mat4(2, 0), mat4(2, 1), mat4(2, 2), mat4(3, 0), mat4(3, 1), mat4(3, 2)).determinant(),

		-Mat3(mat4(0, 1), mat4(0, 2), mat4(0, 3), mat4(2, 1), mat4(2, 2), mat4(2, 3), mat4(3, 1), mat4(3, 2), mat4(3, 3)).determinant(),
		 Mat3(mat4(0, 0), mat4(0, 2), mat4(0, 3), mat4(2, 0), mat4(2, 2), mat4(2, 3), mat4(3, 0), mat4(3, 2), mat4(3, 3)).determinant(),
		-Mat3(mat4(0, 0), mat4(0, 1), mat4(0, 3), mat4(2, 0), mat4(2, 1), mat4(2, 3), mat4(3, 0), mat4(3, 1), mat4(3, 3)).determinant(),
		 Mat3(mat4(0, 0), mat4(0, 1), mat4(0, 2), mat4(2, 0), mat4(2, 1), mat4(2, 2), mat4(3, 0), mat4(3, 1), mat4(3, 2)).determinant(),

		 Mat3(mat4(0, 1), mat4(0, 2), mat4(0, 3), mat4(1, 1), mat4(1, 2), mat4(1, 3), mat4(3, 1), mat4(3, 2), mat4(3, 3)).determinant(),
		-Mat3(mat4(0, 0), mat4(0, 2), mat4(0, 3), mat4(1, 0), mat4(1, 2), mat4(1, 3), mat4(3, 0), mat4(3, 2), mat4(3, 3)).determinant(),
		 Mat3(mat4(0, 0), mat4(0, 1), mat4(0, 3), mat4(1, 0), mat4(1, 1), mat4(1, 3), mat4(3, 0), mat4(3, 1), mat4(3, 3)).determinant(),
		-Mat3(mat4(0, 0), mat4(0, 1), mat4(0, 2), mat4(1, 0), mat4(1, 1), mat4(1, 2), mat4(3, 0), mat4(3, 1), mat4(3, 2)).determinant(),

		-Mat3(mat4(0, 1), mat4(0, 2), mat4(0, 3), mat4(1, 1), mat4(1, 2), mat4(1, 3), mat4(2, 1), mat4(2, 2), mat4(2, 3)).determinant(),
		 Mat3(mat4(0, 0), mat4(0, 2), mat4(0, 3), mat4(1, 0), mat4(1, 2), mat4(1, 3), mat4(2, 0), mat4(2, 2), mat4(2, 3)).determinant(),
		-Mat3(mat4(0, 0), mat4(0, 1), mat4(0, 3), mat4(1, 0), mat4(1, 1), mat4(1, 3), mat4(2, 0), mat4(2, 1), mat4(2, 3)).determinant(),
		 Mat3(mat4(0, 0), mat4(0, 1), mat4(0, 2), mat4(1, 0), mat4(1, 1), mat4(1, 2), mat4(2, 0), mat4(2, 1), mat4(2, 2)).determinant()));
}

engine::maths::Mat2 engine::maths::transpose(const Mat2& mat2)
{
	return Mat2(
		mat2(0, 0), mat2(1, 0),
		mat2(0, 1), mat2(1, 1));
}

engine::maths::Mat3 engine::maths::transpose(const Mat3& mat3)
{
	return Mat3(
		mat3(0, 0), mat3(1, 0), mat3(2, 0),
		mat3(0, 1), mat3(1, 1), mat3(2, 1),
		mat3(0, 2), mat3(1, 2), mat3(2, 2));
}

engine::maths::Mat4 engine::maths::transpose(const Mat4& mat4)
{
	return Mat4(
		mat4(0, 0), mat4(1, 0), mat4(2, 0), mat4(3, 0),
		mat4(0, 1), mat4(1, 1), mat4(2, 1), mat4(3, 1),
		mat4(0, 2), mat4(1, 2), mat4(2, 2), mat4(3, 2),
		mat4(0, 3), mat4(1, 3), mat4(2, 3), mat4(3, 3));
}

engine::maths::Mat4 engine::maths::lookAt(const Vec3& eye, const Vec3& at, const Vec3& up)
{
	Vec3 zAxis = normalize(at - eye);
	Vec3 xAxis = normalize(cross(up, zAxis));
	Vec3 yAxis = cross(zAxis, xAxis);

	return Mat4(
		xAxis.x(),		yAxis.x(),		zAxis.x(),		0.0f,
		xAxis.y(),		yAxis.y(),		zAxis.y(),		0.0f,
		xAxis.z(),		yAxis.z(),		zAxis.z(),		0.0f,
		dot(xAxis, eye), dot(yAxis, eye), dot(zAxis, eye), 1.0f);
}

engine::maths::Mat4 engine::maths::perspective(float fov, float aspect, float nearClip, float farClip)
{
	float yScale = 1.0f / tan(0.5f * fov);
	float xScale = yScale / aspect;
	float nearmfar = nearClip - farClip;

	return Mat4(
		xScale, 0,		0,								   0,
		0,		yScale, 0,								   0,
		0,		0,		(farClip + nearClip) / nearmfar,  -1,
		0,		0,		2 * farClip * nearClip / nearmfar, 0);
}

engine::maths::Mat2 engine::maths::operator*(float f, const Mat2& mat2)
{
	Mat2 m(mat2);
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
			m(i, j) *= f;

	return m;
}

engine::maths::Mat3 engine::maths::operator*(float f, const Mat3& mat3)
{
	Mat3 m(mat3);
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			m(i, j) *= f;

	return m;
}

engine::maths::Mat4 engine::maths::operator*(float f, const Mat4& mat4)
{
	Mat4 m(mat4);
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			m(i, j) *= f;

	return m;
}