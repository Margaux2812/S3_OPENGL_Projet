#pragma once


/*!
 * \file FreeflyCamera.hpp
 * \brief Create a camera
 */

#include "../lib/glimac/include/glm.hpp"
#include "../lib/glimac/include/SDLWindowManager.hpp"

class FreeflyCamera{
private :
	glm::vec3 m_Position;
	float m_fPhi;
	float m_fTheta;
	glm::vec3 m_FrontVector;
	glm::vec3 m_LeftVector;
	glm::vec3 m_UpVector;
	const float cameraSpeed = 0.1f;
	const float cameraSpeedRotation = 0.1f;
	bool upPressed = false;
	bool downPressed = false;
	bool forwardPressed = false;
	bool backwardPressed = false;
	bool rightPressed = false;
	bool leftPressed = false;
	bool mouseEnteredScreen = false;

public:
	//Constructeur
	/**
	 * \brief Construct a new Freefly Camera object
	 * 
	 */
	FreeflyCamera();

	//Méthodes

	/**
	 * \brief give initial position to the camera
	 * 
	 * \return glm::vec3 initial position of the camera
	 */
	glm::vec3 initialPos();

	/**
	 * \brief Calculate movement vector of camera
	 * 
	 * \param m_FrontVector 
	 * \param m_LeftVector 
	 * \param m_UpVector 
	 * \param m_fPhi 
	 * \param m_fTheta 
	 */
	void computeDirectionVectors(glm::vec3 &m_FrontVector, glm::vec3 &m_LeftVector, glm::vec3 &m_UpVector, const float m_fPhi, const float m_fTheta);

	/**
	 * \brief move up and down
	 * 
	 * \param t Speed of movement
	 */
	void moveUp(const float t);

	/**
	 * \brief move left and right
	 * 
	 * \param t Speed of movement
	 */
	void moveLeft(const float t);

	/**
	 * \brief move front and back
	 * 
	 * \param t Speed of movement
	 */
	void moveFront(const float t);

	/**
	 * \brief rotate caracter camera to the left and right
	 * 
	 * \param degrees degrees of rotation
	 */
	void rotateLeft(const float degrees);

	/**
	 * \brief rotate caracter camera up and down
	 * 
	 * \param degrees degrees of rotation
	 */
	void rotateUp(const float degrees);

	/**
	 * \brief Get the View Matrix object
	 * 
	 * \return glm::mat4 
	 */
	glm::mat4 getViewMatrix() const;

	/**
	 * \brief check selected movement and select good function
	 * 
	 */
	void updateCameraMovement();

	/**
	 * \brief stop movement of camera when inPause
	 * 
	 */
	void stopMovement();

	/**
	 * \brief Camera key down event manager
	 * 
	 * \param e event
	 */
	void handleKeyboardEventsDown(const SDLKey e);

	/**
	 * \brief Camera key up event manager
	 * 
	 * \param e event
	 */
	void handleKeyboardEventsUp(const SDLKey e);

	/**
	 * \brief Camera mouse event manager
	 * 
	 * \param e event
	 */
	void handleMouseEvents(const SDL_Event e);
};