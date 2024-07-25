#pragma once
#include <iostream>
#include <string>
#include <cctype>
#include <cmath>

#include "cls_date.h"
#include "cls_string.h"

// template <class t>

class cls_ipunt_validation
{
public:
    cls_ipunt_validation()
    {
    }

    template <typename t>
    static bool is_number_between(t from, t to, t number)
    {
        if (number >= from && number <= to)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    static bool is_date_between(cls_date date, cls_date from, cls_date to)
    {
        if ((cls_date::is_date_after_date(date, from) || cls_date::is_date_equal_date(date, from)) && (cls_date::is_date_before_date(date, to) || cls_date::is_date_equal_date(date, to)))
        {
            return true;
        }

        if ((cls_date::is_date_after_date(date, to) || cls_date::is_date_equal_date(date, to)) && (cls_date::is_date_before_date(date, from) || cls_date::is_date_equal_date(date, from)))
        {
            return true;
        }

        return false;
    }

    template <typename t>
    static t read_number(string error_message = "Invalid number, enter again: ")
    {
        t number = 0;
        while (!(cin >> number))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << error_message;
        }
        return number;
    }

    template <typename t>
    static t read_number_between(t from, t to, string error_message = "Number is not within the range, enter again: ")
    {
        t number = read_number<t>();

        while (!is_number_between(from, to, number))
        {
            cout << error_message;
            number = read_number<t>();
        }

        return number;
    }

    static bool is_valide_date(cls_date date)
    {
        return cls_date::is_valide_date(date);
    }

    static string read_string()
    {
        string st_name = "";
        getline(cin >> ws, st_name);

        return st_name;
    }
};
