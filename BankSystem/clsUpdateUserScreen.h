#pragma once
#include <iostream>
#include "clsUser.h"
#include "clsUtility.h"
#include "clsScreen.h"
#include "clsInputValidate.h"
using namespace std;

class clsUpdateUserScreen : protected clsScreen
{
private:

    static void _ReadUserInfo(clsUser& User)
    {
        cout << "\nYou Have The Right To Skip (Just Write \"Skip\"):\n";

        cout << "\n\nEnter FirstName: ";

        string String = clsInputValidate::ReadString();
        if (clsString::UpperAllString(String) != "SKIP")
            User.FirstName = String;

        cout << "\nEnter LastName: ";

        String = clsInputValidate::ReadString();
        if (clsString::UpperAllString(String) != "SKIP")
            User.LastName = String;

        cout << "\nEnter Email: ";

        String = clsInputValidate::ReadString();
        if (clsString::UpperAllString(String) != "SKIP")
            User.Email = String;

        cout << "\nEnter Phone: ";

        String = clsInputValidate::ReadString();
        if (clsString::UpperAllString(String) != "SKIP")
            User.Phone = String;

        cout << "\nEnter Password: ";

        String = clsInputValidate::ReadString();
        if (clsString::UpperAllString(String) != "SKIP")
            User.Password = String;

        cout << "\nPermission (y/n)? ";

        String = clsInputValidate::ReadString();
        if (clsUtility::AreYouSure())
            User.Permissions = _ReadPermissionsToSet();
    }

    static void _PrintUser(clsUser User)
    {
        cout << "\nUser Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << User.FirstName;
        cout << "\nLastName    : " << User.LastName;
        cout << "\nFull Name   : " << User.FullName();
        cout << "\nEmail       : " << User.Email;
        cout << "\nPhone       : " << User.Phone;
        cout << "\nUser Name   : " << User.UserName;
        cout << "\nPassword    : " << User.Password;
        cout << "\nPermissions : " << User.Permissions;
        cout << "\n___________________\n";

    }

    static int _ReadPermissionsToSet()
    {
        cout << "\nDo you want to give full access? y/n? ";
        if (clsUtility::AreYouSure())
            return -1;
        else
        {
            int Permissions = 0;
            cout << "\nDo you want to give access to : \n ";
            cout << "\nShow Client List? y/n? ";
            if (clsUtility::AreYouSure())
                Permissions += clsUser::enPermissions::pListClients;
            cout << "\nAdd New Client? y/n? ";
            if (clsUtility::AreYouSure())
                Permissions += clsUser::enPermissions::pAddNewClient;
            cout << "\nDelete Client? y/n? ";
            if (clsUtility::AreYouSure())
                Permissions += clsUser::enPermissions::pDeleteClient;
            cout << "\nUpdate Client? y/n? ";
            if (clsUtility::AreYouSure())
                Permissions += clsUser::enPermissions::pUpdateClients;
            cout << "\nFind Client? y/n? ";
            if (clsUtility::AreYouSure())
                Permissions += clsUser::enPermissions::pFindClient;
            cout << "\nTransactions? y/n? ";
            if (clsUtility::AreYouSure())
                Permissions += clsUser::enPermissions::pTranactions;
            cout << "\nManage Users? y/n? ";
            if (clsUtility::AreYouSure())
                Permissions += clsUser::enPermissions::pManageUsers;
            cout << "\nLogin Register? y/n? ";
            if (clsUtility::AreYouSure())
                Permissions += clsUser::enPermissions::pLoginRegister;
            if (Permissions == 255)
                return -1;
            return Permissions;
        }
    }

public:
    static void ShowUpdateUserScreen()
    {
        _DrawScreenHeader("\tUpdate User Screen");
        string UserName = "";

        cout << "\nPlease Enter User UserName: ";
        UserName = clsInputValidate::ReadString();

        while (!clsUser::IsUserExist(UserName))
        {
            cout << "\nAccount number is not found, choose another one: ";
            UserName = clsInputValidate::ReadString();
        }

        clsUser User1 = clsUser::Find(UserName);

        _PrintUser(User1);

        cout << "\nAre you sure you want to update this User y/n? ";

        if (clsUtility::AreYouSure())
        {
            cout << "\n\nUpdate User Info:";
            cout << "\n____________________\n";


            _ReadUserInfo(User1);

            clsUser::enSaveResults SaveResult;

            SaveResult = User1.Save();

            switch (SaveResult)
            {
            case  clsUser::enSaveResults::svSucceeded:
            {
                cout << "\nUser Updated Successfully :-)\n";

                _PrintUser(User1);
                break;
            }
            case clsUser::enSaveResults::svFaildEmptyObject:
            {
                cout << "\nError User was not saved because it's Empty";
                break;

            }

            }
        }
    }
};

