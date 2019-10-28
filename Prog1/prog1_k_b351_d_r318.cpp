/*
   File: prog1_k_b351_d_r318.cpp

   Author: Kimberly Beal
   C.S.1428.751
   Lab Section: L52
   Program: #1
   Due Date: 07/16/18
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

    cout << "Kimberly Beal" << endl
         << "C.S.1428" << endl
         << "Lab Section: L52" << endl
         << "07-16-18" << endl << endl;

    cout << "A sphere with a diameter of " << diameter << " inches " << endl
         << "and a radius of " << radius << " inches has a volume " << endl
         << "of " << sphere_volume << " cubic inches." << endl;


    system("PAUSE>NUL");

    return 0;

}
