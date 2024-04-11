#include <iostream>
// #include "student.h"
#define Max_Student_Size 30

using namespace std;

class student;
class homeWork;

class lecture
{
private:
    homeWork *listHomeWork;
    student *listStudents;
    int studentCounter;
    int homeWorkCounter;
    string lectureName;
    string classProfessor;
    string id;

public:
    lecture();
    student *getListStudent();
    homeWork *getListHomeWork();
    void addStudent();
    void addHomeWork();
    int getStudentCounter();
    int getHomeWorkCounter();
    void setStudentCounterr(int input);
    void showStudentList();
    void showHomeWorkList();
    void setId(string input);
    string getId();
    string getProfessorClass();
    string getlectureName();
    void setProfessorClass(string input);
    void setlectureName(string input);
    void loadLectureData(string id);
    void updateLectureData(string id);
    void loadStudents(string id);
    void updateStudentList(string id);
    void loadHomeWorks(string id);
    void updateHomeWorks(string id);
    void checkHomeWork();
    bool checkStuExist(string id);
    void changeProfessor(string inputPath,string restoreProfId);
    void removeStudent();
    void removeStudentId(string inputId);
};
