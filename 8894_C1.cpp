/*
 * Personalisation Number: 8894
 */

#include <iostream>
#include <iomanip>   // setw() for aligned table output
#include <string>

using namespace std;

// ---------------------------------------------------------------------------
// Shared constant: the Personalisation Number is defined once and every task
// derives its personalised values from it, so changing it here updates the
// whole program consistently (no "magic numbers" repeated in each task).
// ---------------------------------------------------------------------------
const int PERSONALISATION_NUMBER = 8894;
const int NUM_DIGITS = 4;

// Prototypes
void task1(); void task2(); void task3(); void task4(); void task5();
void task6(); void task7(); void task8(); void task9(); void task10();

// Helper prototypes
int getDigit(int number, int position);
int sumOfDigits(int number);
void printHeader(int taskNumber, const string& title);
void displayWelcome(const string& name, int marks);
void showPersonalisationCall();
double computeAverage();
void incrementGlobalAndStatic();

int main() {
    task1(); task2(); task3(); task4(); task5();
    task6(); task7(); task8(); task9(); task10();
    return 0;
}

// ===========================================================================
// Helper functions
// ===========================================================================

// Returns the digit at the given position, counting from the left starting
// at 1 (e.g. getDigit(8894, 2) == 8). Uses integer division/modulus so no
// string conversion is needed.
int getDigit(int number, int position) {
    int divisor = 1;
    for (int i = 0; i < NUM_DIGITS - position; i++) {
        divisor *= 10;
    }
    return (number / divisor) % 10;
}

// Adds up every digit of a non-negative number by repeatedly taking the
// last digit (% 10) and removing it (/ 10).
int sumOfDigits(int number) {
    int sum = 0;
    while (number > 0) {
        sum += number % 10;
        number /= 10;
    }
    return sum;
}

// Prints a consistent heading so each task's output is easy to locate.
void printHeader(int taskNumber, const string& title) {
    cout << "\n==================================================\n";
    cout << " Task " << taskNumber << ": " << title << '\n';
    cout << "==================================================\n";
}

// ===========================================================================
// Task 1 - Variables & Output
// Reads two integers and prints their sum.
// Personalisation: the two inputs are the 2nd digit (8) and the last digit (4)
// of 8894, so the expected sum is 12.
// ===========================================================================
void task1() {
    printHeader(1, "Variables & Output");

    int firstNumber = getDigit(PERSONALISATION_NUMBER, 2);           // 2nd digit
    int secondNumber = getDigit(PERSONALISATION_NUMBER, NUM_DIGITS); // last digit
    int sum = firstNumber + secondNumber;

    cout << "Second digit of " << PERSONALISATION_NUMBER << ": " << firstNumber << '\n';
    cout << "Last digit of " << PERSONALISATION_NUMBER << ":   " << secondNumber << '\n';
    cout << "Sum: " << firstNumber << " + " << secondNumber << " = " << sum << '\n';
}

// ===========================================================================
// Task 2 - Arithmetic Operations
// Multiplies two numbers and prints the result.
// Personalisation: one operand is the digit sum of 8894 (8+8+9+4 = 29); the
// other is the last two digits (94), giving 29 * 94 = 2726.
// ===========================================================================
void task2() {
    printHeader(2, "Arithmetic Operations");

    int digitSum = sumOfDigits(PERSONALISATION_NUMBER);
    int lastTwoDigits = PERSONALISATION_NUMBER % 100;
    int product = digitSum * lastTwoDigits;

    cout << "Sum of digits of " << PERSONALISATION_NUMBER << ": " << digitSum << '\n';
    cout << "Last two digits: " << lastTwoDigits << '\n';
    cout << "Product: " << digitSum << " * " << lastTwoDigits << " = " << product << '\n';
}

// ===========================================================================
// Task 3 - Loops / Iterations
// Prints a multiplication table from 1 up to N using nested for loops.
// Personalisation: N = (8894 % 10) + 1 = 5, so a 5 x 5 table is printed.
// ===========================================================================
void task3() {
    printHeader(3, "Loops / Iterations");

    const int n = (PERSONALISATION_NUMBER % 10) + 1;
    const int columnWidth = 5;
    cout << "N = (" << PERSONALISATION_NUMBER << " % 10) + 1 = " << n << "\n\n";

    // Column header row
    cout << setw(columnWidth) << "x" << " |";
    for (int col = 1; col <= n; col++) {
        cout << setw(columnWidth) << col;
    }
    cout << '\n' << string(columnWidth + 2 + columnWidth * n, '-') << '\n';

    // Outer loop = rows, inner loop = columns; each cell is row * col.
    for (int row = 1; row <= n; row++) {
        cout << setw(columnWidth) << row << " |";
        for (int col = 1; col <= n; col++) {
            cout << setw(columnWidth) << row * col;
        }
        cout << '\n';
    }
}

// ===========================================================================
// Task 4 - If-Else Conditions
// Checks whether a number is even or odd using the remainder after dividing
// by 2. Personalisation: the full number 8894 is tested (result: even).
// ===========================================================================
void task4() {
    printHeader(4, "If-Else Conditions");

    int number = PERSONALISATION_NUMBER;
    if (number % 2 == 0) {
        cout << number << " is EVEN (" << number << " % 2 = 0)\n";
    } else {
        cout << number << " is ODD (" << number << " % 2 = 1)\n";
    }
}

// ===========================================================================
// Task 5 - Switch Case
// Displays the month name for a value between 1 and 12 using a switch.
// Personalisation: input = (8894 % 12) + 1 = 2 + 1 = 3, which is March.
// The default case guards against any value outside 1-12.
// ===========================================================================
void task5() {
    printHeader(5, "Switch Case");

    int monthNumber = (PERSONALISATION_NUMBER % 12) + 1;
    cout << "Month input = (" << PERSONALISATION_NUMBER << " % 12) + 1 = " << monthNumber << '\n';
    cout << "Month: ";

    switch (monthNumber) {
        case 1:  cout << "January";   break;
        case 2:  cout << "February";  break;
        case 3:  cout << "March";     break;
        case 4:  cout << "April";     break;
        case 5:  cout << "May";       break;
        case 6:  cout << "June";      break;
        case 7:  cout << "July";      break;
        case 8:  cout << "August";    break;
        case 9:  cout << "September"; break;
        case 10: cout << "October";   break;
        case 11: cout << "November";  break;
        case 12: cout << "December";  break;
        default: cout << "Invalid month number"; break;
    }
    cout << '\n';
}

// ===========================================================================
// Task 6 - Arrays
// Declares an array of five integers, fills it with a loop and prints the
// third value (index 2). Personalisation: the array holds the digits of 8894
// in an order that places the last digit (4) in the third slot, plus the
// digit sum (29) as the fifth value.
// ===========================================================================
void task6() {
    printHeader(6, "Arrays");

    const int ARRAY_SIZE = 5;
    int values[ARRAY_SIZE];

    values[0] = getDigit(PERSONALISATION_NUMBER, 1);           // 8
    values[1] = getDigit(PERSONALISATION_NUMBER, 2);           // 8
    values[2] = getDigit(PERSONALISATION_NUMBER, NUM_DIGITS);  // 4 (last digit)
    values[3] = getDigit(PERSONALISATION_NUMBER, 3);           // 9
    values[4] = sumOfDigits(PERSONALISATION_NUMBER);           // 29

    cout << "Array contents: ";
    for (int i = 0; i < ARRAY_SIZE; i++) {
        cout << values[i] << (i < ARRAY_SIZE - 1 ? ", " : "\n");
    }
    // Arrays are zero-indexed, so the third value is at index 2.
    cout << "Third value (index 2): " << values[2]
         << "  <- last digit of " << PERSONALISATION_NUMBER << '\n';
}

// ===========================================================================
// Task 7 - Functions with Parameters
// displayWelcome() receives a name and marks as parameters and prints a
// personalised welcome message. Personalisation: the message includes the
// Personalisation Number, and the marks are its last two digits (94).
// The name is passed by const reference to avoid copying the string.
// ===========================================================================
void displayWelcome(const string& name, int marks) {
    cout << "Welcome, " << name << " (Personalisation No. "
         << PERSONALISATION_NUMBER << ")!\n";
    cout << "Your Fundamentals of Programming module mark is: "
         << marks << "/100\n";
}

void task7() {
    printHeader(7, "Functions with Parameters");

    const string studentName = "Qais";
    int marks = PERSONALISATION_NUMBER % 100;   // last two digits -> 94
    displayWelcome(studentName, marks);
}

// ===========================================================================
// Task 8 - Static Local Variables
// showPersonalisationCall() keeps a static local counter that is initialised
// only once and keeps its value between calls, so it reports the current
// call number. Personalisation: it prints 8894 and is called 5 times.
// ===========================================================================
void showPersonalisationCall() {
    static int callCount = 0;   // initialised once, persists across calls
    callCount++;
    cout << "Personalisation Number: " << PERSONALISATION_NUMBER
         << " | Function call count: " << callCount << '\n';
}

void task8() {
    printHeader(8, "Static Local Variables");

    const int TOTAL_CALLS = 5;
    for (int i = 0; i < TOTAL_CALLS; i++) {
        showPersonalisationCall();
    }
}

// ===========================================================================
// Task 9 - Debugging computeAverage()
// Reads integer marks until the sentinel -1, ignores other negative marks,
// and returns the average of valid marks as a double (0.0 if none).
// Each bug from the original code is documented with "Bug n" / "Fix" notes.
// ===========================================================================
double computeAverage() {
    int total = 0;
    int count = 0;
    int mark = 0;

    // Bug 1: The do-while loop added the mark to the total BEFORE checking it,
    //        so the sentinel -1 was added to the total.
    // Fix:   Read inside a while(true) loop and break as soon as -1 is read,
    //        before any processing happens.
    while (true) {
        // Bug 5 (robustness): The original never checked whether cin
        //        succeeded. A non-integer (e.g. "abc") puts cin into a fail
        //        state, mark is set to 0 and the loop never ends.
        // Fix:   Check the stream. On end-of-input stop reading; on invalid
        //        text clear the error, discard that token and keep going.
        if (!(cin >> mark)) {
            if (cin.eof()) {
                break;                      // no more input: stop safely
            }
            cin.clear();
            string invalidToken;
            cin >> invalidToken;            // discard only the bad token
            cout << "  (Invalid input ignored - please enter integers)\n";
            continue;
        }

        if (mark == -1) {
            break;                          // sentinel reached: stop reading
        }

        // Bug 2: Invalid (negative) values were included in the total.
        // Fix:   Skip any negative mark other than the sentinel.
        if (mark < 0) {
            continue;
        }

        total = total + mark;

        // Bug 3: count was incremented for every input, including -1 and
        //        negative marks, which made the average too small.
        // Fix:   count is now only incremented for valid (>= 0) marks.
        count = count + 1;
    }

    // Bug 4: "total / count" was integer division (fraction lost) and would
    //        divide by zero if no valid marks were entered.
    // Fix:   Return 0.0 when count is 0; otherwise cast total to double so
    //        floating-point division keeps the decimal part.
    if (count == 0) {
        return 0.0;
    }
    return static_cast<double>(total) / count;
}

// Testing note: task9 runs computeAverage() three times so the required
// cases can be checked in one run:
//   Case 1 - no valid marks:            -5 -20 -1      -> expected 0.00
//   Case 2 - all valid marks:           70 85 90 -1    -> expected 81.67
//   Case 3 - valid, zero and negatives: 60 0 -10 75 -3 50 -1 -> expected 46.25
// Results were checked against the values calculated by hand above.
void task9() {
    printHeader(9, "Debugging computeAverage()");

    const int TEST_CASES = 3;
    const string caseDescriptions[TEST_CASES] = {
        "No valid marks (e.g. -5 -20 -1)",
        "All valid marks (e.g. 70 85 90 -1)",
        "Mixture of valid, zero and negative (e.g. 60 0 -10 75 -3 50 -1)"
    };

    cout << fixed << setprecision(2);
    for (int i = 0; i < TEST_CASES; i++) {
        cout << "\nTest case " << (i + 1) << ": " << caseDescriptions[i] << '\n';
        cout << "Enter marks separated by spaces, end with -1: ";
        double average = computeAverage();
        cout << "Average of valid marks: " << average << '\n';
    }
    cout.unsetf(ios::fixed);            // restore default formatting
    cout << setprecision(6);
}

// ===========================================================================
// Task 10 - Global vs. Static Variables
// A global variable is visible to every function, so any function can change
// it. A static local variable keeps its value between calls but can only be
// accessed inside its own function. A normal local variable is shown for
// contrast because it is recreated on every call.
// Personalisation: all three start from values based on 8894.
// ===========================================================================
int globalCounter = PERSONALISATION_NUMBER;   // global: accessible anywhere

void incrementGlobalAndStatic() {
    static int staticCounter = PERSONALISATION_NUMBER;  // initialised once only
    int localCounter = PERSONALISATION_NUMBER;          // reset every call

    globalCounter++;
    staticCounter++;
    localCounter++;

    cout << "  global = " << globalCounter
         << " | static local = " << staticCounter
         << " | normal local = " << localCounter << '\n';
}

void task10() {
    printHeader(10, "Global vs. Static Variables");

    cout << "All counters start at " << PERSONALISATION_NUMBER << " and are incremented on each call:\n";
    const int TOTAL_CALLS = 3;
    for (int i = 0; i < TOTAL_CALLS; i++) {
        incrementGlobalAndStatic();
    }

    // Only the global can be changed from outside the function; the static
    // local is hidden inside incrementGlobalAndStatic().
    globalCounter += 100;
    cout << "task10() adds 100 directly to the global -> global = " << globalCounter << '\n';
    cout << "(The static local cannot be accessed here - it is scoped to its function.)\n";
    incrementGlobalAndStatic();

    cout << "\nResult: the global and static local both keep their values between calls;\n"
         << "the global can be modified by any function, while the static local is private\n"
         << "to its function. The normal local resets to " << PERSONALISATION_NUMBER + 1
         << " every call.\n";
}
