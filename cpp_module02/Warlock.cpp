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
	_wBook.learnSpell(spell);
}

void Warlock::forgetSpell(const std::string spellName) {
	_wBook.forgetSpell(spellName);
}

void Warlock::launchSpell(const std::string spellName, ATarget const &target) {
	ASpell* spell = _wBook.createSpell(spellName);
	if (spell) {
		spell->launch(target);
		delete spell;
	}
}
