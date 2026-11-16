#pragma once
#include<iostream>
#include"clsPerson.h"
#include"clsString.h"
#include<vector>
#include"clsScreen.h"
#include"clsUser.h"
#include<iomanip>
class clsListUserScreen : protected clsScreen
{

	static void _PrintUserRecord(clsUser Client) {
		cout << "| " << setw(20) << left << Client.UserName;
		cout << "| " << setw(20) << left << Client.FullName();
		cout << "| " << setw(20) << left << Client.Phone;
		cout << "| " << setw(20) << left << Client.Email;
		cout << "| " << setw(20) << left << Client.PassWord;
		cout << "| " << setw(20) << left << Client.Permissions;
	}

public:

	static void ShowUserList() {
		vector<clsUser>VClient
			= clsUser::GetUserList();
		string Titel = "\tUser List Screen";
		string Subtitle = "(" + to_string(VClient.size()) + ") Users";
		_DrawScreenHeader(Titel, Subtitle);
		
		cout << "| " << left << setw(20) << "UserName";
		cout << "| " << left << setw(20) << "FullName";
		cout << "| " << left << setw(20) << "Phone";
		cout << "| " << left << setw(20) << "Email";
		cout << "| " << left << setw(20) << "Password";
		cout << "| " << left << setw(20) << "Permissions";
		cout << "\n-------------------------------------------------------------------------------------------------------\n";
		if (VClient.size() == 0)
		{
			cout << "\t\t\tNo Users Available In the System!";
		}
		else
		{
			for (clsUser C : VClient)
			{
				_PrintUserRecord(C);
				cout << endl;
			}
		}
		cout << "\n------------------------------------------------------------------------------------------------------\n";
	}

	

};

