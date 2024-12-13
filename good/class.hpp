#pragma once
#include <iostream>

class Class {
private :
	std::string wn;
	std::string wt;
	Class();
	Class(const std::string &, const std::string &);
	Class(Class const &);
	Class & operator=(Class const &);
	~Class();
public :
	const std::string & getName() const;
	const std::string & getTitle() const;
	void setTitle(const std::string &);
	void introduce() const;
};