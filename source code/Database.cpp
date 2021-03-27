#include <string>
using namespace std;

#include <mysql/jdbc.h>
using namespace sql;

#include "Database.h"

DatabaseConnection::DatabaseConnection()
{
	mysql::MySQL_Driver* driver = mysql::get_mysql_driver_instance();
	connection = driver->connect("tcp://127.0.0.1:3306", "root", "");

	connection->setSchema("dbsos");
}

DatabaseConnection::~DatabaseConnection()
{
	connection->close();
	delete connection;
}

PreparedStatement* DatabaseConnection::prepareStatement(string query)
{
	return connection->prepareStatement(query);
}