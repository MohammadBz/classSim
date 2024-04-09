#include <iostream>
#include "sample\human.h"
#include "sample\student.h"

using namespace std;
void copyData(human person, student &stu)
{
    stu.setfirstName(person.getFirstName());
    stu.setLastName(person.getLastName());
    stu.setId(person.getId());
    stu.setPassword(person.getPassword());
}
void studentMenuText()
{
    cout << "-----1-Show current Classes for checking homeworks and grades\n-----2-show your personal information\n-----3-return to menu\n--------------------\nPlease select by using number\n";
}
void validStuPathMenu(string &path)
{
    while (path.compare("1") != 0 && path.compare("2") != 0 && path.compare("3"))
    {
        cout << "Wrong input!\n Please just select 1 or 2 or 3\n";
        getline(cin, path);
    }
}

void studentMenu(human person)
{
    student newStu;
    copyData(person, newStu);
    newStu.loadClassName(newStu.getId());
    string temp;
    studentMenuText();
    getline(cin, temp);
    validStuPathMenu(temp);
    while (temp.compare("3") != 0)
    {
        if (temp.compare("1") == 0)
        {
            newStu.chooseClass();
        }
        else if (temp.compare("2") == 0)
        {
            newStu.showPersonDetails();
        }
        else
        {
            return;
        }
        studentMenuText();
        getline(cin, temp);
        validStuPathMenu(temp);
    }
}