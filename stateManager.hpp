#ifndef STATEMANAGER_HPP
#define STATEMANAGER_HPP

#include <SFML/Graphics.hpp>

class StateManager {

private:
    int m_current_view;
    
public:
    StateManager();
	
	void update(sf::Time& time);
	void render(sf::RenderWindow& window);
	void process_event(sf::Event& event, sf::Time& time);
	void changeView(int new_view);
}

#endif // STATEMANAGER_HPP
