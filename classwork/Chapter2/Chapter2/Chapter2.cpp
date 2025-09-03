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
//Integar literal - one or more digits for example 20, like string literal, cannot change, fixed

//Floating point literals - one or more digits + fraction
// 3.14159 or 3E10 -3E10 3E-10

// Variable - Named memory location where data is stored
std::string name;
name = "Bill";
std::cout << "Hello World " << name;
// in C++ every statement must end with a semicolon
// Statement = Anything that does something in the language

}
