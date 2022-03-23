#include "Dummy.hpp"

Dummy::Dummy(void) : ATarget("Dummy Practice") {}

Dummy::~Dummy(void) {}

ATarget *Dummy::clone(void) const {
	return (new Dummy(*this));
}
