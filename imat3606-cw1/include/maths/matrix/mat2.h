#pragma once

/*!
 * @file mat2.h
 * @brief Header file for the Mat2 class.
 * @author George McDonagh */


// Local includes

#include "maths/maths.h"


// Namespaces

namespace engine { namespace maths {

	//! 2x2 Matrix.
	/*! A 2x2 Matrix with column-major order.
	  * @note Linear memory storage layout:
	  *	[0] [2]
	  * [1] [3] */
	class Mat2
	{
	public:
		//! Construct a 2x2 Matrix.
		/*! Constructs a 2x2 identity matrix. */
		Mat2();

		//! Construct a 2x2 Matrix with a specific diagonal value.
		/*! @param diagonal The value of the components on the diagonal. */
		Mat2(float diagonal);

		//! Construct a 2x2 Matrix with specific components.
		/*! @param values The values of the matrix in column-major order. */
		Mat2(float values[4]);

		//! Construct a 2x2 Matrix with specific components.
		/*! @param c1x Left-most column's X component.
		  * @param c1y Left-most column's Y component.
		  * @param c2x Right-most column's X component.
		  * @param c2y Right-most column's Y component. */
		Mat2(float c1x, float c1y,
			float c2x, float c2y);

		//! Construct a 2x2 Matrix with specific column data.
		/*! @param col1 Left-most column.
		  * @param col2 Right-most column. */
		Mat2(const Vec2& col1, const Vec2& col2);

		//! Destructor.
		~Mat2();

		//! Get the determinant of the Mat2.
		/*! @return The determinant of the Mat2. */
		float determinant() const;

		//! Transpose the matrix.
		/*! Flips the matrix components on the diagonal; the columns of the Mat2 become the rows and vice versa. */
		void transpose();

		//! Get a pointer to the matrices elements.
		/*! @return A pointer to the first component of the element. */
		const float* const data_ptr() const;

		//! Add two 2x2 matrix objects together.
		/*! @param mat2 A 2x2 matrix object. */
		Mat2 operator+(const Mat2& mat2) const;

		//! Substract one 2x2 matrix from another.
		/*! @param mat2 A 2x2 matrix object. */
		Mat2 operator-(const Mat2& mat2) const;

		//! Multiply two 2x2 matrix objects together.
		/*! @param mat2 A 2x2 matrix object. */
		Mat2 operator*(const Mat2& mat2) const;

		//! Multiply a two-component vector by a 2x2 matrix.
		/*! @param vec2 A two-component vector object. */
		Vec2 operator*(const Vec2& vec2) const;

		//! Increment one matrix object's components by another's.
		/*! @param mat2 A 2x2 matrix object. */
		Mat2& operator+=(const Mat2& mat2);

		//! Decremement one matrix object's components by another's.
		/*! @param mat2 A 2x2 matrix object. */
		Mat2& operator-=(const Mat2& mat2);

		//! Assign one matrix object to the product of itself and another.
		/*! @param mat2 A 2x2 matrix object. */
		Mat2& operator*=(const Mat2& mat2);

		//! Compare two matrix object's equivalence to eachother.
		/*! @param mat2 A 2x2 matrix object. */
		bool operator==(const Mat2& mat2) const;

		//! Compare two matrix object's inequality.
		/*! @param mat2 A 2x2 matrix object. */
		bool operator!=(const Mat2& mat2) const;

		//! Get a non-mutable reference of the matrix element at @c (col,row)
		/*! @param col The component's column.
		  * @param row The component's row. */
		const float& operator()(int col, int row) const;

		//! Get a mutable reference of the matrix element at @c (col,row)
		/*! @param col The component's column.
		  * @param row The component's row. */
		float& operator()(int col, int row);

	private:
		float m_values[4]; /*!< The matrix object's components, stored column-major order. */
	};

} }