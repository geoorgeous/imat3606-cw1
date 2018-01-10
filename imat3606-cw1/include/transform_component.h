#pragma once

/*! @file transform_component.h
  * @brief Header file for TransformComponent class.
  * @author George McDonagh */


// Internal includes

#include "maths\maths.h"
#include "component.h"


namespace engine {

	class TransformComponent : public Component
	{
	public:
		TransformComponent(maths::Vec3 position, maths::Vec3 scale, maths::Vec3 orientation);

		~TransformComponent() override;

		const maths::Vec3& position() const;

		const maths::Vec3& scale() const;

		const maths::Vec3& orientation() const;

		maths::Vec3& position();

		maths::Vec3& scale();

		maths::Vec3& orientation();

		maths::Mat4 getMatrix() const;

	private:
		maths::Vec3 m_position;
		maths::Vec3 m_scale;
		maths::Vec3 m_orientation;
	};

}