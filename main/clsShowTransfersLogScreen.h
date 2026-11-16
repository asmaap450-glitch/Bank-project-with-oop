#pragma once
#include<iostream>
#include"clsPerson.h"
#include"clsUser.h"
#include"clsScreen.h"
#include"Globale.h"
#include"clsBankClient.h"

class clsShowTransfersLogScreen :protected clsScreen
{
	
	static void _PrintClientRecord(clsBankClient::stLogTransferRecord LogTransfer ) {
		cout << "| " << setw(20) << left << LogTransfer.DateTime;
		cout << "| " << setw(20) << left << LogTransfer .ScourceClient;
		cout << "| " << setw(20) << left << LogTransfer.DestinationBalance;
		cout << "| " << setw(20) << left << LogTransfer.Amount;
		cout << "| " << setw(20) << left << LogTransfer.ScourceBalance;
		cout << "| " << setw(20) << left << LogTransfer.DestinationBalance;
		cout << "| " << setw(20) << left << LogTransfer.UserName;

	}

public:

	static void ShowClientList() {
		if (!CheckAccessRights(clsUser::enPermission::LoginRegister))
		{
			return;
		}
		vector< clsBankClient::stLogTransferRecord>VClient
			= clsBankClient::vLogTransferRecord();
		string Titel = "\tTransfer Log List Screen";
		string Subtitle = "(" + to_string(VClient.size()) + ") Rcord(s)";
		_DrawScreenHeader(Titel, Subtitle);
		cout << "| " << left << setw(20) << "Date/Time";
		cout << "| " << left << setw(20) << "s.Acct";
		cout << "| " << left << setw(20) << "d.Acct";
		cout << "| " << left << setw(20) << "Amount";
		cout << "| " << left << setw(20) << "s.Balance";
		cout << "| " << left << setw(20) << "d.Balance";
		cout << "| " << left << setw(20) << "UserName";

		cout << "\n-------------------------------------------------------------------------------------------------------\n";
		if (VClient.size() == 0)
		{
			cout << "\t\t\tNo Users Available In the System!";
		}
		else
		{
			for (clsBankClient::stLogTransferRecord C : VClient)
			{
				_PrintClientRecord(C);
				cout << endl;
			}
		}
		cout << "\n------------------------------------------------------------------------------------------------------\n";
	}
};

