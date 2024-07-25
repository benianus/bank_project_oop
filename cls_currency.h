#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

#include "cls_string.h"

using namespace std;

class cls_currency
{
private:
    enum en_currency_mode
    {
        empty_mode = 0,
        update_mode = 1
    };

    en_currency_mode _mode;
    string _country;
    string _currency_code;
    string _currency_name;
    float _rate;

    static cls_currency _get_currency_empty_object()
    {
        return cls_currency(en_currency_mode::empty_mode, "", "", "", 0);
    }
    static cls_currency _convert_line_to_currency_object(string line, string seperatr = "#//#")
    {
        vector<string> v_currency = cls_string::split(line, seperatr);

        return cls_currency(en_currency_mode::update_mode, v_currency[0], v_currency[1], v_currency[2], stof(v_currency[3]));
    }
    static vector<cls_currency> _load_currency_data_from_file()
    {
        vector<cls_currency> v_currency;
        fstream file_name;

        file_name.open("Currencies.txt", ios::in);
        if (file_name.is_open())
        {
            string line;
            while (getline(file_name, line))
            {
                cls_currency currency = _convert_line_to_currency_object(line);
                v_currency.push_back(currency);
            }
            file_name.close();
        }
        return v_currency;
    }
    static string _convert_currency_to_line(cls_currency currency, string seperator = "#//#")
    {
        string currency_info_line = "";

        currency_info_line += currency.get_country() + seperator;
        currency_info_line += currency.get_currency_code() + seperator;
        currency_info_line += currency.get_currency_name() + seperator;
        currency_info_line += to_string(currency.get_rate());

        return currency_info_line;
    }
    static void _save_currency_data_to_file(vector<cls_currency> v_currency)
    {
        fstream file_name;

        file_name.open("Currencies.txt", ios::out);

        if (file_name.is_open())
        {
            string line;
            for (cls_currency c : v_currency)
            {
                line = _convert_currency_to_line(c);
                file_name << line << endl;
            }
            file_name.close();
        }
    }
    void _update()
    {
        vector<cls_currency> v_currency = _load_currency_data_from_file();

        for (cls_currency &c : v_currency)
        {
            if (c.get_currency_code() == get_currency_code())
            {
                c = *this;
                break;
            }
        }

        _save_currency_data_to_file(v_currency);
    }

public:
    cls_currency(en_currency_mode mode, string country, string currency_code, string currency_name, float rate)
    {
        _mode = mode;
        _country = country;
        _currency_code = currency_code;
        _currency_name = currency_name;
        _rate = rate;
    }

    bool is_empty()
    {
        return (_mode == en_currency_mode::empty_mode);
    }
    string get_country()
    {
        return _country;
    }
    string get_currency_code()
    {
        return _currency_code;
    }
    string get_currency_name()
    {
        return _currency_name;
    }
    float get_rate()
    {
        return _rate;
    }
    
    void update_rate(float new_rate)
    {
        _rate = new_rate;
        _update();
    }

    static cls_currency find_by_code(string code)
    {
        code = cls_string::all_capital_letters(code);

        fstream file_name;

        file_name.open("Currencies.txt", ios::in);

        if (file_name.is_open())
        {
            string line;
            while (getline(file_name, line))
            {
                cls_currency currency = _convert_line_to_currency_object(line);
                if (cls_string::all_capital_letters(currency.get_currency_code()) == code)
                {
                    return currency;
                    break;
                }
            }
            file_name.close();
        }

        return _get_currency_empty_object();
    }

    static cls_currency find_by_country(string country)
    {
        country = cls_string::all_capital_letters(country);

        fstream file_name;

        file_name.open("Currencies.txt", ios::in);

        if (file_name.is_open())
        {
            string line;
            while (getline(file_name, line))
            {
                cls_currency currency = _convert_line_to_currency_object(line);
                if (cls_string::all_capital_letters(currency.get_country()) == country)
                {
                    return currency;
                    break;
                }
            }
            file_name.close();
        }

        return _get_currency_empty_object();
    }

    static bool is_currency_exist(string code)
    {
        cls_currency currency = cls_currency::find_by_code(code);

        return (!currency.is_empty());
    }

    static vector<cls_currency> get_currencies_list()
    {
        return _load_currency_data_from_file();
    }
    
    float convert_to_usd(float amount)
    {
        return (float)(amount / get_rate());
    }
    float convert_to_other_currency(float amount, cls_currency currency2)
    {
        float amount_in_usd = convert_to_usd(amount);

        if (currency2.get_currency_code() == "USD")
        {
            return amount_in_usd;
        }
        
        return (float)(amount_in_usd * currency2.get_rate());
    }
};
