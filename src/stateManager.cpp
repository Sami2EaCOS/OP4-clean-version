#include <stateManager.hpp>

#include <SFML/Graphics.hpp>
#include <definition.hpp>

StateManager::StateManager() : m_current_view({MenuV, MenuV}) {

}

void StateManager :: update(sf::Time& time, sf::RenderWindow& window) {
    switch (m_current_view.actual) {
    case MenuV:
		m_mv.update(time, window);
		break;
	case SettingsV:
		break;
	case PlayV:
		m_pv.update(time, window);
		break;
    }
}

void StateManager :: render(sf::RenderWindow& window) {
    switch (m_current_view.actual) {
    case MenuV:
		m_mv.render(window);
        break;
	case SettingsV:
		break;
	case PlayV:
		m_pv.render(window);
		break;
    }
}

void StateManager :: process_event(sf::Event& event, sf::RenderWindow& window, sf::Time& time) {
    switch (m_current_view.actual) {
    case MenuV:
		m_mv.process_event(event, window, time, m_current_view);
        break;
	case SettingsV:
		break;
	case PlayV:
		m_pv.process_event(event, window, time, m_current_view);
		break;
    }
}
