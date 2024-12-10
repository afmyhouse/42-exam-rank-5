#pragma once
#include <iostream>
#include <map>

#include "ASpell.hpp"
#include "ATarget.hpp"

class Warlock
{
	private :
		std::string _name;
		std::string _title;
		Warlock(void);
		Warlock(Warlock const &ref);
		Warlock &operator=(Warlock const &ref);
		std::map <std::string, ASpell *> _SpellBook;
	public :
		Warlock(std::string const &name, std::string const &title);
		~Warlock(void);

		std::string const getName(void) const ;
		std::string const getTitle(void) const ;
		void setTitle(std::string const &rnewTitle);
		void introduce(void) const ;

		void learnSpell(ASpell *spell);
		void forgetSpell(std::string const &spellName);
		void launchSpell(std::string const name, ATarget const &target);
};