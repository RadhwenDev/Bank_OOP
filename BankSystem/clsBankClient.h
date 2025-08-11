#pragma once
#include <iostream>
#include "clsPerson.h";
#include <vector>
#include <string>
#include "clsString.h";
#include <fstream>

using namespace std;

class clsBankClient : public clsPerson
{
private:
	enum enMode { EmptyMode = 0, UpdateMode = 1, AddNewMode = 2};
	enMode _Mode;
	string _AccountNumber;
	string _PinCode;
	float _AccountBalance;
	bool _MarkForDelete = false;

	static clsBankClient _ConvertLineToClientObject(string Line, string Seperator = "#//#")
	{
		vector <string> vClientData;
		vClientData = clsString::Split(Line, Seperator);
		return clsBankClient(enMode::UpdateMode, vClientData[0], vClientData[1], vClientData[2], vClientData[3], vClientData[4], vClientData[5], stof(vClientData[6]));
	}

	static string _ConvertClientObjectToLine(clsBankClient Client, string Seperator = "#//#")
	{
		string stClientRecord = "";
		stClientRecord += Client.FirstName + Seperator;
		stClientRecord += Client.LastName + Seperator;
		stClientRecord += Client.Email + Seperator;
		stClientRecord += Client.Phone + Seperator;
		stClientRecord += Client.AccountNumber + Seperator;
		stClientRecord += Client.PinCode + Seperator;
		stClientRecord += to_string(Client.AccountBalance);

		return stClientRecord;

	}

	static  vector <clsBankClient> _LoadClientsDataFromFile()
	{
		vector <clsBankClient> vClients;

		fstream MyFile;
		MyFile.open("MyClient.txt", ios::in);//read Mode

		if (MyFile.is_open())
		{

			string Line;


			while (getline(MyFile, Line))
			{

				clsBankClient Client = _ConvertLineToClientObject(Line);

				vClients.push_back(Client);
			}
			MyFile.close();

		}
		return vClients;

	}

	static void _SaveCleintsDataToFile(vector <clsBankClient> vClients)
	{
		fstream MyFile;
		MyFile.open("MyClient.txt", ios::out);
		string DataLine;
		if (MyFile.is_open())
		{
			string Line;
			for (clsBankClient& Client : vClients)
			{
				if (Client._MarkForDelete == false)
				{
					DataLine = _ConvertClientObjectToLine(Client);
					MyFile << DataLine << endl;
				}
			}
			MyFile.close();
		}
	}

	void _Update()
	{
		vector <clsBankClient> _vClients;
		_vClients = _LoadClientsDataFromFile();
		for (clsBankClient& C : _vClients)
		{
			if (C.AccountNumber == AccountNumber)
			{
				C = *this;
				break;
			}
		}
		_SaveCleintsDataToFile(_vClients);
	}

	void _AddNew()
	{
		_AddDataLineToFile(_ConvertClientObjectToLine(*this));
	}

	void _AddDataLineToFile(string Line)
	{
		fstream MyFile;
		MyFile.open("MyClient.txt", ios::out | ios::app);
		if (MyFile.is_open())
		{
			MyFile << Line << endl;
			MyFile.close();
		}
	}

	static clsBankClient _GetEmptyClientObject()
	{
		return clsBankClient(enMode::EmptyMode, "", "", "", "", "", "", 0);
	}

public:
	clsBankClient(enMode Mode , string FirstName, string LastName, string Email, string Phone, string AccountNumber, string PinCode, float AccountBalance) : clsPerson(FirstName, LastName, Email, Phone)
	{
		_Mode = Mode;
		_AccountNumber = AccountNumber;
		_PinCode = PinCode;
		_AccountBalance = AccountBalance;
	}

	bool IsEmpty()
	{
		return (_Mode == enMode::EmptyMode);
	}

	void SetAccountNumber(string AccountNumber)
	{
		_AccountNumber = AccountNumber;
	}
	string GetAccountNumber()
	{
		return _AccountNumber;
	}
	__declspec(property(get = GetAccountNumber, put = SetAccountNumber)) string AccountNumber;

	void SetPinCode(string PinCode)
	{
		_PinCode = PinCode;
	}
	string GetPinCode()
	{
		return _PinCode;
	}
	__declspec(property(get = GetPinCode, put = SetPinCode)) string PinCode;
	
	void SetAccountBalance(float AccountBalance)
	{
		_AccountBalance = AccountBalance;
	}
	float GetAccountBalance()
	{
		return _AccountBalance;
	}
	__declspec(property(get = GetAccountBalance, put = SetAccountBalance)) float AccountBalance;

	static clsBankClient Find(string AccountNumber)
	{
		vector <clsBankClient> vClients;
		fstream MyFile;
		MyFile.open("MyClient.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsBankClient Client = _ConvertLineToClientObject(Line);
				if (Client.AccountNumber == AccountNumber)
				{
					MyFile.close();
					return Client;
				}
			}
			MyFile.close();
		}
		return _GetEmptyClientObject();
	}

	static clsBankClient Find(string AccountNumber, string PinCode)
	{
		vector <clsBankClient> vClients;
		fstream MyFile;
		MyFile.open("MyClient.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsBankClient Client = _ConvertLineToClientObject(Line);
				if (Client.AccountNumber == AccountNumber && Client.PinCode == PinCode)
				{
					MyFile.close();
					return Client;
				}
			}
			MyFile.close();
		}
		return _GetEmptyClientObject();
	}

	enum enSaveResults { svFaildEmptyObject = 0, svSucceeded = 1, svFaildAccountNumberExists = 2};

	enSaveResults Save()
	{

		switch (_Mode)
		{
		case enMode::EmptyMode:
		{
			return enSaveResults::svFaildEmptyObject;
		}
		case enMode::UpdateMode:
		{
			_Update();
			return enSaveResults::svSucceeded;
			break;
		}
		case enMode::AddNewMode:
			if (clsBankClient::IsClientExist(_AccountNumber))
				return enSaveResults::svFaildAccountNumberExists;
			else
			{
				_AddNew();
				return enSaveResults::svSucceeded;
			}
		}
	}

	bool Delete()
	{
		auto vClients = _LoadClientsDataFromFile();
		for (auto& Client : vClients)
		{
			if (Client.AccountNumber == _AccountNumber)
			{
				Client._MarkForDelete = true;
				break;
			}
		}
		_SaveCleintsDataToFile(vClients);
		*this = _GetEmptyClientObject();

		return true;
	}

	static clsBankClient GetAddNewClientObject(string AccountNumber)
	{
		return clsBankClient(enMode::AddNewMode, "", "", "", "", AccountNumber, "", 0);
	}

	static vector <clsBankClient> GetClientsList()
	{
		return _LoadClientsDataFromFile();
	}

	static float GetTotalBalances()
	{
		float Sum = 0;
		auto vClients =  GetClientsList();
		for (auto& Client : vClients)
		{
			Sum += Client.AccountBalance;
		}
		return Sum;
	}

	static bool IsClientExist(string AccountNumber)
	{
		clsBankClient Client1 = clsBankClient::Find(AccountNumber);
		return (!Client1.IsEmpty());
	}

	void Deposit(float Amount)
	{
		_AccountBalance += Amount;
		Save();
	}

	void Withdraw(float Amount)
	{
		_AccountBalance -= Amount;
		Save();
	}

	bool Transfer(float Amount, clsBankClient& DestinationClient)
	{
		if (Amount > DestinationClient.AccountBalance)
			return false;
		else
		{
			Withdraw(Amount);
			DestinationClient.Deposit(Amount);
			return true;
		}
	}
};

