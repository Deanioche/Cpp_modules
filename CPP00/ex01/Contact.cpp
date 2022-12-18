/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyulee <dohyulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 17:26:24 by dohyulee          #+#    #+#             */
/*   Updated: 2022/12/14 14:34:52 by dohyulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.h"

void Contact::putContact(int i, const std::string data)
{ 
	contact[i] = data; 
}

std::string Contact::getContact(int i) const
{ 
	return (contact[i]);
}
