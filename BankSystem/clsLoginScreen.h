#pragma once
#include <iostream>
#include "clsMainScreen.h"
#include "clsScreen.h"
#include "clsUser.h"
#include "Global.h"
using namespace std;
class clsLoginScreen : protected clsScreen
{
private:
	static void _Login()
	{
		bool LoginFailed = false;
		string UserName, Password;
		short t = 3;
		do
		{
			if (LoginFailed)
			{
				cout << "\n\nInvalid UserName/Password!\n";
				cout << "You Have " << t << " Trials to login.\n\n";
			}
			cout << "Enter Username? ";
			cin >> UserName;

			cout << "Enter Password? ";
			cin >> Password;

			CurrentUser = clsUser::Find(UserName, Password);

			LoginFailed = CurrentUser.IsEmpty();
			if (LoginFailed)
			{
				t--;
			}
		} while (LoginFailed && t > 0);
		if (t == 0)
		{
			cout << "\nYou are Locked after 3 faild trails\n";
			Status = enLocked::eLocked;
			system("pause>0");
		}
		else
		{
			clsUser::_SaveUsersRegisterToFile(CurrentUser);
			clsMainScreen::ShowMainMenue();
		}
	}
public:
	static void ShowLoginScreen()
	{
		system("cls");
		_DrawScreenHeader("\t  Login Screen");
		_Login();
	}
};

