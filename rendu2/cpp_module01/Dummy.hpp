
#pragma once
#include <iostream>
#include "ATarget.hpp"

class Dummy : public ATarget
{
	public :
		Dummy(void);
		~Dummy(void);

		virtual ATarget * clone(void) const;
};
