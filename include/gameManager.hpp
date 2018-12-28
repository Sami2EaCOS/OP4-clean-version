#ifndef GAMEMANAGER_HPP
#define GAMEMANAGER_HPP

#include <SFML/Graphics.hpp>
#include <stateManager.hpp>

class GameManager {

private:
	sf::ContextSettings m_settings;
	sf::Time m_time;
	sf::Clock m_clock;
	sf::Event m_event;
	sf::RenderWindow m_window;
	StateManager m_sm;

public:
	GameManager();
	void run();
};

#endif // GAMEMANAGER_HPP
