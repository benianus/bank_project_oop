#pragma once
#include <iostream>
#include "cls_person.h"

using namespace std;


class cls_employee : public cls_person
{
private:
    string _title;
    double _salary;
    string _department;

public:
    void set_title(string title)
    {
        _title = title;
    }
    string get_title()
    {
        return _title;
    }

    void set_salary(double salary)
    {
        _salary = salary;
    }
    double get_salary()
    {
        return _salary;
    }

    void set_department(string department)
    {
        _department = department;
    }
    string get_department()
    {
        return _department;
    }
};

