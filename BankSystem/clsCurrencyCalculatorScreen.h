#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include <string>
#include "clsUtility.h"
using namespace std;

class clsCurrencyCalculatorScreen : protected clsScreen
{
private:
	static float ReadAmountExchange()
	{
		cout << "\nEnter Amount to Exchange: ";
		float Amount = clsInputValidate::ReadNumber<float>("Enter Amount to Exchange: ");
		return Amount;
	}

	static void PrintCurrencyCard(clsCurrency Currency)
	{
		cout << "-----------------------------\n";
		cout << "Country    : " << Currency.Country();
		cout << "\nCode       : " << Currency.CurrencyCode();
		cout << "\nName       : " << Currency.CurrencyName();
		cout << "\nRate(1$)   : " << Currency.Rate();
		cout << "\n-----------------------------\n\n";
	}

	static float _ExchangeCalculator(float Amount , float Rate, bool test = true)
	{
		if (test)
			return Amount * Rate;
		return Amount / Rate;
	}

	static string _StringConvertToUSD(clsCurrency Currency1, float Amount)
	{
		return to_string(Amount) + " " + Currency1.CurrencyCode() + " = " + to_string(Currency1.ConvertToUSD(Amount)) + " USD";
	}

	static string _StringConvertFromUSD(clsCurrency Currency1, clsCurrency Currency2, float Amount)
	{
		return to_string(Amount) + " " + Currency1.CurrencyCode() + " = " + to_string(Currency1.ConvertToOtherCurrency(Amount, Currency2)) + " " + Currency2.CurrencyCode();
	}

	static void _CurrencyCalculator()
	{
		cout << "Please Enter Currency1 Code:\n";
		string CurrencyCode1 = clsInputValidate::ReadString();

		while (!clsCurrency::IsCurrencyExist(CurrencyCode1))
		{
			cout << "\nCurrency Was not Found, choose another one: ";
			CurrencyCode1 = clsInputValidate::ReadString();
		}

		clsCurrency Currency1 = clsCurrency::FindByCode(CurrencyCode1);

		cout << "\nPlease Enter Currency2 Code:\n";
		string CurrencyCode2 = clsInputValidate::ReadString();

		while (!clsCurrency::IsCurrencyExist(CurrencyCode2))
		{
			cout << "\nCurrency Was not Found, choose another one: ";
			CurrencyCode2 = clsInputValidate::ReadString();
		}

		clsCurrency Currency2 = clsCurrency::FindByCode(CurrencyCode2);

		float Amount = ReadAmountExchange();

		cout << "\nConvert From:\n";
		PrintCurrencyCard(Currency1);

		if("USD" == Currency1.CurrencyCode())
			cout << _StringConvertFromUSD(Currency1, Currency2, Amount);
		else
			cout << _StringConvertToUSD(Currency1, Amount);

		if ("USD" == Currency2.CurrencyCode() || "USD" == Currency1.CurrencyCode())
		{
			return;
		}
		cout << "\n\nConverting from USD to:\n\n";
		cout << "To:\n";
		PrintCurrencyCard(Currency2);

		cout << _StringConvertFromUSD(Currency1, Currency2, Amount);
	}

public:
	static void ShowCurrencyCalculatorScreen()
	{
		_DrawScreenHeader("\tUpdate Currency Screen");
		_CurrencyCalculator();
		cout << "\n\nDo you want to perform another calculation? y/n ? ";
		while(clsUtility::AreYouSure())
		{
			cout << "\n\n";
			_CurrencyCalculator();
			cout << "\n\nDo you want to perform another calculation? y/n ? ";
		}
	}
};

