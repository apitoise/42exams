/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ASpell.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcadet <cadet.florian@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 12:50:11 by fcadet            #+#    #+#             */
/*   Updated: 2020/08/19 14:09:30 by fcadet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASPELL_HPP
# define ASPELL_HPP

# include <iostream>
# include <string>

class		ATarget;

class		ASpell
{
	public:
		ASpell(void);
		ASpell(const std::string &n, const std::string &e);
		ASpell(const ASpell &s);
		virtual							~ASpell(void);
		ASpell							&operator=(const ASpell &s);

		const std::string				&getName(void) const;
		const std::string				&getEffects(void) const;
		void							launch(const ATarget &t) const;
		virtual ASpell					*clone(void) const = 0;

	private:
		std::string						_name;
		std::string						_effects;
};

# include "ATarget.hpp"

#endif
