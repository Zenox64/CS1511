#include <iostream>
using namespace std;

int invites;
char color, mail, elecMail;
const double colorInvCost = 0.2;
const double mailingCost = 0.2;
const double elecMailCost = 0.2;
const double elecMailFee = 20;
const double costPer = 0.75;
const double medCostPer = 0.50;
const double overCostPer = 1.00;
double totalCost, baseInvCost, totalCostColor, totalMailCost;
bool electronicMail = false;
bool mailing = false;
bool coloring = false;

int main() {
    cout << "Number of invites: \n";
    cin >> invites;
    cout << "Are invitations in color? (Y/N) \n";
    cin >> color;
    cout << "Are invitations being mailed? (Y/N) \n";
    cin >> mail;
    if(mail == 'Y') {
        cout << "Would you like electronic mail? (Y/N)\n";
        cin >> elecMail;
    }
    if (elecMail == 'Y') {
        electronicMail = true;
    }

    //formatting
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);

    if(invites < 20) {
        baseInvCost = invites * costPer;
        cout << baseInvCost << endl;
    }
    if(invites >= 20 && invites < 100) {
        baseInvCost = invites * medCostPer;
        cout << baseInvCost << endl;
    }
    if(invites >= 100) {
        baseInvCost = invites * overCostPer;
        cout << baseInvCost << endl;
    }
    if(color == 'Y') {
        totalCostColor = colorInvCost * invites + baseInvCost;
        coloring = true;

    }
    if(color == 'N') {
        totalCost = baseInvCost;
    }
    if(mail == 'Y') {
        totalCost = mailingCost * invites + baseInvCost;
        cout << totalMailCost << endl;
        mailing = true;
    }
    if (electronicMail) {
        totalCost = totalCost + elecMailFee;
    }
    if(mail == 'N') {
        totalMailCost = totalCostColor;
    }
    cout << "Party Invitations, Inc\n";
    cout << "Quantity Ordered: " << invites << endl;
    if (mailing) {
        cout << "Mailing " << invites << " @ $0.20/invitation" << endl;
    }
    if (electronicMail) {
        cout << "Additional electronic mailing fee of $" << elecMailFee << endl;
    }
    if (coloring) {
        cout << "Printing " << invites << " in color @ additional $0.20/invitation" << endl;
    }
    cout << "Total Cost: $" << totalCost << endl;
}
