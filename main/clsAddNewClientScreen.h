#pragma once
#include<iostream>
#include"clsInputValidation.h"
#include<iomanip>
#include"clsScreen.h"
#include"clsBankClient.h"
class clsAddNewClientScreen:protected clsScreen
{
	static void _ReadClientInfo(clsBankClient& client) {
		cout << "\nEnter FristName:";
		client.FristName = clsInputValidation::ReadString();
		cout << "\n Enter LastName:";
		client.LastName = clsInputValidation::ReadString();
		client.FullName() = client.FristName + client.LastName;
		cout << "\n Enter Email:";
		client.Email = clsInputValidation::ReadString();
		cout << "\nEnter Phone:";
		client.Phone = clsInputValidation::ReadString();
		cout << "\nEnter Pincode:";
		client.Pincode = clsInputValidation::ReadString();
		cout << "\nEnter Balance:";
		client.AccountBalance = clsInputValidation::ReadNumber<double>();
	}
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
	static void AddNewClient() {
		if (!CheckAccessRights(clsUser::enPermission::pAddNewlCient))
		{
			return;
		}
		_DrawScreenHeader("\t\tAdd Client");
		cout << "\nPlease Enter Client Account Number:";
		string account = clsInputValidation::ReadString();
		while (clsBankClient::IsClientExist(account))
		{
			cout << "\nAccount number is already used ,choose another one: ";
			account = clsInputValidation::ReadString();
		}
		clsBankClient client1 = clsBankClient::GetAddNewClientObject(account);
		_ReadClientInfo(client1);
		clsBankClient::enSaveResult SaveResult;
		SaveResult = client1.Save();
		switch (SaveResult)
		{
		case clsBankClient::enSaveResult::svSucceeded:
		{
			cout << "\nAccount Added Successfully:-)\n";
		_PrintClient(client1);
			break;
		}
		case clsBankClient::enSaveResult::svFailEmptyObject:
		{
			cout << "\nError account was not saved because it's Empty";
			break;
		}
		case clsBankClient::enSaveResult::svFaildAccountNumberExit:
		{
			cout << "\nError account was not saved because it's used!";
			break;
		}
		}

	}

};

