#ifndef MENUVIEW_HPP
#define MENUVIEW_HPP

#include <SFML/Graphics.hpp>

#include <views/menu/menu.hpp>

class MenuView {

private:
	Menu m_menu;
    
public:
    MenuView();
    void update(sf::RenderWindow& window);
    void render(sf::RenderWindow& window);
    void process_event(sf::Event& event, sf::Time& time, sf::RenderWindow& window);
};

#endif // MENUVIEW_HPP
