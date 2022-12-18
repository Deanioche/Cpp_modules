/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyulee <dohyulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 17:26:27 by dohyulee          #+#    #+#             */
/*   Updated: 2022/12/14 14:34:56 by dohyulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

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
