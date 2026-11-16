#pragma once
#include"clsInputValidation.h"
#include"clsMainScreen.h"
#include"clsUser.h"
#include"clsScreen.h"
#include"Globale.h"
#include"clsDate.h"
class clsLoginScreen:protected clsScreen
{      
	static bool _Login()
	{
		bool loginfaild = false;
		int trials = 0;
		string username;
		string password;

		do
		{

			if (loginfaild)
			{		 
				trials++;
				cout << "\nInvlaid UserName Or PassWord!\n";
				cout << "\nYou Have " <<3 - trials << " to Login\n";
			}

          if(trials==3)
		  {
			  cout << "\nYour are Locked After 3 faild trails\n";
			  return false;
		  } 
			cout << "\nEnter UserName?";
			cin >> username;
			cout << "\nEnter Password?";
			cin >> password;
			CurrentUser = clsUser::Find(username, password);
			loginfaild = CurrentUser.IsImpty();
		} while (loginfaild);

		CurrentUser.RegisterLogin();
		clsMainScreen::ShowMainMenue();
		
		return true;
	}
 	public:

	static bool ShowLoginScreen()
	{
		system("cls");
		_DrawScreenHeader("\tLogin Screen");
		return _Login();

	}
};

