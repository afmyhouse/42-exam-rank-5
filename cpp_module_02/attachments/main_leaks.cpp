#include "Warlock.hpp"
#include "Dummy.hpp"
#include "Fwoosh.hpp"
#include "SpellBook.hpp"
#include "TargetGenerator.hpp"
#include "BrickWall.hpp"
#include "Polymorph.hpp"
#include "Fireball.hpp"
#include <iostream>

//### leaks oriented main.cpp ###
int main() {
	{
		// Create a Warlock
		Warlock merlin("Merlin", "Master of Magic");

		// Introduce the Warlock
		merlin.introduce();

		// Create and learn spells
		Fwoosh fwoosh;
		Fireball fireball;
		Polymorph polymorph;

		merlin.learnSpell(&fwoosh);
		merlin.learnSpell(&fireball);
		merlin.learnSpell(&polymorph);

		// Create targets
		Dummy dummy;
		BrickWall wall;

		// Launch spells at targets
		merlin.launchSpell("Fwoosh", dummy);
		merlin.launchSpell("Fireball", wall);
		merlin.launchSpell("Polymorph", dummy);

		// Forget a spell and try launching it
		merlin.forgetSpell("Fireball");
		merlin.launchSpell("Fireball", wall); // Should not launch; spell is forgotten

		// Edge cases
		merlin.launchSpell("NonexistentSpell", dummy); // Should not launch; doesn't exist
	}

	// Test memory cleanup for SpellBook
	{
		SpellBook spellBook;

		// Add spells to SpellBook
		Fwoosh fwoosh;
		Fireball fireball;

		spellBook.learnSpell(&fwoosh);
		spellBook.learnSpell(&fireball);

		// Forget a spell
		spellBook.forgetSpell("Fwoosh");

		// Create spell and delete afterward
		ASpell* clonedFireball = spellBook.createSpell("Fireball");
		if (clonedFireball) {
			std::cout << "Cloned spell: " << clonedFireball->getName() << " created successfully." << std::endl;
			delete clonedFireball;
		}

		// Attempt to create a nonexistent spell
		ASpell* nonexistentSpell = spellBook.createSpell("NonexistentSpell");
		if (!nonexistentSpell) {
			std::cout << "Nonexistent spell could not be created." << std::endl;
		}
	}

	// Test memory cleanup for TargetGenerator
	{
		TargetGenerator targetGen;

		// Add targets
		Dummy dummy;
		BrickWall wall;

		targetGen.learnTargetType(&dummy);
		targetGen.learnTargetType(&wall);

		// Forget a target type
		targetGen.forgetTargetType("Target Practice Dummy");

		// Create target and delete afterward
		ATarget* clonedWall = targetGen.createTarget("Inconspicuous Red-brick Wall");
		if (clonedWall) {
			std::cout << "Cloned target: " << clonedWall->getType() << " created successfully." << std::endl;
			delete clonedWall;
		}

		// Attempt to create a nonexistent target
		ATarget* nonexistentTarget = targetGen.createTarget("NonexistentTarget");
		if (!nonexistentTarget) {
			std::cout << "Nonexistent target could not be created." << std::endl;
		}
	}

	// Final message
	std::cout << "All tests completed successfully." << std::endl;

	return 0;
}
