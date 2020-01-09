#include "Skybox.h"

unsigned int loadCubemap(std::vector<std::string> faces)
{
	unsigned int textureID;
	glGenTextures(1, &textureID);
	glBindTexture(GL_TEXTURE_CUBE_MAP, textureID);

	int width, height;
	for (unsigned int i = 0; i < faces.size(); i++)
	{
		unsigned char* data = SOIL_load_image(faces[i].c_str(), &width, &height, nullptr, SOIL_LOAD_AUTO);
		if (data)
		{
			glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + i, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
			SOIL_free_image_data(data);
		}
		else
		{
			std::cout << "Cubemap texture failed to load at path: " << faces[i] << std::endl;
			SOIL_free_image_data(data);
		}
	}
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);

	return textureID;
}

void Skybox::setupBuffers()
{
	glGenVertexArrays(1, &skyboxVAO);
	glGenBuffers(1, &skyboxVBO);
	glBindVertexArray(skyboxVAO);
	glBindBuffer(GL_ARRAY_BUFFER, skyboxVBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(skyboxVertices), &skyboxVertices, GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
}

void Skybox::start()
{
	faces.push_back("skybox/hills_rt.png");
	faces.push_back("skybox/hills_lf.png");
	faces.push_back("skybox/hills_up.png");
	faces.push_back("skybox/hills_dn.png");
	faces.push_back("skybox/hills_bk.png");
	faces.push_back("skybox/hills_ft.png");


	skyboxProgram = new ShaderProgram("skybox.vert", "skybox.frag");
	setupBuffers();
	cubemapTexture = loadCubemap(faces);
}

void Skybox::render(glm::mat4 view, glm::mat4 projection)
{
	glDepthFunc(GL_LEQUAL);
	skyboxProgram->Use();
	view = glm::mat4(glm::mat3(view));
	GLuint vie = glGetUniformLocation(skyboxProgram->get_programID(), "view");
	glUniformMatrix4fv(vie, 1, GL_FALSE, glm::value_ptr(view));
	GLuint proj = glGetUniformLocation(skyboxProgram->get_programID(), "projection");
	glUniformMatrix4fv(proj, 1, GL_FALSE, glm::value_ptr(projection));
	glBindVertexArray(skyboxVAO);
	glBindTexture(GL_TEXTURE_CUBE_MAP, cubemapTexture);
	glDrawArrays(GL_TRIANGLES, 0, 36);
	glBindVertexArray(0);
	glDepthFunc(GL_LESS);
}

void Skybox::destroy()
{
	glDeleteVertexArrays(1, &skyboxVAO);
	glDeleteBuffers(1, &skyboxVBO);
	delete skyboxProgram;
}