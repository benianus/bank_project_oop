#pragma once
#include <iostream>
#include <iomanip>

#include "cls_screen.h"
#include "cls_input_validation.h"
#include "cls_users_list_screen.h"
#include "cls_add_new_user_screen.h"
#include "cls_delete_user_screen.h"
#include "cls_update_user_screen.h"
#include "cls_find_user_screen.h"

using namespace std;

class cls_manage_users_screen : protected cls_screen
{
private:
    enum en_manage_users_options
    {
        list_users = 1,
        add_new_users = 2,
        delete_userse = 3,
        update_users = 4,
        find_users = 5,
        main_menu = 6
    };
    static short _read_manage_users_option()
    {
        short choice;
        cout << "\nPlease, What do you want to chooose 1 to 6: ";
        choice = cls_ipunt_validation::read_number_between<short>(1, 6, "Invalid choice, enter number between 1 to 6");

        return choice;
    }
    static void _go_back_to_manage_users_screen()
    {
        cout << endl
             << "Press any key to go back to main menu ";
        system("pause");
        show_manage_users_screen();
    }
    static void _show_list_users_screen()
    {
        // cout << "\nList users screen will be shown here\n";
        cls_users_list_screen::show_users_list();
    }
    static void _show_add_new_users_screen()
    {
        // cout << "\nAdd new users screen will be shown here" << endl;
        cls_add_new_user_screen::add_new_users();
    }
    static void _show_delete_users_screen()
    {
        // cout << "\nDelete users screen will be shown here" << endl;
        cls_delete_user_screen::delete_client();
    }
    static void _show_update_users_screen()
    {
        // cout << "\nUpdate users screen wil be shown here" << endl;
        cls_update_user_screen::update_users();
    }
    static void _show_find_users_screen()
    {
        // cout << "\nFind users screen will be show here" << endl;
        cls_find_user_screen::find_client();
    }
    static void _performe_manage_users_screen_options(en_manage_users_options choice)
    {
        switch (choice)
        {
        case en_manage_users_options::list_users:
            system("cls");
            _show_list_users_screen();
            _go_back_to_manage_users_screen();
            break;
        case en_manage_users_options::add_new_users:
            system("cls");
            _show_add_new_users_screen();
            _go_back_to_manage_users_screen();
            break;
        case en_manage_users_options::delete_userse:
            system("cls");
            _show_delete_users_screen();
            _go_back_to_manage_users_screen();
            break;
        case en_manage_users_options::update_users:
            system("cls");
            _show_update_users_screen();
            _go_back_to_manage_users_screen();
            break;
        case en_manage_users_options::find_users:
            system("cls");
            _show_find_users_screen();
            _go_back_to_manage_users_screen();
            break;
        case en_manage_users_options::main_menu:
        {
        }
        }
    }

public:
    static void show_manage_users_screen()
    {
        if (!check_access_rights(cls_user::en_user_permissions::manange_users_access))
        {
            return;
        }
        system("cls");
        _draw_screen("\tManage users screen");
        cout << setw(37) << left << "\n\t\t\t\t\t============================================\n";
        cout << setw(37) << left << "\n\t\t\t\t\tMain menu\n";
        cout << setw(37) << left << "\n\t\t\t\t\t============================================\n";
        cout << setw(37) << left << "\n\t\t\t\t\t[1] List users\t\t\t\t\n";
        cout << setw(37) << left << "\n\t\t\t\t\t[2] Add new users\t\t\t\t\n";
        cout << setw(37) << left << "\n\t\t\t\t\t[3] Delete users \t\t\t\t\n";
        cout << setw(37) << left << "\n\t\t\t\t\t[4] Update users info\t\t\t\t\n";
        cout << setw(37) << left << "\n\t\t\t\t\t[5] Find users\t\t\t\t\n";
        cout << setw(37) << left << "\n\t\t\t\t\t[6] Main menu\t\t\t\t\n";
        cout << setw(37) << left << "\n\t\t\t\t\t============================================\n";

        _performe_manage_users_screen_options((en_manage_users_options)_read_manage_users_option());
    }
};
