#include "Class.hpp"

Class::Class() {}
Class::Class(const std::string &, const std::string &) {}
Class::Class(Class const &) {}
Class & Class::operator=(Class const &) {}
Class::~Class() {}
const std::string & Class::getName() const {}
const std::string & Class::getTitle() const {}
void Class::setTitle(const std::string &) {}
void Class::introduce() const {}
