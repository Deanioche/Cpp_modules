#ifndef HARL_H
#define HARL_H
#include <iostream>
// #include <string>

class Harl
{
private:
	std::string levels[4];
	void (Harl::*harl_complains[4])();
	void debug(void);
	void info(void);
	void warning(void);
	void error(void);
public:
	void complain(std::string level);
	Harl(void);
	~Harl(void);
};

#endif
