#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <filesystem>
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
void human::showPersonDetails()
{
    cout << "--------------------\nfull name:" << this->firstName << " " << this->lastName << "\nID:" << this->id<< endl;
}

bool human::loadUserData(string &id)
{
    string filePath = "userDataBase\\" + id + "\\UserData.txt";
    ifstream inputFile(filePath);
    if (!inputFile.is_open())
    {
        return false;
    }

    string line;
    if (getline(inputFile, line))
    {
        stringstream ss(line);
        string attribute;

        while (getline(ss, attribute, ','))
        {
            size_t colonPos = attribute.find(':');
            if (colonPos != string::npos)
            {
                string attr = attribute.substr(0, colonPos);
                string value = attribute.substr(colonPos + 1);

                attr.erase(remove(attr.begin(), attr.end(), ' '), attr.end());
                value.erase(remove(value.begin(), value.end(), ' '), value.end());

                if (attr == "status")
                {
                    this->status = value;
                }
                else if (attr == "firstName")
                {
                    this->firstName = value;
                }
                else if (attr == "lastName")
                {
                    this->lastName = value;
                }
                else if (attr == "ID")
                {
                    this->id = value;
                }
                else if (attr == "Password")
                {
                    this->password = value;
                }
                else if (attr == "Role")
                {
                    this->role = value;
                }
            }
        }
    }
    inputFile.close();
    return true;
}
void human::updateUserData()
{
    string filePath = "userDataBase\\" + id + "\\UserData.txt";
    ofstream outputFile(filePath);
    outputFile << "status:" << this->getStatus() << ",";
    outputFile << "firstName:" << this->getFirstName() << ",";
    outputFile << "lastName:" << this->getLastName() << ",";
    outputFile << "ID:" << this->getId() << ",";
    outputFile << "Password:" << this->getPassword() << ",";
    outputFile << "Role:" << this->getRole() << ",";
    outputFile.close();
}
