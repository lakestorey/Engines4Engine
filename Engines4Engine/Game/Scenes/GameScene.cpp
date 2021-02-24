#include "GameScene.h"

GameScene::GameScene() :shape(nullptr){
}

GameScene::~GameScene() {
	delete shape;
	shape = nullptr;
}

bool GameScene::OnCreate() {
	//std::cout << "game scene" << std::endl;
	Debug::Info("game scene created", "GameScene.cpp", __LINE__);

	Vertex v;
	std::vector<Vertex> vertexList;
	//reserve memory beforehand so it can move it dynamically.
	vertexList.reserve(3);
	//can use the same object and just push it onto the list each time.
	v.position = glm::vec3(0.5f, 0.0f, 0.0f); //top right
	vertexList.push_back(v);
	v.position = glm::vec3(0.0f, -0.0f, 0.0f); //top left
	vertexList.push_back(v);
	v.position = glm::vec3(0.5f, -0.5f, 0.0f); //bottom right
	vertexList.push_back(v);

	Vertex c;
	std::vector<Vertex> vertexList2;
	vertexList2.reserve(3);
	c.position = glm::vec3(0.0f, -0.0f, 0.0f); //top left
	vertexList2.push_back(c);
	c.position = glm::vec3(0.0f, -0.5f, 0.0f); //bottom left
	vertexList2.push_back(c);
	c.position = glm::vec3(0.5f, -0.5f, 0.0f); // bottom right
	vertexList2.push_back(c);

	Model* model = new Model();
	model->AddMesh(new Mesh(vertexList));
	model->AddMesh(new Mesh(vertexList2));
	shape = new GameObject(model);

	return true;
}

void GameScene::Update(const float deltaTime_) {
	//prints out millis between frames, every frame.
	std::cout << deltaTime_ << std::endl;
}

void GameScene::Render() {
	shape->Render();
}