#include <iostream>
#include <string>
using namespace std;

#include <mysql/jdbc.h>
using namespace sql;

#include "Database.h"
#include "Recipe.h"
#include "RecipeManager.h"

int RecipeManager::insertRecipe(Recipe* recipe)
{
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement("INSERT INTO Recipe VALUES (?, ?)");

	ps->setString(1, recipe->recipeId);
	ps->setString(2, recipe->recipeName);

	int status = ps->executeUpdate();

	delete ps;
	return status;
}

Recipe* RecipeManager::viewRecipe(int recipeId)
{
	Recipe* recipe = NULL;
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement("SELECT * FROM Recipe ORDER BY Recipe.recipeId ASC");

	//ps->setInt(1, recipeId);

	ResultSet* rs = ps->executeQuery();
	ResultSetMetaData* rs_meta = rs->getMetaData();
	int columns = rs_meta->getColumnCount();

	while (rs->next())
	{
		recipe = new Recipe();

		cout << "\t\t\t\t-------------------------\n" << "\t\t\t\tRecipe ID: " << rs->getString(1) << "\n\t\t\t\tRecipe Name: " << rs->getString(2) 
			<< "\n\t\t\t\t-------------------------\n\n";
	}

	delete rs;
	delete ps;

	return recipe;
}

Recipe* RecipeManager::selectRecipe(int recipeId)
{
	Recipe* recipe = NULL;
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement("SELECT * FROM Recipe WHERE recipeId = ?");

	ps->setInt(1, recipeId);

	ResultSet* rs = ps->executeQuery();

	if (rs->next())
	{
		recipe = new Recipe();
		
		recipe->recipeId = rs->getString(1);
		recipe->recipeName = rs->getString(2);
	}

	delete rs;
	delete ps;

	return recipe;
}