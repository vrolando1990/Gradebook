/*
Gradebook using composition and an array based list for students with object arrays inside
Gradebook holds students and each student has assignments, tests and a final.
 
*/

#include "Gbook.h"
#include <fstream>
#include <iostream>

using namespace std;

// Driver - Kicks off program and Menu
int main()
{
    
    // User selection used to navigate menu
    char selection;
    // Gradebook created
    Gbook one;
    
    // Loads the information from the last program ran.
    one.restart();
    
    // Do-While Q has not been selected
    do {
        cout << "\n --- Welcome to Gradebook --- " << endl << endl;
        cout << " --- SELECTION MENU --- " << endl << endl;
        cout << "S: New Semester\n"
             << "A: Add Student\n"
             << "P: Add Assignment Grade\n"
             << "T: Add Test Grade\n"
             << "F: Add Final Grade\n"
             << "C: Change Grade\n"
             << "G: Calculate Final Grades\n"
             << "O: Print Grades\n"
             << "L: List Length\n"
             << "Q: To Quit Program" << endl;
    
        // Selection is saved
        cin >> selection;

        // If statements to manage the users menu selection 
        if(selection == 'S' || selection == 's') {
            Gbook newOne; // Creates a new object 
            one = newOne; // Old Gradebook points to new gradebook which effectivly clears the old information
            one.newSemester();
        } else if(selection == 'A' || selection == 'a') {
            one.addStudent();
        } else if(selection == 'P' || selection == 'p') {
            one.addAssign();
        } else if(selection == 'T' || selection == 't') {
            one.addTest();
        } else if(selection == 'F' || selection == 'f') {
            one.addFinal();
        } else if(selection == 'C' || selection == 'c') {
            one.gradeChange();
        } else if(selection == 'G' || selection == 'g') {
            one.finalGrades();
        } else if(selection == 'O' || selection == 'o') {
            one.outputData();
        } else if(selection == 'L' || selection == 'l') {
            cout << one.getLength() << endl;
        }

    } while(selection != 'Q' && selection != 'q');

    // Run quit file write for load later
    one.quit();

    return 0;
}