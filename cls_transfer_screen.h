#pragma once
#include <iostream>
#include <iomanip>

#include "cls_bank_client.h"
#include "cls_screen.h"
#include "cls_input_validation.h"
#include "cls_utility.h"

using namespace std;

class cls_transfer_screen : protected cls_screen
{
private:
    static void _print_client(cls_bank_client client)
    {
        cout << "\n\tClient card" << endl;
        cout << "----------------------" << endl;
        cout << "Full name: " << client.get_full_name() << endl;
        cout << "Account number: " << client.get_account_number() << endl;
        cout << "Account Balance: " << client.get_account_balance() << endl;
        cout << "----------------------" << endl;
    }
    static string _read_account_number()
    {
        cout << "\nPlease, enter account number to transfer from: ";
        string account_number = cls_ipunt_validation::read_string();

        while (!cls_bank_client::is_client_exist(account_number))
        {
            cout << "\nAccount number not found, enter again: ";
            account_number = cls_ipunt_validation::read_string();
        }

        return account_number;
    }
    static float _read_amount(cls_bank_client source_client)
    {
        float amount;
        cout << "\nHow much amount do you want to transfer: ";
        amount = cls_ipunt_validation::read_number<float>();

        while (amount > source_client.get_account_balance())
        {
            cout << "\nYou can't Transfer, amount is greater then the account balance, enter again: ";
            amount = cls_ipunt_validation::read_number<float>();
        }

        return amount;
    }

public:
    static void show_transfer_screen()
    {
        _draw_screen("\tTransfer screen");
        
        cls_bank_client source_client = cls_bank_client::find(_read_account_number());
        _print_client(source_client);

        cls_bank_client destination_client = cls_bank_client::find(_read_account_number());
        _print_client(destination_client);

        float amount = _read_amount(source_client);

        char answer = 'y';
        cout << "\nAre you sure to perform the operation Y/N: ";
        cin >> answer;

        if (answer == 'y' || answer == 'Y')
        {

            if (source_client.transfer(amount, destination_client, current_user.get_user_name()))
            {
                cout << "\nTransfer done successfully\n";
            }
            else
            {
                cout << "\nTransfer failed\n";
            }
                        
            _print_client(source_client);
            _print_client(destination_client);
        }
        else
        {
            cout << "\nAmount transfer operation cancelled\n";
        }
    }
};
