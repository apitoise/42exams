/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ATarget.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcadet <cadet.florian@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 12:56:08 by fcadet            #+#    #+#             */
/*   Updated: 2020/08/19 13:10:32 by fcadet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ATarget.hpp"

ATarget::ATarget(void) : _type()
{
}

ATarget::ATarget(const std::string &t) : _type(t)
{
}

ATarget::ATarget(const ATarget &t) : _type(t._type)
{
}

ATarget::~ATarget(void)
{
}

ATarget							&ATarget::operator=(const ATarget &t)
{
	_type = t._type;
	return (*this);
}

const std::string				&ATarget::getType(void) const
{
	return (_type);
}

void							ATarget::getHitBySpell(const ASpell &s) const
{
	std::cout << _type << " has been " << s.getEffects() << "!\n";
}
