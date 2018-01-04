#pragma once

/*!
 * @file mat3.h
 * @brief Header file for the Mat3 class.
 * @author George McDonagh */


// Local includes

#include "maths/maths.h"


// Namespaces

namespace engine { namespace maths {

	//! 3x3 Matrix.
	/*! A 3x3 Matrix with column-major order. 
	  * @note Linear memory storage layout: 
	  * [0] [3] [6] 
	  * [1] [4] [7]
	  * [2] [5] [8] */
	class Mat3
	{
	public:
		//! Default constructor.
		/*! Constructs a 3x3 identity matrix. */
		Mat3();

		//! Constructs a 3x3 matrix with a specified diagonal value.
		/*! @param diagonal The value of the components on the diagonal. */
		Mat3(float diagonal);

		//! Constructs a 3x3 matrix with specified components.
		/*! @param values The values of the matrix in column-major order. */
		Mat3(float values[9]);

		//! Constructs a 3x3 matrix with specified components.
		/*! @param c1x Left-most column's X component.
		  * @param c1y Left-most column's Y component.
		  * @param c1z Left-most column's Z component.
		  * @param c2x Middle column's X component.
		  * @param c2y Middle column's Y component. 
		  * @param c2z Middle column's Z component.
		  * @param c3x Right-most column's X component.
		  * @param c3y Right-most column's Y component.
		  * @param c3z Right-most column's Z component. */
		Mat3(float c1x, float c1y, float c1z,
			float c2x, float c2y, float c2z,
			float c3x, float c3y, float c3z);

		//! Constructs a 3x3 matrix with specified columns.
		/*! @param col1 Left-most column.
		  * @param col2 Middle column. 
		  * @param col3 Right-most column. */
		Mat3(const Vec3& col1, const Vec3& col2, const Vec3& col3);

		//! Constructs a 3x3 matrix using the top left components of a 4x4.
		/*! @param mat4 A 4x4 matrix. */
		Mat3(const Mat4& mat4);

		//! Destructor.
		~Mat3();

		//! Get the determinant of the Mat3.
		/*! @return The determinant of the Mat3. */
		float determinant() const;

		//! Transpose the matrix.
		/*! Flips the matrix components on the diagonal; makes the columns of the matrix become the rows of the matrix and vice versa. */
		void transpose();

		//! Get a pointer to the matrices elements.
		/*! @return A pointer to the first component of the element. */
		const float* const data_ptr() const;

		//! Add two 3x3 matrix objects together.
		/*! @param mat3 A 3x3 matrix object. */
		Mat3 operator+(const Mat3& mat3) const;

		//! Substract one 3x3 matrix from another.
		/*! @param mat3 A 3x3 matrix object. */
		Mat3 operator-(const Mat3& mat3) const;

		//! Multiply two 3x3 matrix objects together.
		/*! @param mat3 A 3x3 matrix object. */
		Mat3 operator*(const Mat3& mat3) const;

		//! Multiply a three-component vector by a 3x3 matrix.
		/*! @param vec3 A three-component vector object. */
		Vec3 operator*(const maths::Vec3& vec3) const;

		//! Increment one matrix object's components by another's.
		/*! @param mat3 A 3x3 matrix object. */
		Mat3& operator+=(const Mat3& mat3);

		//! Decremement one matrix object's components by another's.
		/*! @param mat3 A 3x3 matrix object. */
		Mat3& operator-=(const Mat3& mat3);

		//! Assign one matrix object to the product of itself and another.
		/*! @param mat3 A 3x3 matrix object. */
		Mat3& operator*=(const Mat3& mat3);

		//! Compare two matrix object's equivalence to eachother.
		/*! @param mat3 A 3x3 matrix object. */
		bool operator==(const Mat3& mat3) const;

		//! Compare two matrix object's inequality.
		/*! @param mat3 A 3x3 matrix object. */
		bool operator!=(const Mat3& mat3) const;

		//! Get a non-mutable reference of the matrix element at @c (col,row)
		/*! @param col The component's column.
		  * @param row The component's row. */
		const float& operator()(int col, int row) const;

		//! Get a mutable reference of the matrix element at @c (col,row)
		/*! @param col The component's column.
		  * @param row The component's row. */
		float& operator()(int col, int row);

	private:
		float m_values[9]; /*!< The matrix object's components, stored column-major order. */
	};

} }