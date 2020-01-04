#include "../include/skybox.hpp"
#include "../include/vertex.hpp"
#include <vector>
#include "../lib/glimac/include/Image.hpp"

const std::vector<std::string> faces = 
{
    "assets/textures/skybox/Box_Right.png",
    "assets/textures/skybox/Box_Left.bmp",
    "assets/textures/skybox/Box_Top.png",
    "assets/textures/skybox/Box_Bottom.bmp",
    "assets/textures/skybox/Box_Front.bmp",
    "assets/textures/skybox/Box_Back.bmp"
};

const Vertex3DColor skyboxVertices[] = {
        // positions          
        Vertex3DColor( glm::vec3(-1.f,  1.f, -1.f), glm::vec3(0.22f, 0.427f, 0.616f)),
        Vertex3DColor( glm::vec3(-1.f, -1.f, -1.f), glm::vec3(0.55f, 0.7f, 0.886f)),
        Vertex3DColor( glm::vec3( 1.f, -1.f, -1.f), glm::vec3(0.55f, 0.7f, 0.886f)),
        Vertex3DColor( glm::vec3(1.f, -1.f, -1.f), glm::vec3(0.55f, 0.7f, 0.886f)),
        Vertex3DColor( glm::vec3( 1.f,  1.f, -1.f), glm::vec3(0.22f, 0.427f, 0.616f)),
        Vertex3DColor( glm::vec3(-1.f,  1.f, -1.f), glm::vec3(0.22f, 0.427f, 0.616f)),

        Vertex3DColor(glm::vec3(-1.f, -1.f,  1.f), glm::vec3(0.55f, 0.7f, 0.886f)),
        Vertex3DColor(glm::vec3(-1.f, -1.f, -1.f), glm::vec3(0.55f, 0.7f, 0.886f)),
        Vertex3DColor(glm::vec3(-1.f,  1.f, -1.f), glm::vec3(0.22f, 0.427f, 0.616f)),
        Vertex3DColor(glm::vec3(-1.f,  1.f, -1.f),  glm::vec3(0.22f, 0.427f, 0.616f)),
        Vertex3DColor(glm::vec3(-1.f,  1.f,  1.f), glm::vec3(0.22f, 0.427f, 0.616f)),
        Vertex3DColor(glm::vec3(-1.f, -1.f,  1.f), glm::vec3(0.55f, 0.7f, 0.886f)),

        Vertex3DColor(glm::vec3(1.f, -1.f, -1.f), glm::vec3(0.55f, 0.7f, 0.886f)),
        Vertex3DColor(glm::vec3(1.f, -1.f,  1.f), glm::vec3(0.55f, 0.7f, 0.886f)),
        Vertex3DColor(glm::vec3(1.f,  1.f,  1.f), glm::vec3(0.22f, 0.427f, 0.616f)),
        Vertex3DColor(glm::vec3(1.f,  1.f,  1.f), glm::vec3(0.22f, 0.427f, 0.616f)),
        Vertex3DColor(glm::vec3(1.f,  1.f, -1.f),  glm::vec3(0.22f, 0.427f, 0.616f)),
        Vertex3DColor(glm::vec3(1.f, -1.f, -1.f), glm::vec3(0.55f, 0.7f, 0.886f)),

        Vertex3DColor(glm::vec3(-1.f, -1.f,  1.f), glm::vec3(0.55f, 0.7f, 0.886f)),
        Vertex3DColor(glm::vec3(-1.f,  1.f,  1.f), glm::vec3(0.22f, 0.427f, 0.616f)),
        Vertex3DColor(glm::vec3(1.f,  1.f,  1.f), glm::vec3(0.22f, 0.427f, 0.616f)),
        Vertex3DColor(glm::vec3(1.f,  1.f,  1.f), glm::vec3(0.22f, 0.427f, 0.616f)),
        Vertex3DColor(glm::vec3(1.f, -1.f,  1.f), glm::vec3(0.55f, 0.7f, 0.886f)),
        Vertex3DColor(glm::vec3(-1.f, -1.f,  1.f), glm::vec3(0.55f, 0.7f, 0.886f)),

        Vertex3DColor(glm::vec3(-1.f,  1.f, -1.f), glm::vec3(0.22f, 0.427f, 0.616f)), 
        Vertex3DColor(glm::vec3(1.f,  1.f, -1.f), glm::vec3(0.22f, 0.427f, 0.616f)), 
        Vertex3DColor(glm::vec3(1.f,  1.f,  1.f), glm::vec3(0.22f, 0.427f, 0.616f)),
        Vertex3DColor(glm::vec3(1.f,  1.f,  1.f), glm::vec3(0.22f, 0.427f, 0.616f)),
        Vertex3DColor(glm::vec3(-1.f,  1.f,  1.f), glm::vec3(0.22f, 0.427f, 0.616f)),
        Vertex3DColor(glm::vec3(-1.f,  1.f, -1.f), glm::vec3(0.22f, 0.427f, 0.616f)), 

        Vertex3DColor(glm::vec3(-1.f, -1.f, -1.f), glm::vec3(0.55f, 0.7f, 0.886f)),
        Vertex3DColor(glm::vec3(-1.f, -1.f,  1.f), glm::vec3(0.55f, 0.7f, 0.886f)),
        Vertex3DColor(glm::vec3(1.f, -1.f, -1.f), glm::vec3(0.55f, 0.7f, 0.886f)),
        Vertex3DColor(glm::vec3(1.f, -1.f, -1.f), glm::vec3(0.55f, 0.7f, 0.886f)),
        Vertex3DColor(glm::vec3(-1.f, -1.f,  1.f), glm::vec3(0.55f, 0.7f, 0.886f)),
        Vertex3DColor(glm::vec3(1.f, -1.f,  1.f), glm::vec3(0.55f, 0.7f, 0.886f))
    };
    /*0.55f, 0.7f, 0.886f*/

Skybox::Skybox()
:m_textureID(0),
m_shader(new MyShader("shaders/skybox.vs.glsl", "shaders/skybox.fs.glsl"))
{
    loadTexture();
	const GLuint VERTEX_ATTR_POSITION = 0;
    const GLuint VERTEX_ATTR_COLOR = 1;

    glGenVertexArrays(1, &m_vao);
    glBindVertexArray(m_vao);
    glGenBuffers(1, &m_vbo);
    glBindBuffer(GL_ARRAY_BUFFER, m_vbo);

    glBufferData(GL_ARRAY_BUFFER, sizeof(skyboxVertices), &skyboxVertices, GL_STATIC_DRAW);

    glEnableVertexAttribArray(VERTEX_ATTR_POSITION);
    glEnableVertexAttribArray(VERTEX_ATTR_COLOR);
    glVertexAttribPointer(VERTEX_ATTR_POSITION, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex3DColor), (const GLvoid*) offsetof(Vertex3DColor, position));
    glVertexAttribPointer(VERTEX_ATTR_COLOR, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex3DColor), (const GLvoid*) offsetof(Vertex3DColor, color));
    glBindBuffer(GL_ARRAY_BUFFER, 0); // debinder la VBO
    glBindVertexArray(0); //Debinder la VAO

    m_shader->setUniform1i("uSkybox", 0);

}

Skybox::~Skybox(){
	glDeleteVertexArrays(1, &m_vao);
    glDeleteBuffers(1, &m_vbo);
}

void Skybox::draw(glm::mat4 MVMatrix){
    MVMatrix = glm::mat4(glm::mat3(MVMatrix));
    glDepthFunc( GL_LEQUAL ); 
	m_shader->bind();
    m_shader->setUniformMatrix4fv("uMVPMatrix", glm::value_ptr(ProjMatrix*MVMatrix));
    m_shader->setUniformMatrix4fv("uMVMatrix", glm::value_ptr(MVMatrix));

    //glActiveTexture(GL_TEXTURE0);
    //glBindTexture(GL_TEXTURE_CUBE_MAP, m_textureID);

    glBindVertexArray(m_vao);
    glDrawArrays(GL_TRIANGLES, 0, 36);
    glDepthFunc( GL_LESS );

    glBindVertexArray(0); //Debinder la VAO
    m_shader->unbind();
}

void Skybox::loadTexture(){
    glActiveTexture(GL_TEXTURE0);
    glGenTextures(1, &m_textureID);
    glBindTexture(GL_TEXTURE_CUBE_MAP, m_textureID);
   
    for (GLuint i = 0; i < faces.size(); i++){
        std::unique_ptr<glimac::Image> textureImg = glimac::loadImage(faces[i]);

        if(textureImg == NULL){
            std::cout << "Image located in "<< faces[i] << " not loaded !" <<std::endl;
        }

        glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + i,
            0, 
            GL_RGB,
            textureImg->getWidth(),
            textureImg->getHeight(),
            0,
            GL_RGBA,
            GL_UNSIGNED_BYTE,
            textureImg->getPixels());

        glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE); 
        glBindTexture(GL_TEXTURE_CUBE_MAP, 0);
    }
}