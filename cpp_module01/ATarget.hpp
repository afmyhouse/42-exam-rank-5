#pragma once
#include <iostream>
#include "ASpell.hpp"

class ASpell;

class ATarget {
private :
	std::string _type;
public :
	ATarget();
	ATarget(ATarget const &);
	ATarget & operator=(ATarget const &);
	ATarget(const std::string );
	virtual ~ATarget();
	std::string getType() const;
	virtual ATarget* clone() const = 0;
	void getHitBySpell(ASpell const &) const;
};