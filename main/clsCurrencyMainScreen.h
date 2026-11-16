#pragma once
#include<iostream>
#include"clsInputValidation.h"
#include "clsScreen.h"
#include<iomanip>
#include"clsCurrenciesListScreen.h"
#include"clsFindCurrencyScreen.h"
#include"clsUpdateCurrencyScreen.h"
#include"clsCurrencyCalculatorScreen.h"
using namespace std;
class clsCurrencyMainScreen:protected clsScreen
{
	enum  eCurrencyMenue { ListCurrencies = 1, FindCurrency = 2, UpdateRate = 3, CurrencyCalculator = 4, MainMenue = 5 };

	static short ReadCurrenciesMenueOption()
	{
		cout << setw(37) << left << "" << "Choose whate do you want to do [1 to 5]?";
		short choise = clsInputValidation::ReadNumberBetween(1, 5);
		return choise;
	}

	static void _GotoCurrencyExhangeMenue() {
		cout << "\nPress any key to go back to main menue...";
		system("pause>0");
		ShowCurrencyExhangeMenue();
	}

	static void _ShowListCurrenciesScreen()
	{
		//cout << "\nListCurrencies Screen Will be here...\n";
		clsCurrenciesListScreen::ShowCurrenciesListScreen();
	}

	static void _ShowFindCurrencyScreen()
	{
		//cout << "\nFind Currency Screen Will be here...\n";
		clsFindCurrencyScreen::ShowFindCurrencyScreen();
	}

	static void _ShowUpdateRateScreen()
	{
		//cout << "\nUpdate Rate screen will be here....\n";
		clsUpdateCurrencyScreen::UpdateCurrencyScreen();
	}

	static void _ShowCurrencyCalculatorScreen()
	{
		//cout << "\nCurrency Calculator screen will be here....\n";
		clsCurrencyCalculatorScreen::ShowCurrencyCalculatorScreen();
	}

	static void _ShowMainMenueScreen()
	{

	}

	static void _PerformCurrencyMenueOption(eCurrencyMenue chois) {
		switch (chois)
		{
		case eCurrencyMenue::ListCurrencies:
		{
			system("cls");
			_ShowListCurrenciesScreen();
			_GotoCurrencyExhangeMenue();
			break;
		}

		case eCurrencyMenue::FindCurrency:
		{
			system("cls");
			_ShowFindCurrencyScreen();
			_GotoCurrencyExhangeMenue();
			break;
		}

		case eCurrencyMenue::UpdateRate:
		{
			system("cls");
			_ShowUpdateRateScreen();
			_GotoCurrencyExhangeMenue();
			break;
		}

		case eCurrencyMenue::CurrencyCalculator:
		{
			system("cls");
			_ShowCurrencyCalculatorScreen();
			_GotoCurrencyExhangeMenue();
			break;
		}

		case eCurrencyMenue::MainMenue:
		{

		}
		}
	}

public:

	static void ShowCurrencyExhangeMenue() {
		//if (!CheckAccessRights(clsUser::enPermission::CurrencyEx))
		//{
			//return;
		//}
		system("cls");
		_DrawScreenHeader("\t  Currency Exhange Main Screen");
		cout << setw(37) << left << "" << "=====================================================\n";
		cout << setw(37) << left << "" << "\t\tCurrency Exhange Menue Screen\n";
		cout << setw(37) << left << "" << "=======================================================\n";
		cout << setw(37) << left << "" << "\t[1]List Currencies.\n";
		cout << setw(37) << left << "" << "\t[2]Find Currency.\n";
		cout << setw(37) << left << "" << "\t[3]Update Rate.\n";
		cout << setw(37) << left << "" << "\t[4]Currency Calculator.\n";
		cout << setw(37) << left << "" << "\t[5]Main Menue.\n";
		cout << setw(37) << left << "" << "=============================================================\n";
		_PerformCurrencyMenueOption((eCurrencyMenue)ReadCurrenciesMenueOption());
	}
};

