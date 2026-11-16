#pragma once
#include<iostream>
#include"clsInputValidation.h"
#include"clsString.h"
#include"clsUser.h"
#include"clsScreen.h"
class clsUpdateUserScreen : protected clsScreen
{
	static void _ReadUserInfo(clsUser& client) {

		cout << "\nEnter FristName : ";
		client.FristName = clsInputValidation::ReadString();
		cout << "\n Enter LastName:";
		client.LastName = clsInputValidation::ReadString();
		client.FullName() = client.FristName + client.LastName;
		cout << "\n Enter Email:";
		client.Email = clsInputValidation::ReadString();
		cout << "\nEnter Phone:";
		client.Phone = clsInputValidation::ReadString();
		cout << "\nEnter Username:";
		client.UserName = clsInputValidation::ReadString();
		cout << "\nEnter PassWord:";
		client.PassWord = clsInputValidation::ReadString();
		cout << "\nEnter Permissions:";
		client.Permissions = _ReadPermissionsToSet();
	}

	static int _ReadPermissionsToSet()
	{
		char c = 'n';
		int count = 0;
		cout << "\nDo You Want to give full access ? y or n ";
		cin >> c;
		if (c == 'n' || c == 'N')
		{
			cout << "\nDo You Want to give full access to :";
			cout << "\nShow Users List? y or n ?";
			cin >> c;
			if (c == 'y' || c == 'Y')
			{
				count += clsUser::enPermission::pListClient;
			}
			cout << "\nAdd New Users? y or n ?";
			cin >> c;
			if (c == 'y' || c == 'Y')
			{
				count += clsUser::enPermission::pAddNewlCient;
			}
			cout << "\nDelet Clint? y or n ?";
			cin >> c;
			if (c == 'y' || c == 'Y')
			{
				count += clsUser::enPermission::pDeletClient;
			}
			cout << "\nUpdate client? y or n ?";
			cin >> c;
			if (c == 'y' || c == 'Y')
			{
				count += clsUser::enPermission::pUpdateClient;
			}
			cout << "\nFind Client? y or n ?";
			cin >> c;
			if (c == 'y' || c == 'Y')
			{
				count += clsUser::enPermission::pFindClient;
			}
			cout << "\nTrancaction? y or n ?";
			cin >> c;
			if (c == 'y' || c == 'Y')
			{
				count += clsUser::enPermission::Transaction;
			}
			cout << "\nManage Users? y or n ?";
			cin >> c;
			if (c == 'y' || c == 'Y')
			{
				count += clsUser::enPermission::Manageusers;
			}

			cout << "\nLoginRegister? y or n ?";
			cin >> c;
			if (c == 'y' || c == 'Y')
			{
				count += clsUser::enPermission::LoginRegister;
			}

		}
		else
		{
			count += clsUser::enPermission::All;
		}
		return  count;
	}

    static void _PrintUser(clsUser User)
    {
        cout << "Client Card:\n";
        cout << "_____________________________\n";
        cout << "\nFristName   : " << User.FristName;
        cout << "\nLastName    : " << User.LastName;
        cout << "\nFullName    : " << User.FullName();
        cout << "\nEmail       : " << User.Email;
        cout << "\nPhone       : " << User.Phone;
        cout << "\nUserName    : " << User.UserName;
        cout << "\nPassword    : " << User.PassWord;
        cout << "\nPermissions : " << User.Permissions;
        cout << "\n_______________________________\n";
    }

public:

    static void ShowUpdateClientScreen()
    {

        _DrawScreenHeader("\tUpdate User Screen");

        string UserName = "";

        cout << "\nPlease Enter User Name: ";
        UserName = clsInputValidation::ReadString();

        while (!clsUser::IsUserExist(UserName))
        {
            cout << "\nUserName is not found, choose another one: ";
            UserName = clsInputValidation::ReadString();
        }

        clsUser Client1 = clsUser::Find(UserName);

        _PrintUser(Client1);

        cout << "\nAre you sure you want to update this User y/n? ";

        char Answer = 'n';
        cin >> Answer;

        if (Answer == 'y' || Answer == 'Y')
        {

            cout << "\n\nUpdate User Info:";
            cout << "\n____________________\n";


            _ReadUserInfo(Client1);

            clsUser::enSaveResult SaveResult;

            SaveResult = Client1.Save();

            switch (SaveResult)
            {
            case  clsUser::enSaveResult::svSucceeded:
            {
                cout << "\nAccount Updated Successfully :-)\n";

                _PrintUser(Client1);
                break;
            }
            case clsUser::enSaveResult::svFaildAccountNumberExit:
            {
                cout << "\nError account was not saved because it's Empty";
                break;

            }

            }

        }

    }
};

