#include "Warlock.hpp"

Warlock::Warlock(std::string const &name, std::string const &title) : _name(name), _title(title) {
	std::cout << this->_name << ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock(void) {std::cout << this->_name << ": My job here is done!" << std::endl;
	for (std::map<std::string, ASpell *>::iterator it= _SpellBook.begin(); it !=_SpellBook.end(); it++){
		delete it->second;
	}
}

std::string const Warlock::getName(void) const {return (this->_name);}

std::string const  Warlock::getTitle(void) const {return(this->_title);}

void Warlock::setTitle(std::string const &newTitle) {this->_title = newTitle;}

void Warlock::introduce(void) const {std::cout<< this->_name <<": I am "<< this->_name << ", "<< this->_title<<"!"<<std::endl;}

void Warlock::learnSpell(ASpell *spell) {
	if (spell)
		if (_SpellBook.find(spell->getName()) == _SpellBook.end())
			_SpellBook[spell->getName()] = spell->clone();
 }

void Warlock::forgetSpell(std::string const &spellName) {
	if (_SpellBook.find(spellName) != _SpellBook.end()) {
		delete _SpellBook[spellName];
		_SpellBook.erase(_SpellBook.find(spellName));
	}
}

void Warlock::launchSpell(std::string spellName, ATarget const &target) {
	if (_SpellBook.find(spellName) != _SpellBook.end())
		_SpellBook[spellName]->launch(target);
}