/*
 * COSC 1436
 * Lab 5
 * Trip Planner
 * Phuc Nguyen
 * Fall 2025
 */

#include <iostream>
#include <cctype>
#include <iomanip>
#include <cmath>
#include <string>

using namespace std;

struct Stop
{
    int x;
    int y;
};

const int MaxStops = 100;

/// <summary>Displays program information.</summary>
void DisplayProgramInformation()
{
    cout << "Lab 5 - Trip Planner" << endl;
    cout << "COSC 1436 - Fall 2025" << endl;
    cout << "Phuc Nguyen" << endl;
    cout << "-------------------------------" << endl << endl;
}

/// <summary>Reads an integer from the user within the given range.</summary>
/// <param name="prompt">Prompt text.</param>
/// <param name="minValue">Minimum allowed value.</param>
/// <param name="maxValue">Maximum allowed value.</param>
/// <returns>Validated integer in the given range.</returns>
int ReadIntInRange(const string& prompt, int minValue, int maxValue)
{
    int value;

    while (true)
    {
        cout << prompt;
        cin >> value;

        if (value >= minValue && value <= maxValue)
            return value;

        cout << "ERROR: Enter a value in the range "
            << minValue << " to " << maxValue << "." << endl;
    }
}

/// <summary>Displays the main menu and reads the user's selection.</summary>
/// <returns>Uppercase letter for the selected command.</returns>
char DisplayMainMenu()
{
    cout << endl;
    cout << "Main Menu" << endl;
    cout << "-----------" << endl;
    cout << "A)dd stop" << endl;
    cout << "V)iew trip" << endl;
    cout << "R)emove stop" << endl;
    cout << "C)lear trip" << endl;
    cout << "Q)uit" << endl;

    char choice;

    while (true)
    {
        cout << "Enter option: ";
        cin >> choice;

        choice = static_cast<char>(toupper(choice));

        switch (choice)
        {
            case 'A':
            case 'V':
            case 'R':
            case 'C':
            case 'Q':
                return choice;
        }

        cout << "Invalid menu option." << endl;
    }
}

/// <summary>Asks user to confirm quitting.</summary>
/// <returns>true to quit, false to return to menu.</returns>
bool HandleQuit()
{
    char answer;

    while (true)
    {
        cout << "Are you sure you want to quit? (Y/N): ";
        cin >> answer;

        answer = static_cast<char>(toupper(answer));

        if (answer == 'Y')
            return true;

        if (answer == 'N')
            return false;

        cout << "Invalid option. Please enter Y or N." << endl;
    }
}

/// <summary>Finds the next free index in the trip array.</summary>
/// <returns>Index of first nullptr, or -1 if full.</returns>
int FindNextFreeIndex(Stop* trip[], int maxSize)
{
    for (int i = 0; i < maxSize; ++i)
    {
        if (trip[i] == nullptr)
            return i;
    }
    return -1;
}

/// <summary>Gets the current number of stops.</summary>
int GetStopCount(Stop* trip[], int maxSize)
{
    int count = 0;

    for (int i = 0; i < maxSize; ++i)
    {
        if (trip[i] != nullptr)
            ++count;
        else
            break; // Keep the array compacted, so first null means "done"
    }
    return count;
}

/// <summary>Gets a stop pointer by stop number (1-based).</summary>
Stop* GetStopByNumber(Stop* trip[], int maxSize, int stopNumber)
{
    int index = stopNumber - 1;

    if (index < 0 || index >= maxSize)
        return nullptr;

    return trip[index];
}

/// <summary>Removes the stop at the given index and compacts the array.</summary>
void RemoveStopAtIndex(Stop* trip[], int maxSize, int index)
{
    if (index < 0 || index >= maxSize)
        return;

    if (trip[index] == nullptr)
        return;

    delete trip[index];
    trip[index] = nullptr;

    // Compacts the array: shift left until it hits first null
    int newIndex = index;

    for (int i = index + 1; i < maxSize; ++i)
    {
        trip[newIndex] = trip[i];
        newIndex++;

        if (trip[i] == nullptr)
            break;
    }

    // Clear the last moved slot
    if (newIndex < maxSize)
        trip[newIndex] = nullptr;
}

/// <summary>Deletes all stops and sets all entries to nullptr.</summary>
void ClearTrip(Stop* trip[], int maxSize)
{
    for (int i = 0; i < maxSize; ++i)
    {
        delete trip[i];
        trip[i] = nullptr;
    }
}

/// <summary>Reads and validates the user's speed (1–60 mph).</summary>
int ReadSpeed()
{
    return ReadIntInRange("Enter your speed (1 - 60 mph): ", 1, 60);
}

/// <summary>Calculates the distance between two points.</summary>
double CalculateDistance(int x1, int y1, int x2, int y2)
{
    int dx = x2 - x1;
    int dy = y2 - y1;

    return sqrt(static_cast<double>(dx * dx + dy * dy));
}

/// <summary>Calculates travel time in whole minutes, rounding up.</summary>
int CalculateTravelTimeMinutes(double distance, int speedMph)
{
    if (speedMph <= 0)
        return 0;

    double hours = distance / speedMph;
    double minutes = hours * 60.0;

    return static_cast<int>(ceil(minutes));
}

/// <summary>Handles the Add Stop menu option.</summary>
void HandleAddStop(Stop* trip[], int maxSize)
{
    int index = FindNextFreeIndex(trip, maxSize);

    if (index == -1)
    {
        cout << "Trip is full. Cannot add more stops." << endl;
        return;
    }

    int x = ReadIntInRange("Enter X coordinate (-100 to 100): ", -100, 100);
    int y = ReadIntInRange("Enter Y coordinate (-100 to 100): ", -100, 100);

    Stop* newStop = new Stop;
    newStop->x = x;
    newStop->y = y;

    trip[index] = newStop;

    cout << "Stop added as stop #" << (index + 1) << "." << endl;
}

/// <summary>Handles the View Trip menu option.</summary>
void HandleViewTrip(Stop* trip[], int maxSize, int speedMph)
{
    int count = GetStopCount(trip, maxSize);

    if (count == 0)
    {
        cout << "No stops in trip." << endl;
        return;
    }

    cout << endl;
    cout << left;
    cout << setw(6) << "Stop"
        << setw(15) << "Location"
        << setw(20) << "Distance (miles)"
        << setw(20) << "Time (minutes)" << endl;
    cout << string(60, '-') << endl;

    double totalDistance = 0.0;
    int    totalMinutes = 0;

    int prevX = 0;
    int prevY = 0;

    for (int i = 0; i < count; ++i)
    {
        Stop* s = trip[i];

        double distance = CalculateDistance(prevX, prevY, s->x, s->y);
        int minutes = CalculateTravelTimeMinutes(distance, speedMph);

        totalDistance += distance;
        totalMinutes += minutes;

        cout << setw(6) << (i + 1);

        cout << "(" << s->x << ", " << s->y << ")";
        int locWidth = 15 - static_cast<int>(
            to_string(s->x).size() + to_string(s->y).size() + 4);
        if (locWidth < 1) locWidth = 1;
        cout << setw(locWidth) << " ";

        cout << fixed << setprecision(2)
            << setw(20) << distance
            << setw(20) << static_cast<double>(minutes)
            << endl;

        prevX = s->x;
        prevY = s->y;
    }

    cout << string(60, '-') << endl;
    cout << setw(6) << count
        << setw(15) << ""
        << setw(20) << totalDistance
        << setw(20) << static_cast<double>(totalMinutes) << endl;

    cout << right;
}

/// <summary>Handles the Remove Stop menu option.</summary>
void HandleRemoveStop(Stop* trip[], int maxSize)
{
    int count = GetStopCount(trip, maxSize);

    if (count == 0)
    {
        cout << "No stops to remove." << endl;
        return;
    }

    int stopNumber = ReadIntInRange(
        "Enter stop number to remove (1 or higher): ", 1, count);

    if (GetStopByNumber(trip, maxSize, stopNumber) == nullptr)
    {
        cout << "Stop does not exist." << endl;
        return;
    }

    RemoveStopAtIndex(trip, maxSize, stopNumber - 1);

    cout << "Stop " << stopNumber << " removed." << endl;
}

/// <summary>Handles the Clear Trip menu option.</summary>
void HandleClearTrip(Stop* trip[], int maxSize)
{
    char answer;

    while (true)
    {
        cout << "Are you sure you want to clear the trip? (Y/N): ";
        cin >> answer;

        answer = static_cast<char>(toupper(answer));

        if (answer == 'Y')
        {
            ClearTrip(trip, maxSize);
            cout << "Trip cleared." << endl;
            return;
        }

        if (answer == 'N')
            return;

        cout << "Invalid option. Please enter Y or N." << endl;
    }
}

int main()
{
    DisplayProgramInformation();

    // create trip array (all nullptr)
    Stop* trip[MaxStops] = {nullptr};

    int speedMph = ReadSpeed();

    bool done = false;

    do
    {
        char command = DisplayMainMenu();

        switch (command)
        {
            case 'A': HandleAddStop(trip, MaxStops);               break;
            case 'V': HandleViewTrip(trip, MaxStops, speedMph);    break;
            case 'R': HandleRemoveStop(trip, MaxStops);            break;
            case 'C': HandleClearTrip(trip, MaxStops);             break;
            case 'Q':
                if (HandleQuit())
                    done = true;
                break;
        }

    } while (!done);

    // Clean up any remaining stops before exiting
    ClearTrip(trip, MaxStops);

    return 0;
}
