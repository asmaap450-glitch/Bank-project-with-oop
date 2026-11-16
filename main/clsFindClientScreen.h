#pragma once
#include<iostream>
#include"clsInputValidation.h"
#include"clsScreen.h"
#include"clsBankClient.h"
class clsFindClientScreen:protected clsScreen
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
public:
	static void ShowClientScreen()
	{
		if (!CheckAccessRights(clsUser::enPermission::pFindClient))
		{
			return;
		}
		_DrawScreenHeader("\tFind Client Screen");
		string account;
		cout << "\nPlease Enter Account Number: ";
		account = clsInputValidation::ReadString();
		while (!clsBankClient::IsClientExist(account))
		{
			cout << "\nAccount Number is not found, Please enter another one: ";
			account = clsInputValidation::ReadString();
		}
		clsBankClient client1 = clsBankClient::Find(account);
		if (!client1.IsImpty())
		{
			cout << "\nClient Found :-)\n ";
		}
		else
		{
			cout << "\nClient is not Found :-(\n ";
		}
		_PrintClient(client1);
	}
};

