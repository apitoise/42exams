#ifndef POLYMORPH_HPP
# define POLYMORPH_HPP

# include <string>
# include <iostream>
# include "ASpell.hpp"

class	Polymorph;

class	Polymorph: public ASpell {
	public:
		Polymorph(void);
		virtual ~Polymorph(void);
		virtual ASpell	*clone(void) const;
};

#endif
