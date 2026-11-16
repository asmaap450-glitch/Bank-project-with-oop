#pragma once
#include<iostream>
#include"clsBankClient.h"
#include<iomanip>
#include"clsScreen.h"
#include"clsMainScreen.h"
class clsClientListScreen:protected clsScreen
{
	static void printclintrecord(clsBankClient Client) {
		cout << "| " << setw(15) << left << Client.AccountNumber();
		cout << "| " << setw(15) << left << Client.FullName();
		cout << "| " << setw(15) << left << Client.Phone;
		cout << "| " << setw(15) << left << Client.Email;
		cout << "| " << setw(15) << left << Client.Pincode;
		cout << "| " << setw(15) << left << Client.AccountBalance;
	}
public:
	static void ShowClientList() {
		if (!CheckAccessRights(clsUser::enPermission::pListClient))
		{
			return;
		}
		vector<clsBankClient>VClient
			= clsBankClient::GetClientList();
		string Title = "\t Client List Screen";
		string SubTitle = "\t(" + to_string(VClient.size()) + ") Clients ";
		_DrawScreenHeader(Title, SubTitle);
		cout << "\n-------------------------------------------------------------------------------------------------------\n";
		cout << "| " << left << setw(15) << "AcountNumber";
		cout << "| " << left << setw(15) << "Client Name";
		cout << "| " << left << setw(15) << "Phone";
		cout << "| " << left << setw(15) << "Email";
		cout << "| " << left << setw(15) << "Pin Code";
		cout << "| " << left << setw(15) << "Balance";
		cout << "\n-------------------------------------------------------------------------------------------------------\n";
		if (VClient.size() == 0)
		{
			cout << "\t\t\tNo Client Available In the System!";
		}
		else
		{
			for (clsBankClient C : VClient)
			{
				printclintrecord(C);
				cout << endl;
			}
		}
		cout << "\n------------------------------------------------------------------------------------------------------\n";
	}

};

