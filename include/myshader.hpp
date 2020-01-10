#pragma once

/*!
 * \file myshader.hpp
 * \brief Create a shader
 * Use personal shader structue and glimac library for manage vertex and fragment shaders
 */


#include <string>
#include <GL/glew.h>
#include <iostream>
#include <sstream>
#include <fstream>
#include "../lib/glimac/include/glm.hpp"
/**
 * @brief 
 * 
 */
struct ShaderProgramSources{
	std::string VertexSource;
	std::string FragmentSource;
};

class MyShader{
private:
	unsigned int m_shaderID;
public:

/**
 * @brief Construct a new My Shader object
 * 
 * @param vertexShaderPath 
 * @param fragmentShaderPath 
 */
	MyShader(const std::string& vertexShaderPath, const std::string& fragmentShaderPath);
	
/**
 * @brief Destroy the My Shader object
 * 
 */
	~MyShader();


/**
 * @brief 
 * 
 */
	void bind() const;

/**
 * @brief 
 * 
 */
	void unbind() const;

//////Set uniforms//////

/**
 * @brief Set the Uniform3f object
 * 
 * @param name 
 * @param value 
 */
	void setUniform3f(const std::string& name, const glm::vec3 value);

/**
 * @brief Set the Uniform Vec3 object
 * 
 * @param name 
 * @param value 
 */
	void setUniformVec3(const std::string& name, const glm::vec3 value[6]);

/**
 * @brief Set the Uniform1i object
 * 
 * @param name 
 * @param value 
 */
	void setUniform1i(const std::string& name, const int value);

/**
 * @brief Set the Uniform1f object
 * 
 * @param name 
 * @param value 
 */
	void setUniform1f(const std::string& name, const float value);

/**
 * @brief Set the Uniform Matrix4fv object
 * 
 * @param name 
 * @param value 
 */
	void setUniformMatrix4fv(const std::string& name, const GLfloat*value);

/**
 * @brief Set the Uniform Matrix4x3fv object
 * 
 * @param name 
 * @param value 
 */
	void setUniformMatrix4x3fv(const std::string& name, const GLfloat*value);
		
private:

/**
 * @brief Get the Uniform Location object
 * 
 * @param name 
 * @return GLint 
 */
	GLint getUniformLocation(const std::string& name);

/**
 * @brief 
 * 
 * @param filepath 
 * @param filepath2 
 * @return ShaderProgramSources 
 */
	ShaderProgramSources ParseShaders(const std::string& filepath, const std::string& filepath2);
	
/**
 * @brief 
 * 
 * @param type 
 * @param source 
 * @return unsigned int 
 */
	unsigned int CompileShaders(const unsigned int type, const std::string& source);
	
/**
 * @brief Create a Shaders object
 * 
 * @param vertexShader 
 * @param fragmentShader 
 * @return int 
 */
	int CreateShaders(const std::string& vertexShader, const std::string& fragmentShader);
};