#pragma once
#include <iostream>
#include "clsInputValidate.h"
#include "clsBankClient.h"
#include "clsScreen.h"
#include "clsUser.h"
#include "Global.h"
#include "clsUtility.h"
using namespace std;

class clsTransferScreen : protected clsScreen
{
private:
	static void _ShowClientCard(clsBankClient Client)
	{
		cout << "\nClient Card:\n";
		cout << "__________________________\n";
		cout << "\nFull Name   :" << Client.FullName();
		cout << "\nAcc. Number :" << Client.AccountNumber;
		cout << "\nBalance     :" << Client.AccountBalance;
		cout << "\n__________________________\n\n";
	}


public:
	static void ShowTransferScreen()
	{
		_DrawScreenHeader("Transfer Screen");
		cout << "Please Enter Account Number to Transfer From: ";
		string AccountNum1 = clsInputValidate::ReadString();
		while (!clsBankClient::IsClientExist(AccountNum1))
		{
			cout << "\nClient with [" << AccountNum1 << "] does not exist, Choose another Account: ";
			AccountNum1 = clsInputValidate::ReadString();
		}
		clsBankClient Client1 = clsBankClient::Find(AccountNum1);
		_ShowClientCard(Client1);

		cout << "Please Enter Account Number to Transfer To: ";
		string AccountNum2 = clsInputValidate::ReadString();
		while (!clsBankClient::IsClientExist(AccountNum2) || AccountNum1 == AccountNum2)
		{
			if (AccountNum1 == AccountNum2)
				cout << "\nSorry, You don't Transfer To your Account, Choose another Account: ";
			else
				cout << "\nClient with [" << AccountNum2 << "] does not exist, Choose another Account: ";
			AccountNum2 = clsInputValidate::ReadString();
		}

		clsBankClient Client2 = clsBankClient::Find(AccountNum2);
		_ShowClientCard(Client2);

		float TransferAmount = clsInputValidate::ReadNumber<float>("Enter Transfer Amount? ");
		while (TransferAmount > Client1.AccountBalance)
		{
			TransferAmount = clsInputValidate::ReadNumber<float>("Amount Exceeds the available Balance, Enter another Amount ? ");
		}
		cout << "\nAre you sure you want to perform this operation? y/n? ";
		if (!clsUtility::AreYouSure())
			cout << "\nOperation was Cancelled!\n";
		else
		{
			Client1.Transfer(TransferAmount, Client2);
			cout << "\nTransfer done Successfully\n";
			_ShowClientCard(Client1);
			_ShowClientCard(Client2);
			cout << "\n\n";
			clsUser::_SaveTransferLogToFile(Client1, Client2, CurrentUser, TransferAmount);
		}
	}
};

