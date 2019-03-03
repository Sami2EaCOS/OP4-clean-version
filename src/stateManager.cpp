#include <stateManager.hpp>

#include <SFML/Graphics.hpp>
#include <definition.hpp>

StateManager::StateManager() : m_current_view({MENUVIEW, MENUVIEW}) {

}

void StateManager :: update(sf::Time& time) {
    switch (m_current_view.actual) {
    case MENUVIEW:
		m_mv.update(time);
		break;
	case SETTINGSVIEW:
		break;
	case PLAYVIEW:
		m_pv.update(time);
		break;
	case GAMEVIEW:
		break;
    }
}

void StateManager :: render(sf::RenderWindow& window) {
    switch (m_current_view.actual) {
    case MENUVIEW:
		m_mv.render(window);
        break;
	case SETTINGSVIEW:
		break;
	case PLAYVIEW:
		m_pv.render(window);
		break;
	case GAMEVIEW:
		break;
    }
}

void StateManager :: process_event(sf::Event& event, sf::RenderWindow& window, sf::Time& time) {
    switch (m_current_view.actual) {
    case MENUVIEW:
		m_mv.process_event(event, window, time, m_current_view);
        break;
	case SETTINGSVIEW:
		break;
	case PLAYVIEW:
		m_pv.process_event(event, window, time, m_current_view);
		break;
	case GAMEVIEW:
		break;
    }
}
