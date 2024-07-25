#pragma once
#include <iostream>

#include "cls_bank_client.h"
#include "cls_screen.h"
#include "cls_input_validation.h"
#include "cls_person.h"

using namespace std;

class cls_delete_client_screen : protected cls_screen
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

public:
    static void delete_client()
    {
        if (!check_access_rights(cls_user::en_user_permissions::delete_client_access))
        {
            return;
        }
        _draw_screen("Delete client screen");
        string account_number = "";
        cout << "Please, enter account number: ";
        account_number = cls_ipunt_validation::read_string();
        while (!cls_bank_client::is_client_exist(account_number))
        {
            cout << "Client not exist, try another one\n";
            account_number = cls_ipunt_validation::read_string();
        }

        cls_bank_client client = cls_bank_client::find(account_number);
        _print_client(client);

        char answer = 'y';
        cout << "Are you sure to delete this account Y/N: ";
        cin >> answer;

        if (answer == 'y' || answer == 'Y')
        {
            if (client.Delete())
            {
                cout << "\nClient succssefully deleted\n";
                _print_client(client);
            }
            else
            {
                cout << "\nError, client was not deleted\n";
            }
        }
    }

};