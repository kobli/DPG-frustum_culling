#ifndef UTILS_HPP_18_12_29_15_46_10
#define UTILS_HPP_18_12_29_15_46_10 
#include <iostream>
#include <vector>
#include <tuple>
#include <string>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "libs.hpp"
#include "types.hpp"

#define BUFFER_OFFSET(i) ((char *)NULL + (i))

std::ostream& operator<<(std::ostream& s, const glm::vec3& v);
std::istream& operator>>(std::istream& s, glm::vec3& v);

void setUniform(GLuint program, const glm::mat4x4& m, std::string name);

/** Creates and links shader program from pairs shaderType-fileName.
 */
GLuint loadShaderProgram(std::vector<std::tuple<GLenum,std::string>> shaderFiles);

void openglCallbackFunction(GLenum source,
		GLenum type,
		GLuint id,
		GLenum severity,
		GLsizei length,
		const GLchar* message,
		const void* userParam);

#endif /* UTILS_HPP_18_12_29_15_46_10 */
