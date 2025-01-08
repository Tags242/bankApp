#include "AccountMenu.h"
#include "Authentication.h"
#include "sendMoneyMenu.h"
#include "dollarAccountMenu.h"
#include "Repository.h"
#include "User.h"
#include <iostream>
using namespace std;

void AccountMenu(User &user)
{
    while (true)
    {
        string name = user.getName();
        string surname = user.getSurname();
        string user_id = user.getUserId();
        double balance = user.getBalance();

        Repository repo;

        cout <<"+-----------------------------------------------------------------------------------------+"<< endl << endl;
        cout <<"|                                      Account Menu                                       |" << endl << endl;
        cout <<"+-----------------------------------------------------------------------------------------+"<< endl << endl;

        cout << "                    __________________________________________________"  << endl;
        cout << "                   /                                                  \\" << endl;
        cout << "                   |                                                  |" << endl;
        cout << "                   |                                                  |" << endl;
        printBalance(balance);
        cout << "                   |                                                  |" << endl;
        cout << "                   |                                                  |" << endl;
        cout << "                   |                                                  |" << endl;
        printName(name, surname);
        cout << "                   \\__________________________________________________/" << endl << endl;

        cout << "IBAN: " << user_id << endl << endl;

        cout << "| Last Transactions " << endl;
        cout <<"-------------------------------------------------------------------------------------------"<< endl;
        repo.displayTransactions(user_id);
        cout << endl;

        cout << "[1] Send Money" << endl;
        cout << "[2] Open Dollar Account " << endl << endl;

        string input;
        getline(cin, input);
        char choice = input[0];

        switch (choice) 
        {
            case '1':
                sendMoneyMenu(user); 
                break;
            case '2':
                dollarAccountMenu();
                break;
            default:
                cout << "Invalid input. Please try again." << endl;
                break;
        }
    } 
}

void printName(string name, string surname)
{
    size_t length = name.length() + surname.length() + 1;
    cout << "                   |  " << name << " " << surname;
    for (size_t i = 0; i < 39 - length; i++)
    {
        cout << " ";
    }
    cout << "Bankc++  |" << endl;
}

void printBalance(double balance)
{

    size_t length = to_string(balance).length();
    cout << "                   |  BALANCE = " << "tl " << balance;
    for (size_t i = 0; i < 42 - length ; i++)
    {
        cout << " ";
    }
    cout << "|" << endl;
}