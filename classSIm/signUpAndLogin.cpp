#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <filesystem>
#include "sample\human.h"

using namespace std;

bool nameCheck(string str)
{
    for (char c : str)
    {
        if (!isalpha(c))
        {
            return false;
        }
    }
    if (str.size() > 25)
    {
        return false;
    }
    return true;
}
bool passWordCheck(string str)
{
    if (str.length() < 6)
    {
        return false;
    }
    for (char c : str)
    {
        if (isspace(c) || c == ',')
        {
            return false;
        }
    }
    return true;
}
bool checkId(string str)
{
    for (char c : str)
    {
        if (!isdigit(c))
        {
            return false;
        }
    }
    return true;
}
string idGenerator(string role)
{
    ifstream inputFile("IdHistory.txt");

    string line;
    getline(inputFile, line);
    inputFile.close();

    istringstream iss(line);
    string num1Str, num2Str;
    getline(iss, num1Str, ',');
    getline(iss, num2Str, ',');
    int num1, num2;
    istringstream(num1Str) >> num1;
    istringstream(num2Str) >> num2;
    if (role.compare("student") == 0)
    {
        num1++;
        ofstream outputFile("IdHistory.txt");
        outputFile << num1 << "," << num2;
        outputFile.close();
        return num1Str;
    }
    else
    {
        num2++;
        ofstream outputFile("IdHistory.txt");
        outputFile << num1 << "," << num2;
        outputFile.close();
        return num2Str;
    }
}
void createUserDataFile(human person)
{
    string folderPath = "userDataBase\\" + person.getId();
    filesystem::create_directory(folderPath);

    string filePath = folderPath + "\\UserData.txt";
    string filePathClass = folderPath + "\\ClassData.txt";
    ofstream outputFile(filePath);
    ofstream outputFileClass(filePathClass);
    outputFile << "status:" << person.getStatus() << ",";
    outputFile << "firstName:" << person.getFirstName() << ",";
    outputFile << "lastName:" << person.getLastName() << ",";
    outputFile << "ID:" << person.getId() << ",";
    outputFile << "Password:" << person.getPassword() << ",";
    outputFile << "Role:" << person.getRole() << ",";
    outputFile.close();
    outputFileClass.close();
}

string getPath()
{
    string path;
    getline(cin, path);
    while (path.compare("1") != 0 && path.compare("2") != 0)
    {
        cout << "Invalid input try again\n";
        getline(cin, path);
    }
    return path;
}
bool isValidPass(string humanPass)
{
    cout << "Please enter your password:\n";
    string temp;
    getline(cin, temp);
    while (temp.compare(humanPass) != 0 || passWordCheck(temp) == false)
    {
        cout << "Wrong Password!\nDo you want to try again(select 1) or return to menu(select 2)?\n";
        string path = getPath();
        if (path.compare("1") == 0)
        {
            return isValidPass(humanPass);
        }
        else
        {
            return false;
        }
    }
    return true;
}

human signUp()
{
    human newPerson;
    string temp;
    cout << "Please enter your first Name:\n";
    getline(cin, temp);
    while (nameCheck(temp) == false)
    {
        cout << "wrong input! please only use english letters\n";
        getline(cin, temp);
    }
    newPerson.setfirstName(temp);
    cout << "Please enter your last Name:\n";
    getline(cin, temp);
    while (nameCheck(temp) == false)
    {
        cout << "wrong input! please only use english letters\n";
        getline(cin, temp);
    }
    newPerson.setLastName(temp);
    cout << "Please enter your password(minimum 6 character without using space and ,)\n";
    getline(cin, temp);
    while (passWordCheck(temp) == false)
    {
        cout << "wrong input! your password should have at least 6 character and don't contain space or comma(,)\n";
        getline(cin, temp);
    }
    newPerson.setPassword(temp);
    cout << "Are you student or professor?\n";
    getline(cin, temp);
    while (temp.compare("student") != 0 && temp.compare("professor") != 0)
    {
        cout << "wrong input!please only select between those two option\n";
        getline(cin, temp);
    }
    newPerson.setRole(temp);
    newPerson.setId(idGenerator(temp));
    newPerson.setStatus("active");
    createUserDataFile(newPerson);
    cout << "Welcome " << newPerson.getFirstName() << " " << newPerson.getLastName() << endl;
    return newPerson;
}
// status:<>,firstName:<>,LastName:<>,ID:<>,Password:<>,Role:<>,
void checkAdmin()
{
    cout << "Please enter your password:\n";
    string temp;
    getline(cin, temp);
    if(temp.compare("admin123")==0){
        
    }
}
human login()
{
    human newPerson;
    human fail;
    fail.setRole("no");
    cout << "please enter your ID:\n";
    string temp;
    getline(cin, temp);
    if (temp.compare("admin") == 0)
    {
    }
    while (checkId(temp) == false)
    {
        cout << "ID only contain numbers\n";
        getline(cin, temp);
    }
    if (newPerson.loadUserData(temp) == false)
    {

        cout << "There is no such ID in our dataBase\nDo you want to try again(select 1) or return to menu(select 2)?\n";
        string path = getPath();
        if (path.compare("1") == 0)
        {
            human alo = login();
            return alo;
        }
        else
            return fail;
    } // end if
    // we have that id so we continue and checl the passwords
    if (isValidPass(newPerson.getPassword()) == false)
    {
        return fail;
    } // if true then the login was succesful
    cout << "Welcome " << newPerson.getFirstName() << " " << newPerson.getLastName() << endl;
    return newPerson;
}