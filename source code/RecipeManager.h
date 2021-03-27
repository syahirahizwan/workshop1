#ifndef RECIPEMANAGER_H
#define RECIPEMANAGER_H

class RecipeManager
{
public:
	int insertRecipe(Recipe* recipe);
	Recipe* viewRecipe(int recipeId);
	Recipe* selectRecipe(int recipeId);
};

#endif
