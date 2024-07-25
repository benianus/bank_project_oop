#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

#include "cls_person.h"
#include "cls_string.h"
#include "cls_date.h"
#include "cls_utility.h"

using namespace std;

class cls_user : public cls_person
{
private:
    enum en_mode
    {
        empty_mode = 0,
        update_mode = 1,
        add_new_mode = 2
    };

    en_mode _mode;
    string _user_name;
    string _password;
    int _permissions;
    bool _mark_for_delete = false;

    static cls_user _convert_line_to_user_object(string line, string seperator = "#//#")
    {
        vector<string> v_user = cls_string::split(line, seperator);
        return cls_user(en_mode::update_mode, v_user[0], v_user[1], v_user[2], v_user[3], v_user[4], cls_utility::decryption(v_user[5]), stoi(v_user[6]));
    }
    static cls_user _get_empty_object()
    {
        return cls_user(en_mode::empty_mode, "", "", "", "", "", "", 0);
    }
    static vector<cls_user> _load_user_date_from_file()
    {
        vector<cls_user> v_user;

        fstream file_name;
        file_name.open("Users.txt", ios::in); // read mode
        if (file_name.is_open())
        {
            string line;

            while (getline(file_name, line))
            {
                cls_user user = _convert_line_to_user_object(line);
                v_user.push_back(user);
            }

            file_name.close();
        }

        return v_user;
    }
    static string _convert_user_object_to_line(cls_user user, string delimiter = "#//#")
    {
        string user_record_line = "";

        user_record_line = user.get_first_name() + delimiter;
        user_record_line += user.get_last_name() + delimiter;
        user_record_line += user.get_email() + delimiter;
        user_record_line += user.get_phone() + delimiter;
        user_record_line += user.get_user_name() + delimiter;
        user_record_line += cls_utility::encryption(user.get_password()) + delimiter;
        user_record_line += to_string(user.get_permissions());

        return user_record_line;
    }

    string _prepare_login_record(string seperator = "#//#")
    {

        string login_recorde_line = "";

        login_recorde_line += cls_date::get_system_date_string() + seperator;
        login_recorde_line += get_user_name() + seperator;
        login_recorde_line += cls_utility::encryption(get_password()) + seperator;
        login_recorde_line += to_string(get_permissions());

        return login_recorde_line;
    }

    static void _save_user_date_to_file(vector<cls_user> v_user)
    {
        fstream file_name;
        file_name.open("Users.txt", ios::out); // overwrite mode
        string data_line;
        if (file_name.is_open())
        {
            for (cls_user c : v_user)
            {
                if (c._mark_for_delete == false)
                {
                    data_line = _convert_user_object_to_line(c);
                    file_name << data_line << endl;
                }
            }
            file_name.close();
        }
    }
    static void _add_date_line_to_file(string line)
    {
        fstream file_name;
        file_name.open("Users.txt", ios::out | ios::app);
        if (file_name.is_open())
        {
            file_name << line << endl;
            file_name.close();
        }
    }

    void _update()
    {
        vector<cls_user> v_user = _load_user_date_from_file();
        for (cls_user &i : v_user)
        {
            if (i.get_user_name() == get_user_name())
            {
                i = *this;
                break;
            }
        }
        _save_user_date_to_file(v_user);
    }
    void _add_new()
    {
        _add_date_line_to_file(_convert_user_object_to_line(*this));
    }

public:
    struct st_register_login
    {
        string register_login;
        string username;
        string password;
        int permissions;
    };
    static st_register_login _convert_register_login_line_to_record(string line, string seperator = "#//#")
    {
        st_register_login user;
        vector<string> v_user = cls_string::split(line, seperator);

        user.register_login = v_user[0];
        user.username = v_user[1];
        user.password = cls_utility::decryption(v_user[2]);
        user.permissions = stoi(v_user[3]);

        return user;
    }

    enum en_user_permissions
    {
        all_access = -1,
        show_client_list_access = 1,
        add_new_client_access = 2,
        delete_client_access = 4,
        update_client_access = 8,
        find_client_access = 16,
        transactions_access = 32,
        manange_users_access = 64,
        login_registered_access = 128,
        currency_exhcange_access = 256

    };

    cls_user(en_mode mode, string first_name, string last_name, string email, string phone, string user_name, string password, int permissions) : cls_person(first_name, last_name, email, phone)
    {
        _mode = mode;
        _user_name = user_name;
        _password = password;
        _permissions = permissions;
    }

    bool is_empty()
    {
        return (_mode == en_mode::empty_mode);
    }
    bool get_mark_for_delete()
    {
        return _mark_for_delete;
    }

    void set_user_name(string user_name)
    {
        _user_name = user_name;
    }
    string get_user_name()
    {
        return _user_name;
    }
    // __declspec(property(get = get_user_name, put = set_user_name)) string username;

    void set_password(string password)
    {
        _password = password;
    }
    string get_password()
    {
        return _password;
    }
    // __declspec(property(get = get_password, put = set_password)) string password;

    void set_permissions(int permissions)
    {
        _permissions = permissions;
    }
    int get_permissions()
    {
        return _permissions;
    }
    // __declspec(property(get = get_permissions, put = set_permissions)) string permissions;

    static cls_user find(string user_name)
    {
        fstream file_name;
        file_name.open("Users.txt", ios::in);
        if (file_name.is_open())
        {
            string line;

            while (getline(file_name, line))
            {
                cls_user user = _convert_line_to_user_object(line);
                if (user._user_name == user_name)
                {
                    file_name.close();
                    return user;
                }
            }
            file_name.close();
        }
        return _get_empty_object();
    }
    static cls_user find(string user_name, string password)
    {
        fstream file_name;
        file_name.open("Users.txt", ios::in);
        if (file_name.is_open())
        {
            string line;

            while (getline(file_name, line))
            {
                cls_user user = _convert_line_to_user_object(line);
                if (user._user_name == user_name && user._password == password)
                {
                    file_name.close();
                    return user;
                }
            }
            file_name.close();
        }
        return _get_empty_object();
    }
    static bool is_user_exist(string username)
    {
        cls_user user = cls_user::find(username);
        return (!user.is_empty());
    }
    static bool is_user_exist(string username, string password)
    {
        cls_user user = cls_user::find(username, password);
        return (!user.is_empty());
    }

    enum en_save_results
    {
        save_failed_empty_object = 0,
        save_success = 1,
        save_failed_account_number_exist = 2
    };

    en_save_results save()
    {
        switch (_mode)
        {
        case en_mode::empty_mode:
            if (is_empty())
            {
                return en_save_results::save_failed_empty_object;
            }
        case en_mode::update_mode:
            _update();
            return en_save_results::save_success;
        case en_mode::add_new_mode:
            if (cls_user::is_user_exist(_user_name))
            {
                return en_save_results::save_failed_account_number_exist;
            }
            _add_new();
            _mode = en_mode::update_mode;
            return en_save_results::save_success;
            break;
        default:
            return (en_save_results)0;
            break;
        }
    }

    bool Delete()
    {
        vector<cls_user> v_user = _load_user_date_from_file();
        for (cls_user &c : v_user)
        {
            if (c.get_user_name() == _user_name)
            {
                c._mark_for_delete = true;
                break;
            }
        }

        _save_user_date_to_file(v_user);

        *this = _get_empty_object();

        return true;
    }
    static cls_user get_add_new_user_object(string username)
    {
        return cls_user(en_mode::add_new_mode, "", "", "", "", username, "", 0);
    }

    static vector<cls_user> get_users_list()
    {
        return _load_user_date_from_file();
    }

    bool check_access_permission(en_user_permissions permissions)
    {
        if (this->get_permissions() == en_user_permissions::all_access)
        {
            return true;
        }

        if ((permissions & this->get_permissions()) == permissions)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void registered_login()
    {
        string date_line = _prepare_login_record();
        fstream file_name;

        file_name.open("Login_register.txt", ios::out | ios::app);

        if (file_name.is_open())
        {
            file_name << date_line << endl;
            file_name.close();
        }
    }
    static vector<st_register_login> get_register_login_list()
    {
        fstream file_name;
        vector<st_register_login> v_user;

        file_name.open("Login_register.txt", ios::in);

        if (file_name.is_open())
        {
            st_register_login user;
            string line;
            while (getline(file_name, line))
            {
                user = _convert_register_login_line_to_record(line);
                v_user.push_back(user);
            }
            file_name.close();
        }

        return v_user;
    }
};
