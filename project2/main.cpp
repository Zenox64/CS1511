#include <iostream>
using namespace std;

//variables
int invites;
char color, mail, elecMail;
const double colorInvCost = 0.2; // standard costs
const double mailingCost = 0.2;
const double elecMailFee = 20; // standard mail fee
double costPer = 0.75; // holds current cost for scenario
double totalCost; // variable that holds the running total
bool electronicMail = false; // automatically set false
bool mailing = false;
bool coloring = false;

int main() { // the function
    // getting information from inputs
    cout << "Number of invites: \n";
    cin >> invites;
    cout << "Are invitations in color? (Y/N) \n";
    cin >> color;
    cout << "Are invitations being mailed? (Y/N) \n";
    cin >> mail;
    if(mail == 'Y') { // decides whether or not to ask another question
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

    // determining the rate per invitation
    if(invites < 20) {
        costPer = 0.75;
        totalCost = invites * costPer; // adds cost of invitation to total
    }
    if(invites >= 20 && invites < 100) { // greater than or equal to 20 but less than 100
        costPer = 0.50;
        totalCost = invites * costPer;
    }
    if(invites >= 100) { // greater than or equal to 100
        costPer = 0.40;
        totalCost = invites * costPer;
    }
    if(color == 'Y') { // adds color cost if user opts for color
        totalCost = colorInvCost * invites + totalCost;
        coloring = true; //makes coloring true which leads to outputting color price information
    }
    if(mail == 'Y') { // adds mail cost if user opts for mail
        totalCost = mailingCost * invites + totalCost;
        mailing = true; //makes mailing true which leads to outputting mail price information
    }
    if (electronicMail) { // if user opts for electronic mail, mail fee is added
        totalCost = totalCost + elecMailFee;
    }
    //output information
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
    if(color == 'N' && mail == 'N') { // if no extras are selected, user is informed
        cout << "No extras selected \n";
    }
    cout << "Total Cost: $" << totalCost << endl; // total cost output
}
