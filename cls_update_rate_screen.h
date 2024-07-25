#pragma once

#include <iostream>
#include <iomanip>

#include "cls_screen.h"
#include "cls_currency.h"
#include "cls_input_validation.h"

using namespace std;

class cls_update_rate_screen : protected cls_screen
{
private:
    static float _read_new_rate()
    {
        float new_rate = 0;
        cout << "\nEnter new rate: ";
        new_rate = cls_ipunt_validation::read_number<float>("Invalid number, try again");

        return new_rate;
    }
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

public:
    static void show_update_rate_screen()
    {
        _draw_screen("\tUpdate rate screen");

        string currency_code = "";
        cout << "\nPlease enter currency code: ";
        currency_code = cls_ipunt_validation::read_string();

        while (!cls_currency::is_currency_exist(currency_code))
        {
            cout << "\nCurrency not found,try again: ";
            currency_code = cls_ipunt_validation::read_string();
        }
        
        cls_currency currency = cls_currency::find_by_code(currency_code);
        _print_currency_card(currency);

        char answer = 'y';
        cout << "\nAre you sure to update the rate Y/N: ";
        cin >> answer;

        if (toupper(answer) == 'Y')
        {
            cout << "\nUpdate currency rate:";
            cout << "\n_____________________\n";

            currency.update_rate(_read_new_rate());
            cout << "\nCurrency rate updated successfully\n";
            _print_currency_card(currency);
        }
        else
        {
            cout << "\nOperation cancelled\n";
        }
    }
};
