/*
   File: prog1_k_b351_d_r318.cpp

   Author: Kimberly Beal and Devin Roseman
   C.S.1428.751
   Lab Section: L52
   Program: #1
   Due Date: 07/16/18

   This program prompts the user for the diameter of a sphere (in inches)
   allowing for real input data. After reading the value entered at the
   keyboard, the program calculates the radius of the sphere. It then
   calculates the volume of the sphere. Two blank lines are displayed
   before the author's identifying information is written to the console.
   One blank line is written to the console before the diameter of the
   sphere along with the calculated radius and volume of the sphere are
   written in sentence form. Numeric values in the output statement are
   displayed to one decimal place. The layout and content of the output
   screen are shown below.

   Input (keyboard):  diameter  (double)
   Constants:         PI = 3.141592 (double)
   Output (console):
              Author's Name
              C.S.1428.?        // '?' represents student's lecture section #
              Lab Section: L?   // '?' represents student's lab section #
              --/--/--          // dashes represent due date, month/day/year
                  <blank line>
              A sphere with a diameter of ? inches
              and a radius of ? inches has a volume
              of ? cubic inches.

   ================================================

   <Output will vary based on actual input values.>



*/
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <iomanip>

using namespace std;

int main()

{
    const double PI = 3.141592;

    double radius,
           diameter,
           sphere_volume;


    cout << "Enter the diameter of a sphere (in inches): ";
    cin >> diameter;

    radius = diameter / 2;

    sphere_volume = (4.0/3.0) * PI * pow(radius,3);

    cout << fixed << setprecision(1);

    cout << endl << endl;

    cout << "Kimberly Beal and Devin Roseman" << endl
         << "C.S.1428.751" << endl
         << "Lab Section: L52" << endl
         << "07-16-18" << endl << endl;

    cout << "A sphere with a diameter of " << diameter << " inches " << endl
         << "and a radius of " << radius << " inches has a volume " << endl
         << "of " << sphere_volume << " cubic inches." << endl;


    system("PAUSE>NUL");

    return 0;

}
