#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator() {}

TargetGenerator::~TargetGenerator() {
	for (std::map<std::string, ATarget*>::iterator it = _tBook.begin(); it != _tBook.end(); ++it) {
		delete it->second;
	}
	_tBook.clear();
}

void TargetGenerator::learnTargetType(ATarget* target) {
	if (target && _tBook.find(target->getType()) == _tBook.end()) {
		_tBook[target->getType()] = target->clone();
	}
}

void TargetGenerator::forgetTargetType(std::string const &tType) {
	std::map<std::string, ATarget*>::iterator it = _tBook.find(tType);
	if (it != _tBook.end()) {
		delete it->second;
		_tBook.erase(it);
	}
}

ATarget* TargetGenerator::createTarget(std::string const &tType) {
	std::map<std::string, ATarget*>::iterator it = _tBook.find(tType);
	if (it != _tBook.end()) {
		return it->second->clone();
	}
	return NULL;
}
