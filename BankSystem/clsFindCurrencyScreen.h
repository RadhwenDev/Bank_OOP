#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsCurrency.h"
#include "clsInputValidate.h"
using namespace std;

class clsFindCurrencyScreen : protected clsScreen
{
private:
	static short _ReadTypeOfWriting()
	{
		cout << "Find By: [1] Code or [2] Country ? ";
		short Choice = clsInputValidate::ReadNumberBetween(1, 2, "Enter Number 1 Or 2 : ");
		return Choice;
	}

	static void _ShowResults(clsCurrency Currency)
	{
		if (Currency.IsEmpty())
		{
			cout << "\nCurrency Was not Found :-(\n\n";
			return;
		}
		else
		{
			cout << "\nCurrency Found :-)\n\n";
			PrintCurrencyCard(Currency);
		}
	}

	static void PrintCurrencyCard(clsCurrency Currency)
	{
		cout << "Currency Card:\n";
		cout << "-----------------------------\n";
		cout << "Country    : " << Currency.Country();
		cout << "\nCode       : " << Currency.CurrencyCode();
		cout << "\nName       : " << Currency.CurrencyName();
		cout << "\nRate(1$)   : " << Currency.Rate();
		cout << "\n-----------------------------\n";
	}

public:
	static void ShowFindCurrencyScreen()
	{
		_DrawScreenHeader("Find Currency Screen");
		if (_ReadTypeOfWriting() == 1)
		{
			cout << "Please Enter CurrencyCode: ";
			string CurrencyCode = clsInputValidate::ReadString();
			clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
			_ShowResults(Currency);
		}
		else
		{
			cout << "Please Enter Country Name: ";
			string CountryName = clsInputValidate::ReadString();
			clsCurrency CurrencyCountry = clsCurrency::FindByCountry(CountryName);
			_ShowResults(CurrencyCountry);
		}
	}
};

