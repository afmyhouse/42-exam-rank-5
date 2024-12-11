#pragma once
#include <iostream>

class Warlock {
private :
	std::string _name;
	std::string _title;
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
};