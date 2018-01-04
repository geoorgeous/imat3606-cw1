/*!
 * @file mat3.cpp
 * @brief Implimentation file for the Mat3 class.
 * @author George McDonagh */


// Local includes

#include "maths\matrix\mat3.h"


// Namespaces

using namespace engine::maths;


Mat3::Mat3()
	: Mat3(1.0f)
{ }

Mat3::Mat3(float diagonal)
{
	m_values[0] = diagonal;
	m_values[1] = 0.0f;
	m_values[2] = 0.0f;

	m_values[3] = 0.0f;
	m_values[4] = diagonal;
	m_values[5] = 0.0f;

	m_values[6] = 0.0f;
	m_values[7] = 0.0f;
	m_values[8] = diagonal;
}

Mat3::Mat3(float values[9])
{
	for (int i = 0; i < 9; i++)
		m_values[i] = values[i];
}

Mat3::Mat3(float c1x, float c1y, float c1z,
	float c2x, float c2y, float c2z,
	float c3x, float c3y, float c3z)
{
	m_values[0] = c1x;
	m_values[1] = c1y;
	m_values[2] = c1z;

	m_values[3] = c2x;
	m_values[4] = c2y;
	m_values[5] = c2z;

	m_values[6] = c3x;
	m_values[7] = c3y;
	m_values[8] = c3z;
}

Mat3::Mat3(const Vec3& col1, const Vec3& col2, const  Vec3& col3)
{
	m_values[0] = col1.x();
	m_values[1] = col1.y();
	m_values[2] = col1.z();

	m_values[3] = col2.x();
	m_values[4] = col2.y();
	m_values[5] = col2.z();

	m_values[6] = col3.x();
	m_values[7] = col3.y();
	m_values[8] = col3.z();
}

Mat3::Mat3(const Mat4& mat4)
{
	for (int x = 0; x < 3; x++)
		for (int y = 0; y < 3; y++)
			(*this)(x, y) = mat4(x, y);
}

Mat3::~Mat3() { }

float Mat3::determinant() const
{
	return (
		(m_values[0] * ((m_values[4] * m_values[8]) - (m_values[7] * m_values[5]))) -
		(m_values[3] * ((m_values[1] * m_values[8]) - (m_values[7] * m_values[2]))) +
		(m_values[6] * ((m_values[1] * m_values[5]) - (m_values[4] * m_values[2]))));
}

void Mat3::transpose()
{
	*this = maths::transpose(*this);
}

const float* const Mat3::data_ptr() const
{
	return m_values;
}

Mat3 Mat3::operator+(const Mat3& mat3) const
{
	float m[9];

	for (int i = 0; i < 9; i++)
		m[i] = m_values[i] + mat3.m_values[i];

	return Mat3(m);
}

Mat3 Mat3::operator-(const Mat3& mat3) const
{
	float m[9];

	for (int i = 0; i < 9; i++)
		m[i] = m_values[i] - mat3.m_values[i];

	return Mat3(m);
}

Mat3 Mat3::operator*(const Mat3& mat3) const
{
	return Mat3(
		m_values[0] * mat3.m_values[0] + m_values[3] * mat3.m_values[1] + m_values[6] * mat3.m_values[2],
		m_values[1] * mat3.m_values[0] + m_values[4] * mat3.m_values[1] + m_values[7] * mat3.m_values[2],
		m_values[2] * mat3.m_values[0] + m_values[5] * mat3.m_values[1] + m_values[8] * mat3.m_values[2],

		m_values[0] * mat3.m_values[3] + m_values[3] * mat3.m_values[4] + m_values[6] * mat3.m_values[5],
		m_values[1] * mat3.m_values[3] + m_values[4] * mat3.m_values[4] + m_values[7] * mat3.m_values[5],
		m_values[2] * mat3.m_values[3] + m_values[5] * mat3.m_values[4] + m_values[8] * mat3.m_values[5],

		m_values[0] * mat3.m_values[6] + m_values[3] * mat3.m_values[7] + m_values[6] * mat3.m_values[8],
		m_values[1] * mat3.m_values[6] + m_values[4] * mat3.m_values[7] + m_values[7] * mat3.m_values[8],
		m_values[2] * mat3.m_values[6] + m_values[5] * mat3.m_values[7] + m_values[8] * mat3.m_values[8]);
}

Vec3 Mat3::operator*(const Vec3& vec3) const
{
	return Vec3(
		m_values[0] * vec3.x() + m_values[3] * vec3.y() + m_values[6] * vec3.z(),
		m_values[1] * vec3.x() + m_values[4] * vec3.y() + m_values[7] * vec3.z(),
		m_values[2] * vec3.x() + m_values[5] * vec3.y() + m_values[8] * vec3.z());
}

Mat3& Mat3::operator+=(const Mat3& mat3)
{
	for (int i = 0; i < 9; i++)
		m_values[i] += mat3.m_values[i];

	return *this;
}

Mat3& Mat3::operator-=(const Mat3& mat3)
{
	for (int i = 0; i < 9; i++)
		m_values[i] -= mat3.m_values[i];

	return *this;
}

Mat3& Mat3::operator*=(const Mat3& mat3)
{
	const float* m = &(*this * mat3)(0, 0);

	for (int i = 0; i < 9; i++)
		m_values[i] = m[i];

	return *this;
}

bool Mat3::operator==(const Mat3& mat3) const
{
	return mat3.m_values == m_values;
}

bool Mat3::operator!=(const Mat3& mat3) const
{
	return mat3.m_values != m_values;
}

const float& Mat3::operator()(int col, int row) const
{
	return m_values[3 * col + row];
}

float& Mat3::operator()(int col, int row)
{
	return m_values[3 * col + row];
}