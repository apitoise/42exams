#ifndef SPELLBOOK_HPP
# define SPELLBOOK_HPP

# include <vector>
# include "ASpell.hpp"

class	SpellBook {
	public:
		SpellBook(void);
		virtual	~SpellBook(void);

		void	learnSpell(ASpell *s);
		void	forgetSpell(const std::string &s);
		ASpell	*generateSpell(const std::string &s);

	private:
		std::vector<ASpell *>	_spells;

		SpellBook(const SpellBook &other);
		SpellBook	&operator=(const SpellBook &other);
};

#endif
