/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BrickWall.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcadet <cadet.florian@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 13:12:56 by fcadet            #+#    #+#             */
/*   Updated: 2020/08/19 13:28:13 by fcadet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRICKWALL_HPP
# define BRICKWALL_HPP

#include "ATarget.hpp"

class		BrickWall : public ATarget
{
	public:
		BrickWall(void);
		virtual			~BrickWall(void);

		virtual ATarget	*clone(void) const;
};

#endif
