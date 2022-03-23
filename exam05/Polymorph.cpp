#include "Polymorph.hpp"

Polymorph::Polymorph(void) : ASpell("Polymorph", "turned to a sheep") {}

Polymorph::~Polymorph(void) {}

ASpell	*Polymorph::clone(void) const {
	return (new Polymorph(*this));
}
