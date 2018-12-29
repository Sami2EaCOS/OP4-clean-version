#include <views/menu/menuView.hpp>
#include <views/menu/menu.hpp>

#include <SFML/Graphics.hpp>

MenuView :: MenuView() {

}

void MenuView :: update(sf::RenderWindow& window) {
	m_menu.update(window);
}

void MenuView :: render(sf::RenderWindow& window) {
	m_menu.draw(window);
}

void MenuView :: process_event(sf::Event& event, sf::Time& time, sf::RenderWindow& window) {
	m_menu.play(event, window);
}
