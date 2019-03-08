#include <SFML/Graphics.hpp>
#include <iostream>

#include <views/play/play.hpp>
#include <definition.hpp>

Play :: Play () : m_window_x(0), m_window_y(0), m_changingScale(true) {
	// Font Initialisation
	if (!m_font.loadFromFile("font.ttf")) {
		std::cout << "Chargement de la police d'écriture impossible" << std::endl;
	}

	// Initialisation
	m_online.setString("En ligne");
	m_local.setString("Local");
	m_training.setString("Training");
	m_back.setString("Retour");
}

void Play :: update(sf::Time& time) {
	if (m_changingScale) {

		updateMainButton(m_online);
		updateUnderButton(m_local, 0);
		updateUnderButton(m_training, 1);
		updateBackButton(m_back);

		m_changingScale = false;
	}
}

void Play :: updateMainButton(TextButton& button) {
	button.setSize(m_window_x, m_window_y, 0.6f, 0.2f);
	button.setPosition(m_window_x*0.5f - button.getBox().getSize().x*0.5f, m_window_y*0.34f);
}

void Play :: updateUnderButton(TextButton& button, int order) {
	button.setSize(m_window_x, m_window_y, 0.29f, 0.15f);
	button.setPosition(m_window_x*0.2f + (m_window_x*0.31f)*order, m_window_y*0.54f + m_window_x * 0.02f);
}

void Play :: updateBackButton(TextButton& button) {
	button.setSize(m_window_x, m_window_y, 0.12f, 0.05f);
	button.setPosition(m_window_x*0.02f, m_window_x*0.02f);
}

void Play :: draw(sf::RenderWindow& window) const {
	// Button
	window.draw(m_online);
	window.draw(m_local);
	window.draw(m_training);
	window.draw(m_back);
}

void Play :: process_event(sf::Event& event, sf::RenderWindow& window, sf::Time& time, View& view) {
	// Window Scale
	if (m_window_x != window.getSize().x || m_window_y != window.getSize().y) {
		m_window_x = window.getSize().x;
		m_window_y = window.getSize().y;
		m_changingScale = true;
	}

	// If the play Button is pressed
	if (m_online.onMouseOver(event, window)) {
		
	} else if (m_local.onMouseOver(event, window)) {
		
	} else if (m_training.onMouseOver(event, window)) {
		
	} else if (m_back.onMouseOver(event, window)) {
		view.previous = view.actual;
		view.actual = MENUVIEW;
	}
}