#include <views/menu/menu.hpp>
#include <iostream>
#include <fstream>
#include <sstream>
#include <stateManager.hpp>
#include <definition.hpp>
#include <icon.hpp>

#include <SFML/Graphics.hpp>

Menu :: Menu() : m_window_size(sf::Vector2u(0, 0)), m_selection(0) {
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

	// Font Initialisation
	if (!m_font.loadFromFile("font.ttf")) {
		std::cout << "Chargement de la police d'écriture impossible" << std::endl;
	}

	// Main Text Initialisation
	initText(m_text_title, "OverPowered Puissance 4");
	initText(m_text_play, "Jouer ?");
	initText(m_text_setting, "Option!");
	initText(m_text_quit, "Quitter");

	// Selection Setting Text Initialisation
	initText(m_text_setting_resolution, "Résolution: ");
	initText(m_text_setting_fullscreen, "Plein Ecran: ");
	initText(m_text_setting_antialiasing, "Antialiasing: ");

	// Selection Play Text Initialisation
	initText(m_text_play_multiplayer, "Jouer à plusieurs");
	initText(m_text_play_training, "Entrainement");
	initText(m_text_play_tutorial, "Tutoriel");
}

void Menu :: initText(sf::Text& text, std::string str) {
	text.setFont(m_font);
	text.setString(str);
	text.setFillColor(sf::Color::White);
}

void Menu :: draw(sf::RenderWindow& window) {
	
	// Drawing Menu Text
	window.draw(m_text_title);
	window.draw(m_text_play);
	window.draw(m_text_setting);
	window.draw(m_text_quit);
	
	// Drawing Selection Text
	switch (m_selection) {
	case PLAY:
		window.draw(m_text_play_multiplayer);
		window.draw(m_text_play_training);
		window.draw(m_text_play_tutorial);
		break;

	case SETTING:
		window.draw(m_text_setting_resolution);
		window.draw(m_text_setting_fullscreen);
		window.draw(m_text_setting_antialiasing);
		break;

	default:
		break;
	}
}

void Menu :: play(sf::Event& event, sf::RenderWindow& window) {
	mainSelection(m_text_play, window, event);
	mainSelection(m_text_setting, window, event);
	mainSelection(m_text_quit, window, event);
	resolutionChange(window, event);
	fullscreenOrNot(window, event);
	antialiasingChange(window, event);
}

void Menu :: update(sf::RenderWindow& window) {

	// Resolution Update
	if (window.getSize() != m_window_size) {
		m_window_size = window.getSize();
		int charSizeButton = m_window_size.y * 0.06f;

		// Title
		m_text_title.setCharacterSize(m_window_size.y * 0.1f);

		sf::FloatRect rect_title = m_text_title.getGlobalBounds();
		m_text_title.setPosition(m_window_size.x / 2 - rect_title.width / 2, m_window_size.y * 0.15f);

		// Play Button
		m_text_play.setCharacterSize(charSizeButton);

		sf::FloatRect rect_play = m_text_play.getGlobalBounds();
		m_text_play.setPosition(m_window_size.x / 2 - rect_title.width / 4 - rect_play.width / 2, m_window_size.y / 2);

		// Setting Button
		m_text_setting.setCharacterSize(charSizeButton);

		sf::FloatRect rect_setting = m_text_setting.getGlobalBounds();
		m_text_setting.setPosition(m_window_size.x / 2 - rect_title.width / 4 - rect_setting.width / 2, m_window_size.y / 2 + charSizeButton * 1.5f);

		// Setting Button
		m_text_quit.setCharacterSize(charSizeButton);

		sf::FloatRect rect_quit = m_text_quit.getGlobalBounds();
		m_text_quit.setPosition(m_window_size.x / 2 - rect_title.width / 4 - rect_quit.width / 2, m_window_size.y / 2 + charSizeButton * 3.f);
	
		// Multiplayer Button
		m_text_play_multiplayer.setCharacterSize(charSizeButton);
		m_text_play_multiplayer.setPosition(m_window_size.x / 2, m_window_size.y / 2);

		// Training Button
		m_text_play_training.setCharacterSize(charSizeButton);
		m_text_play_training.setPosition(m_window_size.x / 2, m_window_size.y / 2 + charSizeButton * 1.5f);

		// Training Button
		m_text_play_tutorial.setCharacterSize(charSizeButton);
		m_text_play_tutorial.setPosition(m_window_size.x / 2, m_window_size.y / 2 + charSizeButton * 3.f);

		// Resolution Button
		m_text_setting_resolution.setCharacterSize(charSizeButton);
		m_text_setting_resolution.setPosition(m_window_size.x / 2, m_window_size.y / 2);

		// Resolution String
		std::ostringstream buffer_resolution;
		buffer_resolution << "Resolution: " << m_window_size.x << "x" << m_window_size.y;
		m_text_setting_resolution.setString(buffer_resolution.str());

		// FullScreen Button
		m_text_setting_fullscreen.setCharacterSize(charSizeButton);
		m_text_setting_fullscreen.setPosition(m_window_size.x / 2, m_window_size.y / 2 + charSizeButton * 1.5f);

		// Antialiasing Button
		m_text_setting_antialiasing.setCharacterSize(charSizeButton);
		m_text_setting_antialiasing.setPosition(m_window_size.x / 2, m_window_size.y / 2 + charSizeButton * 3.0f);

		std::ostringstream buffer_antialiasing;
		buffer_antialiasing << "Antialiasing: " << window.getSettings().antialiasingLevel;
		std::cout << window.getSettings().antialiasingLevel << std::endl;
		m_text_setting_antialiasing.setString(buffer_antialiasing.str());
	}

	// FullScreen String
	if (m_fullscreen) {
		m_text_setting_fullscreen.setString("Plein Ecran: Oui");
	} else {
		m_text_setting_fullscreen.setString("Plein Ecran: Non");
	}

	// Selection Update
	if (m_text_play.getFillColor() != sf::Color::White) {
		m_selection = PLAY;
	} else if (m_text_setting.getFillColor() != sf::Color::White) {
		m_selection = SETTING;
	} else if (m_text_quit.getFillColor() != sf::Color::White) {
		window.close();
	} else {
		m_selection = 0;
	}
}

void Menu :: mainSelection(sf::Text& text, sf::RenderWindow& window, sf::Event& event) {
	sf::FloatRect text_rect = text.getGlobalBounds();

	if (text_rect.contains(static_cast<sf::Vector2f>(sf::Mouse::getPosition(window)))) {
		if (event.type == sf::Event::MouseButtonPressed) {
			if (event.mouseButton.button == sf::Mouse::Left) {
				cleanTextColor();
				text.setFillColor(sf::Color::Magenta);
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

void Menu :: resolutionChange(sf::RenderWindow& window, sf::Event& event) {
	sf::FloatRect text_rect = m_text_setting_resolution.getGlobalBounds();
	
	if (text_rect.contains(static_cast<sf::Vector2f>(sf::Mouse::getPosition(window))) && m_selection == SETTING) {
		if (event.type == sf::Event::MouseButtonPressed) {
			if (event.mouseButton.button == sf::Mouse::Left) {
				switch(window.getSize().y) {
				case RESOLUTION_1:
					resizeWindow(window, RESOLUTION_2 * 16 / 9, RESOLUTION_2);
					break;
				case RESOLUTION_2:
					resizeWindow(window, RESOLUTION_1 * 16 / 9, RESOLUTION_1);
					break;
				}
			}
			else if (event.mouseButton.button == sf::Mouse::Right) {
				switch(window.getSize().y) {
				case RESOLUTION_1:
					resizeWindow(window, RESOLUTION_2 * 16 / 9, RESOLUTION_2);
					break;
				case RESOLUTION_2:
					resizeWindow(window, RESOLUTION_1 * 16 / 9, RESOLUTION_1);
					break;
				}
			}
		}
	}
}

void Menu :: fullscreenOrNot(sf::RenderWindow& window, sf::Event& event) {
	sf::FloatRect text_rect = m_text_setting_fullscreen.getGlobalBounds();
	
	if (text_rect.contains(static_cast<sf::Vector2f>(sf::Mouse::getPosition(window))) && m_selection == SETTING) {
		if (event.type == sf::Event::MouseButtonPressed) {
			if (event.mouseButton.button == sf::Mouse::Left || event.mouseButton.button == sf::Mouse::Right) {
				window.close();
				sf::ContextSettings settings;
				settings.antialiasingLevel = 8;
				if (m_fullscreen) {
					window.create(
						sf::VideoMode(m_window_size.x, m_window_size.y),
						"OP4",
						sf::Style::Close | sf::Style::Titlebar,
						settings);
					fullscreenChangeInFile(false);
					m_fullscreen = false;
				} else {
					window.create(
						sf::VideoMode(m_window_size.x, m_window_size.y),
						"OP4",
						sf::Style::Fullscreen,
						settings);
					fullscreenChangeInFile(true);
					m_fullscreen = true;
				}
				window.setFramerateLimit(60);
				window.setIcon(window_icon.width, window_icon.height, window_icon.pixel_data);
			}
		}
	}
	
}

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
	m_text_setting.setFillColor(sf::Color::White);
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

void Menu :: antialiasingChange(sf::RenderWindow& window, sf::Event& event) {
	sf::FloatRect text_rect = m_text_setting_antialiasing.getGlobalBounds();

	if (text_rect.contains(static_cast<sf::Vector2f>(sf::Mouse::getPosition(window))) && m_selection == SETTING) {
		if (event.type == sf::Event::MouseButtonPressed) {
			if (event.mouseButton.button == sf::Mouse::Left) {
				switch (window.getSettings().antialiasingLevel) {
				case 16:
					changeWindowForAntialiasing(window, 0);
					break;
				
				case 8:
					changeWindowForAntialiasing(window, 16);
					break;
				
				case 4:
					changeWindowForAntialiasing(window, 8);
					break;

				case 2:
					changeWindowForAntialiasing(window, 4); 
					break;

				case 0:
					changeWindowForAntialiasing(window, 2);
					break;
				
				default:
					break;
				}
			} else if (event.mouseButton.button == sf::Mouse::Right) {
				switch (window.getSettings().antialiasingLevel) {
				case 16:
					changeWindowForAntialiasing(window, 8);
					break;

				case 8:
					changeWindowForAntialiasing(window, 4);
					break;

				case 4:
					changeWindowForAntialiasing(window, 2);
					break;

				case 2:
					changeWindowForAntialiasing(window, 0);
					break;

				case 0:
					changeWindowForAntialiasing(window, 16);
					break;

				default:
					break;
				}
			}
		}
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

void Menu :: changeWindowForAntialiasing(sf::RenderWindow& window, int level) {
	window.close();
	sf::ContextSettings settings;
	settings.antialiasingLevel = level;
	if (m_fullscreen) {
		window.create(
			sf::VideoMode(window.getSize().x, window.getSize().y),
			"OP4",
			sf::Style::Fullscreen,
			settings);
	}
	else {
		window.create(
			sf::VideoMode(window.getSize().x, window.getSize().y),
			"OP4",
			sf::Style::Close | sf::Style::Titlebar,
			settings);
	}

	window.setFramerateLimit(60);
	window.setIcon(window_icon.width, window_icon.height, window_icon.pixel_data);

	// Antialiasing String

	std::ostringstream buffer_antialiasing;
	buffer_antialiasing << "Antialiasing: " << window.getSettings().antialiasingLevel;
	std::cout << window.getSettings().antialiasingLevel << std::endl;
	m_text_setting_antialiasing.setString(buffer_antialiasing.str());

	antialiasingChangeInFile(level);
}