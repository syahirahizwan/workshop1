#ifndef USERMANAGER_H
#define USERMANAGER_H

class UserManager
{
public:
	int registerUser(User* user);
	//int updateUser(User* user);
	bool loginUser(string username);
	bool password(string username, string password);
};
#endif
