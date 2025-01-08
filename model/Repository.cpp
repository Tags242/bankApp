#include "Repository.h"
#include "User.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;


const char* stringToArray(const string& str) 
{
    static char buffer[256];
    size_t length = str.length();
    for (size_t i = 0; i < length && i < sizeof(buffer) - 1; i++) 
    {
        buffer[i] = str[i];
    }
    buffer[length] = '\0'; 
    return buffer;
}

unsigned short Repository::getUserId()
{
    return user_id - 1;
}


Repository::Repository() 
{
    user_id = 1;
}

void Repository::resetUserId()
{
    unsigned short num = 1;
    ofstream file("user_id.bin", ios::binary | ios::trunc);
    if (file.is_open()) 
    {
        file.write((char*)&num, sizeof(unsigned short));
        file.close();
    }
}

void Repository::writeUserId()// 0'dan user_id.bin yaratmak için kullanılır 0dan başlatır 1 kere çalıştırılacak
{
    ofstream file("user_id.bin", ios::binary | ios::trunc);
    if (file.is_open()) 
    {
        file.write((char*)&user_id, sizeof(unsigned short));
        file.close();
    }
}

void Repository::readUserId()// file'daki user_id'yi okur
{
    ifstream file("user_id.bin", ios::binary);
    if (file.is_open()) 
    {
        file.read((char*)&user_id, sizeof(unsigned short));
        file.close();
    } 
}

void Repository::IncrementUserId() // user_id'yi 1 arttırır ve file'a yazar
{
    user_id++;
    writeUserId();
}

void Repository::addUser(User user) 
{
    readUserId();
    ofstream file(to_string(user_id), ios::binary | ios::trunc);// şuanki user_id ile binary file açar
    if (file.is_open()) 
    {
        //name
        unsigned short nameLength = user.getName().length();
        file.write((char*)&nameLength, sizeof(unsigned short));      // boyutu yaz
        file.write(stringToArray(user.getName()), nameLength);      // içeriği yaz

        //surname
        unsigned short surnameLength = user.getSurname().length();
        file.write((char*)&surnameLength, sizeof(unsigned short));      // boyutu yaz
        file.write(stringToArray(user.getSurname()), surnameLength);   // içeriği yaz

        //password
        unsigned short passwordLength = user.getPassword().length();
        file.write((char*)&passwordLength, sizeof(unsigned short));      // boyutu yaz
        file.write(stringToArray(user.getPassword()), passwordLength);  // içeriği yaz

        double balance = user.getBalance();
        file.write((char*)&balance, sizeof(double));

        file.close(); 
    }

    IncrementUserId();
}

User Repository::readUserData(string user_id) 
{
    User user;
    ifstream file(user_id, ios::binary | ios::ate);

    string name;
    string surname;
    string password;
    double balance;

    if (file.is_open()) 
    {
        streampos fileSize = file.tellg();
        file.seekg(0, ios::beg);
        char* mBlock = new char[fileSize];
        file.read(mBlock, fileSize);

        char* p = mBlock;

        unsigned short nameLength = *((unsigned short*)(p));
        p += sizeof(unsigned short);

        for (unsigned short i = 0; i < nameLength; i++)
        {
            name += *((char*)(p));
            p += sizeof(char);
        }

        unsigned short surnameLength = *((unsigned short*)(p));
        p += sizeof(unsigned short);

        for (unsigned short i = 0; i < surnameLength; i++)
        {
            surname += *((char*)(p));
            p += sizeof(char);
        }

        unsigned short passwordLength = *((unsigned short*)(p));
        p += sizeof(unsigned short);

        for (unsigned short i = 0; i < passwordLength; i++)
        {
            password += *((char*)(p));
            p += sizeof(char);
        }

        balance = *((double*)(p));

        user.setName(name);
        user.setSurname(surname);
        user.setPassword(password);
        user.setBalance(balance);

        file.close();
        delete[] mBlock;
    }
    else
    {
        cerr << "file can not open";
    } 
     

    return user;
}

void Repository::sendMoney(User& sender, string recipient_id, double money) 
{

    string sender_id = sender.getUserId();
    User recipient = readUserData(recipient_id);

    sender.setBalance(sender.getBalance() - money);
    recipient.setBalance(recipient.getBalance() + money);

    ofstream senderFile(sender_id, ios::binary | ios::trunc);
    if (senderFile.is_open()) 
    {
        unsigned short nameLength = sender.getName().length();
        senderFile.write((char*)&nameLength, sizeof(unsigned short));
        senderFile.write(stringToArray(sender.getName()), nameLength);

        unsigned short surnameLength = sender.getSurname().length();
        senderFile.write((char*)&surnameLength, sizeof(unsigned short));
        senderFile.write(stringToArray(sender.getSurname()), surnameLength);

        unsigned short passwordLength = sender.getPassword().length();
        senderFile.write((char*)&passwordLength, sizeof(unsigned short));
        senderFile.write(stringToArray(sender.getPassword()), passwordLength);

        double balance = sender.getBalance();
        senderFile.write((char*)&balance, sizeof(double));

        senderFile.close();
    } 
    else
    {
        cerr << "Error: Unable to open sender file for updating." << endl;
    }

    ofstream recipientFile(recipient_id, ios::binary | ios::trunc);
    if (recipientFile.is_open()) 
    {
        unsigned short nameLength = recipient.getName().length();
        recipientFile.write((char*)&nameLength, sizeof(unsigned short));
        recipientFile.write(stringToArray(recipient.getName()), nameLength);

        unsigned short surnameLength = recipient.getSurname().length();
        recipientFile.write((char*)&surnameLength, sizeof(unsigned short));
        recipientFile.write(stringToArray(recipient.getSurname()), surnameLength);

        unsigned short passwordLength = recipient.getPassword().length();
        recipientFile.write((char*)&passwordLength, sizeof(unsigned short));
        recipientFile.write(stringToArray(recipient.getPassword()), passwordLength);

        double balance = recipient.getBalance();
        recipientFile.write((char*)&balance, sizeof(double));

        recipientFile.close();
    } 
    else 
    {
        cerr << "Error: Unable to open recipient file for updating." << endl;
    }
}

void Repository::logTransaction(const string& sender_id, string& recipient_id, double money) 
{
    // Log for the sender
    ofstream senderFile(sender_id + "_transactions.bin", ios::binary | ios::app);
    if (senderFile.is_open()) 
    {
        // Write action type for sender
        string action = "Sent to";
        unsigned short actionLength = action.length();
        senderFile.write((char*)&actionLength, sizeof(unsigned short));
        senderFile.write(stringToArray(action), actionLength);

        // Write recipient ID
        unsigned short recipientLength = recipient_id.length();
        senderFile.write((char*)&recipientLength, sizeof(unsigned short));
        senderFile.write(stringToArray(recipient_id), recipientLength);

        // Write amount
        senderFile.write((char*)&money, sizeof(double));

        senderFile.close();
    }
    else
    {
        cerr << "Error: Unable to open sender transaction file." << endl;
    }

    // Log for the recipient
    ofstream recipientFile(recipient_id + "_transactions.bin", ios::binary | ios::app);
    if (recipientFile.is_open()) 
    {
        // Write action type for recipient
        string action = "Received from";
        unsigned short actionLength = action.length();
        recipientFile.write((char*)&actionLength, sizeof(unsigned short));
        recipientFile.write(stringToArray(action), actionLength);

        // Write sender ID
        unsigned short senderLength = sender_id.length();
        recipientFile.write((char*)&senderLength, sizeof(unsigned short));
        recipientFile.write(stringToArray(sender_id), senderLength);

        // Write amount
        recipientFile.write((char*)&money, sizeof(double));

        recipientFile.close();
    }
    else
    {
        cerr << "Error: Unable to open recipient transaction file." << endl;
    }
}

void Repository::displayTransactions(string& user_id) 
{
    ifstream file(user_id + "_transactions.bin", ios::binary | ios::ate);
    if (!file.is_open()) 
    {
        cout << "You don't have any transactions." << endl << endl;
        return;
    }

    streampos fileSize = file.tellg();
    file.seekg(0, ios::beg);

    char* mBlock = new char[fileSize];
    file.read(mBlock, fileSize);

    char* p = mBlock;

    while (p < mBlock + fileSize) 
    {
        // Read action type
        unsigned short actionLength = *((unsigned short*)(p));
        p += sizeof(unsigned short);

        string action;
        for (unsigned short i = 0; i < actionLength; i++) 
        {
            action += *((char*)(p));
            p += sizeof(char);
        }

        // Read other user ID
        unsigned short otherIdLength = *((unsigned short*)(p));
        p += sizeof(unsigned short);

        string otherId;
        for (unsigned short i = 0; i < otherIdLength; i++) 
        {
            otherId += *((char*)(p));
            p += sizeof(char);
        }

        // Read money
        double money = *((double*)(p));
        p += sizeof(double);

 
        cout << action << " " << otherId << ": " << money << " TL." << endl;
        cout << "-------------------------------------------------------------------------------------------" << endl;
    }

    delete[] mBlock;
    file.close();
}
