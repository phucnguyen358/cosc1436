// Chapter 4
// COSC 1436

#include <iostream>
#include <string>
#include <iomanip>

//Movie details
// add variable. to the beginning of all variables after putting them into a structure, in this case we added movie.
struct Movie
{
    // Movie details
    std::string title;           //Required
    std::string description;     //Optional
    int runLength;               //Required, 0
    int releaseYear;             //Optional, between 1900-2100
    //double userRating;           //Optional 1.0-10.0
    bool isClassic;              //Required, false
    std::string genres;          //Optional (comma separate list of genres)
};

int main()
{
    //Demo prefix/postfix-increment/decrement
    // only works with ints
    /*std::cout << "Enter a value: ";
    int number;
    std::cin >> number;
    
    std::cout << "Prefix (++x) = " << ++number << ", x = " << number << std::endl;
    std::cout << "Prefix (--x) = " << --number << ", x = " << number << std::endl;
    std::cout << "Postfix (x++) = " << number++ << ", x = " << number << std::endl;
    std::cout << "Postfix (x--) = " << number-- << ", x = " << number << std::endl;*/

    // Demo nested loops 10x12=120
    // 1 2 3 4 5
    // 1 1 2 3 4 5
    // 2 2 4 6 8 10
    // 3 3 6 9 12 15
    // Be wary of performance issues as nested loops are the first culpit to look towards when suffering from performance issues
    /*for (int rows = 1; rows < 100; ++rows)
    {
        for (int cols = 1; cols < 10; ++cols)
        {
            std::cout << std::setw(4) << (rows * cols);
        }

        std::cout << std::endl;
    }*/
    //Display main menu
    bool done = false;
    do //while (!done)
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

        // Validate input
        //if (choice == "A" || choice == "a")
        //{
        //    //TODO: Move add code here
        //    std::cout << "Add not implmented" << std::endl;
        //} else if (choice == "V" || choice == "v")
        //{
        //    //TODO: Movie view code here
        //    std::cout << "View not implmented" << std::endl;
        //} else if (choice == "E" || choice == "e")
        //{
        //    std::cout << "Edit Not implmented" << std::endl;
        //} else if (choice == "D" || choice == "d")
        //{
        //    std::cout << "Delete implmented" << std::endl;
        //} else if (choice == "Q" || choice == "q")
        //{
        //    return 0;
        //} else
        //{
        //    std::cout << "Invalid choice" << std::endl;

        //}
        // switch is limited to integers and char, need to place break at the end of the line
        // place default last
        // when using multiple cases of the same letter, the first statement of each letter can be deleted, C++ will follow through to the next line
        // Declaring a variable
        // switch-statment
        // "std::cout << "View not implemented" << std::endl;
        // break;"

        switch (choice)
        {
            case 'A':
            case 'a': std::cout << "Add not implmented" << std::endl; done = true; break;

            case 'V':
            case 'v': std::cout << "View not implmented" << std::endl; done = true; break;

            case 'D':
            case 'd': std::cout << "Delete not implmented" << std::endl; done = true; break;

            case 'E':
            case 'e': std::cout << "Edit not implmented" << std::endl; done = true; break;

            case 'Q':
            case 'q': return 0;

            default: std::cout << "Invalid choice" << std::endl; break;
        };
    } while (!done);
    
    //int id;
    // always set 0 to {}
    Movie movie = {0};

    // Get movie details
    std::cout << "Enter movie title: ";
    std::cin.ignore();
    std::getline(std::cin, movie.title);
    // Title is required
  //  bool isEmpty = title == "";
   // if (isEmpty)
        while (movie.title == "")
        {
            std::cout << "Title is required" << std::endl;
            std::getline(std::cin, movie.title);
        }
    // Use block statement to pair to two statements
    std::cout << "Enter the run length (in minutes): ";
    /*runLength = -1;
    while (runLength < 0)
    {
        std::cin >> runLength;
        if (runLength < 0)
            std::cout << "ERROR: Run length must be at least 0" << std::endl;

    }*/
    //std::cin >> runLength;
    do //while (runLength < 0)
    {
        std::cin >> movie.runLength;
        //Error
        if (movie.runLength < 0)
        {
        
        std::string message = "Run length must be at least 0";
        std::cout << "ERROR: " << message << std::endl;
        }   

        //std::cin >> runLength;
    } while (movie.runLength < 0);
    


    std::cout << "Enter the release year (1900-2100): ";
    std::cin >> movie.releaseYear;
    /*if (releaseYear < 1900)
    {
        std::cout << "Release year must be at least 1900" << std::endl;
        releaseYear = 1900;
    } else if (releaseYear > 2100)
    {
        std::cout << "Release year must between 1900 and 2100" << std::endl;
        releaseYear = 1900;
    }*/
    
    while (movie.releaseYear < 1900 || movie.releaseYear > 2100)
    {
        std::cout << "Release year must between 1900 and 2100" << std::endl;
        //releaseYear = 1900;
        std::cin >> movie.releaseYear;
    }
    std::cout << "Enter the optional description: ";
    std::cin.ignore();
    std:getline(std::cin, movie.description);

    /*std::cout << "Enter the optional user rating (1.0-10.0): ";
    std::cin >> userRating;
    if (userRating < 1.0 || userRating > 10.0)
    {
        std::cout << "Rating must be between 1.0 and 10.0" << std::endl;
        userRating = 1.0;*/
    
    /*if (userRating < 1.0)
    {
        std::cout << "Rating must be betwen 1.0 and 10.0" << std::endl;
        userRating = 1.0;
    } else if (userRating > 10.0)
    {    
            std::cout << "Rating must be 1.0 and 10.0" << std::endl;
            userRating = 1.0;
    }*/
    // Genres, up to 5
    //done = false;
    //int count = 0;
    //while (!done && count < 5)
    //{
    //    std::string genre;

    //std::cout << "Enter the genre (or blank to continue): ";
    //std::getline(std::cin, genre);
    //if (genre == "")
    //    done = true;
    //else
    //    genres = genres + ", " + genre;

    //++count;    // or, count++
    //}
    done = false;
    //int index = 0;
    //for (count = 0; count < 5 && !done; ++count)
    //for (index = 0; index < 5; ++index)
    for (int index = 0; index < 5; ++index)
    {
        std::string genre;

        std::cout << "Enter the genre (or blank to continue): ";
        std::getline(std::cin, genre);
        if (genre == "")
            //done = true;
            //index = 5;
            break;
        else if (genre == " ")
            continue;
        
        movie.genres = movie.genres + ", " + genre;
    }
    std::cout << "Is this a classic (Y/N)?: ";
    std::string input;
    std::cin >> input;
    // if (Eb) S [ else S ] ;
    // 
    //Infinite loop
    //while (true) {}
    //for (;;) {}
    // break; and continue; can only be used inside loops
    // break is for exiting loop
    // continue is for exiting the iteration
    /* if (_strcmpi(input.c_str(), "Y") == 0)
        isClassic = true;
    if (_strcmpi(input.c_str(), "N") == 0)
        isClassic = false;
    else
        std::cout << "You must enter either Y or N";*/
    //done = false;
   // while (!done)
    while (true)
     {
            if (_strcmpi(input.c_str(), "Y") == 0)
            {
                movie.isClassic = true;
                //done = true;
                break;
            } else if (_strcmpi(input.c_str(), "N") == 0)
            {
                movie.isClassic = false;
                    //done = true;
                    break;
            } else {
                
                    std::cout << "You must enter either Y or N";

                    std::cin >> input;
             }
    }
    // View movie
    // Title (Year)
    // Run Length (min)
    // User Rating = ##
    // Is Classic?
    // [Description]

    std::cout << std::fixed << std::setprecision(1) << std::endl;
    std::cout << movie.title << " (" << movie.releaseYear << ")" << std::endl;
    std::cout << "Run Length " << movie.runLength << " mins" << std::endl;
    std::cout << "Genres " << movie.genres << std::endl;
    //std::cout << "User Rating = " << userRating << std::endl;
    //std::cout << "Is Classic? " << isClassic << std::endl;
    /*std::string classicIndicator;
    if (isClassic)
        classicIndicator = "Yes";
    else
        classicIndicator = "No";*/
    //Conditional_expression ::= Eb ? Et : Ef, 1. whatever Et is, is whatever the rest of the expression results, 2. both Et and Ef must be the same type otherwise the compiler fails
    // std::string classicIndicator = isClassic ? "Yes" : "No";
    std::cout << "Is Classic? " << (movie.isClassic ? "Yes" : "No") << std::endl;
    if (movie.description != "")
        std::cout << movie.description << std::endl;
    std::cout << std::endl;


    



















    //TODO: Handle other values
    // Notes:
    // Logical AND &&
    // Logical OR  ||
    // Logical NOT !
    // OP1|OP2|AND|OR
    //----------------
    // F  |F  |F  |F
    // F  |T  |F  |T
    // T  |F  |F  |T
    // T  |T  |T  |T
    // Short circuit evalution is important later need to understand later since I blanked out
}

void relationalDemo()
{
    std::cout << "Enter two values: ";
    int left, right;
    std::cin >> left >> right;

    // Relational operators ::= > >= < <= == !=
    // Warning 1 - Equality and equals are similar and work in the same situations
    // Warning 2 - Be very, very careful of floating point comparison for equality
    // Consider using >= or <= instead unless comparing to an integer
    // Warning 3 - Strings compare by character values not by locale
    // == equality, != unequality
    // strcmpi(string, string) returns a int, somethings the POXIS error shows up, place a _ in front of strcmpi
    // use c_str() is convert C into C++
    bool areEqual = left == right;
    std::cout << "areEqual = " << areEqual << std::endl;
    areEqual = left == right;
    std::cout << "areEqual = " << areEqual << std::endl;

   // dont write areEqual = left == 10;
   // instead write areEqual = 10 = left; put literal(10) on the left side

    std::cout << "> " << (left > right) << std::endl;
    std::cout << "< " << (left < right) << std::endl;
    std::cout << ">=" << (left >= right) << std::endl;
    std::cout << "<=" << (left <= right) << std::endl;
    std::cout << "==" << (left == right) << std::endl;
    std::cout << "!=" << (left != right) << std::endl;

    float someValue = (10 / 3.0) * 3.0;
    float someOtherValue = (10 * 3.0) / 3.0;
    areEqual = someValue == someOtherValue;
    std::cout << areEqual << std::endl;

    // Comparison works but is case sensitive
    std::string name1 = "Bob";
    std::string name2 = "bob";
    std::cout << (name1 == name2) << std::endl;

    // To compare strings case insensitive use the strcmpi
    // > 0 ::= left > right
    // < 0 ::= left < right
    // == 0 ::= left == right
    areEqual = _strcmpi(name1.c_str(), name2.c_str()) == 0;
 












}
