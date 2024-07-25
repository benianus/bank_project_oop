#pragma once
#include <iostream>
#include <iomanip>

#include "cls_bank_client.h"
#include "cls_screen.h"
#include "cls_person.h"

using namespace std;

class cls_client_screen : protected cls_screen
{
private:
    static void _print_client_record_line(cls_bank_client client)
    {
        cout << setw(15) << left << "" << "| " << left << setw(15) << client.get_account_number();
        cout << "| " << left << setw(20) << client.get_full_name();
        cout << "| " << left << setw(12) << client.get_phone();
        cout << "| " << left << setw(20) << client.get_email();
        cout << "| " << left << setw(10) << client.get_pin_code();
        cout << "| " << left << setw(12) << client.get_account_balance();
    }

public:
    static void show_clients_list()
    {
        if (!check_access_rights(cls_user::en_user_permissions::show_client_list_access))
        {
            return;
        }
        
        vector<cls_bank_client> v_client = cls_bank_client::get_clients_list();
        string title = "\tClients list screen";
        string sub_title = "\t (" + to_string(v_client.size()) + ") Clients";

        _draw_screen(title, sub_title);
        cout << setw(15) << left << "" << "____________________________________________________________________________________________________\n";
        cout << setw(15) << left << "" << "____________________________________________________________________________________________________\n";
        cout << "\n\t\t\t\tClients list : (" << v_client.size() << ") \t\t\t\t\n";
        cout << setw(15) << left << "" << "___________________________________________________________________________________________________\n\n";
        cout << setw(15) << left << "" << "| " << left << setw(15) << "Account number";
        cout << "| " << left << setw(20) << "Client name";
        cout << "| " << left << setw(12) << "Phone";
        cout << "| " << left << setw(20) << "Email";
        cout << "| " << left << setw(10) << "PIN code";
        cout << "| " << left << setw(12) << "Balance";
        cout << "\n";
        cout << setw(15) << left << "" << "____________________________________________________________________________________________________\n";

        if (v_client.empty())
        {
            cout << "\n\t\t\tClient list empty, No available client!\n";
        }
        else
        {
            for (cls_bank_client client : v_client)
            {
                _print_client_record_line(client);
                cout << endl;
            }
        }
        cout << setw(15) << left << "" << "____________________________________________________________________________________________________\n";
    }
};