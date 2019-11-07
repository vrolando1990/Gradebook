/*
Gradebook using composition and an array based list for students with object arrays inside
Gradebook holds students and each student has assignments, tests and a final.
 
*/

// Inlcude gaurd
#ifndef TEST_H
#define TEST_H

// Class TEST oject for TEST grades (student has tests - has-a relationship)
class Test{
public:
    // Test number setter/getter prototypes
    void setNumber(int);
    int getNumber() const;
    
    // Test grade setter/getter prototypes
    void setGrade(double);
    double getGrade() const;
    
private:
    // Holds students test number 
    int number = 0;
    // Holds students test grade 
    double grade = 0;
    
};

// ------------------ Test number setter/getter function ------------------- //

void Test :: setNumber(int num){
    number = num;
}

int Test :: getNumber() const{
    return number;
}

// ------------------ Test grade setter/getter function ------------------- //

void Test :: setGrade(double num){
    grade = num;
}

double Test :: getGrade() const{
    return grade;
}

#endif
