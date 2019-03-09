#include <SFML/Graphics.hpp>

#ifndef BUTTON_HPP
#define BUTTON_HPP

class TextButton : public sf::Drawable {

private:
	// Style
	sf::Font m_font;

	// Piece of Button
	sf::RectangleShape m_box;
	sf::Text m_text;

	// Draw function (Drawable)
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

public:
	TextButton();
	
	// Style function
	void setString(std::string str);
	void setSize(unsigned int window_x, unsigned int window_y, float size_x, float size_y);
	void setPosition(float position_x, float position_y);

	// Event function
	bool onMouseOver(sf::Event& event, sf::RenderWindow& window);

	// Get function
	sf::RectangleShape getBox() const;
};

#endif // BUTTON_HPP
