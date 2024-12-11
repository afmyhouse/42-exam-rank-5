#pragma once
#include <iostream>
#include <map>
#include "ASpell.hpp"
#include "ATarget.hpp"

class Warlock {
private :
	std::string _name;
	std::string _title;
	std::map<std::string, ASpell*> _wBook;
	Warlock();
	Warlock(Warlock const &);
	Warlock & operator=(Warlock const &);
public :
	Warlock(const std::string &, const std::string &);
	~Warlock();
	const std::string & getName() const;
	const std::string & getTitle() const;
	void setTitle(const std::string &);
	void introduce() const;

	void learnSpell(ASpell*);
	void forgetSpell(const std::string);
	void launchSpell(const std::string, ATarget const &);
};