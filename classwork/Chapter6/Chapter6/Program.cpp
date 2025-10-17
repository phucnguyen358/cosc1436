// Chapter 4
// COSC 1436
// Notes: Never use global scope, only local scope, reasons are 1: its unrestricted, anybody can do anything they want outside of your code, 2: not mantainable, 3: not isolated, 4: memory allocation looks like int g_thisIsAVariable, so dont use g_ or global scope
//
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
// 2nd type of parmeter is 
/// 3rd type of parmeter is output / return type. The caller provides the storage for the storage, but not the value. The function is reponsible for leading the value.
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
    std::cout << std::fixed << std::setprecision(1) << std::endl;
    std::cout << movie.title << " (" << movie.releaseYear << ")" << std::endl;
    std::cout << "Run Length " << movie.runLength << " mins" << std::endl;
    std::cout << "Genres " << movie.genres << std::endl;
    std::cout << "Is Classic? " << (movie.isClassic ? "Yes" : "No") << std::endl;
    if (movie.description != "")
        std::cout << movie.description << std::endl;
    std::cout << std::endl;
}
/// <summary>/// Prompt user and add movie details./// </summary>
Movie AddMovie ()
{
    Movie movie;// = {0};

    //Get movie details
    movie.title = ReadString("Enter movie title: ", true);

    std::cout << "Enter the run length (in minutes): ";
    do
    {
        std::cin >> movie.runLength;

        //Error
        if (movie.runLength < 0)
        {
            DisplayError("Run length must be at least 0");
        }
    } while (movie.runLength < 0);

    std::cout << "Enter the release year (1900-2100): ";
    std::cin >> movie.releaseYear;
    while (movie.releaseYear < 1900 || movie.releaseYear > 2100)

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
void DeleteMovie(Movie movie)
{
    if (!Confirm("Are you sure want to delete " + movie.title + "?"))
        return;

    //TODO: Delte movie
    DisplayWarning("Not implemented yet");
}

void EditMovie(Movie movie)
{
    DisplayWarning("Not implemented yet");
}

int main()
{
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

        Movie movie;

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
