#include "../include/skybox.hpp"
#include "../include/vertex.hpp"
#include <vector>
#include "../lib/glimac/include/Image.hpp"

#define GL_TEXTURE_CUBE_MAP_ARB             0x8513
#define GL_TEXTURE_CUBE_MAP_POSITIVE_X_ARB  0x8515
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_X_ARB  0x8516
#define GL_TEXTURE_CUBE_MAP_POSITIVE_Y_ARB  0x8517
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_Y_ARB  0x8518
#define GL_TEXTURE_CUBE_MAP_POSITIVE_Z_ARB  0x8519
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_Z_ARB  0x851A

const std::vector<std::string> textures_faces = 
{
    "assets/textures/skybox/Box_Right.png",
    "assets/textures/skybox/Box_Left.bmp",
    "assets/textures/skybox/Box_Top.png",
    "assets/textures/skybox/Box_Bottom.bmp",
    "assets/textures/skybox/Box_Front.bmp",
    "assets/textures/skybox/Box_Back.bmp"
};

const float skyboxVertices[] = {
        // positions          
        -1.f,  1.f, -1.f,
        -1.f, -1.f, -1.f,
         1.f, -1.f, -1.f,
         1.f, -1.f, -1.f,
         1.f,  1.f, -1.f,
        -1.f,  1.f, -1.f,

        -1.f, -1.f,  1.f,
        -1.f, -1.f, -1.f,
        -1.f,  1.f, -1.f,
        -1.f,  1.f, -1.f,
        -1.f,  1.f,  1.f,
        -1.f, -1.f,  1.f,

         1.f, -1.f, -1.f,
         1.f, -1.f,  1.f,
         1.f,  1.f,  1.f,
         1.f,  1.f,  1.f,
         1.f,  1.f, -1.f,
         1.f, -1.f, -1.f,

        -1.f, -1.f,  1.f,
        -1.f,  1.f,  1.f,
         1.f,  1.f,  1.f,
         1.f,  1.f,  1.f,
         1.f, -1.f,  1.f,
        -1.f, -1.f,  1.f,

        -1.f,  1.f, -1.f,
         1.f,  1.f, -1.f,
         1.f,  1.f,  1.f,
         1.f,  1.f,  1.f,
        -1.f,  1.f,  1.f,
        -1.f,  1.f, -1.f,

        -1.f, -1.f, -1.f,
        -1.f, -1.f,  1.f,
         1.f, -1.f, -1.f,
         1.f, -1.f, -1.f,
        -1.f, -1.f,  1.f,
         1.f, -1.f,  1.f
    };

Skybox::Skybox()
:m_shader(new MyShader("shaders/skybox.vs.glsl", "shaders/skybox.fs.glsl"))
{
    loadTexture();
	const GLuint VERTEX_ATTR_POSITION = 0;

    glGenVertexArrays(1, &m_vao);
    glBindVertexArray(m_vao);
    glGenBuffers(1, &m_vbo);
    glBindBuffer(GL_ARRAY_BUFFER, m_vbo);

    glBufferData(GL_ARRAY_BUFFER, sizeof(skyboxVertices), &skyboxVertices, GL_STATIC_DRAW);

    glEnableVertexAttribArray(VERTEX_ATTR_POSITION);
    glVertexAttribPointer(VERTEX_ATTR_POSITION, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);

    glBindBuffer(GL_ARRAY_BUFFER, 0); // debinder la VBO
    glBindVertexArray(0); //Debinder la VAO

}

Skybox::~Skybox(){
	glDeleteVertexArrays(1, &m_vao);
    glDeleteBuffers(1, &m_vbo);
}

void Skybox::draw(glm::mat4 MVMatrix){

	m_shader->bind();
    m_shader->setUniformMatrix4fv("uMVPMatrix", glm::value_ptr(ProjMatrix*glm::mat4(glm::mat3(MVMatrix))));
    m_shader->setUniformMatrix4fv("uMVMatrix", glm::value_ptr(glm::mat4(glm::mat3(MVMatrix))));

    glBindVertexArray(m_vao);

    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_CUBE_MAP, m_textureID[0]);

    m_shader->setUniform1i("uSkybox", 0);

    glDepthFunc(GL_LEQUAL);
    glDrawArrays(GL_TRIANGLES, 0, 36);
    glDepthFunc(GL_LESS);

    glBindVertexArray(0); //Debinder la VAO
    m_shader->unbind();
}

void Skybox::loadTexture(){

    glActiveTexture(GL_TEXTURE0);

    glGenTextures(1, m_textureID);
    //Texture jour
    glBindTexture(GL_TEXTURE_CUBE_MAP, m_textureID[0]);
   
    for(unsigned int i = 0; i < textures_faces.size(); i++){
        glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE); 

        std::unique_ptr<glimac::Image> textureImg = glimac::loadImage(textures_faces[i]);

        if(textureImg == NULL)
            std::cout << "Image located in "<< textures_faces[i] << " not loaded !" <<std::endl;
        
        glTexImage2D(m_skyboxTarget[i],
            0,
            GL_RGB,
            textureImg->getWidth(),
            textureImg->getHeight(),
            0,
            GL_RGB,
            GL_UNSIGNED_BYTE,
            textureImg->getPixels()
            );
    }
    glBindTexture(GL_TEXTURE_2D, 0);
}