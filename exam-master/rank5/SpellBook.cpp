/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SpellBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcadet <cadet.florian@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 13:37:16 by fcadet            #+#    #+#             */
/*   Updated: 2020/08/19 13:42:57 by fcadet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SpellBook.hpp"

SpellBook::SpellBook(void)
{
}

SpellBook::~SpellBook(void)
{
	for (std::vector<ASpell *>::iterator it = _spells.begin(); it != _spells.end(); ++it)
		delete *it;
	_spells.clear();
}

void				SpellBook::learnSpell(ASpell *s)
{
	for (std::vector<ASpell *>::iterator it = _spells.begin(); it != _spells.end(); ++it)
		if ((*it)->getName() == s->getName())
			return ;	
	_spells.push_back(s->clone());
}

void				SpellBook::forgetSpell(const std::string &s)
{
	for (std::vector<ASpell *>::iterator it = _spells.begin(); it != _spells.end(); ++it)
	{
		if ((*it)->getName() == s)
		{
			delete *it;
			_spells.erase(it);
			return ;
		}
	}
}

ASpell				*SpellBook::generateSpell(const std::string &s)
{
	for (std::vector<ASpell *>::iterator it = _spells.begin(); it != _spells.end(); ++it)
		if ((*it)->getName() == s)
			return (*it);
	return (NULL);
}
