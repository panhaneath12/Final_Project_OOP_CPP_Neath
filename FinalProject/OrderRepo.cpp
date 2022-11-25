#pragma once

#include <iostream>
#include "Order.cpp"
#include"OrderDAO.cpp"
#include <vector>
using namespace std;
class OrderRepo : public OrderDAO {
private:
	vector<Order>orders;
public:
	char ch;
	OrderRepo() {}
	~OrderRepo() {
	}
	void addOrder(Order order) {
		orders.push_back(order);
	}
	void viewOrder()
	{
		vector<Order>::iterator it;
		for (it = orders.begin(); it != orders.end(); it++) {
			cout << "\nOrder ID" << "\t\t" << "Coffee Your Order" << "\t\t" << "Price" << "\t\t" << "Quantity" << endl;
			cout << (*it).getOderID() << "\t\t\t" << (*it).getCoffeeName() << "\t\t   " << (*it).getPrice() << "\t\t     " << (*it).getQuantity() << endl;
		}
	}
	void editOrder(int id)
	{
		vector<Order>::iterator it;
		for (it = orders.begin(); it != orders.end(); it++) {
			if ((*it).getOderID() == id) {
				(*it).outputOrder();
				(*it).editOrderOption();
				break;
			}
			else
			{
				cout << "Your ID Not Found";
			}

		}
	}
	void deleteOrder(int id)
	{
		vector<Order>::iterator it;
		for (it = orders.begin(); it != orders.end(); it++) {
			if ((*it).getOderID() == id) {
				viewOrder();
				cout << "Do you to Delete this Order?(y or n):";
				cin >> ch;
				if (ch == 'y') {
					orders.erase(it);
					cout << "Your Order has Been Deleted\n";
				}
				else
				{
					cout << "Your Order hasn't Deleted\n";
				}
				break;
			}
			else
			{
				cout << "Your ID Has Not Found\n";
			}
		}
	}
	Order getOrderByID(int id)
	{
		Order order;
		vector<Order>::iterator it;
		for (it = orders.begin(); it != orders.end(); it++) {
			if ((it)->getOderID() == id) {
				return *it;
			}
		}
		return order;
	}
	double getTotalOrder()
	{
		double total = 0;
		vector<Order>::iterator it;
		for (it = orders.begin(); it != orders.end(); it++) {
			total += (*it).getPrice() * (*it).getQuantity();
		}
		return total;
	}



};