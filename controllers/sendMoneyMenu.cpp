#include "sendMoneyMenu.h"
#include "Authentication.h"
#include "User.h"
#include "Repository.h"
#include "AccountMenu.h"
#include <iostream>

using namespace std;

void sendMoneyMenu(User &sender)
{
    cout <<"+-----------------------------------------------------------------------------------------+"<< endl << endl;
    cout <<"|                                         Send Money                                      |"<< endl << endl;
    cout <<"+-----------------------------------------------------------------------------------------+"<< endl << endl;

    Repository repo;
    string recipient_id;
    double money;
    
    while(true)
    {
        cout << "Write the IBAN of the recipient: ";
        getline(cin,recipient_id);
        break;
    }
    //recipient_id doesnt exist

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
            repo.sendMoney(sender,recipient_id,money);
            repo.logTransaction(sender.getUserId(), recipient_id, money);
            cout << "Transferred " << money << "tl from " << sender.getUserId() << " to " << recipient_id << endl;
        }
        cin.clear();
        cin.ignore();
        break;
    }
}