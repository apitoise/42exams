#ifndef	SPELLBOOK_HPP
# define SPELLBOOK_HPP

# include <string>
# include <iostream>
# include <vector>
# include "ASpell.hpp"

class	SpellBook;

class	SpellBook {
	public:
		SpellBook(void);
		~SpellBook(void);
		void	learnSpell(ASpell *s);
		void	forgetSpell(const std::string &s);
		ASpell	*createSpell(const std::string &s);

	private:
		std::vector<ASpell *>	_spells;
		
		SpellBook(const SpellBook &other);
		SpellBook				&operator=(const SpellBook &other);
};

#endif
