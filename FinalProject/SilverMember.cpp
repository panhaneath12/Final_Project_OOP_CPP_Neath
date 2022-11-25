#pragma once
#include<iostream>
#include"Member.cpp"
using namespace std;
class SilverMember :public Member {
private:
	const int discount = 15;
	//Order order;
public:
	SilverMember() :Member() {};
	SilverMember(int ID, string Name, string Phone_number) :Member(ID, Name, Phone_number) {}
	int getDiscount()
	{
		return discount;
	}
	void inputSilverMember() {
		Member::input();
	}
	void outputSilverMember()
	{
		Member::output();
		cout << "Your discount : " << discount << "%" << endl;
		cout << "Total Payment: " << Member::orderRepo.getTotalOrder() * discount << "$" << endl;

	}
};