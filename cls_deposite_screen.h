#pragma once
#include <iostream>
#include <iomanip>

#include "cls_bank_client.h"
#include "cls_screen.h"
#include "cls_input_validation.h"
#include "cls_person.h"

using namespace std;

class cls_deposite_screen : protected cls_screen
{
private:
    static void _print_client(cls_bank_client client)
    {
        cout << "\n\tClient card" << endl;
        cout << "----------------------" << endl;
        cout << "First name: " << client.get_first_name() << endl;
        cout << "Last name: " << client.get_last_name() << endl;
        cout << "Full name: " << client.get_full_name() << endl;
        cout << "Email: " << client.get_email() << endl;
        cout << "Phone: " << client.get_phone() << endl;
        cout << "Account number: " << client.get_account_number() << endl;
        cout << "PIN code: " << client.get_pin_code() << endl;
        cout << "Account Balance: " << client.get_account_balance() << endl;
        cout << "----------------------" << endl;
    }
    static string _read_account_number()
    {
        string account_number = "";
        cout << "\nPlease, enter account number: ";
        getline(cin >> ws, account_number);

        return account_number;
    }

public:
    static void show_deposite_screen()
    {
        _draw_screen("\tDeposite screen");
        cout << "\nPlease, enter account number: ";
        string account_number = _read_account_number();

        while (!cls_bank_client::is_client_exist(account_number))
        {
            cout << "\nAccount number not found, enter again: ";
            account_number = _read_account_number();
        }

        cls_bank_client client = cls_bank_client::find(account_number);
        _print_client(client);

        double amount = 0;
        cout << "\nHow much amount do you want to deposite: ";
        cin >> amount;

        char answer = 'y';
        cout << "\nAre you sure to perform the operation Y/N: ";
        cin >> answer;

        if (answer == 'y' || answer == 'Y')
        {
            client.deposite(amount);
            cout << "\nAmount deposited successfully\n";
            cout << "\nAccount balance: " << client.get_account_balance() << endl;
        }
        else
        {
            cout << "\nAmount deposite operation cancelled\n";
        }
    }
};
