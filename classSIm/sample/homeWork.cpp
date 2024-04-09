#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <filesystem>
#include "homeWork.h"

using namespace std;

homeWork::homeWork()
{
    this->awnserCount = 0;
}
string homeWork::getQuestionName()
{
    return this->questionName;
}
void homeWork::setQuestionName(string input)
{
    this->questionName = input;
}
void homeWork::setQuestionPath(string input)
{
    this->questionPath.append(input);
}
string homeWork::getQuestionPath()
{
    return this->questionPath;
}
void homeWork::setAwnserCount(int input)
{
    this->awnserCount = input;
}
int homeWork::getAwnserCount()
{
    return this->awnserCount;
}
void homeWork::addStudent(string input)
{
    this->listStudents[this->awnserCount] = input;
    this->awnserCount++;
}
string *homeWork::getStudentList()
{
    return this->listStudents;
}
string *homeWork::getGradeList()
{
    return this->listStudents;
}
void homeWork::addAwnserPath(string input)
{
    this->listAwnsersPath[this->awnserCount] = input;
    this->awnserCount++;
}
void homeWork::addGrade(string input)
{
    this->listGrades[this->awnserCount] = input;
    this->awnserCount++;
}
string *homeWork::getAwnsersPathList()
{
    return this->listAwnsersPath;
}

void homeWork::createHomeWorkDataFiles(homeWork hw, string idclass)
{
    string folderPath = "classDataBase\\" + idclass + "\\homeWork\\" + hw.getQuestionName();
    filesystem::create_directory(folderPath);

    string filePath = folderPath + "\\QuestionPath.txt";
    string filePathSt = folderPath + "\\ListOfStudents.txt";
    string filePathG = folderPath + "\\ListOfGrades.txt";
    string filePathPa = folderPath + "\\ListOfAwnsersPath.txt";
    ofstream outputFile(filePath);
    outputFile << hw.getQuestionPath();

    ofstream outputFileSt(filePathSt);
    ofstream outputFileG(filePathG);
    ofstream outputFilePa(filePathPa);
    outputFile.close();
    outputFileG.close();
    outputFilePa.close();
    outputFileSt.close();
}
void homeWork::loadStudents(string classID)
{
    string filePath = "classDataBase\\" + classID + "\\homeWork\\" + this->questionName + "\\ListOfStudents.txt";
    ifstream inputFile(filePath);

    string studentName;
    this->awnserCount = 0;
    while (getline(inputFile, studentName))
    {
        this->listStudents[this->awnserCount] = studentName;
        this->awnserCount++;
    }
    inputFile.close();
}
void homeWork::loadGradess(string classID)
{
    string filePath = "classDataBase\\" + classID + "\\homeWork\\" + this->questionName + "\\ListOfGrades.txt";
    ifstream inputFile(filePath);

    string studentName;
    this->awnserCount = 0;
    while (getline(inputFile, studentName))
    {
        this->listGrades[this->awnserCount] = studentName;
        this->awnserCount++;
    }
    inputFile.close();
}
void homeWork::loadAPaths(string classID)
{
    string filePath = "classDataBase\\" + classID + "\\homeWork\\" + this->questionName + "\\ListOfAwnsersPath.txt";
    ifstream inputFile(filePath);

    string studentName;
    this->awnserCount = 0;
    while (getline(inputFile, studentName))
    {
        this->listAwnsersPath[this->awnserCount] = studentName;
        this->awnserCount++;
    }
    inputFile.close();
}
void homeWork::updateStudents(string classID)
{
    string filePath = "classDataBase\\" + classID + "\\homeWork\\" + this->questionName + "\\ListOfStudents.txt";
    ofstream outputFile(filePath);
    for (int i = 0; i < this->awnserCount; i++)
    {
        outputFile << this->listStudents[i] << endl;
    }
    outputFile.close();
}
void homeWork::updateGRades(string classID)
{
    string filePath = "classDataBase\\" + classID + "\\homeWork\\" + this->questionName + "\\ListOfGrades.txt";
    ofstream outputFile(filePath);
    for (int i = 0; i < this->awnserCount; i++)
    {
        outputFile << this->listGrades[i] << endl;
    }
    outputFile.close();
}
void homeWork::updatePaths(string classID)
{
    string filePath = "classDataBase\\" + classID + "\\homeWork\\" + this->questionName + "\\ListOfAwnsersPath.txt";
    ofstream outputFile(filePath);
    for (int i = 0; i < this->awnserCount; i++)
    {
        outputFile << this->listAwnsersPath[i] << endl;
    }
    outputFile.close();
}
void homeWork::showAnswersList()
{
    for (int i = 0; i < this->awnserCount; i++)
    {
        if (this->listGrades[i].compare("-1") != 0)
        {
            cout << "ID:" << this->listStudents[i] << "\tanswer Path:" << this->listAwnsersPath[i] << "\tgiven Grade:" << this->listGrades[i] << endl;
        }
        else
        {
            cout << "ID:" << this->listStudents[i] << "\tanswer Path:" << this->listAwnsersPath[i] << "\tgiven Grade:Not defined yet" << endl;
        }
    }
}
bool homeWork::checkGradeStuDuplicate(string id)
{
    for (int i = 0; i < this->awnserCount; i++)
    {
        if (this->listStudents[i].compare(id) == 0)
        {
            return true;
        }
    }
    return false;
}

void homeWork::editGrade(string classId, string stuID, string inputGrade)
{
    int index = -1;
    for (int i = 0; i < this->awnserCount; i++)
    {
        if (stuID.compare(this->listStudents[i]) == 0)
        {
            index = i;
            break;
        }
    }
    this->listGrades[index] = inputGrade;
    this->updateGRades(classId);
}
void homeWork::seeGrade(string stuID)
{
    int index = -1;
    for (int i = 0; i < this->awnserCount; i++)
    {
        if (stuID.compare(this->listStudents[i]) == 0)
        {
            index = i;
            break;
        }
    }
    if (this->listGrades[index].compare("-1") == 0)
    {
        cout << "Not defined\n";
    }
    else
    {
        cout << "given Grade:" << this->listGrades[index] << endl;
    }
}