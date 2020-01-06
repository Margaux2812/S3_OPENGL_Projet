#include "../include/FreeflyCamera.hpp"
#include "../include/cube.hpp"
#include <math.h>
#include <iostream>

FreeflyCamera::FreeflyCamera(){
	m_Position = initialPos();
	m_fPhi = M_PI;
	m_fTheta = 0.f;
	computeDirectionVectors(m_FrontVector, m_LeftVector, m_UpVector, m_fPhi, m_fTheta);
}

//Méthodes
glm::vec3 FreeflyCamera::initialPos(){
    return glm::vec3(25.f, 1.f, 25.f);
}

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
void FreeflyCamera::moveUp(const float t){
    m_Position += t*m_UpVector;
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

    /*On veut faire modulo 2PI*/
    if(m_fPhi < -(float)M_PI){
        m_fPhi += 2.f*M_PI;
    }else if(m_fPhi > (float)M_PI){
        m_fPhi -= 2.f*M_PI;
    }
	m_FrontVector = glm::vec3(std::cos(m_fTheta)*std::sin(m_fPhi), 
							  std::sin(m_fTheta), 
							  std::cos(m_fTheta)*std::cos(m_fPhi));
	m_LeftVector = glm::vec3(std::sin(m_fPhi+M_PI/2.), 
							  0.f, 
							  std::cos(m_fPhi+M_PI/2.));
}
void FreeflyCamera::rotateLeft(const float degrees){
	m_fTheta += glm::radians(degrees);

    /*On peut faire une rotation que jusqu'à regarder le sol, ou regarder le ciel*/
    if(m_fTheta < -1.41f){
        m_fTheta = -1.41f;
    }else if(m_fTheta > 1.57){
        m_fTheta=1.57;
    }

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

void FreeflyCamera::updateCameraMovement(){
        if(forwardPressed){
        	moveFront(cameraSpeed);
        }
        else if(backwardPressed){
        	moveFront(-cameraSpeed);
        }
        else if(leftPressed){
        	moveLeft(cameraSpeed);
        }
        else if(rightPressed){
        	moveLeft(-cameraSpeed);
        }
        else if(upPressed){
            moveUp(cameraSpeed);
        }
        else if(downPressed){
            moveUp(-cameraSpeed);
        }

    SDL_EventState(SDL_MOUSEMOTION, SDL_IGNORE);
    SDL_WarpMouse(400, 300);
    SDL_EventState(SDL_MOUSEMOTION, SDL_ENABLE); 
}

void FreeflyCamera::handleKeyboardEventsDown(const SDLKey e){
    switch(e){
        /*Z key to move forward*/
        case SDLK_z: forwardPressed = true;
        break;
        /*S key to move backward*/
        case SDLK_s: backwardPressed = true;
        break;
        /*Q key to move left*/
        case SDLK_q: leftPressed = true;
        break;
        /*D key to move right*/
        case SDLK_d: rightPressed = true;
        break;
        /*A key to move up*/
        case SDLK_a: upPressed = true;
        break;
        /*D key to move down*/
        case SDLK_w: downPressed = true;
        break;
        
        default: break;
    }
}

void FreeflyCamera::handleKeyboardEventsUp(const SDLKey e){
    switch(e){
        /*Z key to move forward*/
        case SDLK_z: forwardPressed = false;
        break;
        /*S key to move backward*/
        case SDLK_s: backwardPressed = false;
        break;
        /*Q key to move left*/
        case SDLK_q: leftPressed = false;
        break;
        /*D key to move right*/
        case SDLK_d: rightPressed = false;
        break;
        /*A key to move up*/
        case SDLK_a: upPressed = false;
        break;
        /*D key to move down*/
        case SDLK_w: downPressed = false;
        break;
        
        default: break;
    }
}

void FreeflyCamera::handleMouseEvents(const SDL_Event e){
    if(!mouseEnteredScreen){
        SDL_ShowCursor(SDL_DISABLE);
        SDL_WarpMouse(400, 300);
        SDL_WM_GrabInput(SDL_GRAB_ON);
        mouseEnteredScreen = true;
    }
    if ( e.motion.xrel != 0 ) {
      rotateUp( float(-e.motion.xrel) * cameraSpeedRotation);
    }
    if ( e.motion.yrel != 0 ) {
      rotateLeft( float(-e.motion.yrel) * cameraSpeedRotation);
    }
    //SDL_WarpMouse(400, 300);
}