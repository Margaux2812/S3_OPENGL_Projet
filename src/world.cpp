#include "../include/world.hpp"

World::World()
:m_skybox(new Skybox),
m_selector(new Selector),
m_pinceau(new Pinceau)
{
    for(int i=0; i!=REACHEND; ++i){
	    m_allCubes.push_back(new Cube((typeCube)i));
    }
}

World::~World(){
	for(uint i=0; i<m_allCubes.size(); i++){
		delete m_allCubes[i];
	}
	delete m_skybox;
}

void World::drawLights(){
    for(GLuint i=0; i<m_allCubes[LIGHT]->size(); i++){
        m_lights[i] = (m_allCubes[LIGHT]->getData()[i]);
    }
    for(GLuint i=m_allCubes[LIGHT]->size(); i<6; i++){
        m_lights[i] = (glm::vec3(0.f, 0.f, 0.f));
    }
}

void World::draw(const glm::mat4 MVMatrix, const bool ctrlIsPressed){
	m_skybox->draw(MVMatrix);

	glDepthRange(0, 0.01); //Pour que le curseur soit visible à tout moment
	glm::vec3 color;
	
	if(ctrlIsPressed){
		color = glm::vec3(1.f, 1.f, 0.f);
	}else if(existsSmth(m_selector->getPosition())){
		color = glm::vec3(1.f, 0.f, 0.f);
	}else{
		color = glm::vec3(0.33f, 0.65f, 1.f);
	}

	m_selector->draw(MVMatrix, color);
	glDepthRange(0.01, 1.0); //Pour que le curseur soit visible à tout moment

	glEnable(GL_BLEND); //Pour la transparence
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); //Pour la transparence
    
    drawLights();
    /*On ne dessine pas les lumières*/
	for(uint i=1; i<REACHEND; i++){
		m_allCubes[i]->draw(MVMatrix, m_lights);
	}

    glDisable(GL_BLEND);
    glDepthRange(0, 1.0); //Pour que le curseur soit visible à tout moment
    
    m_pinceau->draw();
}
void World::handleEvents(const SDLKey e, const bool ctrlIsPressed){
	m_pinceau->handleEvents(e);

	/*Handle Cube events*/
	switch(e){
    	case SDLK_DELETE:	for(uint i=0; i<m_allCubes.size(); i++){
				        		m_allCubes[i]->deleteCube(m_selector->getPosition());
				        	}
		break;
		case SDLK_RETURN:	if(ctrlIsPressed){
								replace(m_selector->getPosition(), m_pinceau->getType());
							}else{
								addCube(m_selector->getPosition(), m_pinceau->getType());
							}
		break;
		case SDLK_n : 		changeNightMode();
		break;
        case SDLK_c : 		digCube(m_selector->getPosition(), m_pinceau->getType());
        break;
        case SDLK_e: 		extrudeCube(m_selector->getPosition(), m_pinceau->getType());
        break;
        
        default: break;
    }

	m_selector->handleEvents(e);
}

void World::replace(const glm::vec3 position, const typeCube typePinceau){
	for(uint i=0; i<m_allCubes.size(); i++){
		m_allCubes[i]->deleteCube(position);
	}
	m_allCubes[typePinceau]->addCube(position);
}

bool World::existsSmth(const glm::vec3 position){
	int exists;
	for(uint i=0; i<m_allCubes.size(); i++){
		exists = m_allCubes[i]->findFromPosition(position);
		//Il existe
		if(exists != -1){
			return true;
			break;
		}
	}
	return false;
}

void World::addCube(const glm::vec3 position, const typeCube typePinceau){
	bool existsCubeHere = existsSmth(position);
	
	if(!existsCubeHere){
		m_allCubes[typePinceau]->addCube(position);
	}	
}

void World::changeNightMode(){
	m_skybox->updateSky();
	for(int i=0; i!=REACHEND; ++i){
	    m_allCubes[i]->changeNightMode();
    }
}

int World::findLastCube(const glm::vec3 position){
	glm::vec3 positionTmp = glm::vec3(position.x, WORLD_DEPTH+1, position.z);
	while(existsSmth(positionTmp)){
		positionTmp.y++;
	}
    return positionTmp.y;
}

/*On a le curseur à un endroit et on veut ajouter un dernier cube en haut de l'endroit où on est
S'il n'y a pas de cube, ça en ajoute un à y=0*/
void World::extrudeCube(glm::vec3 position, const typeCube typePinceau){
    int yMax = findLastCube(position);
    position.y = yMax;
    m_allCubes[typePinceau]->addCube(position);
}

/*On a le curseur à un endroit et on veut enlever le dernier cube en haut de l'endroit où on est*/
void World::digCube(glm::vec3 position, const typeCube typePinceau){
    int yMax = findLastCube(position);
    position.y = yMax-1;
    m_allCubes[typePinceau]->deleteCube(position);
}