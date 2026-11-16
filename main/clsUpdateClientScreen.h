#pragma once
#include<iostream>
#include"clsInputValidation.h"
#include"clsScreen.h"
#include"clsBankClient.h"
class clsUpdateClientScreen:protected clsScreen
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
		client.AccountBalance = clsInputValidation::ReadNumber<int>();
	}
public:
    static void ShowUpdateClientScreen()
    {
        if (!CheckAccessRights(clsUser::enPermission::pUpdateClient))
        {
            return;
        }
        _DrawScreenHeader("\tUpdate Client Screen");

        string AccountNumber = "";

        cout << "\nPlease Enter client Account Number: ";
        AccountNumber = clsInputValidation::ReadString();

        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nAccount number is not found, choose another one: ";
            AccountNumber = clsInputValidation::ReadString();
        }

        clsBankClient Client1 = clsBankClient::Find(AccountNumber);

        _PrintClient(Client1);

        cout << "\nAre you sure you want to update this client y/n? ";

        char Answer = 'n';
        cin >> Answer;

        if (Answer == 'y' || Answer == 'Y')
        {

            cout << "\n\nUpdate Client Info:";
            cout << "\n____________________\n";


            _ReadClientInfo(Client1);

            clsBankClient::enSaveResult SaveResult;

            SaveResult = Client1.Save();

            switch (SaveResult)
            {
            case  clsBankClient::enSaveResult::svSucceeded:
            {
                cout << "\nAccount Updated Successfully :-)\n";

                _PrintClient(Client1);
                break;
            }
            case clsBankClient::enSaveResult::svFaildAccountNumberExit:
            {
                cout << "\nError account was not saved because it's Empty";
                break;

            }

            }

        }

    }
};

