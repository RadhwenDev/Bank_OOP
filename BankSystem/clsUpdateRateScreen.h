#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsCurrency.h"
#include "clsInputValidate.h"
#include "clsUtility.h"
using namespace std;

class clsUpdateRateScreen : protected clsScreen
{
private:
	static void PrintCurrencyCard(clsCurrency Currency)
	{
		cout << "Currency Card:\n";
		cout << "-----------------------------\n";
		cout << "Country    : " << Currency.Country();
		cout << "\nCode       : " << Currency.CurrencyCode();
		cout << "\nName       : " << Currency.CurrencyName();
		cout << "\nRate(1$)   : " << Currency.Rate();
		cout << "\n-----------------------------\n\n";
	}

public:
	static void ShowUpdateRateScreen()
	{
		_DrawScreenHeader("\tUpdate Currency Screen");
		cout << "Please enter Currency Code: ";
		string CurrencyCode = clsInputValidate::ReadString();
		
		while (!clsCurrency::IsCurrencyExist(CurrencyCode))
		{
			cout << "\nCurrency Was not Found, choose another one: ";
			CurrencyCode = clsInputValidate::ReadString();
		}
		cout << "\nCurrency Found :-)\n\n";
		clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
		PrintCurrencyCard(Currency);
		cout << "Are you sure you want to update the rate of this Currency y/n? ";
		if (!clsUtility::AreYouSure())
			return;
		cout << "\nUpdate Currency Rate:\n";
		cout << "____________________\n";
		cout << "\nEnter New Rate: ";
		float Rate = clsInputValidate::ReadNumber<float>("Enter New Rate : ");
		Currency.UpdateRate(Rate);
		cout << "\nCurrency Rate Updated Successfully :-)\n\n";
		PrintCurrencyCard(Currency);
	}
};

