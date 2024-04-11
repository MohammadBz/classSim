#include <iostream>
#include <fstream>
#include <filesystem>
#include "professor.h"
#include "lecture.h"

using namespace std;

professor::professor()
{
    this->classCounter = 0;
}

string *professor::getListClass()
{
    return this->listClassName;
}
void professor::addClassName(string input)
{
    this->listClassName[this->classCounter].append(input);
    this->classCounter++;
}
int professor::getClassCounter()
{
    return this->classCounter;
}
void professor::setClassCounter(int input)
{
    this->classCounter = input;
}
void professor::showClassList()
{
    int classCount = 1;
    for (int i = 0; i < this->classCounter; i++, classCount++)
    {
        cout << "class number #" << classCount << "\nclass name:" << this->listClassName[i] << endl
             << "class ID:" << this->listClassName[i + 1] << endl;
        i++;
    }
}
void professor::loadClassName(string id)
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
void professor::writeClassName(string id)
{

    string filePath = "userDataBase\\" + id + "\\ClassData.txt";
    ofstream outputFile(filePath);

    for (int i = 0; i < this->classCounter; i++)
    {
        outputFile << this->listClassName[i] << endl;
    }

    outputFile.close();
}
string classGenerateID()
{
    ifstream inputFile("classIdHistory.txt");
    int currentID;
    inputFile >> currentID;
    inputFile.close();
    string id;
    ifstream inputFileAgain("classIdHistory.txt");
    getline(inputFileAgain, id);
    inputFileAgain.close();
    int newID = currentID + 1;

    ofstream outputFile("classIdHistory.txt");
    outputFile << newID;
    outputFile.close();
    return id;
}
void professor::createClass()
{
    string temp;
    cout << "Please give us the class name:\n";
    getline(cin, temp);
    addClassName(temp);
    string id = classGenerateID();
    addClassName(id);
    string fullName = this->getFirstName() + " " + this->getLastName();
    string filePath = "classDataBase\\" + id + "\\basicData.txt";
    string folderPath = "classDataBase\\" + id;
    filesystem::create_directory(folderPath);
    ofstream outputFile(filePath);
    outputFile << "id:" << id << ","
               << "nameL:" << temp << ",nameP:" << fullName << ",";
    outputFile.close();
    string Lpath = "classDataBase\\" + id + "\\listStudents.txt";
    ofstream outputFileL(Lpath);
    outputFileL.close();
    string HWpath = "classDataBase\\" + id + "\\listHomeWork.txt";
    ofstream outputFileHW(HWpath);
    outputFileHW.close();
    string homeWorkPath = "classDataBase\\" + id + "\\homeWork";
    filesystem::create_directory(homeWorkPath);
}

void classMenuText()
{
    cout << "-----1-add Stduent To class\n-----2-remove Student\n-----3-show Student List\n-----4-add HomeWork\n-----5-check HomeWork\n-----6-return to professor Panel\n";
}

void professor::classMenu(string id)
{
    string path;
    classMenuText();
    lecture inputClass;
    inputClass.loadLectureData(id);
    inputClass.loadStudents(id);
    cout << "Please choose by number\n";
    getline(cin, path);
    while (path.compare("6") != 0)
    {
        if (path.compare("1") == 0)
        {
            inputClass.addStudent();
            inputClass.updateStudentList(id);
            inputClass.loadStudents(id);
        }
        else if(path.compare("2")==0){
            inputClass.removeStudent();
        }
        else if (path.compare("3") == 0)
        {
            inputClass.showStudentList();
        }
        else if (path.compare("4") == 0)
        {
            inputClass.addHomeWork();
            inputClass.updateHomeWorks(id);
            inputClass.loadHomeWorks(id);
        }
        else if (path.compare("5") == 0)
        {
            inputClass.loadHomeWorks(id);
            inputClass.checkHomeWork();
        }
        classMenuText();
        cout << "Please choose by number\n";
        getline(cin, path);
    }
}
void professor::chooseClass()
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
    classMenu(inputId);
}
void professor::exitAllLecture()
{
    for (int i = 1; i < this->classCounter; i++)
    {
        lecture newLec;
        newLec.loadLectureData(this->listClassName[i]);
        cout << "for lecture " << newLec.getlectureName() << endl;
        newLec.changeProfessor("delete", "");
        newLec.updateLectureData(newLec.getId());
        i++;
    }
}
void professor::removeClassName(string classid)
{
    int index = 0;
    int i = 0;
    for (int i = 0; i < this->classCounter; i++)
    {
        if (this->listClassName[i].compare(classid) == 0)
        {
            index = i;
            break;
        }
    }
    if (i == this->classCounter)
    {
        cout << "you don't participate in that class\n";
        return;
    }
    index--;
    for (int j = index + 2; j < this->classCounter; j++, index++)
    {
        listClassName[index] = listClassName[j];
    }
    this->classCounter = this->classCounter - 2;
}
string findProfessorOfLecture(string classid, string *nameArr, int nameCount)
{
    for (int i = 0; i < nameCount; i++)
    {
        string tempId = nameArr[i];
        if (tempId[0] == '1')
        { // the user is professor
            professor temp;
            temp.loadUserData(tempId);
            temp.loadClassName(tempId);
            if (temp.getClassCounter() > 0&&temp.getStatus().compare("active")==0)
            {
                string *classList = temp.getListClass();
                for (int k = 0; k < temp.getClassCounter(); k++)
                {
                    if (classList[k].compare(classid) == 0)
                    {
                        return temp.getId();
                    }
                }
            }
        }
    }
    return "NULL";
}
void professor::restoreAllLecture(string *nameArr, int nameCount)
{
    for (int i = 1; i < this->classCounter; i++)
    {
        lecture newLec;
        newLec.loadLectureData(this->listClassName[i]);
        string oldProfId = findProfessorOfLecture(newLec.getId(), nameArr, nameCount);
        professor oldProf;
        oldProf.loadUserData(oldProfId);
        oldProf.loadClassName(oldProfId);
        oldProf.removeClassName(newLec.getId());
        oldProf.writeClassName(oldProfId);
        newLec.changeProfessor("restore", this->getId());
        i++;
    }
}