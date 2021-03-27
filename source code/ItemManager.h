#ifndef ITEMMANAGER_H
#define ITEMMANAGER_H

class ItemManager
{
public:
	int insertItem(Item* item);
	Item* selectItem(string itemCode);
	Item* deleteItem(string itemCode);

};
#endif
