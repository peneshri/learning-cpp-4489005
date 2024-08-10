// Learning C++ 
// Challenge 06_03
// Upgrade to work with files, by Eduardo Corpeño 

#include <iostream>
#include <vector>
#include "records.h"
#include <fstream>

void initialize(StudentRecords&);

int main(){
    int id;
    StudentRecords SR;
    
    initialize(SR);

    SR.all_report_cards();
    
    std::cout << std::endl << std::endl;
    return (0);
}

void initialize(StudentRecords& srec){
    std::ifstream inFile;
    std::string str;

    inFile.open("students.txt");
    if (inFile.fail())
        std::cout << "Students file not found!" << std::endl;
    while (!inFile.eof()){
        getline(inFile, str);
        int sid = stoi(str);
        getline(inFile, str);
        srec.add_student(sid, str);
    }
    inFile.close();

    inFile.open("courses.txt");
    if (inFile.fail())
        std::cout << "Courses file not found!" << std::endl;
    while (!inFile.eof()){
        getline(inFile, str);
        int cid = stoi(str);
        getline(inFile, str);
        std::string cname = str;
        getline(inFile, str);
        int credits = stoi(str);
        srec.add_course(cid, cname, credits);
    }
    inFile.close();

    inFile.open("grades.txt");
    if (inFile.fail())
        std::cout << "Grades file not found!" << std::endl;
    while (!inFile.eof()){
        getline(inFile, str);
        int sid = stoi(str);
        getline(inFile, str);
        int cid = stoi(str);
        getline(inFile, str);
        char grade = str[0];
        srec.add_grade(sid, cid, grade);
    }
    inFile.close();
}
