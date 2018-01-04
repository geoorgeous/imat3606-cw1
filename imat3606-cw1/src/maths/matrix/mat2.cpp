/*!
 * @file mat2.cpp
 * @brief Implimentation file for the Mat2 class.
 * @author George McDonagh */


// Local includes

#include "maths\matrix\mat2.h"


// Namespaces

using namespace engine::maths;


Mat2::Mat2()
	: Mat2(1.0f)
{ }

Mat2::Mat2(float diagonal)
{
	m_values[0] = diagonal;
	m_values[1] = 0.0f;

	m_values[2] = 0.0f;
	m_values[3] = diagonal;
}

Mat2::Mat2(float values[4])
{
	for (int i = 0; i < 4; i++)
		m_values[i] = values[i];
}

Mat2::Mat2(float c1x, float c1y,
	float c2x, float c2y)
{
	m_values[0] = c1x;
	m_values[1] = c1y;

	m_values[2] = c2x;
	m_values[3] = c2y;
}

Mat2::Mat2(const Vec2& col1, const Vec2& col2)
{
	m_values[0] = col1.x();
	m_values[1] = col1.y();

	m_values[2] = col2.x();
	m_values[3] = col2.y();
}

Mat2::~Mat2() { }

float Mat2::determinant() const
{
	return (m_values[0] * m_values[3]) - (m_values[2] * m_values[1]);
}

void Mat2::transpose()
{
	*this = maths::transpose(*this);
}

const float* const Mat2::data_ptr() const
{
	return m_values;
}

Mat2 Mat2::operator+(const Mat2& mat2) const
{
	float m[4];

	for (int i = 0; i < 4; i++)
		m[i] = m_values[i] + mat2.m_values[i];

	return Mat2(m);
}

Mat2 Mat2::operator-(const Mat2& mat2) const
{
	float m[4];

	for (int i = 0; i < 4; i++)
		m[i] = m_values[i] - mat2.m_values[i];

	return Mat2(m);
}

Mat2 Mat2::operator*(const Mat2& mat2) const
{
	return Mat2(
		m_values[0] * mat2.m_values[0] + m_values[2] * mat2.m_values[1],
		m_values[1] * mat2.m_values[0] + m_values[3] * mat2.m_values[1],

		m_values[0] * mat2.m_values[2] + m_values[2] * mat2.m_values[3],
		m_values[1] * mat2.m_values[2] + m_values[3] * mat2.m_values[3]);
}

Vec2 Mat2::operator*(const Vec2& vec2) const
{
	return Vec2(
		m_values[0] * vec2.x() + m_values[2] * vec2.y(),
		m_values[1] * vec2.x() + m_values[3] * vec2.y());
}

Mat2& Mat2::operator+=(const Mat2& mat2)
{
	for (int i = 0; i < 4; i++)
		m_values[i] += mat2.m_values[i];

	return *this;
}

Mat2& Mat2::operator-=(const Mat2& mat2)
{
	for (int i = 0; i < 4; i++)
		m_values[i] -= mat2.m_values[i];

	return *this;
}

Mat2& Mat2::operator*=(const Mat2& mat2)
{
	const float* m = &(*this * mat2)(0, 0);

	for (int i = 0; i < 4; i++)
		m_values[i] = m[i];

	return *this;
}

bool Mat2::operator==(const Mat2& mat2) const
{
	return mat2.m_values == m_values;
}

bool Mat2::operator!=(const Mat2& mat2) const
{
	return mat2.m_values != m_values;
}

const float& Mat2::operator()(int col, int row) const
{
	return m_values[2 * col + row];
}

float& Mat2::operator()(int col, int row)
{
	return m_values[2 * col + row];
}