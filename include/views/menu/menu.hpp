#ifndef MENU_HPP
#define MENU_HPP

#include <SFML/Graphics.hpp>

class Menu {

private:
	sf::Vector2u m_window_size;
	sf::Font m_font;
	sf::Text m_text_title;
	sf::Text m_text_play;
	sf::Text m_text_setting;

public:
	Menu();
	void draw(sf::RenderWindow& window);
	void play(sf::Event& event, sf::Time& time);
	void playUpdate(sf::Time& time);
};

#endif // MENU_HPP