/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Polymorph.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcadet <cadet.florian@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 13:14:51 by fcadet            #+#    #+#             */
/*   Updated: 2020/08/19 14:37:11 by fcadet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Polymorph.hpp"

Polymorph::Polymorph(void) : ASpell("Polymorph", "turned to a sheep")
{
}

Polymorph::~Polymorph(void)
{
}

ASpell	*Polymorph::clone(void) const
{
	return (new Polymorph(*this));
}
