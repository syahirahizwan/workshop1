#include <iostream>
#include <string>
#include <conio.h>

using namespace std;

#include "Item.h"
#include "ItemManager.h"
#include "Instructions.h"
#include "InstructionsManager.h"
#include "RecipeIngredients.h"
#include "IngredientsManager.h"
#include "Recipe.h"
#include "RecipeManager.h"
#include "User.h"
#include "UserManager.h"

int num;
int y;
char x;
int intRecipeId;
string strPassword[100];
int intUsername[100];
string strRecipeName;
Item* item = new Item();
ItemManager itemManager;
Recipe* recipe = new Recipe();
RecipeManager recipeManager;
RecipeIngredients* ingredients = new RecipeIngredients();
IngredientsManager ingredientsManager;
Instructions* instructions = new Instructions();
InstructionsManager instructionsManager;
User* user = new User();
UserManager userManager;
void welcome();

//void itemDelete()
//{
//	cout << "\t\t\t\t  _________________________________________________\n\n";
//	cout << "\t\t\t\t  ------------------- VIEW ITEM -------------------\n\n";
//	cout << "\t\t\t\t  _________________________________________________\n\n";
//	string itemCode;
//	cout << "\t\t\t\tInsert item code for item you want to delete.\n\t\t\t\tItem Code : ";
//	cin >> itemCode;
//
//	Item* item = itemManager.deleteItem(itemCode);
//	cout << "\n\t\t\t\tItem has been deleted.";
//}

void userRegister()
{
	cout << "\t\t\t\t  _________________________________________________\n\n";
	cout << "\t\t\t\t  --------------------REGISTER---------------------\n\n";
	cout << "\t\t\t\t  _________________________________________________\n\n";
	cout << "\t\t\t\tUsername : ";
	cin >> user->username;
	cout << "\t\t\t\tNew password (less than 8 characters) : ";
	cin >> user->password;

	int status = userManager.registerUser(user);		// register new user into database


	//show successful or unsuccessful process
	if (status != 0)
		cout << "\t\t\t\tSuccessful registration." << endl;
	else
		cout << "\t\t\t\tRegistration fail." << endl;
}

//function to add item into database
void addItem()
{
	cout << "\t\t\t\t  _________________________________________________\n\n";
	cout << "\t\t\t\t  --------------------ADD ITEM---------------------\n\n";
	cout << "\t\t\t\t  _________________________________________________\n\n";
	cout << "\n\t\t\t\tPlease insert new item details as stated\n";
	cout << "\t\t\t\tItem Code : ";
	cin >> item->itemCode;
	cout << "\t\t\t\tItem Name : ";
	cin.ignore();
	getline(cin, item->itemName);
	cout << "\t\t\t\tQuantity : ";
	cin >> item->quantity;
	cout << "\t\t\t\tExpiry Date (YYYYMMDD) : ";
	cin >> item->expiryDate;

	int status = itemManager.insertItem(item);		// insert item into database


	//show successful or unsuccessful process
	if (status != 0)
		cout << "\t\t\t\tItem is successfully added." << endl;
	else
		cout << "\t\t\t\tUnable to add new item." << endl;
}

//function to search for items in database
void searchItem()
{
	cout << "\t\t\t\t  _________________________________________________\n\n";
	cout << "\t\t\t\t  ------------------- VIEW ITEM -------------------\n\n";
	cout << "\t\t\t\t  _________________________________________________\n\n";
	string itemCode;

	Item* item = itemManager.selectItem(itemCode);
}

//functions to add recipe
void addRecipe()
{
	cout << "\t\t\t\t  _________________________________________________\n\n";
	cout << "\t\t\t\t  --------------------ADD RECIPE-------------------\n\n";
	cout << "\t\t\t\t  _________________________________________________\n\n";
	cout << "\t\t\t\tPlease insert new recipe details." << endl;
	cout << "\t\t\t\tRecipe Id : ";
	cin >> recipe->recipeId;
	cout << "\t\t\t\tRecipe Name : ";
	cin.ignore();
	getline(cin, recipe->recipeName);

	int status = recipeManager.insertRecipe(recipe);

	if (status != 0)
		cout << "\t\t\t\tSuccessfully added new recipe." << endl;
	else
		cout << "\t\t\t\tUnable to add new recipe." << endl;
}

//function to search for recipes in the database
void searchRecipe()
{
	cout << "\t\t\t\t  _________________________________________________\n\n";
	cout << "\t\t\t\t  ------------------SEARCH RECIPE------------------\n\n";
	cout << "\t\t\t\t  _________________________________________________\n\n";
	
	Recipe* recipe = recipeManager.viewRecipe(intRecipeId);
	
	cout << "\n\t\t\t\tPlease enter the recipe you want to search." << endl;
	cout << "\t\t\t\tRecipe Id : ";
	cin >> intRecipeId;

	system("pause");
	system("CLS");
	Recipe* recipe2 = recipeManager.selectRecipe(intRecipeId);
	
	cout << "\n\t\t\t\tThe name for the recipe is " << recipe->recipeName << "." << endl;
}

//function to add ingredient
void addIngredients()
{
	cout << "\n\t\t\t\tRecipe Id : ";
	cin >> ingredients->recipeId;
	cout << "\t\t\t\tIngredient Name : ";
	cin.ignore();
	getline(cin, ingredients->ingredientName);
	//cin >> ingredients->ingredientName;
	cout << "\t\t\t\tAmount : ";
	cin >> ingredients->amount;

	int status = ingredientsManager.insertRecipeIngredients(ingredients);

	if (status != 0)
		cout << "\t\t\t\tIngredients has been successfully added." << endl;
	else
		cout << "\t\t\t\tUnable to add a new ingredient." << endl;
}

//function to search for ingredients in the database
void searchIngredients()
{
	cout << "\n\t\t\t\tThe ingredients are :\n\n";
	RecipeIngredients* ingredients = ingredientsManager.selectRecipeIngredients(intRecipeId);
}

//function to add instructions
void addInstructions()
{
	cout << "\n\t\t\t\tRecipe Id : ";
	cin >> instructions->recipeId;
	cout << "\t\t\t\tStep number : ";
	cin >> instructions->steps;
	cout << "\t\t\t\tInstructions : ";
	cin.ignore();
	getline(cin, instructions->description);
	//cin >> instructions->description;

	int status = instructionsManager.insertInstructions(instructions);

	if (status != 0)
		cout << "Instruction has been succesfully added." << endl;
	else
		cout << "Unable to add instruction." << endl;
}

//function to search for instructions in the database
void searchInstructions()
{
	InstructionsManager instructionsManager;
	cout << "\n\t\t\t\tThe instructions are : \n\n";
	Instructions* instructions = instructionsManager.selectInstructions(intRecipeId);
}


void menu()
{
	cout << "\t\t\t\t  _________________________________________________\n";
	cout << "\t\t\t\t  _________________________________________________\n\n";
	cout << "\t\t\t\t\tWELCOME TO HOUSEHOLD ORGANIZER SYSTEM\n\n";
	cout << "\t\t\t\t  _________________________________________________\n";
	cout << "\t\t\t\t  _________________________________________________\n\n";
	cout << "\t\t\t\tInsert number to choose" << endl;
	cout << "\t\t\t\t1. Item\n\t\t\t\t2. Recipe" << endl << "\t\t\t\tAnswer : ";
	cin >> num;

	//opening item's table
	if (num == 1)
	{
		system("CLS");
		int i;
		cout << "\t\t\t\t  _________________________________________________\n\n";
		cout << "\t\t\t\t  ---------------------- ITEM ---------------------\n\n";
		cout << "\t\t\t\t  _________________________________________________\n\n";
		cout << "\n\t\t\t\tInsert your selection." << endl;
		cout << "\t\t\t\t1. Add new item\n" << "\t\t\t\t2. Display item" 
			<< "\n\t\t\t\t3. Return to main menu" << endl << "\t\t\t\tAnswer : ";
		cin >> i;

		//to add new item
		if (i == 1)
		{
			system("CLS");
			addItem();
			cout << "\n\n\t\t\t\tDo you want to add another item?\n\t\t\t\tType y for yes and n for no.\n\t\t\t\tAnswer : ";
			cin >> x;
			if (x == 'y' || x == 'Y')
			{
				system("CLS");
				addItem();
				cout << "\t\t\t\t";
				system("pause");
				system("CLS");
				return menu();
			}
			else if (x == 'n' || x == 'N')
			{
				cout << "\n\t\t\t\tDo you want to search for item?\n\t\t\t\tPress y for yes.\n\t\t\t\tAnswer : ";
				cin >> x;
				if (x == 'y' || x == 'Y')
				{
					searchItem();
					system("pause");
					system("CLS");
					return menu();
				}
				else
				{
					system("CLS");
					menu();
				}
			}
			else
			{
				cout << "\n\t\t\t\tError!!!!!! Please try again.\n\t\t\t\t";
				system("pause");
				system("CLS");
				return menu();
			}
		}

		//to display items
		else if (i == 2)
		{
			system("CLS");
			searchItem();
			cout << "\t\t\t\t";
			system("pause");
			system("CLS");
			return menu();
		}
		//to delete item
		else if (i == 3)
		{
			system("CLS");
			return menu();
		}
		else
		{
			cout << "\n\t\t\t\tThe number does not exist :( Please try again.\n\t\t\t\t";
			system("pause");
			system("CLS");
			return menu();
		}
	}
	//opening recipe's table
	else if (num == 2)
	{
		system("CLS");
		int r;
		cout << "\t\t\t\t  _________________________________________________\n\n";
		cout << "\t\t\t\t  --------------------- RECIPE --------------------\n\n";
		cout << "\t\t\t\t  _________________________________________________\n\n";
		cout << "\n\n\t\t\t\tInsert your selection : " << endl;
		cout << "\t\t\t\t1. Add new recipe\n" << "\t\t\t\t2. Search recipe" << "\n\t\t\t\t3. Others" << "\n\t\t\t\t4. Return to main" << endl << "\t\t\t\tAnswer : ";
		cin >> r;

		//to add new recipe
		if (r == 1)
		{
			system("CLS");
			addRecipe();
			cout << "\n\t\t\t\tDo you want to add ingredient(s)? Type 'y' to proceed : ";
			cin >> x;
			if (x == 'Y' || x == 'y')
			{
				cout << "\n\t\t\t\tHow many ingredients are there?\n\t\t\t\tAnswer : ";
				cin >> y;
				for (int i = 0; i < y; i++)
				{
					addIngredients();
				}
			}
			else
			{
				system("CLS");
				menu();
			}
			cout << "\n\t\t\t\tDo you want to add instruction(s)? Type 'y' to proceed : ";
			cin >> x;
			if (x == 'y' || x == 'Y')
			{
				cout << "\n\t\t\t\tHow many instructions are there?\n\t\t\t\tAnswer : ";
				cin >> y;
				for (int i = 0; i < y; i++)
				{
					addInstructions();
				}
			}
			else
			{
				system("CLS");
				menu();
			}
		}

		//to search for recipe(s)
		else if (r == 2)
		{
			system("CLS");
			searchRecipe();
			cout << "\t\t\t\tDo you want to look at the ingredients used to make this dish?" << endl;
			cout << "\t\t\t\tType y to proceed : ";
			cin >> x;

			if (x == 'y' || x == 'Y')
			{
				searchIngredients();
				cout << "\n\t\t\t\tDo you want to proceed with instructions to cook this dish?" << endl;
				cout << "\t\t\t\tType y to proceed : ";
				cin >> x;

				if (x == 'y' || x == 'Y')
				{
					searchInstructions();
					cout << "\t\t\t\t";
					system("pause");
					system("CLS");
					return menu();
				}
				else
				{
					system("CLS");
					return menu();
				}
			}
			else
			{
				system("CLS");
				return menu();
			}
		}
		else if (r == 3)
		{
			system("CLS");
			cout << "\t\t\t\t  _________________________________________________\n\n";
			cout << "\t\t\t\t  --------------------- RECIPE --------------------\n\n";
			cout << "\t\t\t\t  _________________________________________________\n\n";
			cout << "\n\n\t\t\t\tInsert your selection : " << endl;
			cout << "\t\t\t\t1. Add ingredient\n" << "\t\t\t\t2. Add Instruction" << "\n\t\t\t\t3. Return to main" << endl << "\t\t\t\tAnswer : ";
			cin >> r;

			if (r == 1)
			{
				cout << "\n\t\t\t\tHow many ingredient(s) do you want to add?\n\t\t\t\tAnswer : ";
				cin >> y;
				for (int i = 0; i < y; i++)
				{
					addIngredients();
				}
			}
			else if (r == 2)
			{
				cout << "\n\t\t\t\tHow many instruction(s) do you want to add?\n\t\t\t\tAnswer : ";
				cin >> y;
				for (int i = 0; i < y; i++)
				{
					addInstructions();
				}
			}
			else if (r == 3)
			{
				system("CLS");
				return menu();
			}
			else
			{
				cout << "\n\t\t\t\tThe number does not exist :( Please try again.\n\t\t\t\t";
				system("pause");
				system("CLS");
				return menu();
			}
		}
		else if (r == 4)
		{
			system("CLS");
			return menu();
		}
		else
		{
			cout << "\n\t\t\t\tThe number does not exist :( Please try again.\n\t\t\t\t";
			system("pause");
			system("CLS");
			return menu();
		}
	}
	else
	{
		cout << "\n\t\t\t\tThe number does not exist :( Please try again.\n\t\t\t\t";
		system("pause");
		system("CLS");
		return menu();
	}
}

void userPwd(string username)
{
	string password;
	int retryCount = 0;
	char c;

	retry:
	cout << "\t\t\t\tPlease enter password : ";
	/*cin >> password;*/
	c = NULL;
	password = "";

	do {
		c = _getch();
		switch (c) {
		case 0://special keys. like: arrows, f1-12 etc.
			_getch();//just ignore also the next character.
			break;
		case 13://enter
			cout << endl;
			break;
		case 8://backspace
			if (password.length() > 0) {
				password.erase(password.end() - 1); //remove last character from string
				cout << c << ' ' << c;//go back, write space over the character and back again.
			}
			break;
		default://regular ascii
			password += c;//add to string
			cout << '*';//print `*`
			break;
		}
	} while (c != 13);

	bool blnLogin = userManager.password(username, password);

	if (blnLogin == true)
	{
		system("CLS");
		menu();
	}
	else
	{
		cout << "\n\t\t\t\tIncorrect password. Please try again.\n\n";
		retryCount++;
		
		if(retryCount < 3)
		{
			goto retry;
		}
		else
		{
			cout << "\n\t\t\t\tIncorrect password. Maximum number of retry attempts reached.\n\t\t\t\t";
			system("pause");
			system("CLS");
			welcome();
		}
	}
}

void userLogin()
{
	string username;

	cout << "\t\t\t\t  _________________________________________________\n\n";
	cout << "\t\t\t\t  -------------------- LOGIN ----------------------\n\n";
	cout << "\t\t\t\t  _________________________________________________\n\n";
	cout << "\t\t\t\tUsername : ";
	cin >> username;

	bool blnUserExist = userManager.loginUser(username);

	if (blnUserExist == true)
	{
		userPwd(username);
		system("pause");
		system("CLS");

	}
	else
	{
		cout << "\t\t\t\tUsername does not exist. Please try again.\n\t\t\t\t";
		system("pause");
		system("CLS");
		userLogin();

	}
}

void welcome()
{
	cout << "\t\t\t\t  _________________________________________________\n";
	cout << "\t\t\t\t  _________________________________________________\n\n";
	cout << "\t\t\t\t\tWELCOME TO HOUSEHOLD ORGANIZER SYSTEM\n\n";
	cout << "\t\t\t\t  _________________________________________________\n";
	cout << "\t\t\t\t  _________________________________________________\n\n";
	cout << "\t\t\t\tInsert number to choose" << endl;
	cout << "\t\t\t\t1. Register new account\n\t\t\t\t2. Login" << endl << "\t\t\t\tAnswer : ";
	cin >> num;
	if (num == 1)
	{
		system("CLS");
		userRegister();
		system("pause");
		system("CLS");
		userLogin();

	}
	else if (num == 2)
	{
		system("CLS");
		userLogin();
	}
	else
	{
		cout << "\n\t\t\t\tThe number does not exist. Please try again.";
		welcome();
	}
}

int main()
{
	welcome();
}
