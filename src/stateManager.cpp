#include "stateManager.hpp"

#include <SFML/Graphics.hpp>

#include "definition.hpp"

StateManager :: StateManager() : m_current_view(MENUVIEW) {

}

void StateManager :: update(sf::Time& time) {
    switch (m_current_view) {
    case MENUVIEW:
        break;
    }
}

void StateManager :: render(sf::RenderWindow& window) {
    switch (m_current_view) {
    case MENUVIEW:
        break;
    }
}

void StateManager :: process_event(sf::Event& event, sf::Time& time) {
    switch (m_current_view) {
    case MENUVIEW:
        break;
    }
}

void StateManager :: changeView(int new_view) {
    m_current_view = new_view;
}
