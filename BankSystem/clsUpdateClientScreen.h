#pragma once
#include <iostream>
#include "clsScreen.h";
#include "clsInputValidate.h";
#include "clsBankClient.h";
#include "clsString.h";
#include "clsUtility.h";
using namespace std;

class clsUpdateClientScreen : protected clsScreen
{
private:
    static void _PrintClient(clsBankClient Client)
    {
        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << Client.FirstName;
        cout << "\nLastName    : " << Client.LastName;
        cout << "\nFull Name   : " << Client.FullName();
        cout << "\nEmail       : " << Client.Email;
        cout << "\nPhone       : " << Client.Phone;
        cout << "\nAcc. Number : " << Client.AccountNumber;
        cout << "\nPassword    : " << Client.PinCode;
        cout << "\nBalance     : " << Client.AccountBalance;
        cout << "\n___________________\n";

    }

    static void ReadClientInfo(clsBankClient& Client)
    {
        cout << "\nYou Have The Right To Skip (Just Write \"Skip\"):\n";

        cout << "\n\nEnter FirstName: ";

        string String = clsInputValidate::ReadString();
        if (clsString::UpperAllString(String) != "SKIP")
            Client.FirstName = String;

        cout << "\nEnter LastName: ";

        String = clsInputValidate::ReadString();
        if (clsString::UpperAllString(String) != "SKIP")
            Client.LastName = String;

        cout << "\nEnter Email: ";

        String = clsInputValidate::ReadString();
        if (clsString::UpperAllString(String) != "SKIP")
            Client.Email = String;

        cout << "\nEnter Phone: ";

        String = clsInputValidate::ReadString();
        if (clsString::UpperAllString(String) != "SKIP")
            Client.Phone = String;

        cout << "\nEnter PinCode: ";

        String = clsInputValidate::ReadString();
        if (clsString::UpperAllString(String) != "SKIP")
            Client.PinCode = String;

        cout << "\nEnter Account Balance: ";

        String = clsInputValidate::ReadString();
        if (clsString::UpperAllString(String) != "SKIP")
            Client.AccountBalance = stof(String);
    }

public:
    static void ShowUpdateClientScreen()
    {
        if (!CheckAccessRights(clsUser::enPermissions::pUpdateClients))
        {
            return;// this will exit the function and it will not continue
        }
        _DrawScreenHeader("\tUpdate Client Screen");

        string AccountNumber = "";

        cout << "\nPlease Enter client Account Number: ";
        AccountNumber = clsInputValidate::ReadString();

        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nAccount number is not found, choose another one: ";
            AccountNumber = clsInputValidate::ReadString();
        }

        clsBankClient Client1 = clsBankClient::Find(AccountNumber);

        _PrintClient(Client1);

        cout << "\nAre you sure you want to update this client y/n? ";

        if (clsUtility::AreYouSure())
        {

            cout << "\n\nUpdate Client Info:";
            cout << "\n____________________\n";


            ReadClientInfo(Client1);

            clsBankClient::enSaveResults SaveResult;

            SaveResult = Client1.Save();

            switch (SaveResult)
            {
            case  clsBankClient::enSaveResults::svSucceeded:
            {
                cout << "\nAccount Updated Successfully :-)\n";

                _PrintClient(Client1);
                break;
            }
            case clsBankClient::enSaveResults::svFaildEmptyObject:
            {
                cout << "\nError account was not saved because it's Empty";
                break;

            }

            }

        }
    }
};

