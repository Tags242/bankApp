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

void Repository::sendMoney(string sender_id, string recipient_id, double money) {

    User sender = readUserData(sender_id);
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
        cout << "Error: Unable to open sender file for updating." << endl;
        return;
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
        cout << "Error: Unable to open recipient file for updating." << endl;
        return;
    }

    cout << "Transaction completed successfully. Transferred " << money << "tl from " << sender_id << " to " << recipient_id << endl;
}