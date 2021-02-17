#ifndef GAME1_H
#define GAME1_H

// ../ = go to parent folder
//makes navigation easier
#include "../Engine/Core/CoreEngine.h"
#include "Scenes/StartScene.h"
#include "Scenes/GameScene.h"

class Game1 : public GameInterface {
public:
	Game1();
	virtual ~Game1();

	bool OnCreate() override;
	void Update(const float deltaTime_) override;
	void Render() override;
private:
	int currentSceneNum;
	Scene* currentScene;
	void BuildScene();
};
#endif //!GAME1_H
