#include "ATarget.hpp"

ATarget::ATarget() {}

ATarget::ATarget(const std::string &type)
	: _targetType(type) {}

ATarget::ATarget(ATarget const &ref) {
	*this = ref;
}

ATarget & ATarget::operator=(ATarget const &ref) {
	if (this != &ref) {
		_targetType = ref.getType();
	}
	return *this;
}

ATarget::~ATarget() {}

const std::string & ATarget::getType() const {
	return _targetType;
}

void ATarget::getHitBySpell(ASpell const &spell) const {
	std::cout << _targetType << " has been " << spell.getEffects() << "!" << std::endl;
}
