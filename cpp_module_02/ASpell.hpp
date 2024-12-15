#pragma once
#include <iostream>
#include "ATarget.hpp"

class ATarget;

class ASpell {
protected :
	std::string _spellName;
	std::string _spellEffects;
public :
	ASpell();
	ASpell(const std::string &, const std::string &);
	ASpell(ASpell const &);
	ASpell & operator=(ASpell const &);
	virtual ~ASpell();

	std::string getName() const;
	std::string getEffects() const;
	virtual ASpell* clone() const = 0;
	void launch(ATarget const &) const;
};