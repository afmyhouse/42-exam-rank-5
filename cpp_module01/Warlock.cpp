#include "Warlock.hpp"

Warlock::Warlock(const std::string &name, const std::string &title)
	: _name(name), _title(title) {
	std::cout << _name << ": This looks like another boring day." << std::endl;
}
Warlock::~Warlock() {
	std::cout << _name << ": My job here is done!" << std::endl;
}
const std::string & Warlock::getName() const {
	return (_name);
}
const std::string & Warlock::getTitle() const {
	return (_title);
}
void Warlock::setTitle(const std::string &newTitle) {
	_title = newTitle;
}
void Warlock::introduce() const {
	std::cout << _name << ": I am " << _name <<", " << _title << "!" << std::endl;
}

void Warlock::learnSpell(ASpell*spell) {
	if (spell && _wBook.find(spell->getName()) == _wBook.end()) {
		_wBook[spell->getName()] = spell->clone();
	}
}

void Warlock::forgetSpell(const std::string spellName) {
	std::map<std::string, ASpell*>::iterator it = _wBook.find(spellName);
	if (it != _wBook.end()) {
		delete it->second;
		_wBook.erase(it);
	}
}

void Warlock::launchSpell(const std::string spellName, ATarget const &target) {
	std::map<std::string, ASpell*>::iterator it = _wBook.find(spellName);
	if (it != _wBook.end()) {
		it->second->launch(target);
	}
}
