#pragma once
#include <iostream>
#include "ATarget.hpp"

class ATarget;

class ASpell {
private :
	std::string _name;
	std::string _effects;
public :
	ASpell();
	ASpell(ASpell const &);
	ASpell & operator=(ASpell const &);
	ASpell(const std::string, const std::string);
	virtual ~ASpell();
	std::string getName() const;
	std::string getEffects() const;
	virtual ASpell* clone() const = 0;
	void launch(ATarget const &) const;

};

