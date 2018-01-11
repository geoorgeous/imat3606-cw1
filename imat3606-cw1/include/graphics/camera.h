#pragma once

/*!
  * @file camera.h
  * @brief Header file for the Camera class.
  * @author George McDonagh */


// Local includes

#include "maths\maths.h"


// Namespaces

namespace engine { namespace graphics {

	//! Stores the state of a camera.
	/*! Stores all the information needed to control the way a given scene is displayed to the user. */
	class Camera
	{
	public:
		//! Default constructor.
		/*! Creates a camera at (0,0,0), looking in the negative z direction, with a 67 degree FOV, a 1:1 aspect ratio, a near clip of 0.1, and a far clip of 100. */
		Camera();

		//! Primary Camera constructor.
		/*! @param position Pos.
		  * @param direction Direction.
		  * @param fov Fov.
		  * @param aspect Aspect.
		  * @param nearClip Nearclip.
		  * @param farClip Farclip. */
		Camera(maths::Vec3 position, maths::Vec3 direction, float fov, float aspect, float nearClip, float farClip);
		
		//! Camera object destructor.
		~Camera();

		//! Camera position.
		/*! @return A reference to an immutable 3-component vector; the Camera object's position containing its X, Y, and Z position. */
		const maths::Vec3& position() const;

		//! Camera forwards direction.
		/*! @return A reference to an immutable 3-component vector; the Camera's forward-facing direction. */
		const maths::Vec3& direction() const;

		//! Camera orientation around its own axis.
		/*! @return A reference to an immutable 3-component vector; the Camera object's orientation containing its X, Y, and Z orientations. */
		const maths::Vec3& orientation() const;

		//! Gets a LookAt matrix constructed from the Camera's properties.
		/*! @return A reference to an immutable 4x4 matrix; the Camera's cached view matrix. */
		const maths::Mat4& getViewMatrix() const;

		//! Gets a perspective projection matrix constructed from the Camera's properties.
		/*! @return A reference to an immutable 4x4 matrix; the Camera's cached perspective matrix. */
		const maths::Mat4& getPerspectiveMatrix() const;

		//! Get the Camera's Field of View.
		/*! @return A reference to an immutable float; the Camera's Field of View (in degrees). */
		const float& fov() const;

		//! Get the Camera's Field of View.
		/*! @return A reference to a mutable float; the Camera's Field of View (in degrees). */
		float& fov();

		//! Get the Camera's asepect ratio.
		/*! @return A reference to an immutable float; the Camera's Aspect Ratio. For a standard projection this would be the current context's @p width/height. */
		const float& aspect() const;

		//! Get the Camera's asepect ratio.
		/*! @return A reference to a mutable float; the Camera's Aspect Ratio. For a standard projection this would be the current context's @p width/height. */
		float& aspect();

		//! Get the Camera's near-clip value.
		/*! @return A reference to an immutable float; the number of units from the Camera that objects will start to render from. */
		const float& nearClip() const;

		//! Get the Camera's near-clip value.
		/*! @return A reference to a mutable float; the number of units from the Camera that objects will start to render from. */
		float& nearClip();

		//! Get the Camera's far-clip value.
		/*! @return A reference to an immutable float; the number of units from the Camera that objects will stop being rendered from. */
		const float& farClip() const;

		//! Get the Camera's far-clip value.
		/*! @return A reference to a mutable float; the number of units from the Camera that objects will stop being rendered from. */
		float& farClip();

		//! Move the Camera object.
		/*! Moves the position of the camera along its own axis.
		  * @param offset The position offset. 
		  * @note As this changes the position of the camera the View matrix is recalculated when calling @c move() */
		void move(maths::Vec3 offset);

		//! Rotate the Camera object.
		/*! Rotates the orientation of the Camera.
		  * @param offset The amount of rotation to offset the current orientation by.
		  * @note As this changes the orientation of the camera the View matrix is recalculated when calling @c rotate() */
		void rotate(maths::Vec3 offset);

	private:
		float m_fov; /*!< Field of View (in degrees). */
		float m_aspect; /*!< Aspect ratio (width / height) */
		float m_nearClip; /*!< Distance from the camera that graphics will start being rendered. */
		float m_farClip; /*!< Distance from the camera that graphics will stop being rendered. */

		maths::Mat4 m_matView; /*!< View matrix of the Camera object. */
		maths::Mat4 m_matPerspective; /*!< Perspective projection matrix of the Camera object. */

		maths::Vec3 m_position; /*< Camera position in 3D space. */
		maths::Vec3 m_orientation; /*< Camera orientation in 3D space. */

		maths::Vec3 m_up; /*!< The up-direction vector of the camera. Equivalant to its local Y axis. */;
		maths::Vec3 m_forward; /*!< The forward-direction vector representing where the camera is pointed. Equivalant to its local Z axis. */;
		maths::Vec3 m_right; /*!< The vector casting off to the right hand side of the camera. Equivalant to its local X axis. */

		float m_speed; /*! Camera movement speed modifier. */
		float m_rotationSensitivity; /*! Sensitivity to rotations. */

		//! Update the Camera's view matrix.
		/*! Recalculates and caches the View matrix with the Camera object's current position and orientation. This is generally called every time the Camera's position or orientation is changed. */
		void updateView();

		//! Update the Camera's perspective matrix.
		/*! Recalculates and caches the Perspective matrix with the Camera object's current field of view, aspect ratio, and clipping plane distances. */
		void updatePerspective();
	};

} }