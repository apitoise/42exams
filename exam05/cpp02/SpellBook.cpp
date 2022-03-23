#include "SpellBook.hpp"

SpellBook::SpellBook(void) {}

SpellBook::~SpellBook(void) {}

void		SpellBook::learnSpell(ASpell *s) {
	for(std::vector<ASpell *>::iterator it = _spells.begin(); it != _spells.end(); ++it) {
		if ((*it)->getName() == s->getName())
			return ;
	}
	_spells.push_back(s->clone());
}

void		SpellBook::forgetSpell(const std::string &s) {
	for(std::vector<ASpell *>::iterator it = _spells.begin(); it != _spells.end(); ++it) {
		if ((*it)->getName() == s) {
			delete(*it);
			_spells.erase(it);
			return ;
		}
	}
}

ASpell*		SpellBook::createSpell(const std::string &s) {
	for(std::vector<ASpell *>::iterator it = _spells.begin(); it != _spells.end(); ++it) {
		if ((*it)->getName() == s)
			return (*it);
	}
	return (NULL);
}
