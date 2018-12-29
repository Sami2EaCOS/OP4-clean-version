#include <gameManager.hpp>
#include <stateManager.hpp>
#include <SFML/Graphics.hpp>
#include <ctime>
#include <fstream>
#include <iostream>
#include <experimental/filesystem>

#include <definition.hpp>
#include <icon.hpp>

GameManager :: GameManager() : m_time(m_clock.restart()) {
	
	std::string key;
	std::ifstream cfg(CONFIG);
	if (cfg.is_open()) {
		while (std::getline(cfg, key, '=')) {
			std::string value;
			if (key == "antialiasing") {
				std::getline(cfg, value, '\n');
				m_settings.antialiasingLevel = std::stoi(value);

			} else if (key == "resolution") {
				// X
				std::getline(cfg, value, 'x');
				m_width = std::stoi(value);

				// Y
				std::getline(cfg, value, '\n');
				m_height = std::stoi(value);

			} else if (key == "fullscreen") {
				std::getline(cfg, value, '\n');
				m_fullscreen = std::stoi(value);

			}
		}
		cfg.close();
	} else {
		if (!(std::experimental::filesystem::exists("File"))) {
			std::experimental::filesystem::create_directory("File");
		}

		std::ofstream cfgNew;
		cfgNew.open(CONFIG);
		cfgNew << "antialiasing=" << 8 << std::endl;
		m_settings.antialiasingLevel = AA;

		cfgNew << "resolution=" << RESOLUTION_X << 'x' << RESOLUTION_Y << std::endl;
		m_width = RESOLUTION_X;
		m_height = RESOLUTION_Y;

		cfgNew << "fullscreen=" << FULLSCREENED << std::endl;
		m_fullscreen = FULLSCREENED;

		cfgNew.close();
	}

	if (m_fullscreen) {
		m_window.create(
			sf::VideoMode(m_width, m_height),
			"OP4",
			sf::Style::Fullscreen,
			m_settings);
		m_window.setFramerateLimit(60);
		m_window.setIcon(window_icon.width, window_icon.height, window_icon.pixel_data);
	} else {
		m_window.create(
			sf::VideoMode(m_width, m_height),
			"OP4",
			sf::Style::Close | sf::Style::Titlebar,
			m_settings);
		m_window.setFramerateLimit(60);
		m_window.setIcon(window_icon.width, window_icon.height, window_icon.pixel_data);
	}
}

void GameManager :: run() {
    while (m_window.isOpen()) {
        while (m_window.pollEvent(m_event)) {
            switch(m_event.type) {
            case sf::Event::Closed:
				m_window.close();
				break;

            default:
				m_sm.process_event(m_event, m_time, m_window);
                break;
            }
        }
		m_sm.update(m_time, m_window);

        m_window.clear(sf::Color::Black);
		m_sm.render(m_window);
        m_window.display();
    }
}