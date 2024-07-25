#pragma once
#include <iostream>
#include <iomanip>

#include "cls_bank_client.h"
#include "cls_screen.h"
#include "cls_input_validation.h"
#include "cls_utility.h"

using namespace std;

class cls_transfer_list_screen : protected cls_screen
{
private:
    static void _print_transfer_log_list(cls_bank_client::st_transfer_log st_tranfer)
    {
        cout << setw(15) << left << ""
             << "| " << left << setw(25) << st_tranfer.date_time;
        cout << "| " << left << setw(20) << st_tranfer.source_account_number;
        cout << "| " << left << setw(20) << st_tranfer.destination_account_number;
        cout << "| " << left << setw(10) << st_tranfer.amount_transfered;
        cout << "| " << left << setw(20) << st_tranfer.source_account_balance;
        cout << "| " << left << setw(20) << st_tranfer.destination_account_balance;
        cout << "| " << left << setw(10) << st_tranfer.username;
    }

public:
    static void show_transfer_log_list_screen()
    {
        vector<cls_bank_client::st_transfer_log> v_tranfer_log = cls_bank_client::get_tranfert_log_list();

        string title = "\tTransfers log list";
        string sub_title = "\t\tTransfers log(s): (" + to_string(v_tranfer_log.size()) + ")";

        system("cls");
        _draw_screen(title, sub_title);
        cout << setw(15) << left << ""
             << "__________________________________________________________________________________________________________________________________________________\n";
        cout << setw(15) << left << ""
             << "__________________________________________________________________________________________________________________________________________________\n";
        cout << "\n\t\t\t\tTransfers log list \t\t\t\t\n";
        cout << setw(15) << left << ""
             << "_________________________________________________________________________________________________________________________________________________\n\n";
        cout << setw(15) << left << ""
             << "| " << left << setw(25) << "Time & Date";
        cout << "| " << left << setw(20) << "S.account number";
        cout << "| " << left << setw(20) << "D.account number";
        cout << "| " << left << setw(10) << "Amount";
        cout << "| " << left << setw(20) << "S.account balance";
        cout << "| " << left << setw(20) << "D.account balance";
        cout << "| " << left << setw(10) << "User";
        cout << "\n";
        cout << setw(15) << left << ""
             << "__________________________________________________________________________________________________________________________________________________\n\n";

        if (v_tranfer_log.size() == 0)
        {
            cout << "\n\t\t\tRegister login list is empty!\n";
        }
        else
        {
            for (cls_bank_client::st_transfer_log st_tranfer : v_tranfer_log)
            {
                _print_transfer_log_list(st_tranfer);
                cout << endl;
            }
        }
        cout << setw(15) << left << ""
             << "__________________________________________________________________________________________________________________________________________________\n";
    }
    
};
