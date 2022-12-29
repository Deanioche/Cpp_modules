#include "Weapon.h"

Weapon::Weapon(const std::string type) : typeName(type) {}

Weapon::~Weapon(void){}

const std::string& Weapon::getType(void) const 
{ 
    return (this->typeName); 
}

void Weapon::setType(const std::string type) 
{ 
    this->typeName = type; 
}
