#ifndef ASPELL_HPP
# define ASPELL_HPP

class	ASpell;

# include <iostream>
# include <string>
# include "ATarget.hpp"


class	ASpell {
	public:
		ASpell(void);
		ASpell(const std::string &n, const std::string &e);
		virtual ~ASpell(void);
		ASpell(const ASpell &other);
		ASpell	&operator=(const ASpell &other);

		const std::string	&getName(void) const;
		const std::string	&getEffects(void) const;
		void				launch(const ATarget &t) const;
		virtual ASpell				*clone(void) const = 0;

	private:
		std::string	_name;
		std::string	_effects;
};


#endif
