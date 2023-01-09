#ifndef SERIALIZATION_HPP
#define SERIALIZATION_HPP

#include <string>

typedef struct
{
	std::string name;
	std::string job;
	int height;
} Data;

uintptr_t serialize(Data *ptr);
Data *deserialize(uintptr_t raw);

#endif