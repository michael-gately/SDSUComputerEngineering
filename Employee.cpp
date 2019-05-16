/*
 * Employee.cpp
 *
 *  Created on: Apr 12, 2019
 *      Author: michael
 */
#include <stdlib.h>
#include <iostream>
#include <list>

#include <iostream>
using namespace std;

class Employee //Parent Employee Class
{

private:
	string firstname;
	string lastname;
	long ID;
	string department;
public:
	int profit; //Used by each child class
	Employee(); //Default Constructor
	Employee(string firstname,string lastname, //Explicit Constructor
			long ID, string department,
			int profit);
	virtual int getSalary() = 0; //Virtual functions that is different for each child class.
	virtual void display();
	virtual ~Employee();
};

class Owner : public Employee //Child Class
{
public:
	Owner();
	Owner(string firstname2,string lastname2,
			long ID2, string department2,
			int profit2, int salary2);
	void display();
	int getSalary();
	~Owner();

private:
	int salary;
	int totIncome;

};

class Chef : public Employee
{
public:
	Chef();
	Chef(string firstname2,string lastname2,
			long ID2, string department2,
			int profit2, int salary2,
			string cuisine2);
	void display();
	int getSalary();
	~Chef();

private:
	string cuisine;
	int salary;
	int totIncome;
};

class Waiter : public Employee
{
public:
	Waiter();
	Waiter(string firstname2,string lastname2,
			long ID2, string department2,
			int profit2, int salary2,
			int yearsOfService2, int tips);
	void display();
	int getSalary();
	void setTips();
	~Waiter();

private:
	int yearsOfService;
	int salary;
	int tips;
	int totIncome;

};


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


int main()
{
	int monthlyProfit;
	int tips1 = 0, tips2 = 0, tips3 = 0;

	cout << "How much Profit was made this month?"<<endl;
	cin >> monthlyProfit;

	cout << "How much did the 1st Waiter make in tips?"<<endl;
	cin >> tips1;

	cout << "How much did the 2nd Waiter make in tips?"<<endl;
	cin >> tips2;

	cout << "How much did the 3rd Waiter make in tips?"<<endl;
	cin >> tips3;

	cout<<endl;

	Employee * ptr;
	list<Employee*> emptyList;
	ptr = new Owner("Bob","Freeman",12345,"Owner",monthlyProfit,15000);
	emptyList.push_back(ptr);
	ptr = new Chef("Larry","Jones",23456,"Chef",monthlyProfit,10000,"Italian");
	emptyList.push_back(ptr);
	ptr = new Chef("Rob","Jones",23457,"Chef",monthlyProfit,10000,"French");
	emptyList.push_back(ptr);
	ptr = new Waiter("Jon","Snow",34567,"Waiter",monthlyProfit,3000,3,tips1);
	emptyList.push_back(ptr);
	ptr = new Waiter("Rob","Stark",45678,"Waiter",monthlyProfit,3000,5,tips2);
	emptyList.push_back(ptr);
	ptr = new Waiter("Ned","Stark",89742,"Waiter",monthlyProfit,3000,7,tips3);
	emptyList.push_back(ptr);

	for(list<Employee*>::iterator i = emptyList.begin();
			i != emptyList.end(); i++)
	{
		ptr = *i;
		ptr->display();
	}
}







