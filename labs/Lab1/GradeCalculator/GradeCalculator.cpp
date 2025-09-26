// Lab 1
// Phuc Nguyen
// COSC 1436 Fall 2025
#include <iostream>
#include <string>
#include <iomanip>

int main()

{
    std::cout << "Lab 1" << std::endl;
    std::cout << "Phuc Nguyen" << std::endl;
    std::cout << "COSC 1436 2025" << std::endl;

    std::cout << std::endl;
    std::cout << "Enter name: ";
    std::string name;
    std::getline(std::cin, name); // getline reads a line of input from the user and stores it in the variable, in this case its inside "name"
    

    int lab1 = 0, lab2 = 0, lab3 = 0, lab4 = 0;
    int exam1 = 0, exam2 = 0, exam3 = 0;
    int participation = 0, finalExam = 0;

    std::cout << "Enter Lab 1 grade: "; std::cin >> lab1;
    std::cout << "Enter Lab 2 grade: "; std::cin >> lab2;
    std::cout << "Enter Lab 3 grade: "; std::cin >> lab3;
    std::cout << "Enter Lab 4 grade: "; std::cin >> lab4;

    std::cout << "Enter Exam 1 grade: "; std::cin >> exam1;
    std::cout << "Enter Exam 2 grade: "; std::cin >> exam2;
    std::cout << "Enter Exam 3 grade: "; std::cin >> exam3;

    std::cout << "Enter participation: "; std::cin >> participation;
    std::cout << "Enter final exam: "; std::cin >> finalExam;
    std::cout << std::endl;

    std::cout << name << ", your lab grades are: " << std::endl;
    std::cout << "Lab 1 = " << lab1 << std::endl;
    std::cout << "Lab 2 = " << lab2 << std::endl;
    std::cout << "Lab 3 = " << lab3 << std::endl;
    std::cout << "Lab 4 = " << lab4 << std::endl; std::cout << std::endl;

    std::cout << name << ", your exam grades are: " << std::endl;
    std::cout << "Exam 1 = " << exam1 << std::endl;
    std::cout << "Exam 2 = " << exam2 << std::endl;
    std::cout << "Exam 3 = " << exam3 << std::endl; std::cout << std::endl;
    
    std::cout << name << ", your other grades are: " << std::endl;
    std::cout << "Participation = " << participation << std::endl;
    std::cout << "Final Exam = " << finalExam << std::endl; std::cout << std::endl;

    double labAverage = (lab1 + lab2 + lab3 + lab4) / 4.0;  // When interacting with doubles and floats, use non whole numbers such as 1.0 or 8.0
    double examAverage = (exam1 + exam2 + exam3) / 3.0;

    std::cout << name << ", your class grade is: " << std::endl;
    
    std::cout << std::fixed << std::setprecision(2); // setprecision set the number of decimals used for floats and doubles probably
    std::cout << "Lab Average (65%) = " << labAverage << "%" << std::endl;
    std::cout << "Exam Average (20%) = " << examAverage << "%" << std::endl;
    std::cout << "Participation (5%) = " << participation << "%" << std::endl;
    std::cout << "Final Exam (10%) = " << finalExam << "%" << std::endl;

    double classAverage = (labAverage * 0.65) + (examAverage * 0.20) + (participation * 0.05) + (finalExam * 0.10);
    std::cout << "Class Average = " << classAverage << "%" << std::endl;
}