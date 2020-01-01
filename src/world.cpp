#include "../include/world.hpp"

World::World()
{
    for(int i=0; i!=REACHEND; ++i){
	    m_allCubes.push_back(new Cube((typeCube)i));
    }
}

World::~World(){

}

void World::draw(glm::mat4 MVMatrix){
	glEnable(GL_BLEND); //Pour la transparence
	//A l'index 0 c'est la lumiere, on dessine que le reste
	for(uint i=1; i<m_allCubes.size(); i++){
		m_allCubes[i]->draw(MVMatrix, *m_allCubes[0]);
	}
    glDisable(GL_BLEND);
}
void World::handleEvents(const SDLKey e, const glm::vec3 position, const typeCube typePinceau){
	if(e == SDLK_DELETE){
        for(uint i=0; i<m_allCubes.size(); i++){
        	m_allCubes[i]->deleteCube(position);
        }
	}else if(e == SDLK_RETURN){
		addCube(position, typePinceau);
    }else if(e == SDLK_n){
        changeNightMode();
    }

	for(uint i=0; i<m_allCubes.size(); i++){
		m_allCubes[i]->handleEvents(e, position, typePinceau);
	}
}

void World::addCube(const glm::vec3 position, const typeCube typePinceau){
	bool nothingHere = true;
	int exists;
	for(uint i=0; i<m_allCubes.size(); i++){
		exists = m_allCubes[i]->findFromPosition(position);
		//Il existe
		if(exists != -1){
			nothingHere = false;
			break;
		}
	}

	if(nothingHere){
		m_allCubes[typePinceau]->addCube(position);
	}	
}

void World::changeNightMode(){
	for(int i=0; i!=REACHEND; ++i){
	    m_allCubes[i]->changeNightMode();
    }
}

