#pragma once
#include<iostream>
#include"clsInputValidation.h"
#include"clsString.h"
#include"clsUser.h"
#include"clsScreen.h"
class clsDeletUserScreen :protected clsScreen
{
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
    static void ShowDeleteClientScreen()
    {

        _DrawScreenHeader("\tDelete Client Screen");

        string UserName = "";

        cout << "\nPlease Enter UserName: ";
        UserName = clsInputValidation::ReadString();
        while (!clsUser::IsUserExist(UserName))
        {
            cout << "\nUserName is not found, choose another one: ";
            UserName = clsInputValidation::ReadString();
        }

        clsUser Client1 = clsUser::Find(UserName);
        _PrintUser(Client1);

        cout << "\nAre you sure you want to delete this client y/n? ";

        char Answer = 'n';
        cin >> Answer;

        if (Answer == 'y' || Answer == 'Y')
        {


            if (Client1.Delet())
            {
                cout << "\nClient Deleted Successfully :-)\n";
                _PrintUser(Client1);
            }
            else
            {
                cout << "\nError Client Was not Deleted\n";
            }
        }
    }
};

