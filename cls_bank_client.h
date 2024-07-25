#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

#include "cls_string.h"
#include "cls_person.h"
#include "cls_date.h"
#include "cls_user.h"

class cls_bank_client : public cls_person
{
private:
    enum en_mode
    {
        empty_mode = 0,
        update_mode = 1,
        add_new_mode = 2
    };

    en_mode _mode;
    string _account_number;
    string _pin_code;
    float _account_balance;
    bool _mark_for_delete = false;

    static cls_bank_client _convert_line_to_client_object(string line, string seperator = "#//#")
    {
        vector<string> v_client_data = cls_string::split(line, seperator);
        return cls_bank_client(en_mode::update_mode, v_client_data[0], v_client_data[1], v_client_data[2], v_client_data[3], v_client_data[4], v_client_data[5], stod(v_client_data[6]));
    }
    static string _convert_client_object_to_line(cls_bank_client client, string delimiter = "#//#")
    {
        string st_record_line = "";
        st_record_line = client.get_first_name() + delimiter;
        st_record_line += client.get_last_name() + delimiter;
        st_record_line += client.get_email() + delimiter;
        st_record_line += client.get_phone() + delimiter;
        st_record_line += client.get_account_number() + delimiter;
        st_record_line += client.get_pin_code() + delimiter;
        st_record_line += to_string(client.get_account_balance());

        return st_record_line;
    }
    static cls_bank_client _get_empty_object()
    {
        return cls_bank_client(en_mode::empty_mode, "", "", "", "", "", "", 0);
    }
    static vector<cls_bank_client> _load_client_date_from_file()
    {
        vector<cls_bank_client> v_client;

        fstream file_name;
        file_name.open("Clients.txt", ios::in); // read mode
        if (file_name.is_open())
        {
            string line;

            while (getline(file_name, line))
            {
                cls_bank_client client = _convert_line_to_client_object(line);
                v_client.push_back(client);
            }

            file_name.close();
        }

        return v_client;
    }
    static void _save_client_date_to_file(vector<cls_bank_client> v_client)
    {
        fstream file_name;
        file_name.open("Clients.txt", ios::out); // overwrite mode
        string data_line;
        if (file_name.is_open())
        {
            for (cls_bank_client c : v_client)
            {
                if (c._mark_for_delete == false)
                {
                    data_line = _convert_client_object_to_line(c);
                    file_name << data_line << endl;
                }
            }
            file_name.close();
        }
    }
    static void _add_date_line_to_file(string line)
    {
        fstream file_name;
        file_name.open("Clients.txt", ios::out | ios::app);
        if (file_name.is_open())
        {
            file_name << line << endl;
            file_name.close();
        }
    }
    void _update()
    {
        vector<cls_bank_client> _v_client;
        _v_client = _load_client_date_from_file();
        for (cls_bank_client &c : _v_client)
        {
            if (c.get_account_number() == get_account_number())
            {
                c = *this;
                break;
            }
        }
        _save_client_date_to_file(_v_client);
    }
    void _add_new()
    {
        _add_date_line_to_file(_convert_client_object_to_line(*this));
    }
    string _prepare_transfer_login_record(float amount, cls_bank_client destination_client, string username, string seperator = "#//#")
    {
        string transfer_record = "";
        
        transfer_record += cls_date::get_system_date_string() + seperator;
        transfer_record += _account_number + seperator;
        transfer_record += destination_client.get_account_number() + seperator;
        transfer_record += to_string(amount) + seperator;
        transfer_record += to_string(_account_balance) + seperator;
        transfer_record += to_string(destination_client.get_account_balance()) + seperator;
        transfer_record += username;

        return transfer_record;
    }
    void _transfer_log(float amount, cls_bank_client destination_client, string username)
    {
        string date_line = _prepare_transfer_login_record(amount, destination_client, username);
        fstream file_name;

        file_name.open("Transfer_log.txt", ios::out | ios::app);

        if (file_name.is_open())
        {
            file_name << date_line << endl;
            file_name.close();
        }
    }

public:
    cls_bank_client(en_mode mode, string first_name, string last_name, string email, string phone, string account_number, string pin_code, float account_balance) : cls_person(first_name, last_name, email, phone)
    {
        _mode = mode;
        _account_number = account_number;
        _pin_code = pin_code;
        _account_balance = account_balance;
    }

    bool is_empty()
    {
        return (_mode == en_mode::empty_mode);
    }

    bool get_mark_for_delete()
    {
        return _mark_for_delete;
    }

    void set_account_number(string account_number)
    {
        _account_number = account_number;
    }
    void set_pin_code(string pin_code)
    {
        _pin_code = pin_code;
    }
    void set_account_balance(float account_balance)
    {
        _account_balance = account_balance;
    }

    string get_account_number()
    {
        return _account_number;
    }
    string get_pin_code()
    {
        return _pin_code;
    }
    float get_account_balance()
    {
        return _account_balance;
    }

    /* No UI related code in business logic code
    void print()
    {
        cout << "----------------------" << endl;
        cout << "First name: " << get_first_name() << endl;
        cout << "Last name: " << get_last_name() << endl;
        cout << "Full name: " << get_full_name() << endl;
        cout << "Email: " << get_email() << endl;
        cout << "Phone: " << get_phone() << endl;
        cout << "Account number: " << _account_number << endl;
        cout << "PIN code: " << _pin_code << endl;
        cout << "Account Balance: " << get_account_balance() << endl;
        cout << "----------------------" << endl;
    } */
    void deposite(double amount)
    {
        _account_balance += amount;
        save();
    }
    bool whithdraw(double amount)
    {
        if (amount >= _account_balance)
        {
            return false;
        }
        else
        {
            _account_balance -= amount;
            save();
            return true;
        }
    }
    bool transfer(float amount, cls_bank_client &destination_client, string username)
    {
        if (amount > _account_balance)
        {
            return false;
        }

        whithdraw(amount);
        destination_client.deposite(amount);
        _transfer_log(amount, destination_client, username);
        return true;        
    }
    
    static cls_bank_client find(string account_number)
    {
        fstream file_name;
        file_name.open("Clients.txt", ios::in);
        if (file_name.is_open())
        {
            string line;

            while (getline(file_name, line))
            {
                cls_bank_client client = _convert_line_to_client_object(line);
                if (client._account_number == account_number)
                {
                    file_name.close();
                    return client;
                }
            }
            file_name.close();
        }
        return _get_empty_object();
    }
    static cls_bank_client find(string account_number, string pin_code)
    {
        fstream file_name;
        file_name.open("Clients.txt", ios::in);
        if (file_name.is_open())
        {
            string line;

            while (getline(file_name, line))
            {
                cls_bank_client client = _convert_line_to_client_object(line);
                if (client._account_number == account_number && client._pin_code == pin_code)
                {
                    file_name.close();
                    return client;
                }
            }
        }
        return _get_empty_object();
    }

    static bool is_client_exist(string user_name)
    {
        cls_bank_client client = cls_bank_client::find(user_name);
        return (!client.is_empty());
    }
    static bool is_client_exist(string account_number, string pin_code)
    {
        cls_bank_client client = cls_bank_client::find(account_number, pin_code);
        return (!client.is_empty());
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
            if (cls_bank_client::is_client_exist(_account_number))
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

    static cls_bank_client get_add_new_client_object(string account_number)
    {
        return cls_bank_client(en_mode::add_new_mode, "", "", "", "", account_number, "", 0);
    }

    bool Delete()
    {
        vector<cls_bank_client> v_client = _load_client_date_from_file();
        for (cls_bank_client &c : v_client)
        {
            if (c.get_account_number() == _account_number)
            {
                c._mark_for_delete = true;
                break;
            }
        }

        _save_client_date_to_file(v_client);

        *this = _get_empty_object();

        return true;
    }

    static vector<cls_bank_client> get_clients_list()
    {
        return _load_client_date_from_file();
    }

    static double get_clients_total_balance()
    {
        vector<cls_bank_client> v_client = cls_bank_client::get_clients_list();
        double total_balance = 0;

        for (cls_bank_client &c : v_client)
        {
            total_balance += c.get_account_balance();
        }
        return total_balance;
    }

    struct st_transfer_log
    {
        string date_time;
        string source_account_number;
        string destination_account_number;
        float amount_transfered;
        double source_account_balance;
        double destination_account_balance;
        string username;

    };
    static st_transfer_log _convert_transfer_log_line_to_record(string line, string seperator = "#//#")
    {
        st_transfer_log transfer_log;
        vector<string> v_transfer_log = cls_string::split(line, seperator);

        transfer_log.date_time = v_transfer_log[0];
        transfer_log.source_account_number = v_transfer_log[1];
        transfer_log.destination_account_number = v_transfer_log[2];
        transfer_log.amount_transfered = stof(v_transfer_log[3]);
        transfer_log.source_account_balance = stod(v_transfer_log[4]);
        transfer_log.destination_account_balance = stod(v_transfer_log[5]);
        transfer_log.username = v_transfer_log[6];

        return transfer_log;
    }
    static vector<st_transfer_log> get_tranfert_log_list()
    {
        vector<st_transfer_log> v_tranfer_list;
        fstream file_name;

        file_name.open("Transfer_log.txt", ios::in);

        if (file_name.is_open())
        {
            string line;
            st_transfer_log st_tranfer;
            while (getline(file_name, line))
            {
                st_tranfer = _convert_transfer_log_line_to_record(line);
                v_tranfer_list.push_back(st_tranfer);
            }
            
            file_name.close();
        }
        
        return v_tranfer_list;
    }
    
};