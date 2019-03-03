#ifndef PLAYVIEW_HPP
#define PLAYVIEW_HPP

#include <SFML/Graphics.hpp>
#include <definition.hpp>
#include <views/play/play.hpp>

class PlayView {

private:
	Play m_play;

public:
	PlayView();
	void update(sf::Time& time);
	void render(sf::RenderWindow& window);
	void process_event(sf::Event& event, sf::RenderWindow& window, sf::Time& time, View& view);
};

#endif // PLAYVIEW_HPP
