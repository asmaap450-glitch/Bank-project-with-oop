#pragma once
#include<iostream>
#include"clsUser.h"
#include "clsBankClient.h"
clsUser CurrentUser = clsUser::Find("", "");
//string account1 =clsTransferScreen::_ReadAccountNumber("\nPlease Enter Account Number To Transfer from\n");
 clsBankClient CurrentClient = clsBankClient::Find("","");