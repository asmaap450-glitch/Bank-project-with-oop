#pragma once
#include<iostream>
#include<string>
using namespace std;
class clsPerson {
private:
	
	string _FristName;
	string _LastName;
	string _Email;
	string _Phone;
public:
	clsPerson( string fristname, string lastname, string email, string phone)
	{
		_FristName = fristname;
		_LastName = lastname;
		_Email = email;
		_Phone = phone;
	}
	
	string SetFristName(string FristName)
	{
		return _FristName = FristName;
	}
	string GetFristName()
	{
		return _FristName;
	}
	__declspec(property(get = GetFristName, put = SetFristName)) string FristName;
	string SetLastName(string LastName)
	{
		return _LastName = LastName;
	}
	string GetLastName()
	{
		return _LastName;
	}
	__declspec(property(get = GetLastName, put = SetLastName)) string LastName;

	string FullName()
	{
		return _FristName + " " + _LastName;
	}
	string SetEmail(string Email)
	{
		return _Email = Email;
	}
	string GetEmail()
	{
		return _Email;
	}
	__declspec(property(get = GetEmail, put = SetEmail)) string Email;

	string SetPhone(string Phone)
	{
		return _Phone = Phone;
	}
	string GetPhone()
	{
		return _Phone;
	}
	__declspec(property(get =GetPhone, put = SetPhone)) string Phone;
	
	void SendEmail(string Subject, string Body)
	{
		cout << "\nThe following message sent successfully to email: " << _Email;
		cout << "\nSubject: " << Subject;
		cout << "\nBody: " << Body << endl;
	}
	void SendSMS(string TextMessage)
	{
		cout << "\nThe following SMS sent successfully to phone: " << _Phone << endl;
		cout << TextMessage << endl;
	}
};
