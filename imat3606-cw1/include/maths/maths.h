#pragma once

/*!
 * @file maths.h
 * @brief Header file containing maths classes and structs
 * @author George McDonagh */


// External includes

#include <math.h>


// Forward declare classes before including their header files.

namespace engine { namespace maths {

	class Mat2;
	class Mat3;
	class Mat4;

	class Vec2;
	class Vec3;
	class Vec4;

} }


// Local includes

#include "matrix\mat2.h"
#include "matrix\mat3.h"
#include "matrix\mat4.h"

#include "vector\vec2.h"
#include "vector\vec3.h"
#include "vector\vec4.h"


// Macros

#define MATH_PI 3.14159265359f


// Namespace

namespace engine { namespace maths {

	//! Convert radians to degrees.
	/*! @param radians Value of radians to convert to degrees. 
	  * @return Value of @p radians converted to degrees. */
	float degrees(float radians);

	//! Convert degrees to radians.
	/*! @param degrees Value of degrees to convert to radians.
	  * @return Value of @p degrees converted to radians. */
	float radians(float degrees);

	//! Get a vector's unit vector.
	/*! Calculates and returns a vector's unit-length vector.
	  * @param vec2 A two-component vector. 
	  * @return @p vec2's normalized vector. */
	Vec2 normalize(const Vec2& vec2);

	//! Get a vector's unit vector.
	/*! Calculates and returns a vector's unit-length vector.
	  * @param vec3 A three-component vector.
	  * @return @p vec3's normalized vector. */
	Vec3 normalize(const Vec3& vec3);

	//! Get a vector's unit vector.
	/*! Calculates and returns a vector's unit-length vector.
	  * @param vec3 A four-component vector.
	  * @return @p vec4's normalized vector. */
	Vec4 normalize(const Vec4& vec4);

	//! Find the dot product of two three-component vectors.
	/*! @param vec3a The first vector. 
	  * @param vec3b The second vector.
	  * @return The dot product of @p vec3a and @p vec3b. */
	float dot(const Vec3& vec3a, const Vec3& vec3b);

	//! Find the cross product of two three-component vectors.
	/*! Calculates the cross product of two three-component vectors.
	  * @param vec3a The first vector. 
	  * @param vec3b The second vector.
	  * @return A three-component vector perpendicular to both @p vec3a and @p vec3b. */
	Vec3 cross(const Vec3& vec3a, const Vec3& vec3b);

	//! A 2x2 identity matrix.
	/*! @return A 2x2 matrix with a value of 1 assigned to its diagonal components. */
	Mat2 identityMat2();

	//! A 3x3 identity matrix.
	/*! @return A 3x3 matrix with a value of 1 assigned to its diagonal components. */
	Mat3 identityMat3();

	//! A 4x4 identity matrix.
	/*! @return A 4x4 matrix with a value of 1 assigned to its diagonal components. */
	Mat4 identityMat4();

	//! Create a translation matrix from a three-component vector.
	/*! @param t A three-component vector.
	  * @return A 4x4 identity matrix with the first three components of its fourth column assigned the values of @p t. */
	Mat4 translation(const Vec3& t);

	//! Create a scale matrix from a three-component vector.
	/*! @param s A three-component vector. 
	  * @return A 4x4 matrix with the first three diagonal components assigned the values of @p s. */
	Mat4 scale(const Vec3& s);

	//! Create a rotation matrix which rotates around the X axis.
	/*! @param Number of degrees to rotate around X.
	  * @param A 4x4 rotation matrix which rotates around the X axis. */
	Mat4 rotationX(float degrees);

	//! Create a rotation matrix which rotates around the Y axis.
	/*! @param Number of degrees to rotate around Y.
	  * @param A 4x4 rotation matrix which rotates around the Y axis. */
	Mat4 rotationY(float degrees);

	//! Create a rotation matrix which rotates around the Z axis.
	/*! @param Number of degrees to rotate around Z.
	  * @param A 4x4 rotation matrix which rotates around the Z axis. */
	Mat4 rotationZ(float degrees);

	//! Creates a rotation matrix which rotates around all three axis.
	/*! @param r A three-component vector.
	  * @return A 4x4 rotation matrix which combines rotations around X, Y, and Z. */
	Mat4 rotation(const Vec3& r);

	//! Calculate the inverse of a 2x2 matrix.
	/*! @param mat2 A 2x2 matrix.
	  * @return The inverse of @p mat2. */
	Mat2 inverse(const Mat2& mat2);

	//! Calculate the inverse of a 3x3 matrix.
	/*! @param mat3 A 3x3 matrix.
	  * @return The inverse of @p mat3. */
	Mat3 inverse(const Mat3& mat3);

	//! Calculate the inverse of a 4x4 matrix.
	/*! @param mat4 A 4x4 matrix.
	  * @return The inverse of @p mat4. */
	Mat4 inverse(const Mat4& mat4);
	
	//! Calculate the transpose of a 2x2 matrix.
	/*! @param mat2 A 2x2 matrix.
	  * @return The transpose of @p mat2. */
	Mat2 transpose(const Mat2& mat2);

	//! Calculate the transpose of a 3x3 matrix.
	/*! @param mat3 A 3x3 matrix.
	  * @return The transpose of @p mat3. */
	Mat3 transpose(const Mat3& mat3);

	//! Calculate the transpose of a 4x4 matrix.
	/*! @param mat4 A 4x4 matrix.
	  * @return The transpose of @p mat4. */
	Mat4 transpose(const Mat4& mat4);

	//! Create a LookAt matrix.
	/*! Creates a LookAt matrix given an eye (camera) position, a forwards direction vector, and a up-direction vector. 
	  * @param eye Position of the eye relative to world origin. 
	  * @param forwards The direction the eye is pointing toward. 
	  * @param up The up-direction vector of the eye. 
	  * @return A 4x4 LookAt matrix. */
	Mat4 lookAt(const Vec3& eye, const Vec3& forwards, const Vec3& up);

	//! Create a perspective projection matrix.
	/*! Creates a perspective projection matrix given a field of view, view aspect ratio, and clipping planes. 
	  * @param fov Field of View in degrees. 
	  * @param aspect The aspect ratio of the final projection. 
	  * @param The near-clipping distance from the projection. 
	  * @param The far-clipping distance from the projection. 
	  * @return Returns a 4x4 perspective projection matrix. */
	Mat4 perspective(float fov, float aspect, float nearClip, float farClip);

	Mat2 operator*(float f, const Mat2& mat2);

	Mat3 operator*(float f, const Mat3& mat3);

	Mat4 operator*(float f, const Mat4& mat4);

} }