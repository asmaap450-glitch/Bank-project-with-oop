#pragma once
#include<iostream>
#include"clsInputValidation.h"
#include "clsScreen.h"
#include"clsBankClient.h"
#include<iomanip>
#include"clsDepositScreen.h"
#include"clsWithdrawScreen.h"
#include"clsTotalBalancesScreen.h"
#include"clsTransferScreen.h";
#include"clsShowTransfersLogScreen.h";

class clsTransactionsScreen :protected clsScreen
{
	enum  etranMenue { deposit = 1, withdraw = 2, totalbalance = 3 , transfer = 4 ,transferlog = 5, mainmenue = 6 };

	static short ReadTransactionsMenueOption()
	{
		cout << setw(37) << left << "" << "Choose whate do you want to do [1 to 6]?";
		short choise = clsInputValidation::ReadNumberBetween(1, 6);
		return choise;
	}

	static void _GotoTrancationMenue() {
		cout << "\nPress any key to go back to main menue...";
		system("pause>0");
		ShowTransactionMenue();
	}

	static void _ShowDepositScreen()
	{
		//cout << "\nDeposit Screen Will be here...\n";
		clsDepositScreen::ShowDepositScreen();
	}

	static void _ShowWithdrawScreen()
	{
		//cout << "\nWithdraw Screen Will be here...\n";
		clsWithdrawScreen::ShowWithdrawSCreen();
	}

	static void _ShowTotalBalanceScreen()
	{
		//cout << "\Balance screen will be here....\n";
		clsTotalBalancesScreen::TotalBalanceScreen();
	}

	static void _ShowTransferScreen()
	{
		clsTransferScreen::TransferScreen();
	}

	static void _ShowTransferLogScreen()
	{
		clsShowTransfersLogScreen::ShowClientList();
	}

	static void _PerformTransactionMenueOption(etranMenue chois) {
		switch (chois)
		{
		case etranMenue::deposit:
		{
			system("cls");
			_ShowDepositScreen();
			_GotoTrancationMenue();
			break;
		}

		case etranMenue::withdraw:
		{
			system("cls");
			_ShowWithdrawScreen();
			_GotoTrancationMenue();
		}

		case etranMenue::totalbalance:
		{
			system("cls");
			_ShowTotalBalanceScreen();
			_GotoTrancationMenue();
			break;
		}

		case etranMenue::transfer:
		{
			system("cls");
			_ShowTransferScreen();
			_GotoTrancationMenue();
		}

		case etranMenue::transferlog:
		{
			system("cls");
			_ShowTransferLogScreen();
			_GotoTrancationMenue();
		}

		case etranMenue::mainmenue:
		{

		}
		}
	}

public:

	static void ShowTransactionMenue() {
		if (!CheckAccessRights(clsUser::enPermission::Transaction))
		{
			return;
		}
		system("cls");
		_DrawScreenHeader("\t  Transactions Screen");
		cout << setw(37) << left << "" << "=====================================================\n";
		cout << setw(37) << left << "" << "\t\tTransaction Menue Screen\n";
		cout << setw(37) << left << "" << "=======================================================\n";
		cout << setw(37) << left << "" << "\t[1]Deposit.\n";
		cout << setw(37) << left << "" << "\t[2]Withdraw.\n";
		cout << setw(37) << left << "" << "\t[3]Total Balance.\n";
		cout << setw(37) << left << "" << "\t[4]Transfer.\n";
		cout << setw(37) << left << "" << "\t[5]Transfer Log.\n";
		cout << setw(37) << left << "" << "\t[6]Main Menue.\n";
		cout << setw(37) << left << "" << "=============================================================\n";
		_PerformTransactionMenueOption((etranMenue)ReadTransactionsMenueOption());
	}
};