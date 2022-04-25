/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Warlock.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcadet <cadet.florian@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 12:34:58 by fcadet            #+#    #+#             */
/*   Updated: 2020/08/19 13:32:42 by fcadet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WARLOCK_HPP
# define WARLOCK_HPP

# include <iostream>
# include <string>
# include "ASpell.hpp"
# include "ATarget.hpp"
# include "SpellBook.hpp"

class		Warlock
{
	public:
		Warlock(const std::string &n, const std::string &t);
		virtual					~Warlock(void);

		const std::string		&getName(void) const;
		const std::string		&getTitle(void) const;
		void					setTitle(const std::string &t);
		void					introduce(void) const;
		void					learnSpell(ASpell *s);
		void					forgetSpell(const std::string &s);
		void					launchSpell(const std::string &s, const ATarget &t);

	private:
		std::string				_name;
		std::string				_title;
		SpellBook				_spells;

		Warlock(void);
		Warlock(const Warlock &w);
		Warlock					&operator=(const Warlock &w);
};

#endif
