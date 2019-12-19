#include "selector.hpp"

void draw(){
		//Il faudra bind le shader ici

	glBindVertexArray(m_vao); //Binder la VAO
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ibo);

    //Dernier truc est nb de cubes
    glDrawElementsInstanced(GL_TRIANGLES, 36, GL_UNSIGNED_INT, (void*) 0, m_positionsCubes.size());

    glBindVertexArray(0); //Debinder la VAO
}
