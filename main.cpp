// ------------- FILE HEADER -------------
// Author: Yusong Jin
// Assignment: 8
// Date: August 19
// Description: Student Grade Calculator
// Sources: 


// ------------- ZYBOOKS SCORES -------------
// https://learn.zybooks.com/zybook/PCCCS161ASummer25
// Chapter: 9
// Participation: 100%
// Challenge: 100%
// Labs: 100%


// ------------- DISCORD POSTS -------------
// https://discord.com/invite/URYKKf8YHm
// Count: 1
// Links (Optional): 


// ------------- DESIGN DOCUMENT -------------
// A. INPUT [yes/no]: yes
// B. OUTPUT [yes/no]: yes
// C. CALCULATIONS [yes/no]: yes
// D. LOGIC and ALGORITHMS [yes/no]: yes
//    (Optional) flow chart link or file name: 


// ------------- TESTING -------------
// PASS ALL GIVEN SAMPLE RUN TESTS [yes/no]: yes
// (Optional) Additional tests count:   


// ------------- CODE -------------
#include <iostream>
#include <iomanip>
#include <string>
#include <limits>
using namespace std;

// Constants
const double ASSIGNMENT_WEIGHT = 0.6;
const double EXAM_WEIGHT = 0.2;

// Function prototypes
void welcome();
int readInt(string prompt);
void readScore(string prompt, double &num);
double assignAverage(int numAssigns);
void getInput(double &midtermScore, double &finalExamScore);
double calcFinalScore(double assignAvg, double midterm, double final);
void calcLetterGrade(double finalScore, char &letter);

int main() {
    welcome();
    
    int numAssignments = readInt("Enter the number of assignments (0 to 10): ");
    double assignAvg = assignAverage(numAssignments);
    
    double midtermScore, finalExamScore;
    getInput(midtermScore, finalExamScore);
    
    double finalScore = calcFinalScore(assignAvg, midtermScore, finalExamScore);
    
    char letterGrade;
    calcLetterGrade(finalScore, letterGrade);
    
    cout << fixed << setprecision(1);
    cout << "Your Final Numeric score is " << finalScore << endl;
    cout << "Your Final Grade is " << letterGrade << endl;
    cout << "Thank you for using my Grade Calculator!" << endl;
    
    return 0;
}

// Function implementations
void welcome() {
    cout << "Welcome to my Final Grade Calculator!" << endl;
    cout << "Please enter the following information and I will calculate your Final Numerical Grade and Letter Grade for you!" << endl;
    cout << "The number of assignments must be between 0 and 10." << endl;
    cout << "All scores entered must be between 0 and 4." << endl;
}

int readInt(string prompt) {
    int value;
    while (true) {
        cout << prompt;
        cin >> value;
        
        if (cin.fail() || value < 0 || value > 10) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Illegal Value! Please try again!!" << endl;
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return value;
        }
    }
}

void readScore(string prompt, double &num) {
    while (true) {
        cout << prompt;
        cin >> num;
        
        if (cin.fail() || num < 0 || num > 4) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Illegal Score! Please try again!" << endl;
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return;
        }
    }
}

double assignAverage(int numAssigns) {
    double total = 0;
    for (int i = 1; i <= numAssigns; i++) {
        double score;
        readScore("Enter score " + to_string(i) + ": ", score);
        total += score;
    }
    return (numAssigns > 0) ? total / numAssigns : 0;
}

void getInput(double &midtermScore, double &finalExamScore) {
    readScore("Enter your midterm exam score: ", midtermScore);
    readScore("Enter your final exam score: ", finalExamScore);
}

double calcFinalScore(double assignAvg, double midterm, double final) {
    return (assignAvg * ASSIGNMENT_WEIGHT) + 
           (midterm * EXAM_WEIGHT) + 
           (final * EXAM_WEIGHT);
}

void calcLetterGrade(double finalScore, char &letter) {
    if (finalScore >= 3.3) {
        letter = 'A';
    } else if (finalScore >= 2.8) {
        letter = 'B';
    } else if (finalScore >= 2.0) {
        letter = 'C';
    } else if (finalScore >= 1.2) {
        letter = 'D';
    } else {
        letter = 'F';
    }
}




// ------------- DESIGN -------------
/* 
Program Name: Grade Calculations using Reference Parameters

Program Description: Student Grade Calculator

Design:
A. INPUT
Define the input variables including name data type. 
int numAssignments;
double assignmentScore;
double midtermScore;
double finalExamScore;

B. OUTPUT
Define the output variables including data types. 
double assignAvg;
double finalScore;
char letterGrade;

C. CALCULATIONS
Describe calculations used by algorithms in step D.  
List all formulas.
assignAvg = (sum of all assignment scores) / numAssignments;
finalScore = (assignAvg * 0.6) + (midtermScore * 0.2) + (finalExamScore * 0.2)

D. LOGIC and ALGORITHMS
Design the logic of your program using pseudocode or flowcharts. 
Use conditionals, loops, functions or array constructs.
List the steps in transforming inputs into outputs.
BEGIN
BEGIN PROGRAM
    // Define constants
    CONSTANT ASSIGNMENT_WEIGHT = 0.6
    CONSTANT EXAM_WEIGHT = 0.2
    
    // Function prototypes
    FUNCTION welcome(): VOID
    FUNCTION readInt(prompt: string): INT
    FUNCTION readScore(prompt: string, REF num: double): VOID
    FUNCTION assignAverage(numAssigns: INT): DOUBLE
    FUNCTION getInput(REF midtermScore: double, REF finalExamScore: double): VOID
    FUNCTION calcFinalScore(assignAvg: double, midterm: double, final: double): DOUBLE
    FUNCTION calcLetterGrade(finalScore: double, REF letter: char): VOID

FUNCTION main():
    CALL welcome()
    
    numAssignments = CALL readInt("Enter the number of assignments (0 to 10): ")
    
    assignAvg = CALL assignAverage(numAssignments)
    
    DECLARE midtermScore, finalExamScore: double
    CALL getInput(midtermScore, finalExamScore)
    
    finalScore = CALL calcFinalScore(assignAvg, midtermScore, finalExamScore)
    
    DECLARE letterGrade: char
    CALL calcLetterGrade(finalScore, letterGrade)
    
    PRINT "Your Final Numeric score is " + finalScore (formatted to 1 decimal)
    PRINT "Your Final Grade is " + letterGrade
    PRINT "Thank you for using my Grade Calculator!"
END FUNCTION

FUNCTION welcome():
    PRINT welcome messages and instructions
END FUNCTION

FUNCTION readInt(prompt: string): INT
    DO
        PRINT prompt
        READ input
        IF input is not integer OR input < 0 OR input > 10 THEN
            CLEAR cin error state
            DISCARD invalid input
            PRINT "Illegal Value! Please try again!!"
        ELSE
            RETURN input
        END IF
    WHILE true
END FUNCTION

FUNCTION readScore(prompt: string, REF num: double): VOID
    DO
        PRINT prompt
        READ input
        IF input is not number OR input < 0 OR input > 4 THEN
            CLEAR cin error state
            DISCARD invalid input
            PRINT "Illegal Score! Please try again!"
        ELSE
            num = input  // Update reference parameter
            RETURN
        END IF
    WHILE true
END FUNCTION

FUNCTION assignAverage(numAssigns: INT): DOUBLE
    total = 0
    FOR i FROM 1 TO numAssigns
        DECLARE score: double
        CALL readScore("Enter score " + i + ": ", score)  // score passed by reference
        total = total + score
    END FOR
    IF numAssigns > 0 THEN
        RETURN total / numAssigns
    ELSE
        RETURN 0
    END IF
END FUNCTION

FUNCTION getInput(REF midtermScore: double, REF finalExamScore: double): VOID
    CALL readScore("Enter your midterm exam score: ", midtermScore)
    CALL readScore("Enter your final exam score: ", finalExamScore)
END FUNCTION

FUNCTION calcFinalScore(assignAvg: double, midterm: double, final: double): DOUBLE
    RETURN (assignAvg * ASSIGNMENT_WEIGHT) + 
           (midterm * EXAM_WEIGHT) + 
           (final * EXAM_WEIGHT)
END FUNCTION

FUNCTION calcLetterGrade(finalScore: double, REF letter: char): VOID
    IF finalScore >= 3.3 THEN
        letter = 'A'
    ELSE IF finalScore >= 2.8 THEN
        letter = 'B'
    ELSE IF finalScore >= 2.0 THEN
        letter = 'C'
    ELSE IF finalScore >= 1.2 THEN
        letter = 'D'
    ELSE
        letter = 'F'
    END IF
END FUNCTION
END

SAMPLE RUNS
Copy from assignment document.
Welcome to my Final Grade Calculator!
Please enter the following information and I will calculate your Final Numerical Grade and Letter Grade for you!
The number of assignments must be between 0 and 10.
All scores entered must be between 0 and 4.
Enter the number of assignments (0 to 10): 6
Enter score 1: 3.4 
Enter score 2: 4 
Enter score 3: 2.5 
Enter score 4: 3.3
Enter score 5: 3.1
Enter score 6: 2.5
Enter your midterm exam score: 3.5
Enter your final exam score: 4
Your Final Numeric score is 3.4
Your Final Grade is A
Thank you for using my Grade Calculator!


Welcome to my Final Grade Calculator!
Please enter the following information and I will calculate your Final Numerical Grade and Letter Grade for you!
The number of assignments must be between 0 and 10.
All scores entered must be between 0 and 4.
Enter the number of assignments (0 to 10): 3
Enter score 1: 3 
Enter score 2: 4 
Enter score 3: 2.5 
Enter your midterm exam score: 2.5
Enter your final exam score: 2
Your Final Numeric score is 2.8
Your Final Grade is B
Thank you for using my Grade Calculator!


Welcome to my Final Grade Calculator!
Please enter the following information and I will calculate your Final Numerical Grade and Letter Grade for you!
The number of assignments must be between 0 and 10.
All scores entered must be between 0 and 4.
Enter the number of assignments (0 to 10): 12
Illegal Value! Please try again!!
Enter the number of assignments (0 to 10): 5
Enter score 1: 3.4 
Enter score 2: 4 
Enter score 3: 2.5 
Enter score 4: 5.5
Illegal Score! Please try again!
Enter score 4: 3.5
Enter score 5: 3.1
Enter your midterm exam score: 3.5
Enter your final exam score: 4
Your Final Numeric score is 3.5
Your Final Grade is A
Thank you for using my Grade Calculator!
*/