/*
 * Employee.h
 *
 *  Created on: Apr 12, 2019
 *      Author: michael
 */

#include <iostream>
using namespace std;

#ifndef EMPLOYEE_H_
#define EMPLOYEE_H_



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




#endif /* EMPLOYEE_H_ */
