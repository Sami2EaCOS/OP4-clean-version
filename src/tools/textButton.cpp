#include <tools/textButton.hpp>
#include <iostream>

TextButton :: TextButton() {
	// Font Initialisation
	if (!m_font.loadFromFile("font.ttf")) {
		std::cout << "Chargement de la police d'écriture impossible" << std::endl;
	}

	// Box init
	m_box.setFillColor(sf::Color::Black);
	m_box.setOutlineColor(sf::Color::White);

	// Text init
	m_text.setFont(m_font);
	m_text.setFillColor(sf::Color::White);
}

void TextButton :: setString(std::string str) {
	m_text.setString(str);
}

void TextButton :: setOutlineThickness(float border) {
	m_box.setOutlineThickness(border*0.005f);
}

void TextButton :: setSize(float size_x, float size_y) {
	// Box Size
	m_box.setSize(sf::Vector2f(size_x, size_y));

	// Text Size
	m_text.setCharacterSize((unsigned int) floor(size_y*0.75f));
}

void TextButton :: setPosition(float position_x, float position_y) {
	// Box Position
	m_box.setPosition(position_x, position_y);

	// Text Position
	sf::FloatRect rect = m_text.getGlobalBounds();
	m_text.setPosition(m_box.getPosition().x - rect.width*0.5f + m_box.getSize().x*0.5f, m_box.getPosition().y);
}

bool TextButton :: onMouseOver(sf::Event& event, sf::RenderWindow& window) {
	// Definition on a box with the Button with in
	sf::IntRect rect(m_box.getPosition().x, m_box.getPosition().y, m_box.getGlobalBounds().width, m_box.getGlobalBounds().height);

	// Check if the mouse is in the box
	if (rect.contains(sf::Mouse::getPosition(window))) {
		m_box.setFillColor(sf::Color::Color(40, 40, 40, 255));
		if (event.type == sf::Event::MouseButtonReleased) {
			// If the mouse has been pressed, return true
			if (event.mouseButton.button == sf::Mouse::Left) {
				return true;
			}
		}
	}
	else {
		m_box.setFillColor(sf::Color::Black);
	}
	// If not, return false
	return false;
}

void TextButton :: draw(sf::RenderTarget& target, sf::RenderStates states) const {
	target.draw(m_box, states);
	target.draw(m_text, states);
}

sf::RectangleShape TextButton :: getBox() const {
	return m_box;
}
