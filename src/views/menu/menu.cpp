#include <views/menu/menu.hpp>
#include <iostream>
#include <stateManager.hpp>
#include <definition.hpp>

#include <SFML/Graphics.hpp>

Menu :: Menu() : m_window_size(sf::Vector2u(0, 0)) {
	
	// Font Initialisation

	if (!m_font.loadFromFile("font.ttf")) {
		std::cout << "Chargement de la police d'écriture impossible" << std::endl;
	}

	// Text Initialisation

	m_text_title.setFont(m_font);
	m_text_title.setString("Overpowered Puissance 4");
	m_text_title.setFillColor(sf::Color::White);

	m_text_play.setFont(m_font);
	m_text_play.setString("Jouer!");
	m_text_play.setFillColor(sf::Color::White);

	m_text_setting.setFont(m_font);
	m_text_setting.setString("Option");
	m_text_setting.setFillColor(sf::Color::White);
	
}

void Menu :: draw(sf::RenderWindow& window) {
	if (window.getSize() != m_window_size) {
		m_window_size = window.getSize();

		// Title
		m_text_title.setCharacterSize(m_window_size.y * 0.1f);

		sf::FloatRect rect_title = m_text_title.getGlobalBounds();
		m_text_title.setPosition(m_window_size.x / 2 - rect_title.width / 2, m_window_size.y * 0.15f);

		// Play Button
		m_text_play.setCharacterSize(m_window_size.y*0.05f);

		sf::FloatRect rect_play = m_text_play.getGlobalBounds();
		m_text_play.setPosition(m_window_size.x / 2 - rect_title.width / 4 - rect_play.width / 2 , m_window_size.y / 2);

		// Setting Button
		m_text_setting.setCharacterSize(m_window_size.y * 0.05f);

		sf::FloatRect rect_setting = m_text_setting.getGlobalBounds();
		m_text_setting.setPosition(m_window_size.x / 2 - rect_title.width / 4 - rect_setting.width / 2, m_window_size.y / 2 + rect_play.height * 2);

	}

	// Drawing Text
	window.draw(m_text_title);
	window.draw(m_text_play);
	window.draw(m_text_setting);
}

void Menu :: play(sf::Event& event, sf::Time& time) {
	
}

void Menu :: playUpdate(sf::Time& time) {

}
