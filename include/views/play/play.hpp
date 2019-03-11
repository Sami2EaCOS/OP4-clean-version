#include <SFML/Graphics.hpp>
#include <definition.hpp>
#include <tools/textButton.hpp>

#ifndef PLAY_HPP
#define PLAY_HPP

class Play {

private:
	// Style
	sf::Font m_font;

	// Resolution Help
	int m_window_x;
	int m_window_y;
	bool m_changingScale;

	// Button
	TextButton m_online;
	TextButton m_local;
	TextButton m_training;
	TextButton m_back;

public:
	Play();

	// Loop function
	void draw(sf::RenderWindow& window) const;
	void process_event(sf::Event& event, sf::RenderWindow& window, sf::Time& time, View& view);
	void update(sf::Time& time, sf::RenderWindow& window);

	// Update function
	void updateMainButton(TextButton& button);
	void updateUnderButton(TextButton& button, int order);
	void updateBackButton(TextButton& button);
};

#endif // PLAY_HPP
