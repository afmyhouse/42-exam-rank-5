#include "ATarget.hpp"

ATarget::ATarget() {}

ATarget::ATarget(const std::string &t)
	: tt(t) {}

ATarget::ATarget(ATarget const &r) {
	*this = r;
}

ATarget & ATarget::operator=(ATarget const &r) {
	if (this != &r) {

	}
	return *this;
}

ATarget::~ATarget() {}

const std::string & ATarget::getType() const {
	return tt;
}

void ATarget::getHitBySpell(ASpell const &s) const {
	std::cout << tt << " has been " << s.getEffects() << "!" << std::endl;
}
