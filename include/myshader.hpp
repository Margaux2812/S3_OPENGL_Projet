#pragma once

#include <string>
#include <GL/glew.h>
#include <iostream>
#include <sstream>
#include <fstream>

struct ShaderProgramSources{
	std::string VertexSource;
	std::string FragmentSource;
};

class MyShader{
private:
	unsigned int m_shaderID;
public:
	MyShader(const std::string& vertexShaderPath, const std::string& fragmentShaderPath);
	~MyShader();

	void bind() const;
	void unbind() const;

	//Set uniforms
	void setUniformMatrix4fv(const std::string& name, const GLfloat*value);
	
private:
	GLint getUniformLocation(const std::string& name);
	ShaderProgramSources ParseShaders(const std::string& filepath, const std::string& filepath2);
	unsigned int CompileShaders(unsigned int type, const std::string& source);
	int CreateShaders(const std::string& vertexShader, const std::string& fragmentShader);
};