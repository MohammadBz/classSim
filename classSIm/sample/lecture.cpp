#include <iostream>
#define Max_Student_Size 30
#include "lecture.h"
#include "student.h"

using namespace std;

lecture::lecture(string className,string professorName)
{
    this->classProfessor.append(professorName);
    this->lectureName.append(className);
    this->listStudents=new student[Max_Student_Size];
    this->studentCounter = 0;
}

student *lecture::getListStudent()
{
    return this->listStudents;
}
void lecture::addStudent(student inputSt)
{
    if(this->studentCounter<Max_Student_Size){
    this->listStudents[this->studentCounter] = inputSt;

    this->studentCounter++;
    }
    else{
        cout<< "you can't add anymore student!\n";
    }
}
int lecture::getStudentCounter(){
    return this->studentCounter;
}
void lecture::setStudentCounterr(int input){
    this->studentCounter=input;
}
string lecture::getProfessorClass(){
    return this->classProfessor;
} 

void lecture::showStudentList(){
    cout<<"Professor of this lecture:"<<this->classProfessor<<endl;
    if(this->studentCounter==0){
        cout<<"there is no student in this class\n";
        return ;
    }
    for(int i=0;i<this->studentCounter;i++){
        cout << "student number #" << i + 1 << ":\nfirst name:" << this->listStudents[i].getFirstName() << "\nlast name:" << this->listStudents[i].getLastName() <<"\nID:"<<this->listStudents[i].getId()<<endl;
    }
}
string lecture::getlectureName(){
   return this->lectureName;  
}