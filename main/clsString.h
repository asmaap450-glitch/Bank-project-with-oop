#pragma once
#include<iostream>
#include<vector>
using namespace std;
class clsString
{
private:
	string _value;
public:
	clsString()
	{
		_value = "";
	}
	clsString(string value)
	{
		_value = value;
	}
	string SetValue(string value)
	{
		return _value = value;
	}
	string GetValue()
	{
		return _value;
	}
	__declspec(property(get = GetValue, put = SetValue))string Value;

	static short Length(string si)
	{
		return si.length();
	}
	short Length()
	{
		return _value.length();
	}

	static short CountWords(string si)
	{
		short count = 0;
		short pos = 0;
		string delim = " ";
		string sword;
		while ((pos = si.find(delim)) != std::string::npos)
		{
			sword = si.substr(0, pos);
			if (sword != " ")
				count++;
			si.erase(0, pos + delim.length());
		}
		if (si != " ")
			count++;
		return count;
	}
	short CountWords()
	{
		return CountWords(_value);
	}
	
	static string LowerFristLittleFromEachWord(string si) {
		bool fristlittle = true;
		cout << "frist letter of the string\n";
		for (int i = 0;i < si.length();i++)
		{
			if (si[i] != ' ' && fristlittle) {
				si[i] = tolower(si[i]);
			}
			fristlittle = (si[i] == ' ' ? true : false);
		}
		return si;
	}
	void LowerFristLittleFromEachWord() {
		_value= LowerFristLittleFromEachWord(_value);
	}

	static string UpperFristLitterFromEachWord(string si) {
		bool fristlittle = true;
		for (int i = 0;i < si.length();i++)
		{
			if (si[i] != ' ' && fristlittle) {
				si[i] = toupper(si[i]);
			}
			fristlittle = (si[i] == ' ' ? true : false);
		}
		return si;
	}
	void UpperFristLitterFromEachWord() {
	_value = UpperFristLitterFromEachWord(_value);
	}

	static string  UpperAllString(string S1)
	{
		for (short i = 0; i < S1.length(); i++)
		{
			S1[i] = toupper(S1[i]);
		}
		return S1;
	}
	void  UpperAllString()
	{
		_value = UpperAllString(_value);
	}

	static string  LowerAllString(string S1)
	{
		for (short i = 0; i < S1.length(); i++)
		{
			S1[i] = tolower(S1[i]);
		}
		return S1;
	}
	void  LowerAllString()
	{
		_value = LowerAllString(_value);
	}

	static char  InvertLetterCase(char char1)
	{
		return isupper(char1) ? tolower(char1) : toupper(char1);
	}

	static string  InvertAllLettersCase(string S1)
	{
		for (short i = 0; i < S1.length(); i++)
		{
			S1[i] = InvertLetterCase(S1[i]);
		}
		return S1;
	}
	void  InvertAllLettersCase()
	{
		_value = InvertAllLettersCase(_value);
	}

	enum enWhatToCount { SmallLetters = 0, CapitalLetters = 1, All = 3 };

	static short CountLetters(string S1, enWhatToCount WhatToCount = enWhatToCount::All)
	{


		if (WhatToCount == enWhatToCount::All)
		{
			return S1.length();
		}

		short Counter = 0;

		for (short i = 0; i < S1.length(); i++)
		{

			if (WhatToCount == enWhatToCount::CapitalLetters && isupper(S1[i]))
				Counter++;


			if (WhatToCount == enWhatToCount::SmallLetters && islower(S1[i]))
				Counter++;


		}

		return Counter;

	}

	static short  CountCapitalLetters(string S1)
	{

		short Counter = 0;

		for (short i = 0; i < S1.length(); i++)
		{

			if (isupper(S1[i]))
				Counter++;

		}

		return Counter;
	}
	short  CountCapitalLetters()
	{
		return CountCapitalLetters(_value);
	}

	static short  CountSmallLetters(string S1)
	{

		short Counter = 0;

		for (short i = 0; i < S1.length(); i++)
		{

			if (islower(S1[i]))
				Counter++;

		}

		return Counter;
	}
	short  CountSmallLetters()
	{
		return CountSmallLetters(_value);
	}

	static short CountSpecificLetter(string si, char letter, int matchcase = true) {
		int count = 0;
		for (int i = 0;i < si.length();i++)
		{
			if (matchcase)
			{
				if (si[i] == letter)
					count++;
			}
			else
			{
				if (tolower(si[i]) == tolower(letter))
					count++;
			}
		}
		return count;
	}
	short CountSpecificLetter(char letter, bool matchcase = true)
	{
		return CountSpecificLetter(_value, letter);
	}

	static bool IsVowel(char Ch1)
	{
		Ch1 = tolower(Ch1);

		return ((Ch1 == 'a') || (Ch1 == 'e') || (Ch1 == 'i') || (Ch1 == 'o') || (Ch1 == 'u'));

	}

	static short  CountVowels(string S1)
	{

		short Counter = 0;

		for (short i = 0; i < S1.length(); i++)
		{

			if (IsVowel(S1[i]))
				Counter++;

		}

		return Counter;
	}
	short  CountVowels()
	{
		return CountVowels(_value);
	}

	static vector<string> Split(string si,string Delim ) {
		vector<string>vstring;
		short pos = 0;
		string sword;
		while ((pos = si.find(Delim)) != std::string::npos)
		{
			sword = si.substr(0, pos);
			if (sword != " ")
			{
				vstring.push_back(sword);
			}
			si.erase(0, pos + Delim.length());
		}
		if (si != " ")
		{
			vstring.push_back(si);
		}
		return vstring;
	}
	vector<string>Split(string Delim)
	{
		return Split(_value, Delim);
	}

	static string  TrimLeft(string si) {
		for (int i = 0;i < si.length();i++)
		{
			if (si[i] != ' ')
			{
				return si.substr(i, si.length() - i);
			}
		}
		return " ";
	}
	string TrimLeft()
	{
		return TrimLeft(_value);
	}

	static string TrimRight(string si) {
		for (int i = si.length() - 1;i >= 0;i--)
		{
			if (si[i] != ' ')
			{
				return si.substr(0, i + 1);
			}
		}
		return " ";
	}
	string TrimRight()
	{
		return TrimRight(_value);
	}

	static string Trim(string si) {
		return TrimLeft(TrimRight(si));
	}
	string Trim()
	{
		return Trim(_value);
	}

	static string JoinString(string arrsi[], short length,string delim) {
		string word = " ";
		for (int i = 0;i <= length;i++)
		{
			word = word + arrsi[i] + delim;
		}
		return word.substr(0, word.length() - delim.length());
	}

	static string JoinString(vector<string> vsi, string delim) {
		string word = " ";
		for (string& i : vsi)
		{
			word = word + i + delim;
		}
		return word.substr(0, word.length() - delim.length());
	}

	static void PrintEachWord(string si) {
		short count = 0;
		short pos = 0;
		string delim = " ";
		string sword;
		while ((pos = si.find(delim)) != std::string::npos)
		{
			sword = si.substr(0, pos);
			if (sword != " ")
				cout << sword << endl;;
			si.erase(0, pos + delim.length());
		}
		if (si != " ")
			cout << si << endl;
	}
	void PrintEachWord()
	{
		PrintEachWord(_value);
	}

	static string ReversWordInString(string str) {
		vector<string>vstr;
		string str2 = "";
		vstr = Split(str," ");
		vector<string>::iterator iter = vstr.end();// iter مش حاجه جواها قيمه هو point من  نوع الفيكتور بيأشر علي قيمه 
		while (iter != vstr.begin())
		{
			--iter;
			str2 += *iter + " ";
		}
		return	str2 = str2.substr(0, str2.length() - 1);
	}
	void ReversWordInString()
	{
		_value= ReversWordInString(_value);
	}

	static string ReplaseWordByBuiltInFuncation(string sr, string stringtoreplase, string replaseto) {
		int pos = sr.find(stringtoreplase);
		while (pos != std::string::npos)
		{
			sr = sr.replace(pos, stringtoreplase.length(), replaseto);
			pos = sr.find(stringtoreplase);
		}
		return sr;
	}
	string ReplaseWordByBulitInFuncation(string stringtoreplas, string replaseto)
	{
		return ReplaseWordByBuiltInFuncation(_value, stringtoreplas, replaseto);
	}

	static string ReplaceWord(string S1, string StringToReplace, string sRepalceTo, bool MatchCase = true)
	{

		vector<string> vString = Split(S1, " ");

		for (string& s : vString)
		{
			if (MatchCase)
			{
				if (s == StringToReplace)
				{
					s = sRepalceTo;
				}
			}
			else
			{
				if (LowerAllString(s) == LowerAllString(StringToReplace))
				{
					s = sRepalceTo;
				}

			}
		}
		return JoinString(vString, " ");
	}
	string ReplaceWord(string StringToReplace, string sRepalceTo)
	{
		return ReplaceWord(_value, StringToReplace, sRepalceTo);
	}

	static string RemovePunctuations(string S1)
	{
		string S2 = "";

		for (short i = 0; i < S1.length(); i++)
		{
			if (!ispunct(S1[i]))
			{
				S2 += S1[i];
			}
		}
		return S2;
	}
	void RemovePunctuations()
	{
		_value = RemovePunctuations(_value);
	}

};

