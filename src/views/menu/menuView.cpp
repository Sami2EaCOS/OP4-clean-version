#include <views/menu/menuView.hpp>
#include <SFML/Graphics.hpp>

MenuView :: MenuView() {

}

void MenuView :: update(sf::Time& time) {
	m_menu.update(time);
}

void MenuView :: render(sf::RenderWindow& window) {
	m_menu.draw(window);
}

void MenuView :: process_event(sf::Event& event, sf::RenderWindow& window, sf::Time& time, View& view) {
	m_menu.process_event(event, window, time, view);
}
