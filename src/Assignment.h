/*
Gradebook using composition and an array based list for students with object arrays inside
Gradebook holds students and each student has assignments, tests and a final.
 
*/

// Inlcude gaurd
#ifndef ASSIGNMENT_H
#define ASSIGNMENT_H

// Class ASSIGNMENT oject for ASSIGNMENT grades (student has assignments - has-a relationship)
class Assignment{
public:
    // Assignment number setter/getter prototypes
    void setNumber(int);
    int getNumber() const;
    
    // Assignment grade setter/getter prototypes
    void setGrade(double);
    double getGrade() const;

private:
    // Holds students assignment number 
    int number = 0;
    // Holds students assignment grade 
    double grade = 0;
};

// ------------------ Assignment number setter/getter function ------------------- //

void Assignment :: setNumber(int num){
    number = num;
}

int Assignment :: getNumber() const{
    return number;
}

// ------------------ Assignment grade setter/getter function ------------------- //

void Assignment :: setGrade(double num){
    grade = num;
}

double Assignment :: getGrade() const{
    return grade;
}

#endif
