#include "ASpell.hpp"

ASpell::ASpell(std::string const &name, std::string const &effects) : _name(name), _effects(effects) {}

ASpell::ASpell(ASpell const &ref) {*this = ref;}

ASpell &ASpell::operator=(ASpell const &ref) {
	this->_name = ref.getName();
	this->_effects = ref.getEffects();
	return (*this);
}

ASpell::~ASpell(void) {}

std::string const ASpell::getName(void) const { return (this->_name);}

std::string const ASpell::getEffects(void) const { return (this->_effects);}

void ASpell::launch(ATarget const &target) { target.getHitBySpell(*this);}
