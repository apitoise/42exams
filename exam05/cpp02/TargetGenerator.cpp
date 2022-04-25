#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator(void) {}

TargetGenerator::~TargetGenerator(void) {
//	for (std::vector<ATarget *>::iterator it = _targets.begin(); it != _targets.end(); ++it)
//		delete(*it);
//	_targets.clear();
}

void	TargetGenerator::learnTargetType(ATarget *t) {
	for (std::vector<ATarget *>::iterator it = _targets.begin(); it != _targets.end(); ++it) {
		if ((*it)->getType() == t->getType())
			return;
	}
	_targets.push_back(t);
}

void	TargetGenerator::forgetTargetType(const std::string &t) {
	for (std::vector<ATarget *>::iterator it = _targets.begin(); it != _targets.end(); ++it) {
		if ((*it)->getType() == t) {
			delete(*it);
			_targets.erase(it);
			return ;
		}
	}
}

ATarget	*TargetGenerator::createTarget(const std::string &t) {
	for (std::vector<ATarget *>::iterator it = _targets.begin(); it != _targets.end(); ++it)
		if ((*it)->getType() == t)
			return (*it);
	return (NULL);
}
