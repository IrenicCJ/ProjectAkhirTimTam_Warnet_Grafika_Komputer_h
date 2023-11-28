#include "Application.h"

Application::Application()
{

}

Application::~Application()
{
}

void Application::setupPerspective()
{
	// Pass perspective projection matrix
	glm::mat4 projection = glm::perspective(fovy, (GLfloat)this->screenWidth / (GLfloat)this->screenHeight, 0.1f, 100.0f);
	shader->setMat4("projection", projection);

	glm::mat4 view = glm::lookAt(glm::vec3(posCamX, posCamY, posCamZ), glm::vec3(viewCamX, viewCamY, viewCamZ), glm::vec3(upCamX, upCamY, upCamZ));
	shader->setMat4("view", view);
}

void Application::MoveCamera(float speed)
{
	float x = viewCamX - posCamX;
	float z = viewCamZ - posCamZ;
	// forward positive cameraspeed and backward negative -cameraspeed.
	posCamX = posCamX + x * speed;
	posCamZ = posCamZ + z * speed;
	viewCamX = viewCamX + x * speed;
	viewCamZ = viewCamZ + z * speed;
}

void Application::StrafeCamera(float speed)
{
	float x = viewCamX - posCamX;
	float z = viewCamZ - posCamZ;
	float orthoX = -z;
	float orthoZ = x;

	// left positive cameraspeed and right negative -cameraspeed.
	posCamX = posCamX + orthoX * speed;
	posCamZ = posCamZ + orthoZ * speed;
	viewCamX = viewCamX + orthoX * speed;
	viewCamZ = viewCamZ + orthoZ * speed;
}

void Application::RotateCamera(float speed)
{
	float x = viewCamX - posCamX;
	float z = viewCamZ - posCamZ;
	viewCamZ = (float)(posCamZ + glm::sin(speed) * x + glm::cos(speed) * z);
	viewCamX = (float)(posCamX + glm::cos(speed) * x - glm::sin(speed) * z);
}


void Application::setupCamera()
{
	// LookAt camera (position, target/direction, up)
	viewPos = glm::vec3(5, 0.5, 3);
	glm::mat4 view = glm::lookAt(viewPos, glm::vec3(0, 0, 0), glm::vec3(0, 1, 0));
	shader->setMat4("view", view);
}

void Application::setupLighting()
{
	// set lighting attributes
	glm::vec3 lightPos = glm::vec3(0, 1, 0);
	shader->setVec3("lightPos", lightPos);
	shader->setVec3("viewPos", viewPos);
	glm::vec3 lightColor = glm::vec3(1.0f, 1.0f, 1.0f);
	shader->setVec3("lightColor", lightColor);
}

void Application::Init()
{
	// Build a lighting map shader
	shader = new Shader("texturedCube.vert", "texturedCube.frag");
	shader->Init();
	// Create cube diffuse texture and specular texture
	cubeDiffTex = new Texture("crate_diffusemap.png");
	cubeDiffTex->Init();
	cubeSpecTex = new Texture("crate_specularmap.png");
	cubeSpecTex->Init();

	// Create instance of cube
	cube = new Cube(shader, cubeDiffTex, cubeSpecTex);
	cube->Init();
	cube->SetScale(0.2f, 0.2f, 0.2f);

	cubeDiffTex2 = new Texture("monitor.jpg");
	cube2 = new Cube(shader, cubeDiffTex2, cubeDiffTex2);
	cube2->Init();
	cube2->SetScale(0.2f, 0.2f, 0.2f);

	cubeDiffTex3 = new Texture("meja.jpg");
	cube3 = new Cube(shader, cubeDiffTex3, cubeDiffTex3);
	cube3->Init();
	cube3->SetScale(0.2f, 0.2f, 0.2f);

	cubeDiffTex4 = new Texture("kaki meja.jpg");
	cube4 = new Cube(shader, cubeDiffTex4, cubeDiffTex4);
	cube4->Init();
	cube4->SetScale(0.2f, 0.2f, 0.2f);

	cubeDiffTex5 = new Texture("pegangan_monitor.jpg");
	cube5 = new Cube(shader, cubeDiffTex5, cubeDiffTex5);
	cube5->Init();
	cube5->SetScale(0.2f, 0.2f, 0.2f);

	cubeDiffTex6 = new Texture("dudukan_senderan_kursi.png");
	cube6 = new Cube(shader, cubeDiffTex6, cubeDiffTex6);
	cube6->Init();
	cube6->SetScale(0.2f, 0.2f, 0.2f);

	cubeDiffTex7 = new Texture("kaki_kursi1.jpg");
	cube7 = new Cube(shader, cubeDiffTex7, cubeDiffTex7);
	cube7->Init();
	cube7->SetScale(0.2f, 0.2f, 0.2f);

	cubeDiffTex8 = new Texture("walls.jpg");
	cube8 = new Cube(shader, cubeDiffTex8, cubeDiffTex7);
	cube8->Init();
	cube8->SetScale(0.2f, 0.2f, 0.2f);

	cubeDiffTex9 = new Texture("floor.jpg");
	cube9 = new Cube(shader, cubeDiffTex9, cubeDiffTex9);
	cube9->Init();
	cube9->SetScale(0.2f, 0.2f, 0.2f);

	cubeDiffTex10 = new Texture("ceiling.png");
	cube10 = new Cube(shader, cubeDiffTex10, cubeDiffTex10);
	cube10->Init();
	cube10->SetScale(0.2f, 0.2f, 0.2f);

	cubeDiffTex11 = new Texture("keyboard.png");
	cube11 = new Cube(shader, cubeDiffTex11, cubeDiffTex11);
	cube11->Init();
	cube11->SetScale(0.2f, 0.2f, 0.2f);

	cubeDiffTex12 = new Texture("lamp_pole.jpg");
	cube12 = new Cube(shader, cubeDiffTex12, cubeDiffTex12);
	cube12->Init();
	cube12->SetScale(0.2f, 0.2f, 0.2f);

	cubeDiffTex13 = new Texture("lamp2.jpg");
	cube13 = new Cube(shader, cubeDiffTex13, cubeDiffTex13);
	cube13->Init();
	cube13->SetScale(0.2f, 0.2f, 0.2f);

	cubeDiffTex14 = new Texture("pc.png");
	cube14 = new Cube(shader, cubeDiffTex14, cubeDiffTex14);
	cube14->Init();
	cube14->SetScale(0.2f, 0.2f, 0.2f);

	cubeDiffTex15 = new Texture("coba.png");
	cube15 = new Cube(shader, cubeDiffTex15, cubeDiffTex15);
	cube15->Init();
	cube15->SetScale(0.2f, 0.2f, 0.2f);

	cubeDiffTex16 = new Texture("postergamink.jpg");
	cube16 = new Cube(shader, cubeDiffTex16, cubeDiffTex16);
	cube16->Init();
	cube16->SetScale(0.2f, 0.2f, 0.2f);

	cubeDiffTex17 = new Texture("poster5.jpg");
	cube17 = new Cube(shader, cubeDiffTex17, cubeDiffTex17);
	cube17->Init();
	cube17->SetScale(0.2f, 0.2f, 0.2f);

	cubeDiffTex18 = new Texture("poster3.jpg");
	cube18 = new Cube(shader, cubeDiffTex18, cubeDiffTex18);
	cube18->Init();
	cube18->SetScale(0.2f, 0.2f, 0.2f);

	cubeDiffTex19 = new Texture("poster4.jpg");
	cube19 = new Cube(shader, cubeDiffTex19, cubeDiffTex19);
	cube19->Init();
	cube19->SetScale(0.2f, 0.2f, 0.2f);

	cubeDiffTex20 = new Texture("resep.jpg");
	cube20 = new Cube(shader, cubeDiffTex20, cubeDiffTex20);
	cube20->Init();
	cube20->SetScale(0.2f, 0.2f, 0.2f);

	
	// setup perspective 
	setupPerspective();
	// setup camera
	 setupCamera(); 
		// setup lighting
		setupLighting();
	InitCamera();
}

void Application::InitCamera()
{
	posCamX = 0.0f;
	posCamY = 1.0f;
	posCamZ = 8.0f;
	viewCamX = 0.0f;
	viewCamY = 1.0f;
	viewCamZ = 0.0f;
	upCamX = 0.0f;
	upCamY = 1.0f;
	upCamZ = 0.0f;
	CAMERA_SPEED = 0.001f;
	fovy = 45.0f;
	glfwSetInputMode(this->window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
}

void Application::DeInit()
{
	delete cube;
}

void Application::Update(double deltaTime)
{
	angle += (float)((deltaTime * 1.5f) / 1000);
	cube->SetRotation(angle, 0, 1, 0);
}

void Application::Render()
{
	glViewport(0, 0, this->screenWidth, this->screenHeight);

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	glEnable(GL_DEPTH_TEST);

	setupPerspective();

	//setupCamera();

	//DrawColoredPlane();

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++) {
			if (j > 1) {
				//Kaki Kursi
				cube7->SetPosition(-8 + (i * 30) + (j - 2) * 4, -1.1, -4);
				cube7->SetScale(0.25, 1.5, 0.25);
				cube7->Draw();

				//Kaki Meja
				cube4->SetPosition(-12.5 + (i * 30) + (j - 2) * 13, -0.5, 3);
				cube4->SetScale(0.25, 2.5, 0.25);
				cube4->Draw();
			}
			else {
				//Kaki Kursi
				cube7->SetPosition(-8 + (i * 30) + j * 4, -1.1, 1);
				cube7->SetScale(0.25, 1.5, 0.25);
				cube7->Draw();

				//Kaki Meja
				cube4->SetPosition(-12.5 + (i * 30) + j * 13, -0.5, 9);
				cube4->SetScale(0.25, 2.5, 0.25);
				cube4->Draw();
			}
		}

		//Dudukan Kursi
		cube6->SetPosition(-0.85 + (i * 4.27), -3.5, -0.2);
		cube6->SetScale(1.75, 0.25, 1.75);
		cube6->Draw();

		//Senderan Kursi
		cube6->SetPosition(-1 + (i * 5), 0.075, -4.25);
		cube6->SetScale(1.5, 1.75, 0.25);
		cube6->Draw();

		//Papan Meja
		cube3->SetPosition(-0.3 + (i * 1.5), -0.45, 0.8);
		cube3->SetScale(5, 0.25, 2);
		cube3->Draw();

		//Dudukan Monitor
		cube5->SetPosition(-1.5 + (i * 7.5), 0.9, 3.1);
		cube5->SetScale(1, 0.05, 0.7);
		cube5->Draw();

		//Penyangga Monitor
		cube5->SetPosition(-5 + (i * 25), 0.56, 16);
		cube5->SetScale(0.3, 1, 0.15);
		cube5->Draw();

		//Layar Monitor
		cube5->SetPosition(-1 + (i * 5), 1, 15);
		cube5->SetScale(1.5, 1, 0.15);
		cube5->Draw();

		//Layar 2
		cube2->SetPosition(-1.1 + (i * 5.55), 1.175, 2170);
		cube2->SetScale(1.35, 0.85, 0.001);
		cube2->Draw();

		//Keyboard
		cube11->SetPosition(-1.2 + (i * 7.5), 0.9, 2.5);
		cube11->SetScale(1, 0.05, 0.5);
		cube11->Draw();

		//Mouse
		cube5->SetPosition(-10 + (i * 36.5), 0.9, 4.25);
		cube5->SetScale(0.2, 0.05, 0.3);
		cube5->Draw();

		//PC
		cube14->SetPosition(-5 + (i * 12.5), 0.5, 2);
		cube14->SetScale(0.6, 1, 1);
		cube14->Draw();
	}

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++) {
			if (j > 1) {
				//Kaki Kursi
				cube7->SetPosition(-8 + (i * 30) + (j - 2) * 4, -1.1, -86);
				cube7->SetScale(0.25, 1.5, 0.25);
				cube7->Draw();

				//Kaki Meja
				cube4->SetPosition(-12.5 + (i * 30) + (j - 2) * 13, -0.5, -94);
				cube4->SetScale(0.25, 2.5, 0.25);
				cube4->Draw();
			}
			else {
				//Kaki Kursi
				cube7->SetPosition(-8 + (i * 30) + j * 4, -1.1, -81);
				cube7->SetScale(0.25, 1.5, 0.25);
				cube7->Draw();

				//Kaki Meja
				cube4->SetPosition(-12.5 + (i * 30) + j * 13, -0.5, -88);
				cube4->SetScale(0.25, 2.5, 0.25);
				cube4->Draw();
			}
		}

		//Dudukan Kursi
		cube6->SetPosition(-0.85 + (i * 4.27), -3.5, -11.9);
		cube6->SetScale(1.75, 0.25, 1.75);
		cube6->Draw();

		//Senderan Kursi
		cube6->SetPosition(-1 + (i * 5), 0.075, -80.5);
		cube6->SetScale(1.5, 1.75, 0.25);
		cube6->Draw();

		//Papan Meja
		cube3->SetPosition(-0.3 + (i * 1.5), -0.45, -11.35);
		cube3->SetScale(5, 0.25, 2);
		cube3->Draw();

		//Dudukan Monitor
		cube5->SetPosition(-1.5 + (i * 7.5), 0.9, -33.2);
		cube5->SetScale(1, 0.05, 0.7);
		cube5->Draw();

		//Penyangga Monitor
		cube5->SetPosition(-5 + (i * 25), 0.56, -156.5);
		cube5->SetScale(0.3, 1, 0.15);
		cube5->Draw();

		//Layar Monitor
		cube5->SetPosition(-1 + (i * 5), 1, -155.5);
		cube5->SetScale(1.5, 1, 0.15);
		cube5->Draw();

		//Layar 2
		cube2->SetPosition(-1.1 + (i * 5.55), 1.175, -23250);
		cube2->SetScale(1.35, 0.85, 0.001);
		cube2->Draw();

		//Keyboard
		cube11->SetPosition(-1.2 + (i * 7.5), 0.9, -44.7);
		cube11->SetScale(1, 0.05, 0.5);
		cube11->Draw();

		//Mouse
		cube5->SetPosition(-10 + (i * 36.5), 0.9, -74.6);
		cube5->SetScale(0.2, 0.05, 0.3);
		cube5->Draw();

		//PC
		cube14->SetPosition(-5 + (i * 12.5), 0.5, -23);
		cube14->SetScale(0.6, 1, 1);
		cube14->Draw();
	}

	//Lantai
	cube9->SetPosition(0.2, -10.1, -0.35);
	cube9->SetScale(30, 0.25, 30);
	cube9->Draw();

	//Tembok
	for (int i = 0; i < 4; i++) {
		if (i > 1) {
			cube8->SetPosition(70 - (i - 2) * 100, 0.275, -0.35);
			cube8->SetScale(0.30, 11.75, 30);
			cube8->Draw();
		}
		else {
			cube8->SetPosition(0.2, 0.275, 15 - i * 100);
			cube8->SetScale(30, 11.75, 0.30);
			cube8->Draw();
		}
	}

	//Langit-langit
	cube10->SetPosition(0.2, 30, -0.35);
	cube10->SetScale(30, 0.30, 30);
	cube10->Draw();

	//Lampu
	for (int i = 0; i < 4; i++) {
		if (i > 1) {
			//Dudukan Lampu
			cube12->SetPosition(-3.7 + ((i - 2) * 14), -9, -13);
			cube12->SetScale(1.75, 0.25, 1.75);
			cube12->Draw();

			//Tiang Lampu
			cube12->SetPosition(-26 + ((i - 2) * 98), -0.05, -91);
			cube12->SetScale(0.25, 4, 0.25);
			cube12->Draw();

			//Lampu
			cube13->SetPosition(-4.35 + ((i - 2) * 16.35), 1.6, -15.15);
			cube13->SetScale(1.5, 1.5, 1.5);
			cube13->Draw();
		}
		else {
			//Dudukan Lampu
			cube12->SetPosition(-3.7 + (i * 14), -9, 0.8);
			cube12->SetScale(1.75, 0.25, 1.75);
			cube12->Draw();

			//Tiang Lampu
			cube12->SetPosition(-26 + (i * 98), -0.05, 5.5);
			cube12->SetScale(0.25, 4, 0.25);
			cube12->Draw();

			//Lampu
			cube13->SetPosition(-4.35 + (i * 16.35), 1.6, 0.9);
			cube13->SetScale(1.5, 1.5, 1.5);
			cube13->Draw();
		}
	}

	//pintu
	cube15->SetPosition(26.3, 0.06, -1.9);
	cube15->SetScale(0.8, 7, 5);
	cube15->Draw();

	//poster
	cube16->SetPosition(0.7, 1.175, 4300);
	cube16->SetScale(3, 4, 0.001);
	cube16->Draw();

	cube17->SetPosition(3.7, 1.175, 4300);
	cube17->SetScale(3, 4, 0.001);
	cube17->Draw();

	cube18->SetPosition(0.7, 1.175, -25300);
	cube18->SetScale(3, 4, 0.001);
	cube18->Draw();

	cube19->SetPosition(3.7, 1.175, -25300);
	cube19->SetScale(3, 4, 0.001);
	cube19->Draw();

	//Meja resepsionis
	cube3->SetPosition(-5.2, -0.175, -1.47);
	cube3->SetScale(0.8, 3.5, 7);
	cube3->Draw();

	cube3->SetPosition(-1.25, -0.175, -26.7);
	cube3->SetScale(5, 3.5, 0.25);
	cube3->Draw();

	cube3->SetPosition(-2, -0.175, -55.6);
	cube3->SetScale(2.55, 3.5, 0.25);
	cube3->Draw();

	cube20->SetPosition(-2.05, 0, -1.5);
	cube20->SetScale(2.5, 0.25, 7);
	cube20->Draw();

	glDisable(GL_DEPTH_TEST);
}


void Application::ProcessInput(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
		glfwSetWindowShouldClose(window, true);
	}

	// zoom camera
	// -----------
	if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_RIGHT) == GLFW_PRESS) {
		if (fovy < 90) {
			fovy += 0.0001f;
		}
	}

	if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS) {
		if (fovy > 0) {
			fovy -= 0.0001f;
		}
	}

	// update camera movement 
	// -------------
	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) {
		MoveCamera(CAMERA_SPEED);
	}
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) {
		MoveCamera(-CAMERA_SPEED);
	}

	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) {
		StrafeCamera(-CAMERA_SPEED);
	}

	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) {
		StrafeCamera(CAMERA_SPEED);
	}

	// update camera rotation
	// ----------------------
	double mouseX, mouseY;
	double midX = screenWidth / 2;
	double midY = screenHeight / 2;
	float angleY = 0.0f;
	float angleZ = 0.0f;

	// Get mouse position
	glfwGetCursorPos(window, &mouseX, &mouseY);
	if ((mouseX == midX) && (mouseY == midY)) {
		return;
	}

	// Set mouse position
	glfwSetCursorPos(window, midX, midY);

	// Get the direction from the mouse cursor, set a resonable maneuvering speed
	angleY = (float)((midX - mouseX)) / 1000;
	angleZ = (float)((midY - mouseY)) / 1000;

	// The higher the value is the faster the camera looks around.
	viewCamY += angleZ * 2;

	// limit the rotation around the x-axis
	if ((viewCamY - posCamY) > 8) {
		viewCamY = posCamY + 8;
	}
	if ((viewCamY - posCamY) < -8) {
		viewCamY = posCamY - 8;
	}
	RotateCamera(-angleY);
}

int main(int argc, char** argv) {
	Application app = Application();
	app.Start("Cube Example",
		800, 600,
		false,
		false);
}

