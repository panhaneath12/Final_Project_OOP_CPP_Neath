#pragma once
#include<iostream>
#include"Member.cpp"
using namespace std;
class NormalMember : public Member {
private:
	const int discount = 5;
	//Order order;
	string Type = "Normal";
public:
	NormalMember() :Member() {};
	NormalMember(int ID, string Name, string Phone_number) :Member(ID, Name, Phone_number) {}
	int getDiscount()
	{
		return discount;
	}
	string getType()
	{
		return Type;
	}
	void inputNormalMember() {
		Member::input();
	}
	void outputNormalMember()
	{
		Member::output();
		cout << "Your discount : " << discount << "%" << endl;
		cout << "Total Payment: " << Member::orderRepo.getTotalOrder() * discount << "$" << endl;
	}

};