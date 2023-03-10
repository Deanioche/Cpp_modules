#ifndef HARL_H
#define HARL_H
#include <iostream>

class Harl
{
private:
	void (Harl::*funPtr[4])();
	std::string levels[4];
	void debug(void);
	void info(void);
	void warning(void);
	void error(void);
public:
	void complain(const std::string level);
	void harlFilter(const std::string level);
	Harl(void);
	~Harl(void);
};

#endif
