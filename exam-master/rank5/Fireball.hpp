/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fireball.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcadet <cadet.florian@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 13:12:56 by fcadet            #+#    #+#             */
/*   Updated: 2020/08/19 13:29:41 by fcadet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIREBALL_HPP
# define FIREBALL_HPP

#include "ASpell.hpp"

class		Fireball : public ASpell
{
	public:
		Fireball(void);
		virtual			~Fireball(void);

		virtual ASpell	*clone(void) const;
};

#endif
