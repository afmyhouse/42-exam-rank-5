#include "Fwoosh.hpp"
#include "ASpell.hpp"

Fwoosh::Fwoosh(void) : ASpell("Fwoosh","fwooshed") {}
Fwoosh::~Fwoosh(void) {};

ASpell *Fwoosh::clone() const { return (new Fwoosh);}