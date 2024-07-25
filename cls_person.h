#pragma once
#include <iostream>
#include <string>

#include "interface_comunication.h"

using namespace std;

class cls_person : public interface_comunication
{
private:
    string _first_name;
    string _last_name;
    string _email;
    string _phone;

public:
    // constructor

    cls_person(string first_name, string last_name, string email, string phone)
    {
        _first_name = first_name;
        _last_name = last_name;
        _email = email;
        _phone = phone;
    }

    // set properties
    void set_first_name(string first_name)
    {
        _first_name = first_name;
    }
    void set_last_name(string last_name)
    {
        _last_name = last_name;
    }
    void set_email(string email)
    {
        _email = email;
    }
    void set_phone(string phone)
    {
        _phone = phone;
    }

    // get functions

    string get_first_name()
    {
        return _first_name;
    }
    string get_last_name()
    {
        return _last_name;
    }
    string get_email()
    {
        return _email;
    }
    string get_phone()
    {
        return _phone;
    }

    string get_full_name()
    {
        return _first_name + " " + _last_name;
    }

    void print()
    {
        cout << "Info" << endl;
        cout << "----------------------" << endl;
        cout << "First name: " << _first_name << endl;
        cout << "Last name: " << _last_name << endl;
        cout << "Full name: " << get_full_name() << endl;
        cout << "Email: " << _email << endl;
        cout << "Phone: " << _phone << endl;
        cout << "----------------------" << endl;
    }

    void send_email(string text, string body)
    {
    }
    void send_sms(string text, string body)
    {
    }
    void send_fax(string text, string body)
    {
    }
};
