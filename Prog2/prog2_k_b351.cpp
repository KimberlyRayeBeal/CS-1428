/*
   File: prog2_k_b351.cpp

   Author: Kimberly Beal
   C.S.1428.751
   Lab Section: L52
   Program: #2
   Due Date: 07/19/18
*/

#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>
#include <cstdlib>

using namespace std;

int main()
{
   const double PI = 3.141592;

   double radius,
          height,
          sphere_surface_area,
          cylinder_surface_area;

   ifstream fin;
   fin.open("prog2_751inp.txt");

   if ( !fin )
   {
        cout << endl << endl
             << "***Program Terminated.***" << endl << endl
             << "Input file failed to open." << endl;

        system("PAUSE>NUL");

        return 1;
   }

   ofstream fout;
   fout.open("prog2_751out.txt");

   if ( !fout )
   {
        cout << endl << endl
             << " ***Program Terminated.*** " << endl << endl
             << "Output file failed to open." << endl;

        fin.close();

        system("PAUSE>NUL");

        return 2;
   }

   fin >> radius >> height;

   sphere_surface_area = 4 * PI * pow(radius,2);

   cylinder_surface_area = 2 * PI * pow(radius,2) + 2 * PI * radius * height;

   fout << "Kimberly Beal" << endl
        << "C.S.1428.751" << endl
        << "Lab Section: L52" << endl
        << "07/19/18" << endl;

   fout << endl
        << fixed << setprecision(2)
        << "The surface area of a sphere with a radius" << endl
        << "of " << radius << " inches is " << sphere_surface_area
        << " inches squared." << endl;

   fout << endl
        << "The surface area of a cylinder with" << endl
        << "a radius of " << radius << " inches and a height" << endl
        << "of " << height << " inches is " << cylinder_surface_area
        << " inches squared. " << endl;

   cout << "Kimberly Beal" << endl
        << "C.S.1428.751" << endl
        << "Lab Section: L52" << endl
        << "07/19/18" << endl;

   cout << endl
        << "The surafce area report has been written to prog2_751out.txt"
        << endl;

   fin.close();
   fout.close();

   system("PAUSE>NUL");

   return 0;
}
