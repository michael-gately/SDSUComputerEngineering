/*
 * Employee.cpp
 *
 *  Created on: Apr 12, 2019
 *      Author: michael
 */

#include <iostream>
using namespace std;

#include "Employee.h"

Employee :: Employee() //Default Constructor
{
	firstname = "";
	lastname = "";
	ID = 0;
	department = "";
	profit = 0;
}

Employee :: Employee(string firstname2,string lastname2,
		long ID2, string department2, int profit2) //taking in arguments to initialize data members.
{
	firstname = firstname2;
	lastname = lastname2;
	ID = ID2;
	department = department2;
	profit = profit2;
}

void Employee :: display() //Display used partly in each child class display
{
	cout << " Name : " <<firstname<< " " << lastname <<endl;
	cout << " ID : " << ID<<endl;
	cout << " Employee Class : " <<department<<endl;
}

Employee :: ~Employee()
{

}

Owner :: Owner()
{
	salary = 0;
	totIncome = 0;
}

Owner :: Owner(string firstname2,string lastname2,
		long ID2, string department2,
		int profit2, int salary2)
: Employee(firstname2,lastname2,
		ID2,department2,profit2)
{
	salary = salary2;
	totIncome = 0;
}

Owner :: ~Owner()
{

}

void Owner :: display()
{
	Employee :: display();
	cout << " Salary : " << getSalary()<<endl;
	cout<<endl;
}

int Owner :: getSalary() //Owner gets 60% of the profit + his 15000 salary
{
	totIncome = salary + (profit * (0.60));
	return totIncome;
}

Chef :: Chef()
{
	cuisine = "";
	salary = 0;
	totIncome = 0;
}

Chef :: Chef(string firstname2,string lastname2,
		long ID2, string department2,
		int profit2, int salary2, string cuisine2)
: Employee(firstname2,lastname2,
		ID2,department2,profit2)
{
	salary = salary2;
	totIncome = 0;
	cuisine = cuisine2;
}

Chef :: ~Chef()
{

}

void Chef :: display() //Chef has an added data member that is his cuisine of expertise.
{
	Employee :: display();
	cout << " Cuisine Type: "<< cuisine <<endl;
	cout << " Salary : " << getSalary()<<endl;
	cout<<endl;
}

int Chef :: getSalary() //Each chef gets 20% of the profit added to their salary
{
	totIncome = salary + (profit * (0.20));
	return totIncome;
}

Waiter :: Waiter() //Waiter has special data members years of service and tips.
{
	yearsOfService = 0;
	salary = 0;
	tips = 0;
	totIncome = 0;
}

Waiter :: Waiter(string firstname2,string lastname2,
		long ID2, string department2,
		int profit2, int salary2,
		int yearsOfService2, int tips2)
: Employee(firstname2,lastname2,
		ID2,department2,profit2)
{
	yearsOfService = yearsOfService2;
	salary = salary2;
	tips = tips2;
	totIncome = 0;
}

Waiter :: ~Waiter()
{

}

void Waiter :: display()
{
	Employee :: display();
	cout << " Years of Service : "<< yearsOfService<<endl;
	cout << " Salary : " << getSalary()<<endl;
	cout<<endl;
}

int Waiter :: getSalary() //Waiter earns their salary plus tips.
{
	totIncome = salary + tips;
	return totIncome;
}







