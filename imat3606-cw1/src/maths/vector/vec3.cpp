/*!
 * @file vec3.cpp
 * @brief Implimentation file for the Vec3 class.
 * @author George McDonagh */


// Local includes

#include "maths\vector\vec3.h"


// Namespaces

using namespace engine::maths;


Vec3::Vec3()
	: Vec3(0.0f, 0.0f, 0.0f)
{ }

Vec3::Vec3(float f)
{
	m_values[0] = m_values[1] = m_values[2] = f;
}

Vec3::Vec3(float v1, float v2, float v3)
{
	m_values[0] = v1;
	m_values[1] = v2;
	m_values[2] = v3;
}

Vec3::Vec3(const Vec3& vec3)
	: Vec3(vec3.x(), vec3.y(), vec3.z())
{ }

Vec3::Vec3(const Vec4& vec4)
	: Vec3(vec4.x(), vec4.y(), vec4.z())
{ }

Vec3::Vec3(const Vec2& vec2, float z)
	: Vec3(vec2.x(), vec2.y(), z)
{ }

Vec3::~Vec3() { }

const float& Vec3::x() const
{
	return m_values[0];
}

const float& Vec3::y() const
{
	return m_values[1];
}

const float& Vec3::z() const
{
	return m_values[2];
}

const float& Vec3::r() const
{
	return m_values[0];
}

const float& Vec3::g() const
{
	return m_values[1];
}

const float& Vec3::b() const
{
	return m_values[2];
}

const float& Vec3::s() const
{
	return m_values[0];
}

const float& Vec3::t() const
{
	return m_values[1];
}

const float& Vec3::p() const
{
	return m_values[2];
}

float& Vec3::x()
{
	return m_values[0];
}

float& Vec3::y()
{
	return m_values[1];
}

float& Vec3::z()
{
	return m_values[2];
}

float& Vec3::r()
{
	return m_values[0];
}

float& Vec3::g()
{
	return m_values[1];
}

float& Vec3::b()
{
	return m_values[2];
}

float& Vec3::s()
{
	return m_values[0];
}

float& Vec3::t()
{
	return m_values[1];
}

float& Vec3::p()
{
	return m_values[2];
}

float Vec3::magnitude() const
{
	return sqrt(x() * x() + y() * y() + z() * z());
}

void Vec3::normalize()
{
	*this /= magnitude();
}

Vec3 Vec3::operator+(const Vec3& vec3) const
{
	return Vec3(x() + vec3.x(), y() + vec3.y(), z() + vec3.z());
}

Vec3 Vec3::operator-(const Vec3& vec3) const
{
	return Vec3(x() - vec3.x(), y() - vec3.y(), z() - vec3.z());
}

Vec3 Vec3::operator-() const
{
	return Vec3(-x(), -y(), -z());
}

Vec3 Vec3::operator*(const Vec3& vec3) const
{
	return Vec3(x() * vec3.x(), y() * vec3.y(), z() * vec3.z());
}

Vec3 Vec3::operator*(float f) const
{
	return Vec3(x() * f, y() * f, z() * f);
}

Vec3 Vec3::operator/(const Vec3& vec3) const
{
	return Vec3(x() / vec3.x(), y() / vec3.y(), z() / vec3.z());
}

Vec3 Vec3::operator/(float f) const
{
	return Vec3(x() / f, y() / f, z() / f);
}

Vec3& Vec3::operator+=(const Vec3& vec3)
{
	x() += vec3.x();
	y() += vec3.y();
	z() += vec3.z();
	return *this;
}

Vec3& Vec3::operator-=(const Vec3& vec3)
{
	x() -= vec3.x();
	y() -= vec3.y();
	z() -= vec3.z();
	return *this;
}

Vec3& Vec3::operator*=(const Vec3& vec3)
{
	x() *= vec3.x();
	y() *= vec3.y();
	z() *= vec3.z();
	return *this;
}

Vec3& Vec3::operator*=(float f)
{
	x() *= f;
	y() *= f;
	z() *= f;
	return *this;
}

Vec3& Vec3::operator/=(const Vec3& vec3)
{
	x() /= vec3.x();
	y() /= vec3.y();
	z() /= vec3.z();
	return *this;
}

Vec3& Vec3::operator/=(float f)
{
	x() /= f;
	y() /= f;
	z() /= f;
	return *this;
}

bool Vec3::operator==(const Vec3& vec3) const
{
	return vec3.m_values == m_values;
}

bool Vec3::operator!=(const Vec3& vec3) const
{
	return vec3.m_values != m_values;
}

const float& Vec3::operator()(int i) const
{
	return m_values[i];
}

float& Vec3::operator()(int i)
{
	return m_values[i];
}