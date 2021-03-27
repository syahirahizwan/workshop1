#ifndef INSTRUCTIONSMANAGER_H
#define INSTRUCTIONSMANAGER_H

class InstructionsManager
{
public:
	int insertInstructions(Instructions* instructions);
	int updateInstructions(Instructions* instructions);
	Instructions* selectInstructions(int recipeId);
};

#endif