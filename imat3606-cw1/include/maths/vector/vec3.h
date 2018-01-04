#pragma once

/*!
 * @file vec3.h
 * @brief Header file for the Vec3 class.
 * @author George McDonagh */


// Local includes

#include "maths\maths.h"


// Namespaces

namespace engine { namespace maths {

	//! A three-component vector.
	class Vec3
	{
	public:
		//! Constructs an empty three-component vector.
		Vec3();

		//! Constructs a three-component vector filled with a specified value.
		/*! @param f Value to fill the vector with. */
		Vec3(float f);

		//! Constructs a three-component vector with specified values.
		/*! @param v1 Vector's first component. (X, R, or S value)
		  * @param v2 Vector's second component. (Y, G, or T value)
		  * @param v3 Vector's third component. (Z, B, or P value) */
		Vec3(float v1, float v2, float v3);

		//! Constructs a three-component vector using another.
		/*! @param vec3 A three-component vector. */
		Vec3(const Vec3& vec3);

		//! Constructs a three-component vector using a four-component vector.
		/*! Uses the first three components of a four-component vector and throws away the last.
		  * @param vec4 A four-component vector. */
		Vec3(const Vec4& vec4);

		//! Constructs a three component vector using a two-component vector and a specified third value.
		/*! @param vec2 A two-component vector to use for the first and second components.
		  * @param z The value of the vector's third component. */
		Vec3(const Vec2& vec2, float z);

		//! Default destructor.
		~Vec3();

		//! Vector's X component.
		/*! @return Read-only reference to the vector's first component. */
		const float& x() const;

		//! Vector's Y component.
		/*! @return Read-only reference to the vector's second component. */
		const float& y() const;

		//! Vector's Z component.
		/*! @return Read-only reference to the vector's third component. */
		const float& z() const;

		//! Vector's R component.
		/*! @return Read-only reference to the vector's first component. */
		const float& r() const;

		//! Vector's G component.
		/*! @return Read-only reference to the vector's second component. */
		const float& g() const;

		//! Vector's B component.
		/*! @return Read-only reference to the vector's third component. */
		const float& b() const;

		//! Vector's S component.
		/*! @return Read-only reference to the vector's first component. */
		const float& s() const;

		//! Vector's T component.
		/*! @return Read-only reference to the vector's second component. */
		const float& t() const;

		//! Vector's P component.
		/*! @return Read-only reference to the vector's third component. */
		const float& p() const;

		//! Vector's X component.
		/*! @return Modifiable reference to the vector's first component. */
		float& x();

		//! Vector's Y component.
		/*! @return Modifiable reference to the vector's second component. */
		float& y();

		//! Vector's Z component.
		/*! @return Modifiable reference to the vector's third component. */
		float& z();

		//! Vector's R component.
		/*! @return Modifiable reference to the vector's first component. */
		float& r();

		//! Vector's G component.
		/*! @return Modifiable reference to the vector's second component. */
		float& g();

		//! Vector's B component.
		/*! @return Modifiable reference to the vector's third component. */
		float& b();

		//! Vector's S component.
		/*! @return Modifiable reference to the vector's first component. */
		float& s();

		//! Vector's T component.
		/*! @return Modifiable reference to the vector's second component. */
		float& t();

		//! Vector's P component.
		/*! @return Modifiable reference to the vector's third component. */
		float& p();

		//! Vector's magnitude.
		/*! @return The vector's magnitude/length/strength. */
		float magnitude() const;

		//! Normalizes the vector.
		void normalize();

		Vec3 operator+(const Vec3& vec3) const;

		Vec3 operator-(const Vec3& vec3) const;

		Vec3 operator-() const;

		Vec3 operator*(const Vec3& vec3) const;

		Vec3 operator*(float f) const;

		Vec3 operator/(const Vec3& vec3) const;

		Vec3 operator/(float f) const;

		Vec3& operator+=(const Vec3& vec3);

		Vec3& operator-=(const Vec3& vec3);

		Vec3& operator*=(const Vec3& vec3);

		Vec3& operator*=(float f);

		Vec3& operator/=(const Vec3& vec3);

		Vec3& operator/=(float f);

		bool operator==(const Vec3& vec3) const;

		bool operator!=(const Vec3& vec3) const;

		const float& operator()(int i) const;

		float& operator()(int i);

	private:
		float m_values[3]; /*!< The vector object's components. */
	};

} }