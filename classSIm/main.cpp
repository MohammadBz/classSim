#include <iostream>
#include "sample\lecture.h"
#include "sample\student.h"
#include "sample\human.h"
#include "sample\professor.h"

using namespace std;

int main()
{
      student ali;
      ali.setfirstName("ali");
      ali.setLastName("ghol");
      student popo;
      popo.setfirstName("poria");
      popo.setLastName("schafsyacfysac");
      professor omidi;
      omidi.setfirstName("gholam");
      omidi.setLastName("omidi");
      string omidiFullName=omidi.getFirstName()+omidi.getLastName();
      lecture firstClass("physics 1",omidiFullName);
      omidi.addClass(firstClass.getlectureName());
      firstClass.addStudent(ali);
      firstClass.addStudent(popo);
      firstClass.showStudentList();
      ali.addClass(firstClass.getlectureName());
      ali.showClassList();


    return 0;
}
