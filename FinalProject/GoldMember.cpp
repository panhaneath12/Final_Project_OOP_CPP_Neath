#pragma once
#include<iostream>
#include"Member.cpp"
using namespace std;
class GoldMember :public Member {
private:
	const int discount = 20;
	//Order order;
public:
	GoldMember() :Member() {};
	GoldMember(int ID, string Name, string Phone_number) :Member(ID, Name, Phone_number) {}
	int getDiscount()
	{
		return discount;
	}
	void inputGoldMember() {
		Member::input();
	}
	void outputGoldMember()
	{
		Member::output();
		cout << "Your discount : " << discount << "%" << endl;
		cout << "Total Payment: " << Member::orderRepo.getTotalOrder() * discount << "$" << endl;

	}
};