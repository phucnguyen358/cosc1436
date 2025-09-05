// 
// Your Name
// Lab #
// COSC 1436 Fall 2025
//
#include <iostream>
// will always start with #include, what changes is within the <?> or Preprocessor directive, will only use 1 or 2 this semester
// #include <iostream> takes contents of file
int main()
{
//   std::cout << "Hello World" << " " << "Your Name";
//   std::cout displays messages
// << is output stream operator,only used with std::cout
// "Hello World" is a string literal in C++
//   std::cout << "Hello World";
//   std::cout << "Your Name";
//   std::cout << "Hello World "  << "Your Name" << std::endl;
// use std::endl to move to next line
// std::cout << "You are " << 20 << " years old" << std::endl;
// numbers don't need ""
// Identical to << endl;
// std::cout << "Hello World " << "Your Name\n";
// std::cout << "Hello World\tYour Name";
// std::cout << "Hellow World \"Your Name\"";
// std::cout << "C:\\Windows";


//String literals "..." literal meaning read only data, cannot change, fixed
// "Whatever"
//Escape sequence - special meaning to the compiler
//  - Starts with \ followed by a character
// \t will generate a tab and no way of controling how many times it tabs
// dont mixed endl and \n, use one
// \n - newline
// \t - tab
// \" - double quote
// \\ - slash
// // escape characters count as one character
// Integar literal - one or more digits for example 20, like string literal, cannot change, fixed

// Floating point literals - one or more digits + fraction
// 3.14159 or 3E10 -3E10 3E-10

// Variable - Named memory location where data is stored
// std::string name;
// name = "Bill";
// std::cout << "Hello World " << name;
// in C++ every statement must end with a semicolon
// Statement = Anything that does something in the language

// var-decl ::= T id;
// type = defines what can be stored in the variable and in what format

// int age;
// age = 20;
// std::cout << "You are " << age << " years old";
// variables are always named as nouns and never as "X" or "Y"
// var-decl = id;
// id::= must start with a letter or underscore followed by letters, digits, and underscore in that order
// id::= or identifiers cannot be keywords(blue words), must be unique

// Area of rectangle calculator
// A = lw
//int length;
//int width;
// if the variables are closely related like length and width, use comma
//length = 10;
//width = 20;
int length = 10, width = 20;

// Uninitialized vaiable - YOU MUST assign a value to a variable before you read it
// int area;
// area = 0;
int area = 0;
// area = length * width;
std::cout << "Area of rectangle is " << area << std::endl;
// T = type
// Int or Integers can only be stored as whole numbers
// std::string can include names and addresses "5" is not the same as 5
// 2 difference approaches to variable delcarations
// Block - all variables together
int radius, diameter;
std::string circlename;

// Now I can use the variables

// Inline - variables are delcared just before they are used
int radius, diameter;
// Use radius, diameter

std::string circleName;
// Use circleName
// Use Block or Inline, be consistant
// Interegal
// Types - Bool       | Char              | Speed Char    | Short           | Int          | Long         | ua char | ua start | " int       | " long     | float              | double
// Size  - 1 bit      |1                  | 1             | 2               | 4            | 4            | 1       | 2        | 4           | 4          | 4                  | 8
// Range - false/true | all letters 0-255 | [-128 to 128] | -32768 to 32768 | +- 2 billion | +- 2 Billion | 0-255   | 0-64K    | 0-4 Billion | 0-4 Billion| 5-7 digitals(cd)   |12-15 digitals(dc)
// ua = unassigned, cd = counting decimals
// asn::= E = E
//  L-Wallow R-Wallow
// Variables can only be on the left side of a L-wallow
// Readable | Writable
double pi;
pi = 3.14159;

char letterGrade;
letterGrade = 'A';
// char literals is in quotes
// string literals is in double quotes

bool isPassing;
isPassing = true;
// Assignment is right associative, starts from the right to left
//length = 100;
//width = 100;
length = width = 100;

}
