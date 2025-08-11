#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include "clsUser.h"
#include "clsScreen.h"
using namespace std;

class clsTransferLog : protected clsScreen
{
private:
	static void _PrintTransferLogScreen(clsUser::stTransfer Transfer)
	{
		cout << "\t| " << setw(23) << left << Transfer.Date;
		cout << "| " << setw(8) << left << Transfer.AccountNumber1;
		cout << "| " << setw(8) << left << Transfer.AccountNumber2;
		cout << "| " << setw(8) << left << Transfer.Amount;
		cout << "| " << setw(12) << left << Transfer.AccountBalance1;
		cout << "| " << setw(12) << left << Transfer.AccountBalance2;
		cout << "| " << setw(8) << left << Transfer.UserName;
		
	}
public:
	static void ShowTransferLog()
	{
		vector <clsUser::stTransfer> vTransfer = clsUser::GetTransferLogList();
		string Title = "\tTransfer Log List Screen";
		string SubTitle = "\t\t(" + to_string(vTransfer.size()) + ") Records(s).";
		_DrawScreenHeader(Title, SubTitle);
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "______________________________________________\n" << endl;
		cout << "\t| " << setw(23) << left << "Date/Time";
		cout << "| " << setw(8) << left << "s.Acct";
		cout << "| " << setw(8) << left << "d.Acct";
		cout << "| " << setw(8) << left << "Amount";
		cout << "| " << setw(12) << left << "s.Balance";
		cout << "| " << setw(12) << left << "d.Balance";
		cout << "| " << setw(8) << left << "User";
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "______________________________________________\n" << endl;
		if (vTransfer.size() == 0)
			cout << "\t\t\t\tNo Transfer Available In the System!";
		else
		{
			for (clsUser::stTransfer& Transfer : vTransfer)
			{
				_PrintTransferLogScreen(Transfer);
				cout << endl;
			}
		}
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "______________________________________________\n" << endl;
	}

};

