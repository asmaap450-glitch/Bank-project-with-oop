#pragma once
#include<iostream>
#include"clsPerson.h";
#include"clsImployee.h";
using namespace std;
class clsDevolper :public clsImployee {
private:
	string _MainProgramLanguage;
public:
	clsDevolper(float salary, int id, string fristname, string lastname, string email, string phone, string title,
		string department, string mainprogramlanguage)
		:clsImployee(salary, id, fristname, lastname, email, phone, title, department)
	{
		_MainProgramLanguage = mainprogramlanguage;
	}

	string SetMainProgramingLanguage(string language)
	{
		return _MainProgramLanguage = language;
	}
	string MainProgramingLanguage()
	{
		return _MainProgramLanguage;
	}
	void PrintResult()
	{
		cout << "Info:\n";
		cout << "_____________________________\n";
		cout << "\nID       :" << Id();
		cout << "\nFristName: " << FristName();
		cout << "\nLastName : " << LastName();
		cout << "\nFullName : " << FullName();
		cout << "\nEmail    : " << Email();
		cout << "\nPhone    : " << Phone();
		cout << "\nTitle    : " << Title();
		cout << "\nDepatment: " << Department();
		cout << "\nSalary   : " << Salary();
		cout << "\nPLanguage: " << MainProgramingLanguage();
		cout << "\n_______________________________\n";
	}

};
