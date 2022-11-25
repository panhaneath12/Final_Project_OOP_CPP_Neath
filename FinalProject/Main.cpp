#include<iostream>
#include"UserManager.cpp"
#include"Application.cpp"
int main()
{
	Application application;
	UserManager userManager;
	string username;
	string password;
	do {
		cout << "===========Login===========" << endl;
		cout << "Enter username: ";
		cin >> username;
		cout << "Password: ";
		cin >> password;
		User* user = userManager.authenticateUser(username, password);
		if (user != nullptr) {
			if (user->getType() == "ADMIN") {
				application.runApp();
			}
			else if (user->getType() == "NORMAL") {
				application.runApp2();
			}
		}
		else {
			cout << "Invalid user" << endl;
		}
	} while (true);

}
