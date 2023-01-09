#include "Serialization.hpp"
#include <iostream>

int main()
{
	Data useless_data;

	useless_data.title = "How to make a cake";
	useless_data.content = "Cake is recommended to order in a cake shop.\nDo not try to make your self.";
	useless_data.price = 5000;

	uintptr_t up = serialize(&useless_data);
	std::cout << "serialized: " << up << std::endl;
	std::cout << "useless data : " << &useless_data << std::endl;
	std::cout << std::endl;

	Data *data = deserialize(up);
	std::cout << "[ " << data->title << " - $"
			<< data->price << " ]\n"
			<< data->content << std::endl;
	std::cout << std::endl;

	std::cout << "&useless_data : " << &useless_data << std::endl;
	std::cout << "data : " << data << std::endl;

	return 0;
}