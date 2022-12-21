#include "PhoneBook.h"

// 생성자에서 변수들 초기화.
PhoneBook::PhoneBook()
{
	idx = 0;
	fields[0] = "first name";
	fields[1] = "last name";
	fields[2] = "nickname";
	fields[3] = "phone number";
	fields[4] = "darkest secret";

	// ###########################################################
	// 테스트용 
	// 더미 값 7개 넣기.
	for (int i = 0; i < 7; i++)
	{
		contacts[i].putContact(0, std::to_string(i) + "abcdef");
		for (int j = 1; j < 5; j++)
		{
			contacts[i].putContact(j, "0123456789abcdef");
		}
		idx = (idx + 1) % 8;
	}
	// 평가 전 삭제 필요
	// ###########################################################
}

// 위 다섯가지 항목 순서대로 입력받아 새로운 연락처 생성 및 저장.
void PhoneBook::add()
{
	for (int i = 0; i < 5; i++)
	{
		std::string input;
		std::cout << fields[i] << ": " << std::endl;

		// input이 비었다는건 값을 아직 안받았다는 것.
		while (input.empty())
		{
			std::getline(std::cin, input);

			// error bit가 1이 되면 프로그램 종료
			if (std::cin.fail())
			{
				std::cout << "Error : cin failed." << std::endl;
				exit(1);
			}
			
			// 입력된 문자열에서 앞 뒤로 공백 trim.
			// erase(idx, len) 는 idx 부터 len개 만큼 지운다.
			input = input.erase(0, input.find_first_not_of(' '));
			input = input.erase(input.find_last_not_of(' ') + 1, input.length() - input.find_last_not_of(' ') - 1);

			// i가 3이라는 건 phone number를 받을 때.
			if (i == 3)
			{
				std::string::size_type j = 0;

				// 각 문자가 숫자, +, -가 아니면 for문을 종료시키고 j를 더이상 상승시키지 않음.
				for (; j < input.length(); j++)
					if (!std::isdigit(input.at(j)) && input.at(j) != '+' && input.at(j) != '-')
						break;

				// j가 문자열 길이만큼 상승되지 않았으면 에러 메세지 출력 및 i를 1 감소시켜, phone number를 재입력 받도록 한다.
				if (j < input.length())
				{
					std::cout << "Error : Only digit, '+', '-' are acceptable." << std::endl;
					i--;
					continue;
				}
			}
		}
		// 연락처의 5가지 항목 중, 이번에 입력받은 하나 저장. (이걸 5번 반복)
		contacts[idx].putContact(i, input);
	}
	// 연락처 하나 입력이 끝난 후, idx를 올리는데, 8 이상이 되면 0부터 다시 증가한다.
	idx = (idx + 1) % 8;
}

// search는 PhoneBook 클래스의 멤버 변수의 수정이 없으므로 맨 뒤에 const가 붙는다.
void PhoneBook::search() const
{
	// 0번 연락처의 0번째 항목이 비었으면 PhoneBook에 데이터가 하나도 없는 것.
	if (contacts[0].getContact(0).empty())
	{
		std::cout << "The phoneBook is empty." << std::endl;
		return;
	}

	// setw == setwidth
	// iomanip 헤더에서 온 함수로, 문자열의 길이를 입력받은 수 길이로 고정시켜 우측 정렬한다.
	std::cout << std::setw(10) << "index"
			<< "|"
			<< std::setw(10) << "first name"
			<< "|"
			<< std::setw(10) << "last name"
			<< "|"
			<< std::setw(10) << "nickname" << std::endl;

	// 연락처 8개 출력
	for (int i = 0; i < 8; i++)
	{
		// 빈 연락처가 나오면 break.
		// 연락처가 8개 이상 입력된 경우 이 조건엔 걸리지 않고 무조건 8개가 모두 출력된다.
		if (contacts[i].getContact(0).empty())
			break;

		// cout에 setw(10)을 넣으면 다음 1번의 입력에 한해서 문자열 10칸 고정 및 우측 정렬 옵션이 설정된다.
		// 모든 입력에 대해 옵션을 지정하려면 각각의 입력 앞에 setw 함수를 넣어야 한다.
		std::cout << std::setw(10) << i + 1 << "|";

		// 연락처의 0 ~ 2 인덱스 항목(PhoneBook 클래스의 field 배열)까지만 출력하는 이유는 
		// 나머지 항목은 상세 화면에서 보여지기 때문.
		for (int j = 0; j < 3; j++)
		{
			std::string str(contacts[i].getContact(j));

			// 목록 화면에서는 문.자열이 11자 이상 일시, 그 뒤 문자열은 생략하고 마지막 문자를 '.'처리한다.
			// 0123456789abcdef -> 012345678.
			if (str.length() > 10)
			{
				str.erase(10, str.length() - 10);
				str[9] = '.';
			}


			// 줄의 맨 끝에는 '|'문자를 붙이지 않는다.
			if (j < 2)
				std::cout << std::setw(10) << str << "|";
			else
				std::cout << std::setw(10) << str << std::endl;
		}
	}


	// 상세화면 띄우기
	std::string input;
	int index;
	while (1)
	{
		std::cout << "Insert the index of contact to display: " << std::endl;
		std::getline(std::cin, input);
		if (std::cin.fail())
		{
			std::cout << "Error : cin failed." << std::endl;
			exit(1);
		}
		// 숫자 1 ~ 8만 받아야 하므로, 입력된 문자열이 한글자가 아니거나, 숫자가 아니면 에러
		if (input.size() != 1 || !std::isdigit(input[0]))
		{
			std::cout << "Error : not a number." << std::endl;
			continue;
		}
		
		// 받은 문자열을 공백 기준으로 나눠 >> 형태로 받을수 있게 한다.
		std::stringstream ss(input);

		// index는 int형이므로 ss에서 받는 문자가 int형으로 변환되어 삽입된다.
		ss >> index;

		// 1~8이 아니거나, 연락처의 해당 인덱스의 첫번쨰 항목에 값이 없으면 빈것.
		if (index < 1 || index > 8 || contacts[index - 1].getContact(0).empty())
		{
			std::cout << "Error : out of index." << std::endl;
			continue;
		}
		else
		{
			// 해당 연락처의 5개 필드를 줄 단위로 모두 출력.
			for (int j = 0; j < 5; j++)
				std::cout << fields[j] << ": " << contacts[index - 1].getContact(j) << std::endl;
			break;
		}
	}
}
