#ifndef CONTACT_H
#define CONTACT_H
#include <iostream>

class Contact
{
private:
	std::string contact[5];

public:
	void putContact(int i, const std::string data);

	// 맴버 변수를 수정하는 함수가 아니므로 const
	std::string getContact(int i) const;
};

#endif
