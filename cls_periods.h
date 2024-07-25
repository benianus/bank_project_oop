#pragma once
#include <iostream>

#include "cls_date.h"

class cls_periodes
{

public:
    cls_date start_date;
    cls_date end_date;

    cls_periodes(cls_date start_date, cls_date end_date)
    {
        this->start_date = start_date;
        this->end_date = end_date;
    }
    static bool is_overlap_date(cls_periodes periode1, cls_periodes periode2)
    {
        if ((cls_date::f_compare_dates(periode2.end_date, periode1.start_date) == cls_date::en_compare_dates::before) || (cls_date::f_compare_dates(periode2.start_date, periode1.end_date) == cls_date::en_compare_dates::after))
        {
            return false;
        }
        else
        {
            return true;
        }
    }
    short calculate_periode_date(cls_periodes periode, bool include_last_day = false)
    {
        return cls_date::diffirence_in_days(periode.start_date, periode.end_date, include_last_day);
    }
    bool is_date_within_periode(cls_periodes periode, cls_date date)
    {
        return !(cls_date::f_compare_dates(date, periode.start_date) == cls_date::en_compare_dates::before || cls_date::f_compare_dates(date, periode.end_date) == cls_date::en_compare_dates::after);
        // return (f_compare_dates(periode.start_date, date) == en_compare_dates::before && f_compare_dates(periode.end_date, date) == en_compare_dates::after);
    }

    short periode_length(cls_periodes periode, bool include_last_day = false)
    {
        return cls_date::diffirence_in_days(periode.start_date, periode.end_date, include_last_day);
    }
    int calculate_overlped_days(cls_periodes periode1, cls_periodes periode2)
    {
        int periode1_length = periode_length(periode1, true);
        int periode2_length = periode_length(periode2, true);
        int overlaped_days = 0;

        if (!is_overlap_date(periode1, periode2))
        {
            return 0;
        }

        if (periode1_length < periode2_length)
        {
            while (cls_date::is_date_before_date(periode1.start_date, periode1.end_date))
            {
                if (is_date_within_periode(periode2, periode1.start_date))
                {
                    overlaped_days++;
                }
                periode1.start_date = cls_date::increase_date_by_one_day(periode1.start_date);
            }
        }
        else
        {
            while (cls_date::is_date_before_date(periode2.start_date, periode2.end_date))
            {
                periode2.start_date = cls_date::increase_date_by_one_day(periode2.start_date);
                if (is_date_within_periode(periode1, periode2.start_date))
                {
                    overlaped_days++;
                }
            }
        }
        return overlaped_days;
    }

    void print()
    {
        cout << "Start date: ";
        start_date.print();
        
        cout << "End date: ";
        end_date.print();
    }
};
