#pragma once
#include<iostream>
#include"clsInputValidation.h"
#include"clsScreen.h"
class clsFindCurrencyScreen:protected clsScreen
{
	static void _PrintCurrencyRecord(clsCurrency Currency) {
		cout << "\nCurrency Card:\n";
		cout << "\n___________________________________\n";
		cout << "\nCountry   :" <<  Currency.Country();
		cout << "\nCode      :" <<  Currency.CurrencyCode();
		cout << "\nName      :" <<  Currency.CurrencyName();
		cout << "\nRate/(1$) :" << Currency.Rate();
		cout << "\n___________________________________\n";
	
	}

	static void _ShowResults(clsCurrency Currency)
	{
		if (!Currency.IsEmpty())
		{
			cout << "\nCurrency Found :-)\n ";
			_PrintCurrencyRecord(Currency);
		}
		else
		{
			cout << "\nCurrency is not Found :-(\n ";
		}
	}
public:
	static void ShowFindCurrencyScreen()
	{
		//if (!CheckAccessRights(clsUser::enPermission::pFindClient))
		//{
			//return;
		//}
		short coi;
		_DrawScreenHeader("\tFind Currency Screen");
		cout << "\nFind By: [1] Code or [2] Country ?";
		cin >> coi;
		if (coi == 1)
		{
			string code;
			cout << "\nPlease Enter Currency Code: ";
			code = clsInputValidation::ReadString();
			clsCurrency Currency1 = clsCurrency::FindByCode(code);
			_ShowResults(Currency1);
		}
		else if (coi == 2)
		{
			string country;
			cout << "\nPlease Enter Country Name: ";
			country = clsInputValidation::ReadString();
			clsCurrency Currency2 = clsCurrency::FindByCountry(country);
			_ShowResults(Currency2);
		}
		else
		{
			cout << "\n Eror ! Please enter Number between 1 or 2 ";
		}
	}

};

