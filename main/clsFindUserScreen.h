#pragma once
#include<iostream>
#include"clsInputValidation.h"
#include"clsString.h"
#include"clsUser.h"
#include"clsScreen.h"
class clsFindUserScreen:protected clsScreen
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

	static void ShowUserScreen()
	{
		_DrawScreenHeader("\tFind User Screen");
		string UserName;
		cout << "\nPlease Enter UserName: ";
		UserName = clsInputValidation::ReadString();
		while (!clsUser::IsUserExist(UserName))
		{
			cout << "\nAccount Number is not found, Please enter another one: ";
			UserName = clsInputValidation::ReadString();
		}
		clsUser client1 = clsUser::Find(UserName);
		if (!client1.IsImpty())
		{
			cout << "\nClient Found :-)\n ";
		}
		else
		{
			cout << "\nClient is not Found :-(\n ";

		}
		_PrintUser(client1);
	}
};

