#pragma once
#include <iostream>
#include <iomanip>

#include "cls_screen.h"
#include "cls_currency.h"
#include "cls_input_validation.h"

using namespace std;

class cls_find_currency : protected cls_screen
{
private:
    static void _print_currency_card(cls_currency currency)
    {
        cout << "\n_______________________\n";
        cout << "\nCurrency card";
        cout << "\n_______________________\n";
        cout << "\nCountry: " << currency.get_country() << endl;
        cout << "Code: " << currency.get_currency_code() << endl;
        cout << "Name: " << currency.get_currency_name() << endl;
        cout << "Rate(1$): " << currency.get_rate() << " " << currency.get_currency_code();
        cout << "\n_______________________\n";
    }

    static void _show_results(cls_currency currency)
    {
        if (!currency.is_empty())
        {
            cout << "\nCurrency found.\n";
            _print_currency_card(currency);
        }
        else
        {
            cout << "\nCurrency not found\n";
        }
    }

public:
    static void show_find_currency_screen()
    {
        _draw_screen("\tFind currency");

        short search_type;
        cout << "Find by: [1] Code or [2] Country: ";
        search_type = cls_ipunt_validation::read_number_between<short>(1,2, "\nNumber is not within 1 and 2: ");

        if (search_type == 1)
        {
            string code;
            cout << "\nEnter currency code: ";
            code = cls_ipunt_validation::read_string();
            cls_currency currency = cls_currency::find_by_code(code);
            _show_results(currency);
        }
        else
        {
            string country;
            cout << "\nEnter country name: ";
            country = cls_ipunt_validation::read_string();
            cls_currency currency = cls_currency::find_by_country(country);
            _show_results(currency);
        }
    }
};
