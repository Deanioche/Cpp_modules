#include <string>
#include <iostream>

int main(void)
{
	// PTR과 REF 둘 다 같은 주소(stringHI)를 가진다.
	// 둘의 차이는 포인터 변수는 변수 크기 만큼의 메모리를 사용하고,
	// 레퍼런스는 레퍼런스 변수를 위한 메모리가 필요하지 않다.
	// 단, 함수 인자로 받는 레퍼런스 변수에는 메모리 할당이 일어난다. ( Call Stack 호출 스택이 달라지므로 )
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
