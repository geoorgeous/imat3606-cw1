/*!
 * @file vec2.cpp
 * @brief Implimentation file for the Vec2 class.
 * @author George McDonagh */


// Local includes

#include "maths\vector\vec2.h"


// Namespaces

using namespace engine::maths;


Vec2::Vec2()
	: Vec2(0.0f, 0.0f)
{ }

Vec2::Vec2(float f)
{
	m_values[0] = m_values[1] = f;
}

Vec2::Vec2(float v1, float v2)
{
	m_values[0] = v1;
	m_values[1] = v2;
}

Vec2::Vec2(const Vec2& vec2)
	: Vec2(vec2.x(), vec2.y())
{ }

Vec2::~Vec2() { }

const float& Vec2::x() const
{
	return m_values[0];
}

const float& Vec2::y() const
{
	return m_values[1];
}

const float& Vec2::r() const
{
	return m_values[0];
}

const float& Vec2::g() const
{
	return m_values[1];
}

const float& Vec2::s() const
{
	return m_values[0];
}

const float& Vec2::t() const
{
	return m_values[1];
}

float& Vec2::x() 
{ 
	return m_values[0]; 
}

float& Vec2::y() 
{ 
	return m_values[1]; 
}

float& Vec2::r() 
{ 
	return m_values[0]; 
}

float& Vec2::g() 
{ 
	return m_values[1]; 
}

float& Vec2::s() 
{ 
	return m_values[0]; 
}

float& Vec2::t() 
{ 
	return m_values[1]; 
}

float Vec2::magnitude() const
{
	return sqrt(x() * x() + y() * y());
}

void Vec2::normalize()
{
	*this /= magnitude();
}

Vec2 Vec2::operator+(const Vec2& vec2) const
{
	return Vec2(x() + vec2.x(), y() + vec2.y());
}

Vec2 Vec2::operator-(const Vec2& vec2) const
{
	return Vec2(x() - vec2.x(), y() - vec2.y());
}

Vec2 Vec2::operator-() const
{
	return Vec2(-x(), -y());
}

Vec2 Vec2::operator*(const Vec2& vec2) const
{
	return Vec2(x() * vec2.x(), y() * vec2.y());
}

Vec2 Vec2::operator*(float f) const
{
	return Vec2(x() * f, y() * f);
}

Vec2 Vec2::operator/(const Vec2& vec2) const
{
	return Vec2(x() / vec2.x(), y() / vec2.y());
}

Vec2 Vec2::operator/(float f) const
{
	return Vec2(x() / f, y() / f);
}

Vec2& Vec2::operator+=(const Vec2& vec2)
{
	x() += vec2.x();
	y() += vec2.y();
	return *this;
}

Vec2& Vec2::operator-=(const Vec2& vec2)
{
	x() -= vec2.x();
	y() -= vec2.y();
	return *this;
}

Vec2& Vec2::operator*=(const Vec2& vec2)
{
	x() *= vec2.x();
	y() *= vec2.y();
	return *this;
}

Vec2& Vec2::operator*=(float f)
{
	x() *= f;
	y() *= f;
	return *this;
}

Vec2& Vec2::operator/=(const Vec2& vec2)
{
	x() /= vec2.x();
	y() /= vec2.y();
	return *this;
}

Vec2& Vec2::operator/=(float f)
{
	x() /= f;
	y() /= f;
	return *this;
}

bool Vec2::operator==(const Vec2& vec2) const
{
	return vec2.m_values == m_values;
}

bool Vec2::operator!=(const Vec2& vec2) const
{
	return vec2.m_values != m_values;
}

const float& Vec2::operator()(int i) const
{
	return m_values[i];
}

float& Vec2::operator()(int i)
{
	return m_values[i];
}