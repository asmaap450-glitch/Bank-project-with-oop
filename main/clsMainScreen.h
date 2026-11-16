#pragma once
#include<iostream>
#include"clsInputValidation.h"
#include"clsScreen.h"
#include<iomanip>
#include"clsClientListScreen.h"
#include"clsAddNewClientScreen.h"
#include"clsDeletClientScreen.h"
#include"clsUpdateClientScreen.h"
#include"clsFindClientScreen.h"
#include"clsTransactionsScreen.h"
#include"clsLoginRegisterScreen.h"
#include"clsManageUsersScreen.h"
#include"Globale.h"
#include"clsCurrencyMainScreen.h"
class clsMainScreen:protected clsScreen
{
	enum enMainMenueOption {
		showclientlist = 1, addnewclient = 2, deletclient = 3, updateclient = 4,
		findclient = 5, transaction = 6, manageusers = 7, loginregister = 8 ,CurrencyExchange = 9,logout = 10
	};
	static short _ReadMainManueOption()
	{
		    cout << setw(37) << left<<" "<<"Choose what you want to do?[1 to 10]?";
			short chois = clsInputValidation::ReadNumberBetween(1, 10, "Invalid Number Enter Number Between 1 , 10");
			return chois;
	}

	static void _GoToMainMenueScreen()
	{
		cout << setw(37) << left << " "<<"\nPress any key to go back to main menue...";
		system("pause>0");
		ShowMainMenue();

	}

	static void _ShowClientListScreen()
	{
		clsClientListScreen::ShowClientList();
	}

	static void _ShowAddNewClientScreen()
	{
		clsAddNewClientScreen::AddNewClient();
	}

	static void _ShowDeletClientScreen()
	{
		clsDeletClientScreen::ShowDeleteClientScreen();
	}

	static void _ShowUpdateClientInfoScreen()
	{
		clsUpdateClientScreen::ShowUpdateClientScreen();
	}

	static void _ShowFindClientScreen()
	{
		clsFindClientScreen::ShowClientScreen();
	}

	static void _ShowTransactionsScreen()
	{
		//cout << "\nTransactions Menue will be here....\n";
		clsTransactionsScreen::ShowTransactionMenue();
	}

	static void _ShowManageUsersScreen()
	{
		//cout << "\nUsers Menue will be here....\n";
		clsManageUsersScreen::ShowManageUserMenue();
	}

	static void _ShowRegisterScreen()
	{
		clsLoginRegisterScreen::ShowUserList();
	}

	static void _ShowCurrencyMainScreen()
	{
		clsCurrencyMainScreen::ShowCurrencyExhangeMenue();
	}

	/*static void _ShowEndScreen()
	{
		cout << "\nEnd screen will be here...\n ";
	}*/

	static void _Logout()
	{
		CurrentUser = clsUser::Find("", "");
	}

	static void _PerfromMainMenueOption(enMainMenueOption chois)
	{
		switch (chois)
		{
		case enMainMenueOption::showclientlist:
		{
			system("cls");
			_ShowClientListScreen();
			_GoToMainMenueScreen();
			break;
		}
		case enMainMenueOption::addnewclient:
		{
			system("cls");
			_ShowAddNewClientScreen();
			_GoToMainMenueScreen();
			break;
		}
		case enMainMenueOption::deletclient:
		{
			system("cls");
			_ShowDeletClientScreen();
			_GoToMainMenueScreen();
			break;
		}
		case enMainMenueOption::updateclient:
		{
			system("cls");
			_ShowUpdateClientInfoScreen();
			_GoToMainMenueScreen();
			break;
		}
		case enMainMenueOption::findclient:
		{
			system("cls");
			_ShowFindClientScreen();
			_GoToMainMenueScreen();
			break;
		}
		case enMainMenueOption::transaction:
		{
			system("cls");
			_ShowTransactionsScreen();		
			_GoToMainMenueScreen();

			break;
		}
		case enMainMenueOption::manageusers:
		{
			system("cls");
			_ShowManageUsersScreen();
			_GoToMainMenueScreen();

			break;
		}
		case enMainMenueOption::loginregister:
		{
			system("cls");
			_ShowRegisterScreen();
			_GoToMainMenueScreen();
			break;
		}

		case enMainMenueOption::CurrencyExchange:
		{
			system("cls");
			_ShowCurrencyMainScreen();
			_GoToMainMenueScreen();
			break;
		}
		case enMainMenueOption::logout:
		{
			system("cls");
			_Logout();
			break;
		}
		}
	}

	public:

	static void ShowMainMenue()
	{
		system("cls");
		_DrawScreenHeader("\t\tMain Screen");

		cout << setw(37) << left << "" << "===================================================\n";
		cout << setw(37) << left << "" << "\t\t\tMain Menue \n";
		cout << setw(37) << left << "" << "===================================================\n";
		cout << setw(37) << left << "" << "\t[1] Show Client List.\n";
		cout << setw(37) << left << "" << "\t[2] Add New Client.\n";
		cout << setw(37) << left << "" << "\t[3] Delete Client.\n";
		cout << setw(37) << left << "" << "\t[4] Update Client Info.\n";
		cout << setw(37) << left << "" << "\t[5] Find Client.\n";
		cout << setw(37) << left << "" << "\t[6]  Transaction.\n";
		cout << setw(37) << left << "" << "\t[7] Manage Users.\n";
		cout << setw(37) << left << "" << "\t[8] Login Register.\n";
		cout << setw(37) << left << "" << "\t[9] Currency Exchange.\n";
		cout << setw(37) << left << "" << "\t[10] Logout.\n";
		cout << setw(37) << left << "" << "===================================================\n";
		_PerfromMainMenueOption((enMainMenueOption)_ReadMainManueOption());
	}
};

