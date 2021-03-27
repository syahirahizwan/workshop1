#include <iostream>
#include <string>
using namespace std;

#include <mysql/jdbc.h>
using namespace sql;

#include "Database.h"
#include "RecipeIngredients.h"
#include "IngredientsManager.h"

int IngredientsManager::insertRecipeIngredients(RecipeIngredients* recipeIngredients)
{
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement("INSERT INTO RecipeIngredients VALUES (?, ?, ?)");


	ps->setString(1, recipeIngredients->recipeId);
	ps->setString(2, recipeIngredients->ingredientName);
	ps->setString(3, recipeIngredients->amount);

	int status = ps->executeUpdate();

	delete ps;


		return status;
}

RecipeIngredients* IngredientsManager::selectRecipeIngredients(int recipeId)
{
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement("SELECT * FROM RecipeIngredients WHERE recipeId = ?");
	
	ps->setInt(1, recipeId);

	ResultSet* rs = ps->executeQuery();
	ResultSetMetaData* rs_meta = rs->getMetaData();
	int columns = rs_meta->getColumnCount();

	RecipeIngredients* recipeIngredients = NULL;

	//Loop for each row
	while (rs->next())
	{
		cout << "\t\t\t\t" << rs->getString(3) << " " << rs->getString(2) << "\n";
	}

	delete rs;
	delete ps;

	return recipeIngredients;
}