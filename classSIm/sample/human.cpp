#include <iostream>
#include "human.h"

using namespace std;

void human::setfirstName(string input)
{
    this->firstName = input;
}
string human::getFirstName()
{
    return this->firstName;
}
void human::setLastName(string input)
{
    this->lastName = input;
}
string human::getLastName()
{
    return this->lastName;
}
void human::setId(string input)
{
    this->id = input;
}
string human::getId()
{
    return this->id;
}
void human::setPassword(string input)
{
    this->password = input;
}
string human::getPassword()
{
    return this->password;
}
void human::setRole(string input)
{
    this->role = input;
}
string human::getRole()
{
    return this->role;
}
void human::setStatus(string input)
{
    this->status = input;
}
string human::getStatus()
{
    return this->status;
}
