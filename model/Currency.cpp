#include "Currency.h"
#include <fstream>
using namespace std;


Currency::Currency()
{
    readCurrencies();
}

Currency::~Currency()
{

}

double Currency::getDolar()
{
    return dolar;
}

void Currency::setDolar(double dolar)
{
    this -> dolar = dolar;
    ofstream file("currencies.bin", ios::binary);
    if (file.is_open())
    {
        file.write((char*)&dolar,sizeof(double));
        file.close();
    }
}

void Currency::readCurrencies()
{
    ifstream file("currencies.bin", ios::binary);
    if (file.is_open())
    {
        file.read((char*)&dolar,sizeof(double));
        file.close();
    }
}
