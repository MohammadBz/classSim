#include <iostream>
#include <windows.h>
#include "sample\lecture.h"
#include "sample\student.h"
#include "sample\human.h"
#include "sample\professor.h"
#include "signUpAndLogin.h"
#include "professorPanel.h"
#include "studentPanel.h"

using namespace std;

void validPathMenu(string &path)
{
  while (path.compare("1") != 0 && path.compare("2") != 0 && path.compare("3") != 0)
  {
    cout << "Wrong input!\n Please just select 1 or 2 or 3\n";
    getline(cin, path);
  }
}
void menuText()
{
  cout << "-----1-Sign UP\n-----2-Login\n-----3-Exit\n--------------------\nPlease select by using number\n";
}

void menu()
{

  cout << "--------------------\n-----Welcome !\n";
  menuText();
  string path;
  getline(cin, path);
  validPathMenu(path);
  while (path.compare("3") != 0)
  {
    if (path.compare("1") == 0)
    {
      human temp = signUp();
      cout << "Welcome " << temp.getFirstName() << " " << temp.getLastName() << endl;
      if (temp.getStatus().compare("inActive") == 0)
      {
        cout << "Your account is inActive please contact admin\n";
      }
      else if (temp.getRole().compare("professor") == 0)
      {
        professorMenu(temp);
      }
      else if (temp.getRole().compare("student") == 0)
      {
        studentMenu(temp);
      }
    }
    else if (path.compare("2") == 0)
    {
      human temp = login();
      if (temp.getStatus().compare("inActive") == 0)
      {
        cout << "Your account is inActive please contact admin\n";
      }
      else if (temp.getRole().compare("professor") == 0)
      {
        professorMenu(temp);
      }
      else if (temp.getRole().compare("student") == 0)
      {
        studentMenu(temp);
      }
    }
    else
    {
      return;
    }
    menuText();
    getline(cin, path);
    validPathMenu(path);
  } // end while
}

int main()
{
  system("color 0a");
  menu();
  return 0;
}
