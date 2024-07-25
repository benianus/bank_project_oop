#pragma once

#include <iostream>
#include <iomanip>

#include "cls_main_screen.h"
#include "cls_screen.h"
#include "cls_user.h"
#include "global.h"

using namespace std;

class cls_login_screen : protected cls_screen
{
private:
    static bool _login()
    {
        bool login_failed = false;
        string username, password;
        short failed_login_count = 0;

        do
        {
            if (login_failed)
            {
                failed_login_count++;

                cout << "\nInvalid Username/Password: ";
                cout << "\nLogin failed, it rests " << (3 - failed_login_count) << " times to try\n";
            }
            if (failed_login_count == 3)
            {
                cout << "\nSytem locked\n";
                return false;
            }

            cout << "\nEnter Username: ";
            cin >> username;

            cout << "\nEnter Password: ";
            cin >> password;

            current_user = cls_user::find(username, password);

            login_failed = current_user.is_empty();

        } while (login_failed);

        current_user.registered_login();
        
        cls_main_screen::show_main_menu_screen();

        return true;
    }

public:
    static bool show_login_screen()
    {
        system("cls");
        _draw_screen("\tLogin");
        return _login();
    }
};
