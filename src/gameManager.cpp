#include <gameManager.hpp>
#include <stateManager.hpp>
#include <SFML/Graphics.hpp>
#include <ctime>

#include <definition.hpp>
#include <icon.hpp>

GameManager :: GameManager() : m_time(m_clock.restart()) {
    m_settings.antialiasingLevel = 8;
    m_window.create(
        sf::VideoMode(VIDEOWIDTH, VIDEOHEIGHT),
        "OP4",
        sf::Style::Close | sf::Style::Titlebar,
        m_settings);
	m_window.setFramerateLimit(60);
	m_window.setIcon(window_icon.width, window_icon.height, window_icon.pixel_data);
}

void GameManager :: run() {
    while (m_window.isOpen()) {
        while (m_window.pollEvent(m_event)) {
            switch(m_event.type) {
            case sf::Event::Closed:
                m_window.close();
                break;
            case sf::Event::Resized:
                break;
            default:
				m_sm.process_event(m_event, m_time);
                break;
            }
        }
		m_sm.update(m_time);

        m_window.clear(sf::Color::Black);
		m_sm.render(m_window);
        m_window.display();
    }
}
