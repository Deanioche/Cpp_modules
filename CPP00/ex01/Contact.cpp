#include "Contact.h"

void Contact::putContact(int i, const std::string data)
{ 
	contact[i] = data; 
}

std::string Contact::getContact(int i) const
{ 
	return (contact[i]);
}
