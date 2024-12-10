#include "Dummy.hpp"
#include  "ATarget.hpp"

Dummy::Dummy(void) : ATarget("Target Practice Dummy") {}
Dummy::~Dummy(void) {}

ATarget *Dummy::clone(void) const {return (new Dummy);}