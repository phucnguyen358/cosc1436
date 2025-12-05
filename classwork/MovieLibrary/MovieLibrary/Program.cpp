// Chapter 4
// COSC 1436

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream> //File IO
#include <sstream> //Stringstream


//Movie details
struct Movie
{
    int id;                     //Unique identifier
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
void DisplayError(std::string const&);

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

void DisplayError( std::string const& message)
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

    if (std::cin.peek())
        std::cin.ignore();

    std::string input;
    std::getline(std::cin, input);

    while (isRequired && input == "")
    {
        DisplayError("Value is required");

        std::getline(std::cin, input);
    }

    return input;
}

void ViewMovie ( Movie* movie )
{
    //if (movie.title == "")
    if (!movie)
    {
        DisplayWarning("No movies exist");
        return;
    }

    std::cout << std::fixed << std::setprecision(1) << std::endl;
    std::cout << "Id " << movie->id << std::endl;
    std::cout << movie->title << " (" << movie->releaseYear << ")" << std::endl;
    std::cout << "Run Length " << movie->runLength << " mins" << std::endl;
    std::cout << "Genres " << movie->genres << std::endl;
    std::cout << "Is Classic? " << (movie->isClassic ? "Yes" : "No") << std::endl;
    if (movie->description != "")
        std::cout << movie->description << std::endl;
    std::cout << std::endl;
}

void ViewMovies( Movie* movies[], int size )
{
    //Enumerate movies until we run out
    //for (Movie movie
    for (int index = 0; index < size; ++index)
    {
        //if (movies[index].title == "")
        //    return;
        if (movies[index])
        ViewMovie(movies[index]);
    };
}
/// <summary>Prompt user and add movie details.</summary>
Movie* AddMovie ()
{
    //Movie movie;// = {0};
    Movie* movie = new Movie;

    //Get movie details
    movie->title = ReadString("Enter movie title: ", true);

    std::cout << "Enter the run length (in minutes): ";
    movie->runLength = ReadInt(0);

    std::cout << "Enter the release year (1900-2100): ";
    //std::cin >> movie->releaseYear;
    movie->releaseYear = ReadInt(1900, 2100);

    movie->description= ReadString("Enter the optional description: ", false);

    // Genres, up to 5
    for (int index = 0; index < 5; ++index)
    {
        std::string genre = ReadString("Enter the genre (or blank to continue): ", false);
        if (genre == "")
            break;
        else if (genre == " ")
            continue;

        movie->genres = movie->genres + ", " + genre;
    }

    movie->isClassic = Confirm("Is this a classic movie?");

    return movie;
}

Movie* FindMovie(Movie* movies[], int size, int id)
{
    for (int index = 0; index < size; ++index)
    {
        //If pointer valid and movie matches ID then return it
        if (movies[index] && movies[index]->id == id)
            return movies[index];
    }

    return nullptr;
}

void RemoveMovieFromArray(Movie* movies[], int size, Movie* movie)
{
    for (int index = 0; index < size; ++index)
    {
        if (movies[index] = +movie)
        {
            movies[index] = nullptr;
            delete movie;
            return;
        }
    }
}
/// <returns></returns>
void DeleteMovie(Movie* movies[], int size)
{
    // Get movie to delete
    std::cout << "Enter the movie ID to delete: ";
    int id = ReadInt(1);
    
    // Find the movie
    Movie* movie = FindMovie(movies, size, id);
    if (!movie)
    {
        DisplayWarning("Movie not found");
        return;
    }

    if (!Confirm("Are you sure want to delete " + movie->title + "?"))
        return;

    //DeleteMovie
    RemoveMovieFromArray(movies, size, movie);
}

void EditMovie()
{
    DisplayWarning("Not implemented yet");
}

int AddToMovieArray(Movie* movies[], int size, Movie* movie)
{
    static int nextId = 1;
    // Using pointers as parameters:
    // Validate parameters first
    // Pointers generally should not null
    if (movie == nullptr)
    {
        DisplayError("Invalid movie");
        return -1;
    }

    //Enumerate the array looking for the first blank movie
    for (int index = 0; index < size; ++index)
    {
        //if (movies[index].title == "")
        //if (!movies[index] == nullptr
        if (!movies[index])
        {
            //Set unique ID of movie
            // movie.id = 0; For structures use parameter access
            movie->id = nextId++;
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

    // Pointer - memory address
    // Data points
    // Pointer value is a memory address ( 8 bytes)
    // Value pointed to by pointer (dereferenced avalue) is int ( 4 bytes)
    // pointer_decl ::+ T* id
    int* pInt;            //Pointer to an int
    pInt = &localInt;    // Using & to convert pointer to int

    
    localInt = 9876;

    //Dereferencing a pointer returns the original type T
    // dereference_op := *ptr
    *pInt = 5678;

    // An uninitialized pointer points to garbage, pointers should be pointed to valid memory, memory 0 is always invalid, any type is pointer is valid
    // Initialize pointer to memory 0 which is invalid
    //      NULL - C version, not preferred as it is still an int
    // nullptr - preferred in C++
    //float* pFloat = NULL;  Null is defined as zero under the hood, no different than this |
    float* pFloat = nullptr;                                                              //|
    //pFloat = 0;  Don't do this          <-------------------------------------------------<
    //pFloat = 1234;



    // ALways ensure pointer is valid(not null) before dereferencing
    //if (pFloat != nullptr)
    if (pFloat) 
    {
        //This is going to crash hard if pointer is NULL
        *pFloat = 123.45;
    }
    
    //Initializing a pointer
    // nullptr
    float localFloat = 123.45;

    // Inintalize a pointer to a local variable or parameter
    pFloat = &localFloat; // Address of localFloat, must be a variable

    *pFloat = 456.78; //localFloat = 456.78

    //Initialize a pointer to an array element
    float someFloats[10] = {0};
    pFloat = &someFloats[1]; // Ptr references second element

    //Compiler error, types must exactly match
    //pFloat = pInt; // float* = int*

    //Dynamic memory
    // new_op ::= new T returns T*
    pFloat = new float;
    *pFloat = 89.76;

    for (int index = 0; index < 10000; ++index) //Clean up memory
    {
        pFloat = new float;
        *pFloat = index;

        //never doubley delete a pointer, assign it to null, it will crash or corrupt memory
        delete pFloat; 
        pFloat = nullptr;

        //Ensure you call delete for rach pointer you allocate using new
        //these two lines always go together |
        delete pFloat;                //<----|
        pFloat = nullptr;
        //*pFloat = index; //using a deallocated pointer may crash or corrupt
    }

    //Pointer assignment must exactly match the types used (no coercion)
    // pFloat = float
    // someFloat[1] = float
    // &(Et) = T*
    // &(someFloats[1]) = &(float) = float*
    
}

// Pointers vs pass by ref
void EditMovieWithPassByReference(Movie& movie) //C++ with pass by ref, prefereed
{
    movie.title = ReadString("Enter the new title: ", true);

    std::cout << "Enter the new run length: ";
    movie.runLength = ReadInt(0);
}

//Switching from ref to pointers
// 1. Change ref parameter to pointer
// 2. Validate the parameter
// 3. Dereference to get underlying value or use pointer access op

void EditMovieWithPointer(Movie* movie) //C with pointers, only if needed
{
    if (movie == nullptr)
        return;

    //movie.title = ReadString("Enter the new tite: ", true);
    movie->title = ReadString("Enter the new tite: ", true);

    std::cout << "Enter the new run length: ";
    movie->runLength = ReadInt(0);
}

void ArrayAndPointerDemo()
{
    // *** Need to understand later ***
    const int MaxSize = 100;

    int numbers[MaxSize];
    
    for (int index = 0; index < MaxSize; ++index)
        numbers[index] = index + 1;

    for (int index = 0; index < MaxSize; ++index)
        std::cout << numbers[index] << std::endl;

    //Arrays and pointers are COMPLETELY interchangeable
    int* pNumbers = numbers;
    
    for (int index = 0; index < MaxSize; ++index)
        numbers[index] = index + 1; //Can use array syntax with pointers and vice versa

    //Can enumerate without using array element operator
    int* pElement = pNumbers = numbers;
    for (int index = 0; index < MaxSize; ++index)
        //std::cout << numbers[index] << std::endl;
        std::cout << *(pElement + index) << std::endl;

    pElement = numbers;
    for (int index = 0; index < MaxSize; ++index)
        //std::cout << numbers[index] << std::endl;
        std::cout << *(pElement++) << std::endl;
}

/**int* ResizeArray(int* array[], int oldSize, int newSize)
{
    if (newSize <= 0)
    {
        DisplayError("I don't think so");
        return nullptr;
    }
    //int* pNewValue = new int;

    //newSize > 0
    int* pNewArray = new int[newSize];

    // Init the array because we cannot use int syntax with new
    for (int index = 0; index < newSize; ++index)
        pNewArray[index] = 0;

    // Copy values from old to new array
    oldSize = (oldSize < newSize) ? oldSize : newSize;
    for (int index = 0; index < oldSize; ++index)
        pNewArray[index] = array[index];
    
    return pNewArray;
}*/

void DeleteArray(int array[])
{
    //Rules
    // 1. THe array better have been allocated using new
    // 2. You must delete the entire array using delete[] if not memory leak
    // 3. If delete[] is called on a null ptr it will most likely crash
    if (array)
        delete[] array;
    array = nullptr;
}

int youWillNeverDoThis = 100;
int* ReturningAPointerDemo(int someValue, int values[])
{
    int* ptr = nullptr;

    // Valid cases for returning a pointer
    // 1. Dynamcially allocated memory using new
    ptr = new int;
    // 2. Elements of an array parameter
    ptr = &values[0];
    // 3. Global variables
    ptr = &youWillNeverDoThis;

    // Invalid cases
    // 1. Parameters  (ptr = &someValue)
    // 2. Local variables (int localVar; ptr= &localVar;)
    
    return nullptr;
}


void LoadMovies(Movie* movies[], int size)
{
    //TODO: Implement this
}

std::string QuoteString(std::string const& value)
{
    std::stringstream str;

    //If no starting double quote, then add double quote
    if (value.length() == 0 || value[0] != '"')
        str << '"';
    str << value;

    //If no ending double quote, then add double quote
    if (value.length() == 0 || value[value.length() - 1] != '"')
        str << '"';

    return str.str();
}

void SaveMovie(std::ofstream& file, Movie* pMovie)
{
    if (!pMovie)
        return;

    //Id, title, release year, run length, isClassic, genres, description
    file << pMovie->id
        << ", " << QuoteString(pMovie->title)
        << ", " << pMovie->releaseYear
        << ", " << pMovie->runLength
        << ", " << (pMovie->isClassic ? 1 : 0)
        << ", " << QuoteString(pMovie->genres)
        << ", " << QuoteString(pMovie->description)
        << std::endl;
}


void SaveMovies(const char* filename, Movie* movies[], int size)
{
    /*std::fstream fs;
    std::ifstream ifs;
    std::ofstream ofs;*/

    std::ofstream file;

    //To use a file, must open it
    // Flags (bitwise OR together)
    // in | out - access mode
    // binary - text or binary
    // app | ate | trunc - write mode
    //      app - append (always)
    //      app - appead (by default)
    //      trunc - replace
    file.open(filename, std::ios::out | std::ios::trunc);
    if (file.fail())
    {
        DisplayError("Unable to save movies");
        return;
    }

    //file << "Writing to the file";
    for (int index = 0; index < size; ++index)
        SaveMovie(file, movies[index]);
}


int main()
{

    const char* FileName = "movies.csv";

    //ReturningAPointerDemo();

    //ArrayAndPointerDemo();

    //Movie movie;

    ////Calling pass by reference function
    //EditMovieWithPassByReference(movie);

    ////Calling with pointer
    //// 4. Must use address of if normal variable, or pointer
    //EditMovieWithPointer(&movie);

    //PointerDemo();
    
    // Cannot calculate the size of an array at runtime so use a const int variable
    // 1) size is required at declaration, 2) size > 0, 3) it must be a const intergar expression, known at compiler time, 4)
    const int MaximumMovies = 100;
    Movie* movies[MaximumMovies] = {0};

    LoadMovies(movies, MaximumMovies);


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
            case 'd': DeleteMovie(movies, MaximumMovies); break;

            case 'E':
            case 'e': EditMovie(); break;

            case 'Q':
            case 'q': SaveMovies(FileName, movies, MaximumMovies); done = true; break;

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
// Heaps: 
// Pointers are passby values but can be referenced
// 3 valid cases of returning a pointer:
// dynamic memory
// type a array
// global variables

// Quiz 3
// Define function: named block of code reused by other code
// getemployee question: must pass arugment inside parameters, answer is the getemployee(), not passing any arugments
// Factorial question: no exit clause, crashes with overflow
// * Which does not impact function overload resolution question: looks at name, number, type so arugment type and order, never return type so return type is answer
// return statement exits a function
// not a valid function declaration: int, string is not a valid function declaration
// FuncA calls FuncB question: CallStack called from bottom to top, FuncA () calls FuncA() so A is declared, so answer is A,B,C | C,B,A
// 10 for input question: bypass value stays 10
// Speed is not a benefit of a function
// given following code question: 10
// void is special type
// callstack bottom up
// local variables and parameters are stored in callstack
// Fibonacci question: if(value <=0), not return 0 because itll mess up the value
// input output question: input is copied to the parameter, input/output is address, output is caller passes
// CalculatePay Question: return result
// PI question: diameter
// overload display10 question: 10 is int
// parameer is the name of fuction
// somefunction question: parameter needs & so answer is int, std::string&

//Quiz 4:
// One of the answers is Set_New_Handler

//Lab5:
//Story 6 no gap example:
// When deleting a point, the previous points must move up including the null point

// 6 variations of Const
// Should read from right to left
// T * - ptr to T / can read and write
// T * Const - const ptr to T / 
// 
// 3 types of Streams: fstreams, ifstreams, ofstreams
// Fstreams: can read and write, ifstream: can read(input, cin), ofstreams: write(output,cout)
// 

// Quiz 5:
// one of the answers is BCPL

// Error at 471