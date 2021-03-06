#ifndef STATEMANAGER_HPP
#define STATEMANAGER_HPP

#include <SFML/Graphics.hpp>

#include <definition.hpp>
#include <views/menu/menuView.hpp>
#include <views/play/playView.hpp>

class StateManager {

private:
	// Information for actual view
    View m_current_view;

	// Information for the game
	int* choiceEvent;

	// Views
	MenuView m_mv;
	PlayView m_pv;
    
public:
    StateManager();
    void update(sf::Time& time, sf::RenderWindow& window);
    void render(sf::RenderWindow& window);
    void process_event(sf::Event& event, sf::RenderWindow& window, sf::Time& time);
};

#endif // STATEMANAGER_HPP
