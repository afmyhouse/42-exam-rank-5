#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator() {}

TargetGenerator::TargetGenerator(TargetGenerator const &ref) {
	*this = ref;
}

TargetGenerator &TargetGenerator::operator=(TargetGenerator const &ref) {
	if (this != &ref) {
	}
	return *this;
}

TargetGenerator::~TargetGenerator() {
	std::map<std::string, ATarget*>::iterator it;
	for ( it = _targetBook.begin(); it != _targetBook.end(); ++it) {
		delete it->second;
	}
	_targetBook.clear();
}

void TargetGenerator::learnTargetType(ATarget* target) {
	std::map<std::string, ATarget*>::iterator it = _targetBook.find(target->getType());
	if (it == _targetBook.end()) {
		_targetBook[target->getType()] = target->clone();
	}
}

void TargetGenerator::forgetTargetType(const std::string &_spellName) {
	std::map<std::string, ATarget*>::iterator it = _targetBook.find(_spellName);
	if (it != _targetBook.end()) {
		delete it->second;
		_targetBook.erase(it);
	}
}
ATarget* TargetGenerator::createTarget(const std::string &_spellName) {
	ATarget* target = NULL;
	std::map<std::string, ATarget*>::iterator it = _targetBook.find(_spellName);
	if (it != _targetBook.end()) {
		target = it->second->clone();
	}
	return target;
}