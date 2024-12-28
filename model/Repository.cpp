#include "Repository.h"
#include "User.h"
#include <fstream>
#include <string>
using namespace std;


const char* getLength(const std::string& str) 
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
    return user_id;
}

Repository::Repository() 
{
    user_id = 0;
}

void Repository::resetUserId()
{
    unsigned short num = 0;
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
        if (file.gcount() != sizeof(unsigned short)) 
        {
            user_id = 0;
        }
    } 
    else 
    {
        user_id = 0;
    }
}

void Repository::IncrementUserId() // file'daki okur ve 1 arttırır
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
        file.write((char*)&nameLength, sizeof(unsigned short)); // boyutu yaz
        file.write(getLength(user.getName()), nameLength);      // içeriği yaz

        //surname
        unsigned short surnameLength = user.getSurname().length();
        file.write((char*)&surnameLength, sizeof(unsigned short)); // boyutu yaz
        file.write(getLength(user.getSurname()), surnameLength);   // içeriği yaz

        //password
        unsigned short passwordLength = user.getPassword().length();
        file.write((char*)&passwordLength, sizeof(unsigned short)); // boyutu yaz
        file.write(getLength(user.getPassword()), passwordLength);  // içeriği yaz

        int balance = user.getBalance();
        file.write((char*)&balance, sizeof(int));

        file.close(); 
    }

    IncrementUserId();
}

