/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SpellBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcadet <cadet.florian@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 13:33:01 by fcadet            #+#    #+#             */
/*   Updated: 2020/08/19 13:48:11 by fcadet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPELLBOOK_HPP
# define SPELLBOOK_HPP

# include <vector>
# include "ASpell.hpp"

class		SpellBook
{
	public:
		SpellBook(void);
		virtual 			~SpellBook(void);

		void				learnSpell(ASpell *s);
		void				forgetSpell(const std::string &s);
		ASpell				*generateSpell(const std::string &s);

	private:
		std::vector<ASpell *>		_spells;

		SpellBook(const SpellBook &b);
		SpellBook			&operator=(const SpellBook &b);
};

#endif
