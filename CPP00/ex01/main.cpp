#include "PhoneBook.h"

int main()
{
	std::string input;
	PhoneBook phoneBook;

	std::cout << "type ADD, SEARCH, EXIT: " << std::endl;
	while (1)
	{
		// stdin 한줄 입력 받기
		// std::cin 으로 받으면 ' '(스페이스)를 기준으로 한 단어만 받는다.
		// "ADD sadsadsa"같이 공백을 사이로 두고 정상 입력과 의도되지 않은 입력까지 처리를 하려면 getline을 이용해 한 줄을 전부 받아야 한다.
		std::getline(std::cin, input);

		// error bit가 여러 종류가 있는데, 하나라도 조건에 걸리면 1 반환.
		// cin.clear()는 그 에러비트를 초기화하는 것. stdin 으로 입력된 문자열이 담긴 버퍼와는 관련 없다.
		// 이 코드에서 fail()이 발생할만한 상황은 stdin입력 상황에서 ctrl^d로 eof를 입력했을 때.
		if (std::cin.fail())
		{
			std::cout << "Error : cin failed." << std::endl;
			exit(1); // 에러 플래그와 함께 종료.
		}
		if (input == "EXIT")
			exit(0); // 정상 종료
		else if (input == "ADD")
			phoneBook.add();
		else if (input == "SEARCH")
			phoneBook.search();
		std::cout << "type ADD, SEARCH, EXIT: " << std::endl;
	}
	return (0);
}
