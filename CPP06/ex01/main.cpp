#include "Serialization.hpp"
#include <iostream>

int main()
{
	Data labour;

	labour.name = "labour";
	labour.height = 190;
	labour.job = "student";

	uintptr_t up = serialize(&labour);
	std::cout << "serialized: " << up << std::endl;

	Data *data = deserialize(up);
	std::cout << data->name << ", " << data->height << ", " << data->job << std::endl;

	return 0;
}