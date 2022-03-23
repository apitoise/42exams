#ifndef ATARGET_HPP
# define ATARGET_HPP

class	ATarget;

# include <iostream>
# include <string>
# include "ASpell.hpp"

class	ATarget {
	public:
		ATarget(void);
		ATarget(const std::string &t);
		virtual	~ATarget(void);
		const std::string	&getType(void) const;
		virtual ATarget				*clone(void) const = 0;
		void				getHitBySpell(const ASpell &s) const;

	private:
		std::string			_type;
};


#endif
