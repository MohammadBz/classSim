#include <iostream>
#pragma once
#include "human.h"
#define Max_Size_Class_T 30

using namespace std;

class professor : public human
{
private:
    string listClassName[Max_Size_Class_T];
    int classCounter;

public:
    professor();
    string *getListClass();
    void addClassName(string input);
    int getClassCounter();
    void setClassCounter(int input);
    void showClassList();
    void loadClassName(string id);
    void writeClassName(string id);
    void createClass();
    void classMenu(string id);
    void chooseClass();
    void exitAllLecture();
    void restoreAllLecture(string *nameArr,int nameCount);
    void removeClassName(string classid);
};
