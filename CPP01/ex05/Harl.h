#ifndef HARL_H
#define HARL_H
#include <iostream>

class Harl
{
private:
	std::string levels[4];
	void (Harl::*funPtr[4])();
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
