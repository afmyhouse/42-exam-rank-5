#include "ASpell.hpp"

ASpell::ASpell() {}

ASpell::ASpell(const std::string &name, const std::string &effects)
	:_spellName(name), _spellEffects(effects) {}

ASpell::ASpell(ASpell const &ref) {
	*this = ref;
}

ASpell & ASpell::operator=(ASpell const &ref) {
	if (this != &ref) {
		_spellName = ref.getName();
		_spellEffects = ref.getEffects();
	}
	return (*this);
}

ASpell::~ASpell() {}

std::string ASpell::getName() const {
	return (_spellName);
}

std::string ASpell::getEffects() const {
	return (_spellEffects);
}

void ASpell::launch(ATarget const &target) const {
	target.getHitBySpell(*this);
}
