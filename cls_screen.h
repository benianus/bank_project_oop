#pragma once

#include <iostream>
#include <iomanip>

#include "cls_user.h"
#include "global.h"
#include "cls_date.h"

using namespace std;

class cls_screen : public cls_date
{
protected:

    static void _draw_screen(string title, string sub_title = "")
    {
        cout << "\n\t\t\t\t\t============================================\n";
        cout << setw(20) << left << "\n\t\t\t\t\t" << title;
        if (sub_title != "")
        {
            cout << "\n\t\t\t\t\t" << sub_title;
        }
        cout << "\n\n\t\t\t\t\t============================================\n";

        cout << "\n\t\t\t\t\tUser: " << current_user.get_user_name() << endl;
        cout << "\t\t\t\t\tDate: " << cls_date::date_to_string(cls_date()) << endl;
    }

    static bool check_access_rights(cls_user::en_user_permissions permissions)
    {
        if (!current_user.check_access_permission(permissions))
        {
            cout << "\n\t\t\t\t---------------------------------\n";
            cout << "\n\t\t\t\tAccess denied, contact your Admin\n";
            cout << "\n\t\t\t\t---------------------------------\n";
            return false;
        }
        else
        {
            return true;
        }
    }
};
