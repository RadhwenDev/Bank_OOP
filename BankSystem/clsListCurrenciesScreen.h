#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsCurrency.h"
#include <iomanip>
#include <string>
using namespace std;
class clsListCurrenciesScreen : protected clsScreen
{
private:
	static void PrintExchangeCurrency(clsCurrency Currency)
	{
		cout << "\t| " << setw(25) << left << Currency.Country();
		cout << "\t| " << setw(8) << left << Currency.CurrencyCode();
		cout << "\t| " << setw(40) << left << Currency.CurrencyName();
		cout << "\t| " << setw(12) << left << Currency.Rate();
	}
public:
	static void ShowListCurrenciesScreen()
	{
		vector <clsCurrency> vCurrency;
		vCurrency = clsCurrency::GetAllUSDRates();
		string Title = "\t\tCurrencies List Screen";
		string SubTitle = "\t\t  (" + to_string(vCurrency.size()) + ") Currency.";
		_DrawScreenHeader(Title, SubTitle);
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "______________________________________________________\n" << endl;
		cout << "\t| " << setw(25) << left << "Country";
		cout << "\t| " << setw(8) << left << "Code";
		cout << "\t| " << setw(40) << left << "Name";
		cout << "\t| " << setw(12) << left << "Rate/(1$)";
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "______________________________________________________\n" << endl;
		for (clsCurrency& Currency : vCurrency)
		{
			PrintExchangeCurrency(Currency);
			cout << endl;
		}
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "______________________________________________________\n" << endl;
	}
};

