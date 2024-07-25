#pragma once
#include <iostream>
#include <iomanip>

#include "cls_bank_client.h"
#include "cls_screen.h"
#include "cls_input_validation.h"
#include "cls_person.h"

using namespace std;

class cls_update_client_screen : protected cls_screen
{
private:
    static void _read_client_info(cls_bank_client &client)
    {
        cout << "\nEnter first name: ";
        client.set_first_name(cls_ipunt_validation::read_string());

        cout << "\nEnter last name: ";
        client.set_last_name(cls_ipunt_validation::read_string());

        cout << "\nEnter email: ";
        client.set_email(cls_ipunt_validation::read_string());

        cout << "\nEnter phone: ";
        client.set_phone(cls_ipunt_validation::read_string());

        cout << "\nEnter PIN code: ";
        client.set_pin_code(cls_ipunt_validation::read_string());

        cout << "\nEnter account balance: ";
        client.set_account_balance(cls_ipunt_validation::read_number<float>());
    }
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

public:
    static void update_client()
    {
        if (!check_access_rights(cls_user::en_user_permissions::update_client_access))
        {
            return;
        }
        _draw_screen("\tUpdate client screen");
        string account_number = "";

        cout << "Please, enter account number: ";
        account_number = cls_ipunt_validation::read_string();

        while (!cls_bank_client::is_client_exist(account_number))
        {
            cout << "\nAccount number is not found, choose another one: ";
            account_number = cls_ipunt_validation::read_string();
        }

        cls_bank_client client = cls_bank_client::find(account_number);
        _print_client(client);

        char answer = 'y';
        cout << "Are you sure to Update this account Y/N: ";
        cin >> answer;

        if (answer == 'y' || answer == 'Y')
        {
            cout << "\nUpdate Client Info:";
            cout << "\n____________________\n";

            _read_client_info(client);

            cls_bank_client::en_save_results save_results;
            save_results = client.save();

            switch (save_results)
            {
            case cls_bank_client::en_save_results::save_success:
                cout << "Account Update successfully\n";
                _print_client(client);
                break;
            case cls_bank_client::en_save_results::save_failed_empty_object:
                cout << "Error, Empty account\n";
                break;
            }
        }
        
    }
};