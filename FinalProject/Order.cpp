#pragma once
#include<iostream>

using namespace std;
class Order {
private:
	int orderID;
	string coffeeName;
	float price;
	int quantity;
	int dicount;
public:
	Order() :orderID(0), coffeeName("Unknow"), price(0), quantity(0), dicount(0) {}
	Order(int order_ID, string coffee_name, float price, int quantity, int discount) :orderID(order_ID), coffeeName(coffee_name), price(price), quantity(quantity), dicount(discount) {}
	~Order() {}
	int num;
	char ch;
	void setOderID(int orderID)
	{
		if (orderID > 0) {
			this->orderID = orderID;
		}
	}
	int getOderID()
	{
		return orderID;
	}
	void setCoffeeName(string coffeeName)
	{
		this->coffeeName = coffeeName;
	}
	string getCoffeeName()
	{
		return coffeeName;
	}
	void setPrice(float price)
	{
		if (price > 0) {
			this->price = price;
		}
		else
		{
			cout << "Your Input Negative Number\n";
		}
	}
	float getPrice()
	{
		return price;
	}
	void setQuantity(int quantity)
	{
		if (quantity > 0) {
			this->quantity = quantity;
		}
		else
		{
			cout << "Your Input Negative Number\n";
		}
	}
	int getQuantity()
	{
		return quantity;
	}
	float totalPayment(int discount)
	{
		return quantity * price * (100 - discount) / 100;
	}
	void setDiscount(int discount)
	{
		if (dicount > 0) {
			this->dicount = dicount;
		}
		else
		{
			cout << "Your Input Negative Number\n";
		}
	}
	int getDiscount()
	{
		return dicount;
	}
	int option;
	void menuTable()
	{

		cout << "\n================Menu======================\n";
		cout << "|| No. ||      COFFEE      ||   price   ||" << endl;
		cout << "||=====||==================||===========||" << endl;
		cout << "|| 1   ||   AMERICANO      ||   2.5$    ||" << endl;
		cout << "|| 2   ||   ESPRESSO       ||   3.0$    ||" << endl;
		cout << "|| 3   ||   CAPPUCCINO     ||   3.5$    ||" << endl;
		cout << "|| 4   ||   LATTE          ||   3.5$    ||" << endl;
		cout << "|| 5   ||   MOCHA          ||   4.0$    ||" << endl;
		cout << "==========================================" << endl;
		cout << "Choose What you want to drink?(1-5): ";
		cin >> option;
		switch (option)
		{
		case 1:
			coffeeName = "AMERICANO";
			price = 2.5;
			//dicount = 10;
			break;
		case 2:
			coffeeName = "ESPRESSO";
			price = 3;
			//dicount = 10;
			break;
		case 3:
			coffeeName = "CAPPUCCINO";
			price = 3.5;
			//dicount = 10;
			break;
		case 4:
			coffeeName = "LATTE";
			price = 3.5;
			//dicount = 10;
			break;
		case 5:
			coffeeName = "MOCHA";
			price = 4;
			//dicount = 10;
			break;
		default:
			break;
		}
	}

	virtual	void inputOrder()
	{
		cout << "Input your Order ID : ";
		cin >> orderID;
		menuTable();
		cout << "Input your Quantity: ";
		cin >> quantity;


	}
	virtual	void outputOrder()
	{
		cout << "\nYour Order ID: " << orderID << endl;
		cout << "Your Coffee Name: " << coffeeName << endl;
		cout << "Your Quantity : " << quantity << endl;
		cout << "Your Coffee price: " << price << endl;
		//cout << "Your Discount: " << dicount << "%" << endl;
		//cout << "Your Total amount: " << totalPayment(dicount) << endl;

	}
	virtual void editOrderOption()
	{

		do {
			cout << "=========Edit Option========\n";
			cout << "1. Edit Order ID \n";
			cout << "2. Edit Order Coffee Name \n";
			cout << "3. Edit Order Quantity  \n";
			cout << "4. Edit Order Price \n";
			cout << "5. Edit All \n";
			cout << "0. Exist\n";
			cout << "Choose your option: ";
			cin >> num;
			switch (num)
			{
			case 1:
				cout << "Input New Order ID:";
				cin >> orderID;
				cout << "Your Order has Been Update\n";
				break;
			case 2:
				cout << "Input New Coffee Name:";
				cin >> coffeeName;
				cout << "Your Order has Been Update\n";
				break;
			case 3:
				cout << "Input New Coffee Quantity:";
				cin >> quantity;
				cout << "Your Order has Been Update\n";
				break;
			case 4:
				cout << "Input New Coffee price:";
				cin >> price;
				cout << "Your Order has Been Update\n";
				break;
			case 5:
				cout << "Input All New";
				inputOrder();
				cout << "Your Order has Been Update\n";
				break;
			case 0:
				cout << "Thank!!\n";
				break;
			default:
				cout << "Your Choose Option Hasn't Found\n";
				break;
				cout << "Do you want to Edit Agian?(y or n)";
				cin >> ch;
			}
		} while (ch != 'n');


	}

	Order getOrderInput()
	{
		cout << "Input your Order ID : ";
		cin >> orderID;
		cout << "\n================Menu======================\n";
		cout << "|| No. ||      COFFEE      ||   price   ||" << endl;
		cout << "||=====||==================||===========||" << endl;
		cout << "|| 1   ||   AMERICANO      ||   2.5$    ||" << endl;
		cout << "|| 2   ||   ESPRESSO       ||   3.0$    ||" << endl;
		cout << "|| 3   ||   CAPPUCCINO     ||   3.5$    ||" << endl;
		cout << "|| 4   ||   LATTE          ||   3.5$    ||" << endl;
		cout << "|| 5   ||   MOCHA          ||   4.0$    ||" << endl;
		cout << "==========================================" << endl;
		cout << "Choose What you want to drink?(1-5): ";
		cin >> option;
		switch (option)
		{
		case 1:
			coffeeName = "AMERICANO";
			price = 2.5;
			//dicount = 10;
			break;
		case 2:
			coffeeName = "ESPRESSO";
			price = 3;
			//dicount = 10;
			break;
		case 3:
			coffeeName = "CAPPUCCINO";
			price = 3.5;
			//dicount = 10;
			break;
		case 4:
			coffeeName = "LATTE";
			price = 3.5;
			//dicount = 10;
			break;
		case 5:
			coffeeName = "MOCHA";
			price = 4;
			//dicount = 10;
			break;
		default:
			break;
		}

		cout << "Input your Quantity: ";
		cin >> quantity;
		Order order(orderID, coffeeName, price, quantity, dicount);
		return order;
	}

};