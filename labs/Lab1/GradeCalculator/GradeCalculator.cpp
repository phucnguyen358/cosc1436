// Lab 1
// Phuc Nguyen
// COSC 1436 Fall 2025
#include <iostream>
#include <string>
#include <iomanip>

int main()

{
    // setprecision set the number of decimals used for floats and doubles probably
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Lab 1" << std::endl;
    std::cout << "Phuc Nguyen" << std::endl;
    std::cout << "COSC 1436 2025" << std::endl;

    std::cout << std::endl;
    std::cout << "Enter name: ";
    std::string name;
    std::getline(std::cin, name);
    // getline reads a line of input from the user and stores it in the variable, in this case its inside "name"

    std::cout << "Enter Lab 1 grade: ";
    int Lab1 = 0;
    std::cin >> Lab1;

    std::cout << "Enter Lab 2 grade: ";
    int Lab2 = 0;
    std::cin >> Lab2;

    std::cout << "Enter Lab 3 grade: ";
    int Lab3 = 0;
    std::cin >> Lab3;

    std::cout << "Enter Lab 4 grade: ";
    int Lab4 = 0;
    std::cin >> Lab4;

    std::cout << "Enter Exam 1 grade: ";
    int Exam1 = 0;
    std::cin >> Exam1;

    std::cout << "Enter Exam 2 grade: ";
    int Exam2 = 0;
    std::cin >> Exam2;

    std::cout << "Enter Exam 3 grade: ";
    int Exam3 = 0;
    std::cin >> Exam3;

    std::cout << "Enter participation: ";
    int participation = 0;
    std::cin >> participation;

    std::cout << "Enter final exam: ";
    int finalExam = 0;
    std::cin >> finalExam;

    std::cout << std::endl;
    std::cout << name << ", your lab grades are: " << std::endl;
    std::cout << "Lab 1 = " << Lab1 << std::endl;
    std::cout << "Lab 2 = " << Lab2 << std::endl;
    std::cout << "Lab 3 = " << Lab3 << std::endl;
    std::cout << "Lab 4 = " << Lab4 << std::endl;

    std::cout << std::endl;
    std::cout << name << ", your exam grades are: " << std::endl;
    std::cout << "Exam 1 = " << Exam1 << std::endl;
    std::cout << "Exam 2 = " << Exam2 << std::endl;
    std::cout << "Exam 3 = " << Exam3 << std::endl;
    
    std::cout << std::endl;
    std::cout << name << ", your other grades are: " << std::endl;
    std::cout << "Participation = " << participation << std::endl;
    std::cout << "Final Exam = " << finalExam << std::endl;

    // When interacting with doubles and floats, use non whole numbers such as 1.0 or 8.0
    double labAverage = (Lab1 + Lab2 + Lab3 + Lab4) / 4.0;
    std::cout << std::endl;
    std::cout << name << ", your class grade is: " << std::endl;
    std::cout << "Lab Average (65%) = " << labAverage << "%" << std::endl;

    // I could change line 84 into a double so that any number that gets inputted will come out with a percent. In this case, I wanted to copy exactly what was written on the sample output.
    int examAverage = (Exam1 + Exam2 + Exam3) / 3;
    std::cout << "Exam Average (20%) = " << examAverage << "%" << std::endl;

    std::cout << "Participation (5%) = " << participation << "%" << std::endl;

    std::cout << "Final Exam (10%) = " << finalExam << "%" << std::endl;
    // same case as line 77, use non whole numbers
    double classAverage = (labAverage * 0.65) + (examAverage * 0.20) + (participation * 0.05) + (finalExam * 0.10);
    std::cout << "Class Average = " << classAverage << "%" << std::endl;
}