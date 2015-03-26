/******************************
* Programmer: Austin Ivicevic *
* CSPG220					  *
* Final Project               *
*******************************/
#include <iostream>
#include <list>
#include <queue>
#include <ctime>
#include "Menu.h"
#include "Classes(Temp).h"
using namespace std;

//Globals
void Intro();
void Line();
void CreateCustomers(int &r);
void Solve();
void DisplayCalls();
void ReRandomizeCalls();
list<Customer> mainList;
queue<Customer> mainQueue;
Menu myMenu("Begin Solving", "View All Calls", "Re-randomize calls", "Exit Program");
int randGen = (rand() % 4) + 1;

void main()
{
	//Declarations
	srand(time(NULL));
	bool endProgram = false;
	int selected;
	CreateCustomers(randGen);	//Populate list and queue with customers

	Intro();					//Intro

	//Display the menu.... make selection and carry out the function
	do
	{
		myMenu.DisplayMenu();
		selected = myMenu.GetSelected();
		if (selected == 1)
		{
			system("cls");
			Solve();
			endProgram = true;
		}
		else if (selected == 2)
			DisplayCalls();
		else if (selected == 3)
			ReRandomizeCalls();
		else
			endProgram = true;
	} while (!endProgram);

	//Be sure that the list & queue are empty
	mainList.clear();
	while (mainQueue.size() > 0)
		mainQueue.pop();
}

void Intro()
{
	cout << "This program is designed to take care of incoming IT" <<
		" calls for a networking company. As the calls\ncome in, the data" <<
		" from the customer is stored into a list and an instance of the" <<
		" customer\nclass will be added into our queue for processing." <<
		" Each one will be solvable using a data structure\nand a list"
		" of them will appear below the complaint, prompting the user"
		" (of this program) to decide\nwhich one can solve the problem."
		" It will then display a 'Correct' or 'Incorrect' message."
		" This will\ncontinue until the user decides to exit or"
		" no remaining incoming calls exist in the queue."; Line();
	system("pause");
}

void Line()
{
	cout << "\n_______________________________________\n\n";
}

void CreateCustomers(int &r)
{
	if (r == 1)
	{
		Customer cust1("Chase", "7147775555", "Need to reverse the order of my files.");
		mainList.push_back(cust1);
		mainQueue.push(cust1);
	}
	if (r == 2)
	{
		Customer cust1("Chase", "7147775555", "Need to reverse the order of my files.");
		mainList.push_back(cust1);
		mainQueue.push(cust1);
		Customer cust2("Daniel", "7145869997", "Question: What can I use to insert various values into new positions of a structure every time?");
		mainList.push_back(cust2);
		mainQueue.push(cust2);
	}
	if (r == 3)
	{
		Customer cust1("Chase", "7147775555", "Need to reverse the order of files.");
		mainList.push_back(cust1);
		mainQueue.push(cust1);
		Customer cust2("Daniel", "7145869997", "Question: What can I use to insert various values into new positions of a structure every time?");
		mainList.push_back(cust2);
		mainQueue.push(cust2);
		Customer cust3("Sal", "7145647795", "Question: How can I find the shortest path to a file destination?");
		mainList.push_back(cust3);
		mainQueue.push(cust3);
	}
	if (r == 4)
	{
		Customer cust1("Chase", "7147775555", "Need to reverse the order of files.");
		mainList.push_back(cust1);
		mainQueue.push(cust1);
		Customer cust2("Daniel", "7145869997", "Question: What can I use to insert various values into new positions of a structure every time?");
		mainList.push_back(cust2);
		mainQueue.push(cust2);
		Customer cust3("Sal", "7145647795", "Question: How can I find the shortest path to a file destination?");
		mainList.push_back(cust3);
		mainQueue.push(cust3);
		Customer cust4("Moe", "7158622254", "I need to be able to search through data as quickly as possible. How can I do this?");
		mainList.push_back(cust4);
		mainQueue.push(cust4);
	}
	if (r == 5)
	{
		Customer cust1("Chase", "7147775555", "Need to reverse the order of files.");
		mainList.push_back(cust1);
		mainQueue.push(cust1);
		Customer cust2("Daniel", "7145869997", "Question: What can I use to insert various values into new positions of a structure every time?");
		mainList.push_back(cust2);
		mainQueue.push(cust2);
		Customer cust3("Sal", "7145647795", "Question: How can I find the shortest path to a file destination?");
		mainList.push_back(cust3);
		mainQueue.push(cust3);
		Customer cust4("Moe", "7158622254", "I need to be able to search through data as quickly as possible. How can I do this?");
		mainList.push_back(cust4);
		mainQueue.push(cust4);
		Customer cust5("Eric", "7458697412", "I am creating a game. Which structure can I use to best store the items in my character's inventory?");
		mainList.push_back(cust5);
		mainQueue.push(cust5);
	}
}

void Solve()
{
	int counter = 0;
	int ans;
	bool correct;
	list<Customer>::iterator p = mainList.begin();

	while (p != mainList.end())
	{
		//1
		do
		{
			cout << "\nQueue size: " << mainQueue.size() << endl;
			cout << "Call # " << counter + 1 << ": "; Line();
			p->DisplayCustomerInfo();
			cout << "Should you use: \n1. List\n2. Stack\n3. Queue\nAnswer: "; cin >> ans;
			if (ans == 2)
			{
				cout << "\nCorrect!!!\n\n";
				correct = true;
				p++; counter++;				//Increment iterator and counter
				mainQueue.pop();			//Remove element from queue
			}
			else
			{
				cout << "\nIncorrect... try again\n\n";
				correct = false;
			}
		} while (!correct);

		//2
		if (p != mainList.end())
		{
			do
			{
				cout << "\nQueue size: " << mainQueue.size() << endl;
				cout << "Call # " << counter + 1 << ": "; Line();
				p->DisplayCustomerInfo();
				cout << "Should you use: \n1. List\n2. Map\n3. Queue\n4. Binary Tree\nAnswer: "; cin >> ans;
				if (ans == 1)
				{
					cout << "\nCorrect!!!\n\n";
					p++; counter++;				//Increment iterator and counter
					mainQueue.pop();			//Remove element from queue
					correct = true;
				}
				else
				{
					cout << "\nIncorrect... try again\n\n";
					correct = false;
				}
			} while (!correct);
		}

		//3
		if (p != mainList.end())
		{
			do
			{
				cout << "\nQueue size: " << mainQueue.size() << endl;
				cout << "Call # " << counter + 1 << ": "; Line();
				p->DisplayCustomerInfo();
				cout << "Should you use: \n1. Vector\n2. Map\n3. Graph\n4. Binary Tree\nAnswer: "; cin >> ans;
				if (ans == 3)
				{
					cout << "\nCorrect!!!\n\n";
					p++; counter++;				//Increment iterator and counter
					mainQueue.pop();			//Remove element from queue
					correct = true;
				}
				else
				{
					cout << "\nIncorrect... try again\n\n";
					correct = false;
				}
			} while (!correct);
		}

		//4
		if (p != mainList.end())
		{
			do
			{
				cout << "\nQueue size: " << mainQueue.size() << endl;
				cout << "Call # " << counter + 1 << ": "; Line();
				p->DisplayCustomerInfo();
				cout << "Should you use: \n1. Vector\n2. Binary Tree\n3. Queue\n4. Stack\nAnswer: "; cin >> ans;
				if (ans == 2)
				{
					cout << "\nCorrect!!!\n\n";
					p++; counter++;				//Increment iterator and counter
					mainQueue.pop();			//Remove element from queue
					correct = true;
				}
				else
				{
					cout << "\nIncorrect... try again\n\n";
					correct = false;
				}
			} while (!correct);
		}

		//5
		if (p != mainList.end())
		{
			do
			{
				cout << "\nQueue size: " << mainQueue.size() << endl;
				cout << "Call # " << counter + 1 << ": "; Line();
				p->DisplayCustomerInfo();
				cout << "Should you use: \n1. Vector\n2. Stack\n3. Binary Tree\n4. List\nAnswer: "; cin >> ans;
				if (ans == 4)
				{
					cout << "\nCorrect!!! (This is a trick question because this is not the only right answer, but by far the most sensible)\n\n";
					correct = true;
					p++; counter++;				//Increment iterator and counter
					mainQueue.pop();			//Remove element from queue
				}
				else
				{
					cout << "\nIncorrect... try again\n\n";
					correct = false;
				}
			} while (!correct);
		}

		if (!mainQueue.empty())
			cout << "An error has occurred...\n\n";
		else
			cout << "Queue size: " << mainQueue.size() << endl << "You have solved all of the call complaints.\nThe program will now terminate.\n\n";
	}
}

void DisplayCalls()
{
	list<Customer>::iterator i = mainList.begin();
	cout << "Queue size: " << mainQueue.size() << endl;
	while (i != mainList.end())
	{
		i->DisplayCustomerInfo();
		cout << endl;
		i++;
	}
	system("pause");
}

void ReRandomizeCalls()
{
	mainList.clear();
	while (!mainQueue.empty())
		mainQueue.pop();
	randGen = (rand() % 4) + 1;
	CreateCustomers(randGen);
	cout << "The calls have been randomized.\n";
	system("pause");
}

