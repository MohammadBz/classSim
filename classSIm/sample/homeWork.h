#include <iostream>
#define Max_Student_Size 30
#pragma once

using namespace std;
class homeWork
{
private:
    string questionName;
    string questionPath;
    string listStudents[Max_Student_Size];
    string listGrades[Max_Student_Size];
    string listAwnsersPath[Max_Student_Size];
    int awnserCount;
public:
    homeWork();
    string getQuestionName();
    void setQuestionName(string input);
    void setQuestionPath(string input);
    string getQuestionPath();
    void setAwnserCount(int input);
    int getAwnserCount();
    void addStudent(string input);
    void addGrade(string input);
    string *getStudentList();
    string *getGradeList();
    void addAwnserPath(string input);
    string *getAwnsersPathList();
    void createHomeWorkDataFiles(homeWork hw, string idclass);
    void loadStudents(string classID);
    void loadGradess(string classID);
    void loadAPaths(string classID);
    void updateStudents(string classID);
    void updateGRades(string classID);
    void updatePaths(string classID);
    void showAnswersList();
    bool checkGradeStuDuplicate(string id);
    void editGrade(string classId,string stuID,string inputGrade);
    void seeGrade(string stuID);
};