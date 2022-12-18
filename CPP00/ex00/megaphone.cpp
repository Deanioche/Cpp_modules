#include <iostream>
#include <string>

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (1);
	}
	for (int i = 1; i < argc; i++)
	{
		// str(char *val) val을 str형태로 변환.   
		std::string str(argv[i]);

		// str.length()는 size_t 형을 반환하므로 int로 캐스팅
		for (int j = 0; j < (int)str.length(); j++)
			// toupper는 int형을 반환하므로 char형으로 캐스팅
			std::cout << (char)std::toupper(str[j]);
	}
	std::cout << std::endl;
	return (0);
}