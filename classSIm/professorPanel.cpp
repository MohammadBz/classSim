#include <iostream>
#include "sample\human.h"
#include "sample\professor.h"

using namespace std;

void copyData(human person, professor &prof)
{
    prof.setfirstName(person.getFirstName());
    prof.setLastName(person.getLastName());
    prof.setId(person.getId());
    prof.setPassword(person.getPassword());
}
void validProfPathMenu(string &path)
{
    while (path.compare("1") != 0 && path.compare("2") != 0 && path.compare("3") != 0 && path.compare("4") != 0)
    {
        cout << "Wrong input!\n Please just select 1 or 2 or 3 or 4\n";
        getline(cin, path);
    }
}

void professorMenuText()
{
    cout << "-----1-Create new class\n-----2-Show current Classes for creating or checking homeworks or adding new students\n-----3-show your personal information\n-----4-return to menu\n--------------------\nPlease select by using number\n";
}
void professorMenu(human person)
{
    professor newProf;
    copyData(person, newProf);
    newProf.loadClassName(newProf.getId());
    string temp;
    professorMenuText();
    getline(cin, temp);
    validProfPathMenu(temp);
    while (temp.compare("4") != 0)
    {
        if (temp.compare("1") == 0)
        {
            newProf.createClass();
            newProf.writeClassName(newProf.getId());
        }
        else if (temp.compare("2") == 0)
        {
           newProf.chooseClass();
        }
        else if (temp.compare("3") == 0)
        {
            newProf.showPersonDetails();
        }
        else
        {
            return;
        }
        professorMenuText();
        getline(cin, temp);
        validProfPathMenu(temp);
    }
}
