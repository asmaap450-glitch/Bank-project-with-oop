#pragma once
#include<iostream>
#include"clsInputValidation.h"
#include "clsScreen.h"
#include"clsBankClient.h"
#include"clsMainScreen.h"
#include"clsListUserScreen.h"
#include"clsAddNewUsersScreen.h"
#include"clsDeletUserScreen.h"
#include"clsUpdateUserScreen.h"
#include"clsFindUserScreen.h";
class clsManageUsersScreen:protected clsScreen
{
 enum eManmenue{Listuser=1,Addnew=2,Deletuser=3,Updateuser=4,Finduser=5,Mainmenue=6};

 static short _ReadManageUsersMenueOption()
{
	cout << setw(37) << left << "" << "Choose whate do you want to do [1 to 6]?";
	short choise = clsInputValidation::ReadNumberBetween<short>(1, 6);
	return choise;
}

 static void _GotoManageMenue() {
	cout << "\nPress any key to go back to Manage menue...";
	system("pause>0");
	ShowManageUserMenue();
}

 static void _ShowUsersDataScreen()
 {
	 //cout << "usre data screen will be here\n";
	 clsListUserScreen::ShowUserList();
 }

 static void _ShowAddNewUsersScreen()
 {
	// cout << "Add new user screen will be here\n";
	 clsAddNewUsersScreen::AddNewClient();
 }

 static void _ShowDeletUserScreen()
 {
	// cout << "Delet user screem will be here\n";
	 clsDeletUserScreen::ShowDeleteClientScreen();
 }

 static void _ShowUpdateUserScreen()
 {
	 //cout << "Update User Screen Will be Here\n";
	 clsUpdateUserScreen::ShowUpdateClientScreen();
 }

 static void _ShowFindUserScreen()
 {
	 //cout << "Find User screen will be here\n";
	 clsFindUserScreen::ShowUserScreen();
 }

 static void _PreformManageUsersMenueOption(eManmenue chois) {
	
	switch (chois)
	{
	case eManmenue::Listuser:
	{
		system("cls");
		_ShowUsersDataScreen();
		_GotoManageMenue();
		break;
	}

	case eManmenue::Addnew:
	{
		system("cls");
		_ShowAddNewUsersScreen();
		_GotoManageMenue();
		break;
	}

	case eManmenue::Deletuser:
	{
		system("cls");
		_ShowDeletUserScreen();
		_GotoManageMenue();
		break;
	}

	case eManmenue::Updateuser:
	{
		system("cls");
		_ShowUpdateUserScreen();
		_GotoManageMenue();
		break;
	}

	case eManmenue::Finduser:
	{
		system("cls");
		_ShowFindUserScreen();
		_GotoManageMenue();
		break;
	}

	case eManmenue::Mainmenue:
	{

	}
	}
}

public:

 static void ShowManageUserMenue() {
	/* if (!CheckAccessPermission(enPermission::Manageusers))
	 {
		 ShowAccessDeniedMessage();
		 GotoMainMenue();
	 }*/
	 if (!CheckAccessRights(clsUser::enPermission::Manageusers))
	 {
		 return;
	 }
	 system("cls");
	 _DrawScreenHeader("\t Manage Users Screen");
	 cout << setw(37) << left << ""<<"===================================================\n";
	 cout << setw(37) << left << "" << "\t\tManage Users List Screen\n";
	 cout << setw(37) << left << "" << "===================================================\n";
	 cout << setw(37) << left << "" << "\t[1] List User.\n";
	 cout << setw(37) << left << "" << "\t[2] Add New User.\n";
	 cout << setw(37) << left << "" << "\t[3] Delete User.\n";
	 cout << setw(37) << left << "" << "\t[4] Update User.\n";
	 cout << setw(37) << left << "" << "\t[5] Find User.\n";
	 cout << setw(37) << left << "" << "\t[6] Main Menue.\n";
	 cout << setw(37) << left << "" << "===================================================\n";
	 _PreformManageUsersMenueOption((eManmenue)_ReadManageUsersMenueOption());
 }


};

