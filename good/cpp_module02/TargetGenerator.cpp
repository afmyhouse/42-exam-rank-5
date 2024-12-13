#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator() {}
TargetGenerator::~TargetGenerator() {
		for (std::map<std::string, ATarget*>::iterator it = tb.begin(); it != tb.end(); ++it) {
		delete it->second;
	}
	tb.clear();
}

void TargetGenerator::learnTargetType(ATarget* t) {
	std::map<std::string, ATarget*>::iterator it = tb.find(t->getType());
	if (it == tb.end()) {
		tb[t->getType()]  = t->clone();
	}
}
void TargetGenerator::forgetTargetType(const std::string &tt) {
	std::map<std::string, ATarget*>::iterator it = tb.find(tt);
	if (it != tb.end()) {
		delete it->second;
		tb.erase(it);
	}
}
ATarget* TargetGenerator::createTarget(const std::string &tt) {
	std::map<std::string, ATarget*>::iterator it = tb.find(tt);
	if (it != tb.end()) {
		return it->second->clone();
	}
	return NULL;
}
