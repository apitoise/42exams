/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ASpell.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcadet <cadet.florian@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 12:56:08 by fcadet            #+#    #+#             */
/*   Updated: 2020/08/19 13:12:14 by fcadet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ASpell.hpp"

ASpell::ASpell(void) : _name(), _effects()
{
}

ASpell::ASpell(const std::string &n, const std::string &e) : _name(n), _effects(e)
{
}

ASpell::ASpell(const ASpell &s) : _name(s._name), _effects(s._effects)
{
}

ASpell::~ASpell(void)
{
}

ASpell							&ASpell::operator=(const ASpell &s)
{
	_name = s._name;
	_effects = s._effects;
	return (*this);
}

const std::string				&ASpell::getName(void) const
{
	return (_name);
}

const std::string				&ASpell::getEffects(void) const
{
	return (_effects);
}

void							ASpell::launch(const ATarget &t) const
{
	t.getHitBySpell(*this);
}
