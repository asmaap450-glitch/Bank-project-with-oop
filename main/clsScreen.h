#pragma once
#include<iostream>
#include"clsUser.h"
#include"Globale.h"
#include"clsLoginScreen.h"
#include"clsDate.h"
using namespace std;
class clsScreen
{
protected:
	static void _DrawScreenHeader(string Title, string SubTitle = " ")
	{
		cout << "\n\t\t\t\t\t------------------------------------------------\n";
		cout << "\n\t\t\t\t\t  "<<Title;
		if (SubTitle != " ")
		{
		cout << "\n\t\t\t\t\t  " << SubTitle;
		}
		cout << "\n\t\t\t\t\t------------------------------------------------\n";
		cout << "\n\t\t\t\t\tUser : "<<CurrentUser.UserName;
		cout << "\n\t\t\t\t\tDate : " << clsDate::DateToString(clsDate())<<endl;

	}
	static bool CheckAccessRights(clsUser::enPermission Permission)
	{
		if (!CurrentUser.CheckAccessPermission(Permission))
		{
			cout << "\t\t\t\t\________________________________________________________________";

			cout << "\n\n\t\t\t\t\Access Denied! Contact your Admin\n";

			cout << "\t\t\t\t\________________________________________________________________";
			return false;
		}
		else
		{
			return true;
		}

	}
	
};