#include <iostream>
#define Max_Student_Size 30
#include "lecture.h"
#include <fstream>
#include <sstream>
#include <algorithm>
#include "student.h"
#include "homeWork.h"

using namespace std;

lecture::lecture()
{
    this->listStudents = new student[Max_Student_Size];
    this->listHomeWork = new homeWork[Max_Student_Size];
    this->studentCounter = 0;
    this->homeWorkCounter = 0;
}

student *lecture::getListStudent()
{
    return this->listStudents;
}
homeWork *lecture::getListHomeWork()
{
    return this->listHomeWork;
}
void lecture::addStudent()
{
    string inputId;
    cout << "Please give us the id of student\n";
    getline(cin, inputId);
    student temp;
    if (temp.loadUserData(inputId) == false)
    {
        cout << "There is no student with this ID\n";
        return;
    }
    if (this->studentCounter < Max_Student_Size)
    {
        this->listStudents[this->studentCounter] = temp;
        this->studentCounter++;
        temp.addClass(this->getlectureName());
        temp.addClass(this->getId());
        temp.writeClassName(temp.getId());
        cout << temp.getFirstName() << " " << temp.getLastName() << "   have been added to class\n";
    }
    else
    {
        cout << "you can't add anymore student!\n";
    }
}
void lecture::addHomeWork()
{
    homeWork newHw;
    cout << "What is the question name?\n";
    string temp;
    getline(cin, temp);
    newHw.setQuestionName(temp);
    cout << "What is the directory path of your question?\n";
    getline(cin, temp);
    newHw.setQuestionPath(temp);
    newHw.createHomeWorkDataFiles(newHw, this->id);
    if (this->homeWorkCounter < Max_Student_Size)
    {
        this->listHomeWork[this->homeWorkCounter] = newHw;
        this->homeWorkCounter++;
    }
    else
    {
        cout << "you can't add anymore homeWorks!\n";
    }
}
int lecture::getStudentCounter()
{
    return this->studentCounter;
}
void lecture::setStudentCounterr(int input)
{
    this->studentCounter = input;
}
string lecture::getProfessorClass()
{
    return this->classProfessor;
}

void lecture::showStudentList()
{
    cout << "Professor of this lecture:" << this->classProfessor << endl;
    if (this->studentCounter == 0)
    {
        cout << "there is no student in this class\n";
        return;
    }
    for (int i = 0; i < this->studentCounter; i++)
    {
        cout << "student number #" << i + 1 << ":\nfirst name:" << this->listStudents[i].getFirstName() << "\nlast name:" << this->listStudents[i].getLastName() << "\nID:" << this->listStudents[i].getId() << endl;
    }
}
void lecture::showHomeWorkList()
{
    if (this->homeWorkCounter == 0)
    {
        cout << "there is no homeWork in this class\n";
        return;
    }
    for (int i = 0; i < this->homeWorkCounter; i++)
    {
        cout << "homeWork number #" << i + 1 << " :" << listHomeWork[i].getQuestionName() << endl;
    }
}
int lecture::getHomeWorkCounter()
{
    return this->homeWorkCounter;
}
string lecture::getlectureName()
{
    return this->lectureName;
}
void lecture::setId(string input)
{
    this->id = input;
}
string lecture::getId()
{
    return this->id;
}
void lecture::setlectureName(string input)
{
    this->classProfessor = input;
}
void lecture::setProfessorClass(string input)
{
    this->lectureName;
}
void lecture::loadStudents(string id)
{
    string filePath = "classDataBase\\" + id + "\\listStudents.txt";
    ifstream inputFile(filePath);

    string studentName;
    this->studentCounter = 0;
    while (getline(inputFile, studentName))
    {
        student temp;
        temp.loadUserData(studentName);
        this->listStudents[this->studentCounter] = temp;
        this->studentCounter++;
    }
    inputFile.close();
}
void lecture::loadLectureData(string id)
{
    string filePath = "classDataBase\\" + id + "\\basicData.txt";
    ifstream inputFile(filePath);

    string line;
    if (getline(inputFile, line))
    {
        stringstream ss(line);
        string attribute;

        while (getline(ss, attribute, ','))
        {
            size_t colonPos = attribute.find(':');
            if (colonPos != string::npos)
            {
                string attr = attribute.substr(0, colonPos);
                string value = attribute.substr(colonPos + 1);

                attr.erase(remove(attr.begin(), attr.end(), ' '), attr.end());
                value.erase(remove(value.begin(), value.end(), ' '), value.end());

                if (attr == "id")
                {
                    this->id = value;
                }
                else if (attr == "nameL")
                {
                    this->lectureName = value;
                }
                else if (attr == "nameP")
                {
                    this->classProfessor = value;
                }
            }
        }
    }
    inputFile.close();
}

void lecture::updateStudentList(string id)
{
    string filePath = "classDataBase\\" + id + "\\listStudents.txt";
    ofstream outputFile(filePath);
    for (int i = 0; i < this->studentCounter; i++)
    {
        outputFile << this->listStudents[i].getId() << endl;
    }
    outputFile.close();
}

void lecture::loadHomeWorks(string id)
{
    string filePath = "classDataBase\\" + id + "\\listHomeWork.txt";
    ifstream inputFile(filePath);

    string hwName;
    this->homeWorkCounter = 0;
    while (getline(inputFile, hwName))
    {
        homeWork temp;
        temp.setQuestionName(hwName);
        this->listHomeWork[this->homeWorkCounter] = temp;
        this->homeWorkCounter++;
    }
    inputFile.close();
}
void lecture::updateHomeWorks(string id)
{
    string filePath = "classDataBase\\" + id + "\\listHomeWork.txt";
    ofstream outputFile(filePath);
    for (int i = 0; i < this->homeWorkCounter; i++)
    {
        outputFile << this->listHomeWork[i].getQuestionName() << endl;
    }
    outputFile.close();
}
bool lecture::checkStuExist(string id){
for(int i=0;i<this->studentCounter;i++){
    if(listStudents[i].getId().compare(id)==0){
        return true;
    }
}
return false;
}

void lecture::checkHomeWork()
{
    if (this->homeWorkCounter == 0)
    {
        cout << "There is no active home Work to check\n";
        return;
    }
    this->showHomeWorkList();
    cout << "Please select homeWork by it's Name\n";
    string input;
    getline(cin, input);
    homeWork newHw;
    newHw.setQuestionName(input);
    newHw.loadStudents(this->id);
    newHw.loadAPaths(this->id);
    newHw.loadGradess(this->id);
    if (newHw.getAwnserCount() == 0)
    {
        cout << "Nobody has submitted their answer yet\n";
        return;
    }
    newHw.showAnswersList();
    cout<<"Do you want to grade anyone?(yes or no)\n";
    string path;
    getline(cin,path);
    if(path.compare("yes")==0){
     cout<<"Give us the id of the student:\n";
     string idStu;
     getline(cin,idStu);   
        if(this->checkStuExist(idStu)==true){
          cout<<"What is your Grade for this stduent?\n";
          string gradeInput;
          getline(cin,gradeInput);
          newHw.editGrade(this->id,idStu,gradeInput);
        //  newHw
        cout<<"edited Successfully\n";
        }
    else {
        return;
    }
}
}