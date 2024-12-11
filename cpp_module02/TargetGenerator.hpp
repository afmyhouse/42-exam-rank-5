#pragma once
#include <iostream>
#include <map>
#include "ATarget.hpp"

class TargetGenerator {
private :
	TargetGenerator(TargetGenerator const &);
	TargetGenerator & operator=(TargetGenerator const &);
	std::map<std::string, ATarget*> _tBook;
public :
	TargetGenerator();
	~TargetGenerator();
	void learnTargetType(ATarget*);
	void forgetTargetType(std::string const &);
	ATarget* createTarget(std::string const &);
};
