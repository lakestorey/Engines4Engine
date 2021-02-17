#ifndef WINDOW_H //used instead of pragma once
#define WINDOW_H //because pragma once is windows only

#include <SDL.h>
#include <glew.h>
#include <SDL_opengl.h>
#include <string>
#include <iostream>
#include "Debug.h"

class Window {
public:
	Window();
	~Window();
	bool OnCreate(std::string name_, int width_, int height_);
	void OnDestroy();
	int GetWidth() const;
	int GetHeight() const;
	SDL_Window* GetWindow() const;

private:
	void SetPreAttributes();
	void SetPostAttributes();

	int width;
	int height;
	SDL_Window* window;
	SDL_GLContext context;

};
#endif // !WINDOW_H