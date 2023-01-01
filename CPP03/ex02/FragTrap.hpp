#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
	public:
		FragTrap(void);
		FragTrap(std::string name);
		FragTrap(const FragTrap& fragtrap);
		~FragTrap(void);
		const FragTrap& operator=(const FragTrap& fragtrap);
		void attack(const std::string& target);
		void highFivesGuys(void);
};

#endif
