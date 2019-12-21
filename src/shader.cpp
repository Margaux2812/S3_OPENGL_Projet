#include "../include/shader.hpp"

ShaderProgramSources Shader::ParseShader(const std::string& vertexShaderFilepath, const std::string& fragmentShaderFilepath){
	std::ifstream vertexStream(vertexShaderFilepath);
	std::ifstream fragmentStream(fragmentShaderFilepath);

	std::string line;
	std::stringstream ss[2];

	while(getline(vertexStream, line)){
		ss[0] << line << '\n';
	}

	while(getline(fragmentStream, line)){
		ss[1] << line << '\n';
	}

	return { ss[0].str(), ss[1].str()};
}

unsigned int Shader::CompileShader(unsigned int type, const std::string& source){

	unsigned int shaderId= glCreateShader(GL_VERTEX_SHADER);
	const char* src = source.c_str();
	glShaderSource(shaderId, 1, &src, nullptr);
	glCompileShader(shaderId);

	int isCompiled;
	glGetShaderiv(shaderId, GL_COMPILE_STATUS, &isCompiled);
	if(!isCompiled){
		int length;
		glGetShaderiv(shaderId, GL_INFO_LOG_LENGTH, &length);
		char* message = (char*)alloca(length * sizeof(char));
		glGetShaderInfoLog(shaderId, length, &length, message);
		std::cout << "Shader non compile" << std::endl;
		std::cout << message << std::endl;
		glDeleteShader(shaderId);

		return 0;
	}

	return shaderId;
}

int Shader::CreateShader(const std::string& vertexShader, const std::string& fragmentShader){

	unsigned int program = glCreateProgram();
	unsigned int vs = CompileShader(GL_VERTEX_SHADER, vertexShader);
	unsigned int fs = CompileShader(GL_FRAGMENT_SHADER, fragmentShader);

	glAttachShader(program, vs);
	glAttachShader(program, fs);
	glLinkProgram(program);
	glValidateProgram(program);

	glDeleteShader(vs);
	glDeleteShader(fs);

	return program;
}

