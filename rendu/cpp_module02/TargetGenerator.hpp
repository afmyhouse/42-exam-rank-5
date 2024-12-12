#pragma once
#include <iostream>
#include <map>
#include "ATarget.hpp"

class TargetGenerator {
private :
	std::map<std::string, ATarget*> tb;
	TargetGenerator(const std::string &, const std::string &);
	TargetGenerator(TargetGenerator const &);
	TargetGenerator & operator=(TargetGenerator const &);

public :
	TargetGenerator();
	~TargetGenerator();

	void learnTargetType(ATarget*);
	void forgetTargetType(const std::string &);
	ATarget* createTarget(const std::string &);
};