#include "Weapon.h"

Weapon::Weapon(const std::string& _type) : type(_type) {}

const std::string& Weapon::getType() const 
{ 
    return ((const std::string& )type); 
}

void Weapon::setType(const std::string& _type) 
{ 
    type = _type; 
}
