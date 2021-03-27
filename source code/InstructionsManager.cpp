#include <iostream>
#include <string>
using namespace std;

#include <mysql/jdbc.h>
using namespace sql;

#include "Database.h"
#include "Instructions.h"
#include "InstructionsManager.h"

int InstructionsManager::insertInstructions(Instructions* instructions)
{
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement("INSERT INTO instructions VALUES (?, ?, ?)");

	ps->setInt(1, instructions->recipeId);
	ps->setString(2, instructions->steps);
	ps->setString(3, instructions->description);

	int status = ps->executeUpdate();

	delete ps;

	return status;

}

Instructions* InstructionsManager::selectInstructions(int recipeId)
{
	Instructions* instructions = NULL;
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement("SELECT * FROM instructions WHERE recipeId = ?");
	
	ps->setInt(1, recipeId);

	ResultSet* rs = ps->executeQuery();
	ResultSetMetaData* rs_meta = rs->getMetaData();
	int columns = rs_meta->getColumnCount();


	while (rs->next())
	{
		instructions = new Instructions();
		cout << "\t\t\t\t" << rs->getString(2) << " " << rs->getString(3) << "\n";

		/*instructions->recipeId = rs->getString(1);
		instructions->steps = rs->getString(2);
		instructions->description = rs->getString(3);*/
	}

	delete rs;
	delete ps;

	return instructions;
}