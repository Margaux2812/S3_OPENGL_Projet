#include "../include/FreeflyCamera.hpp"
#include <math.h>

FreeflyCamera::FreeflyCamera(){
	m_Position = glm::vec3(0.f, 0.f, 0.f);
	m_fPhi = M_PI;
	m_fTheta = 0.f;
	computeDirectionVectors(m_FrontVector, m_LeftVector, m_UpVector, m_fPhi, m_fTheta);
}

//Méthodes
void FreeflyCamera::computeDirectionVectors(glm::vec3 &m_FrontVector, glm::vec3 &m_LeftVector, glm::vec3 &m_UpVector, const float m_fPhi, const float m_fTheta){
	m_FrontVector = glm::vec3(
		std::cos(m_fTheta)*std::sin(m_fPhi), 
		std::sin(m_fTheta), 
		std::cos(m_fTheta)*std::cos(m_fPhi));
	m_LeftVector = glm::vec3(
		std::sin(m_fPhi+M_PI/2.f), 
		0.f, 
		std::cos(m_fPhi+M_PI/2.f));
	m_UpVector = glm::cross(m_FrontVector, m_LeftVector);
}
void FreeflyCamera::moveLeft(const float t){
	m_Position += t*m_LeftVector;
	m_UpVector = glm::cross(m_FrontVector, m_LeftVector);
}
void FreeflyCamera::moveFront(const float t){
	m_Position += t*m_FrontVector;
	m_UpVector = glm::cross(m_FrontVector, m_LeftVector);
}
void FreeflyCamera::rotateUp(const float degrees){
	m_fPhi += glm::radians(degrees);
	m_FrontVector = glm::vec3(std::cos(m_fTheta)*std::sin(m_fPhi), 
							  std::sin(m_fTheta), 
							  std::cos(m_fTheta)*std::cos(m_fPhi));
	m_LeftVector = glm::vec3(std::sin(m_fPhi+M_PI/2.), 
							  0.f, 
							  std::cos(m_fPhi+M_PI/2.));
}
void FreeflyCamera::rotateLeft(const float degrees){
	m_fTheta += glm::radians(degrees);
	m_FrontVector = glm::vec3(std::cos(m_fTheta)*std::sin(m_fPhi), 
							  std::sin(m_fTheta),
							  std::cos(m_fTheta)*std::cos(m_fPhi));
	m_LeftVector = glm::vec3(std::sin(m_fPhi+M_PI/2.), 
							 0.f,
							 std::cos(m_fPhi+M_PI/2.));
}
glm::mat4 FreeflyCamera::getViewMatrix() const{
	return glm::lookAt(m_Position, m_Position+m_FrontVector, m_UpVector);
}


void FreeflyCamera::handleKeyboardEvents(const SDLKey e){
    switch(e){
        /*Z key to move forward*/
        case SDLK_z: moveFront(cameraSpeed);
        break;
        /*S key to move backward*/
        case SDLK_s: moveFront(-cameraSpeed);
        break;
        /*Q key to move left*/
        case SDLK_q: moveLeft(cameraSpeed);
        break;
        /*D key to move right*/
        case SDLK_d: moveLeft(-cameraSpeed);
        break;
        
        default: break;
    }
}