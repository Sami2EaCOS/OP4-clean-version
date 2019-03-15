#include <views/menu/menu.hpp>
#include <definition.hpp>
#include <iostream>
#include <fstream>
#include <sstream>

#include <SFML/Graphics.hpp>
#include <cmath>

Menu :: Menu() : m_window_x(0), m_window_y(0) {
	/*
	std::string key;
	std::ifstream cfg(CONFIG);
	if (cfg.is_open()) {
		while (std::getline(cfg, key, '=')) {
			std::string value;
			std::getline(cfg, value, '\n');
			if (key == "fullscreen") {
				m_fullscreen = std::stoi(value);
			}
		}
		cfg.close();
	}
	else {
		m_fullscreen = true;
	}
	*/

	// Font Initialisation
	if (!m_font.loadFromFile("font.ttf")) {
		std::cout << "Chargement de la police d'écriture impossible" << std::endl;
	}

	// Title Initialisation
	initText(m_title, "OverPowered Puissance 4");

	// Button Initialisation
	this->m_play.setString("Jouer");
	this->m_settings.setString("Options");
	this->m_quit.setString("Quitter");
}

void Menu :: initText(sf::Text& text, std::string str) {
	text.setFont(m_font);
	text.setString(str);
	text.setFillColor(sf::Color::White);
}

void Menu :: update(sf::Time& time, sf::RenderWindow& window) {
	// Window Scale
	if (m_window_x != window.getSize().x || m_window_y != window.getSize().y) {
		m_window_x = window.getSize().x;
		m_window_y = window.getSize().y;


		// Graphic Update
		updateTitle(m_title);

		updateButton(m_play, 0);
		updateButton(m_settings, 1);
		updateButton(m_quit, 2);
	}
}

void Menu :: updateTitle(sf::Text& title) {
	title.setCharacterSize((unsigned int) floor(m_window_y*0.1f));
	sf::FloatRect rect = title.getGlobalBounds();
	title.setPosition(m_window_x*0.5f - rect.width*0.5f, m_window_y*0.15f);
}

void Menu :: updateButton(TextButton& button, int order) {
	button.setSize(m_window_x, m_window_y, 0.35f, 0.08f);
	button.setPosition(m_window_x*0.5f - button.getBox().getSize().x*0.5f, m_window_y*0.4f + (button.getBox().getSize().y + m_window_y * 0.05f)*order);
}


void Menu :: draw(sf::RenderWindow& window) const {
	// Title
	window.draw(m_title);

	// Button
	window.draw(m_play);
	window.draw(m_settings);
	window.draw(m_quit);
}

void Menu :: process_event(sf::Event& event, sf::RenderWindow& window, sf::Time& time, View& view) {
	// If the play Button is pressed
	if (m_play.onMouseOver(event, window)) {
		view.previous = view.actual;
		view.actual = PlayV;
	// Or if the settings Button is pressed
	} else if (m_settings.onMouseOver(event, window)) {
		view.previous = view.actual;
		view.actual = SettingsV;
	// Or if the quit Button is pressed
	} else if (m_quit.onMouseOver(event, window)) {
		window.close();
	}
}