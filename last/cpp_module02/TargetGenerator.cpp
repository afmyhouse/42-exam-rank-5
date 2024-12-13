#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator() {}

TargetGenerator::TargetGenerator(TargetGenerator const &r) {
	*this = r;
}

TargetGenerator &TargetGenerator::operator=(TargetGenerator const &r) {
	if (this != &r) {
	}
	return *this;
}

TargetGenerator::~TargetGenerator() {
	for (std::map<std::string, ATarget*>::iterator it = tb.begin(); it != tb.end(); ++it) {
		delete it->second;
	}
	tb.clear();
}

void TargetGenerator::learnTargetType(ATarget* t) {
	std::map<std::string, ATarget*>::iterator it = tb.find(t->getType());
	if (it == tb.end()) {
		tb[t->getType()] = t->clone();
	}
}

void TargetGenerator::forgetTargetType(const std::string &sn) {
	std::map<std::string, ATarget*>::iterator it = tb.find(sn);
	if (it != tb.end()) {
		delete it->second;
		tb.erase(it);
	}
}
ATarget* TargetGenerator::createTarget(const std::string &sn) {
	ATarget* target = NULL;
	std::map<std::string, ATarget*>::iterator it = tb.find(sn);
	if (it != tb.end()) {
		target = it->second->clone();
	}
	return target;
}