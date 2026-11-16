#pragma once
#include<iostream>
#include"clsString.h"
#include"clsDate.h"
using namespace std;
class clsInputValidation
{
public:
	 template<typename T>
	static T IsNumberBetween(T num, T numfrom, T numto)
	{ 
		if (numfrom <= num && numto >= num)
			return true;
		else
			return false;
	}

	static bool IsDateBetween(clsDate date, clsDate datefrom, clsDate dateto)
	{
		if (clsDate::IsDate1AfterDate2(date, datefrom) || clsDate::IsDate1EqualDate2(date, datefrom)
			&&
			clsDate::IsDate1BeforeDate2(date, dateto) || clsDate::IsDate1EqualDate2(date, dateto))
		{ 
			return true;
	    }
		if (clsDate::IsDate1AfterDate2(date, dateto) || clsDate::IsDate1EqualDate2(date, dateto)
			&&
			clsDate::IsDate1BeforeDate2(date, datefrom) || clsDate::IsDate1EqualDate2(date, datefrom))
		{
			return true;
		}
		return false;
	}

	 template<typename T>
	static T ReadNumber(string ErrorMessage = "Invalid Number, Enter again\n")
	{
		T Number;
		while (!(cin >> Number)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << ErrorMessage;
		}
		return Number;
	}

	template <typename T>
	static T ReadNumberBetween(T From, T To, string ErrorMessage = "Number is not within range, Enter again:\n")
	{
		T Number = ReadNumber<short>();

		while (!IsNumberBetween(Number, From, To))
		{
			cout << ErrorMessage;
			Number = ReadNumber<short>();
		}
		return Number;
	}

	static bool IsValidDate(clsDate Date)
	{
		return clsDate::IsValidDate(Date);
	}

	static string ReadString()
	{
		string read ="";
		getline(cin >> ws, read);
		return read;

	}
};

