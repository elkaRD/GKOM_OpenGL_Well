#include "Light.h"

void Light::update(GLfloat lightIntensity, ShaderProgram* shader, ShaderProgram* shader2, glm::vec3 cameraPosition)
{

	shader->Use();
	GLint objectColorLoc = glGetUniformLocation(shader->get_programID(), "objectColor");
	GLint lightColorLoc = glGetUniformLocation(shader->get_programID(), "lightColor");
	glUniform3f(objectColorLoc, 1.0f, 0.5f, 0.31f);
	glUniform3f(lightColorLoc, 1.0f, 0.5f, 1.0f);

	GLint lightDirLoc = glGetUniformLocation(shader->get_programID(), "dirLight.direction");
	GLint viewPosLoc = glGetUniformLocation(shader->get_programID(), "viewPos");
	//glUniform3f(lightPosLoc, lightPos.x, lightPos.y, lightPos.z);
	glUniform3f(lightDirLoc, -3.0f, -0.5f, -1.5f);
	glUniform3f(viewPosLoc, cameraPosition.x, cameraPosition.y, cameraPosition.z);
	// Set lights properties
	glm::vec3 ambient = glm::vec3(0.2f, 0.2f, 0.2f) * lightIntensity;
	glm::vec3 diffues = glm::vec3(1.0f, 1.0f, 1.0f) * lightIntensity;
	glm::vec3 specular = glm::vec3(0.8f, 0.8f, 0.8f) * lightIntensity;
	glUniform3f(glGetUniformLocation(shader->get_programID(), "dirLight.ambient"), 0.5f, 0.5f, 0.5f);
	glUniform3f(glGetUniformLocation(shader->get_programID(), "dirLight.diffuse"), 0.5f, 0.5f, 0.5f);
	glUniform3f(glGetUniformLocation(shader->get_programID(), "dirLight.specular"), 0.1f, 0.1f, 0.1f);
	glUniform3f(glGetUniformLocation(shader->get_programID(), "pointLight.ambient"), ambient.x, ambient.y, ambient.z);
	glUniform3f(glGetUniformLocation(shader->get_programID(), "pointLight.diffuse"), diffues.x, diffues.y, diffues.z);
	glUniform3f(glGetUniformLocation(shader->get_programID(), "pointLight.specular"), specular.x, specular.y, specular.z);
	glUniform1f(glGetUniformLocation(shader->get_programID(), "pointLight.constant"), 1.0f);
	glUniform1f(glGetUniformLocation(shader->get_programID(), "pointLight.linear"), 0.09f);
	glUniform1f(glGetUniformLocation(shader->get_programID(), "pointLight.quadratic"), 0.032f);
	shader2->Use();
	glUniform1f(glGetUniformLocation(shader2->get_programID(), "light"), lightIntensity);
}