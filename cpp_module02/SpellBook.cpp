#include "SpellBook.hpp"

SpellBook::SpellBook() {}

SpellBook::~SpellBook() {
	for (std::map<std::string, ASpell*>::iterator it = _sBook.begin(); it != _sBook.end(); ++it) {
		delete it->second;
	}
	_sBook.clear();
}

void SpellBook::learnSpell(ASpell* spell) {
	if (spell && _sBook.find(spell->getName()) == _sBook.end()) {
		_sBook[spell->getName()] = spell->clone();
	}
}

void SpellBook::forgetSpell(const std::string & spellName) {
	std::map<std::string, ASpell*>::iterator it = _sBook.find(spellName);
	if (it != _sBook.end()) {
		delete it->second;
		_sBook.erase(it);
	}
}

ASpell* SpellBook::createSpell(const std::string & spellName) {
	ASpell* spell = NULL;
	std::map<std::string, ASpell*>::iterator it = _sBook.find(spellName);
	if (it != _sBook.end()) {
		spell = it->second->clone();
	}
	return spell;
}
