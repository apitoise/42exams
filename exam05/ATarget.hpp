#ifndef	ATARGET_HPP
# define ATARGET_HPP

# include <iostream>
# include <string>

class	ASpell;

class	ATarget {
	public:
		ATarget(void);
		ATarget(const std::string &t);
		ATarget(const ATarget &t);
		virtual				~ATarget(void);
		ATarget				&operator=(const ATarget &other);

		const std::string	&getType(void) const;
		void				getHitBySpell(const ASpell &s) const;
		virtual ATarget		*clone(void) const = 0;

		private:
			std::string		_type;
};

# include "ASpell.hpp"

#endif
