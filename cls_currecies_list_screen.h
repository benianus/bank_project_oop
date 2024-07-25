#pragma once
#include <iostream>
#include <iomanip>

#include "cls_screen.h"
#include "cls_currency.h"

using namespace std;

class cls_currecies_list : protected cls_screen
{
private:
    static void _print_currency_record_line(cls_currency currency)
    {
        cout << setw(15) << left << ""
             << "| " << left << setw(40) << currency.get_country();
        cout << "| " << left << setw(20) << currency.get_currency_code();
        cout << "| " << left << setw(40) << currency.get_currency_name();
        cout << "| " << left << setw(20) << currency.get_rate();
    }

public:
    static void show_currencies_list()
    {
        vector<cls_currency> v_currency = cls_currency::get_currencies_list();
        string title = "\tCurrencies list screen";
        string sub_title = "\t (" + to_string(v_currency.size()) + ") Currencies";

        _draw_screen(title, sub_title);
        cout << setw(15) << left << ""
             << "___________________________________________________________________________________________________________________________\n";
        cout << setw(15) << left << ""
             << "___________________________________________________________________________________________________________________________\n";
        cout << "\n\t\t\t\tCurrencies list : (" << v_currency.size() << ") \t\t\t\t\n";
        cout << setw(15) << left << ""
             << "__________________________________________________________________________________________________________________________\n\n";
        cout << setw(15) << left << ""
             << "| " << left << setw(40) << "Country";
        cout << "| " << left << setw(20) << "Code";
        cout << "| " << left << setw(40) << "Name";
        cout << "| " << left << setw(20) << "Rate(1$)";
        cout << "\n";
        cout << setw(15) << left << ""
             << "___________________________________________________________________________________________________________________________\n\n";

        if (v_currency.empty())
        {
            cout << "\n\t\t\tCurrencies list empty, No available Currencies!\n";
        }
        else
        {
            for (cls_currency currency : v_currency)
            {
                _print_currency_record_line(currency);
                cout << endl;
            }
        }
        cout << setw(15) << left << ""
             << "___________________________________________________________________________________________________________________________\n";
    }
};
