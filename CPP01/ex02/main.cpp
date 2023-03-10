#include <iostream>

int main(void)
{
	std::string stringHI = "HI THIS IS BRAIN";
	std::string* stringPTR = &stringHI;
	std::string& stringREF = stringHI;

	std::cout << "The memory address of the string variable: " << &stringHI << std::endl;
	std::cout << "The memory address held by stringPTR: " << stringPTR << std::endl;
	std::cout << "The memory address held by stringREF: " << &stringREF << std::endl;
	std::cout << std::endl;

	std::cout << "The value of the string variable: " << stringHI << std::endl;
	std::cout << "The value pointed to by stringPTR: " << *stringPTR << std::endl;
	std::cout << "The value pointed to by stringREF: " << stringREF << std::endl;
	std::cout << std::endl;

	return (0);
}
