#include "Warlock.hpp"

Warlock::Warlock(const std::string &n, const std::string &t) : _name(n), _title(t) {
	std::cout << _name << ": What a boring day\n";
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

void				Warlock::setTitle(const std::string &t) {
	_title = t;
}

void				Warlock::introduce(void) const {
	std::cout << _name << ": My name is " << _name << ", " << _title << "!\n";
}

void				Warlock::learnSpell(ASpell *s) {
	_spells.learnSpell(s);
}

void				Warlock::forgetSpell(const std::string &s) {
	_spells.forgetSpell(s);
}

void				Warlock::launchSpell(const std::string &s, const ATarget &t) {
	ASpell	*sp = _spells.generateSpell(s);

	if (sp)
		sp->launch(t);
}
