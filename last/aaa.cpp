#include "aaa.hpp"

aaa::aaa() {}

aaa::aaa(aaa const &r) {
	*this = r;
}

aaa &aaa::operator=(aaa const &r) {
	if (this != &r) {

	}
	return *this;
}

aaa::~aaa() {}

