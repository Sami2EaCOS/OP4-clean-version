#include <gameManager.hpp>
#include <SFML/Graphics.hpp>
#include <ctime>

#include <definition.hpp>

GameManager :: GameManager() : m_time(m_clock.restart()) {
    m_settings.antialiasingLevel = 8;
    m_window.create(
        sf::VideoMode(VIDEOWIDTH,VIDEOHEIGHT),
        "OP4",
        sf::Style::Close | sf::Style::Titlebar | sf::Style::Resize,
        m_settings);
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
                break;
            }
        }
        m_window.clear(sf::Color::Black);
        m_window.display();
    }
}
