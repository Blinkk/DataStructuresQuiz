#ifndef MENU_H
#define MENU_H
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Menu
{
private:
	vector<string> *menu;
	int size;

public:
	Menu() { size = 0; menu = new vector<string>; }
	Menu(string item1, string item2, string item3, string item4);
	~Menu();
	void AddOption();
	void DisplayMenu();
	int GetSize();
	int GetSelected();
};

//Functions defined
Menu::Menu(string item1, string item2, string item3, string item4)
{
	size = 4;
	menu = new vector<string>;
	menu->push_back(item1);
	menu->push_back(item2);
	menu->push_back(item3);
	menu->push_back(item4);
}

Menu::~Menu()
{
	menu->clear();
}

void Menu::AddOption()
{
	size++;
	vector<string> *p = new vector<string>;
	for (int i = 0; i < size - 1; i++)
		p->at(i) = menu->at(i);
	cout << "Enter Menu Text: "; getline(cin, p->at(size - 1));//p[size - 1]);
	delete[]menu;
	menu = p;
	p = NULL;
}

void Menu::DisplayMenu()
{
	system("cls");
	cout << "_______________Main Menu______________\n";
	for (int i = 0; i < size; i++)
		cout << i + 1 << ". " << menu->at(i) << endl;
	cout << endl << endl << "Enter your choice: ";
}

int Menu::GetSelected()
{
	int option;
	do
	{
		cin >> option;
	} while (option < 0 || option > size);
	return option;
}

int Menu::GetSize()
{
	return size;
}

#endif