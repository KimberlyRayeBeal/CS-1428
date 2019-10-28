/*
   File: prog5_k_b351.cpp

   Author: Kimberly Beal
   C.S.1428.751
   Lab Section: L52
   Program: #5
   Due Date: 08/01/18
*/

#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>
#include <cstdlib>

using namespace std;

void printIdInfo ( ostream &out );
void readData ( ifstream &fin, double &side1, double &side2, double &side3 );
double calcPerimeterTriange( double side1, double side2, double side3 );
double calcAreaEquilateral ( double side1 );
void printIsEquilateralMsg ( ofstream &fout );
double calcAreaTriangle ( double side1, double side2, double side3 );
void printResults ( ofstream &fout, double side1, double side2, double side3,
                   double perimeter, double area );
void printFileNotification ( );

int main ( )
{
    double side1,
           side2,
           side3,
           perimeter,
           area;

    ifstream fin;
    fin.open( "prog5_751inp.txt" );

    if ( !fin )
    {
        cout << endl << endl
             << "***Program Terminated.***" << endl << endl
             << "Input file failed to open." << endl;

        system( "PAUSE>NUL" );

        return 1;
    }

    ofstream fout;
    fout.open( "prog5_751out.txt" );

    if ( !fout )
    {
        cout << endl << endl
             << " ***Program Terminated.*** " << endl << endl
             << "Output file failed to open." << endl;

        fin.close( );

        return 2;
    }

    printIdInfo ( fout );

    readData ( fin, side1, side2, side3 );

    fout << fixed << setprecision(1);

    while ( side1 > 0 && side2 > 0 && side3 > 0 )
    {
        perimeter = calcPerimeterTriange ( side1, side2, side3);

        if ( side1 == side2 && side1 == side3 )
        {
            area = calcAreaEquilateral ( side1 );

            printIsEquilateralMsg ( fout );
        }
        else
            area = calcAreaTriangle ( side1, side2, side3 );

       printResults ( fout, side1, side2, side3, perimeter, area );

       readData ( fin, side1, side2, side3 );
    }

    printIdInfo ( cout );

    printFileNotification ( );

    fin.close( );
    fout.close( );

    system( "PAUSE>NUL" );

    return 0;
}


/*
    Function: printIdInfo

    The function printIdInfo prints the authors' identifying information
    (name, class/section number, lab section number, due date) on the first,
    second, third and fourth lines of the output. Two blank lines are printed
    after the due date. The output is directed to the screen or to an output
    file depending on the call.

    Sample Output:
                Authors' Names
    		 	C.S.1428.?
                Lab Section: L?
     			--/--/--                 // due date in this format
                    <blank line>
                    <blank line>


    Receives:  output stream variable
    Constants: none
    Returns:   nothing - prints authors' identifying information
*/

void printIdInfo ( ostream &out )
{
    out << "Kimberly Beal" << endl
        << "C.S.1428.751" << endl
        << "Lab Section: L52 " << endl
        << "08/01/18" << endl << endl << endl;
}

 /*
      Function: readData

      The function readData uses one statement to read the sides of a triangle
      from an input file.

      Receives:  input file variable; 3 sides of a triangle (doubles);
                 in this order
      Constants: none
      Returns: side1, side2, side3
*/

void readData ( ifstream &fin, double &side1, double &side2, double &side3 )
{
    fin >> side1 >> side2 >> side3;

}
/*
      Function: calcPerimeterTriange

      The function calcPerimeterTriangle calculates the perimeter
      of a triangle.

      Receives: three sides of a triangle (doubles)
      Constants: none
      Returns: perimeter of the triangle (double)
*/

double calcPerimeterTriange ( double side1, double side2, double side3 )
{
    double perimeter;

    perimeter = side1 + side2 + side3;

    return perimeter;
}

/*
      Function: calcAreaEquilateral

      The function calcAreaEquilateral calculates the area of an
      equilateral triangle.

      Receives: length of one side of an equilateral triangle (double)
      Constants: none
      Returns: area of the equilateral triangle (double)
*/

double calcAreaEquilateral ( double side1 )
{
    double area;

    area = (pow(side1, 2) * sqrt(3.0)) / 4.0;

    return area;
}
/*
      Function: printIsEquilateralMsg

      The function printIsEquilateralMsg prints to the output file
      a message indicating to the user that the triangle currently
      being processed is an equilateral triangle.

      Sample Output:

      The triangle is an equilateral triangle.

      Receives: output file variable
      Constants: none
      Returns: nothing; prints message to the output file
*/

void printIsEquilateralMsg ( ofstream &fout )
{
    fout << "The triangle is an equilateral triangle." << endl;
}
/*
      Function: calcAreaTriangle

      The function calcAreaTriangle calculates the area of a
      non-equilateral triangle using Heron's formula. It is assumed
      the angles of the triangles being processed are sufficiently
      large so that numerical stability is maintained.

      Receives: lengths of the three sides of a triangle (doubles)
      Constants: none
      Returns: area of the triangle (double)
*/

double calcAreaTriangle ( double side1, double side2, double side3 )
{
    double s,
           area;

    s =  calcPerimeterTriange( side1, side2, side3 ) / 2;
    area = sqrt( s * ( s - side1 ) * ( s - side2 ) * ( s - side3 ) );

    return area;
}
/*
      Function: printResults

      The function printResults prints to an output file in sentence form
      the lengths of the sides of a triangle along with the perimeter and
      area of the triangle followed by one blank line. The calling routine
      determines how precise to display numeric data.

      Sample Output:

      The sides of triangle (in inches) are ?.?, ?.?, ?.?.
      The perimeter of the triangle is ??.? inches.
      The area of the triangle is ??.? inches squared.
          <blank line>

      Receives: output file variable;
                lengths of the three sides of a triangle (doubles);
                calculated perimeter & area of the triangle (doubles);
                in this order
      Constants: none
      Returns: nothing; prints the lengths of the sides of a
               triangle plus the calculated perimeter and area
               of the triangle
*/

void printResults ( ofstream &fout, double side1, double side2, double side3,
                   double perimeter, double area )
{
    fout << "The sides of the triangle (in inches) are " << side1 << ", "
         << side2 << ", " << side3 << "." << endl
         << "The perimeter of the triangle is " << perimeter << " inches."
         << endl
         << "The area of the triangle is " << area << " inches squared."
         << endl << endl;
}
/*
    Function: printFileNotification

    The function printFileNotification prints a complete sentence to the screen
    letting the user know the name of the data file to which the triangle report
    has been written.

    Sample Output:

    The triangle report has been written to <output filename>.

    Receives:  nothing
    Constants: none
    Returns:   nothing - prints file notification to the screen
*/

void printFileNotification ( )
{
    cout << "The triangle report has been written to prog5_751out.txt."
         << endl;
}
