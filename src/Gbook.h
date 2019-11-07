/*
Gradebook using composition and an array based list for students with object arrays inside
Gradebook holds students and each student has assignments, tests and a final.
 
*/


// Inlcude gaurd
#ifndef GBOOK_H
#define GBOOK_H

#include "Student.h"
#include <fstream>
#include <iostream>

using namespace std;

// Max student capacity
const long MAX_LENGTH = 9999;

class Gbook
{
public:
    // Constructor
    Gbook();
    
    // Prototype
    void newSemester(); // Creates a new semester (Clears out the old)
    void addStudent(); // Adds a student to semester
    void addAssign(); // Adds an assignment and grade to student
    void addTest(); // Adds a test and grade to atudent
    void addFinal(); // Adds a final test grade to student
    int getLength() const; // Returns length
    void gradeChange() const; // Changes a students grade 
    void finalGrades(); // Calculates students final grades
    void outputData() const; // Prints all the information 
    void quit() const; // Quits program and creates program file for restart 
    void restart(); // Restarts the program using the information from the file quite created

private:
    void sort(int) const; // Sorting function

    // Length of added students
    int length;
    // Initiating a student array
    Student* student;

    // number of assignments
    int numAssign = 0;
    // Total Assignment weight
    double assignWeight = 0;

    // number of test
    int numTest = 0;
    // Total test weight
    double testWeight = 0;

    // number of final
    int numFinal = 0;
    // Total final weight
    double finalWeight = 0;

    // Count of totals entered each time a new assignment or program is created
    int totalAssign = 0;
    int totalTest = 0;

    // To keep track of weight when new semester is created
    double totalWeight = 0;
};

Gbook ::Gbook()
{
    // Initiates to zero when an object is created
    length = 0;
    // Array is created
    student = new Student[MAX_LENGTH];
}

// Creates a new semester
void Gbook ::newSemester()
{
    // keep doing the inside block till until weight equals 100%
    do {

        // Total weight is set to 100%
        totalWeight = 100;

        // Assignment total and weight
        cout << "Enter # of programming Assignments [Range: 0 - 6]: " << endl;
        do {
            cin >> numAssign;
        } while(numAssign < 0 || numAssign > 6);

        cout << "Enter total weight for Assignments: " << endl;
        cin >> assignWeight;

        // Subtracts the entered assignment weight from the total weight
        totalWeight = totalWeight - assignWeight;

        // Test total and weight
        cout << "Enter # of tests [Range: 0 - 4] : " << endl;
        do {
            cin >> numTest;
        } while(numTest < 0 || numTest > 4);

        cout << "Enter total weight for tests [Must be " << totalWeight << " or less]: " << endl;
        cin >> testWeight;

        // Subtracts the entered test weight from the total weight
        totalWeight = totalWeight - testWeight;

        // Final total and weight
        cout << "Enter # of finals [Range: 0 - 1]: " << endl;

        // Only save the grade if it there is a final test
        do {
            cin >> numFinal;
        } while(numFinal < 0 || numFinal > 1);

        // If there is a final then enter the weight for that final
        if(numFinal == 1) {
            cout << "Enter the total weight for final Exam [Due to the weight of other activities the weight must be "
                 << totalWeight << " no less]: " << endl;
            cin >> finalWeight;
            // Subtracts the entered test weight from the total weight
            totalWeight = totalWeight - finalWeight;
        }

        // If the total weight does not equal 100% to total weight is reset and the do/while condition will cause the
        // whole proccess to repeat
        if(totalWeight != 0) {
            cout << "\nTotal weight must add up to 100%. Try again. " << endl << endl;
            totalWeight = 100;
        }

    } while(totalWeight != 0);
}

// Adds a student to semester/Gradebook
void Gbook ::addStudent()
{
    // Bool used for adding another student question
    bool selection = false;
    // Holds the users selection
    char choice;

    // Loop to keep adding students
    do {
        // Enter students first name
        string name;
        cout << "Enter Students first name: ";
        cin >> name;
        student[length].setFirstName(name);

        // Enter students last name (Length us used to iterate through student)
        cout << "Enter " << student[length].getFirstName() << "'s last name: ";
        cin >> name;
        student[length].setLastName(name);

        // String holds the entire name (Length us used to iterate through student)
        string fullName = student[length].getFirstName() + " " + student[length].getLastName();

        // Do while ID is out of desired rage
        do {
            // Enter students ID
            int id;
            cout << "Enter " << fullName << "'s ID: ";
            cin >> id;
            student[length].setId(id);
        } while(student[length].getId() < 1 || student[length].getId() > 9999);

        // Update length because a new student had been created
        length++;

        // Question to add a new student
        cout << "Would you like to add another student [Y/N]? ";
        cin >> choice;

        // Depeding on users selction of the above the selection bool will be updated and trigger the do while loop
        if(choice == 'Y' && choice == 'y') {
            selection = false;
        } else if(choice == 'N' || choice == 'n') {
            selection = true;
        }

    } while(!selection);
    
    sort(0);
}

// Add a assignment to each student and their grade for the assignment
void Gbook ::addAssign()
{
    
    // Assignment number and grade holders
    int num;
    int grade;
    
    // Do while number entered is out of the total number of assignment range
    do {
        // User prompt for assignment number
        cout << "Enter the assignment number [Existing assignments " << totalAssign << "]: " << endl;
        cin >> num;
    
        // Check if assignment number already exists
        for(int i = 0; i < length; i++) {
            for(int j = 0; j < numAssign; j++) {
                // If assignmnet number exists number is given a -1 so do while is failed 
                if(student[i].assignment[j].getNumber() == num) {
                    num = -1;
                    cout << "Sorry, the assignment number you have chosen already exists. Choose another!" << endl;
                }
            }
        }
    } while(num < 1 || num > numAssign);
    
    // Counter is updated 
    totalAssign++;
    
    // Asks user to enter a grade for each student and saves it
    for(int i = 0; i < length; i++) {
        cout << "Enter " << student[i].getFirstName() << " " << student[i].getLastName() << "'s grade for assignment "
             << num << endl;
        cin >> grade;

        student[i].addAssignment(num, grade);
    }
}

// Add a test to each student and their grade for the test
void Gbook ::addTest()
{
    
    // Test number and grade holders
    int num;
    int grade;

    // Do while number entered is out of the total number of test range
    do {
        // User prompt for test number
        cout << "Enter the test number [Existing test " << totalTest << "]: " << endl;
        cin >> num;
        
        // Check if test number already exists
        for(int i = 0; i < length; i++) {
            for(int j = 0; j < numTest; j++) {
                // If test number exists number is given a -1 so do while is failed 
                if(student[i].tests[j].getNumber() == num) {
                    num = -1;
                    cout << "Sorry, the test number you have chosen already exists. Choose another!" << endl;
                }
            }
        }

    } while(num < 1 || num > numTest);
    
    // Counter is updated 
    totalTest++;
    
    // Asks user to enter a grade for each student and saves it
    for(int i = 0; i < length; i++) {
        cout << "Enter " << student[i].getFirstName() << " " << student[i].getLastName() << "'s grade for test " << num
             << endl;
        cin >> grade;

        // student[i].setMaxTest(numTest);
        student[i].addTest(num, grade);
    }
}

void Gbook ::addFinal()
{
    // Only runs if the class is having a test
    if(numFinal != 0) {
        
        // Checks if a grade had already been entered
        for(int i = 0; i < length; i++) {
            if(student[i].studFinal.getGrade() != 0) {
                cout << "You have already entered a Final grade! " << endl;
                return;
            }
        }
        
        // Used to hold the grade the user entered for final 
        double finalGrade;
        
        // Asks for the final grade of each student
        for(int i = 0; i < length; i++) {
            cout << "Enter " << student[i].getFirstName() << " " << student[i].getLastName() << "'s grade for final "
                 << endl;
            cin >> finalGrade;

            student[i].addFinal(finalGrade);
        }
        // Prompt letting user kno that there is not test
    } else {
        cout << "You mentioned you were not going to have a final." << endl;
        return; // Returns to menu
    }
}

// Sorts Array based list Alphabetically or Numerically 
void Gbook ::sort(int choice) const
{

    int j = 0; // Counter
    bool swap; // Bool to 
    Student temp;
    
    // If statement to manage which sort to run
    if(choice == 0) {
    
    // Alphabetically sort
        while(swap) {
            swap = false;
            j++;

            for(int i = 0; i < length - j; i++) {
                if(student[i].getFirstName() > student[i + 1].getFirstName()) {
                    temp = student[i];
                    student[i] = student[i + 1];
                    student[i + 1] = temp;
                    swap = true;
                }
            }
        }
    // Numerically sort based on student ID
    } else if(choice == 1) {
    j = 0;
    
    // Numerically sort
        while(swap) {
            swap = false;
            j++;

            for(int i = 0; i < length - j; i++) {
                if(student[i].getId() < student[i + 1].getId()) {
                    temp = student[i];
                    student[i] = student[i + 1];
                    student[i + 1] = temp;
                    swap = true;
                }
            }
        }
    }
}

// Return total number of students
int Gbook ::getLength() const
{
    return length;
}

// Changes a students grade 
void Gbook ::gradeChange() const
{
    
    int searchID; // Id being searched for place holder 
    double newGrade; // new grade holder 
    char selection; // User memu selection
    int selectionNum; // Test or Assignment selection holder

    bool found = false; // Bool for searching algorithm
    int foundLoc = 0; // Found location holder

    // Do until an existing student ID is entered
    do {
        
        // Ask for a user id
        cout << "To change a student grade please enter the Student ID: ";
        cin >> searchID;
        
        // Look for student
        for(int i = 0; i < length; i++) {
            if(student[i].getId() == searchID) {
                found = true;
                foundLoc = i;
            }
        }

    } while(!found);
    
    // Option menu for user
    cout << "------- Which grade would you like to change -------" << endl;
    cout << "MENU: " << endl;

    cout << "P: Program\n"
         << "T: Test\n"
         << "F: Final\n";
         
    // Holds menu selection
    cin >> selection;
    
    // Do while grade entered is out of range 
    do {
        // Prompt for the new grade
        cout << "Please input the students new grade: " << endl;
        cin >> newGrade;

    } while(newGrade < 0 || newGrade > 100);

    // Assignment grade is being changed
    if(selection == 'P' || selection == 'p') {
        found = false;
        // Do until assignment entered exists
        do {
            // Assignment number requested 
            cout << "Please enter program assignment number: ";
            cin >> selectionNum;
            
            // Assignment search 
            for(int i = 0; i < numAssign; i++) {
                if(student[foundLoc].assignment[i].getNumber() == selectionNum) {
                    found = true;
                    student[foundLoc].assignment[i].setGrade(newGrade);
                }
            }
        } while(!found);
    // Test grade is being changed
    } else if(selection == 'T' || selection == 't') {
        found = false;
        // Do until test entered exists
        do {
            // Test number requested 
            cout << "Please enter test number: ";
            cin >> selectionNum;
            
            // Test search 
            for(int i = 0; i < numTest; i++) {
                if(student[foundLoc].tests[i].getNumber() == selectionNum) {
                    found = true;
                    student[foundLoc].tests[i].setGrade(newGrade);
                }
            }
        } while(!found);
    // Test grade is being changed
    } else if(selection == 'F' || selection == 'f') {
        student[foundLoc].addFinal(newGrade); // Sets new grade 
    }
    
    // Finished prompt
    cout << "\nGrade changed successfully: " << endl << endl;
}

// Final grade calulation 
void Gbook ::finalGrades()
{
    // Calulcates the total assignment average for each student  
    for(int i = 0; i < length; i++) {
        for(int j = 0; j < numAssign; j++) {
            // Adds assignment grades
            student[i].setAssignAveGrade((student[i].getAssignAveGrade() + student[i].assignment[j].getGrade())); 
        }
        
        // Divides assignment grade total by total number of assignments
        student[i].setAssignAveGrade((student[i].getAssignAveGrade() / numAssign));
    }

    // Calulcates the total test average for each student 
    for(int i = 0; i < length; i++) {
        for(int j = 0; j < numTest; j++) {
            // Adds test grades
            student[i].setTestAveGrade((student[i].getTestAveGrade() + student[i].tests[j].getGrade()));
        }
        // Divides test grade total by total number of test
        student[i].setTestAveGrade((student[i].getTestAveGrade() / numTest));
    }
    
    // Calulcates the students final grade 
    for(int i = 0; i < length; i++) {
        
        // (Assign Total Avrg.) * (Assign Weight/100) + (Test Total Avrg.) * (Test Weight/100) + (Final Test grade.) * (Final Test Weight/100)
        student[i].setTotalFinal(((student[i].getTestAveGrade() * (assignWeight / 100)) +
            (student[i].getAssignAveGrade() * (testWeight / 100)) +
            (student[i].studFinal.getGrade() * (finalWeight / 100))));
    }
    
    // Prompt as to hen calculations have completed
    cout << "\nFinal grades have been calculated. " << endl << endl;
}

// Prints Gradebook for user 
void Gbook ::outputData() const
{
    // Place holder for sorting menu option
    int choice;
    
    // Sorting menu - Do while input is not in the menu
    do {
        // Sorting menu
        cout << "\nHow would you like to print out Gradebook?\n\n"
             << "0: Print Alphabetically\n"
             << "1: In Order by ID\n";
        cin >> choice;
    } while(choice < 0 || choice > 1);
    
    // Sort accordingly
    sort(choice);
    
    // Create file to read too
    ofstream outFile;
    outFile.open("C:\\Users\\vrola\\OneDrive\\Documents\\CPPWorkspace\\SummerClass\\Assign_4_New\\Grades.out");
    
    // Writes the following information to file
    outFile << "---- Gradebook Data ----" << endl << endl;

    outFile << "Number of Programs: " << numAssign << " Weight: " << assignWeight << endl;
    outFile << "Number of Tests: " << numTest << " Weight: " << testWeight << endl;
    outFile << "Number of Finals: " << numFinal << " Weight: " << finalWeight << endl << endl;

    outFile << "Total number of student: " << length << endl << endl;
    
    // Loop writes students name, id, each assignment, test and final number and grade, plus total grade information
    for(int i = 0; i < length; i++) {
        outFile << student[i].getFirstName() << " " << student[i].getLastName() << " Student ID: " << student[i].getId() << endl << endl;

        for(int j = 0; j < numAssign; j++) {
            outFile << "Program # " << student[i].assignment[j].getNumber() << ": " << student[i].assignment[j].getGrade()
                    << endl;
        }

        for(int j = 0; j < numTest; j++) {
            outFile << "Test # " << student[i].tests[j].getNumber() << ": " << student[i].tests[j].getGrade() << endl;
        }

        outFile << endl;

        if(numFinal != 0) {
            outFile << "Final Test Grade: " << student[i].studFinal.getGrade() << endl;
        }

        outFile << "Program average: " << student[i].getAssignAveGrade() << endl;
        outFile << "Test average: " << student[i].getTestAveGrade() << endl;
        outFile << "Final grade: " << student[i].getTotalFinal() << endl << endl;
    }
    
    // Closes writing file
    outFile.close();
}

// When user quits the information is saved to Grades.dat to read back in when program is ran again 
// Prints a simplified format for easy program reading 
void Gbook ::quit() const
{
    // Create file to read too
    ofstream outFile;
    outFile.open("C:\\Users\\vrola\\OneDrive\\Documents\\CPPWorkspace\\SummerClass\\Assign_4_New\\Grades.dat");

    // Writes number of assignments and weights for each
    outFile << numAssign << " " << assignWeight << endl;
    outFile << numTest << " " << testWeight << endl;
    outFile << numFinal << " " << finalWeight << endl << endl;

    // Current totals counter 
    outFile << totalAssign << endl;
    outFile << totalTest << endl;
    outFile << totalWeight << endl;
    
    // Writes total amount of students before closed
    outFile << length << endl << endl;

    // Writes Name, id, Final grade, Averages, assignments, tests and final information  
    for(int i = 0; i < length; i++) {

        outFile << student[i].getFirstName() << " " << student[i].getLastName() << " " << student[i].getId() << " "
                << student[i].getTotalFinal() << endl;
        outFile << student[i].getAssignAveGrade() << " " << student[i].getTestAveGrade() << endl;

        for(int j = 0; j < numAssign; j++) {
            outFile << student[i].assignment[j].getNumber() << " " << student[i].assignment[j].getGrade() << endl;
        }

        for(int j = 0; j < numTest; j++) {
            outFile << student[i].tests[j].getNumber() << " " << student[i].tests[j].getGrade() << endl;
        }

        if(numFinal != 0) {
            outFile << student[i].studFinal.getGrade() << endl;
        }
    }
    
    // Closes writing file
    outFile.close();

    // Because program quit the destructor is called to delete allocated memory for test and assignment objects 
    for(int i = 0; i < length; i++) {
        student[i].~Student();
    }
}

// Reads all the information in Grade.dat that was created when program quit back into the program
void Gbook ::restart()
{
    
    // Will read file as long as the file exists  if it doesnt return to menu (User wont notice this)
    ifstream inFile("C:\\Users\\vrola\\OneDrive\\Documents\\CPPWorkspace\\SummerClass\\Assign_4_New\\Grades.dat");
    if(!inFile) {
        return;
    }
    
    int assign;
    inFile >> assign;
    numAssign = assign;
    inFile >> assignWeight;

    int test;
    inFile >> test;
    numTest = test;
    inFile >> testWeight;

    int finals;
    inFile >> finals;
    numFinal = finals;
    inFile >> finalWeight;

    inFile >> totalAssign;
    inFile >> totalTest;
    inFile >> totalWeight;

    int numLength;
    inFile >> numLength;
    length = numLength;

    double x = 0;
    string name;
    int id = 0;
    double total = 0;

    for(int i = 0; i < numLength; i++) {

        inFile >> name;
        student[i].setFirstName(name);

        inFile >> name;
        student[i].setLastName(name);

        inFile >> id;
        student[i].setId(id);

        inFile >> total;
        student[i].setTotalFinal(total);
        
        inFile >> x;
        inFile >> x;

        for(int j = 0; j < assign; j++) {
            inFile >> x;
            student[i].assignment[j].setNumber(x);
            inFile >> total;
            student[i].assignment[j].setGrade(total);
        }

        for(int j = 0; j < test; j++) {
            inFile >> x;
            student[i].tests[j].setNumber(x);
            inFile >> total;
            student[i].tests[j].setGrade(total);
        }

        if(finals != 0) {
            inFile >> total;
            student[i].studFinal.setGrade(total);
        }
    }
}

#endif
