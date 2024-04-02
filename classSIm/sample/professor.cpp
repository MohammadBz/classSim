#include <iostream>
#include "professor.h"

using namespace std;

professor::professor(){
    this->classCounter=0;
}

string *professor::getListClass()
{
    return this->listClassName;
}
void professor::addClass(string input)
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
void professor::showClassList(){
        if(this->classCounter==0){
       cout<<"you don't have any active class\n";
        return ;
    }
     for(int i=0;i<this->classCounter;i++){
        cout << "class number #" << i + 1 << "\nclass name:"<<  this->listClassName[i]<<endl;
    } 
}