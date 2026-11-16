#pragma once
#include<iostream>
#include"clsInputValidation.h"
#include"clsScreen.h"
#include"clsCurrency.h"
class clsCurrencyCalculatorScreen :protected clsScreen
{
	static void _PrintCurrency(clsCurrency Currency,string Title = "CurrencyCard") {
		cout << Title << endl;
		cout << "\n___________________________________\n";
		cout << "\nCountry   :" << Currency.Country();
		cout << "\nCode      :" << Currency.CurrencyCode();
		cout << "\nName      :" << Currency.CurrencyName();
		cout << "\nRate/(1$) :" << Currency.Rate();
		cout << "\n___________________________________\n";
	}

	static clsCurrency _GetCurrency(string message)
	{
         string code;
			cout << message <<endl;

			code = clsInputValidation::ReadString();

			while (!clsCurrency::IsCurrencyExist(code))
			{
				cout << "\nCurrency1 Code is not found, Please enter another one: ";
				code = clsInputValidation::ReadString();
			}
			clsCurrency Currency = clsCurrency::FindByCode(code);
			return Currency;
	}

	static float _ReadAmount()
	{			
		cout << "\nEnter Amount to Exchange:";
           float amount=0;
		   amount = clsInputValidation::ReadNumber<float>();
			return amount;
	}
	
	static void _PrintCalculationResults(float amount, clsCurrency Currency1, clsCurrency Currency2)
	{
				_PrintCurrency(Currency1,"Conver From:");
				float amountusd = Currency1.ConvertToUSD(amount);
				cout << amount<<" " << Currency1.CurrencyCode() << " = " <<amountusd<<" USD\n";

				if (Currency2.CurrencyCode() == "USD")
				{
					return;
				}				
				cout << "\nConverting from USD to:";

				_PrintCurrency(Currency2,"To:");

				float AmountInCurrency2 = Currency1.ConvertToOtherCurrency(amount, Currency2);

				cout << amount << " " << Currency1.CurrencyCode() 
					<< " = " << amount << " " << Currency2.CurrencyCode();
	}
public:
	static void ShowCurrencyCalculatorScreen()
	{			
		char A = 'y';

		while (A == 'y' || A == 'Y')
		{
			system("cls");
			_DrawScreenHeader("\nCalculater Currency Screen");
			clsCurrency CurrencyFrom = _GetCurrency("\nPlease Enter Currency1 Code: ");
			clsCurrency CurrencyTo= _GetCurrency("\nPlease Enter Currency2 Code: ");
			float Amount = _ReadAmount();

			_PrintCalculationResults(Amount, CurrencyFrom, CurrencyTo);

			cout << "\nDo You want to perform another calulator ? y/n ?";
			cin >> A;
		}
	}
};
