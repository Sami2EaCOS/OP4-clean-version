#ifndef MENU_HPP
#define MENU_HPP

#include <SFML/Graphics.hpp>
#include <definition.hpp>
#include <tools/textButton.hpp>

class Menu {

private:
	// Resolution Help
	unsigned int m_window_x;
	unsigned int m_window_y;

	// Style
	sf::Font m_font;

	// Title
	sf::Text m_title;

	// Button
	TextButton m_play;
	TextButton m_settings;
	TextButton m_quit;

public:
	Menu();

	// Loop function
	void draw(sf::RenderWindow& window) const;
	void process_event(sf::Event& event, sf::RenderWindow& window, sf::Time& time, View& view);
	void update(sf::Time& time, sf::RenderWindow& window);

	// Initialisation function
	void initText(sf::Text& text, std::string str);

	// Update function
	void updateTitle(sf::Text& title);
	void updateButton(TextButton& button, int order);
};

#endif // MENU_HPP