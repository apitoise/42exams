#ifndef	WARLOCK_HPP
# define WARLOCK_HPP

# include <string>
# include <iostream>
# include <vector>
# include "ASpell.hpp"
# include "ATarget.hpp"

class	Warlock {
	public:
		Warlock(std::string name, std::string title);
		~Warlock(void);
		const std::string	&getName(void) const;
		const std::string	&getTitle(void) const;
		void				setTitle(const std::string &title);
		void				introduce(void) const;
		void				learnSpell(const ASpell *s);
		void				forgetSpell(const std::string &n);
		void				launchSpell(const std::string &n, const ATarget &t);

	private:
		std::string				_name;
		std::string				_title;
		std::vector<ASpell *>	_spells;

		Warlock(void);
		Warlock(const Warlock &other);
		Warlock	&operator=(const Warlock &other);
};

#endif
