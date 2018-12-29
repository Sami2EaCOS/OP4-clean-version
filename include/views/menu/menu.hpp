#ifndef MENU_HPP
#define MENU_HPP

#include <SFML/Graphics.hpp>
#include <iostream>

class Menu {

private:
	sf::Vector2u m_window_size;
	sf::Font m_font;

	// Main text
	sf::Text m_text_title;
	sf::Text m_text_play;
	sf::Text m_text_setting;
	sf::Text m_text_quit;

	int m_selection;

	// Setting Selection Text
	sf::Text m_text_setting_resolution;
	sf::Text m_text_setting_fullscreen;
	bool m_fullscreen;
	sf::Text m_text_setting_antialiasing;

	// Play Selection Text
	sf::Text m_text_play_multiplayer;
	sf::Text m_text_play_training;
	sf::Text m_text_play_tutorial;

public:
	Menu();
	// Loop function
	void draw(sf::RenderWindow& window);
	void play(sf::Event& event, sf::RenderWindow& window);
	void update(sf::RenderWindow& window);

	// Initialisation function
	void initText(sf::Text& text, std::string str);

	// Cursor function
	void mainSelection(sf::Text& text, sf::RenderWindow& window, sf::Event& event);
	void cleanTextColor();

	// Parameter function
	void resizeWindow(sf::RenderWindow& window, int x, int y);
	void resolutionChange(sf::RenderWindow& window, sf::Event& event);
	void resolutionChangeInFile(int x, int y);
	void fullscreenOrNot(sf::RenderWindow& window, sf::Event& event);
	void fullscreenChangeInFile(bool trueOrFalse);
	void antialiasingChange(sf::RenderWindow& window, sf::Event& event);
	void antialiasingChangeInFile(int level);
	void changeWindowForAntialiasing(sf::RenderWindow& window, int level);
};

#endif // MENU_HPP