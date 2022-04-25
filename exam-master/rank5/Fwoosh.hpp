/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fwoosh.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcadet <cadet.florian@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 13:12:56 by fcadet            #+#    #+#             */
/*   Updated: 2020/08/19 13:24:12 by fcadet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FWOOSH_HPP
# define FWOOSH_HPP

#include "ASpell.hpp"

class		Fwoosh : public ASpell
{
	public:
		Fwoosh(void);
		virtual			~Fwoosh(void);

		virtual ASpell	*clone(void) const;
};

#endif
