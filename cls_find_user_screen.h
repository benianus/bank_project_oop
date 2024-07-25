#pragma once

#include <iostream>
#include <iomanip>

#include "cls_screen.h"
#include "cls_user.h"
#include "cls_person.h"
#include "cls_input_validation.h"

using namespace std;

class cls_find_user_screen : protected cls_screen
{
private:
    static void _print_user(cls_user user)
    {
        cout << "\n\tUser card" << endl;
        cout << "----------------------" << endl;
        cout << "First name: " << user.get_first_name() << endl;
        cout << "Last name: " << user.get_last_name() << endl;
        cout << "Full name: " << user.get_full_name() << endl;
        cout << "Email: " << user.get_email() << endl;
        cout << "Phone: " << user.get_phone() << endl;
        cout << "Username: " << user.get_user_name() << endl;
        cout << "Password: " << user.get_password() << endl;
        cout << "Permissions: " << user.get_permissions() << endl;
        cout << "----------------------" << endl;
    }

public:
    static void find_client()
    {
        
        _draw_screen("\tFind user screen");
        cout << "\nPlease, enter username: ";
        string username = cls_ipunt_validation::read_string();

        while (!cls_user::is_user_exist(username))
        {
            cout << "User not found, please enter again: ";
            username = cls_ipunt_validation::read_string();
        }
        cls_user client = cls_user::find(username);

        if (!client.is_empty())
        {
            cout << "\nUser found\n";
            _print_user(client);
        }
        else
        {
            cout << "\nUser not found\n";
        }
    }
};
