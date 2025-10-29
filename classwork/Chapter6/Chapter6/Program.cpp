// Chapter 4
// COSC 1436
// Notes: Never use global scope, only local scope, reasons are 1: its unrestricted, anybody can do anything they want outside of your code, 2: not mantainable, 3: not isolated, 4: memory allocation looks like int g_thisIsAVariable, so dont use g_ or global scope, need to understand the 3 best types of loops to use (for, while, do). Switch expression is limited to a integer value. Can only be a intergal and char. Also must be unique and constant integer. Short circuit evualtion skips the evaultion of set numbers: EX A && B, if A is false then it doesnt matter what B is. The side effect of increment/decrement is everytime a operator is called, the value is changed. 
// Function overload: using the same function name for multiple implantations, to get over overloading, use different number of parameter types.
// Arrays: list of values of the same type, Type ID[Eci] ex: Int Grades[25] grades for 25 students, [Eci] is the size or # of elements, Element is a singular value, stored in a array
// Cant define a array without declaring the size, if you define a array without a value it is a open array which is a array of unknown size, A closed/opened array is a array of fixed size, only for the declaration of the variable that the size is fixed, otherwise it is undefined
// The number inside the array must be greatere than 0 and a const int expression, at runtime there is no way to calulate the value of an array,
// How to calulate bytes: bytes = size(type)*size so for grades for 25 students the size is 100 because an int is 4 bytes. 4*25=100 strings are 8 bytes, bools are 1
// saying x[n] is the same as [25], must start at 0 for arrays, at runtime you can not determine the value of a array
// Factorial function
#include <iostream>
#include <string>
#include <iomanip>


//Movie details
struct Movie
{
    std::string title;          //Required
    std::string description;    //Optional
    int runLength;              //Required, 0
    int releaseYear;            //Optional, but between 1900-2100
    bool isClassic;             //Required, false
    std::string genres;         //Optional (comma separated list of genres)
};

enum class ForegroundColor {
    Black = 30,
    Red = 31,
    Green = 32,
    Yellow = 33,
    Cyan = 36,
    BrightRed = 91,
    BrightGreen = 92,
    BrightYellow = 93,
    BrightCyan = 96
};

// Function prototypes
// Forward delcarations/referencing
void DisplayError(std::string);

void ResetTextColor()
{
    std::cout << "\033[0m";
}

void SetTextColor( ForegroundColor color )
{
    std::cout << "\033[" << (int)color << "n";
}
/// <summary>Display a confirmation message.</summary>
/// <param name="message">Message to show.</param>
/// <returns>Returns true or false depending on whenever confirmed or not.</returns>
bool Confirm ( std::string message )
{
    std::cout << message << " (Y/N) ";
    std::string input;
    std::cin >> input;

    while (true)
    {
        if (_strcmpi(input.c_str(), "Y") == 0)
            return true;
         else if (_strcmpi(input.c_str(), "N") == 0)
            return false;
         else {
            DisplayError("You must enter either Y or N");

            std::cin >> input;
         }
    }
}
// 3 Kinds of Pameters, 1st is input parameter / pass by value looks like "T id", define "Parameter", parameters are used to get data or "arugments" outside the function into a function
// 2nd type of parmeter is input output parameter / pass by reference. It bypasses the main to return a value. Don't use if you don't need. Only use to return a function when another function is declared. Not used in labs at least of 10/21/25
// 3rd type of parmeter is output / return type looks like "T func()". The caller provides the storage for the storage, but not the value. The function is reponsible for leading the value.
/// <summary>Displays an error message.</summary> 
/// <param name="message">Message to display.</param>
void DisplayError(std::string message)
{
    //std::cout << "\033[91m"
    SetTextColor(ForegroundColor::BrightRed);
    std::cout << "ERROR: " << message << std::endl;
    ResetTextColor();
}
/// <summary>Displays an warning message.</summary>
/// <param name="message">Message to display.</param>
void DisplayWarning(std::string message)
{
    SetTextColor(ForegroundColor::BrightYellow);
    std::cout << message << std::endl;
    ResetTextColor();
}

int ReadInt( int minimumValue, int maximumValue )
{
    do
    {
        int value;
        std::cin >> value;

        if (value >= minimumValue && value <= maximumValue)
            return value;
        
            DisplayError("Value is outside range");
    } while (true);
}

int ReadInt(int minimumValue)
{
    return ReadInt(minimumValue, INT_MAX);
}


std::string ReadString ( std::string message, bool isRequired )
{
    std::cout << message;

    std::string input;
    std::getline(std::cin, input);

    while (isRequired && input == "")
    {
        DisplayError("Value is required");

        std::getline(std::cin, input);
    }

    return input;
}
/// <summary>View details of a movie./// </summary>
/// <remarks>
/// More details including paragraphs of data if you want.
/// </remarks> Every function tag has to have summaries, variables are named as nouns, functions are named as verbs, function names must be unique, a function must be declared before used like variables, main is typically located at the bottom, functions are reusable blocks of code, functions are incapilated, functions dont affect speed no downsides or upsides,

void ViewMovie( Movie movie )
{

    // View movie
    //    Title (Year)
    //    Run Length # min
    //    User Rating = ##
    //    Is Classic? 
    //    [Description]
    if (movie.title == "")
    {
        DisplayWarning("No movies exist");
        return;
    }

    std::cout << std::fixed << std::setprecision(1) << std::endl;
    std::cout << movie.title << " (" << movie.releaseYear << ")" << std::endl;
    std::cout << "Run Length " << movie.runLength << " mins" << std::endl;
    std::cout << "Genres " << movie.genres << std::endl;
    std::cout << "Is Classic? " << (movie.isClassic ? "Yes" : "No") << std::endl;
    if (movie.description != "")
        std::cout << movie.description << std::endl;
    std::cout << std::endl;
}
/// <summary>Prompt user and add movie details.</summary>
Movie AddMovie ()
{
    Movie movie;// = {0};

    //Get movie details
    movie.title = ReadString("Enter movie title: ", true);

    std::cout << "Enter the run length (in minutes): ";
    movie.runLength = ReadInt(0);

    std::cout << "Enter the release year (1900-2100): ";
    std::cin >> movie.releaseYear;
    movie.releaseYear = ReadInt(1900, 2100);

    movie.description= ReadString("Enter the optional description: ", false);

    // Genres, up to 5
    for (int index = 0; index < 5; ++index)
    {
        std::string genre = ReadString("Enter the genre (or blank to continue): ", false);
        if (genre == "")
            break;
        else if (genre == " ")
            continue;

        movie.genres = movie.genres + ", " + genre;
    }

    movie.isClassic = Confirm("Is this a classic movie?");

    return movie;
}


/// <returns></returns>
void DeleteMovie(Movie& movie)
{
    if (!Confirm("Are you sure want to delete " + movie.title + "?"))
        return;

    //TODO: Delete movie
    //DisplayWarning("Not implemented yet");
    movie.title = "";
}

void EditMovie(Movie& movie)
{
    DisplayWarning("Not implemented yet");
}

// Test function overloading
void Display( int value )
{
    std::cout << "int" << std::endl;
}

void Display(double value)
{
    std::cout << "double" << std::endl;
}

void Display(float value)
{
    std::cout << "float" << std::endl;
}

void Display( int value1, double value2 )
{
    std::cout << "int, double" << std::endl;
}

void Display(short value, float)
{
    std::cout << "short, float" << std::endl;
}

void Display(int, short)
{
    std::cout << "short, int" << std::endl;
}

//void TestFunctionOverloading()
//{
//    Display(10);                //Display(Int)
//    Display(4.56);              //Display(Double)
//    Display((short)34);         //Display(Int) -> shortest type cooercion
//    Display(10, 4.56F);         //Display(Int, Double) F after a floating point double is a float
//
//    long lValue = 10000L;
//    Display(1000000000L, 4.56); //Display(Int, Double) L after value is a long
//
//    //Display("Hello", 4.56); Compiler error, no matches
//
//    //Display(10, "Hello"); Compiler error, no matches
//
//    Display('c', 4.56F); // short, float
//    Display((short)5, (short)10); 
//}
 //Stack overflow

int Factorial(int value)
{
    if (value <= 1)
        return 1;
    return value * Factorial(value - 1);
}

void ArrayDemo()
{
    const int MaxNumbers = 100;

    //Init array using { 0 } dont use this with strings
    int numbers[MaxNumbers] = {0};
    //int numbers[100];
    
    //# of days in each month
    //int daysInMonth[12] = { 0 };
    //Approach 1 - correct but not readable
    /*daysInMonth[0] = daysInMonth[2] = daysInMonth[4] = daysInMonth[5] = daysInMonth[6] = daysInMonth[7]
                   = daysInMonth[9] = daysInMonth[11] = 31;
    daysInMonth[1] = 28;
    daysInMonth[3] = daysInMonth[5] = daysInMonth[8] = daysInMonth[10] = 30;*/

    //Approach 2 - init expression
    // Zero init    - each is set to 0// { 0 }
    // Full init    - each element is assigned a value
    // Partial init - each element is assigned a value and remaining elements are 0 initalized
    int daysInMonth[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    //Implicit array sizing, not for partial init, and zero init, this is for strings
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    //Set each element to its element number (element 1 = 1, element 2 = 2, etc)
    //Apporach 1 for small arrays only
    numbers[0] = 1;
    numbers[1] = 2;
    numbers[2] = 3;

    //Approach 2 for any array
    for (int index = 0; index < MaxNumbers; ++index)
        numbers[index] = index + 1;

    for (int index = 0; index < MaxNumbers; ++index)
         std::cout << numbers[index] << std::endl;
}

int main()
{
    // Cannot calculate the size of an array at runtime so use a const int variable
    // 1) size is required at declaration, 2) size > 0, 3) it must be a const intergar expression, known at compiler time, 4)
    const int MaximumMovies = 100;

    //TODO: Leaving this for now to avoid breaking code
    Movie movie;
    Movie movies[MaximumMovies];
 
    // Array operative []
    //    A[index], 
    Movie firstElement = movies[0];

    //Display main menu
    bool done = false;
    do
    {
        std::cout << "Movie Library" << std::endl;
        std::cout << "--------------" << std::endl;
        std::cout << "A)dd Movie" << std::endl;
        std::cout << "V)iew Movies" << std::endl;
        std::cout << "E)dit Movie" << std::endl;
        std::cout << "D)elete Movie" << std::endl;
        std::cout << "Q)uit" << std::endl;

        char choice;
        std::cin >> choice;

        switch (choice)
        {
            case 'A':
            case 'a': movie = AddMovie();  break;

            case 'V':
            case 'v': ViewMovie(movie); break;

            case 'D':
            case 'd': DeleteMovie(movie); break;

            case 'E':
            case 'e': EditMovie(movie); break;

            case 'Q':
            case 'q': done = true;

            default: DisplayError("Invalid choice"); break;
        };
    } while (!done);

    //std::cin.ignore();
    // Function call ::= func ()
    //ViewMovie();
}
