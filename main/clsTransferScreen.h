#pragma once
#include<iostream>
#include"clsPerson.h"
#include"clsBankClient.h"
#include"clsScreen.h"
#include"Globale.h"
#include"clsInputValidation.h"
 
using namespace std;
class clsTransferScreen : protected clsScreen
{
	static void _ClientCard(clsBankClient Client)
	{
		cout << "\nClient Card:\n";
		cout << "\n____________________\n";
		cout << "\nFull Name  :" << Client.FullName();
		cout << "\nAcc.Number :" << Client.AccountNumber();
		cout << "\nBalance    :" << Client.AccountBalance;
		cout << "\n____________________\n";

	}
	static string  _ReadAccountNumber(string message)
	{
		string Account;
		cout << message << endl;
		Account = clsInputValidation::ReadString();
		while (!clsBankClient::IsClientExist(Account))
		{
			cout << "\n Accountnumber is not found, choose another one:\n";
			Account = clsInputValidation::ReadString();

		}
		return Account;
	}
	static float ReadAmount(clsBankClient SourceClient)
	{

		cout << "\nEnter Trasfer Amount?";
		float amount = 0;
		amount = clsInputValidation::ReadNumber<float>();

		while (amount > SourceClient.AccountBalance)
		{
			cout << "\nAmount Exceeds the available Balance, Enter another Amount ? ";
			amount = clsInputValidation::ReadNumber<float>();
		}
		return amount;
	}


public:
	static void TransferScreen()
	{

		_DrawScreenHeader("\tTransfer Screen");

		clsBankClient  SourceClient = clsBankClient::Find(_ReadAccountNumber("\nPlease Enter Account Number To Transfer from\n"));
		_ClientCard(SourceClient);

		clsBankClient DestinationClient = clsBankClient::Find(_ReadAccountNumber("\nPlease Enter Account Number To Transfer To\n"));
		_ClientCard(DestinationClient);

		float Amount = ReadAmount(SourceClient);
		cout << "\nAre You sure you want to perform this operation?y/n?";
		char chois = 'n';
		cin >> chois;
		if (chois == 'Y' || chois == 'y')
		{
			if (SourceClient.Transfer(Amount, DestinationClient, CurrentUser.UserName))
			{
				cout << "\nTransfer done Successfully\n";
			}
			else
			{
				cout << "\nTransfer Faild\n";
			}
		}
		_ClientCard(SourceClient);
		_ClientCard(DestinationClient);
	}
};