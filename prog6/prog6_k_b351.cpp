/*
  File: prog6_k_b351.cpp

  Author: Kimberly Beal
  C.S.1428.751
  Lab Section: L52 
  Program: #6
  Due Date: 08/06/18
*/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>       // 4 Code::Blocks

using namespace std;

const int ROWS = 5,      // number of Fahrenheit temperatures
          COLS = 3;      // number of converted temperature scales

const int CEL = 0,       // column in which Celsius temperatures are stored
          RAN = 1,       // column in which Rankine temperatures are stored
          KEL = 2;       // column in which Kelvin temperatures are stored

const double KELVIN = 273.15,
             RANKINE = 459.67;

void printIdInfo( ostream &out, string AUTHORS, int SECTION, string DUE_DATE );
void printReportHeader ( ofstream &fout );
void readFahrenheitTemperatures ( ifstream &fin, int fahrenheit[ROWS] );
void convertFarenheit2Celsius ( int fahrenheit[ROWS],
                               double conversions[ROWS][COLS] );
void convertFahrenheit2Rankine ( int fahrenheit[ROWS],
                                double conversions[ROWS][COLS] );
void convertCelsius2Kelvin ( double conversions[ROWS][COLS] );
void printTemperatureConversionTable ( ofstream &fout, int fahrenheit[ROWS],
                                      double conversions[ROWS][COLS],
                                      const int PLACES );
void printFileNotification ( char output_filename[ ] );

int main ( )
{
    const string AUTHORS = "Kimberly Beal and Devin Roseman",
                 DUE_DATE = "08/06/18";

    const int SECTION = 751,
              MAX_LENGTH_FN = 20;

    char input_filename[MAX_LENGTH_FN + 1] = "prog6_751inp.txt",
         output_filename[MAX_LENGTH_FN + 1] = "prog6_751out.txt";

    const int PLACES = 2;

    int fahrenheit[ROWS];               // Fahrenheit temperatures

    double conversions[ROWS][COLS];     // stores Celsius, Rankine, Kelvin

    ifstream fin;
    fin.open( "prog6_751inp.txt" );

    if ( !fin )
    {
        cout << endl << endl
             << "***Program Terminated.***" << endl << endl
             << "Input file failed to open." << endl;

        system("PAUSE>NUL");

        return 1;
    }

    ofstream fout;
    fout.open( "prog6_751out.txt" );

    if ( !fout )
    {
        cout << endl << endl
             << " ***Program Terminated.*** " << endl << endl
             << "Output file failed to open." << endl;

        fin.close();

        system("PAUSE>NUL");

        return 2;
    }

    printIdInfo ( fout, AUTHORS, SECTION, DUE_DATE );
    printReportHeader ( fout );
    readFahrenheitTemperatures ( fin, fahrenheit );
    convertFarenheit2Celsius ( fahrenheit, conversions );
    convertFahrenheit2Rankine ( fahrenheit, conversions );
    convertCelsius2Kelvin ( conversions );
    printTemperatureConversionTable ( fout, fahrenheit, conversions, PLACES );
    printIdInfo ( cout, AUTHORS, SECTION, DUE_DATE );
    printFileNotification ( output_filename );

    fin.close( );
    fout.close( );

    system("PAUSE>NUL");

    return 0;
}

/*
    Function: printIdInfo

    The function printIdInfo prints the authors' identifying information
    (name, class/section number, lab section number, due date) on the first,
    second, third and fourth lines of the output. printIdInfo will leave two
    blank lines are printed after the due date. The output is directed to the
    screen or to an output file depending on the call.

    Sample Output:
                Authors' Names
                 C.S.1428.?               //'?' represents lecture section number
                Lab Section: L?          // '?' represents lab section number(s)
                 --/--/--                 // due date in this format
                    <blank line>
                    <blank line>


    Receives:  output stream variables;
               author(s) names (string);
               section number of the authors (int);
               due date of the program (string);
               in this order
    Constants: AUTHOR; SECTION; DUE_DATE
    Returns:   nothing - prints authors' identifying information
*/

void printIdInfo( ostream &out, string AUTHORS, int SECTION, string DUE_DATE )
{
    out << AUTHORS << endl
        << "C.S.1428." << SECTION << endl
        << "Lab Section: L52 and L52" << endl
        << DUE_DATE << endl << endl << endl;
}

/*
    Function: printReportHeader


    The function printReportHeader prints the title "Tempurature Conversion
    Table" with one line blank line before printing the column headers
    (Farenheit, Celsius, Rankine, and Kelvin, in that order) underneath the
    column headers is a line of dashes. This is done on the first, second,
    third, and fourth lines. printReportHeaders output is directed to the output
    file.

    Sample Output:
                      Temperature Conversion Table
                            <blank space>
              Farenheit    Celsius    Rankine     Kelvin
              ------------------------------------------


    Receives:  output stream variable;
    Constants: none
    Returns:   nothing - prints title and column headers;
*/

void printReportHeader ( ofstream &fout )
{
    fout << "        Temperature Conversion Table" << endl << endl
         << "Farenheit   Celsius     Rankine     Kelvin" << endl
         << "------------------------------------------" << endl;
}

/*
    Function: readFahrenheitTemperatures

    The function readFahrenheitTemperatures uses a for loop with one statement
    to read the Fahrenheit temperatures from an input file into a 1-D array.

    Receives:  input file variable; fahrenheit 1-D array;
               in this order
    Constants: ROWS
    Returns: fahrenheit[0], fahrenheit[1],...,fahrenheit[ROWS]
*/

void readFahrenheitTemperatures ( ifstream &fin, int fahrenheit[ROWS] )
{
    for ( int row = 0; row < ROWS; ++row )
        fin >> fahrenheit [row];
}

/*
    Function: convertFahrenheit2Celcius
    
    The function convertFahrenheit2Celcius converts Farenheit to Celcius and stores
    the converted Celcius to in the CEL address of the 2-D array. This is done by
    using a count loop with one statemet.

    Receives: Fahrenheit 1-D array (int); conversions 2-D array (double)
    Constants: ROWS (int); COLS (int); CEL (int)
    Returns: conversions of Farenheit  to Celcius  will be returned to the proper
             column of the 2-D array

*/

void convertFarenheit2Celsius ( int fahrenheit[ROWS],
                               double conversions[ROWS][COLS] )
{
    for ( int rows = 0; rows < ROWS; ++rows )
        conversions[rows][CEL] = ((5.0 / 9.0) * ( fahrenheit[rows] - 32 ));
}

/*
    Function: convertFahrenheit2Rankine

    The function convert Fahrenheit2Rankine converts Farenheit to Rankine and
    stores the converted Rankine in the RAN address of the 2-D array. This is
    done by using a count loop with one statemet.

    Receives: Fahrenheit 1-D array (int); conversions 2-D array (double)
    Constants: ROWS (int); COLS (int); RAN (int)
    Returns: conversions of Farenheit to Rankine will be returned to the proper
             column of the 2-D arraay
*/

void convertFahrenheit2Rankine ( int fahrenheit[ROWS],
                                double conversions[ROWS][COLS] )
{
    for ( int rows = 0; rows < ROWS; ++rows )
        conversions[rows][RAN] = fahrenheit[rows] + RANKINE;
}

/*
    Function: convertCelsius2Kelvin

    The function convertCelsius2Kelvin converts Celcius to kelvin and stores
    the converted kelvin in the KEL address of the 2-D array. This is done by
    using a count loop with one statemet.

    Receives: conversions 2-D array (double)
    Constants: ROWS (int); COLS (int); CEL (int); KEL (int); KELVIN (double)
    Returns: conversions of Celcius to kelvin will be returned to the proper
             column of the 2-D arraay
*/

void convertCelsius2Kelvin ( double conversions[ROWS][COLS] )
{
    for ( int rows = 0; rows < ROWS; ++rows )
        conversions[rows][KEL] = conversions[rows][CEL] + KELVIN;
}

/*
    Function: printTemperatureConversionTable

    The function printTemperatureConversionTable prints the table of the
    temperature conversions in there proper columns (CEL, RAN, KEL, in that
    order), for as many conversions as available using a countloop. The
    calculated conversions are to the second decimal place.

    Note: The title "Temperature Conversion Table", the blank space, the titles:
    "Farenheit", "Celsius", "Rankine", and "Kelvin"; and the dotted line are
    printed in a seperate function.

    Note: The question marks are replaced with numeric values that will vary
    with input.

    Sample Output:
                      Temperature Conversion Table
                            <blank space>
              Farenheit    Celsius    Rankine     Kelvin
              ------------------------------------------
                 ???          ?.??       ?.??       ?.??
                 ???          ?.??       ?.??       ?.??
                 ???          ?.??       ?.??       ?.??
                 ???          ?.??       ?.??       ?.??
                 ???          ?.??       ?.??       ?.??

    Receives: output stream variable; fahrenheit 1-D array (int);
              conversions 2-D array (double); PLACES (int)
    Constants: ROWS (int); COLS (int); CEL (int); KEL (int); KELVIN (double);
               PLACES (int)
    Returns: nothing-prints teperatures to there proper columns

*/

void printTemperatureConversionTable ( ofstream &fout, int fahrenheit[ROWS],
                                      double conversions[ROWS][COLS],
                                      const int PLACES )
{
    fout << fixed << setprecision (PLACES);

    for ( int rows = 0; rows < ROWS; ++rows )
    {
        fout << setw(9) << fahrenheit[rows]
        << setw(10) << conversions[rows][CEL]
        << setw(12) << conversions[rows][RAN]
        << setw(11) << conversions[rows][KEL] << endl;
    }
}

/*
     Function: printFileNotification

     The function printFileNotification prints a complete sentence to the screen
     letting the user know the name of the data file to which the triangle report
     has been written.

     Sample Output:

     The triangle report has been written to <output filename>.

     Receives:  output_filename[ ]
     Constants: none
     Returns:   nothing - prints file notification to the screen
*/

void printFileNotification ( char output_filename[] )
{
    cout << "The processed array data has been written to "
         << output_filename << "." << endl/a;
}
