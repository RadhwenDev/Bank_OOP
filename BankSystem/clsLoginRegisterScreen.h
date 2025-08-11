#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include <iomanip>
using namespace std;


class clsLoginRegisterScreen : protected clsScreen
{
private:
	static void _PrintUserLoginRegister(clsUser::stUser User)
	{
		cout << "\t| " << setw(35) << left << User.Date;
		cout << "| " << setw(25) << left << User.UserName;
		cout << "| " << setw(25) << left << User.Password;
		cout << "| " << setw(25) << left << User.Permissions;
	}

public:
	static void ShowLoginRegister()
	{
		if (!CheckAccessRights(clsUser::pLoginRegister))
			return;
		vector <clsUser::stUser> vUsers = clsUser::GetUsersLoginList();
		string SubTitle = "\t\t(" + to_string(vUsers.size()) + ") Record(s).";
		_DrawScreenHeader("\t Login Register List Screen", SubTitle);
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "______________________________________________\n" << endl;
		cout << "\t| " << setw(35) << left << "Date/Time";
		cout << "| " << setw(25) << left << "UserName";
		cout << "| " << setw(25) << left << "Password";
		cout << "| " << setw(25) << left << "Permissions";
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "______________________________________________\n" << endl;
		if (vUsers.size() == 0)
			cout << "\t\t\t\tNo Users Available In the System!";
		else

			for (clsUser::stUser User : vUsers)
			{

				_PrintUserLoginRegister(User);
				cout << endl;
			}

		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "______________________________________________\n" << endl;
	}
};

