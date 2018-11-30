#ifndef MENUVIEW_HPP
#define MENUVIEW_HPP

#include <SFML/Graphics.hpp>

class MenuView {

private:
    // Rien pour le moment
    
public:
    MenuView();
    void update(sf::Time& time);
    void render(sf::RenderWindow& window);
    void process_event(sf::Event& event, sf::Time& time);    
};

#endif // MENUVIEW_HPP
