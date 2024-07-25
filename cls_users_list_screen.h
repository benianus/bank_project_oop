#pragma once

#include <iostream>
#include <iomanip>

#include "cls_screen.h"
#include "cls_user.h"

using namespace std;

class cls_users_list_screen : protected cls_screen
{
private:
    static void _print_user_record_line(cls_user user)
    {
        cout << setw(15) << left << ""
             << "| " << left << setw(40) << user.get_user_name();
        cout << "| " << left << setw(40) << user.get_password();
        cout << "| " << left << setw(40) << user.get_permissions();
    }

public:
    static void show_users_list()
    {
        vector<cls_user> v_user = cls_user::get_users_list();
        
        string title = "\tList users";
        string sub_title = "\t\tUser(s) (" + to_string(v_user.size()) + ")";
        _draw_screen(title, sub_title);

        cout << setw(15) << left << ""
             << "____________________________________________________________________________________________________\n";
        cout << setw(15) << left << ""
             << "____________________________________________________________________________________________________\n\n";
        cout << setw(15) << left << ""
             << "\t\t\t\tClients list : (" << v_user.size() << ") \t\t\t\t\n";
        cout << setw(15) << left << ""
             << "___________________________________________________________________________________________________\n\n";
        cout << setw(15) << left << ""
             << "| " << left << setw(40) << "Username";
        cout << "| " << left << setw(40) << "Password";
        cout << "| " << left << setw(40) << "Permissions";
        cout << "\n";
        cout << setw(15) << left << ""
             << "____________________________________________________________________________________________________\n";

        if (v_user.empty())
        {
            cout << "\n\t\t\tClient list empty, No available client!\n";
        }
        else
        {
            for (cls_user user : v_user)
            {
                _print_user_record_line(user);
                cout << endl;
            }
        }
        cout << setw(15) << left << ""
             << "____________________________________________________________________________________________________\n";
    }
};
