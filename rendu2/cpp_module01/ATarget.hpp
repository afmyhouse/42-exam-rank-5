#pragma once
#include <iostream>
#include "ASpell.hpp"

class ASpell;

class ATarget
{
	private :
		std::string _type;
		ATarget(void);
	public :
		ATarget(std::string const &type);
		ATarget(ATarget const &ref);
		ATarget &operator=(ATarget const &ref);
		virtual ~ATarget(void);

		std::string const &getType(void) const ;
		void getHitBySpell(ASpell const &spell) const;
		virtual ATarget * clone(void) const = 0;
};
