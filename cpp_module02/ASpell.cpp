#include "ASpell.hpp"

ASpell::ASpell() {}

ASpell::ASpell(const std::string name, const std::string effects)
	: _name(name), _effects(effects) {
}

ASpell::ASpell(ASpell const &ref) {
	*this = ref;
}

ASpell &ASpell::operator=(ASpell const &ref) {
	if (this != &ref) {
		_name = ref.getName();
		_effects =ref.getEffects();
	}
	return *this;
}

ASpell::~ASpell() {}

std::string ASpell::getName() const {
	return (_name);
}

std::string ASpell::getEffects() const {
	return (_effects);
}

void ASpell::launch(ATarget const &target) const {
	target.getHitBySpell(*this);
}
