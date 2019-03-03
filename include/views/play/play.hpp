#ifndef PLAY_HPP
#define PLAY_HPP

#include <SFML/Graphics.hpp>
#include <definition.hpp>

class Play {

private:

public:
	Play();

	// Loop function
	void draw(sf::RenderWindow& window);
	void process_event(sf::Event& event, sf::RenderWindow& window, sf::Time& time, View& view);
	void update(sf::Time& time);
};

#endif // PLAY_HPP
