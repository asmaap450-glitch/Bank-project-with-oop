#pragma once
#include<iostream>
#include"clsPerson.h"
#include"clsBankClient.h"
#include"clsScreen.h"
#include"Globale.h"
#include"clsUser.h"

class clsLoginRegisterScreen : protected clsScreen
{

	static void _PrintUserRecord(clsUser::stLoginRegister LoginRegister) {
		cout << "| " << setw(25) << left << LoginRegister.DateTime;
		cout << "| " << setw(25) << left << LoginRegister.UserName;
		cout << "| " << setw(25) << left << LoginRegister.Password;
		cout << "| " << setw(25) << left << LoginRegister.Permission;
	}

public:

	static void ShowUserList() {
		if (!CheckAccessRights(clsUser::enPermission::LoginRegister))
		{
			return;
		}

		vector<clsUser::stLoginRegister>VClient
			= clsUser::vLoginRegisterRecord();
		string Titel = "\tLogin Register List Screen";
		string Subtitle = "(" + to_string(VClient.size()) + ") Rcord(s)";
		_DrawScreenHeader(Titel, Subtitle);
		cout << "| " << left << setw(25) << "Date/Time";
		cout << "| " << left << setw(25) << "UserName";
		cout << "| " << left << setw(25) << "Password";
		cout << "| " << left << setw(25) << "Permissions";
		cout << "\n-------------------------------------------------------------------------------------------------------\n";
		if (VClient.size() == 0)
		{
			cout << "\t\t\tNo Users Available In the System!";
		}
		else
		{
			for (clsUser::stLoginRegister C : VClient)
			{
				_PrintUserRecord(C);
				cout << endl;
			}
		}
		cout << "\n------------------------------------------------------------------------------------------------------\n";
	}
};

