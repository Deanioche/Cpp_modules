#ifndef SERIALIZATION_HPP
#define SERIALIZATION_HPP

#include <string>

typedef struct
{
	std::string title;
	std::string content;
	int price;
} Data;

uintptr_t serialize(Data *ptr);
Data *deserialize(uintptr_t raw);

#endif