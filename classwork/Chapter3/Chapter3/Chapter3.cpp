#include <iostream>
#include <string>

void main()
{
    // Prompt user for radius of circle
    std::cout << "Enter Radius: ";
    
    // cout is for printing, cin is for getting input
    // cin is used to get input from user
    // Use the input stream operator >> before the variable names
    int radius = 0;
    std::cin >> radius;

    const double Pi = 3.14159;

    // Area = Pi * R^2
    // double * int * int -> double
    double area = Pi * radius * radius;
    std::cout << "Area = " << Pi << " * " << radius << " * " << radius << std::endl;
    std::cout << "Area = " << area << std::endl;

    // Triangle
    std::cout << "Enter base and height of triangle: ";

    int base = 0, height = 0;
    //std::cin >> base;
    //std::cin >> height;
    std::cin >> base >> height;

    // Area = 1/2 * base * height
    // (double / int) * int * int -> double
    area = (1.0 / 2) * base * height;
    std::cout << "Area = " << area << std::endl;

    // int someValue = (1.0 / 2);

    std::cout << "Enter name: ";

    std::string name;
    // std::cin >> name;
    // use std::cin.ignore(); to flush input buffer if code decides to skip
    std::cin.ignore();
    // std::getline(std::cin, variable); when using getline, inside the () is std::cin followed by a variable, getline is used to read strings with space in them
    std::getline(std::cin, name);
    std::cout << name << std::endl;
    // code until precision part which is on next tuesday
    // precedence - order in which operators are evaluated, basically PEMDAS,order of precedence, +- umary(), * / %, +-
    // associactity -order of operaran? evaluate, (left) - left to right, (right) - right to left, right is assignment

    // Overflow and underflow
    // Once a number overflows or underflows, the numbers get flipped into a positive or negative depending on the starting value
    short smallValue = 32767;
    smallValue = smallValue + 1;

    short largeValue = -32768;
    largeValue = largeValue - 1;

    std::cout << smallValue << " " << largeValue << std::endl;

    // Type Coercion - the compiler automatically changes the type of the operators so that both variables match

}