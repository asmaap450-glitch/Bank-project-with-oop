#pragma once
#include<iostream>
#include"clsCurrency.h"
#include<iomanip>
#include"clsScreen.h"
#include"clsMainScreen.h"
#include"clsUser.h"
class clsCurrenciesListScreen:protected clsScreen
{
	static void PrintCurrencyRecord(clsCurrency Currency) {
		cout << "| " << setw(30) << left << Currency.Country();
		cout << "| " << setw(30) << left << Currency.CurrencyCode();
		cout << "| " << setw(30) << left << Currency.CurrencyName();
		cout << "| " << setw(30) << left << Currency.Rate();
	}
public:
	static void ShowCurrenciesListScreen() {
	
		vector<clsCurrency>vCurrency
			= clsCurrency::GetCurrenciesList();
		string Title = "\t Currency List Screen";
		string SubTitle = "\t(" + to_string(vCurrency.size()) + ") Currency";
		_DrawScreenHeader(Title, SubTitle);
		cout << "\n-------------------------------------------------------------------------------------------------------\n";
		cout << "| " <<  setw(30) << left << "Country";
		cout << "| " <<  setw(30) << left << "Code";
        cout << "| " <<  setw(30) << left <<  "Name";
		cout << "| " <<  setw(30) << left << "Rate/(1$)";
		cout << "\n-------------------------------------------------------------------------------------------------------\n";
		if (vCurrency.size() == 0)
		{
			cout << "\t\t\tNo CUrrencies Available In the System!";
		}
		else
		{
			for (clsCurrency C : vCurrency)
			{
				PrintCurrencyRecord(C);
				cout << endl;
			}
		}
		cout << "\n------------------------------------------------------------------------------------------------------\n";
	}
};

