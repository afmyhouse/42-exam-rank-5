#pragma once
#include <iostream>
#include "ASpell.hpp"

class Polymorph : public ASpell{
public :
	Polymorph();
	~Polymorph();
	ASpell* clone() const;
};