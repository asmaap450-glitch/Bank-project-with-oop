#pragma once
#include<iostream>
#include"clsInputValidation.h"
#include "clsScreen.h"
#include"clsBankClient.h"
#include"clsTransactionsScreen.h"
class clsWithdrawScreen : protected clsScreen 
{
	static void _PrintClient(clsBankClient client)
	{
		cout << "Client Card:\n";
		cout << "_____________________________\n";

		cout << "\nFristName   : " << client.FristName;
		cout << "\nLastName    : " << client.LastName;
		cout << "\nFullName    : " << client.FullName();
		cout << "\nEmail       : " << client.Email;
		cout << "\nPhone       : " << client.Phone;
		cout << "\nAcc. Number : " << client.AccountNumber();
		cout << "\nPassword    : " << client.Pincode;
		cout << "\nBalance     : " << client.AccountBalance;
		cout << "\n_______________________________\n";
	}

	static string _ReadAccountNumber()
	{
		string Account = "";
		cout << "\nPlease Enter AccountNumber ?";
		cin >> ws;
		getline(cin, Account);
		return Account;
	}

public :
	static void ShowWithdrawSCreen()
	{
		_DrawScreenHeader("\t\t Withdraw Screen ");

		string accountnum = _ReadAccountNumber();

		while (!clsBankClient::IsClientExist(accountnum))
		{
			cout << "\n Client with [" << accountnum << "] is not exist choose another one!";
			accountnum = _ReadAccountNumber();
		}

		clsBankClient client1 = clsBankClient::Find(accountnum);

		_PrintClient(client1);

		double amount = 0;
		cout << "\nPlease Enter Withdraw amount?";

		amount = clsInputValidation::ReadNumber<double>();

		char ch = 'n';
		cout << "\nYou Are sure you want to perform this transaction? ";
		cin >> ch;
		if (ch == 'y' || ch == 'Y')
		{
			if (client1.Withdraw(amount))
			{
				cout << "\nAmount Deposit Successfully.\n";
				cout << "\nNew Balance is:" << client1.AccountBalance;
			}
			else
			{
				cout << "\nCannot withdraw, insuffecient Balance!\n";
				cout << "Acmount to withdraw is :" << amount;
				cout << "\nYour Balance is " << client1.AccountBalance;
			
			}
		}
		else
		{
			cout << "\nOperation was cancelled.\n";
		}
	}
};
