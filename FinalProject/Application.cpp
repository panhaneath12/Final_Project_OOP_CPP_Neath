#pragma once
#include<iostream>
#include"Coffee.cpp"
#include"UserManager.cpp"
#include"SilverMember.cpp"
#include"GoldMember.cpp"
#include"NormalMember.cpp"
#include"OrderRepo.cpp"

class Application {
public:

	void runApp()
	{
		char ch;
		int num = 0;
		int op = 0;
		UserManager userManager;
		do
		{
			system("cls");
			cout << "\n\n=================ADMIN MENU===================";
			cout << "\n\n\t01. ADD NEW USER";
			cout << "\n\n\t02. VIEW ALL USERS";
			cout << "\n\n\t03. EDIT A USER";
			cout << "\n\n\t04. DELETE A USER";
			cout << "\n\n\t00. EXIT";
			cout << "\n\n\tSelect Your Option (0-4) ";
			cin >> ch;
			system("cls");
			switch (ch)
			{
			case '1': {
				User user;
				user.inputUser();
				//userManager.addUser(user);
				userManager.writeUserToFile(user);
				break;
			}
			case '2':
				userManager.viewUser();
				//userManager.readUserFromFile();
				break;
			case '3': {
				string username;
				cout << "Enter username:";
				cin >> username;
				userManager.editUser(username);
				break;
			}
			case '4': {
				string username;
				cout << "Enter username:";
				cin >> username;
				userManager.deleteUser(username);
				break;
			}
			case '0':
				exit(1);
				break;
			default:
				cout << "\a";
			}
			cin.ignore();
			cin.get();
		} while (ch != '0');
	}
	void runApp2()
	{
		char ch;
		int num = 0;
		int op = 0;
		int orderID;
		Coffee coffee;
		OrderRepo orderRepo;
		GoldMember* goldmember = nullptr;
		SilverMember* silvermember = nullptr;
		NormalMember* normalmember = nullptr;
		char choice;
		enum customerType
		{
			GOLDMEMBER = 1, SILVERMEMBER = 2, NORMALMEMBER = 3
		};
		enum menuType {
			NEW_CUSTOMER = '1', UPDATE_CUSTOMER = '2', SEARCH_CUSTOMER = '3', SORT_CUSTOMER = '4', DELETE_CUSTOMER = '5', VIEWS_ALL_CUSTOMER = '6', EXIT = '7'
		};
		do
		{
			system("cls");
			cout << "\n\t=================Coffee Shop Mangement==================";
			cout << "\n\n\t======================MAIN MENU========================";
			cout << "\n\n\t01. NEW CUSTOMER";
			cout << "\n\n\t02. UPDATE CUSTOMER";
			cout << "\n\n\t03. SEARCH CUSTOMER";
			cout << "\n\n\t04. SORT CUSTOMER";
			cout << "\n\n\t05. DELETE CUSTOMER";
			cout << "\n\n\t06. VIEWS ALL CUSTOMER";
			cout << "\n\n\t07. EXIT";
			cout << "\n\n\tSelect Your Option (0-6) ";
			cin >> ch;
			system("cls");
			switch (ch)
			{
			case menuType::NEW_CUSTOMER:
				do {
					cout << "=======Menu======" << endl;
					cout << "1. Gold Member" << endl;
					cout << "2. Silver Member" << endl;
					cout << "3. Normal Member" << endl;
					cout << "Please enter option: " << endl;
					cin >> op;
					switch (op) {
					case customerType::GOLDMEMBER:
						goldmember = new GoldMember();
						goldmember->inputGoldMember();
						coffee.addMember(goldmember);
						break;
					case customerType::SILVERMEMBER:
						silvermember = new SilverMember();
						silvermember->inputSilverMember();
						coffee.addMember(silvermember);
						break;
					case customerType::NORMALMEMBER:
						normalmember = new NormalMember();
						normalmember->inputNormalMember();
						coffee.addMember(normalmember);
						break;
					default:
						cout << "Invalid" << endl;
						break;
					}
					cout << "Do you want to continue(y/n)";
					cin >> choice;
				} while (choice != 'n');
				break;
			case menuType::UPDATE_CUSTOMER:
				cout << "Input Customer ID: ";
				cin >> num;
				coffee.editMember(num);
				break;
			case menuType::SEARCH_CUSTOMER:
				cout << "Input Customer ID: ";
				cin >> num;
				coffee.searchMember(num);
				break;
			case menuType::SORT_CUSTOMER:
				coffee.sortMember();
				break;
			case menuType::DELETE_CUSTOMER:
				cout << "Input Customer ID: ";
				cin >> num;
				coffee.deleteMember(num);
				break;
			case menuType::VIEWS_ALL_CUSTOMER:
				coffee.viewMember();
				break;
			default:cout << "\a";

			}
			cin.ignore();
			cin.get();
		} while (ch != '7');

	}

};