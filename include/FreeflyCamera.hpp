#pragma once
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
	bool rightPressed = false;
	bool leftPressed = false;

public:
	//Constructeur
	FreeflyCamera();

	//Méthodes
	void computeDirectionVectors(glm::vec3 &m_FrontVector, glm::vec3 &m_LeftVector, glm::vec3 &m_UpVector, const float m_fPhi, const float m_fTheta);
	void moveLeft(const float t);
	void moveFront(const float t);
	void rotateLeft(const float degrees);
	void rotateUp(const float degrees);
	glm::mat4 getViewMatrix() const;

	void updateCameraMovement();
	void handleKeyboardEventsDown(const SDLKey e);
	void handleKeyboardEventsUp(const SDLKey e);
	void handleMouseEvents(const SDL_Event e);
};