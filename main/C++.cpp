#pragma once
#include<iostream>
#include<iomanip>
#include"clsLoginScreen.h"
#include"clsInputValidation.h"
using namespace std;
int main() {
	//clsMainScreen::ShowMainMenue();
	while (true)
	{
		clsLoginScreen::ShowLoginScreen();
	}
	return 0;
}
