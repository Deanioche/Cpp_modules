#include "Weapon.h"

Weapon::Weapon(const std::string type) : type_name(type) {}

Weapon::~Weapon(void){}

const std::string& Weapon::getType(void) const 
{ 
    return (this->type_name); 
}

void Weapon::setType(const std::string type) 
{ 
    this->type_name = type; 
}
