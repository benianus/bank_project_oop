#pragma once 

#include <iostream>
#include <string>

using namespace std;

class interface_comunication
{
public:
    virtual void send_email(string text, string body) = 0;
    virtual void send_sms(string text, string body) = 0;
    virtual  void send_fax(string text, string body) = 0;

};
