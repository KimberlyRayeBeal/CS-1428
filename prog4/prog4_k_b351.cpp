/*
   File: prog4_k_b351.cpp

   Author: Kimberly Beal
   C.S.1428.751
   Lab Section: L52 
   Program: #4
   Due Date:07/27/18
*/

#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>
#include <cstdlib>

using namespace std;

int main ( )
{
   double side1,
          side2,
          side3,
          area,
          s,
          perimeter;

   int num_of_records;

   ifstream fin;
   fin.open("prog4_751inp.txt");

   if ( !fin )
   {
        cout << endl << endl
             << "***Program Terminated.***" << endl << endl
             << "Input file failed to open." << endl;

        system("PAUSE>NUL");

        return 1;
   }

   ofstream fout;
   fout.open("prog4_751out.txt");

   if ( !fout )
   {
        cout << endl << endl
             << " ***Program Terminated.*** " << endl << endl
             << "Output file failed to open." << endl;

        fin.close();

        system("PAUSE>NUL");

        return 2;
   }

   fout << "Kimberly Beal" << endl
        << "C.S.1428.751" << endl
        << "Lab Section: L52" << endl
        << "07/27/18" << endl << endl << endl;

   fin >> num_of_records;

   fout << fixed << setprecision(1);

   for (int i = num_of_records; i > 0; --i)
   {
      fin >> side1 >> side2 >> side3;

      perimeter = side1 + side2 + side3;

      if ( side1 == side2 && side1 == side3 && side2 == side3 )
      {
         s = perimeter / 2;
         area = (pow(s,2)*sqrt(3))/4;

         fout << "The triangle is an equilateral triangle." << endl;
      }
      else
      {
            s = perimeter / 2;

            area = sqrt(s*(s-side1)*(s-side2)*(s-side3));
      }

      fout << "The sides of the triangle (in inches) are " << side1 << ", "
           << side2 << ", and " << side3 << "." << endl
           << "The perimeter of the triangle is " << perimeter << " inches."
           << endl
           << "The area of the triangle is " << area << " inches squared."
           << endl << endl;
   }

   cout << "Kimberly Beal" << endl
        << "C.S.1428.751" << endl
        << "Lab Section: L52" << endl
        << "07/27/18" << endl << endl << endl

        << "The triangle report has been written to prog4_751out.txt." << endl;

   fin.close();
   fout.close();

   system("PAUSE>NUL");

   return 0;
}
