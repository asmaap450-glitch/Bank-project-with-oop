#pragma once
#include<iostream>
#include"clsPerson.h"
#include"clsString.h"
#include"clsDate.h"
#include<vector>
#include<fstream>
class clsBankClient:public clsPerson
{
private:
	enum enMode{ EmptyMode = 0 ,UpdateMode = 1 ,AddNewMode=  2 };
	enMode _Mode;
	string _AccountNumber;
	string _Pincode;
	double _AccountBalance;
	bool _MarkToDelet = false;
 
	static clsBankClient _ConvertLineToClientObject(string Line,string Seperator="#//#")
	{
		vector<string>VClientData;
			VClientData= clsString::Split(Line, Seperator);
		return clsBankClient(enMode::UpdateMode, VClientData[0], VClientData[1], VClientData[2], VClientData[3],
			VClientData[4], VClientData[5], stod(VClientData[6]));
	}
	static string _ConvertClientObjectToLine(clsBankClient Client, string Seperator = "#//#")
	{
		string stClientRecord = "";
		stClientRecord += Client.FristName + Seperator;
		stClientRecord += Client.LastName + Seperator;
		stClientRecord += Client.Email+ Seperator;
		stClientRecord += Client.Phone + Seperator;
		stClientRecord += Client._AccountNumber + Seperator;
		stClientRecord += Client._Pincode + Seperator;
		stClientRecord += to_string(Client._AccountBalance);
		return stClientRecord;
	}
	static vector <clsBankClient> _LoadCleintsDataFromFile()
	{
		vector <clsBankClient> vClients;
		fstream MyFile;
		MyFile.open("clint.txt", ios::in);//read Mode
		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				if (Line != "")
				{
					clsBankClient Client = _ConvertLineToClientObject(Line);
					vClients.push_back(Client);
				}
			}
			MyFile.close();
		}
		return vClients;
	}
	static void _SaveCleintsDataToFile( vector<clsBankClient> vClients)
	{
		fstream MyFile;
		MyFile.open("clint.txt", ios::out);//overwrite
		string DataLine;
		if (MyFile.is_open())
		{
			for (clsBankClient C : vClients)
			{
					//we only write records that are not marked for delete.
				if (C.MarkToDelet() == false)
				{
					DataLine = _ConvertClientObjectToLine(C);
					MyFile << DataLine << endl;
				}
			}
			MyFile.close();
		}
	}
	void _AddDataLineToFail( string stdata) {
		fstream myfail;
		myfail.open("clint.txt", ios::out | ios::app);

		if (myfail.is_open()) {

			myfail << stdata << endl;

			myfail.close();
		}
	}
	void _AddNew()
	{
		_AddDataLineToFail(_ConvertClientObjectToLine(*this));
	}
	void _Update()
	{
		vector<clsBankClient>VClient
			= _LoadCleintsDataFromFile();
		for (clsBankClient& C : VClient)
		{
			if (C._AccountNumber == AccountNumber())
			{
				C = *this;
				break;
			}
		}
		_SaveCleintsDataToFile(VClient);
	}

	static clsBankClient _GetEmptyClientObject()
	{
		return clsBankClient(enMode::EmptyMode, "", "", "", "", "", "", 0);
	}

 string _PrepareTransferLoginRecord( clsBankClient DestinationClient,float amount,string UserName,string Seperator = "#//#")
	  {
		  string stuserRecord = "";
		  stuserRecord += clsDate::GetSystemDateTimeString() + Seperator;
		  stuserRecord += AccountNumber() + Seperator;		  
          stuserRecord += DestinationClient.AccountNumber() + Seperator;
		  stuserRecord +=to_string( amount) + Seperator;
		  stuserRecord += to_string(AccountBalance) + Seperator;
		  stuserRecord += to_string(DestinationClient.AccountBalance) + Seperator;
		  stuserRecord += UserName + Seperator;
		  return stuserRecord;
	  }

	  void _RgisterTransferLog(float amount, clsBankClient DestinationClient,string UserName) {
		  string stdata = _PrepareTransferLoginRecord(DestinationClient,amount,UserName);
		  fstream myfail;
		  myfail.open("transferlog.txt", ios::out | ios::app);

		  if (myfail.is_open()) {

			  myfail << stdata << endl;

			  myfail.close();
		  }
	  }

	  struct stLogTransferRecord;

	  static stLogTransferRecord _ConvertLoginRegisterLineToRecord(string Line, string Seperator = "#//#")
	  {
		   stLogTransferRecord TransferRecord;


		  vector <string> LoginRegisterDataLine = clsString::Split(Line, Seperator);
		  TransferRecord.DateTime = LoginRegisterDataLine[0];
		  TransferRecord.ScourceClient = LoginRegisterDataLine[1];
		  TransferRecord.DestinaionClient = LoginRegisterDataLine[2];
		  TransferRecord.Amount = stoi(LoginRegisterDataLine[3]);
		  TransferRecord.ScourceBalance = stoi(LoginRegisterDataLine[4]);
		  TransferRecord.DestinationBalance = stoi(LoginRegisterDataLine[5]);
		  TransferRecord.UserName = LoginRegisterDataLine[6];


		  return TransferRecord;

	  }

public:
	clsBankClient(enMode Mode, string FristName, string LastName, string Email, string Phone, string Accountnum,
		          string Pincode, float AccountBalance)
		:clsPerson(FristName, LastName, Email, Phone)
	{
		_Mode = Mode;
		_AccountNumber = Accountnum;
		_AccountBalance = AccountBalance;
		_Pincode = Pincode;
	}

	  struct stLogTransferRecord 
	  {
		  string DateTime;
		  string ScourceClient;
		  string DestinaionClient;
		  float Amount;
		  float ScourceBalance;
		  float DestinationBalance;
		  string UserName;
	  };


	bool IsImpty()
	{
		return( _Mode== enMode::EmptyMode);
	}

	bool MarkToDelet()
	{
		return _MarkToDelet;
	}

	string AccountNumber()
	{
		return _AccountNumber;
	}

	void SetPincode(string pincode)
	{
		 _Pincode = pincode;
	}
	string GetPincode()
	{
		return _Pincode;
	}
	__declspec(property(get = GetPincode, put = SetPincode)) string Pincode;

	void SetAccountBalance(float accountbalance)
	{
		 _AccountBalance = accountbalance;
	}
	float GetAccountBalance()
	{
		return _AccountBalance;
	}
	__declspec(property(get = GetAccountBalance, put = SetAccountBalance)) float AccountBalance;

	static clsBankClient Find(string AccountNumber)
	{
		vector <clsBankClient> vClients;
		fstream MyFile;
		MyFile.open("clint.txt", ios::in);
		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsBankClient Client = _ConvertLineToClientObject(Line);
				if (AccountNumber == Client.AccountNumber())
				{
					MyFile.close();
					return Client;
				}
			}
			MyFile.close();
		}
		else
		{
			// أضيفي هذا السطر لتعرفي إذا كان الملف ينفتح أصلاً أم لا
			cout << "\nError: Could not open file! File is missing or in wrong path.\n";
		}
		return _GetEmptyClientObject();
	}
	static clsBankClient Find(string AccountNumber,string Pincode)
	{
		vector <clsBankClient> vClients;
		fstream MyFile;
		MyFile.open("clint.txt", ios::in);//read Mode
		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsBankClient Client = _ConvertLineToClientObject(Line);
				if (AccountNumber == Client.AccountNumber() && Client.Pincode == Pincode)
				{
					MyFile.close();
					return Client;
				}
			}
			MyFile.close();
		}
		return _GetEmptyClientObject();
	}

	static bool IsClientExist(string AccountNumbure)
	{
		clsBankClient client1 = clsBankClient::Find(AccountNumbure);
		return (!client1.IsImpty());
	}

	 enum enSaveResult{ svFailEmptyObject = 0 , svSucceeded = 1 , svFaildAccountNumberExit = 2 };
	 enSaveResult Save()
	 {
		 switch (_Mode)
		 {
		 case enMode::EmptyMode:
		 {
			 return enSaveResult::svFailEmptyObject;
			 break;
		 }
		 case enMode::UpdateMode:
		 {
			 _Update();
			 return enSaveResult::svSucceeded;
			 break;
		 }
		 case enMode::AddNewMode:
			 if (clsBankClient::IsClientExist(_AccountNumber))
			 {
				 return enSaveResult::svFaildAccountNumberExit;
			 }
			 else
			 {
				 _AddNew();
				 _Mode=enMode::UpdateMode;
				 return enSaveResult::svSucceeded;
				 break;
			 }
		 }
	}

	 static clsBankClient GetAddNewClientObject(string Accountnumber)
	 {
		 return clsBankClient(enMode::AddNewMode, "", "", "", "", Accountnumber, "", 0);
	 }

	 bool Delet()
	 {
		 vector<clsBankClient>VClient
			 = _LoadCleintsDataFromFile();
			 for (clsBankClient& C : VClient)
			 {
				 //we only write records that are not marked for delete.
				 if (C._AccountNumber == C.AccountNumber())
				 {
					 C._MarkToDelet = true;
					 break;
				 }
			 }
			 _SaveCleintsDataToFile(VClient);
			 *this = _GetEmptyClientObject();
			 return true;
	 }

	 static vector<clsBankClient>GetClientList() 
	 {
		 // because the _Load is Privet so it couldn't saw by the user this's why we did this funcation to the user see _load
		 // funcation but to new and easy name.
		 return _LoadCleintsDataFromFile();
	 }
	 static double GetTotalBalance()
	 {
		 vector <clsBankClient>VClient =
			 GetClientList();
		 double TotalBalance = 0;
		 for (clsBankClient C : VClient)
		 {
			 TotalBalance += C.AccountBalance;
		 }
		 return TotalBalance;
	 }

	  void Diposit(double amount)
	  {
		 _AccountBalance += amount;
		 Save();
	  }

	  bool Withdraw(double amount)
	  {
		  if (amount > _AccountBalance)
		  {
			  return false;
		  }
		  else 
		  {
			  _AccountBalance -= amount;
			  Save();
		  }
	  }
	 

	  bool Transfer(float Amount, clsBankClient & DestinationClient,string UserName)
	  {
		  if (Amount > AccountBalance)
		  {
			  return false;
		  }
		  Withdraw(Amount);
		  DestinationClient.Diposit(Amount);
		  _RgisterTransferLog(Amount, DestinationClient,UserName);
		  return true;
	  }

	  static vector <stLogTransferRecord> vLogTransferRecord()
	  {
		  vector <stLogTransferRecord> vClient;
		  fstream MyFile;
		  MyFile.open("transferlog.txt", ios::in);//read Mode
		  if (MyFile.is_open())
		  {
			  string Line;
			  while (getline(MyFile, Line))
			  {
				  if (Line != "")
				  {
					 stLogTransferRecord  Client= _ConvertLoginRegisterLineToRecord(Line);
					  vClient.push_back(Client);
				  }
			  }
			  MyFile.close();
		  }
		  return vClient;
	  }
	/*void Print()
	{
		cout << "Client Card:\n";
		cout << "_____________________________\n";

		cout << "\nFristName   : " << FristName;
		cout << "\nLastName    : " << LastName;
		cout << "\nFullName    : " << FullName();
		cout << "\nEmail       : " << Email;
		cout << "\nPhone       : " << Phone;
		cout << "\nAcc. Number : " << _AccountNumber;
		cout << "\nPassword    : " << _Pincode;
		cout << "\nBalance     : " << _AccountBalance;
		cout << "\n_______________________________\n";
	}*/
};

