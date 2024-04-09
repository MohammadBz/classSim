#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <filesystem>
#include "student.h"
#include "lecture.h"
#include "homeWork.h"

using namespace std;

student::student()
{
    this->classCounter = 0;
}
string *student::getListClass()
{
    return this->listClassName;
}
void student::addClass(string input)
{
    this->listClassName[this->classCounter].append(input);
    this->classCounter++;
}
int student::getClassCounter()
{
    return this->classCounter;
}
void student::setClassCounter(int input)
{
    this->classCounter = input;
}
void student::showClassList()
{
    int classCount = 1;
    for (int i = 0; i < this->classCounter; i++, classCount++)
    {
        cout << "class number #" << classCount << "\nclass name:" << this->listClassName[i] << endl
             << "class ID:" << this->listClassName[i + 1] << endl;
        i++;
    }
}

void student::loadClassName(string id)
{
    string filePath = "userDataBase\\" + id + "\\ClassData.txt";
    ifstream inputFile(filePath);

    string className;
    this->classCounter = 0;
    while (getline(inputFile, className))
    {
        this->listClassName[this->classCounter] = className;
        this->classCounter++;
    }

    inputFile.close();
}
void student::writeClassName(string id)
{

    string filePath = "userDataBase\\" + id + "\\ClassData.txt";
    ofstream outputFile(filePath);

    for (int i = 0; i < this->classCounter; i++)
    {
        outputFile << this->listClassName[i] << endl;
    }

    outputFile.close();
}
void classMenuTextS()
{
    cout << "-----1-Show HomeWorks\n-----2-return to student Panel\n";
}
void printQuestion(string input, string classId)
{
    string path = "classDataBase\\" + classId + "\\homeWork\\" + input + "\\QuestionPath.txt";
    string Qpath;
    ifstream file(path);
    getline(file, Qpath);
    file.close();
    ifstream Qfile(Qpath);
    if (!Qfile.is_open())
    {
        cerr << "Failed to open the file." << endl;
        return;
    }
    string line;
    while (getline(Qfile, line))
    {
        cout << line << endl;
    }
    Qfile.close();
}
void submitAwnser(string hwName, string classId, string stuId)
{
    string awnserPath;
    cout << "give us your awnser Path\n";
    getline(cin, awnserPath);
    homeWork hwTemp;
    hwTemp.setQuestionName(hwName);
    hwTemp.loadAPaths(classId);
    hwTemp.loadStudents(classId);
    hwTemp.loadGradess(classId);
    int counter = hwTemp.getAwnserCount();
    hwTemp.addAwnserPath(awnserPath);
    hwTemp.setAwnserCount(counter);
    hwTemp.addStudent(stuId);
    hwTemp.setAwnserCount(counter);
    hwTemp.addGrade("-1");
    hwTemp.updatePaths(classId);
    hwTemp.updateStudents(classId);
    hwTemp.updateGRades(classId);
}
void seeGrade(string hwName, string classId, string stuId)
{
    homeWork hwTemp;
    hwTemp.setQuestionName(hwName);
    hwTemp.loadAPaths(classId);
    hwTemp.loadStudents(classId);
    hwTemp.loadGradess(classId);
    hwTemp.seeGrade(stuId);
}
void homeWorkMenu(string hwName, string classId, string stuid)
{
    string path;
    cout << "-----1-Question\n-----2-submit Awnser\n-----3-see your grade\n-----4-return\n";
    getline(cin, path);
    while (path.compare("4") != 0)
    {
        if (path.compare("1") == 0)
        {
            printQuestion(hwName, classId);
        }
        else if (path.compare("2") == 0)
        {
            submitAwnser(hwName, classId, stuid);
        }
        else if (path.compare("3") == 0)
        {
            seeGrade(hwName,classId,stuid);
        }
        cout << "\n-----1-Question\n-----2-submit Awnser\n-----3-see your grade\n-----4-return\n";
        getline(cin, path);
    }
}

void classMenu(string classid, string stuid)
{
    string path;
    classMenuTextS();
    lecture inputClass;
    inputClass.loadHomeWorks(classid);
    cout << "Please choose by number\n";
    getline(cin, path);
    while (path.compare("2") != 0)
    {
        if (path.compare("1") == 0)
        {
            inputClass.showHomeWorkList();
            if (inputClass.getHomeWorkCounter() != 0)
            {
                cout << "Please choose one of them by their names\n";
                string temp;
                getline(cin, temp);
                homeWorkMenu(temp, classid, stuid);
            }
        }
        else
        {
            return;
        }
        classMenuTextS();
        cout << "Please choose by number\n";
        getline(cin, path);
    }
}

void student::chooseClass()
{
    this->loadClassName(this->getId());
    if (this->classCounter == 0)
    {
        cout << "You don't have any active class\n";
        return;
    }
    this->showClassList();
    cout << "Please select a class using its class id\n";
    string inputId;
    getline(cin, inputId);
    bool checkFlag = false;
    for (int i = 0; i < this->classCounter; i++)
    {
        if (this->listClassName[i].compare(inputId) == 0)
        {
            checkFlag = true;
            break;
        }
    }
    if (checkFlag == false)
    {
        cout << "invalid Input\n";
        return;
    } // we continue if it is true
    classMenu(inputId, this->getId());
}