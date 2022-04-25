/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ATarget.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcadet <cadet.florian@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 13:02:10 by fcadet            #+#    #+#             */
/*   Updated: 2020/08/19 13:12:40 by fcadet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ATARGET_HPP
# define ATARGET_HPP

# include <iostream>
# include <string>

class		ASpell;

class		ATarget
{
	public:
		ATarget(void);
		ATarget(const std::string &t);
		ATarget(const ATarget &t);
		virtual							~ATarget(void);
		ATarget							&operator=(const ATarget &t);

		const std::string				&getType(void) const;
		void							getHitBySpell(const ASpell &s) const;
		virtual ATarget					*clone(void) const = 0;

	private:
		std::string						_type;
};

# include "ASpell.hpp"

#endif
