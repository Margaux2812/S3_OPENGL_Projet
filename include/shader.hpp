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

class Shader{
private:

public:
	ShaderProgramSources ParseShader(const std::string& filepath, const std::string& filepath2);
	unsigned int CompileShader(unsigned int type, const std::string& source);
	int CreateShader(const std::string& vertexShader, const std::string& fragmentShader);
};