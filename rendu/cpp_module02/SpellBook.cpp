#include "SpellBook.hpp"


SpellBook::SpellBook() {}

SpellBook::~SpellBook() {
	for (std::map<std::string, ASpell*>::iterator it = sb.begin(); it != sb.end(); ++it) {
		delete it->second;
	}
	sb.clear();
}

void SpellBook::learnSpell(ASpell* s) {
	std::map<std::string, ASpell*>::iterator it = sb.find(s->getName());
	if (it == sb.end()) {
		sb[s->getName()]  = s->clone();
	}
}

void SpellBook::forgetSpell(const std::string &sn) {
	std::map<std::string, ASpell*>::iterator it = sb.find(sn);
	if (it != sb.end()) {
		delete it->second;
		sb.erase(it);
	}
}

ASpell*  SpellBook::createSpell(const std::string &sn) {
	ASpell *spell = NULL;
	std::map<std::string, ASpell*>::iterator it = sb.find(sn);
	if (it != sb.end()) {
		spell =it->second->clone();
	}
	return spell;
}