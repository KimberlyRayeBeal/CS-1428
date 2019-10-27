/*
   File: prog3_k_b351_d_r318.cpp

   Author: Kimberly Beal and Devin Roseman
   C.S.1428.751
   Lab Section: L52 and L52
   Program: #3
   Due Date: 07/24/18

   This program displays a menu of four geometry calculator options along
   with a prompt for the user to enter his/her menu choice. (See layout
   below.)

   Geometry Calculator
        1.  Calculate the surface area of a cube.
        2.  Calculate the surface area of a sphere.
        3.  Calculate the surface area of a cylinder.
        4.  Calculate the surface area of a rectangular prism.
        5.  Quit

   Enter your choice ( 1 - 5 ):

==========================================================================
   If the user enters 1, the program prompts for the length of one side of
   a cube. The length and the calculated surface area of the cube are then
   displayed on the screen.
             surface area of a cube = 6aa,
             where a is the length of the side of each edge of the cube.

   If the user enters 2, the program prompts for the radius of a sphere.
   The radius and the calculated surface area of the sphere are then
   displayed on the screen.
             surface area of a sphere = 4PIrr,
             where r is the radius of the sphere.

   If the user enters 3, the program prompts for the radius of the base
   of a cylinder and the height of the cylinder. The radius, height and
   calculated surface area of the cylinder are then displayed on the screen.
             surface area of a cylinder = 2PIrr + 2PIrh,
             where r is the radius of the base of the cylinder and
             h is the height of the cylinder.

   If the user enters 4, the program prompts for the lengths of the three
   sides of a rectangular prism. The three input values and the calculated
   surface area of the rectangular prism are then displayed on the screen.
             surface area of a rectangular prism = 2ab + 2bc + 2ac,
             where a, b, and c are the lengths of the 3 sides.

   If the user enters the maximum menu choice, the program will terminate
   after displaying an appropriate message on the screen.

Notes:
    - With the exception of the menu choices, all input data are real and
      measured in inches.
    - The order of operands in all standard formulas is maintained.
    - No single letter variable names are used in standard formulas.
    - 3.14159 is used for the value of PI.
    - The pow function is used for calculations involving exponentiation.
    - A named constant is used to represent the maximum menu choice to
      allow expansion of the menu options.
    - The author's identifying information is displayed on the first four
      lines of the console screen followed by two blank lines and the
      display of the geometric calculator menu.
    - Two blank lines are left before the first prompt in each case and
      again before any output message displayed on the screen.
    - All output values are appropriately labeled either by use of
      descriptive terms or by including them in complete sentence form.
    - Calculated results are displayed to two decimal places.

 Input validation is limited to the following situations:
   1) If the user enters a number outside the range of 1-MAX_CHOICE when
      selecting a menu item, an appropriate error message is displayed on
      the screen.
   2) If the user fails to enter a value greater than zero for the
      requested input values (length(s), radius, height), an appropriate
      error message is displayed on the screen.
   3) In the event that erroneous input is entered as in #1 or #2 above,
      the user is not prompted again to enter correct input. The program
      simply terminates after a message appropriate to the situation is
      displayed on the screen.

   Input (keyboard): menu choice - integer
                     side length (cube) - double
                     radius (sphere or cylinder base) - double
                     height (cylinder) - double
                     length, width, height (rectangular prism) - double

   Constants: PI = 3.14159 (double)
              MAX_CHOICE (integer)       // last menu choice

   Sample Console Screen:

   Author's Name
   C.S.1428.?          // '?' represents student's lecture section number
   Lab Section: L?     // '?' represents student's lab section number
   --/--/--            // dashes represent due date, month/day/year
           <blank line>
           <blank line>
   Geometry Calculator
        1.	Calculate the surface area of a cube.
        2.	Calculate the surface area of a sphere.
        3.	Calculate the surface area of a cylinder.
        4.	Calculate the surface area of a rectangular prism.
        5.	Quit
            <blank line>
   Enter your choice ( 1 - 5 ):
           <blank line>
           <blank line>
   Prompt(s)...
           <blank line>
           <blank line>
   Display of the input value(s) needed to determine the surface area
   of the geometric figure and the calculated surface area of the figure
   either appropriately labeled or in sentence form.

   =================================================================

   <Output will vary based on input.>

*/

#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>

using namespace std;

int main ( )
{
    const double PI = 3.14159;

    const int MAX_CHOICE = 5;

    double radius,
           height,
           length,
           length_a,
           length_b,
           length_c,
           width,
           surface_area;

    int menu_choice;

    cout << "Kimberly Beal and Devin Roseman" << endl
         << "C.S.1428.751" << endl
         << "Lab Section: L52 and L52" << endl
         << "07/24/18" << endl << endl << endl

         << "Geometry Calculator" << endl
         << "     1. Calculate the surface area of a cube. " << endl
         << "     2. Calculate the surface area of a sphere." << endl
         << "     3. Calculate the surface area of a cylinder." << endl
         << "     4. Calculate the surface area of a rectangular prism." << endl
         << "     " << MAX_CHOICE << ". Quit " << endl << endl

         << "Enter your choice ( 1 - " << MAX_CHOICE << " ): ";

    cin >> menu_choice;

    if ( menu_choice <= 0 || menu_choice > MAX_CHOICE )
        cout << endl << endl
             << "You entered an invalid menu choice." << endl
             <<"***PROGRAM WILL BE TERMINATED!***" << endl << endl << endl;
    else
    {
        switch (menu_choice)
        {
            case 1:
                cout << endl << endl
                     << "Enter the length of one side of the cube "
                     << "(in inches): ";
                cin >> length;

                if ( length <= 0 )
                    cout << endl << endl
                         << "You entered " << length <<" inch(es) . That is an "
                         << "invalid length." << endl
                         << "***PROGRAM WILL BE TERMINATED!***" << endl <<endl
                         <<endl;
                else
                {
                    surface_area = 6 * pow(length,2);

                    cout << endl << endl
                         << "The surface area of a cube whose side length "
                         << "is " << length << endl
                         << "inch(es) is " << fixed << setprecision(2)
                         << surface_area << " inch(es) squared."<< endl;
                }
                break;
            case 2:
                cout << endl << endl
                     << "Enter the radius of the sphere (in inches): ";
                cin >> radius;

                if ( radius <= 0 )
                    cout << endl << endl
                         << "You entered " << radius << " inch(es). That is an "
                         << "invalid radius." << endl
                         << "***PROGRAM WILL BE TERMINATED!***" << endl << endl
                         << endl;
                else
                {
                    surface_area = 4 * PI * pow(radius,2);

                    cout << endl << endl
                         << "The surface area of a sphere whose radius is "
                         << radius << endl
                         << "inch(es) is " << fixed << setprecision(2)
                         << surface_area << " inch(es) squared. " << endl;
                }
                break;
            case 3:
                cout << endl << endl
                         << "Enter the radius of the base of the cylinder "
                         << "(in inches): ";
                cin >> radius;

                if ( radius <= 0 )
                    cout << endl << endl
                         << "You entered " << radius << " inch(es). That is an "
                         << "invalid radius." << endl
                         << "***PROGRAM WILL BE TERMINATED!***" << endl << endl
                         << endl;
                else
                {
                    cout << endl
                         << "Enter the height of the cylinder (in inches): ";
                    cin >> height;

                    if ( height <= 0 )
                        cout << endl << endl
                             << "You entered " << height << " inch(es). That "
                             << "is an invalid height." << endl
                             << "***PROGRAM WILL BE TERMINATED!***" << endl
                             << endl << endl;
                    else
                    {
                        surface_area = 2 * PI * pow(radius, 2) +
                                       2 * PI * radius * height;

                        cout << endl << endl
                             << "The surface area of a cylinder whose base has "
                             << "a " << endl
                             << "radius of " << radius << " inch(es) and a "
                             << "height of " << height << " inch(es) " << endl
                             << "is " << fixed << setprecision(2)
                             << surface_area << " inch(es) squared." << endl;
                    }
                }
                break;
            case 4:
                cout << endl << endl
                         << "Enter the side length of the rectangular prism: ";
                cin >> length_a;
                cout << endl
                         << "Enter a different side length of the rectangular "
                         << "prism: ";
                cin >> length_b;
                cout << endl
                         << "Enter a different side length of the rectangular "
                         << "prism: ";
                cin >> length_c;

                if ( length_a <= 0 || length_b <= 0 || length_c <= 0 )
                    cout << endl << endl
                         << "You entered " << length_a << ", " << length_b
                         << ", and " << length_c << "." << endl
                         << "One or more of your inputs are invalid." << endl
                         << "***PROGRAM WILL BE TERMINATED!***" << endl << endl
                         << endl;
                else
                {
                    surface_area = 2 * length_a * length_b +
                                   2 * length_b * length_c +
                                   2 * length_a * length_c;

                    cout << endl << endl
                         << "The surface area of the rectangular prism whose "
                         << "side lengths " << endl
                         << "are " << length_a << ", " << length_b << ", and "
                         << length_c << " is " << fixed << setprecision(2)
                         << surface_area << " inches squared.";
                }
                break;
            case MAX_CHOICE:
                cout << endl << endl
                     << "You are quitting the Geometry Calculator." << endl
                     << "Have a good day!" << endl << endl << endl;
                break;
            }
    }

    system("PAUSE>NUL");

	return 0;
}
