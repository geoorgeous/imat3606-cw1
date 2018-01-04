/*!
 * @file vec4.cpp
 * @brief Implimentation file for the Vec4 class.
 * @author George McDonagh */


// Local includes

#include "maths\vector\vec4.h"


// Namespaces

using namespace engine::maths;


Vec4::Vec4()
	: Vec4(0.0f, 0.0f, 0.0f, 0.0f)
{ }

Vec4::Vec4(float f)
{
	m_values[0] = m_values[1] = m_values[2] = m_values[3] = f;
}

Vec4::Vec4(float v1, float v2, float v3, float v4)
{
	m_values[0] = v1;
	m_values[1] = v2;
	m_values[2] = v3;
	m_values[3] = v4;
}

Vec4::Vec4(const Vec3& vec3)
	: Vec4(vec3.x(), vec3.y(), vec3.z(), 1.0f)
{ }

Vec4::Vec4(const Vec4& vec4)
	: Vec4(vec4.x(), vec4.y(), vec4.z(), vec4.w())
{ }

Vec4::~Vec4() { }

const float& Vec4::x() const
{
	return m_values[0];
}

const float& Vec4::y() const
{
	return m_values[1];
}

const float& Vec4::z() const
{
	return m_values[2];
}

const float& Vec4::w() const
{
	return m_values[3];
}

const float& Vec4::r() const
{
	return m_values[0];
}

const float& Vec4::g() const
{
	return m_values[1];
}

const float& Vec4::b() const
{
	return m_values[2];
}

const float& Vec4::a() const
{
	return m_values[3];
}

const float& Vec4::s() const
{
	return m_values[0];
}

const float& Vec4::t() const
{
	return m_values[1];
}

const float& Vec4::p() const
{
	return m_values[2];
}

const float& Vec4::q() const
{
	return m_values[3];
}

float& Vec4::x()
{
	return m_values[0];
}

float& Vec4::y()
{
	return m_values[1];
}

float& Vec4::z()
{
	return m_values[2];
}

float& Vec4::w()
{
	return m_values[3];
}

float& Vec4::r()
{
	return m_values[0];
}

float& Vec4::g()
{
	return m_values[1];
}

float& Vec4::b()
{
	return m_values[2];
}

float& Vec4::a()
{
	return m_values[3];
}

float& Vec4::s()
{
	return m_values[0];
}

float& Vec4::t()
{
	return m_values[1];
}

float& Vec4::p()
{
	return m_values[2];
}

float& Vec4::q()
{
	return m_values[3];
}

float Vec4::magnitude() const
{
	return sqrt(x() * x() + y() * y() + z() * z() + w() * w());
}

void Vec4::normalize()
{
	*this /= magnitude();
}

Vec4 Vec4::operator+(const Vec4& vec4) const
{
	return Vec4(x() + vec4.x(), y() + vec4.y(), z() + vec4.z(), w() + vec4.w());
}

Vec4 Vec4::operator-(const Vec4& vec4) const
{
	return Vec4(x() - vec4.x(), y() - vec4.y(), z() - vec4.z(), w() - vec4.w());
}

Vec4 Vec4::operator-() const
{
	return Vec4(-x(), -y(), -z(), -w());
}

Vec4 Vec4::operator*(const Vec4& vec4) const
{
	return Vec4(x() * vec4.x(), y() * vec4.y(), z() * vec4.z(), w() * vec4.w());
}

Vec4 Vec4::operator*(float f) const
{
	return Vec4(x() * f, y() * f, z() * f, w() * f);
}

Vec4 Vec4::operator/(const Vec4& vec4) const
{
	return Vec4(x() / vec4.x(), y() / vec4.y(), z() / vec4.z(), w() / vec4.w());
}

Vec4 Vec4::operator/(float f) const
{
	return Vec4(x() / f, y() / f, z() / f, w() / f);
}

Vec4& Vec4::operator+=(const Vec4& vec4)
{
	x() += vec4.x();
	y() += vec4.y();
	z() += vec4.z();
	w() += vec4.w();
	return *this;
}

Vec4& Vec4::operator-=(const Vec4& vec4)
{
	x() -= vec4.x();
	y() -= vec4.y();
	z() -= vec4.z();
	w() -= vec4.w();
	return *this;
}

Vec4& Vec4::operator*=(const Vec4& vec4)
{
	x() *= vec4.x();
	y() *= vec4.y();
	z() *= vec4.z();
	w() *= vec4.w();
	return *this;
}

Vec4& Vec4::operator*=(float f)
{
	x() *= f;
	y() *= f;
	z() *= f;
	w() *= f;
	return *this;
}

Vec4& Vec4::operator/=(const Vec4& vec4)
{
	x() /= vec4.x();
	y() /= vec4.y();
	z() /= vec4.z();
	w() /= vec4.w();
	return *this;
}

Vec4& Vec4::operator/=(float f)
{
	x() /= f;
	y() /= f;
	z() /= f;
	w() /= f;
	return *this;
}

bool Vec4::operator==(const Vec4& vec4) const
{
	return vec4.m_values == m_values;
}

bool Vec4::operator!=(const Vec4& vec4) const
{
	return vec4.m_values != m_values;
}

const float& Vec4::operator()(int i) const
{
	return m_values[i];
}

float& Vec4::operator()(int i)
{
	return m_values[i];
}