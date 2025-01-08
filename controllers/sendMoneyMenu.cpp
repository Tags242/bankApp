#include "sendMoneyMenu.h"
#include "Authentication.h"
#include "User.h"
#include "Repository.h"
#include "AccountMenu.h"
#include <iostream>

using namespace std;

void sendMoneyMenu(User sender)
{
    cout <<"+-----------------------------------------------------------------------------------------+"<< endl << endl;
    cout <<"|                                         Send Money                                      |"<< endl << endl;
    cout <<"+-----------------------------------------------------------------------------------------+"<< endl << endl;

    Repository repo;
    string user_id;
    double money;

    while(true)
    {
        cout << "Write the user id of the recipient: ";
        getline(cin,user_id);
        break;
    }

    while(true)
    {
        cout << "Write the amount of money you want to send: ";
        cin >> money;

        if (sender.getBalance() < money) 
        {
            cout << "Insufficient balance. Transaction failed." << endl;
            
        }
        else
        {
            repo.sendMoney(sender.getUserId(),user_id,money);

        }
        cin.clear();
    }
}