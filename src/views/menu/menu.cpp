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
	initButton(m_play, "Jouer");
	initButton(m_settings, "Option");
	initButton(m_quit, "Quitter");
}

void Menu :: initButton(Button& button, std::string str) {
	button.box.setFillColor(sf::Color::Black);
	button.box.setOutlineColor(sf::Color::White);

	initText(button.text, str);
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

		m_changingScale = false;
	}
}

void Menu :: updateTitle(sf::Text& title) {
	title.setCharacterSize(floor(m_window_y*0.1f));
	sf::FloatRect rect = title.getGlobalBounds();
	title.setPosition(m_window_x*0.5f - rect.width*0.5f, m_window_y*0.15f);
}

void Menu :: updateButton(Button& button, int i) {
	// Box Setup
	button.box.setOutlineThickness(m_window_y*0.005f);
	button.box.setSize(sf::Vector2f(m_window_x*0.35f, m_window_y*0.08f));
	button.box.setPosition(m_window_x*0.5f - button.box.getSize().x*0.5f, m_window_y*0.4f + (button.box.getSize().y + m_window_y * 0.05f)*i);

	// Text Setup
	button.text.setCharacterSize(floor(m_window_y*0.06f));
	sf::FloatRect rect = button.text.getGlobalBounds();
	button.text.setPosition(m_window_x*0.5f - rect.width*0.5f, m_window_y*0.4f + (button.box.getSize().y + m_window_y * 0.05f)*i);
}

void Menu :: draw(sf::RenderWindow& window) {
	if (m_window_x != window.getSize().x || m_window_y != window.getSize().y) {
		m_window_x = window.getSize().x;
		m_window_y = window.getSize().y;
		m_changingScale = true;
	}

	// Title
	window.draw(m_title);

	// Button
	drawButton(m_play, window);
	drawButton(m_settings, window);
	drawButton(m_quit, window);

}

void Menu :: drawButton(Button& button, sf::RenderWindow& window) {
	window.draw(button.box);
	window.draw(button.text);
}

void Menu :: process_event(sf::Event& event, sf::RenderWindow& window, sf::Time& time, View& view) {
	// If the play Button is pressed
	if (onMouseOverButton(m_play, event, window)) {
		view.previous = view.actual;
		view.actual = PLAYVIEW;
	// Or if the settings Button is pressed
	} else if (onMouseOverButton(m_settings, event, window)) {
		view.previous = view.actual;
		view.actual = SETTINGSVIEW;
	// Or if the quit Button is pressed
	} else if (onMouseOverButton(m_quit, event, window)) {
		window.close();
	}
}

bool Menu :: onMouseOverButton(Button& button, sf::Event& event, sf::RenderWindow& window) {
	// Definition on a box with the Button with in
	sf::IntRect rect(button.box.getPosition().x, button.box.getPosition().y, button.box.getGlobalBounds().width, button.box.getGlobalBounds().height);

	// Check if the mouse is in the box
	if (rect.contains(sf::Mouse::getPosition(window))) {
		button.box.setFillColor(sf::Color::Color(40, 40, 40, 255));
		if (event.type == sf::Event::MouseButtonReleased) {
			// If the mouse has been pressed, return true
			if (event.mouseButton.button == sf::Mouse::Left) {
				return true;
			}
		}
	} else {
		button.box.setFillColor(sf::Color::Black);
	}
	// If not, return false
	return false;
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