#include "Warlock.hpp"

Warlock::Warlock(const std::string &name, const std::string &title)
	:_warlockName(name), _warlockTitle(title) {
		std::cout << _warlockName << ": This looks like another boring day." << std::endl;
	}

Warlock::~Warlock() {
		std::cout << _warlockName << ": My job here is done!" << std::endl;
		std::map<std::string, ASpell*>::iterator it;
		for (it = _warlockBook.begin(); it != _warlockBook.end(); ++it ) {
			delete it->second;
		}
		_warlockBook.clear();
}

const std::string & Warlock::getName() const {
	return _warlockName;
}

const std::string & Warlock::getTitle() const {
	return _warlockTitle;
}

void Warlock::setTitle(const std::string &newTitle) {
	_warlockTitle = newTitle;
}

void Warlock::introduce() const {
		std::cout << _warlockName << ": I am " << _warlockName << ", " << _warlockTitle << "!" << std::endl;
}

void Warlock::learnSpell(ASpell* spell) {
	std::map<std::string, ASpell*>::iterator it = _warlockBook.find(spell->getName());
	if (it == _warlockBook.end()) {
		_warlockBook[spell->getName()] = spell->clone();
	}
}

void Warlock::forgetSpell(const std::string spellName) {
	std::map<std::string, ASpell*>::iterator it = _warlockBook.find(spellName);
	if (it != _warlockBook.end()) {
		delete it->second;
		_warlockBook.erase(it);
	}
}

void Warlock::launchSpell(const std::string spellName, ATarget const &target) {
	std::map<std::string, ASpell*>::iterator it = _warlockBook.find(spellName);
	if (it != _warlockBook.end()) {
		it->second->launch(target);
	}
}
