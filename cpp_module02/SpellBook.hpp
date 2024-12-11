#pragma once
#include <iostream>
#include <map>
#include "ATarget.hpp"
#include "ASpell.hpp"


class SpellBook {
private :
	std::map<std::string, ASpell*> _sBook;
	SpellBook & operator=(SpellBook const &);
	SpellBook(SpellBook const &);
public :
	SpellBook();
	~SpellBook();
	void learnSpell(ASpell*);
	void forgetSpell(const std::string &);
	ASpell* createSpell(const std::string &);

};

