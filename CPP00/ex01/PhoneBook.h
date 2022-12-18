/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyulee <dohyulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 16:18:28 by dohyulee          #+#    #+#             */
/*   Updated: 2022/12/14 14:36:57 by dohyulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
#define PHONEBOOK_H

// 문자 10칸 공간을 만들어 주기 위한 함수 setw()의 헤더 
#include <iomanip>
#include <string>
// stdin 입력된 string을 int로 변환하기 위한 함수의 헤더. stringstream
#include <sstream>

// iostream 여기에 들어있음 ( PhoneBook.h에 또 선언하면 중복 선언이 되므로)
#include "Contact.h"

class PhoneBook
{
private:
	// 입력받을 5가지 항목의 이름을 가진 배열.
	std::string fields[5];
	// 연락처가 저장될 8개 공간.
	Contact contacts[8];
	// 연락처가 8개까지 모두 찼을 때, 가장 오래된 연락처 (1번)부터 덮어씌워진다.
	int idx;

public:
	// 클래스 생성자
	PhoneBook();

	// 클래스 멤버 함수
	void add();

	// search 함수에서는 '멤버변수'에 대한 변경이 없으므로 맨 뒤에 const를 선언.
	void search() const;
};

#endif
