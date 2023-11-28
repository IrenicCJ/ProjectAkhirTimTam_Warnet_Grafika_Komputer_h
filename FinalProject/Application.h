#pragma once

#include "RenderEngine.h"
#include "Cube.h"
#include "Shader.h"
#include "Texture.h"

class Application :
	public RenderEngine
{
public:
	Application();
	~Application();
private:
	GLuint shaderProgram, VBO, VAO, EBO, texture, VBO2, VAO2, EBO2, texture2;
	float viewCamX, viewCamY, viewCamZ, upCamX, upCamY, upCamZ, posCamX, posCamY, posCamZ, CAMERA_SPEED, fovy;
	//float angle = 0;
	Shader* shader;
	Texture* cubeDiffTex, * cubeSpecTex, * cubeDiffTex2, * cubeDiffTex3, * cubeDiffTex4, * cubeDiffTex5, * cubeDiffTex6, * cubeDiffTex7, * cubeDiffTex8, * cubeDiffTex9, * cubeDiffTex10, * cubeDiffTex11, * cubeDiffTex12, * cubeDiffTex13, *cubeDiffTex14, *cubeDiffTex15, * cubeDiffTex16, * cubeDiffTex17, * cubeDiffTex18, * cubeDiffTex19, * cubeDiffTex20;
	Cube* cube, * cube2, * cube3, * cube4, * cube5, * cube6, * cube7, *cube8, * cube9, * cube10, * cube11, * cube12, * cube13, * cube14, *cube15, * cube16, * cube17, * cube18, * cube19, * cube20;
	float angle = 0;
	glm::vec3 viewPos;
	void setupPerspective();
	void MoveCamera(float speed);
	void StrafeCamera(float speed);
	void RotateCamera(float speed);
	void setupCamera();
	void InitCamera();
	/*void BuildColoredPlane();
	void DrawColoredPlane();*/
	void setupLighting();
	virtual void Init();
	virtual void DeInit();
	virtual void Update(double deltaTime);
	virtual void Render();
	virtual void ProcessInput(GLFWwindow* window);
};