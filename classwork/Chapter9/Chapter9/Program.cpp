#include <iostream>
#include <string>
#include <cctype>
#include <iomanip>

void CharDemo()
{
    // Character sets
    // ANSI - 1 byte, char in C++
    // Unicode - 2 bytes, wchar_t in C++, wstring for string
    char ansiCharacter = 'A';
    wchar_t unicodeCharacter = 'A';

    std::string ansiString = "Bob";
    std::wstring unicodeString = L"Bob";

    // Variants - Unicode variants of fixed size
    //char8_t char8Byte; needs to use visual studio 2025
    char16_t char16Byte;
    char32_t char32Byte;
}

void CharFunctionDemo()
{
    std::string input;

    std::cout << "Enter a string: ";
    std::getline(std::cin, input);

    std::cout << "Character "
        << std::setw(15) << "Letter? "
        << std::setw(12) << "Digit? " 
        << std::setw(10) << "Letter/Digit? "
        << std::setw(10) << "Lowercase? "
        << std::setw(10) << "To Lower "
        << std::setw(10) << "Uppercase? "
        << std::setw(10) << "To Upper "
        << std::setw(10) << "Space? " << std::endl;
    std::cout << "------------------------------------------------------" << std::endl;

    // Enumberate the characters of the string
    for (int index = 0; index < input.length(); ++index)
    {
        char ch = input[index];

        // All char functions are from C and therefore accept and return an int, not a char
        // Typecast back to char
        std::cout << ch 
            << std::setw(15) << isalpha(ch)
            << std::setw(12) << isdigit(ch)
            << std::setw(10) << isalnum(ch)
            << std::setw(10) << islower(ch)
            << std::setw(10) << (char)tolower(ch)
            << std::setw(10) << isupper(ch)
            << std::setw(10) << (char)toupper(ch)
            << std::setw(10) << isspace(ch)
            << std::endl;
    };
}

void UnicodeCharFunctionDemo()
{
    std::wstring input;

    std::cout << "Enter a string: ";
    std::getline(std::wcin, input); // changed to wcin for wstring

    std::cout << "Character "
        << std::setw(15) << "Letter? "
        << std::setw(12) << "Digit? "
        << std::setw(10) << "Letter/Digit? "
        << std::setw(10) << "Lowercase? "
        << std::setw(10) << "To Lower "
        << std::setw(10) << "Uppercase? "
        << std::setw(10) << "To Upper "
        << std::setw(10) << "Space? " << std::endl;
    std::cout << "------------------------------------------------------" << std::endl;

    // Enumberate the characters of the string
    for (int index = 0; index < input.length(); ++index)
    {
        wchar_t ch = input[index]; // changed to wchar_t ch from char

        // All char functions are from C and therefore accept and return an int, not a char
        // Typecast back to char
        std::cout << ch
            << std::setw(15) << iswalpha(ch)   // added w in front of all functions for wstring
            << std::setw(12) << iswdigit(ch)
            << std::setw(10) << iswalnum(ch)
            << std::setw(10) << iswlower(ch)
            << std::setw(10) << (char)towlower(ch)
            << std::setw(10) << iswupper(ch)
            << std::setw(10) << (char)towupper(ch)
            << std::setw(10) << iswspace(ch)
            << std::endl;
    };
}

void CStringDemo()
{
    // Implicit sizing makes sense here
    char title[] = "My Program";
    // Can do it manually by typing out letter for letter {'M', 'y', ' '}
    //Normally use char* for C strings
    // or char const* for C strings that are const
}

int main()
{
    CharFunctionDemo();
}

// Chapter 9 Notes:
// char set -> mapping from numberic values to "character"
// A&SI - 1 char byte, 2^8 = 256
// a...z, A...Z, 0-9, +-!.:()
// cr, LF, HT, 1/2, 3/4
// square root, heart,
// ASCii - 7 bits
// unicode - 2 bytes/char 2^64
// String Literals are ansi strings
// Placing a L in front of a string converts it into a wstring literal
// isalpha, isdigit, isalum, islower, isupper, isspace
// length returns instead of bytes
// Every string literal must include nullchar, they are null terimated