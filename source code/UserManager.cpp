#include <iostream>
#include <string>
using namespace std;

#include <mysql/jdbc.h>
using namespace sql;

#include "Database.h"
#include "User.h"
#include "UserManager.h"

int UserManager::registerUser(User* user)
{
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement("INSERT INTO User VALUES (?, ?)");

	ps->setString(1, user->username);
	ps->setString(2, user->password);

	int status = ps->executeUpdate();

	delete ps;
	return status;
}

bool UserManager::loginUser(string username)
{
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement("SELECT * FROM User WHERE username = ?");

	ps->setString(1, username);

	ResultSet* rs = ps->executeQuery();

	if (rs->next())
	{
		return true;
	}
	else
	{
		return false;
	}

	delete rs;
	delete ps;
}

bool UserManager::password(string username, string password)
{
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement("SELECT * FROM User WHERE username = (?) and password = (?)");

	ps->setString(1, username);
	ps->setString(2, password);

	ResultSet* rs = ps->executeQuery();

	if (rs->next())
	{
		return true;
	}
	else
	{
		return false;
	}

	delete rs;
	delete ps;
}