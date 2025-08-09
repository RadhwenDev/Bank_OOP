#pragma once
#include <iostream>
#include <string>
using namespace std;

class clsUtility
{
public:
	enum enCharacter { SmallLetter = 1, CapitalLetter = 2, Digit = 3, MixChars = 4 };
	static void Srand()
	{
		srand((unsigned)time(NULL));
	}
	static int RandomNumber(int From, int To)
	{
		return rand() % (To - From + 1) + From;
	}
	static char RandomCharacter(enCharacter enCar)
	{
		switch (enCar)
		{
		case enCharacter::SmallLetter:
			return (char)RandomNumber(97, 122);
		case enCharacter::CapitalLetter:
			return (char)RandomNumber(65, 90);
		case enCharacter::Digit:
			return RandomNumber(48, 57);
		case enCharacter::MixChars:
			switch ((enCharacter)RandomNumber(1, 3))
			{
			case enCharacter::SmallLetter:
				return (char)RandomNumber(97, 122);
			case enCharacter::CapitalLetter:
				return (char)RandomNumber(65, 90);
			default:
				return RandomNumber(48, 57);
			}
		default:
			return char(RandomNumber(65, 90));
		}
	}
	static string GenerateWord(enCharacter enCar, int length)
	{
		string word = "";
		for (int i = 0; i < length; i++)
		{
			word += RandomCharacter(enCar);
		}
		return word;
	}
	static string GenerateOneKey(enCharacter enCar, int length)
	{
		string key = "";
		for (int i = 0; i < length; i++)
		{
			if (i < 3)
				key += GenerateWord(enCar, 4) + "-";
			else
				key += GenerateWord(enCar, 4);
		}
		return key;
	}
	static void GenerateKeys(enCharacter enCar, int num)
	{
		for (int i = 1; i <= num; i++)
		{
			cout << endl << "Key [" << i << "] : " << GenerateOneKey(enCar, 4);
		}
	}
	static void Swap(int& x, int& y)
	{
		int temp = x;
		x = y;
		y = temp;
	}
	static void Swap(double& x, double& y)
	{
		double temp = x;
		x = y;
		y = temp;
	}
	static void Swap(string& x, string& y)
	{
		string temp = x;
		x = y;
		y = temp;
	}
	static void ShuffleArray(int Arr[5], int length)
	{
		for (int i = length - 1; i > 0; i--)
		{
			int j = RandomNumber(0, i + 1);
			Swap(Arr[i], Arr[j]);
		}
	}
	static void ShuffleArray(string Arr[5], int length)
	{
		for (int i = length - 1; i > 0; i--)
		{
			int j = RandomNumber(0, i + 1);
			Swap(Arr[i], Arr[j]);
		}
	}
	static void FillArrayWithRandomNumbers(int Arr3[5], int length, int From, int To)
	{
		for (int i = 0; i < length; i++)
			Arr3[i] = RandomNumber(From, To);
	}
	static void FillArrayWithRandomWords(string Arr4[5], int Row_length, enCharacter enCar, int length)
	{
		for (int i = 0; i < Row_length; i++)
			Arr4[i] = GenerateWord(enCar, length);
	}
	static void FillArrayWithRandomKeys(string Arr4[5], int Row_length, enCharacter enCar, int length)
	{
		for (int i = 0; i < Row_length; i++)
			Arr4[i] = GenerateOneKey(enCar, length);
	}
	static string Tabs(int length)
	{
		string Tab = "";
		for (int i = 0; i < length; i++)
			Tab += "\t";
		return Tab;
	}
	static string EncryptText(string Text, short EncryptionKey)
	{
		string TextEnrypt = "";
		for (int i = 0; i < Text.length(); i++)
		{
			TextEnrypt += char((int)Text[i] + EncryptionKey);
		}
		return TextEnrypt;
	}
	static string DecryptText(string Text, short EncryptionKey)
	{
		string TextEnrypt = "";
		for (int i = 0; i < Text.length(); i++)
		{
			TextEnrypt += char((int)Text[i] - EncryptionKey);
		}
		return TextEnrypt;
	}

	static string ConvertSingleNumberToString(int Number)
	{
		string arr[9] = { "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine" };
		if (Number >= 1 && Number <= 9)
			return arr[Number - 1];
		return "";
	}

	static string ConvertTwoNumberUnderTwentyToString(int Number)
	{
		string arr[] = { "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen" };
		if (Number >= 10 && Number <= 19)
			return arr[Number - 10];
		return "";
	}

	static string ConvertTwoNumberToString(int Number)
	{
		string arr[] = { "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety" };
		if (Number >= 2 && Number <= 9)
			return arr[Number - 2];
		return "";
	}

	static string ConvertPartOfNumberToString(int Number, string Arr[4], short count)
	{
		string String = "";
		int Num = Number % 1000;
		if (Num >= 100)
		{
			String = ConvertSingleNumberToString(Num / 100) + " Hundred ";
			if (Num % 100 < 10 || Num % 10 != 0)
				String += ConvertTwoNumberToString((Num % 100) / 10) + " " + ConvertSingleNumberToString((Num % 10)) + " " + Arr[count];
			else if (Num % 100 >= 10 && Num % 100 <= 19)
				String += ConvertTwoNumberUnderTwentyToString(Num % 100) + " " + Arr[count];
			else
				String += ConvertTwoNumberToString((Num % 100) / 10) + " " + Arr[count];
		}
		else if (Num < 10 && Num % 10 != 0)
			String += ConvertSingleNumberToString((Num % 10)) + " " + Arr[count];
		else if (Num >= 10 && Num <= 19)
			String += ConvertTwoNumberUnderTwentyToString(Num % 100) + " ";
		else
		{
			String += ConvertTwoNumberToString((Num % 100) / 10);
			if (Num % 10 != 0)
				String += " " + ConvertSingleNumberToString(Num % 10) + " " + Arr[count];
			else
				String += " " + Arr[count];
		}
		return String;
	}

	static string ConvertAllNumberToString(int Number)
	{
		string Arr[4] = { "","Thousand ", "Million ", "Billion " };
		string String = "";
		short i = 0;
		int Num = 0;
		if (Number == 0)
			return "Zero";
		while (Number > 0)
		{
			Num = Number % 1000;
			String = ConvertPartOfNumberToString(Num, Arr, i) + String;
			Number /= 1000;
			i++;
		}
		return String;
	}

	static string ConverAllFractionalPartToString(float Number)
	{
		float Num = Number - floor(Number);
		if (Num == 0)
			return "";
		int IntNum = round(Num * 100);
		return "point " + ConvertAllNumberToString(IntNum);
	}

	static string NumberToText(float Number)
	{
		return ConvertAllNumberToString(floor(Number)) + ConverAllFractionalPartToString(Number);
	}

	static bool AreYouSure()
	{
		string Answer = "n";
		getline(cin >> ws, Answer);
		while (Answer != "Y" && Answer != "y" && Answer != "n" && Answer != "N")
		{
			cout << "\nPlease enter (Y/y) : Yes, (N/n) : No  ";
			cin >> Answer;
		}
		if (Answer == "Y" || Answer == "y")
			return true;
		return false;
	}
};

