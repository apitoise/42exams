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

void				Warlock::learnSpell(const ASpell *s) {
	for (std::vector<ASpell *>::iterator it = _spells.begin(); it != _spells.end(); ++it)
		if ((*it)->getName() == s->getName())
			return;
	_spells.push_back(s->clone());
}

void				Warlock::forgetSpell(const std::string &n) {	
	for (std::vector<ASpell *>::iterator it = _spells.begin(); it != _spells.end(); ++it) {
		if ((*it)->getName() == n) {
			delete(*it);
			_spells.erase(it);
			return ;
		}
	}
}

void				Warlock::launchSpell(const std::string &n, const ATarget &t) {
	for (std::vector<ASpell *>::iterator it = _spells.begin(); it != _spells.end(); ++it) {
		if ((*it)->getName() == n) {
			(*it)->launch(t);
		}
	}
}
