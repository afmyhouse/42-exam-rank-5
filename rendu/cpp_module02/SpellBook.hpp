#pragma once
#include <iostream>
#include <map>
#include "ASpell.hpp"

class SpellBook {
private :
	std::map<std::string, ASpell*> sb;
	SpellBook(const std::string &, const std::string &);
	SpellBook(SpellBook const &);
	SpellBook & operator=(SpellBook const &);
public :
	SpellBook();
	~SpellBook();

	void learnSpell(ASpell*);
	void forgetSpell(const std::string &);
	ASpell* createSpell(const std::string &);
};