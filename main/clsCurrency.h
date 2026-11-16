#pragma once
#include<iostream>
#include"clsPerson.h"
#include"clsString.h"
#include<vector>
#include<fstream>
#include"clsUtil.h"
class clsCurrency
{
	enum enMode{ EmptyMode = 0, UpdateMode = 1 };
	enMode _Mode;
	string _Country;
	string _CurrencyCode;
	string _CurrencyName;
	float _Rate;

	static clsCurrency _ConvertLineToCurrencyObject(string Line, string Seperator = "#//#")
	{
		vector<string>vCurrencyData;
		vCurrencyData = clsString::Split(Line, Seperator);

		return clsCurrency(enMode::UpdateMode, vCurrencyData[0], vCurrencyData[1], vCurrencyData[2],stod(vCurrencyData[3]));
	}

	static string _ConvertCurrencyObjectToLine(clsCurrency Currency, string Seperator = "#//#")
	{
		string CurrencyRecord = "";
		CurrencyRecord += Currency.Country() + Seperator;
		CurrencyRecord += Currency.CurrencyCode() + Seperator;
		CurrencyRecord += Currency.CurrencyName() + Seperator;
		CurrencyRecord += to_string(Currency.Rate());
		return CurrencyRecord;
	}

	static vector <clsCurrency> _LoadCurrencyDataFromFile()
	{
		vector <clsCurrency> vCurrency;
		fstream MyFile;
		MyFile.open("Currencies.txt", ios::in);//read Mode
		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				if (Line != "")
				{
					clsCurrency Currency = _ConvertLineToCurrencyObject(Line);
					vCurrency.push_back(Currency);
				}
			}
			MyFile.close();
		}
		return vCurrency;
	}

	static void _SaveCurrencyDataToFile(vector<clsCurrency> vUsers)
	{
		fstream MyFile;
		MyFile.open("Currencies.txt", ios::out);//overwrite
		string DataLine;
		if (MyFile.is_open())
		{
			for (clsCurrency C : vUsers)
			{
				//we only write records that are not marked for delete.
				//if (C._MarkToDelet == false)
				{
					DataLine = _ConvertCurrencyObjectToLine(C);
					MyFile << DataLine << endl;
				}
			}
			MyFile.close();
		}
	}

	void _Update()
	{
		vector<clsCurrency>vCurrency
			= _LoadCurrencyDataFromFile();
		for (clsCurrency& C: vCurrency)
		{
			if (C.CurrencyCode() == CurrencyCode())
			{
				C = *this;
				break;
			}
		}
		_SaveCurrencyDataToFile(vCurrency);
	}

	static clsCurrency _GetEmptyCurrencyObject()
	{
		return clsCurrency(enMode::EmptyMode, "", "", "",  0);
	}

public:
	clsCurrency(enMode Mode, string Country, string CountryCode, string CurrencyName, float Rate)
	{
		_Mode = Mode;
		_Country = Country;
		_CurrencyCode = CountryCode;
		_CurrencyName = CurrencyName;
		_Rate = Rate;
	}

	bool IsEmpty()
	{
		return(_Mode == enMode::EmptyMode);
	}

	static vector<clsCurrency>GetAllUSDRates()
	{
		// because the _Load is Privet so it couldn't saw by the user this's why we did this funcation to the user see _load
		// funcation but to new and easy name.
		return _LoadCurrencyDataFromFile();
	}


	string Country()
	{
		return _Country;
	}
	
	string CurrencyCode()
	{
		return _CurrencyCode;
	}

	string CurrencyName()
	{
		return _CurrencyName;
	}
	
	float Rate()
	{
		return _Rate;
	}

	void UpdateRate(float newrate)
	{
		_Rate = newrate;
		_Update();
	}

	static clsCurrency FindByCode(string CurrencyCode)
	{
		CurrencyCode = clsString::UpperAllString(CurrencyCode);
		fstream MyFile;
		MyFile.open("Currencies.txt", ios::in);
		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsCurrency Currency = _ConvertLineToCurrencyObject(Line);
				if (CurrencyCode == Currency.CurrencyCode())
				{
					MyFile.close();
					return Currency;
				}
			}
			MyFile.close();
		}
		else
		{
			// أضيفي هذا السطر لتعرفي إذا كان الملف ينفتح أصلاً أم لا
			cout << "\nError: Could not open file! File is missing or in wrong path.\n";
		}
		return _GetEmptyCurrencyObject();
	}
	
	static clsCurrency FindByCountry(string Country)
	{
		Country = clsString::UpperAllString(Country);
		fstream MyFile;
		MyFile.open("Currencies.txt", ios::in);
		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsCurrency Currency = _ConvertLineToCurrencyObject(Line);
				if (clsString::UpperAllString( Currency.Country())==Country)
				{
					MyFile.close();
					return Currency;
				}
			}
			MyFile.close();
		}
		else
		{
			// أضيفي هذا السطر لتعرفي إذا كان الملف ينفتح أصلاً أم لا
			cout << "\nError: Could not open file! File is missing or in wrong path.\n";
		}
		return _GetEmptyCurrencyObject();
	}

	static bool IsCurrencyExist(string CurrencyCode)
	{
		clsCurrency C1 = FindByCode(CurrencyCode);
		return (!C1.IsEmpty());
	}

	static vector<clsCurrency>GetCurrenciesList()
	{
		// because the _Load is Privet so it couldn't saw by the user this's why we did this funcation to the user see _load
		// funcation but to new and easy name.
		return _LoadCurrencyDataFromFile();
	}

	float ConvertToUSD(float amount)
	{
		return (float)(amount / Rate());
	}

	float ConvertToOtherCurrency(float amount, clsCurrency Currency2)
	{
		float AmountInUSD = ConvertToUSD(amount);
		if (Currency2.CurrencyCode() == "USD")
		{
			return AmountInUSD;
		}
		return (float)(AmountInUSD * Currency2.Rate());
	}

};

