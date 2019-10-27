/*
   File: prog0_k_b351.cpp

   Author: Kimberly Beal
   C.S.1428.751
   Lab Section: L52
   Program: #0
   Due Date: 07/11/18

   This program
     - prints the student's name on the first line of output
       e.g. John Smith
     - prints 'C.S.1428.#' (without quotation marks) on the second line of
       output with student's lecture section number in place of the # sign
     - prints 'Lab Section: ?' (without quotation marks) on the 3rd line of
       output with the student's lab section number in place of the ? mark
     - prints this program's due date on the fourth line of output
     - leaves line five blank
     - prints 'Major: ?' (without quotation marks) on the sixth line of
       output. The question mark is replaced with the author's major
     - prints 'Minor: ?' (without quotation marks) on the seventh line of
       output. The question mark is replaced with the author's minor or
       specialization or concentration or
       Note: If the author does not have a minor or specialization or
       concentration or, something is 'made up' in order to complete
       the assignment.
     - leaves line eight blank
     - prints 'Hometown: ?' (without quotation marks) on the ninth line
       of output. The question mark is replaced with the name of the
       author's hometown.

   Input: none
   Constants: none
   Output (console): Sample Output:

                Betty Boop
                C.S.1428.?        // '?' represents student's lecture section #
                Lab Section: L?   // '?' represents student's lab section #
                --/--/--          // dashes represent due date, month/day/year
                   <blank line>
                Major: Pig Latin
                Minor: Underwater Polo
                   <blank line>
                Hometown: Fleischerville

   Note: A student may designate a specialization or concentration instead
   of a minor.

*/

#include <iostream>

using namespace std;

int main ( )
{
   cout << "Kimberly Beal" << endl
        << "C.S.1428.751" << endl
        << "Lab Section: L52" << endl
        << "07/11/18" << endl << endl;

   cout << "Major: Mathematics" << endl
        << "Minor: Secondary Education" << endl << endl;

   cout << "Hometown: Austin, Texas" << endl;

   return 0;
}
