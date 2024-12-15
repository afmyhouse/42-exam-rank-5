#include "Warlock.hpp"

Warlock::Warlock(const std::string &name, const std::string &title)
	:_warlockName(name), _warlockTitle(title) {
		std::cout << _warlockName << ": This looks like another boring day." << std::endl;
	}

Warlock::~Warlock() {
		std::cout << _warlockName << ": My job here is done!" << std::endl;
}

const std::string & Warlock::getName() const {
	return _warlockName;
}

const std::string & Warlock::getTitle() const {
	return _warlockTitle;
}

void Warlock::setTitle(const std::string &nt) {
	_warlockTitle = nt;
}

void Warlock::introduce() const {
		std::cout << _warlockName << ": I am " << _warlockName << ", " << _warlockTitle << "!" << std::endl;
}

void Warlock::learnSpell(ASpell* spell) {
	_warlockBook.learnSpell(spell);
}

void Warlock::forgetSpell(const std::string _spellName) {
	_warlockBook.forgetSpell(_spellName);
}

void Warlock::launchSpell(const std::string _spellName, ATarget const &target) {
	ASpell *spell = _warlockBook.createSpell(_spellName);
	if (spell) {
		spell->launch(target);
		delete spell;
	}
}
