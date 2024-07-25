#pragma once

#include <iostream>
#include <iomanip>

#include "cls_screen.h"
#include "cls_user.h"
#include "cls_person.h"
#include "cls_input_validation.h"

using namespace std;

class cls_delete_user_screen: protected cls_screen
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
    static void delete_client()
    {
        
        _draw_screen("Delete user screen");
        string username = "";
        cout << "Please, enter Username: ";
        username = cls_ipunt_validation::read_string();
        while (!cls_user::is_user_exist(username))
        {
            cout << "User not exist, try another one\n";
            username = cls_ipunt_validation::read_string();
        }

        cls_user user = cls_user::find(username);
        _print_user(user);

        char answer = 'y';
        cout << "Are you sure to delete this user Y/N: ";
        cin >> answer;

        if (answer == 'y' || answer == 'Y')
        {
            if (user.Delete())
            {
                cout << "\nUser succssefully deleted\n";
                _print_user(user);
            }
            else
            {
                cout << "\nError, User was not deleted\n";
            }
        }
    }
};
