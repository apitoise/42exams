#include "Warlock.hpp"

Warlock::Warlock(std::string name, std::string title): _name(name), _title(title) {
	std::cout << _name << ": this looks like another boring day.\n";
}

Warlock::~Warlock(void) {
	std::cout << _name << ": My job here is done!\n";
}

const std::string	&Warlock::getName(void) const {
	return (_name);
}

const std::string	&Warlock::getTitle(void) const {
	return (_title);
}

void				Warlock::setTitle(const std::string &title) {
	_title = title;
}

void				Warlock::introduce(void) const {
	std::cout << _name << ": I am " << _name << ", " << _title << "!\n";
}

void				Warlock::learnSpell(ASpell *s) {
	_spells.learnSpell(s);
}

void				Warlock::forgetSpell(const std::string &n) {	
	_spells.forgetSpell(n);
}

void				Warlock::launchSpell(const std::string &n, const ATarget &t) {
	ASpell	*sp = _spells.createSpell(n);

	if (sp)
		sp->launch(t);
}
