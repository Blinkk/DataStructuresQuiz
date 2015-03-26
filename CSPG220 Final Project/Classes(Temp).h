#ifndef CLASSES_H
#define CLASSES_H
#include <iostream>
#include <string>
using namespace std;

class Customer
{
private:
	string name;
	string pNum;
	string complaint;

public:
	Customer(string n, string pN, string comp)
	{
		name = n; pNum = pN;
		complaint = comp;
	}

	void SetCustomerValues(string n, string pN, string comp)
	{
		name = n; pNum = pN;
		complaint = comp;
	}

	void DisplayCustomerInfo()
	{
		cout << "Name: " << name << endl;
		cout << "Phone: " << pNum << endl;
		cout << "Complaint: " << complaint << endl;
	}
};

#endif