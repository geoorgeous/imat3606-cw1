#pragma once

/*!
 * @file mat4.h
 * @brief Header file for the Mat4 class.
 * @author George McDonagh */


// Local includes

#include "maths\maths.h"


// Namespaces

namespace engine { namespace maths {

	//! 4x4 Matrix.
	/*! A 4x4 Matrix with column-major order.
	  * @note Linear memory storage layout:
	  *	[0] [4] [8 ] [12]
	  *	[1] [5] [9 ] [13]
	  *	[2] [6] [10] [14]
	  *	[3] [7] [11] [15] */
	class Mat4
	{
	public:
		//! Default constructor.
		/*! Constructs a 4x4 identity matrix. */
		Mat4();

		//! Constructs a 4x4 matrix with a specified diagonal value.
		/*! @param diagonal The value of the components on the diagonal. */
		Mat4(float diagonal);

		//! Constructs a 4x4 matrix with specified components.
		/*! @param values The values of the matrix in column-major order. */
		Mat4(float values[16]);

		//! Constructs a 3x3 matrix with specified components.
		/*! @param c1x Left-most column's X component.
		  * @param c1y Left-most column's Y component.
		  * @param c1z Left-most column's Z component.
		  * @param c1w Left-most column's W component.
		  * @param c2x Second column's X component.
		  * @param c2y Second column's Y component. 
		  * @param c2z Second column's Z component.
		  * @param c2w Second column's W component.
		  * @param c3x Third column's X component.
		  * @param c3y Third column's Y component.
		  * @param c3z Third column's Z component.
		  * @param c3w Third column's W component.
		  * @param c4x Right-most column's X component.
		  * @param c4y Right-most column's Y component.
		  * @param c4z Right-most column's Z component.
		  * @param c4w Right-most column's W component. */
		Mat4(float c1x, float c1y, float c1z, float c1w,
			float c2x, float c2y, float c2z, float c2w,
			float c3x, float c3y, float c3z, float c3w,
			float c4x, float c4y, float c4z, float c4w);

		//! Constructs a 4x4 matrix with specified columns.
		/*! @param col1 Left-most column.
		  * @param col2 Second column. 
		  * @param col3 Third column.
		  * @param col4 Right-most column. */
		Mat4(const maths::Vec4& col1, const maths::Vec4& col2, const maths::Vec4& col3, const maths::Vec4& col4);

		//! Cosntruct a 4x4 matrix using a 3x3 matrice's elements.
		/*! @param mat3 A 3x3 matrix. */
		Mat4(const maths::Mat3& mat3);

		//! Default destructor.
		~Mat4();

		//! Get the determinant of the Mat4.
		/*! @return The determinant of the Mat4. */
		float determinant() const;

		//! Transpose the matrix.
		/*! Flips the matrix components on the diagonal; makes the columns of the matrix become the rows of the matrix and vice versa. */
		void transpose();

		//! Get a pointer to the matrices elements.
		/*! @return A pointer to the first component of the element. */
		const float* const data_ptr() const;

		//! Add two 4x4 matrix objects together.
		/*! @param mat4 A 4x4 matrix object. */
		Mat4 operator+(const Mat4& mat4) const;

		//! Substract one 4x4 matrix from another.
		/*! @param mat4 A 4x4 matrix object. */
		Mat4 operator-(const Mat4& mat4) const;

		//! Multiply two 4x4 matrix objects together.
		/*! @param mat4 A 4x4 matrix object. */
		Mat4 operator*(const Mat4& mat4) const;

		//! Multiply a four-component vector by a 4x4 matrix.
		/*! @param vec4 A four-component vector object. */
		Vec4 operator*(const Vec4& vec4) const;

		//! Increment one matrix object's components by another's.
		/*! @param mat4 A 4x4 matrix object. */
		Mat4& operator+=(const Mat4& mat4);

		//! Decremement one matrix object's components by another's.
		/*! @param mat4 A 4x4 matrix object. */
		Mat4& operator-=(const Mat4& mat4);

		//! Assign one matrix object to the product of itself and another.
		/*! @param mat4 A 4x4 matrix object. */
		Mat4& operator*=(const Mat4& mat4);

		//! Compare two matrix object's equivalence to eachother.
		/*! @param mat4 A 4x4 matrix object. */
		bool operator==(const Mat4& mat4) const;

		//! Compare two matrix object's inequality.
		/*! @param mat4 A 4x4 matrix object. */
		bool operator!=(const Mat4& mat4) const;

		//! Get a non-mutable reference of the matrix element at @c (col,row)
		/*! @param col The component's column.
		  * @param row The component's row. */
		const float& operator()(int col, int row) const;

		//! Get a mutable reference of the matrix element at @c (col,row)
		/*! @param col The component's column.
		  * @param row The component's row. */
		float& operator()(int col, int row);

	private:
		float m_values[16]; /*!< The matrix object's components, stored column-major order. */
	};

} }