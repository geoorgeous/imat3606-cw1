/*!
 * @file mat4.cpp
 * @brief Implimentation file for the Mat4 class.
 * @author George McDonagh */


// Local includes

#include "maths\matrix\mat4.h"


// Namespaces

using namespace engine::maths;


Mat4::Mat4()
	: Mat4(1.0f)
{ }

Mat4::Mat4(float diagonal)
{
	m_values[0 ] = diagonal;
	m_values[1 ] = 0.0f;
	m_values[2 ] = 0.0f;
	m_values[3 ] = 0.0f;

	m_values[4 ] = 0.0f;
	m_values[5 ] = diagonal;
	m_values[6 ] = 0.0f;
	m_values[7 ] = 0.0f;

	m_values[8 ] = 0.0f;
	m_values[9 ] = 0.0f;
	m_values[10] = diagonal;
	m_values[11] = 0.0f;

	m_values[12] = 0.0f;
	m_values[13] = 0.0f;
	m_values[14] = 0.0f;
	m_values[15] = diagonal;
}

Mat4::Mat4(float values[16])
{
	for (int i = 0; i < 16; i++)
		m_values[i] = values[i];
}

Mat4::Mat4(float c1x, float c1y, float c1z, float c1w,
	float c2x, float c2y, float c2z, float c2w,
	float c3x, float c3y, float c3z, float c3w,
	float c4x, float c4y, float c4z, float c4w)
{
	m_values[0 ] = c1x;
	m_values[1 ] = c1y;
	m_values[2 ] = c1z;
	m_values[3 ] = c1w;

	m_values[4 ] = c2x;
	m_values[5 ] = c2y;
	m_values[6 ] = c2z;
	m_values[7 ] = c2w;

	m_values[8 ] = c3x;
	m_values[9 ] = c3y;
	m_values[10] = c3z;
	m_values[11] = c3w;

	m_values[12] = c4x;
	m_values[13] = c4y;
	m_values[14] = c4z;
	m_values[15] = c4w;
}

Mat4::Mat4(const Vec4& col1, const Vec4& col2, const Vec4& col3, const Vec4& col4)
{
	m_values[0 ] = col1.x();
	m_values[1 ] = col1.y();
	m_values[2 ] = col1.z();
	m_values[3 ] = col1.w();

	m_values[4 ] = col2.x();
	m_values[5 ] = col2.y();
	m_values[6 ] = col2.z();
	m_values[7 ] = col2.w();

	m_values[8 ] = col3.x();
	m_values[9 ] = col3.y();
	m_values[10] = col3.z();
	m_values[11] = col3.w();

	m_values[12] = col4.x();
	m_values[13] = col4.y();
	m_values[14] = col4.z();
	m_values[15] = col4.w();
}

Mat4::Mat4(const Mat3& mat3)
{
	for (int x = 0; x < 3; x++)
		for (int y = 0; y < 3; y++)
			(*this)(x, y) = mat3(x, y);

	(*this)(3, 0) = 0.0f;
	(*this)(3, 1) = 0.0f;
	(*this)(3, 2) = 0.0f;

	(*this)(0, 3) = 0.0f;
	(*this)(1, 3) = 0.0f;
	(*this)(2, 3) = 0.0f;

	(*this)(3, 3) = 1.0f;
}

Mat4::~Mat4() { }

float Mat4::determinant() const
{
	return (
		(m_values[0 ] * (maths::Mat3(m_values[5], m_values[6], m_values[7], m_values[9], m_values[10], m_values[11], m_values[13], m_values[14], m_values[15]).determinant())) -
		(m_values[4 ] * (maths::Mat3(m_values[1], m_values[2], m_values[3], m_values[9], m_values[10], m_values[11], m_values[13], m_values[14], m_values[15]).determinant())) +
		(m_values[8 ] * (maths::Mat3(m_values[1], m_values[2], m_values[3], m_values[5], m_values[6 ], m_values[7 ], m_values[13], m_values[14], m_values[15]).determinant())) -
		(m_values[12] * (maths::Mat3(m_values[1], m_values[2], m_values[3], m_values[5], m_values[6 ], m_values[7 ], m_values[9 ], m_values[10], m_values[11]).determinant())));
}

void Mat4::transpose()
{
	*this = maths::transpose(*this);
}

const float* const Mat4::data_ptr() const
{
	return m_values;
}

Mat4 Mat4::operator+(const Mat4& mat4) const
{
	float m[16];

	for (int i = 0; i < 16; i++)
		m[i] = m_values[i] + mat4.m_values[i];

	return Mat4(m);
}

Mat4 Mat4::operator-(const Mat4& mat4) const
{
	float m[16];

	for (int i = 0; i < 16; i++)
		m[i] = m_values[i] - mat4.m_values[i];

	return Mat4(m);
}

Mat4 Mat4::operator*(const Mat4& mat4) const
{
	return Mat4(
		m_values[0] * mat4.m_values[0 ] + m_values[4] * mat4.m_values[1 ] + m_values[8 ] * mat4.m_values[2 ] + m_values[12] * mat4.m_values[3 ],
		m_values[1] * mat4.m_values[0 ] + m_values[5] * mat4.m_values[1 ] + m_values[9 ] * mat4.m_values[2 ] + m_values[13] * mat4.m_values[3 ],
		m_values[2] * mat4.m_values[0 ] + m_values[6] * mat4.m_values[1 ] + m_values[10] * mat4.m_values[2 ] + m_values[14] * mat4.m_values[3 ],
		m_values[3] * mat4.m_values[0 ] + m_values[7] * mat4.m_values[1 ] + m_values[11] * mat4.m_values[2 ] + m_values[15] * mat4.m_values[3 ], 

		m_values[0] * mat4.m_values[4 ] + m_values[4] * mat4.m_values[5 ] + m_values[8 ] * mat4.m_values[6 ] + m_values[12] * mat4.m_values[7 ],
		m_values[1] * mat4.m_values[4 ] + m_values[5] * mat4.m_values[5 ] + m_values[9 ] * mat4.m_values[6 ] + m_values[13] * mat4.m_values[7 ],
		m_values[2] * mat4.m_values[4 ] + m_values[6] * mat4.m_values[5 ] + m_values[10] * mat4.m_values[6 ] + m_values[14] * mat4.m_values[7 ],
		m_values[3] * mat4.m_values[4 ] + m_values[7] * mat4.m_values[5 ] + m_values[11] * mat4.m_values[6 ] + m_values[15] * mat4.m_values[7 ], 

		m_values[0] * mat4.m_values[8 ] + m_values[4] * mat4.m_values[9 ] + m_values[8 ] * mat4.m_values[10] + m_values[12] * mat4.m_values[11],
		m_values[1] * mat4.m_values[8 ] + m_values[5] * mat4.m_values[9 ] + m_values[9 ] * mat4.m_values[10] + m_values[13] * mat4.m_values[11],
		m_values[2] * mat4.m_values[8 ] + m_values[6] * mat4.m_values[9 ] + m_values[10] * mat4.m_values[10] + m_values[14] * mat4.m_values[11],
		m_values[3] * mat4.m_values[8 ] + m_values[7] * mat4.m_values[9 ] + m_values[11] * mat4.m_values[10] + m_values[15] * mat4.m_values[11], 

		m_values[0] * mat4.m_values[12] + m_values[4] * mat4.m_values[13] + m_values[8 ] * mat4.m_values[14] + m_values[12] * mat4.m_values[15],
		m_values[1] * mat4.m_values[12] + m_values[5] * mat4.m_values[13] + m_values[9 ] * mat4.m_values[14] + m_values[13] * mat4.m_values[15],
		m_values[2] * mat4.m_values[12] + m_values[6] * mat4.m_values[13] + m_values[10] * mat4.m_values[14] + m_values[14] * mat4.m_values[15],
		m_values[3] * mat4.m_values[12] + m_values[7] * mat4.m_values[13] + m_values[11] * mat4.m_values[14] + m_values[15] * mat4.m_values[15]);
}

Vec4 Mat4::operator*(const Vec4& vec4) const
{
	return Vec4(
		m_values[0] * vec4.x() + m_values[4] * vec4.y() + m_values[8 ] * vec4.z() + m_values[12] * vec4.w(),
		m_values[1] * vec4.x() + m_values[5] * vec4.y() + m_values[9 ] * vec4.z() + m_values[13] * vec4.w(),
		m_values[2] * vec4.x() + m_values[6] * vec4.y() + m_values[10] * vec4.z() + m_values[14] * vec4.w(),
		m_values[3] * vec4.x() + m_values[7] * vec4.y() + m_values[11] * vec4.z() + m_values[15] * vec4.w());
}

Mat4& Mat4::operator+=(const Mat4& mat4)
{
	for (int i = 0; i < 16; i++)
		m_values[i] += mat4.m_values[i];

	return *this;
}

Mat4& Mat4::operator-=(const Mat4& mat4)
{
	for (int i = 0; i < 16; i++)
		m_values[i] -= mat4.m_values[i];

	return *this;
}

Mat4& Mat4::operator*=(const Mat4& mat4)
{
	const float* m = &(*this * mat4)(0, 0);

	for (int i = 0; i < 16; i++)
		m_values[i] = m[i];

	return *this;
}

bool Mat4::operator==(const Mat4& mat4) const
{
	return mat4.m_values == m_values;
}

bool Mat4::operator!=(const Mat4& mat4) const
{
	return mat4.m_values != m_values;
}

const float& Mat4::operator()(int col, int row) const
{
	return m_values[4 * col + row];
}

float& Mat4::operator()(int col, int row)
{
	return m_values[4 * col + row];
}