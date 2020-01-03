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
        Vertex3DColor( glm::vec3(-1.f,  1.f, -1.f), glm::vec3(0.53f, 0.8f, 0.92f)),
        Vertex3DColor( glm::vec3(-1.f, -1.f, -1.f), glm::vec3(0.53f, 0.8f, 0.92f)),
        Vertex3DColor( glm::vec3( 1.f, -1.f, -1.f), glm::vec3(0.53f, 0.8f, 0.92f)),
        Vertex3DColor( glm::vec3(1.f, -1.f, -1.f), glm::vec3(0.53f, 0.8f, 0.92f)),
        Vertex3DColor( glm::vec3( 1.f,  1.f, -1.f), glm::vec3(0.53f, 0.8f, 0.92f)),
        Vertex3DColor( glm::vec3(-1.f,  1.f, -1.f), glm::vec3(0.53f, 0.8f, 0.92f)),

        Vertex3DColor(glm::vec3(-1.f, -1.f,  1.f), glm::vec3(0.53f, 0.8f, 0.92f)),
        Vertex3DColor(glm::vec3(-1.f, -1.f, -1.f), glm::vec3(0.53f, 0.8f, 0.92f)),
        Vertex3DColor(glm::vec3(-1.f,  1.f, -1.f), glm::vec3(0.53f, 0.8f, 0.92f)),
        Vertex3DColor(glm::vec3(-1.f,  1.f, -1.f),  glm::vec3(0.53f, 0.8f, 0.92f)),
        Vertex3DColor(glm::vec3(-1.f,  1.f,  1.f), glm::vec3(0.53f, 0.8f, 0.92f)),
        Vertex3DColor(glm::vec3(-1.f, -1.f,  1.f), glm::vec3(0.53f, 0.8f, 0.92f)),

        Vertex3DColor(glm::vec3(1.f, -1.f, -1.f), glm::vec3(0.53f, 0.8f, 0.92f)),
        Vertex3DColor(glm::vec3(1.f, -1.f,  1.f), glm::vec3(0.53f, 0.8f, 0.92f)),
        Vertex3DColor(glm::vec3(1.f,  1.f,  1.f), glm::vec3(0.53f, 0.8f, 0.92f)),
        Vertex3DColor(glm::vec3(1.f,  1.f,  1.f), glm::vec3(0.53f, 0.8f, 0.92f)),
        Vertex3DColor(glm::vec3(1.f,  1.f, -1.f),  glm::vec3(0.53f, 0.8f, 0.92f)),
        Vertex3DColor(glm::vec3(1.f, -1.f, -1.f), glm::vec3(0.53f, 0.8f, 0.92f)),

        Vertex3DColor(glm::vec3(-1.f, -1.f,  1.f), glm::vec3(0.53f, 0.8f, 0.92f)),
        Vertex3DColor(glm::vec3(-1.f,  1.f,  1.f), glm::vec3(0.53f, 0.8f, 0.92f)),
        Vertex3DColor(glm::vec3(1.f,  1.f,  1.f), glm::vec3(0.53f, 0.8f, 0.92f)),
        Vertex3DColor(glm::vec3(1.f,  1.f,  1.f), glm::vec3(0.53f, 0.8f, 0.92f)),
        Vertex3DColor(glm::vec3(1.f, -1.f,  1.f), glm::vec3(0.53f, 0.8f, 0.92f)),
        Vertex3DColor(glm::vec3(-1.f, -1.f,  1.f), glm::vec3(0.53f, 0.8f, 0.92f)),

        Vertex3DColor(glm::vec3(-1.f,  1.f, -1.f), glm::vec3(0.53f, 0.8f, 0.92f)), 
        Vertex3DColor(glm::vec3(1.f,  1.f, -1.f), glm::vec3(0.53f, 0.8f, 0.92f)), 
        Vertex3DColor(glm::vec3(1.f,  1.f,  1.f), glm::vec3(0.53f, 0.8f, 0.92f)),
        Vertex3DColor(glm::vec3(1.f,  1.f,  1.f), glm::vec3(0.53f, 0.8f, 0.92f)),
        Vertex3DColor(glm::vec3(-1.f,  1.f,  1.f), glm::vec3(0.53f, 0.8f, 0.92f)),
        Vertex3DColor(glm::vec3(-1.f,  1.f, -1.f), glm::vec3(0.53f, 0.8f, 0.92f)), 

        Vertex3DColor(glm::vec3(-1.f, -1.f, -1.f), glm::vec3(0.53f, 0.8f, 0.92f)),
        Vertex3DColor(glm::vec3(-1.f, -1.f,  1.f), glm::vec3(0.53f, 0.8f, 0.92f)),
        Vertex3DColor(glm::vec3(1.f, -1.f, -1.f), glm::vec3(0.53f, 0.8f, 0.92f)),
        Vertex3DColor(glm::vec3(1.f, -1.f, -1.f), glm::vec3(0.53f, 0.8f, 0.92f)),
        Vertex3DColor(glm::vec3(-1.f, -1.f,  1.f), glm::vec3(0.53f, 0.8f, 0.92f)),
        Vertex3DColor(glm::vec3(1.f, -1.f,  1.f), glm::vec3(0.53f, 0.8f, 0.92f))
    };

Skybox::Skybox()
:m_textureID(1),
m_shader(new MyShader("shaders/skybox.vs.glsl", "shaders/skybox.fs.glsl"))
{   std::cout << "Texture ID before : " << m_textureID << std::endl;
    loadTexture();
    std::cout << "Texture ID after : " << m_textureID << std::endl;
	const GLuint VERTEX_ATTR_POSITION = 0;

    glGenVertexArrays(1, &m_vao);
    glBindVertexArray(m_vao);
    glGenBuffers(1, &m_vbo);
    glBindBuffer(GL_ARRAY_BUFFER, m_vbo);

    glBufferData(GL_ARRAY_BUFFER, sizeof(skyboxVertices), &skyboxVertices, GL_STATIC_DRAW);

    glEnableVertexAttribArray(VERTEX_ATTR_POSITION);
    glVertexAttribPointer(VERTEX_ATTR_POSITION, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex3DColor), (const GLvoid*) offsetof(Vertex3D, position));
    glBindBuffer(GL_ARRAY_BUFFER, 0); // debinder la VBO
    glBindVertexArray(0); //Debinder la VAO

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
    m_shader->setUniform1i("uSkybox", 0);

    glBindVertexArray(m_vao);
    glBindTexture(GL_TEXTURE_CUBE_MAP, m_textureID);
    glDrawArrays(GL_TRIANGLES, 0, 36);
    glDepthFunc( GL_LESS );

    glBindVertexArray(0); //Debinder la VAO
    m_shader->unbind();
}

void Skybox::loadTexture(){
    glActiveTexture(GL_TEXTURE0);

    glGenTextures(1, &m_textureID);
    glBindTexture(GL_TEXTURE_CUBE_MAP, m_textureID);
   
    loadTextureFace(GL_TEXTURE_CUBE_MAP_NEGATIVE_Z, "assets/textures/skybox/Box_Front.bmp");
    loadTextureFace(GL_TEXTURE_CUBE_MAP_POSITIVE_Z, "assets/textures/skybox/Box_Back.bmp");
    loadTextureFace(GL_TEXTURE_CUBE_MAP_POSITIVE_Y, "assets/textures/skybox/Box_Top.png");
    loadTextureFace(GL_TEXTURE_CUBE_MAP_NEGATIVE_Y, "assets/textures/skybox/Box_Bottom.bmp");
    loadTextureFace(GL_TEXTURE_CUBE_MAP_NEGATIVE_X, "assets/textures/skybox/Box_Left.bmp");
    loadTextureFace(GL_TEXTURE_CUBE_MAP_POSITIVE_X, "assets/textures/skybox/Box_Right.png");
  
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE); 
}

void Skybox::loadTextureFace(const GLenum side_target, const std::string path){
    std::unique_ptr<glimac::Image> textureImg = glimac::loadImage(path);

    if(textureImg == NULL)
        std::cout << "Image located in "<< path << " not loaded !" <<std::endl;

    glTexImage2D(side_target,
        0,
        GL_RGB,
        textureImg->getWidth(),
        textureImg->getHeight(),
        0,
        GL_RGB,
        GL_FLOAT,
        textureImg->getPixels()
        );
}