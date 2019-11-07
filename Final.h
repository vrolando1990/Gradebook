/*
Gradebook using composition and an array based list for students with object arrays inside
Gradebook holds students and each student has assignments, tests and a final.
*/

// Inlcude gaurd
#ifndef FINAL_H
#define FINAL_H

// Class FINAL oject for FINAL TEST grade (student has-a final - has-a relationship)
class Final
{

public:
    // Final test grade setter/getter prototypes
    void setGrade(double num);
    double getGrade() const;

private:
    // Holds students final test grade 
    double grade = 0;
};

// ------------------ Final test grade setter/getter function ------------------- //
void Final ::setGrade(double num)
{
    grade = num;
}

double Final ::getGrade() const
{
    return grade;
}

#endif