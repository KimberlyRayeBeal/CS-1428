/*
   File: prog3_k_b351.cpp

   Author: Kimberly Beal 
   C.S.1428.751
   Lab Section: L52
   Program: #3
   Due Date: 07/24/18
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
