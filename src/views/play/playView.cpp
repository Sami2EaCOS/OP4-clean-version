#include <views/play/playView.hpp>

#include <definition.hpp>
#include <SFML/Graphics.hpp>

PlayView :: PlayView() {

}

void PlayView :: update(sf::Time& time, sf::RenderWindow& window) {
	m_play.update(time, window);
}

void PlayView :: render(sf::RenderWindow& window) {
	m_play.draw(window);
}

void PlayView :: process_event(sf::Event& event, sf::RenderWindow& window, sf::Time& time, View& view) {
	m_play.process_event(event, window, time, view);
}