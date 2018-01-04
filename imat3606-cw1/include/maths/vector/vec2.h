#pragma once

/*!
 * @file vec2.h
 * @brief Header file for the Vec2 class.
 * @author George McDonagh */


// Local includes

#include "maths\maths.h"


// Namespaces

namespace engine { namespace maths {

	//! A two-component vector.
	class Vec2
	{
	public:
		//! Constructs an empty two-component vector.
		Vec2();

		//! Constructs a two-component vector filled with a specified value.
		/*! @param f Value to fill the vector with. */
		Vec2(float f);

		//! Constructs a two-component vector with specified values.
		/*! @param v1 Vector's first component. (X, R, or S value)
		  * @param v2 Vector's second component. (Y, G, or T value) */
		Vec2(float v1, float v2);

		//! Constructs a two-component vector using another.
		/*! @param vec2 A two-component vector. */
		Vec2(const Vec2& vec2);

		//! Default destructor.
		~Vec2();

		//! Vector's X component.
		/*! @return Read-only reference to the vector's first component. */
		const float& x() const;

		//! Vector's Y component.
		/*! @return Read-only reference to the vector's second component. */
		const float& y() const;

		//! Vector's R component.
		/*! @return Read-only reference to the vector's first component. */
		const float& r() const;

		//! Vector's G component.
		/*! @return Read-only reference to the vector's second component. */
		const float& g() const;

		//! Vector's S component.
		/*! @return Read-only reference to the vector's first component. */
		const float& s() const;

		//! Vector's T component.
		/*! @return Read-only reference to the vector's second component. */
		const float& t() const;

		//! Vector's X component.
		/*! @return Modifiable reference to the vector's first component. */
		float& x();

		//! Vector's Y component.
		/*! @return Modifiable reference to the vector's second component. */
		float& y();

		//! Vector's R component.
		/*! @return Modifiable reference to the vector's first component. */
		float& r();

		//! Vector's G component.
		/*! @return Modifiable reference to the vector's second component. */
		float& g();

		//! Vector's S component.
		/*! @return Modifiable reference to the vector's first component. */
		float& s();

		//! Vector's T component.
		/*! @return Modifiable reference to the vector's second component. */
		float& t();

		//! Vector's magnitude.
		/*! @return The vector's magnitude/length/strength. */
		float magnitude() const;

		//! Normalizes the vector.
		void normalize();

		Vec2 operator+(const Vec2& vec2) const;

		Vec2 operator-(const Vec2& vec2) const;

		Vec2 operator-() const;

		Vec2 operator*(const Vec2& vec2) const;

		Vec2 operator*(float f) const;

		Vec2 operator/(const Vec2& vec2) const;

		Vec2 operator/(float f) const;

		Vec2& operator+=(const Vec2& vec2);

		Vec2& operator-=(const Vec2& vec2);

		Vec2& operator*=(const Vec2& vec2);

		Vec2& operator*=(float f);

		Vec2& operator/=(const Vec2& vec2);

		Vec2& operator/=(float f);

		bool operator==(const Vec2& vec2) const;

		bool operator!=(const Vec2& vec2) const;

		const float& operator()(int i) const;

		float& operator()(int i);

	private:
		float m_values[2]; /*!< The vector object's components. */
	};

} }