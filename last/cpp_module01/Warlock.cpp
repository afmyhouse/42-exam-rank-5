#include "Warlock.hpp"

Warlock::Warlock(const std::string &n, const std::string &t)
	:wn(n), wt(t) {
		std::cout << wn << ": This looks like another boring day." << std::endl;
	}

Warlock::~Warlock() {
		std::cout << wn << ": My job here is done!" << std::endl;
}

const std::string & Warlock::getName() const {
	return wn;
}

const std::string & Warlock::getTitle() const {
	return wt;
}

void Warlock::setTitle(const std::string &nt) {
	wt = nt;
}

void Warlock::introduce() const {
		std::cout << wn << ": I am " << wn << ", " << wt << "!" << std::endl;
}

void Warlock::learnSpell(ASpell* s) {
	std::map<std::string, ASpell*>::iterator it = wb.find(s->getName());
	if (it == wb.end()) {
		wb[s->getName()] = s->clone();
	}
}

void Warlock::forgetSpell(const std::string sn) {
	std::map<std::string, ASpell*>::iterator it = wb.find(sn);
	if (it != wb.end()) {
		delete it->second;
		wb.erase(it);
	}
}

void Warlock::launchSpell(const std::string sn, ATarget const &t) {
	std::map<std::string, ASpell*>::iterator it = wb.find(sn);
	if (it != wb.end()) {
		it->second->launch(t);
	}
}
