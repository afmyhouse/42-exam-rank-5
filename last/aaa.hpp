#pragma once
#include <iostream>

class aaa {
private :
	std::string s;
public :
	aaa();
	aaa(aaa const &);
	aaa & operator=(aaa const &);
	~aaa();
};