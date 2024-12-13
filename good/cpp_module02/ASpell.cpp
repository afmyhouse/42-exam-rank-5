#include "ASpell.hpp"

ASpell::ASpell() {}

ASpell::ASpell(const std::string &n, const std::string &e)
	:sn(n), se(e) {}

ASpell::ASpell(ASpell const &r) {
	*this = r;
}

ASpell & ASpell::operator=(ASpell const &r) {
	if (this != &r) {
		sn = r.getName();
		se = r.getEffects();
	}
	return (*this);
}

ASpell::~ASpell() {}

std::string ASpell::getName() const {
	return (sn);
}
std::string ASpell::getEffects() const {
	return (se);
}

void ASpell::launch(ATarget const &t) const {
	t.getHitBySpell(*this);
}
