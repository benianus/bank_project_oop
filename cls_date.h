#pragma once
#pragma warning(disable : 4996)
#include <iostream>
#include <string>
#include <vector>
#include "cls_string.h"

using namespace std;

class cls_date
{
private:
    short _day = 0;
    short _month = 0;
    short _year = 0;
    short _hours = 0;
    short _minutes = 0;
    short _seconds = 0;

public:
    // Constructor
    cls_date()
    {
        time_t time_now = time(0); /* Get time now */

        tm *Now = localtime(&time_now);

        _day = Now->tm_mday;
        _month = Now->tm_mon + 1;
        _year = Now->tm_year + 1900;
        _hours = Now->tm_hour;
        _minutes = Now->tm_min;
        _seconds = Now->tm_sec;
    }
    cls_date(string date)
    {
        vector<string> v_date;
        v_date = cls_string::split(date, "/");

        _day = stod(v_date[0]);
        _month = stod(v_date[1]);
        _year = stod(v_date[2]);
    }
    cls_date(short day, short month, short year)
    {
        _day = day;
        _month = month;
        _year = year;
    }
    cls_date(short number_of_days, short year)
    {
        cls_date date = date_for_days_number(number_of_days, year);

        _day = date._day;
        _month = date._month;
        _year = date._year;
    }
    // set ad get properties
    void set_day(short day)
    {
        _day = day;
    }
    short get_day()
    {
        return _day;
    }

    void set_month(short month)
    {
        _month = month;
    }
    short get_month()
    {
        return _month;
    }

    void set_year(short year)
    {
        _year = year;
    }
    short get_year()
    {
        return _year;
    }

    void set_hours(short hours)
    {
        _hours = hours;
    }
    short get_hours()
    {
        return _hours;
    }

    void set_minutes(short minutes)
    {
        _minutes = minutes;
    }
    short get_minutes()
    {
        return _minutes;
    }

    void set_seconds(short seconds)
    {
        _seconds = seconds;
    }
    short get_seconds()

    {
        return _seconds;
    }

    /*  __declspec(proptery(get = get_day, put = set_day)) short day;
     __declspec(proptery(get = get_month, put = set_month)) short month;
     __declspec(proptery(get = get_yea, put = set_yea)) short year; */

    void print()
    {
        cout << date_to_string() << endl;
    }
    // Methods

    static cls_date get_system_date()
    {
        cls_date date;
        time_t time_now = time(0); /* Get time now */

        tm *Now = localtime(&time_now);

        date._day = Now->tm_mday;
        date._month = Now->tm_mon + 1;
        date._year = Now->tm_year + 1900;

        return date;
    }

    static string get_system_date_string()
    {
        
        time_t time_now = time(0); /* Get time now */

        tm *Now = localtime(&time_now);

        short day, month, year, hours, minutes, seconds;

        day = Now->tm_mday;
        month = Now->tm_mon + 1;
        year = Now->tm_year + 1900;
        hours = Now->tm_hour;
        minutes = Now->tm_min;
        seconds = Now->tm_sec;

        return (to_string(day) + "/" + to_string(month) + "/" + to_string(year) + " - " + to_string(hours) + ":" + to_string(minutes) + ":" + to_string(seconds));
    }
    
    static bool is_leap_year(int year)
    {
        return (year % 400 == 0 || (year % 100 != 0 && year % 4 == 0));
    }
    bool is_leap_year()
    {
        return is_leap_year(_year);
    }

    static short number_of_days_in_year(short year)
    {
        return (is_leap_year(year)) ? 366 : 365;
    }
    short number_of_days_in_year()
    {
        return number_of_days_in_year(_year);
    }

    static short number_of_hours_in_year(short year)
    {
        return number_of_days_in_year(year) * 24;
    }
    short number_of_hours_in_year()
    {
        return number_of_hours_in_year(_year);
    }

    static int number_of_minutes_in_year(short year)
    {
        return number_of_hours_in_year(year) * 60;
    }
    int number_of_minutes_in_year()
    {
        return number_of_minutes_in_year(_year);
    }

    static int number_of_seconds_in_year(short year)
    {
        return number_of_minutes_in_year(year) * 60;
    }
    int number_of_seconds_in_year()
    {
        return number_of_seconds_in_year(_year);
    }

    static short number_of_days_in_month(short year, short month)
    {

        int array_months_31[7] = {1, 3, 5, 7, 8, 10, 12};
        return ((month < 1 || month > 12) ? 0 : ((is_leap_year(year) && month == 2) ? 29 : ((!is_leap_year(year) && month == 2) ? 28 : 31)));
    }
    short number_of_days_in_month()
    {
        return number_of_days_in_month(_year, _month);
    }

    static short number_of_hours_in_month(short year, short month)
    {
        return number_of_days_in_month(year, month) * 24;
    }
    short number_of_hours_in_month()
    {
        return number_of_hours_in_month(_year, _month);
    }

    static int number_of_minutes_in_month(short year, short month)
    {
        return number_of_hours_in_month(year, month) * 60;
    }
    int number_of_minutes_in_month()
    {
        return number_of_minutes_in_month();
    }

    static int number_of_seconds_in_month(short year, short month)
    {
        return number_of_minutes_in_month(year, month) * 60;
    }
    int number_of_seconds_in_month()
    {
        return number_of_seconds_in_month(_year, _month);
    }

    static short day_order_in_calendar(short year, short month, short day)
    {
        int a = ((14 - month) / 12);
        int y = year - a;
        int m = month + (12 * a) - 2;

        int d = (day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;

        return d;
    }
    short day_order_in_calendar()
    {
        return day_order_in_calendar(_year, _month, _day);
    }

    static string day_name_of_week(short day_order)
    {
        string array_weekdays[7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
        for (short i = 0; i < 7; i++)
        {
            if (day_order == i)
            {
                return array_weekdays[i];
            }
        }
    }

    static string month_short_name(short month)
    {
        string month_list[12] = {"Jan", "Feb", "Mar",
                                 "Apr", "May", "Jun",
                                 "Jul", "Aug", "Sep",
                                 "Oct", "Nov", "Dec"};

        return month_list[month - 1];
    }
    string month_short_name()
    {
        return month_short_name(_month);
    }

    static void print_month_calendar(short year, short month)
    {
        int current_day = day_order_in_calendar(year, month, 1);
        int number_of_days = number_of_days_in_month(year, month);

        printf("-----------------%s----------------\n", month_short_name(month).c_str());

        printf("\n  Sat  Mon  Tue  Wed  Thu  Fri  Sun  \n");
        short i;
        for (i = 0; i < current_day; i++)
        {
            printf("     ");
        }
        for (short j = 1; j <= number_of_days; j++)
        {
            printf("%5d", j);
            if (++i == 7)
            {
                i = 0;
                printf("\n");
            }
        }

        printf("\n-----------------------------------\n");
    }
    void print_month_calendar()
    {
        print_month_calendar(_year, _month);
    }

    static void print_year_calendar(short year)
    {
        printf("\n-----------------------------------\n");
        printf("\n\tCalender - %d\t\t\n", year);
        printf("\n-----------------------------------\n");

        for (short i = 1; i <= 12; i++)
        {
            print_month_calendar(year, i);
            cout << endl;
        }
    }
    void print_year_calendar()
    {
        return print_year_calendar(_year);
    }

    static short number_of_days_from_beginning(short year, short month, short day)
    {
        short total_days = 0;

        for (short i = 1; i <= month - 1; i++)
        {
            total_days += number_of_days_in_month(year, i);
        }
        total_days += day;

        return total_days;
    }
    short number_of_days_from_beginning()
    {
        return number_of_days_from_beginning(_year, _month, _day);
    }

    static cls_date date_for_days_number(short total_days, short year)
    {
        cls_date date;

        date._year = year;
        date._month = 1;

        short days_remainder = total_days;
        short month_days = 0;

        while (true)
        {
            short month_days = number_of_days_in_month(year, date._month);
            if (days_remainder > month_days)
            {
                days_remainder -= month_days;
                date._month++;
            }
            else
            {
                date._day = days_remainder;
                break;
            }
        }

        return date;
    }

    static cls_date date_after_adding_days(short days_to_add, cls_date date)
    {
        short days_remainder = days_to_add + number_of_days_from_beginning(date._year, date._year, date._day);
        short month_days = 0;

        date._month = 1;

        while (true)
        {
            month_days = number_of_days_in_month(date._year, date._month);
            if (days_remainder > month_days)
            {
                days_remainder -= month_days;
                date._month++;
                if (date._month > 12)
                {
                    date._month = 1;
                    date._year++;
                }
            }
            else
            {
                date._day = days_remainder;
                break;
            }
        }
        return date;
    }

    static bool is_last_day_in_month(cls_date date)
    {
        return (date._day == number_of_days_in_month(date._year, date._month));
    }

    static bool is_last_month_in_year(short month)
    {
        return (month == 12);
    }
    bool is_last_month_in_year()
    {
        return is_last_month_in_year(_month);
    }

    static cls_date increase_date_by_one_day(cls_date date)
    {

        if (is_last_day_in_month(date))
        {

            if (is_last_month_in_year(date._month))
            {
                date._day = 1;
                date._month = 1;
                date._year++;
            }
            else
            {
                date._day = 1;
                date._month++;
            }
        }
        else
        {
            date._day++;
        }

        return date;
    }

    static void swap_date(cls_date &date_1, cls_date &date_2)
    {

        cls_date temp;

        temp._day = date_1._day;
        temp._month = date_1._month;
        temp._year = date_1._year;

        date_1._day = date_2._day;
        date_1._month = date_2._month;
        date_1._year = date_2._year;

        date_2._day = temp._day;
        date_2._month = temp._month;
        date_2._year = temp._year;
    }
    static int diffirence_in_days(cls_date date_1, cls_date date_2, bool include_last_day = false)
    {
        int days = 0;
        int swap_flag = 1;

        if (!is_date_before_date(date_1, date_2))
        {
            swap_date(date_1, date_2);
            swap_flag = -1;
        }

        while (is_date_before_date(date_1, date_2))
        {
            days++;
            date_1 = increase_date_by_one_day(date_1);
        }

        return include_last_day ? ++days * swap_flag : days * swap_flag;
    }

    static cls_date increase_date_by_x_days(cls_date date, short days)
    {
        for (short i = 0; i < days; i++)
        {
            date = increase_date_by_one_day(date);
        }
        return date;
    }

    static cls_date increase_date_by_one_week(cls_date &date)
    {
        for (short i = 0; i < 7; i++)
        {
            date = increase_date_by_one_day(date);
        }
        return date;
    }
    void increase_date_by_one_week()
    {
        increase_date_by_one_week(*this);
    }

    static cls_date increase_date_by_x_weeks(cls_date &date, short weeks)
    {
        for (short i = 0; i < weeks; i++)
        {
            date = increase_date_by_one_week(date);
        }
        return date;
    }
    void increase_date_by_x_weeks(short weaks)
    {
        increase_date_by_x_weeks(*this, weaks);
    }

    static cls_date increase_date_by_one_month(cls_date &date)
    {

        if (date._month == 12)
        {
            date._month = 1;
            date._year++;
        }
        else
        {
            date._month++;
        }

        short number_days_in_month = number_of_days_in_month(date._year, date._month);

        if (date._day > number_days_in_month)
        {
            date._day = number_days_in_month;
        }

        return date;
    }
    void increase_date_by_one_month()
    {
        increase_date_by_one_month(*this);
    }

    static cls_date increase_date_by_x_month(cls_date &date, short months)
    {
        for (short i = 0; i < months; i++)
        {
            date = increase_date_by_one_month(date);
        }
        return date;
    }
    void increase_date_by_x_month(short months)
    {
        increase_date_by_x_month(*this, months);
    }

    static cls_date increase_date_by_one_year(cls_date &date)
    {
        date._year++;
        return date;
    }
    void increase_date_by_one_year()
    {
        increase_date_by_one_year(*this);
    }

    static cls_date increase_date_by_x_year(cls_date &date, short years)
    {
        for (short i = 0; i < years; i++)
        {
            date = increase_date_by_one_year(date);
        }
        return date;
    }
    void increase_date_by_x_year(short years)
    {
        increase_date_by_x_year(*this, years);
    }

    static cls_date increase_date_by_x_year_faster(cls_date &date, short years)
    {

        date._year += years;

        return date;
    }
    void increase_date_by_x_year_faster(short years)
    {
        increase_date_by_x_year_faster(*this, years);
    }

    static cls_date increase_date_by_one_decade(cls_date &date)
    {

        date._year += 10;
        return date;
    }
    void increase_date_by_one_decade()
    {
        increase_date_by_one_decade(*this);
    }

    static cls_date increase_date_by_x_decades(cls_date &date, short decades)
    {
        for (short i = 0; i < decades * 10; i++)
        {
            date = increase_date_by_one_year(date);
        }
        return date;
    }
    void increase_date_by_x_decades(short decades)
    {
        increase_date_by_x_decades(*this, decades);
    }

    static cls_date increase_date_by_x_decades_faster(cls_date &date, short decades)
    {

        date._year += decades * 10;

        return date;
    }
    void increase_date_by_x_decades_faster(short decades)
    {
        increase_date_by_x_decades_faster(*this, decades);
    }

    static cls_date increase_date_by_one_century(cls_date &date)
    {

        date._year += 100;
        return date;
    }
    void increase_date_by_one_century()
    {
        increase_date_by_one_century(*this);
    }

    cls_date increase_date_by_one_milennium(cls_date &date)
    {

        date._year += 1000;

        return date;
    }
    void increase_date_by_one_milennium()
    {
        increase_date_by_one_milennium(*this);
    }

    static bool is_first_day_in_month(cls_date date)
    {
        return (date._day == 1);
    }
    bool is_first_day_in_month()
    {
        return is_first_day_in_month(*this);
    }

    static bool is_first_month_in_year(short month)
    {
        return (month == 1);
    }

    static cls_date decrease_date_by_one_day(cls_date &date)
    {

        if (is_first_day_in_month(date))
        {
            if (is_first_month_in_year(date._month))
            {
                date._month = 12;
                date._day = number_of_days_in_month(date._year, date._month);
                date._year--;
            }
            else
            {
                date._month--;
                date._day = number_of_days_in_month(date._year, date._month);
            }
        }
        else
        {
            date._day--;
        }

        return date;
    }
    void decrease_date_by_one_day()
    {
        decrease_date_by_one_day(*this);
    }

    static cls_date decrease_date_by_x_day(cls_date &date, short days)
    {
        for (size_t i = 0; i < days; i++)
        {
            date = decrease_date_by_one_day(date);
        }

        return date;
    }
    void decrease_date_by_x_day(short days)
    {
        decrease_date_by_x_day(*this, days);
    }

    static cls_date decrease_date_by_one_week(cls_date &date)
    {
        for (short i = 0; i < 7; i++)
        {
            date = decrease_date_by_one_day(date);
        }
        return date;
    }
    void decrease_date_by_one_week()
    {
        decrease_date_by_one_week(*this);
    }

    static cls_date decrease_date_by_x_week(cls_date &date, short weeks)
    {
        for (short i = 0; i < weeks; i++)
        {
            date = decrease_date_by_one_week(date);
        }
        return date;
    }
    void decrease_date_by_x_week(short weeks)
    {
        decrease_date_by_x_week(*this, weeks);
    }

    static cls_date decrease_date_by_one_month(cls_date &date)
    {
        if (is_first_month_in_year(date._month))
        {
            date._month = 12;
            date._year--;
        }
        else
        {
            date._month--;
        }

        short days_month_number = number_of_days_in_month(date._year, date._month);

        if (date._day > days_month_number)
        {
            date._day = days_month_number;
        }

        return date;
    }
    void decrease_date_by_one_month()
    {
        decrease_date_by_one_month(*this);
    }

    cls_date decrease_date_by_x_month(cls_date &date, short months)
    {
        for (short i = 0; i < months; i++)
        {
            date = decrease_date_by_one_month(date);
        }
        return date;
    }
    void decrease_date_by_x_month(short months)
    {
        decrease_date_by_x_month(*this, months);
    }

    static cls_date decrease_date_by_one_year(cls_date &date)
    {
        date._year--;
        return date;
    }
    void decrease_date_by_one_year()
    {
        decrease_date_by_one_year(*this);
    }

    static cls_date decrease_date_by_x_years(cls_date &date, short years)
    {
        for (short i = 0; i < years; i++)
        {
            date = decrease_date_by_one_year(date);
        }
        return date;
    }
    void decrease_date_by_x_years(short years)
    {
        decrease_date_by_x_years(*this, years);
    }

    static cls_date decrease_date_by_x_years_faster(cls_date &date, short years)
    {
        date._year -= years;
        return date;
    }
    void decrease_date_by_x_years_faster(short years)
    {
        decrease_date_by_x_years_faster(*this, years);
    }

    static cls_date decrease_date_by_one_decades(cls_date &date)
    {
        date._year -= 10;

        return date;
    }
    void decrease_date_by_one_decades()
    {
        decrease_date_by_one_decades(*this);
    }

    static cls_date decrease_date_by_x_decades(cls_date &date, short decades)
    {
        for (short i = 0; i < decades * 10; i++)
        {
            date = decrease_date_by_one_year(date);
        }
        return date;
    }
    void decrease_date_by_x_decades(short decades)
    {
        decrease_date_by_x_decades(*this, decades);
    }

    static cls_date decrease_date_by_x_decades_faster(cls_date &date, short decades)
    {
        date._year -= decades * 10;
        return date;
    }
    void decrease_date_by_x_decades_faster(short decades)
    {
        decrease_date_by_x_decades_faster(*this, decades);
    }

    cls_date decrease_date_by_one_century(cls_date date)
    {
        date._year -= 100;
        return date;
    }
    cls_date decrease_date_by_one_milinniume(cls_date date)
    {
        date._year -= 1000;
        return date;
    }

    static short day_order_in_calendar(cls_date date)
    {
        return day_order_in_calendar(date._year, date._month, date._day);
    }

    static bool is_end_of_week(cls_date date)
    {
        return (day_order_in_calendar(date) == 6);
    }
    bool is_end_of_week()
    {
        return is_end_of_week(*this);
    }

    static bool is_week_end(cls_date date)
    {
        short day_order = day_order_in_calendar(date);
        return (day_order == 5 || day_order == 6);
    }
    bool is_week_end()
    {
        return is_week_end(*this);
    }

    static bool is_business_day(cls_date date)
    {
        /* short day_order = day_order_in_calendar(date);
        return (day_order >= 0 || day_order <= 4); */

        return !is_week_end(date);
    }
    bool is_business_day()
    {
        return is_business_day(*this);
    }

    static short days_until_end_of_week(cls_date date)
    {
        return 6 - day_order_in_calendar(date);
    }
    short days_until_end_of_week()
    {
        return days_until_end_of_week(*this);
    }

    static short days_until_end_of_month(cls_date date)
    {
        cls_date date_2;

        date_2._day = number_of_days_in_month(date._year, date._month);
        date_2._month = date._month;
        date_2._year = date._year;

        return diffirence_in_days(date, date_2, true);
    }
    short days_until_end_of_month()
    {
        return days_until_end_of_month(*this);
    }

    static short days_until_end_of_year(cls_date date)
    {
        cls_date date2;

        date2._day = 31;
        date2._month = 12;
        date2._year = date._year;

        return diffirence_in_days(date, date2, true);
    }
    short days_until_end_of_year()
    {
        return days_until_end_of_year(*this);
    }

    static string day_short_name(short date)
    {
        string days_name[7] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
        return days_name[date];
    }

    static bool is_date_equal_date(cls_date date_01, cls_date date_02)
    {
        return ((date_01._year == date_02._year) ? ((date_01._month == date_02._month) ? ((date_01._day == date_02._day) ? true : false) : false) : false);
    }
    bool is_date_equal_date(cls_date date2)
    {
        return is_date_equal_date(*this, date2);
    }

    static bool is_date_before_date(cls_date date_01, cls_date date_02)
    {
        return (date_01._year < date_02._year) ? true : ((date_01._year == date_02._year) ? ((date_01._month < date_02._month) ? true : ((date_01._month == date_02._month) ? date_01._day < date_02._day : false)) : false);
    }
    bool is_date_before_date(cls_date date2)
    {
        return is_date_before_date(*this, date2);
    }

    static bool is_date_after_date(cls_date date01, cls_date date02)
    {
        return (!is_date_before_date(date01, date02) && !is_date_equal_date(date01, date02));
    }
    bool is_date_after_date(cls_date date2)
    {
        return is_date_after_date(*this, date2);
    }

    static short calculate_business_days(cls_date date1, cls_date date2)
    {
        short counter = 0;

        while (is_date_before_date(date1, date2))
        {
            if (is_business_day(date1))
            {
                counter++;
            }
            date1 = increase_date_by_one_day(date1);
        }

        return counter;
    }
    static short actual_vacation_days(cls_date date1, cls_date date2)
    {
        short counter = 0;

        while (is_date_before_date(date1, date2))
        {
            if (is_business_day(date1))
            {
                counter++;
            }
            date1 = increase_date_by_one_day(date1);
        }

        return counter;
    }

    cls_date calculate_return_date(cls_date date, short vacation_days_number)
    {
        short weekend_counter = 0;

        while (is_week_end(date))
        {
            date = increase_date_by_one_day(date);
        }

        for (short i = 0; i < vacation_days_number + weekend_counter; i++)
        {
            if (is_week_end(date))
            {
                weekend_counter++;
            }

            date = increase_date_by_one_day(date);
        }

        while (is_week_end(date))
        {
            date = increase_date_by_one_day(date);
        }

        return date;
    }

    enum en_compare_dates
    {
        before = -1,
        equal = 0,
        after = 1
    };
    static en_compare_dates f_compare_dates(cls_date date01, cls_date date02)
    {
        if (is_date_before_date(date01, date02))
        {
            return en_compare_dates::before;
        }
        else if (is_date_equal_date(date01, date02))
        {
            return en_compare_dates::equal;
        }
        else
        {
            return en_compare_dates::after;
        }
    }

    static bool is_valide_date(cls_date date)
    {
        // return ((date.month >= 1 && date.month <= 12) ? ((date.day <= number_of_days_in_month(date.year, date.month)) ? true : false) : false);
        if (date._day < 1 || date._day > 31)
        {
            return false;
        }

        if (date._month < 1 || date._month > 12)
        {
            return false;
        }

        if (date._month == 2)
        {
            if (is_leap_year(date._year))
            {
                if (date._day > 29)
                {
                    return false;
                }
            }
            else
            {
                if (date._day > 28)
                {
                    return false;
                }
            }
        }

        short days_in_month = number_of_days_in_month(date._year, date._month);

        if (date._day > days_in_month)
        {
            return false;
        }

        return true;
    }
    bool is_valide_date()
    {
        return is_valide_date(*this);
    }

    static cls_date string_to_date(string date)
    {
        vector<string> v_date = cls_string::split(date);
        cls_date date1;

        date1._day = stoi(v_date[0]);
        date1._month = stoi(v_date[1]);
        date1._year = stoi(v_date[2]);

        return date1;
    }
    static string date_to_string(cls_date date, string delimiter = "/")
    {
        return to_string(date._day) + "/" + to_string(date._month) + "/" + to_string(date._year);
    }

    string date_to_string()
    {
        return date_to_string(*this);
    }
};