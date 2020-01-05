#pragma once

#include "cube.hpp"
#include "myshader.hpp"

enum Fleche {haut, bas, gauche, droite, avant, arriere};

class Selector{
	private:
		GLuint m_vao;
		GLuint m_vbo;
		GLuint m_ibo;
		GLuint vboAll;

		std::vector<glm::vec3> m_positionCube;
		MyShader* m_shader;
	public :
		Selector();
		~Selector();

		glm::vec3 getPosition();

		void draw(glm::mat4 MVMatrix, glm::vec3 color);

		void handleEvents(SDLKey e);
		void updateGPU();
		void updatePos(glm::vec3 position);
		void move(Fleche direction);

};