#pragma once
#include<iostream>
#include"Order.cpp"
#include<vector>
using namespace std;
class OrderDAO {
public:
	virtual void addOrder(Order order) = 0;
	virtual void viewOrder() = 0;
	virtual void editOrder(int id) = 0;
	virtual void deleteOrder(int id) = 0;
	//virtual void sortOrder() = 0;
	virtual Order getOrderByID(int id) = 0;
};