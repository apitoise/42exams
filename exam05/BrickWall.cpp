#include "BrickWall.hpp"

BrickWall::BrickWall(void) : ATarget("BrickWall Practice") {}

BrickWall::~BrickWall(void) {}

ATarget	*BrickWall::clone(void) const {
	return (new BrickWall(*this));
}
