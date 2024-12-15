#pragma once

#include <iostream>
#include "ASpell.hpp"

class ASpell;

class ATarget {
protected :
	std::string _targetType;
public :
	ATarget();
	ATarget(const std::string &);
	ATarget(ATarget const &);
	ATarget & operator=(ATarget const &);
	virtual ~ATarget();

	const std::string & getType() const;
	virtual ATarget* clone() const = 0;
	void getHitBySpell(ASpell const &) const;
};