#pragma once

#include <iostream>
#include "Member.cpp"
#include <vector>
#include<algorithm>

using namespace std;
class Coffee {
private:
	vector<Member*>members;
public:
	char ch;
	void addMember(Member* member) {
		members.push_back(member);
	}
	void viewMember()
	{
		vector<Member*>::iterator it;
		for (it = members.begin(); it != members.end(); it++) {
			/*cout << "ID" << "\t\t" << "Name" << "\t\t" << "Phone Number"<<"\t\t"<<"Type Member" << endl;
			cout << (*it)->getID() << "\t\t" << (*it)->getName() << "\t\t" << (*it)->getPhoneNaumber() <<"\t\t" << endl;*/
			(*it)->outputList();
		}
	}
	void searchMember(int id)
	{
		vector<Member*>::iterator it;
		for (it = members.begin(); it != members.end(); it++) {
			if ((*it)->getID() == id) {
				(*it)->output();
			}
			else
			{
				cout << "Not Found\n";
			}
		}
	}

	void editMember(int id)
	{
		vector<Member*>::iterator it;
		for (it = members.begin(); it != members.end(); it++) {
			if ((*it)->getID() == id) {
				(*it)->output();
				(*it)->inputEdit();
				cout << "\n!!Your Member Has been Updated!!!\n";
				break;
			}
			else
			{
				cout << "Your ID Not Found";
			}

		}
	}
	void sortMember()
	{
		vector<Member*>::iterator it;
		sort(members.begin(), members.end());

	}
	void deleteMember(int id)
	{
		vector<Member*>::iterator it;
		for (it = members.begin(); it != members.end(); it++) {
			if ((*it)->getID() == id) {
				(*it)->output();
				cout << "Do you to Delete this Member?(y or n):";
				cin >> ch;
				if (ch == 'y') {
					members.erase(it);
					cout << "Your Member has Been Deleted\n";
				}
				else {
					cout << "Your Member hasn't Deleted\n";
				}
				break;

			}
			else
			{
				cout << "Your ID Has Not Found\n";
			}
		}
	}
	Member* getMemberByID(int id)
	{
		Member member;
		vector<Member*>::iterator it;
		for (it = members.begin(); it != members.end(); it++) {
			if ((*it)->getID() == id) {
				return *it;
			}
		}
		return nullptr;
	}



};