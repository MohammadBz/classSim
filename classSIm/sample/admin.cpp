#include <iostream>
#include "admin.h"
#include "human.h"
#include <string>
#include <filesystem>
#include "G:\oldDesktop\programing\newS\UNI\402-403-AP\Projects\classSIm\signUpAndLogin.h"
#include "professor.h"
#include "lecture.h"
#define Max_User_Count 100

using namespace std;

void adminMenuText()
{
    cout << "-----1-Create User\n-----2-Create Class\n-----3-Edit user's info\n-----4-delete a user\n-----5-show all user's ID List\n-----6-Restore a user\n-----7-Return to Menu\n";
}
void editUserMenuText()
{
    cout << "-----1-Change first name\n-----2-Change last name\n-----3-change password\n-----4-Return\n";
}
void validPath(string path)
{
    while (path.compare("1") != 0 && path.compare("2") != 0 && path.compare("3") != 0 && path.compare("4") != 0 && path.compare("5") != 0 && path.compare("6") != 0 && path.compare("7") != 0)
    {
        cout << "Invalid Path, try again and select 1 or 2 or 3 or 4 or 5 or 6 or 7\n";
        getline(cin, path);
    }
}
void getDirectoryContents(const string &directoryPath, string *names, int &count)
{
    filesystem::path directory(directoryPath);

    if (!filesystem::is_directory(directory))
    {
        cout << "Error: Not a valid directory path." << endl;
        return;
    }
    count = 0;
    for (const auto &entry : filesystem::directory_iterator(directory))
    {
        names[count] = entry.path().filename().string();
        count++;
    }
}
void showAllUsersId(string *nameArr, int nameCOunts)
{
    for (int i = 0; i < nameCOunts; i++)
    {
        cout << nameArr[i] << endl;
    }
}
void createNewClassAdmin(string *nameArr, int nameCounts)
{
    cout << "the Class belongs to which Professor(give us the Professor ID)?\n";
    string Inputid;
    getline(cin, Inputid);
    if (Inputid[0] != '1')
    {
        cout << "We don't have a professor with that Id\n";
        return;
    }
    int i;
    for (i = 0; i < nameCounts; i++)
    {
        if (Inputid.compare(nameArr[i]) == 0)
        {
            break;
        }
    }
    if (i == nameCounts)
    {
        cout << "We don't have a professor with that Id\n";
        return;
    }
    professor newProfessor;
    newProfessor.loadUserData(Inputid);
    newProfessor.loadClassName(Inputid);
    newProfessor.createClass();
    newProfessor.writeClassName(newProfessor.getId());
}
void editUserData(string *nameArr, int nameCounts)
{
    cout << "what is the Id of the user?\n";
    string inputId;
    getline(cin, inputId);
    int i;
    for (i = 0; i < nameCounts; i++)
    {
        if (inputId.compare(nameArr[i]) == 0)
        {
            break;
        }
    }
    if (i == nameCounts)
    {
        cout << "We don't have a user with that Id\n";
        return;
    }
    human newPerson;
    newPerson.loadUserData(inputId);
    string path;
    editUserMenuText();
    cout << "Please choose by number\n";
    getline(cin, path);
    while (path.compare("4") != 0)
    {
        if (path.compare("1") == 0)
        {
            string newName;
            cout << "what is the new name?\n";
            getline(cin, newName);
            newPerson.setfirstName(newName);
            newPerson.updateUserData();
        }
        else if (path.compare("2") == 0)
        {
            string newName;
            cout << "what is the new name?\n";
            getline(cin, newName);
            newPerson.setLastName(newName);
            newPerson.updateUserData();
        }
        else if (path.compare("3") == 0)
        {
            string newPass;
            cout << "what is the new password?\n";
            getline(cin, newPass);
            newPerson.setPassword(newPass);
            newPerson.updateUserData();
        }
        cout << "successfully changed!\n";
        editUserMenuText();
        cout << "Please choose by number\n";
        getline(cin, path);
    }
}

void deleteUser()
{
    string inputId;
    cout << "Please give the ID\n";
    getline(cin, inputId);
    human newPerson;
    if (newPerson.loadUserData(inputId) == false)
    {
        cout << "We don't have a user with this id\n";
        return;
    }
    if (newPerson.getStatus().compare("inActive") == 0)
    {
        cout << "user is already inActive\n";
        return;
    }
    if (newPerson.getRole().compare("student") == 0)
    {
        newPerson.setStatus("inActive");
        newPerson.updateUserData();
    }
    else
    {
        professor newProf;
        newProf.loadUserData(inputId);
        newProf.loadClassName(inputId);
        newProf.setStatus("inActive");
        newProf.updateUserData();
        if (newProf.getClassCounter() > 0)
        {
            newProf.exitAllLecture();
        }
    }
}

void reStoreUser(string *nameArr, int nameCount)
{
    string inputId;
    cout << "Please give the ID\n";
    getline(cin, inputId);
    human newPerson;
    if (newPerson.loadUserData(inputId) == false)
    {
        cout << "We don't have a user with this id\n";
        return;
    }
    if (newPerson.getRole().compare("student") == 0)
    {
        newPerson.setStatus("active");
        newPerson.updateUserData();
    }
    else
    { // bug  was that it deleetd the old prof ClassData;
        professor newProf;
        newProf.loadUserData(inputId);
        newProf.loadClassName(inputId);
        if (newProf.getClassCounter() > 0)
        {
            newProf.restoreAllLecture(nameArr, nameCount);
        }
        newProf.setStatus("active");
        newProf.updateUserData();
    }
}
void adminMenu()
{
    cout << "Welcome Admin!\n";
    string path;
    adminMenuText();
    cout << "Please choose by number\n";
    getline(cin, path);

    while (path.compare("7") != 0)
    {
        int namesCount = 0;
        string *namesArr = new string[Max_User_Count];
        getDirectoryContents("G:\\oldDesktop\\programing\\newS\\UNI\\402-403-AP\\Projects\\classSIm\\userDataBase", namesArr, namesCount);
        if (path.compare("1") == 0)
        {
            signUp();
        }
        else if (path.compare("2") == 0)
        {
            createNewClassAdmin(namesArr, namesCount);
        }
        else if (path.compare("3") == 0)
        {
            editUserData(namesArr, namesCount);
        }
        else if (path.compare("4") == 0)
        {
            deleteUser();
        }
        else if (path.compare("5") == 0)
        {
            showAllUsersId(namesArr, namesCount);
        }
        else if (path.compare("6") == 0)
        {
            reStoreUser(namesArr, namesCount);
        }
        adminMenuText();
        cout << "Please choose by number\n";
        getline(cin, path);
        delete[] namesArr;
    }
}
