#include <views/menu/menuView.hpp>
#include <views/menu/menu.hpp>

#include <SFML/Graphics.hpp>

MenuView :: MenuView() {

}

void MenuView :: update(sf::Time& time) {
	m_menu.playUpdate(time);
}

void MenuView :: render(sf::RenderWindow& window) {
	m_menu.draw(window);
}

void MenuView :: process_event(sf::Event& event, sf::Time& time) {
	m_menu.play(event, time);
}
