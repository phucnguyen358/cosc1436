// Lab 2
// Phuc Nguyen
// COSC 1436 Fall 2025
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    // Program information/Story 1
    cout << "Monthly interest rate calculator" << endl;
    cout << "Phuc Nguyen" << endl;
    cout << "COSC 1436 Fall 2025" << endl;

    int loanAmount;
    double interestRate, monthlyPayment;
    double balance, interest, payment, totalPayment = 0.0, totalInterest = 0.0;

    // Story 2
    while (true)
    {
        cout << "Please enter the loan amount (value must be between $1 and $1000): ";
        cin >> loanAmount;

        if (loanAmount > 1000)
        {
            cout << "That is an invalid value. The value must be lower than 1000" << endl;
            continue;
        }
        if (loanAmount < 1)
        {
            cout << "That is an invalid value. The value must be higher than 1" << endl;
            continue;
        }
            break;
    }
    // Story 3
    while (true)
    {
        cout << "Please enter the interest rate (%) (value must be between 1 and 100): ";
        cin >> interestRate;

        if (interestRate < 1.0)
        {
            cout << "That is an invalid value. The value must be higher than 1" << endl;
            continue;
        }
        if (interestRate > 100.0)
        {
            cout << "That is an invalid value. The value must be lower than 100" << endl;
            continue;
        } 
            break;
    }
    // Story 5
    while (true)
    {
        cout << "How much do you want to pay each month? (value must be between 0 and the loan amount) ";
        cin >> monthlyPayment;
        if (monthlyPayment < 0)
        {
            cout << "That is an invalid value. The value must be higher than 0" << endl;
            continue;
        }
        if (monthlyPayment > loanAmount)
        {
            cout << "That is an invalid value. The value must be lower than loan amount" << endl;
            continue;
        }
            break;
    }
    // Story 4
    cout << fixed << setprecision(2);
    cout << endl;
    cout << left << setw(8) << "Month"
         << setw(12) << "Balance"
         << setw(12) << "Payment"
         << setw(12) << "Interest"
         << setw(12) << "New Balance" << endl;
    cout << "-------------------------------------------------------------------------" << endl;

    balance = loanAmount;

    // 1st Month : No payment, no interest
    cout << left << setw(8) << 1
         << "$ " << setw(9) << balance
         << "$ " << setw(9) << "0.00"
         << "$ " << setw(9) << "0.00"
         << "$ " << setw(9) << balance << endl;

    for (int month = 2; month <= 12; ++month)
    {
        payment = (balance >= monthlyPayment) ? monthlyPayment : balance;
        // Interest is calulated on (balance - payment)
        if (balance - payment > 0.0)
            interest = (balance - payment) * (interestRate / 100.0);
        else
            interest = 0.0;

        double newBalance = balance - payment + interest;
        
        if (newBalance < 0.01) newBalance = 0.0;
        if (payment < 0.01) payment = 0.0;
        
        cout << left << setw(8) << month
             << "$ " << setw(9) << balance
             << "$ " << setw(9) << payment
             << "$ " << setw(9) << interest
             << "$ " << setw(9) << newBalance << endl;

        totalPayment += payment;
        totalInterest += interest;
        balance = newBalance;

        if (balance <= 0.0)
        {
            for (int m = month + 1; m <= 12; ++m)
            {
                cout << left << setw(8) << m
                     << "$ " << setw(9) << "0.00"
                     << "$ " << setw(9) << "0.00"
                     << "$ " << setw(9) << "0.00"
                     << "$ " << setw(9) << "0.00" << endl;
            }
            break;
        }
    }
    // Story 6
    cout << left << setw(8) << "Total"
         << setw(11) << ""
         << "$ "  << setw(8) << totalPayment
         << " $ " << setw(8) << totalInterest << endl;

    return 0;
}