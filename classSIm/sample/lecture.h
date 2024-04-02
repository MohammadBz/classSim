#include <iostream>
// #include "student.h"
#define Max_Student_Size 30

using namespace std;

class student;

class lecture
{
private:
    student* listStudents;
    int studentCounter;
    string lectureName;
    string classProfessor;
public:
    lecture(string className,string professorName);
    student *getListStudent();
    void addStudent(student inputSt);
    int getStudentCounter();
    void setStudentCounterr(int input);
    void showStudentList();
    string getProfessorClass();
    string getlectureName();
};
