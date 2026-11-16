#pragma once
#include<iostream>
#include"clsInputValidation.h"
#include"clsScreen.h"
#include"clsCurrency.h"
class clsUpdateCurrencyScreen:protected clsScreen
{
	static void _PrintCurrency(clsCurrency Currency) {
		cout << "\nCurrency Card:\n";
		cout << "\n___________________________________\n";
		cout << "\nCountry   :" << Currency.Country();
		cout << "\nCode      :" << Currency.CurrencyCode();
		cout << "\nName      :" << Currency.CurrencyName();
		cout << "\nRate/(1$) :" << Currency.Rate();
		cout << "\n___________________________________\n";
	}
	static float _ReadRate()
	{		
		cout << "\nEnter New Rate:";
		float NewRate = clsInputValidation::ReadNumber<float>();
		return NewRate;
	}
public:
	static void UpdateCurrencyScreen()
	{

		string code;
		cout << "\nPlease Enter Currency Code: ";
		code = clsInputValidation::ReadString();

		while (!clsCurrency::IsCurrencyExist(code))
		{
			cout << "\nCurrency Code is not found, Please enter another one: ";
			code = clsInputValidation::ReadString();
		}

		clsCurrency Currency1 = clsCurrency::FindByCode(code);
		_PrintCurrency(Currency1);

		char answer = 'n';
		cout << "\nAre You Sure you want to update the Rate of this Currency y/n?";
		cin >> answer ;
		if (answer == 'y' || answer == 'Y')
		{
			cout << "\nUpdate Currency Rate:";
		 cout << "\n___________________________________\n";

		 Currency1.UpdateRate(_ReadRate());
		 cout << "\nCurrency Rate Update Successfully :-)";
		 _PrintCurrency(Currency1);
		}
		
	}
};

