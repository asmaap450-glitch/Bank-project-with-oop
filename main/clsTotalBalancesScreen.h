#pragma once
#include<iostream>
#include"clsInputValidation.h"
#include "clsScreen.h"
#include"clsBankClient.h"
#include<iomanip>
#include"clsUtil.h"
class clsTotalBalancesScreen:protected clsScreen
{
	static void _PrintClientRecordBalance(clsBankClient client)
	{
		cout << "|" << setw(15) << left << client.AccountNumber();
		cout << "|" << setw(15) << left << client.FullName();
		cout << "|" << setw(15) << left << client.AccountBalance;
		cout << endl;
	}
public:
   static void TotalBalanceScreen() {
	   vector<clsBankClient>vClient =
		   clsBankClient::GetClientList();

		string titel = "\t  Balance List Screen";
		string subtitel = "\t  (" + to_string(vClient.size()) + ") Clints.";
		_DrawScreenHeader(titel,subtitel);

		cout << "\n-------------------------------------------------------------\n";
		
		cout << "| " << left << setw(15) << "AcountNumber";
		cout << "| " << left << setw(15) << "Client Name";
		cout << "| " << left << setw(15) << "Balance";
		cout << "\n-------------------------------------------------------------------\n";	

		double totalbalance = clsBankClient::GetTotalBalance();

		if (vClient.size() == 0)
		{
			cout << "\t\t\tNo Client Available In the System!";
		}
		else
		{
			for (clsBankClient& C : vClient)
			{
				_PrintClientRecordBalance(C);
				cout << endl;
			}
		}
		cout << "\n--------------------------------------------------------------------\n";

		cout << "\t\t\t\t\t\tTotal Balance = " << totalbalance << endl;
		cout << "\t\t\t\t\t( " << clsUtil::NumberToText(totalbalance) << ")";
	}

};

