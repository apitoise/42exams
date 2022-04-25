/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dummy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcadet <cadet.florian@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 13:14:51 by fcadet            #+#    #+#             */
/*   Updated: 2020/08/19 13:23:32 by fcadet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dummy.hpp"

Dummy::Dummy(void) : ATarget("Dummy Practice")
{
}

Dummy::~Dummy(void)
{
}

ATarget	*Dummy::clone(void) const
{
	return (new Dummy(*this));
}
