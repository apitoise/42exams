#include "ASpell.hpp"

ASpell::ASpell(void) : _name(), _effects() {}

ASpell::ASpell(const std::string &n, const std::string &e) : _name(n), _effects(e) {}

ASpell::ASpell(const ASpell &s) : _name(s._name), _effects(s._effects) {}

ASpell::~ASpell(void) {}

ASpell	&ASpell::operator=(const ASpell &s) {
	_name = s._name;
	_effects = s._effects;
	return (*this);
}

const std::string	&ASpell::getName(void) const {
	return (_name);
}

const std::string	&ASpell::getEffects(void) const {
	return (_effects);
}

void				ASpell::launch(const ATarget &t) const {
	t.getHitBySpell(*this);
}
