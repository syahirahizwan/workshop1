#include <iostream>
#include <string>
using namespace std;

#include <mysql/jdbc.h>
using namespace sql;

#include "Database.h"
#include "Item.h"
#include "ItemManager.h"

int ItemManager::insertItem(Item* item)
{
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement("INSERT INTO item VALUES (?, ?, ?, ?)");

	ps->setString(1, item->itemCode);
	ps->setString(2, item->itemName);
	ps->setString(3, item->quantity);
	ps->setString(4, item->expiryDate);

	int status = ps->executeUpdate();

	delete ps;
	return status;
}

Item* ItemManager::selectItem(string itemCode)
{
	Item* item = NULL;
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement("SELECT * FROM Item ORDER BY Item.expiryDate ASC");

	//ps->setString(1, itemCode);

	ResultSet* rs = ps->executeQuery();
	ResultSetMetaData* rs_meta = rs->getMetaData();
	int columns = rs_meta->getColumnCount();

	while (rs->next())
	{
		item = new Item();

		cout << "\t\t\t\t-----------------------\n" << "\t\t\t\tItem Code: " << rs->getString(1) << "\n\t\t\t\tName: " << rs->getString(2) 
			<< "\n\t\t\t\tQuantity: " << rs->getString(3) << "\n\t\t\t\tExpiry Date: " << rs->getString(4) << "\n\t\t\t\t-----------------------\n\n";
	}

	delete rs;
	delete ps;

	return item;
}

