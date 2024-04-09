#include <iostream>
#pragma once
#include "human.h"
#include <string>
#define Max_Size_Class 10
using namespace std;

class student : public human
{
private:
    string listClassName[Max_Size_Class];
    int classCounter;

public:
    student();
    string *getListClass();
    void addClass(string input);
    int getClassCounter();
    void setClassCounter(int input);
    void showClassList();
    void loadClassName(string id);
    void writeClassName(string id);
    void chooseClass();
};
