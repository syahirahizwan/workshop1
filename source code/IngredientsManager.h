#ifndef INGREDIENTSMANAGER_H
#define INGREDIENTSMANAGER_H

class IngredientsManager
{
public:
	int insertRecipeIngredients(RecipeIngredients* recipeIngredients);
	int updateRecipeIngredients(RecipeIngredients* recipeIngredients);
	RecipeIngredients* selectRecipeIngredients(int recipeId);
};

#endif