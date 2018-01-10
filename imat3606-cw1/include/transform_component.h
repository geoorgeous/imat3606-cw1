#pragma once

/*! @file transform_component.h
  * @brief Header file for TransformComponent class.
  * @author George McDonagh */


// Internal includes

#include "maths\maths.h"
#include "component.h"


// Namespaces

namespace engine {

	//! 3D transform component.
	class TransformComponent : public Component
	{
	public:
		//! Transform constructor.
		/*! @param position A 3-component vector representing a position in 3D space relative to the X, Y, and Z axes.
		  * @param scale A 3-component vector representing a 3D scale.
		  * @param orientation A 3-component vector representing a rotation in 3D space around the X, Y, and Z axis. */
		TransformComponent(maths::Vec3 position, maths::Vec3 scale, maths::Vec3 orientation);

		//! Transform destructor.
		~TransformComponent() override;

		//! Get the Transform's position.
		/*! @return A reference to an immutable 3-component vector. The Transforms 3D position. */
		const maths::Vec3& position() const;

		//! Get the Transform's scale.
		/*! @return A reference to an immutable 3-component vector. The Transform scale components. */
		const maths::Vec3& scale() const;

		//! Get the Transform's orientation.
		/*! @return A reference to an immutable 3-component vector. The transforms orientation in 3D space. */
		const maths::Vec3& orientation() const;

		//! Get the Transform's position.
		/*! @return A reference to a mutable 3-component vector. The Transforms 3D position. */
		maths::Vec3& position();

		//! Get the Transform's scale.
		/*! @return A reference to a mutable 3-component vector. The Transform scale components. */
		maths::Vec3& scale();

		//! Get the Transform's orientation.
		/*! @return A reference to a mutable 3-component vector. The transforms orientation in 3D space. */
		maths::Vec3& orientation();

		//! Get the Transform's transform matrix.
		/*! Calculates and returns the matrix calculated by combining the transforms three components together.
		  * @return A 4x4 matrix. The Transform's transform matrix. */
		maths::Mat4 getMatrix() const;

	private:
		maths::Vec3 m_position; /*!< The Transform's position. */
		maths::Vec3 m_scale; /*!< The Transform's scale. */
		maths::Vec3 m_orientation; /*! The Transform's orientation. */
	};

}