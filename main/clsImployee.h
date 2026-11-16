#pragma once
#include<iostream>
#include"clsPerson.h";
using namespace std;

class clsImployee :public clsPerson
{
private:
	string _Title;
	string _Department;
	float _Salary;
public:
	clsImployee(float salary, int id, string fristname, string lastname, string email, string phone, string title, string department)
		:clsPerson( fristname, lastname, email, phone)
	{
		_Title = title;
		_Department = department;
		_Salary = salary;
	}
	int SetSalary(int Salary)
	{
		return _Salary = Salary;
	}
	int Salary()
	{
		return _Salary;
	}
	string SetTitle(string title)
	{
		return _Title = title;
	}
	string Title()
	{
		return _Title;
	}
	string SetDepartment(string Depatment)
	{
		return _Department = Depatment;
	}
	string Department()
	{
		return _Department;
	}
	void PrintResult()
	{
		cout << "Info:\n";
		cout << "_____________________________\n";
		cout << "\nFristName: " << FristName();
		cout << "\nLastName : " << LastName();
		cout << "\nFullName : " << FullName();
		cout << "\nEmail    : " << Email();
		cout << "\nPhone    : " << Phone();
		cout << "\nTitle    : " << _Title;
		cout << "\nDepatment: " << _Department;
		cout << "\nSalary   : " << _Salary;
		cout << "\n_______________________________\n";
	}
};
