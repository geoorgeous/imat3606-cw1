#pragma once

/*!
 * @file vec4.h
 * @brief Header file for the Vec4 class.
 * @author George McDonagh */


// Local includes

#include "maths\maths.h"


// Namespaces

namespace engine { namespace maths {

	//! A four-component vector.
	class Vec4
	{
	public:
		//! Constructs an empty four-component vector.
		Vec4();

		//! Constructs a four-component vector filled with a specified value.
		/*! @param f Value to fill the vector with. */
		Vec4(float f);

		//! Constructs a four-component vector with specified values.
		/*! @param v1 Vector's first component. (X, R, or S value)
		  * @param v2 Vector's second component. (Y, G, or T value)
		  * @param v3 Vector's third component. (Z, B, or P value)
		  * @param v4 Vector's fourth component. (W, A, or Q value) */
		Vec4(float v1, float v2, float v3, float v4);

		//! Constructs a four-component vector using a three-component vector.
		/*! The four-component vector's first, second, and third components will be assigned the three-component vector's components respectively. The fourth is assigned the value of 1. 
		  * @param vec3 A three-component vector. */
		Vec4(const Vec3& vec3);

		//! Constructs a four-component vector using another.
		/*! @param vec4 A four-component vector. */
		Vec4(const Vec4& vec4);

		//! Default destructor.
		~Vec4();

		//! Vector's X component.
		/*! @return Read-only reference to the vector's first component. */
		const float& x() const;

		//! Vector's Y component.
		/*! @return Read-only reference to the vector's second component. */
		const float& y() const;

		//! Vector's Z component.
		/*! @return Read-only reference to the vector's third component. */
		const float& z() const;

		//! Vector's W component.
		/*! @return Read-only reference to the vector's fourth component. */
		const float& w() const;

		//! Vector's R component.
		/*! @return Read-only reference to the vector's first component. */
		const float& r() const;

		//! Vector's G component.
		/*! @return Read-only reference to the vector's second component. */
		const float& g() const;

		//! Vector's B component.
		/*! @return Read-only reference to the vector's third component. */
		const float& b() const;

		//! Vector's A component.
		/*! @return Read-only reference to the vector's fourth component. */
		const float& a() const;

		//! Vector's S component.
		/*! @return Read-only reference to the vector's first component. */
		const float& s() const;

		//! Vector's T component.
		/*! @return Read-only reference to the vector's second component. */
		const float& t() const;

		//! Vector's P component.
		/*! @return Read-only reference to the vector's third component. */
		const float& p() const;

		//! Vector's Q component.
		/*! @return Read-only reference to the vector's fourth component. */
		const float& q() const;

		//! Vector's X component.
		/*! @return Modifiable reference to the vector's first component. */
		float& x();

		//! Vector's Y component.
		/*! @return Modifiable reference to the vector's second component. */
		float& y();

		//! Vector's Z component.
		/*! @return Modifiable reference to the vector's third component. */
		float& z();

		//! Vector's W component.
		/*! @return Modifiable reference to the vector's fourth component. */
		float& w();

		//! Vector's R component.
		/*! @return Modifiable reference to the vector's first component. */
		float& r();

		//! Vector's G component.
		/*! @return Modifiable reference to the vector's second component. */
		float& g();

		//! Vector's B component.
		/*! @return Modifiable reference to the vector's third component. */
		float& b();

		//! Vector's A component.
		/*! @return Modifiable reference to the vector's fourth component. */
		float& a();

		//! Vector's S component.
		/*! @return Modifiable reference to the vector's first component. */
		float& s();

		//! Vector's T component.
		/*! @return Modifiable reference to the vector's second component. */
		float& t();

		//! Vector's P component.
		/*! @return Modifiable reference to the vector's third component. */
		float& p();

		//! Vector's Q component.
		/*! @return Modifiable reference to the vector's fourth component. */
		float& q();

		//! Vector's magnitude.
		/*! @return The vector's magnitude/length/strength. */
		float magnitude() const;

		//! Normalizes the vector.
		void normalize();

		Vec4 operator+(const Vec4& vec4) const;

		Vec4 operator-(const Vec4& vec4) const;

		Vec4 operator-() const;

		Vec4 operator*(const Vec4& vec4) const;

		Vec4 operator*(float f) const;

		Vec4 operator/(const Vec4& vec4) const;

		Vec4 operator/(float f) const;

		Vec4& operator+=(const Vec4& vec4);

		Vec4& operator-=(const Vec4& vec4);

		Vec4& operator*=(const Vec4& vec4);

		Vec4& operator*=(float f);

		Vec4& operator/=(const Vec4& vec4);

		Vec4& operator/=(float f);

		bool operator==(const Vec4& vec4) const;

		bool operator!=(const Vec4& vec4) const;

		const float& operator()(int i) const;

		float& operator()(int i);

	private:
		float m_values[4]; /*!< The vector object's components. */
	};

} }