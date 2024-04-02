#include <iostream>
#include "student.h"

using namespace std;

student::student(){
    this->classCounter=0;
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
void student::showClassList(){
        if(this->classCounter==0){
       cout<<"student doesn't paticipate in any class\n";
        return ;
    }
     for(int i=0;i<this->classCounter;i++){
        cout << "class number #" << i + 1 << "\nclass name:"<<  this->listClassName[i]<<endl;
    } 
}
