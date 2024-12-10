#pragma once
#include <iostream>
#include "ATarget.hpp"

class ATarget;

class ASpell
{
	private :
		std::string _name;
		std::string _effects;
	public :
		ASpell(void);
		ASpell(std::string const &name, std::string const &effects);
		ASpell(ASpell const &ref);
		ASpell &operator=(ASpell const &ref);
		virtual ~ASpell(void);

		std::string const getName(void) const ;
		std::string const getEffects(void) const ;
		void launch(ATarget const &target);

		virtual ASpell * clone(void) const = 0;
};
