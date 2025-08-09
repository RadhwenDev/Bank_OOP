#pragma once
#include <iostream>
#include "clsDate.h";
#include <sstream>
#include <string>
using namespace std;

class clsInputValidate
{
public:

	static bool IsDateBetween(clsDate Date, clsDate DateFrom, clsDate DateTo)
	{
		return
			(
				(DateFrom.IsDateBeforeDate2(Date) || Date.IsDateEqualDate2(DateFrom)) &&
				(DateTo.IsDateAfterDate2(Date) || Date.IsDateEqualDate2(DateTo))
				)
			||
			(
				(DateTo.IsDateBeforeDate2(Date) || Date.IsDateEqualDate2(DateTo)) &&
				(DateFrom.IsDateAfterDate2(Date) || Date.IsDateEqualDate2(DateFrom))
				);
	}
	template <class T>
	static bool IsNumberBetween(T Number, T From, T To)
	{
		return (Number >= From && Number <= To);
	}
	template <class T>
	static T ReadNumber(const std::string& ErrorMessage)
	{
		std::string input;
		T Number;
		while (true)
		{
			std::getline(std::cin, input);
			std::stringstream ss(input);

			ss >> Number;

			// Check if the entire input was used, and conversion succeeded
			if (!ss.fail() && ss.eof())
				return Number;

			std::cout << ErrorMessage;
		}
	}
	template <class T>
	static T ReadNumberBetween(T From, T To, const std::string& ErrorMessage)
	{
		T Number;
		do
		{
			Number = ReadNumber<T>(ErrorMessage);
		} while (Number < From || Number > To);
		return Number;
	}
	static bool IsValideDate(clsDate Date)
	{
		return Date.IsValid();
	}
	static string ReadString()
	{
		string  S1 = "";
		// Usage of std::ws will extract allthe whitespace character
		getline(cin >> ws, S1);
		return S1;
	}
};

