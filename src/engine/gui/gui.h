#ifndef GUI_H
#define GUI_H

#include "guiData.h"

#include <stdio.h>
#include <thread>
#include <SDL.h>
#include <SDL_image.h> 
#include <fstream>
#include <functional>

#include "../math.h"
#include "uiParser.h"
#include "uiElement.h"
#include "../engineSystem.h"
#include "renderer.h"
#include "../engineEvent.h"
#include "../engineCore.h"

class GUI : public EngineSystem {
	static SDL_Renderer *globalRenderer;
	
	static int windowWidth, windowHeight;

	public:
		static std::string WINDOW_NAME;
		static std::vector<std::function<void(SDL_Event)>> SDLEventHandlers;
		static std::map<std::string, UIElement> menus;
		static SDL_Window* window;
	
	public:
		GUI() {title = "GUI";}
		
		void initialize();
		void handleEvent(EngineEvent event);
		void update();
		
		static bool initSDL();

		static void addSDLEventHandler(std::function<void(SDL_Event)> function);
		
		static inline SDL_Renderer* getRenderer() {return globalRenderer;}
		
		static inline int getWindowWidth() {return windowWidth;}
		static inline int getWindowHeight() {return windowHeight;}
		
		static void setWindowSize(int width, int height);
};

void loadGUI(std::string filePath);
void setTheme(std::string filePath);
void loadList(std::string listName);
void resetGUI();

UIElement* getHoveredElement(UIElement* element);
bool isInBounds(UIElement element, int x, int y);

void windowLoop();

bool initSDL();
bool loadMedia();
void endSDL();

#endif