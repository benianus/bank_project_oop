#pragma once

#include <iostream>
#include <iomanip>

#include "cls_screen.h"
#include "cls_user.h"

using namespace std;

class cls_login_registerd_screen : protected cls_screen
{
private:
    static void _print_user_login_register_record_line(cls_user::st_register_login user)
    {
        cout << setw(15) << left << ""
             << "| " << left << setw(40) << user.register_login;
        cout << "| " << left << setw(20) << user.username;
        cout << "| " << left << setw(12) << user.password;
        cout << "| " << left << setw(20) << user.permissions;
    }

public:
    static void show_login_register_screen()
    {
        if (!check_access_rights(cls_user::en_user_permissions::login_registered_access))
        {
            return;
        }

        vector<cls_user::st_register_login> v_user = cls_user::get_register_login_list();
        string title = "\tRegister login list";
        string sub_title = "\t\tLogin Regiter(s): (" + to_string(v_user.size()) + ")";

        system("cls");
        _draw_screen(title, sub_title);
        cout << setw(15) << left << ""
             << "____________________________________________________________________________________________________\n";
        cout << setw(15) << left << ""
             << "____________________________________________________________________________________________________\n";
        cout << "\n\t\t\t\tLogin register list \t\t\t\t\n";
        cout << setw(15) << left << ""
             << "___________________________________________________________________________________________________\n\n";
        cout << setw(15) << left << ""
             << "| " << left << setw(40) << "Time & Date";
        cout << "| " << left << setw(20) << "Username";
        cout << "| " << left << setw(12) << "Passwond";
        cout << "| " << left << setw(20) << "Permission";
        cout << "\n";
        cout << setw(15) << left << ""
             << "____________________________________________________________________________________________________\n";

        if (v_user.size() == 0)
        {
            cout << "\n\t\t\tRegister login list is empty!\n";
        }
        else
        {
            for (cls_user::st_register_login user : v_user)
            {
                _print_user_login_register_record_line(user);
                cout << endl;
            }
        }
        cout << setw(15) << left << ""
             << "____________________________________________________________________________________________________\n";
    }
};
