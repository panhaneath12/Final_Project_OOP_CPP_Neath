#pragma once
#include<iostream>
#include"OrderRepo.cpp"
#include"Order.cpp"
using namespace std;
class Member {
protected:
	OrderRepo orderRepo;
	Order order;
	int ID;
	string Name;
	string Phone_number;
public:
	Member() :ID(0), Name("Unknow"), Phone_number("Unknow") {}
	Member(int ID, string Name, string Phone_number) :ID(ID), Name(Name), Phone_number(Phone_number) {}
	~Member() {}
	void setID(int ID)
	{
		if (ID < 0) {
			throw "Inviad ID";
		}
		else
		{
			this->ID = ID;
		}
		//this->ID = ID;
	}
	int getID()
	{
		return ID;
	}
	void setName(string Name)
	{
		this->Name = Name;
	}
	string getName()
	{
		return Name;
	}
	void setPhoneNumber(string Phone_number)
	{
		this->Phone_number = Phone_number;
	}
	string getPhoneNaumber()
	{
		return Phone_number;
	}
	void input()
	{
		char ch;
		try {
			cout << "Input Your ID: ";
			cin >> ID;
			setID(ID);
			cout << "Input Your Name: ";
			cin >> Name;
			cout << "Input Your Phone Number: ";
			cin >> Phone_number;
			do {
				orderRepo.addOrder(order.getOrderInput());
				cout << "Do you want to add Order More?(y or n):";
				cin >> ch;
			} while (ch != 'n');
		}
		catch (char* s)
		{
			cout << s;
		}


	}
	int op;
	char ch1;
	void inputEdit()
	{

		do {
			cout << "========Edit Option==========" << endl;
			cout << "1. Input New ID.\n";
			cout << "2. Input New Name.\n";
			cout << "3. Input New Phone Number.\n";
			cout << "4. Input New Order.\n";
			cout << "0. Exits.\n";
			cout << "choose your option(0-4):";
			cin >> op;
			switch (op)
			{
			case 1:
				cout << "Input Your New ID: ";
				cin >> ID;
				break;
			case 2:
				cout << "Input Your New Name: ";
				cin >> Name;
				break;
			case 3:
				cout << "Input Your New Phone Number: ";
				cin >> Phone_number;
				break;
			case 4:
				order.editOrderOption();
				break;
			default:
				cout << "Your Choose Option Hasn't Found\n";
				break;

			}
			cout << "Do you want to Edit Agian?(y or n)";
			cin >> ch1;

		} while (ch1 != 'n');

	}
	void output()
	{
		cout << "\nYour ID is " << ID << endl;
		cout << "Your Name is " << Name << endl;
		cout << "Your Phone Number is " << Phone_number << endl;
		orderRepo.viewOrder();
	}
	void outputList()
	{
		cout << "ID" << "\t\t" << "Member Name" << "\t\t" << "Phone Number" << endl;
		cout << ID << "\t\t\t" << Name << "\t\t\t" << Phone_number << endl;
		cout << "\n";
		orderRepo.viewOrder();
	}

};