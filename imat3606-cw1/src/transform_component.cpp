/*!
 * @file transform_component.cpp
 * @brief Implementation file for the TransformComponent class.
 * @author George McDonagh */


// Local includes

#include "transform_component.h"


// Namespaces

using namespace engine;


TransformComponent::TransformComponent(maths::Vec3 position, maths::Vec3 scale, maths::Vec3 orientation)
	: Component(), m_position(position), m_scale(scale), m_orientation(orientation) { }

TransformComponent::~TransformComponent() { }

const maths::Vec3& TransformComponent::position() const
{
	return m_position;
}

const maths::Vec3& TransformComponent::scale() const
{
	return m_scale;
}

const maths::Vec3& TransformComponent::orientation() const
{
	return m_orientation;
}

maths::Vec3& TransformComponent::position()
{
	return m_position;
}

maths::Vec3& TransformComponent::scale()
{
	return m_scale;
}

maths::Vec3& TransformComponent::orientation()
{
	return m_orientation;
}

maths::Mat4 TransformComponent::getMatrix() const
{
	return maths::Mat4();
}