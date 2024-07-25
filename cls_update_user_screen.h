#pragma once

#include <iostream>
#include <iomanip>

#include "cls_screen.h"
#include "cls_user.h"
#include "cls_person.h"
#include "cls_input_validation.h"

using namespace std;

class cls_update_user_screen : protected cls_screen
{
private:
    static void _read_user_info(cls_user &user)
    {
        cout << "\nEnter first name: ";
        user.set_first_name(cls_ipunt_validation::read_string());

        cout << "\nEnter last name: ";
        user.set_last_name(cls_ipunt_validation::read_string());

        cout << "\nEnter email: ";
        user.set_email(cls_ipunt_validation::read_string());

        cout << "\nEnter phone: ";
        user.set_phone(cls_ipunt_validation::read_string());

        cout << "\nEnter Password: ";
        user.set_password(cls_ipunt_validation::read_string());

        cout << "\nEnter permissions: ";
        user.set_permissions(_read_permissions());
    }
    static int _read_permissions()
    {
        int permission = 0;
        char answer = 'y';

        cout << "\nDo you want to give him full access [Y]Yes [N]No: ";
        cin >> answer;

        if (answer == 'y' || answer == 'Y')
        {
            return -1;
        }

        cout << "\nWhich access do you want to give\n";
        cout << "\nShow client list [Y]Yes [N]No: ";
        cin >> answer;

        if (toupper(answer) == 'Y')
        {
            permission += cls_user::en_user_permissions::show_client_list_access;
        }
        cout << "\nAdd new client [Y]Yes [N]No: ";
        cin >> answer;

        if (toupper(answer) == 'Y')
        {
            permission += cls_user::en_user_permissions::add_new_client_access;
        }

        cout << "\nDelete client [Y]Yes [N]No: ";
        cin >> answer;

        if (toupper(answer) == 'Y')
        {
            permission += cls_user::en_user_permissions::delete_client_access;
        }

        cout << "\nUpdate client [Y]Yes [N]No: ";
        cin >> answer;

        if (toupper(answer) == 'Y')
        {
            permission += cls_user::en_user_permissions::update_client_access;
        }

        cout << "\nFind client [Y]Yes [N]No: ";
        cin >> answer;

        if (toupper(answer) == 'Y')
        {
            permission += cls_user::en_user_permissions::find_client_access;
        }

        cout << "\nTransactions [Y]Yes [N]No: ";
        cin >> answer;

        if (toupper(answer) == 'Y')
        {
            permission += cls_user::en_user_permissions::transactions_access;
        }

        cout << "\nManage users [Y]Yes [N]No: ";
        cin >> answer;

        if (toupper(answer) == 'Y')
        {
            permission += cls_user::en_user_permissions::manange_users_access;
        }

        cout << "\nLogin registered users [Y]Yes [N]No: ";
        cin >> answer;

        if (toupper(answer) == 'Y')
        {
            permission += cls_user::en_user_permissions::login_registered_access;
        }

        cout << "\nCurrency exchange [Y]Yes [N]No: ";
        cin >> answer;

        if (toupper(answer) == 'Y')
        {
            permission += cls_user::en_user_permissions::currency_exhcange_access;
        }
        
        return permission;
    }
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
    static void update_users()
    {

        _draw_screen("\tUpdate users screen");
        string username = "";

        cout << "Please, enter username: ";
        username = cls_ipunt_validation::read_string();

        while (!cls_user::is_user_exist(username))
        {
            cout << "\nUsername is not found, choose another one: ";
            username = cls_ipunt_validation::read_string();
        }

        cls_user uesr = cls_user::find(username);
        _print_user(uesr);

        char answer = 'y';
        cout << "Are you sure to Update this user Y/N: ";
        cin >> answer;

        if (answer == 'y' || answer == 'Y')
        {
            cout << "\nUpdate user Info:";
            cout << "\n____________________\n";

            _read_user_info(uesr);

            cls_user::en_save_results save_results;
            save_results = uesr.save();

            switch (save_results)
            {
            case cls_user::en_save_results::save_success:
                cout << "User Update successfully\n";
                _print_user(uesr);
                break;
            case cls_user::en_save_results::save_failed_empty_object:
                cout << "Error, Empty user\n";
                break;
            }
        }
    }
};
