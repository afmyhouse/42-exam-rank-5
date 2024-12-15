#pragma once
#include <iostream>
//#include <map>
#include "ASpell.hpp"
#include "ATarget.hpp"
#include "SpellBook.hpp"

class Warlock {
private :
	std::string _warlockName;
	std::string _warlockTitle;
	SpellBook _warlockBook;
	Warlock();
	Warlock(Warlock const &);
	Warlock &operator=(Warlock const &);
public :
	Warlock(const std::string &, const std::string &);
	~Warlock();
	const std::string & getName() const;
	const std::string & getTitle() const;
	void setTitle(const std::string &);
	void  introduce() const;

	void learnSpell(ASpell*);
	void forgetSpell(const std::string);
	void launchSpell(const std::string, ATarget const &target);
};