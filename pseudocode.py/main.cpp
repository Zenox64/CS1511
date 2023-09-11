// Keagan Lueck
// 9/7/2023
// Takes input and calculates spell casting success rate

#include <iostream>
using namespace std;

int main() {
    string Spell;
    string Student;

    double total, success;
    double successRt;

    cout << "Enter Student's name:";
    cin >> Student;
    cout << "Enter the spell name:";
    cin >> Spell;
    cout << "Enter the number of attempts:";
    cin >> total;
    cout << "Enter the number of successful attempts:";
    cin >> success;

    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);

    successRt = (success / total) * 100;
    cout << Student << " has a Success Rate of " << successRt << "% out of " << total << " of the " << Spell << " Spell";
    return 0;
}