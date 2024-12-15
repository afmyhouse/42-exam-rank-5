#pragma once
#include <iostream>
#include "ATarget.hpp"

class Dummy : public ATarget {
public :
	Dummy();
	~Dummy();
	ATarget* clone() const;
};