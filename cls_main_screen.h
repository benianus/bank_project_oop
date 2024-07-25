#pragma once
#include <iostream>
#include <string>
#include <iomanip>

#include "cls_screen.h"
#include "cls_person.h"
#include "cls_input_validation.h"
#include "cls_client_list_screen.h"
#include "cls_add_new_client_screen.h"
#include "cls_delete_client_screen.h"
#include "cls_update_client_screen.h"
#include "cls_find_client_screen.h"
#include "cls_transactions_screen.h"
#include "cls_manage_users_screen.h"
#include "cls_login_screen.h"
#include "global.h"
#include "cls_login_registerd_screen.h"
#include "cls_currency_exchange_screen.h"

using namespace std;

class cls_main_screen : protected cls_screen
{
private:
    enum en_main_menu_options
    {
        show_client_list = 1,
        add_new_clients = 2,
        delete_clients = 3,
        update_clients = 4,
        find_clients = 5,
        transactions = 6,
        manage_users = 7,
        login_registered = 8,
        currency_exchange = 9,
        exit = 10
    };
    static void _go_back_main_menu()
    {
        // system("cls");
        cout << setw(37) << left << "\n\t\tPress any key to go back to main menu: ";
        system("pause");
        show_main_menu_screen();
    }
    static short _read_main_menu_option()
    {
        short choice;

        cout << setw(37) << left << "\n\t\t\t\t\tChoose what do you want to do [1] to [10]? ";
        choice = cls_ipunt_validation::read_number_between<short>(1, 10, "Enter a number between 1 to 10");

        return choice;
    }
    static void _show_all_clinets_screen()
    {
        // cout << "\tClients list screen will be shown here\n";
        cls_client_screen::show_clients_list();
    }
    static void _show_add_new_clients_screen()
    {
        // cout << "\tAdd new clients screen will be show here";
        cls_add_new_client_screen::add_new_client();
    }
    static void _show_delete_clients_screen()
    {
        // cout << "\tDelete clients screen will be shown here";
        cls_delete_client_screen::delete_client();
    }
    static void _show_update_clients_screen()
    {
        // cout << "\tUpdate clients screen will be shown here";
        cls_update_client_screen::update_client();
    }
    static void _show_find_clients_screen()
    {
        // cout << "\tFind clients screen will be shown here";
        cls_find_client_screen::find_client();
    }
    static void _show_transactions_screen()
    {
        // cout << "\tTransactions screen will be shown here";
        cls_transactions_screen::show_transaction_menu_screen();
    }
    static void _show_manage_users_screen()
    {
        // cout << "\tManage users will be shown here";
        cls_manage_users_screen::show_manage_users_screen();
    }
    static void _show_login_register_screen()
    {
        //login registered screen will be shown here
        cls_login_registerd_screen::show_login_register_screen();
    }
    static void _show_currency_exchange_screen()
    {
        cls_currency_exchange_screen::show_currency_exchange_screen();
    }
    static void _logout()
    {
        // cout << "\tLogout screen will be shown here";
        current_user = cls_user::find("", "");
    }
    static void _perform_main_menu_option(en_main_menu_options choice)
    {
        switch (choice)
        {
        case en_main_menu_options::show_client_list:
            system("cls");
            _show_all_clinets_screen();
            _go_back_main_menu();
        case en_main_menu_options::add_new_clients:
            system("cls");
            _show_add_new_clients_screen();
            _go_back_main_menu();
            break;
        case en_main_menu_options::delete_clients:
            system("cls");
            _show_delete_clients_screen();
            _go_back_main_menu();
            break;
        case en_main_menu_options::update_clients:
            system("cls");
            _show_update_clients_screen();
            _go_back_main_menu();
            break;
        case en_main_menu_options::find_clients:
            system("cls");
            _show_find_clients_screen();
            _go_back_main_menu();
            break;
        case en_main_menu_options::transactions:
            system("cls");
            _show_transactions_screen();
            _go_back_main_menu();
            break;
        case en_main_menu_options::manage_users:
            system("cls");
            _show_manage_users_screen();
            _go_back_main_menu();
            break;
        case en_main_menu_options::login_registered:
            system("cls");
            _show_login_register_screen();
            _go_back_main_menu();
            break;
        case en_main_menu_options::currency_exchange:
            system("cls");
            _show_currency_exchange_screen();
            _go_back_main_menu();
            break;
        case en_main_menu_options::exit:
            system("cls");
            _logout();
            break;
        }
    }
public:
    static void show_main_menu_screen()
    {
        system("cls");
        _draw_screen("\tMain menu");
        cout << setw(37) << left << "\n\t\t\t\t\t============================================\n";
        cout << setw(37) << left << "\n\t\t\t\t\tMain menu\n";
        cout << setw(37) << left << "\n\t\t\t\t\t============================================\n";
        cout << setw(37) << left << "\n\t\t\t\t\t[1] Show clients list\t\t\t\t\n";
        cout << setw(37) << left << "\n\t\t\t\t\t[2] Add new clients\t\t\t\t\n";
        cout << setw(37) << left << "\n\t\t\t\t\t[3] Delete clients \t\t\t\t\n";
        cout << setw(37) << left << "\n\t\t\t\t\t[4] Update clients info\t\t\t\t\n";
        cout << setw(37) << left << "\n\t\t\t\t\t[5] Find clients\t\t\t\t\n";
        cout << setw(37) << left << "\n\t\t\t\t\t[6] Transactions\t\t\t\t\n";
        cout << setw(37) << left << "\n\t\t\t\t\t[7] Manage users\t\t\t\t\n";
        cout << setw(37) << left << "\n\t\t\t\t\t[8] Login Registered\t\t\t\t\n";
        cout << setw(37) << left << "\n\t\t\t\t\t[9] Currency exhchange\t\t\t\t\n";
        cout << setw(37) << left << "\n\t\t\t\t\t[10] Logout\t\t\t\t\n";
        cout << setw(37) << left << "\n\t\t\t\t\t============================================\n";

        _perform_main_menu_option((en_main_menu_options)_read_main_menu_option());
    }
};