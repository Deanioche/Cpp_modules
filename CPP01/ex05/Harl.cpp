#include "Harl.h"

Harl::Harl(void)
{
    funPtr[0] = &Harl::debug;
    funPtr[1] = &Harl::info;
    funPtr[2] = &Harl::warning;
    funPtr[3] = &Harl::error;
    levels[0] = "DEBUG";
    levels[1] = "INFO";
    levels[2] = "WARNING";
    levels[3] = "ERROR";
}

void Harl::debug(void)
{
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!"
            << std::endl;
}

void Harl::info(void)
{
    std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! "
            "If you did, I wouldn't be asking for more!"
            << std::endl;
}

void Harl::warning(void)
{
    std::cout << "I think I deserve to have some extra bacon for free. I've been coming for "
            "years whereas you started working here since last month."
            << std::endl;
}

void Harl::error(void)
{
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level)
{
	int lv = (level == "DEBUG") * 1 \
				+ (level == "INFO") * 2 \
				+ (level == "WARNING") * 3 \
				+ (level == "ERROR") * 4;
	if (lv == 0) {
		std::cout << "Error: invalid complain\n";
		return ;
	}
	(this->*funPtr[lv - 1])();
}

Harl::~Harl(void) {}
