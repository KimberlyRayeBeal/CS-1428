/*
   File: prog5_k_b351_d_r318.cpp

   Author: Kimberly Beal and Devin Roseman
   C.S.1428.751
   Lab Section: L52 and L52
   Program: #5
   Due Date: 08/01/18

   This program reads the sides of a triangle in inches from an input file,
   allowing for real input. It then calculates the perimeter and area of the
   triangle. It prints the sides of the triangle plus the calculated perimeter
   and area to an output file. It also indicates when the triangle being
   processed is an equilateral triangle.

   An appropriate message is written to the screen informing the user of
   the output file name to which the results have been written. The layout
   and content of the output are shown in the samples below.

   Note: An appropriate message is displayed to the screen if either the
   input file or the output file fails to open.

   Input:
   Each line (record) on the input file contains three real values separated
   by spaces (the sides of a triangle.) Once a negative value for any or all
   of the three sides is read, processing stops.

   Processing:
   A sentinel value read loop & functions are used to process the data as
   follows:

   - A function is called to print to the output file the author's identifying
     information.
   - A function is called to read from the input file the first record (triangle.)

   - As long as there are records to process:
          - A function is called to calculate the perimeter of the triangle
            currently being processed.
          - If the sides of the triangle currently being processed are equal,
                - A function is called to calculate the area of the equilateral
                  triangle.
                - A function is called to write a message to the output file
                  indicating that the triangle being processed is equilateral.
            Otherwise,
                - A function is called which uses Heron's formula to calculate
                  the area of the triangle currently being processed.
          - A function is called to print to the output file in sentence form
            the input values plus the calculated values followed by one blank
            line.
          - The read function is called to read from the input file the second
            and subsequent records (triangles.)

   - A function is called to print to the screen the author's personal
     identifying information.
   - A function is called to print to the screen an appropriate sentence letting
     the user know the name of the data file to which the triangle report has
     been written.

   Note: If the first record contains the sentinel value, only the author's
   personal identifying information will appear in the output file.

   Note: Numeric data is displayed to one decimal place (determined by the
   calling routine.)

==============================================================================

Function definitions included are described below:

1) The void function printIdInfo prints the author's personal information
   (name, class/section number, lab section number, due date) on the first,
   second, third and fourth lines of the output location. printIdInfo prints
   two blank lines after the due date. The output is directed to the output
   file or to the screen depending on the call.
   e.g.   Author's Name
          C.S.1428.?          // '?' represents author's lecture section number
          Lab Section: L?     // '?' represents author's lab section number
          --/--/--            // dashes represent due date, month/day/year
             <blank line>
             <blank line>
2) The void function readData uses only one read statement to "get" the values
   on each record from an input file - the sides of a triangle.
3) The typed function calcPerimeterTriangle calculates the perimeter of a
   triangle.
4) The typed function calcAreaEquilateral calculates the area of an equilateral
   triangle.
5) The void function printIsEquilateralMsg writes a message to the output file
   indicating the triangle being processed is an equilateral triangle.
   e.g.  The triangle is an equilateral triangle.
6) The typed function calcAreaTriangle using Heron's formula calculates the
   area of a triangle. (calcAreaTriangle calls calcPerimeterTriangle to
   calculate perimeter.)
7) The void function printResults prints to the output file in sentence form
   the input values plus the calculated values followed by one blank line.
   The calling routine determines how precise to display numeric data.
   e.g.   The sides of triangle (in inches) are ?.?, ?.?, ?.?.
          The perimeter of the triangle is ??.? inches.
          The area of the triangle is ??.? inches squared.
             <blank line>
8) The void function printFileNotification prints to the screen a statement
   letting the user know the name of the data file to which the triangle
   report has been written.
   e.g.   The triangle report has been written to <output filename>.

    Note: Only the area of a triangle is calculated in the functions that
          calculate area.

==============================================================================

    Each function definition is properly documented.

==============================================================================

    Area of an equilateral triangle:
        area = (s2 * sqrt(3)) / 4 , here s represents the length of 1 side

    Heron's formula to calculate the area of a triangle, given the three
    sides (here calcPerimeterTriangle is a function that calculates the
    perimeter of the triangle):

        s = calcPerimeterTriangle (side1, side2, side3) / 2;
        area = sqrt(s * (s - side1) * (s - side2) * (s - side3));

    Note: Heron's formula as given above is numerically unstable for triangles
    with a very small angle. An alternative that is considered stable involves
    arranging the lengths of the sides so that: a >= b >= c and using a
    completely different formula than that given above. (See specifications.)

    Note: For the purpose of this assignment, the angles of the triangles are
    assumed to be sufficiently large so that numerical instability is not an
    issue. Therefore, the sides of the triangle as listed in the input file
    are NOT reordered, and the version of Heron's formula given above is
    used in calculation.

    Note: area = 1/2 * base * height works for a right triangle if you know
    which of the three sides is the base and which of the three sides is the
    height which is unknown for this programming assignment, and there is no
    guarantee input will be a right triangle.

    Input (file - prog5_751inp.txt): 3 sides of a triangle ( reals )

    Constants: none

    Output (screen):
           Author's Name
           C.S.1428.?        // '?' represents author's lecture section number
           Lab Section: L?   // '?' represents author's lab section number
           --/--/--          // dashes represent due date, month/day/year
                <blank line>
                <blank line>
           <Appropriate message indicating the name of the output file.>

    Output (file - prog5_751out.txt):
           Sample file output:

           Author's Name
           C.S.1428.?        // '?' represents author's lecture section number
           Lab Section: L?   // '?' represents author's lab section number
           --/--/--          // dashes represent due date, month/day/year
                <blank line>
                <blank line>
           The sides of the triangle (in inches) are ?.?, ?.?, and ?.?.
           The perimeter of the triangle is ?.? inches.
           The area of the triangle is ?.? inches squared.
                 <blank line>
           The sides of the triangle (in inches) are ?.?, ?.?, and ?.?.
           The perimeter of the triangle is ?.? inches.
           The area of the triangle is ?.? inches squared.

           ...

    Note: If the first record contains the sentinel value, only the author's
    personal identifying information will appear in the output file.

    ==========================================================================

    <Output will vary based on input values.>
*/

#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>
#include <cstdlib>

using namespace std;

void printIdInfo ( ostream &out );
void readData( ifstream &fin, double &side1, double &side2, double &side3 );
double calcPerimeterTriange( double side1, double side2, double side3 );
double calcAreaEquilateral ( double side1 );
void printIsEquilateralMsg ( ofstream &fout );
double calcAreaTriangle( double side1, double side2, double side3 );
void printResults ( ofstream &fout, double side1, double side2, double side3,
                   double perimeter, double area );
void printFileNotification ( );

int main ( )
{
    double side1,
           side2,
           side3,
           perimeter = 0,
           area = 0;

    ifstream fin;
    fin.open( "prog5_751inp.txt" );

    if ( !fin )
    {
        cout << endl << endl
             << "***Program Terminated.***" << endl << endl
             << "Input file failed to open." << endl;

        system("PAUSE>NUL");

        return 1;
    }

    ofstream fout;
    fout.open( "prog5_751out.txt" );

    if ( !fout )
    {
        cout << endl << endl
             << " ***Program Terminated.*** " << endl << endl
             << "Output file failed to open." << endl;

        fin.close();

        return 2;
    }

    printIdInfo (fout);

    readData( fin, side1, side2, side3 );

    fout << fixed << setprecision(1);
    while ( side1 > 0 && side2 > 0 && side3 > 0 )
    {
        perimeter = calcPerimeterTriange( side1, side2, side3);

        if ( side1 == side2 && side1 == side3 )
        {
            area = calcAreaEquilateral ( side1 );

            printIsEquilateralMsg ( fout );
        }
        else
            calcAreaTriangle( side1, side2, side3 );

       printResults ( fout, side1, side2, side3, perimeter, area );

       readData ( fin, side1, side2, side3 );
    }

    printIdInfo ( cout );

    printFileNotification ( );

    fin.close( );
    fout.close( );

    system("PAUSE>NUL");

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

void printIdInfo (ostream &out)
{
    out << "Kimberly Beal and Devin Roseman" << endl
        << "C.S.1428.751" << endl
        << "Lab Section: L52 and L52" << endl
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

void readData(ifstream &fin, double &side1, double &side2, double &side3)
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

double calcPerimeterTriange(double side1, double side2, double side3)
{
    double perimeter;

    perimeter = side1 + side2 + side3;

    return (perimeter);
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

    area = (pow(side1, 2) * sqrt(3)) / 4;

    return(area);
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

double calcAreaTriangle( double side1, double side2, double side3 )
{
    double s,
           area;

    s =  calcPerimeterTriange( side1, side2, side3 ) / 2;
    area = sqrt( s * ( s - side1 ) * ( s - side2 ) * ( s - side3 ) );

    return (area);
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
