#ifndef CONFIG_HPP
#define CONFIG_HPP

class Config {

private:
	std::ifstream m_cfgInput;
	std::ofstream m_cfgOutput;

public:
	Config();

	void setup();

	void changeFullScreen(bool state);

	bool getFullScreen();
};

#endif // CONFIG_HPP

