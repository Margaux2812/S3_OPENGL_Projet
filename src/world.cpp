#include "../include/world.hpp"

World::World(){
    for(int i=0; i!=LEAF; ++i){
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
void World::handleEvents(const SDLKey e, const glm::vec3 position, typeCube typePinceau){
	for(uint i=0; i<m_allCubes.size(); i++){
		m_allCubes[i]->handleEvents(e, position, typePinceau);
	}
}

bool World::addCube(const glm::vec3 position){

}

