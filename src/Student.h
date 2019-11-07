/*
Gradebook using composition and an array based list for students with object arrays inside
Gradebook holds students and each student has assignments, tests and a final.

*/

// Inlcude gaurd
#ifndef STUDENT_H
#define STUDENT_H

#include "Assignment.h"
#include "Final.h"
#include "Test.h"
#include <string>

using namespace std;

// Max Assignment and Tests that are allowed into the program used for arrrays
const int MAX_ASSIGN = 6;
const int MAX_TEST = 4;

// Class STUDENT oject to hold a STUDENTS assignments, tests and final test (Gbook has Students - has-a relationship)
class Student
{
public:
    // Constructor
    Student();
    // Destructor
    ~Student();
    
    // Prototypes for adding a students assignments, tests and final
    void addAssignment(int, double);
    void addTest(int, double);
    void addFinal(double);

    // First name Setter/Getter
    void setFirstName(string);
    string getFirstName();
    
    // Last name Setter/Getter
    void setLastName(string);
    string getLastName();
    
    // Id Setter/Getter
    void setId(int);
    int getId();
    
    // Assignments average grade Setter/Getter
    void setAssignAveGrade(double);
    double getAssignAveGrade();

    // Tests average grade Setter/Getter
    void setTestAveGrade(double);
    double getTestAveGrade();
    
    // Students Final grade Setter/Getter
    void setTotalFinal(double);
    double getTotalFinal();
    
    // Declaring Array of Object pointers
    Assignment* assignment;
    Test* tests;
    
    // Creating a Final object
    Final studFinal;

private:
    // Grade holders
    double assignAveGrade = 0;
    double testAveGrade = 0;
    double totalFinal = 0;

    // Counter for total amount of assignments and tests
    int assignLength;
    int testLength;

    // Name holders
    string firstName;
    string lastName;
    
    // Student Id number holder 
    int studId;
};

// Constructor to initiate object arrays and assignments and test lengths
Student ::Student()
{
    assignLength = 0;
    testLength = 0;
    assignment = new Assignment[MAX_ASSIGN];
    tests = new Test[MAX_TEST];
}


// ------------------ Adds a new Assignment to Assignments array ------------------- //

void Student ::addAssignment(int aNum, double aGrade)
{
    assignment[assignLength].setNumber(aNum); // Calls assignment number setter and passes value
    assignment[assignLength].setGrade(aGrade); // Calls assignment grade setter and passes value
    assignLength++; // Adds 1 to assignment count
}

// ------------------ Adds a new Test to Tests array ------------------- //

void Student ::addTest(int tNum, double tGrade)
{
    tests[testLength].setNumber(tNum); // Calls test number setter and passes value
    tests[testLength].setGrade(tGrade); // Calls test number setter and passes value
    testLength++; // Adds 1 to test count
}

// ------------------ Adds final by setting a final grade ------------------- //

void Student ::addFinal(double fGrade)
{
    studFinal.setGrade(fGrade);  // Calls final grade setter and passes value
}


// ------------------ First name Setter/Getter ------------------- //

void Student ::setFirstName(string name)
{
    firstName = name;
}

string Student ::getFirstName()
{
    return firstName;
}

// ------------------ Last name Setter/Getter ------------------- //

void Student ::setLastName(string name)
{
    lastName = name;
}

string Student ::getLastName()
{
    return lastName;
}

// ------------------ Id Setter/Getter ------------------- //

void Student ::setId(int id)
{
    studId = id;
}

int Student ::getId()
{
    return studId;
}

// ------------------ Assignments average Grade Setter/Getter ------------------- //

void Student ::setAssignAveGrade(double grade)
{
    assignAveGrade = grade;
}

double Student ::getAssignAveGrade()
{
    return assignAveGrade;
}

// ------------------ Tests average Grade Setter/Getter ------------------- //

void Student ::setTestAveGrade(double grade)
{
    testAveGrade = grade;
}

double Student ::getTestAveGrade()
{
    return testAveGrade;
}

// ------------------ Students Final Grade Setter/Getter ------------------- //

void Student ::setTotalFinal(double grade)
{
    totalFinal = grade;
}

double Student ::getTotalFinal()
{
    return totalFinal;
}

// Object array destructor is called from Gbook
Student :: ~Student(){
    delete[] assignment;
    delete[] tests;
}

#endif
