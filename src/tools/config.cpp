#include <tools/config.hpp>
#include <fstream>
#include <iostream>
#include <sstream>
#include <experimental/filesystem>
#include <definition.hpp>

Config :: Config () {
	m_cfgInput.open(CONFIG);

	if (!(m_cfgInput.is_open())) {
		setup();
	}

	m_cfgInput.close();
}

void Config :: setup() {
	// Create directory
	if (!(std::experimental::filesystem::exists("File"))) {
		std::experimental::filesystem::create_directory("File");
	}

	// Open the file
	m_cfgOutput.open(CONFIG);

	// In file
	m_cfgOutput << "player=" << "none" << std::endl;
	m_cfgOutput << "level=" << 0 << std::endl;
	m_cfgOutput << "fullscreen=" << true << std::endl;

	// Close file
	m_cfgOutput.close();
}

void Config :: changeFullScreen(bool state) {
	// Buffer creation
	std::ostringstream buffer;
	
	// Open the file
	m_cfgInput.open(CONFIG);

	// Write information with update in the buffer
	std::string key;
	if (m_cfgInput.is_open()) {
		while (std::getline(m_cfgInput, key, '=')) {
			std::string value;
			std::getline(m_cfgInput, value, '\n');

			// If it's the right key, change the value, else not
			if (key == "fullscreen") {
				buffer << key << '=' << state << std::endl;
			} else {
				buffer << key << '=' << value << std::endl;
			}
		}
		m_cfgInput.close();
		
		// Rewrite the file with updated information
		m_cfgOutput.open(CONFIG);
		m_cfgOutput << buffer.str();
		m_cfgOutput.close();
	
		// If the file is not open, error
	} else {
		std::cout << "Impossible d'ouvrir le fichier" << std::endl;
	}
}

bool Config :: getFullScreen() {
	// Open the file to write in
	m_cfgInput.open(CONFIG);

	// Trying to found the value in the file
	std::string key;
	while (std::getline(m_cfgInput, key, '=')) {
		std::string value;
		if (key == "fullscreen") {
			std::getline(m_cfgInput, value, '\n');
			
			m_cfgInput.close();
			return std::stoi(value);
		}
	}

	// If we can't, send something generic
	m_cfgInput.close();
	return false;
}