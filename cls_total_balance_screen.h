#pragma once
#include <iostream>
#include <iomanip>

#include "cls_bank_client.h"
#include "cls_screen.h"
#include "cls_input_validation.h"
#include "cls_utility.h"

using namespace std;

class cls_total_balance_screen : protected cls_screen
{
private:
    static void _print_client_record_balance_line(cls_bank_client client)
    {
        cout << setw(20) << left << ""
             << "| " << left << setw(25) << client.get_account_number();
        cout << "| " << left << setw(40) << client.get_full_name();
        cout << "| " << left << setw(12) << client.get_account_balance();
    }

public:
    static void show_clients_total_balance()
    {
        vector<cls_bank_client> v_client = cls_bank_client::get_clients_list();
        string title = "\tTotal balance screen";
        string sub_title = "\t\tClient(s) (" + to_string(v_client.size()) + ") ";
        _draw_screen(title, sub_title);
        cout << setw(20) << left << "" << "_____________________________________________________________________________________________\n";
        cout << setw(20) << left << "\n\t\t\t\tClients list : (" << v_client.size() << ") \t\t\t\t\n";
        cout << setw(20) << left << "" << "____________________________________________________________________________________________\n\n";
        cout << setw(20) << left << "" << "| " << left << setw(25) << "Account number";
        cout << "| " << left << setw(40) << "Client name";
        cout << "| " << left << setw(12) << "Balance" << endl;
        cout << setw(20) << left << "" << "___________________________________________________________________________________________\n\n";

        double total_balance = cls_bank_client::get_clients_total_balance();

        if (v_client.empty())
        {
            cout << "\n\t\t\tClient list empty, No available client!\n";
        }
        else
        {
            for (cls_bank_client client : v_client)
            {
                _print_client_record_balance_line(client);
                cout << endl;
            }
        }
        cout << setw(20) << left << "" << "_____________________________________________________________________________________________\n";
        cout << "\n\t\t\t\ttotal balance : (" << total_balance << ") \t\t\t\t\n";
        cout << "\n\t\t\t(" << cls_utility::converting_number_to_letter(total_balance) << ") \t\t\t\t\n";
    }
};
