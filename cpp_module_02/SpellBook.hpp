#pragma once
#include <iostream>
#include <map>
#include "ASpell.hpp"

class SpellBook {
private :
	std::map<std::string, ASpell*> _spellBook;
	SpellBook(SpellBook const &);
	SpellBook & operator=(SpellBook const &);
public :
	SpellBook();
	~SpellBook();

	void learnSpell(ASpell*);
	void forgetSpell(std::string const &);
	ASpell* createSpell(std::string const &);
};