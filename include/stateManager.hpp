#ifndef STATEMANAGER_HPP
#define STATEMANAGER_HPP

#include <SFML/Graphics.hpp>

#include <views/menu/menuView.hpp>

class StateManager {

private:
    int m_current_view;
	MenuView m_mv;
    
public:
    StateManager();
    void update(sf::Time& time, sf::RenderWindow& window);
    void render(sf::RenderWindow& window);
    void process_event(sf::Event& event, sf::Time& time, sf::RenderWindow& window);
    void changeView(int new_view);
};

#endif // STATEMANAGER_HPP
