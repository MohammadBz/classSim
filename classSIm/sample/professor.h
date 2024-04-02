#include <iostream>
#pragma once
#include "human.h"
#define Max_Size_Class_T 15

using namespace std;

class professor : public human
{
private:
    string listClassName[Max_Size_Class_T];
    int classCounter;

public:
    professor();
    string *getListClass();
    void addClass(string input);
    int getClassCounter();
    void setClassCounter(int input);
    void showClassList();
};
