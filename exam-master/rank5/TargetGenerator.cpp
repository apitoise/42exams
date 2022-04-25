/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TargetGenerator.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcadet <cadet.florian@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 13:37:16 by fcadet            #+#    #+#             */
/*   Updated: 2020/08/19 13:50:08 by fcadet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator(void)
{
}

TargetGenerator::~TargetGenerator(void)
{
	for (std::vector<ATarget *>::iterator it = _targets.begin(); it != _targets.end(); ++it)
		delete *it;
	_targets.clear();
}

void				TargetGenerator::learnTargetType(ATarget *t)
{
	for (std::vector<ATarget *>::iterator it = _targets.begin(); it != _targets.end(); ++it)
		if ((*it)->getType() == t->getType())
			return ;	
	_targets.push_back(t->clone());
}

void				TargetGenerator::forgetTargetType(const std::string &t)
{
	for (std::vector<ATarget *>::iterator it = _targets.begin(); it != _targets.end(); ++it)
	{
		if ((*it)->getType() == t)
		{
			delete *it;
			_targets.erase(it);
			return ;
		}
	}
}

ATarget				*TargetGenerator::createTarget(const std::string &t)
{
	for (std::vector<ATarget *>::iterator it = _targets.begin(); it != _targets.end(); ++it)
		if ((*it)->getType() == t)
			return (*it);
	return (NULL);
}
