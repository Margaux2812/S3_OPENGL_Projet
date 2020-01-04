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
	for(uint i=1; i<m_allCubes.size(); i++){
		delete m_allCubes[i];
	}
	delete m_skybox;
}

void World::draw(glm::mat4 MVMatrix){
	m_skybox->draw(MVMatrix);

	glEnable(GL_BLEND); //Pour la transparence
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); //Pour la transparence
    
	//A l'index 0 c'est la lumiere, on dessine que le reste
	for(uint i=1; i<m_allCubes.size(); i++){
		m_allCubes[i]->draw(MVMatrix, *m_allCubes[0]);
	}
    glDisable(GL_BLEND);

    m_selector->draw(MVMatrix);
    m_pinceau->draw();
}
void World::handleEvents(const SDLKey e, const bool ctrlIsPressed){
	m_pinceau->handleEvents(e);
	if(e == SDLK_DELETE){
        for(uint i=0; i<m_allCubes.size(); i++){
        	m_allCubes[i]->deleteCube(m_selector->getPosition());
        }
	}else if(e == SDLK_RETURN){
		if(ctrlIsPressed){
			replace(m_selector->getPosition(), m_pinceau->getType());
		}else{
			addCube(m_selector->getPosition(), m_pinceau->getType());
		}
    }else if(e == SDLK_n){
        changeNightMode();
    }

	for(uint i=0; i<m_allCubes.size(); i++){
		m_allCubes[i]->handleEvents(e, m_selector->getPosition(), m_pinceau->getType());
	}

	m_selector->handleEvents(e);
}

void World::replace(const glm::vec3 position, const typeCube typePinceau){
	for(uint i=0; i<m_allCubes.size(); i++){
		m_allCubes[i]->deleteCube(position);
	}
	m_allCubes[typePinceau]->addCube(position);
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
	m_skybox->updateSky();
	for(int i=0; i!=REACHEND; ++i){
	    m_allCubes[i]->changeNightMode();
    }
}