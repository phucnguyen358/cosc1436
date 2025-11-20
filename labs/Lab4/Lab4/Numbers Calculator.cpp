#include <iostream>
#include <iomanip>

using namespace std;

const int MAX_SIZE = 100;

// Function: programInfo
// Purpose : Displays the program title, student name, course, and semester
// Inputs  : None
// Returns : Nothing
void programInfo()
{
    cout << "Numbers Calculator" << endl;
    cout << "Phuc Nguyen" << endl;
    cout << "COSC 1436 Fall 2025" << endl;
}

// Function: getMenuChoice
// Purpose : Displays the main menu and gets a validated user choice
// Inputs  : None
// Returns : A valid uppercase menu option (A, L, M, S, I, V, Q)
char getMenuChoice()
{
    char choice;

    while (true)
    {
        cout << endl;
        cout << "Main Menu" << endl;
        cout << "------------------" << endl;
        cout << "A) dd" << endl;
        cout << "L) argest" << endl;
        cout << "M) ean" << endl;
        cout << "S) mallest" << endl;
        cout << "I) nsert" << endl;
        cout << "V) iew" << endl;
        cout << "Q) uit" << endl;
        cout << "Enter option: ";

        cin >> choice;

        // Manual conversion to uppercase:
        if (choice >= 'a' && choice <= 'z')
        {
            choice = choice - 32; // Convert lowercase -> uppercase
        }

        // Validate input
        if (choice == 'A' || choice == 'L' || choice == 'M' ||
            choice == 'S' || choice == 'I' || choice == 'V' ||
            choice == 'Q')
        {
            return choice; // valid choice
        }
        cout << "Invalid option. Please try again." << endl;
    }
}

// Function: getValues
// Purpose : Prompts the user to enter values and store them inside the array
// Inputs  : arr - the array to store values in
//           maxSize - maximum allowable array size
// Returns : The number of valid values entered (does not include 0 or negatives)
int getValues(int arr[], int maxSize)
{
    int count = 0;

    while (count < maxSize)
    {
        int val;
        cout << "Enter a value: ";
        cin >> val;

        if (val < 0)
        {
            cout << "You must enter a value greater than or equal to 0" << endl;
            continue; // ask again, but doesn't advance count
        }

        if (val == 0)
        {
            // Stop, but don't store 0 in the array
            break;
        }

        arr[count++] = val;
    }

    return count; // number of valid values entered
}

// Function: getLargest
// Purpose : Return the largest value in the array
// Inputs  : arr - the array of integers
//           count - number of valid elements in arr
// Returns : The largest integer in arr[0..count-1]
int getLargest(const int arr[], int count)
{
    int largest = arr[0];

    for (int i = 1; i < count; ++i)
    {
        if (arr[i] > largest)
        {
            largest = arr[i];
        }
    }

    return largest;
}

// Function: getSmallest
// Purpose : Return the smallest value in the array
// Inputs  : arr - the array of integers
//           count - number  of valid elements in arr
// Returns : The smallest integer in arr[0..count-1]
int getSmallest(const int arr[], int count)
{
    int smallest = arr[0];
    
    for (int i = 1; i < count; ++i)
    {
        if (arr[i] < smallest)
        {
            smallest = arr[i];
        }
    }

    return smallest;
}

// Function: getMean
// Purpose : Compute the average (mean) of the value in the array
// Inputs  : arr - integer array
//           count - number of valid elements
// Returns : The mean as a double (returns 0 if count is 0)
double getMean(const int arr[], int count)
{
    if (count == 0)
        return 0; // Avoids divide-by-zero

    double sum = 0;

    for (int i = 0; i < count; ++i)
    {
        sum += arr[i];
    }

    return sum / count;
}

// Function: getSum
// Purpose : Return the sum of all values in the array
// Inputs  : arr - integer array
//           count - number of valid elements
// Returns : The total sum of arr[0..count-1]
int getSum(const int arr[], int count)
{
    int sum = 0;

    for (int i = 0; i < count; ++i)
    {
        sum += arr[i];
    }

    return sum;
}

// Function: displayValues
// Purpose : Display array values with 10 values per line
// Inputs  : arr - integer array
//           count - number of valid elements
// Returns : Nothing
void displayValues(const int arr[], int count)
{
    if (count == 0)
    {
        cout << "No values available." << endl;
        return;
    }

    for (int i = 0; i < count; ++i)
    {
        cout << arr[i] << "    "; // spaces between values

        // After every 10th value, start a new line
        if ((i + 1) % 10 == 0)
        {
            cout << endl;
        }
    }

    cout << endl;   // final newline
}

// Function: insertValues
// Purpose : Allow the user to add more values to the array
// Inputs  : arr - integer array
//           count - (reference) current number of stored values
//           maxSize - maximum array capacity
// Returns : Nothing (count is updated to include to new values)
void insertValues(int arr[], int& count, int maxSize)
{
    // If array is already full, do nothing
    if (count >= maxSize)
    {
        cout << "Array is full. Cannot insert more values." << endl;
        return;
    }

    while (count < maxSize)
    {
        int val;
        cout << "Enter a value: ";
        cin >> val;

        if (val < 0)
        {
            cout << "You must enter a value greater than or equal to 0" << endl;
            continue; // don't change count, just reprompt
        }
        if (val == 0)
        {
            // done inserting
            break;
        }
        // positive value and room left
        arr[count] = val;
        count++;
    }
}

int main()
{
    programInfo();
    cout << endl;

    int arr[MAX_SIZE];

    int count = getValues(arr, MAX_SIZE);

    char choice;

    do
    {
        choice = getMenuChoice();

        switch (choice)
        {
            case 'L':
            {
                if (count > 0)
                {
                    int largest = getLargest(arr, count);
                    cout << "Largest = " << largest << endl;
                } else
                {
                    cout << "No values available." << endl;
                }
                break;
            }

            case 'M':
            {
                if (count > 0)
                {
                    double mean = getMean(arr, count);
                    cout << "Mean = " << fixed << setprecision(4) << mean << endl;
                } else
                {
                    cout << "No values available." << endl;
                }
                break;
            }

            case 'V':
            {
                displayValues(arr, count);
                break;
            }

            case 'A':
            {
                if (count > 0)
                {
                    int sum = getSum(arr, count);
                    cout << "Sum = " << sum << endl;
                }
                break;
            }

            case 'S':
            {
                if (count > 0)
                {
                    int smallest = getSmallest(arr, count);
                    cout << "Smallest = " << smallest << endl;
                } else
                {
                    cout << "No values available." << endl;
                }
                break;
            }

            case 'I':
            {
                insertValues(arr, count, MAX_SIZE);
                break;
            }

            case 'Q':
                break;
        }
    } while (choice != 'Q');

    return 0;
}