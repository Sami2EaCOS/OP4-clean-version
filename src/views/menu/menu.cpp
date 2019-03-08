#include <views/menu/menu.hpp>
#include <definition.hpp>
#include <iostream>
#include <fstream>
#include <sstream>

#include <SFML/Graphics.hpp>
#include <cmath>

Menu :: Menu() : m_window_x(0), m_window_y(0), m_changingScale(true) {
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

void Menu :: update(sf::Time& time) {
	if (m_changingScale) {
		updateTitle(m_title);

		updateButton(m_play, 0);
		updateButton(m_settings, 1);
		updateButton(m_quit, 2);

		this->m_changingScale = false;
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
	if (m_window_x != window.getSize().x || m_window_y != window.getSize().y) {
		this->m_window_x = window.getSize().x;
		this->m_window_y = window.getSize().y;
		this->m_changingScale = true;
	}

	// If the play Button is pressed
	if (m_play.onMouseOver(event, window)) {
		view.previous = view.actual;
		view.actual = PLAYVIEW;
	// Or if the settings Button is pressed
	} else if (m_settings.onMouseOver(event, window)) {
		view.previous = view.actual;
		view.actual = SETTINGSVIEW;
	// Or if the quit Button is pressed
	} else if (m_quit.onMouseOver(event, window)) {
		window.close();
	}
}

/*
void Menu :: mainSelection(sf::Text& text, sf::RenderWindow& window, sf::Event& event) {
	sf::FloatRect text_rect = text.getGlobalBounds();

	if (text_rect.contains(static_cast<sf::Vector2f>(sf::Mouse::getPosition(window)))) {
		if (event.type == sf::Event::MouseButtonPressed) {
			if (event.mouseButton.button == sf::Mouse::Left) {
				cleanTextColor();
				text.setFillColor(sf::Color::Yellow);
			}
			else if (event.mouseButton.button == sf::Mouse::Right) {
				text.setFillColor(sf::Color::White);
			}
		}
		text.setOutlineThickness(5);
		text.setOutlineColor(sf::Color::Red);
	} else {
		text.setOutlineThickness(0);
	}
}

/*
void Menu :: resizeWindow(sf::RenderWindow& window, int x, int y) {
	window.close();
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;
	if (m_fullscreen) {
		window.create(
			sf::VideoMode(x, y),
			"OP4",
			sf::Style::Fullscreen,
			settings);
	} else {
		window.create(
			sf::VideoMode(x, y),
			"OP4",
			sf::Style::Close | sf::Style::Titlebar,
			settings);
	}
	
	window.setFramerateLimit(60);
	window.setIcon(window_icon.width, window_icon.height, window_icon.pixel_data);

	resolutionChangeInFile(x, y);
}

void Menu :: cleanTextColor() {
	m_text_play.setFillColor(sf::Color::White);
	m_text_settings.setFillColor(sf::Color::White);
	m_text_quit.setFillColor(sf::Color::White);
}

void Menu :: fullscreenChangeInFile(bool trueOrFalse) {
	std::ostringstream buffer;
	std::string key;
	std::ifstream cfgInput(CONFIG);
	if (cfgInput.is_open()) {
		while (std::getline(cfgInput, key, '=')) {
			std::string value;
			std::getline(cfgInput, value, '\n');
			if (key == "fullscreen") {
				buffer << key << '=' << trueOrFalse << std::endl;
			} else {
				buffer << key << '=' << value << std::endl;
			}
		}
		cfgInput.close();
		std::ofstream cfgOutput;
		cfgOutput.open(CONFIG);
		cfgOutput << buffer.str();

	}
	else {
		std::cout << "Impossible d'ouvrir le fichier" << std::endl;
	}
}

void Menu :: resolutionChangeInFile(int x, int y) {
	std::ostringstream buffer;
	std::string key;
	std::ifstream cfgInput(CONFIG);
	if (cfgInput.is_open()) {
		while (std::getline(cfgInput, key, '=')) {
			std::string value;
			std::getline(cfgInput, value, '\n');
			if (key == "resolution") {
				buffer << key << '=' << x << 'x' << y << std::endl;
			} else {
				buffer << key << '=' << value << std::endl;
			}
		}
		cfgInput.close();
		std::ofstream cfgOutput;
		cfgOutput.open(CONFIG);
		cfgOutput << buffer.str();
	}
	else {
		std::cout << "Impossible d'ouvrir le fichier" << std::endl;
	}
}

void Menu :: antialiasingChangeInFile(int level) {
	std::ostringstream buffer;
	std::string key;
	std::ifstream cfgInput(CONFIG);
	if (cfgInput.is_open()) {
		while (std::getline(cfgInput, key, '=')) {
			std::string value;
			std::getline(cfgInput, value, '\n');
			if (key == "antialiasing") {
				buffer << key << '=' << level << std::endl;
			} else {
				buffer << key << '=' << value << std::endl;
			}
		}
		cfgInput.close();
		std::ofstream cfgOutput;
		cfgOutput.open(CONFIG);
		cfgOutput << buffer.str();
	}
	else {
		std::cout << "Impossible d'ouvrir le fichier" << std::endl;
	}
}

*/