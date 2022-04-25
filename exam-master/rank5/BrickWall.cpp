/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BrickWall.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcadet <cadet.florian@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 13:14:51 by fcadet            #+#    #+#             */
/*   Updated: 2020/08/19 13:28:22 by fcadet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BrickWall.hpp"

BrickWall::BrickWall(void) : ATarget("BrickWall Practice")
{
}

BrickWall::~BrickWall(void)
{
}

ATarget	*BrickWall::clone(void) const
{
	return (new BrickWall(*this));
}
