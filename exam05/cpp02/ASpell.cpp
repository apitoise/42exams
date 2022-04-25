#include "ASpell.hpp"

ASpell::ASpell(void): _name(), _effects() {}

ASpell::ASpell(const std::string &n, const std::string &e): _name(n), _effects(e) {}

ASpell::~ASpell(void) {}

ASpell::ASpell(const ASpell &other): _name(other._name), _effects(other._effects) {}

ASpell	&ASpell::operator=(const ASpell &other) {
	_name = other.getName();
	_effects = other.getEffects();
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
