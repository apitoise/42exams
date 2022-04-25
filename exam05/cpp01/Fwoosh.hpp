#ifndef FWOOSH_HPP
# define FWOOSH_HPP

# include <iostream>
# include <string>
# include "ASpell.hpp"

class	Fwoosh;

class	Fwoosh : public ASpell {
	public:
		Fwoosh(void);
		virtual ~Fwoosh(void);
		virtual ASpell	*clone(void) const;
};

#endif