#include "SProgram.h"

SProgram::SProgram() {

	this->sprogram = glCreateProgram();
	if (!this->sprogram) {
		printf("Shader Program not created.");
		return;
	}
	std::cout << "Insufficient arguements supplied to create a complete shader Program. Please use other overloaded constructor." << std::endl;
}

SProgram::SProgram(const char* vertexShaderPath, const char* fragmentShaderPath) {

	this->sprogram = glCreateProgram();
	if (!this->sprogram) {
		printf("Shader Program not created.");
		return;
	}

	this->fStruct = fragmentShaderPath;
	this->vStruct = vertexShaderPath;

	this->linkShaders();

}

void SProgram::compileShader( const char* lines, GLenum type) {

	GLuint shaderObject = glCreateShader(type);

	const char* code[1] = { lines }; 
	int length[1] = { strlen(lines) };

	glShaderSource(shaderObject, 1, code, length);
	glCompileShader(shaderObject);

	int success;
   char infolog[512];

	glGetShaderiv(shaderObject, GL_COMPILE_STATUS, &success);
	if (!success) {

		glGetShaderInfoLog(shaderObject, sizeof(infolog), NULL, infolog);
		std::cout << "Error compiling shader, "<<type<< ": " << infolog << std::endl;
		return;
	}

	glAttachShader(this->sprogram, shaderObject);

}

void SProgram::linkShaders() {

	std::string s_vstruct = this->readFile(this->vStruct);
	std::string s_fstruct = this->readFile(this->fStruct);

	this->compileShader( s_vstruct.c_str(), GL_VERTEX_SHADER);
	this->compileShader(s_fstruct.c_str(), GL_FRAGMENT_SHADER);

	int success;
	char infolog[512];

	glLinkProgram(this->sprogram);
	glGetProgramiv(this->sprogram, GL_LINK_STATUS, &success);

	if (!success) {

		glGetProgramInfoLog(this->sprogram, sizeof(infolog), NULL, infolog);
		std::cout << "Error Linking Shader Program: " << infolog << std:: endl;
		return;

	}

	glValidateProgram(this->sprogram);
	glGetProgramiv(this->sprogram, GL_VALIDATE_STATUS, &success);

	if (!success) {

		glGetProgramInfoLog(this->sprogram, sizeof(infolog), NULL, infolog);
		std::cout << "Error Validating Shader Program: " << infolog << std::endl;
		return;

	}


}

void SProgram::bindProgram() {

	glUseProgram(this->sprogram);

}

void SProgram::unbindProgram() {

	glUseProgram(0);

}
void SProgram::setInt(const char* attribName, GLuint value) {

	GLuint location = this->getUniformLocation(attribName);

	if ((int)location < 0)
		printf("Supplied attribute : %s is Incorrect or not in use. \n", attribName);

	glUniform1i(location, value);
}

void SProgram::setFloat(const char* attribName, GLfloat value) {

	GLuint location = this->getUniformLocation(attribName);

	if ((int)location < 0)
		printf("Supplied attribute : %s is Incorrect or not in use. \n", attribName);

	glUniform1f(location, value );

}

void SProgram::setVec2(const char* attribName, glm::vec2 value) {

	GLuint location = this->getUniformLocation(attribName);

	if ((int) location < 0)
		printf("Supplied attribute : %s is Incorrect or not in use. \n", attribName);

	glUniform2fv(location, 1, glm::value_ptr(value));

}

void SProgram::setVec3(const char* attribName, glm::vec3 value) {

	GLuint location = this->getUniformLocation(attribName);
	
	if ((int) location < 0)
		printf("Supplied attribute : %s is Incorrect or not in use. \n", attribName);

	glUniform3fv(location, 1, glm::value_ptr(value));

}

void SProgram::setMat4(const char* attribName, glm::mat4 value) {

	GLuint location = this->getUniformLocation(attribName);

	if ((int) location < 0)
		printf("Supplied attribute : %s is Incorrect or not in use. \n", attribName);

	glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(value));

}

GLuint SProgram::getProgramID() {

	return this->sprogram;

}

GLuint SProgram::getUniformLocation(const GLchar* name) {

	return glGetUniformLocation(this->sprogram, name);

}


std::string SProgram::readFile(const char* path) {
	
	std::string line, content;
	std::ifstream filestream(path, std::ios::in);

	if (!filestream.is_open()) {
		std::cout << "Path to file does not exist.";
		return "\0";
	}

	while (!filestream.eof()) {
		
		std::getline(filestream, line);
		content.append(line + "\n");

	}

	filestream.close();
	return content;
}


SProgram::~SProgram() {

}
