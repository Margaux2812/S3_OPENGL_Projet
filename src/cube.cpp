#include "headers/cube.hpp"
#include <glm/gtc/matrix_transform.hpp>
#include "headers/gl_exception.hpp"

namespace cubeData {
    //    v6----- v5
    //   /|      /|
    //  v1------v0|
    //  | |     | |
    //  | |v7---|-|v4
    //  |/      |/
    //  v2------v3
    const glm::vec3 positions[] = {
        // Front v0,v1,v2,v3
        glm::vec3(1, 1, 1), glm::vec3(-1, 1, 1), glm::vec3(-1, -1, 1), glm::vec3(1, -1, 1),
        // Right v0,v3,v4        },v5
        glm::vec3(1, 1, 1), glm::vec3(1, -1, 1), glm::vec3(1, -1, -1), glm::vec3(1, 1, -1),
        // Top v0,v5,v6,v1	
        glm::vec3(1, 1, 1), glm::vec3(1, 1, -1), glm::vec3(-1, 1, -1), glm::vec3(-1, 1, 1), 
        // Left v1,v6,v7,v2	
        glm::vec3(-1, 1, 1), glm::vec3(-1, 1, -1), glm::vec3(-1, -1, -1), glm::vec3(-1, -1, 1),  
        // Bottom v7,v4,v3,v2
        glm::vec3(-1, -1, -1), glm::vec3(1, -1, -1), glm::vec3(1, -1, 1), glm::vec3(-1, -1, 1), 
        // Back v4,v7,v6,v5	
        glm::vec3(1, -1, -1), glm::vec3(-1, -1, -1), glm::vec3(-1, 1, -1), glm::vec3(1, 1, -1)
    };

    const glm::vec3 normals[] = {
        glm::vec3(0, 0, 1), glm::vec3(0, 0, 1), glm::vec3(0, 0, 1), glm::vec3(0, 0, 1),
        glm::vec3(1, 0, 0), glm::vec3(1, 0, 0), glm::vec3(1, 0, 0), glm::vec3(1, 0, 0),
        glm::vec3(0, 1, 0), glm::vec3(0, 1, 0), glm::vec3(0, 1, 0), glm::vec3(0, 1, 0),
        glm::vec3(-1, 0, 0), glm::vec3(-1, 0, 0), glm::vec3(-1, 0, 0), glm::vec3(-1, 0, 0),
        glm::vec3(0,-1, 0), glm::vec3(0,-1, 0), glm::vec3(0,-1, 0), glm::vec3(0,-1, 0),
        glm::vec3(0, 0,-1), glm::vec3(0, 0,-1), glm::vec3(0, 0,-1), glm::vec3(0, 0,-1)
    };

    const unsigned short indices[] = {
        0, 1, 2,   2, 3, 0,       // front
        4, 5, 6,   6, 7, 4,       // right
        8, 9, 10,  10,11,8,       // top
        12,13,14,  14,15,12,      // left
        16,17,18,  18,19,16,      // bottom
        20,21,22,  22,23,20		  // back
    };
}

Cube::Cube() : Object(){
    // ------------------ Vertex Buffer
    unsigned int posVB;
    {
        glGenBuffers(1, &posVB);
        glBindBuffer(GL_ARRAY_BUFFER, posVB);
        glBufferData(GL_ARRAY_BUFFER, sizeof(cubeData::positions), cubeData::positions, GL_STATIC_DRAW);
        glBindBuffer(GL_ARRAY_BUFFER, 0);
    }
    
    // ------------------ Vertex Array
    {
        glGenVertexArrays(1, &m_vao);
        glBindVertexArray(m_vao);

        // Vertex input description
        {
            glEnableVertexAttribArray(0);
            glBindBuffer(GL_ARRAY_BUFFER, posVB);
            glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), NULL);
        }
        
        glBindVertexArray(0);
    }

    // ------------------ Index buffer
    {
        glGenBuffers(1, &m_ib);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ib);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(cubeData::indices), cubeData::indices, GL_STATIC_DRAW);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    }

    // ------------------ Default values for uniforms
    m_shader.bind();
    {
        glm::mat4 modelMat = glm::mat4(1.0f);
        m_shader.setUniformMat4f("uModel", modelMat);
    }
    {
        glm::mat4 viewMat = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, -10.0f));
        glm::mat4 projMat = glm::perspective(glm::radians(45.0f), 1.0f, 0.1f, 100.0f);
        glm::mat4 viewProjMat = projMat * viewMat;
        m_shader.setUniformMat4f("uViewProj", viewProjMat);
    }
    m_shader.unbind();
}

Cube::Cube(glm::vec3 position) : Object(position){
       // ------------------ Vertex Buffer
    unsigned int posVB;
    {
        glGenBuffers(1, &posVB);
        glBindBuffer(GL_ARRAY_BUFFER, posVB);
        glBufferData(GL_ARRAY_BUFFER, sizeof(cubeData::positions), cubeData::positions, GL_STATIC_DRAW);
        glBindBuffer(GL_ARRAY_BUFFER, 0);
    }
    
    // ------------------ Vertex Array
    {
        glGenVertexArrays(1, &m_vao);
        glBindVertexArray(m_vao);

        // Vertex input description
        {
            glEnableVertexAttribArray(0);
            glBindBuffer(GL_ARRAY_BUFFER, posVB);
            glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), NULL);
        }
        
        glBindVertexArray(0);
    }

    // ------------------ Index buffer
    {
        glGenBuffers(1, &m_ib);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ib);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(cubeData::indices), cubeData::indices, GL_STATIC_DRAW);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    }

    // ------------------ Default values for uniforms
    m_shader.bind();
    {
        glm::mat4 modelMat = glm::mat4(1.0f);
        m_shader.setUniformMat4f("uModel", modelMat);
    }
    {
        glm::mat4 viewMat = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, -10.0f));
        glm::mat4 projMat = glm::perspective(glm::radians(45.0f), 1.0f, 0.1f, 100.0f);
        glm::mat4 viewProjMat = projMat * viewMat;
        m_shader.setUniformMat4f("uViewProj", viewProjMat);
    }
    m_shader.unbind();
} 


Cube::~Cube()
{}


void Cube::print(){
   int print = 1;
}

void Cube::draw() {
    // Bind
    glBindVertexArray(m_vao);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ib);
    m_shader.bind();

    // Update model mat uniform
    glm::mat4 modelMat = glm::translate(glm::mat4(1.0f), m_position);
    m_shader.setUniformMat4f("uModel", modelMat);

    // Draw call
    glDrawElements(GL_TRIANGLES, (cubeData::indices).size(), GL_UNSIGNED_SHORT, (void*) 0);
}


    void Cube::addCube(){

    }

    void Cube::extrudeCube(){
    }

    void Cube::digCube(){

    }
    void Cube::deleteCube(){

    }
