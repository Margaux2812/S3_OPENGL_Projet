#include "../include/myshader.hpp"
//#include <filesystem>

MyShader::MyShader(const std::string& vertexShaderFilepath, const std::string& fragmentShaderFilepath)
: m_shaderID(0)
{
	ShaderProgramSources source = ParseShaders(vertexShaderFilepath, fragmentShaderFilepath);
	m_shaderID = CreateShaders(source.VertexSource, source.FragmentSource);
}

MyShader::~MyShader(){
	glDeleteProgram(m_shaderID);
}

ShaderProgramSources MyShader::ParseShaders(const std::string& vertexShaderFilepath, const std::string& fragmentShaderFilepath){
	
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

unsigned int MyShader::CompileShaders(const unsigned int type, const std::string& source){

	unsigned int shaderId= glCreateShader(type);
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

int MyShader::CreateShaders(const std::string& vertexShader, const std::string& fragmentShader){

	unsigned int program = glCreateProgram();
	unsigned int vs = CompileShaders(GL_VERTEX_SHADER, vertexShader);
	unsigned int fs = CompileShaders(GL_FRAGMENT_SHADER, fragmentShader);

	glAttachShader(program, vs);
	glAttachShader(program, fs);
	glLinkProgram(program);
	glValidateProgram(program);

	glDeleteShader(vs);
	glDeleteShader(fs);
	
	return program;
}

void MyShader::bind() const{
	glUseProgram(m_shaderID);
}

void MyShader::unbind() const{
	glUseProgram(0);
}

void MyShader::setUniform3f(const std::string& name, const glm::vec3 value){
	glUniform3f(getUniformLocation(name),
  	value[0],
  	value[1],
  	value[2]);
}

void MyShader::setUniformVec3(const std::string& name, const glm::vec3 value[6]){
	glUniform3fv(getUniformLocation(name),
  	6,
  	glm::value_ptr(value[0]));
}

void MyShader::setUniform1i(const std::string& name, const int value){
	glUniform1i(getUniformLocation(name), value);
}

void MyShader::setUniform1f(const std::string& name, const float value){
	glUniform1f(getUniformLocation(name), value);
}

void MyShader::setUniformMatrix4fv(const std::string& name, const GLfloat*value)
{
	glUniformMatrix4fv(getUniformLocation(name),
                1,
                GL_FALSE,
                value
                );
}

void MyShader::setUniformMatrix4x3fv(const std::string& name, const GLfloat*value)
{
	glUniformMatrix4x3fv(getUniformLocation(name),
                1,
                GL_FALSE,
                value
                );
}

int MyShader::getUniformLocation(const std::string& name)
{
	int location = glGetUniformLocation(m_shaderID, name.c_str());
	// std::cout << "Location =  '" << location << std::endl;
	// if(location == -1){
	// 	std::cout << "Problème variable uniforme '" << name <<"' n'existe pas" << std::endl;
	// }
	

	return location;
}