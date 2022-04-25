/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dummy.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcadet <cadet.florian@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 13:12:56 by fcadet            #+#    #+#             */
/*   Updated: 2020/08/19 13:24:24 by fcadet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DUMMY_HPP
# define DUMMY_HPP

#include "ATarget.hpp"

class		Dummy : public ATarget
{
	public:
		Dummy(void);
		virtual			~Dummy(void);

		virtual ATarget	*clone(void) const;
};

#endif
