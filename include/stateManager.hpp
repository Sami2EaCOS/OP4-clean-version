#ifndef STATEMANAGER_HPP
#define STATEMANAGER_HPP

#include <SFML/Graphics.hpp>

#include <definition.hpp>
#include <views/menu/menuView.hpp>
#include <views/play/playView.hpp>

class StateManager {

private:
    View m_current_view;
	MenuView m_mv;
	PlayView m_pv;
    
public:
    StateManager();
    void update(sf::Time& time);
    void render(sf::RenderWindow& window);
    void process_event(sf::Event& event, sf::RenderWindow& window, sf::Time& time);
};

#endif // STATEMANAGER_HPP
