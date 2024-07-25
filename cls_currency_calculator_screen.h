#pragma once

#include <iostream>
#include <iomanip>

#include "cls_screen.h"
#include "cls_currency.h"
#include "cls_input_validation.h"

using namespace std;

class cls_currency_calculator_screen : protected cls_screen
{
private:
    static void _print_currency_card(cls_currency currency, string card_title = "Currency card")
    {
        cout << "\n_______________________\n";
        cout << card_title;
        cout << "\n_______________________\n";
        cout << "\nCountry: " << currency.get_country() << endl;
        cout << "Code: " << currency.get_currency_code() << endl;
        cout << "Name: " << currency.get_currency_name() << endl;
        cout << "Rate(1$): " << currency.get_rate() << " " << currency.get_currency_code();
        cout << "\n_______________________\n\n";
    }
    static cls_currency _get_currency_code(string message)
    {
        cout << message;
        string currency_code = cls_ipunt_validation::read_string();

        while (!cls_currency::is_currency_exist(currency_code))
        {
            cout << "\nCurrency not found,try again: ";
            currency_code = cls_ipunt_validation::read_string();
        }

        cls_currency currency = cls_currency::find_by_code(currency_code);
        return currency;
    }

    static float _read_amount()
    {
        cout << "\nEnter amount: ";
        float amount = 0;

        amount = cls_ipunt_validation::read_number<float>();
        return amount;
    }

    static void _print_exchange_resutls(cls_currency currency_from, cls_currency currency_to, float amount)
    {
        _print_currency_card(currency_from, "\nConvert from: ");
        float amount_in_usd = currency_from.convert_to_usd(amount);
        cout << amount << " " << currency_from.get_currency_code() << " : " << amount_in_usd << " USD" ;

        if (currency_to.get_currency_code() == "USD")
        {
            return;
        }
        _print_currency_card(currency_to, "\nConvert to: ");
        float amount_in_other_currency = currency_from.convert_to_other_currency(amount, currency_to);

        cout << amount << " " << currency_from.get_currency_code() << " : " << amount_in_other_currency << " " << currency_to.get_currency_code();
    }

public:
    static void show_currency_calculator_screen()
    {
        char _continue = 'y';

        while (_continue == 'y' || _continue == 'Y')
        {
            system("cls");
            _draw_screen("\tCurrency calculator");

            cls_currency currency_from = _get_currency_code("\nEnter currency1 code: ");
            cls_currency currency_to = _get_currency_code("\nEnter currency2 code: ");
            float amount = _read_amount();

            _print_exchange_resutls(currency_from, currency_to, amount);

            cout << "\nDo you want to performe another exchange Y/N: ";
            cin >> _continue;
        }
    }
};
