#include <SFML/Graphics.hpp>

#ifndef DEFINITION_HPP 
#define DEFINITION_HPP

	// View Simplification
	struct View {
		int actual;
		int previous;
	};

	// Views
	enum {
		MenuV = 0,
		SettingsV = 1,
		PlayV = 2,
		ChooseEventV = 3
	};


	constexpr int u = 1;

	// Base Configuration
	#define AA 8
	#define RESOLUTION_X 1280
	#define RESOLUTION_Y 720
	#define FULLSCREENED true

	// Configuration File
	#define CONFIG "File/configuration.cfg"

#endif // DEFINITION_HPP
