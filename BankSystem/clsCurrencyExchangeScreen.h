#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsListCurrenciesScreen.h"
#include "clsFindCurrencyScreen.h"
#include "clsUpdateRateScreen.h"
#include "clsCurrencyCalculatorScreen.h"
using namespace std;

class clsCurrencyExchangeScreen : protected clsScreen
{
private:
	enum enExchangeCurrency {eListCurrencies = 1, eFindCurrency = 2, eUpdateRate = 3, eCurrencyCalculator = 4, eMainMenue = 5};

	static short _ReadExchangCurrency()
	{
		cout << setw(40) << left << "" << "Choose what do you want to do? [1 to 5]? ";
		short Choice = clsInputValidate::ReadNumberBetween<short>(1, 5, "Enter Number between 1 to 5? ");
		return Choice;
	}

	static void _GoBackToExchageCurrencyScreen()
	{
		cout << setw(37) << left << "" << "\n\tPress any key to go back to Exchange Currency...\n";
		system("pause>0");
		ShowCurrencyExchange();
	}

	static void _ShowListCurrencies()
	{
		clsListCurrenciesScreen::ShowListCurrenciesScreen();
	}

	static void _ShowFindCurrency()
	{
		clsFindCurrencyScreen::ShowFindCurrencyScreen();
	}

	static void _ShowUpdateRate()
	{
		clsUpdateRateScreen::ShowUpdateRateScreen();
	}

	static void _ShowCurrencyCalculator()
	{
		clsCurrencyCalculatorScreen::ShowCurrencyCalculatorScreen();
	}

	static void _PerformExchangeCurrenciesOption(enExchangeCurrency ExchageCurrency)
	{
		switch (ExchageCurrency)
		{
		case enExchangeCurrency::eListCurrencies:
			system("cls");
			_ShowListCurrencies();
			_GoBackToExchageCurrencyScreen();
			break;

		case enExchangeCurrency::eFindCurrency:
			system("cls");
			_ShowFindCurrency();
			_GoBackToExchageCurrencyScreen();
			break;

		case enExchangeCurrency::eUpdateRate:
			system("cls");
			_ShowUpdateRate();
			_GoBackToExchageCurrencyScreen();
			break;

		case enExchangeCurrency::eCurrencyCalculator :
			system("cls");
			_ShowCurrencyCalculator();
			_GoBackToExchageCurrencyScreen();
			break;
		}
	}

public:
	static void ShowCurrencyExchange()
	{
		system("cls");
		_DrawScreenHeader("\tCurrency Exchange Main Screen");
		cout << "\t\t\t\t\t==========================================";
		cout << "\n\t\t\t\t\t\t    Currency Exchange Menue\n";
		cout << "\t\t\t\t\t==========================================";
		cout << "\n\t\t\t\t\t   [1] List Currencies.";
		cout << "\n\t\t\t\t\t   [2] Find Currency.";
		cout << "\n\t\t\t\t\t   [3] Update Rate.";
		cout << "\n\t\t\t\t\t   [4] Currency Calculator.";
		cout << "\n\t\t\t\t\t   [5] Main Menue.";
		cout << "\n\t\t\t\t\t==========================================\n";
		_PerformExchangeCurrenciesOption(enExchangeCurrency(_ReadExchangCurrency()));
	}
};

