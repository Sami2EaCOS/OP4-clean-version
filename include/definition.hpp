#include <SFML/Graphics.hpp>

#ifndef DEFINITION_HPP 
#define DEFINITION_HPP

	// Button Simplification
	struct Button {
		sf::Text text;
		sf::RectangleShape box;
	};

	// View Simplification
	struct View {
		int actual;
		int previous;
	};

	// Base Configuration
	#define AA 8
	#define RESOLUTION_X 1280
	#define RESOLUTION_Y 720
	#define FULLSCREENED true

    // Views
    #define MENUVIEW 0
	#define SETTINGSVIEW 1
	#define PLAYVIEW 2
	#define GAMEVIEW 3

	// Menu Selection
	#define PLAY 1
	#define SETTING 2

	// Configuration File
	#define CONFIG "File/configuration.cfg"

	// Resolution
	#define RESOLUTION_1 720
	#define RESOLUTION_2 1080

#endif // DEFINITION_HPP
