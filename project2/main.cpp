#include <iostream>
using namespace std;

int invites;
char color, mail, elecMail;
const double colorInvCost = 0.2;
const double mailingCost = 0.2;
const double elecMailFee = 20;
double costPer = 0.75;
double totalCost;
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
        costPer = 0.75;
        totalCost = invites * costPer;
    }
    if(invites >= 20 && invites < 100) {
        costPer = 0.50;
        totalCost = invites * costPer;
    }
    if(invites >= 100) {
        costPer = 0.40;
        totalCost = invites * costPer;
    }
    if(color == 'Y') {
        totalCost = colorInvCost * invites + totalCost;
        coloring = true;
    }
    if(mail == 'Y') {
        totalCost = mailingCost * invites + totalCost;
        mailing = true;
    }
    if (electronicMail) {
        totalCost = totalCost + elecMailFee;
    }
    cout << "Party Invitations, Inc\n";
    cout << "Quantity Ordered: " << invites << " @ $" << costPer << "/invitation" << endl;
    if (mailing) {
        cout << "Mailing @ additional $0.20/invitation $" << invites * mailingCost << endl;
    }
    if (electronicMail) {
        cout << "Additional electronic mailing fee $" << elecMailFee << endl;
    }
    if (coloring) {
        cout << "Printing in color @ additional $0.20/invitation $" << invites * colorInvCost << endl;
    }
    if(color == 'N' && mail == 'N') {
        cout << "No extras selected \n";
    }
    cout << "Total Cost: $" << totalCost << endl;
}
