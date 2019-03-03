#ifndef MENU_HPP
#define MENU_HPP

#include <SFML/Graphics.hpp>
#include <definition.hpp>

class Menu {

private:
	// Resolution Help
	int m_window_x;
	int m_window_y;
	bool m_changingScale;

	// Style
	sf::Font m_font;

	// Title
	sf::Text m_title;

	// Button
	Button m_play;
	Button m_settings;
	Button m_quit;

public:
	Menu();

	// Loop function
	void draw(sf::RenderWindow& window);
	void process_event(sf::Event& event, sf::RenderWindow& window, sf::Time& time, View& view);
	void update(sf::Time& time);

	// Initialisation function
	void initText(sf::Text& text, std::string str);
	void initButton(Button& button, std::string str);

	// Update function
	void updateTitle(sf::Text& title);
	void updateButton(Button& button, int i);

	// Draw function
	void drawButton(Button& button, sf::RenderWindow& window);

	// Button function
	bool onMouseOverButton(Button& button, sf::Event& event, sf::RenderWindow& window);
};

#endif // MENU_HPP