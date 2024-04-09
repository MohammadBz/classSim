#include <iostream>
#pragma once
#include <string>

using namespace std;

class human
{
private:
    string firstName;
    string lastName;
    string id;
    string password;
    string role;
    string status;

public:
    void setfirstName(string input);
    string getFirstName();
    void setLastName(string input);
    string getLastName();
    void setId(string input);
    string getId();
    void setPassword(string input);
    string getPassword();
    void setRole(string input);
    string getRole();
    void setStatus(string input);
    string getStatus();
    void showPersonDetails();
    bool loadUserData(string &id);

};
