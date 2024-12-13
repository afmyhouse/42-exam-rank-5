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
	wb.learnSpell(s);
}

void Warlock::forgetSpell(const std::string sn) {
	wb.forgetSpell(sn);
}

void Warlock::launchSpell(const std::string sn, ATarget const &t) {
	ASpell *spell = wb.createSpell(sn);
	if (spell) {
		spell->launch(t);
		delete spell;
	}
}
