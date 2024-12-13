#pragma once
#include <iostream>
#include <map>
#include "ATarget.hpp"

class TargetGenerator {
private :
	std::map<std::string, ATarget*> tb;
public :
	TargetGenerator();
	TargetGenerator(TargetGenerator const &);
	TargetGenerator & operator=(TargetGenerator const &);
	~TargetGenerator();

	void learnTargetType(ATarget*);
	void forgetTargetType(std::string const &);
	ATarget* createTarget(std::string const &);
};