#pragma once
#include <iostream>

class Warlock
{
	private :
		std::string _name;
		std::string _title;
		Warlock(void);
		Warlock(Warlock const &ref);
		Warlock &operator=(Warlock const &ref);
	public :
		Warlock(std::string const &name, std::string const &title);
		~Warlock(void);

		std::string const getName(void) const ;
		std::string const getTitle(void) const ;
		void setTitle(std::string const &rnewTitle);
		void introduce(void) const ;
};