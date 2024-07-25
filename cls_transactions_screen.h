#pragma once
#include <iostream>
#include <iomanip>

#include "cls_bank_client.h"
#include "cls_screen.h"
#include "cls_input_validation.h"
#include "cls_person.h"
#include "cls_main_screen.h"
#include "cls_deposite_screen.h"
#include "cls_withdraw_screen.h"
#include "cls_total_balance_screen.h"
#include "cls_transfer_screen.h"
#include "cls_transfer_list_screen.h"

using namespace std;

class cls_transactions_screen : protected cls_screen
{
private:
    enum en_transactions_options
    {
        deposite = 1,
        whithdraw = 2,
        total_balace = 3,
        transfer = 4,
        transfer_log_list = 5,
        main_menu = 6
    };
    static void _go_back_to_transaction_menu()
    {
        // system("cls");
        cout << setw(37) << left << "\n\t\tPress any key to go back to Transactions menu: ";
        system("pause");
        show_transaction_menu_screen();
    }
    static short _read_transactions_menu_option()
    {
        short choice;

        cout << setw(37) << left << "\n\t\t\t\t\tChoose what do you want to do [1] to [6]? ";
        choice = cls_ipunt_validation::read_number_between<short>(1, 6, "Enter a number between 1 to 6");

        return choice;
    }

    static void _show_deposite_screen()
    {
        // cout << "Deposite screen will be shown here";
        cls_deposite_screen::show_deposite_screen();
    }
    static void _show_withdraw_screen()
    {
        // cout << "Withdraw screen will be shown here";
        cls_withdraw_screen::show_withdraw_screen();
    }
    static void _show_total_balance_screen()
    {
        // cout << "Total balance screen will be shown here";
        cls_total_balance_screen::show_clients_total_balance();
    }
    static void _show_transfer_screen()
    {
        // cout << "\nTransfer screen will be shown here\n";
        cls_transfer_screen::show_transfer_screen();
    }
    static void _show_transfer_log_list_screen()
    {
        // cout << "\nTransfer screen list will be shown here";
        cls_transfer_list_screen::show_transfer_log_list_screen();
    }
    static void _perform_transactions_menu_option(en_transactions_options choice)
    {
        switch (choice)
        {
        case en_transactions_options::deposite:
            system("cls");
            _show_deposite_screen();
            _go_back_to_transaction_menu();
            break;
        case en_transactions_options::whithdraw:
            system("cls");
            _show_withdraw_screen();
            _go_back_to_transaction_menu();
            break;
        case en_transactions_options::total_balace:
            system("cls");
            _show_total_balance_screen();
            _go_back_to_transaction_menu();
            break;
        case en_transactions_options::transfer:
            system("cls");
            _show_transfer_screen();
            _go_back_to_transaction_menu();
            break;
        case en_transactions_options::transfer_log_list:
            system("cls");
            _show_transfer_log_list_screen();
            _go_back_to_transaction_menu();
            break;
        case en_transactions_options::main_menu:
            // do nothing here
            system("cls");
            break;
        }
    }

public:
    static void show_transaction_menu_screen()
    {
        if (!check_access_rights(cls_user::en_user_permissions::transactions_access))
        {
            return;
        }
        system("cls");
        _draw_screen("\tTransactions menu");
        cout << setw(37) << left << "\n\t\t\t\t\t============================================\n";
        cout << setw(37) << left << "\n\t\t\t\t\tTransactions screen\n";
        cout << setw(37) << left << "\n\t\t\t\t\t============================================\n";
        cout << setw(37) << left << "\n\t\t\t\t\t[1] Deposite\t\t\t\t\n";
        cout << setw(37) << left << "\n\t\t\t\t\t[2] Withdraw\t\t\t\t\n";
        cout << setw(37) << left << "\n\t\t\t\t\t[3] Total balance\t\t\t\t\n";
        cout << setw(37) << left << "\n\t\t\t\t\t[4] Transfer\t\t\t\t\n";
        cout << setw(37) << left << "\n\t\t\t\t\t[5] Transfer log list\t\t\t\t\n";
        cout << setw(37) << left << "\n\t\t\t\t\t[6] Main menu\t\t\t\t\n";
        cout << setw(37) << left << "\n\t\t\t\t\t============================================\n";

        _perform_transactions_menu_option((en_transactions_options)_read_transactions_menu_option());
    }
};
