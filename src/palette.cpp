#include "../include/palette.hpp"

Palette::Palette()
:m_shader(new MyShader("shaders/texture2D.vs.glsl", "shaders/texture2D.fs.glsl")),
m_texture(new Texture("assets/textures/palette/palette_1.png"))
{
	const GLuint VERTEX_ATTR_POSITION = 0;
    const GLuint VERTEX_ATTR_TEXCOORD = 1;

    glGenBuffers(1, &m_vbo);
    glBindBuffer(GL_ARRAY_BUFFER, m_vbo); //Binder la VBO

    glBufferData(GL_ARRAY_BUFFER, 4 * sizeof(VertexTex), vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ARRAY_BUFFER, 0); // debinder la VBO

    glGenBuffers(1, &m_ibo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ibo);
    //On a 36 points
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, 36*sizeof(uint32_t), indices, GL_STATIC_DRAW);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

    glGenVertexArrays(1, &m_vao);
    glBindVertexArray(m_vao); //Binder la VAO

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ibo);

    glEnableVertexAttribArray(VERTEX_ATTR_POSITION);
    glEnableVertexAttribArray(VERTEX_ATTR_TEXCOORD);

    glBindBuffer(GL_ARRAY_BUFFER, m_vbo); //Binder la VBO
    glVertexAttribPointer(VERTEX_ATTR_POSITION, 3, GL_FLOAT, GL_FALSE, sizeof(VertexTex), (const GLvoid*) offsetof(VertexTex, position));
    glVertexAttribPointer(VERTEX_ATTR_TEXCOORD, 2, GL_FLOAT, GL_FALSE, sizeof(VertexTex), (const GLvoid*) offsetof(VertexTex, texCoords));
    glBindBuffer(GL_ARRAY_BUFFER, 0); // debinder la VBO

    glBindVertexArray(0); //Debinder la VAO
}

Palette::~Palette(){
    delete m_texture;
    delete m_shader;
    glDeleteBuffers(1, &m_ibo);
    glDeleteBuffers(1, &m_vbo);
    glDeleteVertexArrays(1, &m_vao);
}

void Palette::draw(){
	glEnable(GL_BLEND); //Pour la transparence
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); //Pour la transparence
    
    m_shader->bind();
    m_shader->setUniform1i("u_Texture", 0);

    m_texture->bind();
    glBindVertexArray(m_vao); //Binder la VAO
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ibo);

    glDrawElementsInstanced(GL_TRIANGLES, 6, GL_UNSIGNED_INT, (void*) 0, 1);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    glBindVertexArray(0); //Debinder la VAO
    m_texture->unbind();
    m_shader->unbind();
    glDisable(GL_BLEND);
}

void Palette::update(const typeCube type){
	switch(type){
		case LIGHT  : m_texture = new Texture("assets/textures/palette/palette_9.png");
		break;
		case GROUND : m_texture = new Texture("assets/textures/palette/palette_1.png");
		break;
	    case SAND   : m_texture = new Texture("assets/textures/palette/palette_2.png");
	    break;
	    case WATER  : m_texture = new Texture("assets/textures/palette/palette_3.png");
	    break;
	    case GRASS  : m_texture = new Texture("assets/textures/palette/palette_4.png");
	    break;
	    case LEAF   : m_texture = new Texture("assets/textures/palette/palette_5.png");
	    break;
	    case BARBARA: m_texture = new Texture("assets/textures/palette/palette_6.png");
	    break;
	    default: break;
	}
}