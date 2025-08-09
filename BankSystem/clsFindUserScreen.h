#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include "clsInputValidate.h"
using namespace std;

class clsFindUserScreen : protected clsScreen
{
private:

    static void _PrintPermissions(int Permission)
    {
        string arr[7] = { "Show Clients List", "Add New Client", "Delete Client", "Update Client Info", "Find Client", "Transactions", "Manage Users" };
        if (Permission == -1)
        {
            for (int i = 0; i < 7; i++)
                cout << "\t- " << arr[i] << "\n";
        }
        else
        {
            if (Permission & clsUser::enPermissions::pListClients)
                cout << "\t- " << arr[0] << "\n";
            if (Permission & clsUser::enPermissions::pAddNewClient)
                cout << "\t- " << arr[1] << "\n";
            if (Permission & clsUser::enPermissions::pDeleteClient)
                cout << "\t- " << arr[2] << "\n";
            if (Permission & clsUser::enPermissions::pUpdateClients)
                cout << "\t- " << arr[3] << "\n";
            if (Permission & clsUser::enPermissions::pFindClient)
                cout << "\t- " << arr[4] << "\n";
            if (Permission & clsUser::enPermissions::pTranactions)
                cout << "\t- " << arr[5] << "\n";
            if (Permission & clsUser::enPermissions::pManageUsers)
                cout << "\t- " << arr[6] << "\n";
        }
    }

    static void _PrintUser(clsUser User)
    {
        cout << "\nUser Card:";
        cout << "\n______________________________";
        cout << "\nFirstName   : " << User.FirstName;
        cout << "\nLastName    : " << User.LastName;
        cout << "\nFull Name   : " << User.FullName();
        cout << "\nEmail       : " << User.Email;
        cout << "\nPhone       : " << User.Phone;
        cout << "\nUserName    : " << User.UserName;
        cout << "\nPassword    : " << User.Password;
        cout << "\nPermissions : \n";
        _PrintPermissions(User.Permissions);
        cout << "______________________________\n";
    }

public:
    static void ShowFindUserScreen()
    {
        _DrawScreenHeader("\t  Find User Screen");

        string UserName;
        cout << "\nPlease Enter UserName: ";
        UserName = clsInputValidate::ReadString();
        while (!clsUser::IsUserExist(UserName))
        {
            cout << "\nUser is not found, choose another one: ";
            UserName = clsInputValidate::ReadString();
        }
        
        clsUser User1 = clsUser::Find(UserName);

        if (!User1.IsEmpty())
            cout << "\nUser Found :-)\n";
        else
            cout << "\nUser Was not Found :-(\n";

        _PrintUser(User1);
    }
};

