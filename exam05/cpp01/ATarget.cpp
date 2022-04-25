#include "ASpell.hpp"

ATarget::ATarget(void): _type() {}

ATarget::ATarget(const std::string &t): _type(t) {}

ATarget::~ATarget(void) {}

const std::string	&ATarget::getType(void) const {
	return (_type);
}

void				ATarget::getHitBySpell(const ASpell &s) const {
	std::cout << _type << " has been " << s.getEffects() << "!\n";
}
