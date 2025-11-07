// Chapter 4
// COSC 1436

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
    std::cout << "\033[" << (int)color << "m";
}

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

void ViewMovies( Movie movies[], int size )
{
    //Enumerate movies until we run out
    for (int index = 0; index < size; ++index)
    {
        if (movies[index].title == "")
            return;

        ViewMovie(movies[index]);
    };
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
void DeleteMovie()
{
    Movie movie;
    if (!Confirm("Are you sure want to delete " + movie.title + "?"))
        return;

    //TODO: Delete movie
    //DisplayWarning("Not implemented yet");
    movie.title = "";
}

void EditMovie()
{
    DisplayWarning("Not implemented yet");
}

int AddToMovieArray(Movie movies[], int size, Movie movie)
{
    //Enumerate the array looking for the first blank movie
    for (int index = 0; index < size; ++index)
    {
        if (movies[index].title == "")
        {
            //Set the array element
            movies[index] = movie;
            return index;
        }
    }

    DisplayError("No space available for new movie");
    return -1;

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


int Factorial(int value)
{
    if (value <= 1)
        return 1;
    return value * Factorial(value - 1);
}


void DisplayRow(int values[], int size)
{
    for (int row = 0; row < size; ++row)
    {
        //Do stuff here
        std::cout << values[row] << " ";
    }
}

//All dimensions beyond first must be specified in parameter declaration
void DisplayTable(int table[][31], int size)
{
    for (int row = 0; row < size; ++row)
    {
        DisplayRow(table[row], 31);
        std::cout << std::endl;
    }     
}

void PointerDemo()
{
    int localInt = 1234;

    //Pointer to an int, 
    int* pInt;
    pInt = &localInt;

    
    localInt = 9876;

    //Dereferencing a pointer returns the original T value
    *pInt = 5678;
}

int main()
{
    PointerDemo();
    
    // Cannot calculate the size of an array at runtime so use a const int variable
    // 1) size is required at declaration, 2) size > 0, 3) it must be a const intergar expression, known at compiler time, 4)
    const int MaximumMovies = 100;

    //TODO: Leaving this for now to avoid breaking code
    //Movie movie;
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
            case 'a': AddToMovieArray(movies, MaximumMovies, AddMovie()); break;

            case 'V':
            case 'v': ViewMovies(movies, MaximumMovies); break;

            case 'D':
            case 'd': DeleteMovie(); break;

            case 'E':
            case 'e': EditMovie(); break;

            case 'Q':
            case 'q': done = true;

            default: DisplayError("Invalid choice"); break;
        };
    } while (!done);

    //std::cin.ignore();
    // Function call ::= func ()
    //ViewMovie();
}

// Chapter 7
// Hexadecimal 
// Memory        Size
// Byte          1               256=2^8
// Kilobyte      1024 B = 1 MB
// Megabyte      1024 KB
// Gigabyte      1024 MB
// Terabyte      1024 GB
// Pentabyte     1024 TB
// Exabyte       1024 PB
// Programs have a 128 TB limit of memory
// First half of memory is used by OS, 64TB, the rest is used by the program
// Second half is used by program, heap, and callstack 3thirdlys
// Overloads happens because heap and callstack collide and flow into each other
// 64-bit processor uses 8 bytes to address
// Pointers are 16 EB, can be stored in 64-bit processor
// A pointer is a memory address, or dynamic memory, allocates memory when it needs it
// Never assume the size of a pointer, 
// 1) getting a memory address of a value, 2) allocate new memory, 3) a pointers value is always a memorys address, 4) and is what it points to if int then int, 
// * = pointer ex: int* pInt; reading from left to right
// *p = dereference opeator