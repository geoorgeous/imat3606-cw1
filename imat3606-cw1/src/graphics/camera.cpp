/*!
 * @file camera.cpp
 * @brief Implimentation file for the Camera class.
 * @author George McDonagh */


// Local includes

#include "graphics/camera.h"


// Namespaces

using namespace engine::graphics;


Camera::Camera()
{
	m_fov = 67.0f;
	m_aspect = 1.0f;
	m_nearClip = 0.1f;
	m_farClip = 100.0f;

	m_position = maths::Vec3();
	m_orientation = maths::Vec3();

	m_up = maths::Vec3(0.0f, 1.0f, 0.0f);
	m_forward = maths::Vec3(0.0f, 0.0f, -1.0f);
	m_right = cross(m_up, m_forward);

	m_speed = 0.1f;
	m_rotationSensitivity = 0.5f;

	updateView();
	updatePerspective();
}

Camera::Camera(engine::maths::Vec3 position, engine::maths::Vec3 direction, float fov, float aspect, float nearClip, float farClip)
{
	m_fov = fov;
	m_aspect = aspect;
	m_nearClip = nearClip;
	m_farClip = farClip;

	m_position = position;
	m_orientation = maths::Vec3();

	m_up = maths::Vec3(0.0f, 1.0f, 0.0f);
	m_forward = direction;
	m_right = cross(m_up, m_forward);

	m_speed = 0.1f;
	m_rotationSensitivity = 0.5f;

	updateView();
	updatePerspective();
}

Camera::~Camera() { }

const engine::maths::Vec3& Camera::position() const
{
	return m_position;
}

const engine::maths::Vec3& Camera::direction() const
{
	return m_forward;
}

const engine::maths::Vec3& Camera::orientation() const
{
	return m_orientation;
}

const engine::maths::Mat4& Camera::getViewMatrix() const
{
	return m_matView;
}

const engine::maths::Mat4& Camera::getPerspectiveMatrix() const
{
	return m_matPerspective;
}

const float& Camera::fov() const
{
	return m_fov;
}

float& Camera::fov()
{
	return m_fov;
}

const float& Camera::aspect() const
{
	return m_aspect;
}

float& Camera::aspect()
{
	return m_aspect;
}

const float& Camera::nearClip() const
{
	return m_nearClip;
}

float& Camera::nearClip()
{
	return m_nearClip;
}

const float& Camera::farClip() const
{
	return m_farClip;
}

float& Camera::farClip()
{
	return m_farClip;
}

void Camera::move(engine::maths::Vec3 offset)
{
	offset = (m_forward * offset.z()) + (m_right * offset.x()) + (m_up * offset.y());
	m_position += offset * m_speed;

	updateView();
}

void Camera::rotate(engine::maths::Vec3 offset)
{
	m_orientation += offset * m_rotationSensitivity;

	updateView();
}

void Camera::updateView()
{
	maths::Mat4 r = maths::rotation(m_orientation);
	maths::Mat4 t = maths::translation(-m_position);
	m_matView = r * t;

	m_forward = maths::Vec3(m_matView(0, 2), m_matView(1, 2), m_matView(2, 2));
	m_up = maths::Vec3(m_matView(0, 1), m_matView(1, 1), m_matView(2, 1));
	m_right = maths::Vec3(m_matView(0, 0), m_matView(1, 0), m_matView(2, 0));
}

void Camera::updatePerspective()
{
	m_matPerspective = engine::maths::perspective(engine::maths::radians(m_fov), m_aspect, m_nearClip, m_farClip);
}