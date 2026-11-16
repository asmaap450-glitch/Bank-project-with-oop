#pragma once
#include<iostream>
#include"clsPerson.h"
#include"clsString.h"
#include<vector>
#include<fstream>
#include"clsUtil.h"
#include <filesystem>
class clsUser:public clsPerson
{
	
	enum enMode { EmptyMode = 0, UpdateMode = 1, AddNewMode = 2 };
	enMode _Mode;
	string _UserName;
	string _Password;
	int _Permissions;

	bool _MarkToDelet = false;

	static clsUser _ConvertLineToUserObject(string Line, string Seperator = "#//#")
	{
		vector<string>vUserData;
		vUserData = clsString::Split(Line, Seperator);

		return clsUser(enMode::UpdateMode, vUserData[0], vUserData[1], vUserData[2], vUserData[3],
			vUserData[4], clsUtil::DecryptText( vUserData[5]), stod(vUserData[6]));
	}

	static string _ConvertUserObjectToLine(clsUser user, string Seperator = "#//#")
	{
		string stUserRecord = "";
	     stUserRecord += user.FristName + Seperator;
		stUserRecord += user.LastName + Seperator;
		stUserRecord += user.Email + Seperator;
		stUserRecord +=user.Phone + Seperator;
		stUserRecord +=user.UserName + Seperator;
		stUserRecord += clsUtil::EncryptText(user.PassWord) + Seperator;
		stUserRecord += to_string(user.Permissions);
		return stUserRecord;
	}

	static vector <clsUser> _LoadCleintsDataFromFile()
	{
		vector <clsUser> vUsers;
		fstream MyFile;
		MyFile.open("users.txt", ios::in);//read Mode
		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				
					clsUser User = _ConvertLineToUserObject(Line);
					vUsers.push_back(User);
			}
			MyFile.close();
		}
		return vUsers;
	}
	
	static void _SaveCleintsDataToFile(vector<clsUser> vUsers)
	{
		fstream MyFile;
		MyFile.open("users.txt", ios::out);//overwrite
		string DataLine;
		if (MyFile.is_open())
		{
			for (clsUser C : vUsers)
			{
				//we only write records that are not marked for delete.
				if (C._MarkToDelet == false)
				{
					DataLine = _ConvertUserObjectToLine(C);
					MyFile << DataLine << endl;
				}
			}
			MyFile.close();
		}
	}

	void _AddDataLineToFail(string stdata) {
		fstream myfail;
		myfail.open("users.txt", ios::out | ios::app);

		if (myfail.is_open()) {

			myfail << stdata << endl;

			myfail.close();
		}
	}

	void _AddNew()
	{
		_AddDataLineToFail(_ConvertUserObjectToLine(*this));
	}

	void _Update()
	{
		vector<clsUser>vUsers
			= _LoadCleintsDataFromFile();
		for (clsUser & U : vUsers)
		{
			if (U._UserName == UserName)
			{
				U = *this;
				break;
			}
		}
		_SaveCleintsDataToFile(vUsers);
	}

	static clsUser _GetEmptyUserObject()
	{
		return clsUser(enMode::EmptyMode, "", "", "", "", "", "", 0);
	}
	 
	struct stLoginRegister;

	static stLoginRegister _ConvertLoginRegisterLineToRecord(string Line, string Seperator = "#//#")
	{
		stLoginRegister LoginRegisterRecord;
		vector <string> LoginRegisterDataLine = clsString::Split(Line, Seperator);
		LoginRegisterRecord.DateTime = LoginRegisterDataLine[0];
		LoginRegisterRecord.UserName = LoginRegisterDataLine[1];
		LoginRegisterRecord.Password = clsUtil::DecryptText(LoginRegisterDataLine[2]);
		LoginRegisterRecord.Permission = stoi(LoginRegisterDataLine[3]);

		return LoginRegisterRecord;

	}
    string _PrepareLoginRecord( string Seperator = "#//#")
	{
		string stuserRecord = "";
		stuserRecord += clsDate::GetSystemDateTimeString() + Seperator;
		stuserRecord += UserName+ Seperator;
		stuserRecord += clsUtil::EncryptText(PassWord) + Seperator;
		stuserRecord += to_string(Permissions);
		return stuserRecord;
	}

public:

      enum enPermission {
		pListClient = 1, pAddNewlCient = 2, pDeletClient = 4, pUpdateClient = 8,
		pFindClient = 16, Transaction = 32, Manageusers = 64, LoginRegister = 128 , CurrencyEx = 256 , All = -1 };

	  struct stLoginRegister 
	  {
		  string DateTime;
		  string UserName;
		  string Password;
		  int Permission;
	  };


	  static vector <stLoginRegister> vLoginRegisterRecord()
	  {
		  vector <stLoginRegister> vUsers;
		  fstream MyFile;
		  MyFile.open("logFail.txt", ios::in);//read Mode
		  if (MyFile.is_open())
		  {
			  string Line;
			  while (getline(MyFile, Line))
			  {
				  if (Line != "")
				  {
					  stLoginRegister User = _ConvertLoginRegisterLineToRecord(Line);
					  vUsers.push_back(User);
				  }
			  }
			  MyFile.close();
		  }
		  return vUsers;
	  }

	clsUser(enMode Mode, string FristName, string LastName, string Email,
		string Phone, string UserName, string Password, int Permissions) :
		clsPerson(FristName, LastName, Email, Phone)
	{
		_Mode = Mode;
		_UserName = UserName;
		_Password = Password;
		_Permissions = Permissions;
	}

	bool IsImpty()
	{
		return(_Mode == enMode::EmptyMode);
	}

	bool MarkToDelet()
	{
		return _MarkToDelet;
	}

	string GetUserName()
	{
		return _UserName;
	}
	void SetUserName(string username)
	{
		_UserName = username;
	}
	__declspec(property(get = GetUserName ,put = SetUserName)) string UserName;

	string GetPassWord()
	{
		return _Password;
	}
	void SetPassWord(string Password)
	{
		_Password = Password;
	}
	__declspec(property(get = GetPassWord, put = SetPassWord)) string PassWord;

	int GetPermissions()
	{
		return _Permissions;
	}
	void SetPermissions(int per)
	{
		_Permissions = per;
	}
	__declspec(property(get = GetPermissions, put = SetPermissions)) int Permissions;

	static clsUser Find(string UserName)
	{
		vector <clsUser> vUsers;
		fstream MyFile;

		MyFile.open("users.txt", ios::in);
		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsUser User = _ConvertLineToUserObject(Line);
				if ( UserName == User.UserName)
				{
					MyFile.close();
					return User;
				}
			}
			MyFile.close();
		}
		else
		{
			// أضيفي هذا السطر لتعرفي إذا كان الملف ينفتح أصلاً أم لا
			cout << "\nError: Could not open file! File is missing or in wrong path.\n";
		}
		return _GetEmptyUserObject();
	}
	static clsUser Find(string UserName, string PassWord)
	{
		vector <clsUser> vUsers;
		fstream MyFile;

		MyFile.open("users.txt", ios::in);//read Mode
		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsUser User = _ConvertLineToUserObject(Line);
				if (UserName == User.UserName && PassWord ==User.PassWord)
				{
					MyFile.close();
					return User;
				}
			}
			MyFile.close();
		}
		return _GetEmptyUserObject();
	}

	static bool IsUserExist(string UserName)
	{
		clsUser User = clsUser::Find(UserName);
		return (!User.IsImpty());
	}

	enum enSaveResult { svFailEmptyObject = 0, svSucceeded = 1, svFaildAccountNumberExit = 2 };
	enSaveResult Save()
	{
		switch (_Mode)
		{
		case enMode::EmptyMode:
		{
			if (IsImpty())
			{
				return enSaveResult::svFailEmptyObject;
			}
			break;
		}
		case enMode::UpdateMode:
		{
			_Update();
			return enSaveResult::svSucceeded;
			break;
		}
		case enMode::AddNewMode:
		{
			if (clsUser::IsUserExist(_UserName))
			{
				return enSaveResult::svFaildAccountNumberExit;
			}
			else
			{
				_AddNew();
				_Mode = enMode::UpdateMode;
				return enSaveResult::svSucceeded;
			}
			break;
		}
		}
	}

	static clsUser GetAddNewUserObject(string UserName)
	{
		return clsUser(enMode::AddNewMode, "", "", "", "", UserName, "", 0);
	}

	bool Delet()
	{
		vector<clsUser>vUsers
			= _LoadCleintsDataFromFile();
		for (clsUser& C : vUsers)
		{
			//we only write records that are not marked for delete.
			if (C.UserName == _UserName)
			{
				C._MarkToDelet = true;
				break;
			}
		}
		_SaveCleintsDataToFile(vUsers);
		*this = _GetEmptyUserObject();
		return true;
	}

	static vector<clsUser>GetUserList()
	{
		// because the _Load is Privet so it couldn't saw by the user this's why we did this funcation to the user see _load
		// funcation but to new and easy name.
		return _LoadCleintsDataFromFile();
	}
	
	bool CheckAccessPermission(enPermission permission)
	{
		if (this->Permissions == enPermission::All)
			return true;
		if ((permission & this->Permissions) == permission)
			return true;
		else
			return false;
	}

	 void RegisterLogin() {
		string stdata = _PrepareLoginRecord();
		fstream myfail;
		myfail.open("logFail.txt", ios::out | ios::app);

		if (myfail.is_open()) {

			myfail << stdata << endl;

			myfail.close();
		}
	}

	 
};

