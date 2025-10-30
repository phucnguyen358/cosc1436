// Lab 3
// Phuc Nguyen
// COSC 1436 Fall 2025
#include <iostream>
#include <iomanip>
using namespace std;

//Functions//

//Program information
void showProgramInfo()
{
    cout << "FallingDistance Calculator" << endl;
    cout << "Phuc Nguyen" << endl;
    cout << "COSC 1436 Fall 2025" << endl;
    cout << endl;
}

//Prompts the user for number of seconds (1-60)
int promptSeconds()
{
    int seconds;
    do
    {   
        cout << "Please enter the number of seconds: ";
        cin >> seconds;

        if (seconds >= 1 && seconds <= 60)
            return seconds;

        cout << "ERROR: Enter a number in the range of 1-60" << endl;
    } while (true);
}

//Prompts user for desired unit (feet or meters)
char promptUnits()
{
    char unit;
    do
    {
        cout << "Do you want the results in meters or feet? ";
        cin >> unit;

        if (unit == 'm' || unit == 'M' || unit == 'f' || unit == 'F')
            return unit;

        cout << "Invalid input. Please enter 'f' for feet or 'm' for meters." << endl;
    } while (true);
}

// Calculates falling distance in meters for a given time
double fallingDistance(int t)
{
    const double g = 9.8;
    return 0.5 * g * t * t;
}

//Converts meters to feet
double metersToFeet(double meters)
{
    return meters * 3.28084;
}

// Prints the fall distance and velocity table
void print_fall_table(int seconds, char unit)
{
    const double g = 9.8;         // gravity in m/s^2
    const double terminal_m = 90; // terminal velocity in m/s
    const double m_to_ft = 3.28084;

    double factor = 1.0;
    string unit_str = "m";
    double terminal = terminal_m;

    //Determine conversion based on unit
    if (unit == 'f' || unit == 'F')
    {
        factor = m_to_ft;
        unit_str = "ft";
        terminal *= m_to_ft; // convert terminal velocity to ft/s
    }

    cout << endl;
    cout << "Seconds        Distance       Velocity" << endl;
    cout << "======================================" << endl;
    cout << fixed << setprecision(2);

    for (int t = 1; t <= seconds; ++t)
    {
        double distance = fallingDistance(t) * factor;
        double velocity = g * t * factor;

        ///Cap velocity at terminal speed
        if (velocity > terminal)
            velocity = terminal;

        cout << setw(6) << t
            << setw(14) << distance << " " << unit_str
            << setw(10) << velocity << " " << unit_str << "/s"
            << endl;
    }
}

// Main program //

int main()
{
    showProgramInfo();

    int seconds = promptSeconds();
    char unit = promptUnits();
        
    ///Display results
    print_fall_table(seconds, unit);

    return 0;
}
