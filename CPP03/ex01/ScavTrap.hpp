#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
	public:
		ScavTrap(void);
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap& scavtrap);
		~ScavTrap(void);
		const ScavTrap& operator=(const ScavTrap& scavtrap);
		void attack(const std::string& target);
		void guardGate(void) const;
};

#endif
