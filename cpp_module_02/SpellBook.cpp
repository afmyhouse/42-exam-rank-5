#include "SpellBook.hpp"

SpellBook::SpellBook() {}

SpellBook::SpellBook(SpellBook const &ref) {
	*this = ref;
}

SpellBook &SpellBook::operator=(SpellBook const &ref) {
	if (this != &ref) {

	}
	return *this;
}

SpellBook::~SpellBook() {
		std::map<std::string, ASpell*>::iterator it;
		for (it = _spellBook.begin(); it != _spellBook.end(); ++it) {
		delete it->second;
	}
	_spellBook.clear();
}

void SpellBook::learnSpell(ASpell* spell) {
	std::map<std::string, ASpell*>::iterator it = _spellBook.find(spell->getName());
	if (it == _spellBook.end()) {
		_spellBook[spell->getName()] = spell->clone();
	}
}

void SpellBook::forgetSpell(const std::string &_spellName) {
	std::map<std::string, ASpell*>::iterator it = _spellBook.find(_spellName);
	if (it != _spellBook.end()) {
		delete it->second;
		_spellBook.erase(it);
	}
}
ASpell* SpellBook::createSpell(std::string const &_spellName) {
	ASpell* spell = NULL;
	std::map<std::string, ASpell*>::iterator it = _spellBook.find(_spellName);
	if (it != _spellBook.end()) {
		spell = it->second->clone();
	}
	return spell;
}