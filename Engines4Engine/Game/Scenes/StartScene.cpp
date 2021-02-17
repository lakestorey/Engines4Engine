#include "StartScene.h"

StartScene::StartScene() :gameScene(nullptr){
}

StartScene::~StartScene() {
	delete gameScene;
	gameScene = nullptr;
}

bool StartScene::OnCreate() {
	//std::cout << "start scene" << std::endl;
	Debug::Info("start scene created", "StartScene.cpp", __LINE__);
	gameScene = new GameScene();
	gameScene->OnCreate();
	return true;
}

void StartScene::Update(const float deltaTime_) {
}

void StartScene::Render() {
}