#include "ATarget.hpp"

ATarget::ATarget() {}

ATarget::ATarget(const std::string type)
	: _type(type) {
}

ATarget::ATarget(ATarget const &ref) {
	*this = ref;
}

ATarget &ATarget::operator=(ATarget const &ref) {
	if (this != &ref) {
		_type = ref.getType();
	}
	return *this;
}

ATarget::~ATarget() {
}

std::string ATarget::getType() const {
	return (_type);
}

void ATarget::getHitBySpell(ASpell const &spell) const {
	std::cout << _type << " has been " << spell.getEffects() << "!" << std::endl;
}