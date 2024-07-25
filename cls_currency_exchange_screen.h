#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

#include "cls_string.h"
#include "cls_screen.h"
#include "cls_input_validation.h"
#include "cls_main_screen.h"
#include "cls_find_currency_screen.h"
#include "cls_currecies_list_screen.h"
#include "cls_update_rate_screen.h"
#include "cls_currency_calculator_screen.h"

using namespace std;

class cls_currency_exchange_screen : protected cls_screen
{
private:
    enum en_currency_exchange_option
    {
        list_currencies = 1,
        find_currencies = 2,
        update_rate = 3,
        currency_calculator = 4,
        main_menu = 5
    };
    static void _go_back_to_currency_exchange_menu()
    {
        cout << setw(37) << left << "\n Press any key to go back to currency exchange menu: ";
        system("pause");
        show_currency_exchange_screen();
    }
    static short _read_currency_exchange_option()
    {
        short choice;

        cout << setw(37) << left << "\n\t\t\t\t\tChoose what do you want to do [1] to [5]? ";

        choice = cls_ipunt_validation::read_number_between<short>(1, 5, "Invalid number, enter number between 1 to 5");

        return choice;
    }
    static void _show_currencies_list_screen()
    {
        // cout << "\nScreen will be show here\n";
        cls_currecies_list::show_currencies_list();
    }
    static void _show_find_currencies_screen()
    {
        // cout << "\nScreen will be show here\n";
        cls_find_currency::show_find_currency_screen();
    }
    static void _show_update_rate_screen()
    {
        // cout << "\nScreen will be show here\n";
        cls_update_rate_screen::show_update_rate_screen();
    }
    static void _show_currency_calculator_screen()
    {
        // cout << "\nScreen will be show here\n";
        cls_currency_calculator_screen::show_currency_calculator_screen();
    }
    static void _perform_currency_exchange_option(en_currency_exchange_option choice)
    {
        switch (choice)
        {
        case en_currency_exchange_option::list_currencies:
            system("cls");
            _show_currencies_list_screen();
            _go_back_to_currency_exchange_menu();
            break;
        case en_currency_exchange_option::find_currencies:
            system("cls");
            _show_find_currencies_screen();
            _go_back_to_currency_exchange_menu();
            break;
        case en_currency_exchange_option::update_rate:
            system("cls");
            _show_update_rate_screen();
            _go_back_to_currency_exchange_menu();
            break;
        case en_currency_exchange_option::currency_calculator:
            system("cls");
            _show_currency_calculator_screen();
            _go_back_to_currency_exchange_menu();
            break;
        case en_currency_exchange_option::main_menu:
        {
            break;
        }
        }
    }

public:
    static void show_currency_exchange_screen()
    {
        if (!check_access_rights(cls_user::en_user_permissions::currency_exhcange_access))
        {
            return;
        }

        system("cls");
        _draw_screen("\tCurrency exchange menu");
        cout << setw(37) << left << "\n\t\t\t\t\t============================================\n";
        cout << setw(37) << left << "\n\t\t\t\t\tCurrency exchange menu\n";
        cout << setw(37) << left << "\n\t\t\t\t\t============================================\n";
        cout << setw(37) << left << "\n\t\t\t\t\t[1] List currencies\t\t\t\t\n";
        cout << setw(37) << left << "\n\t\t\t\t\t[2] Find currencies\t\t\t\t\n";
        cout << setw(37) << left << "\n\t\t\t\t\t[3] Update rate \t\t\t\t\n";
        cout << setw(37) << left << "\n\t\t\t\t\t[4] Currency calculator\t\t\t\t\n";
        cout << setw(37) << left << "\n\t\t\t\t\t[5] Main menu\t\t\t\t\n";
        cout << setw(37) << left << "\n\t\t\t\t\t============================================\n";
        _perform_currency_exchange_option((en_currency_exchange_option)_read_currency_exchange_option());
        }
};
