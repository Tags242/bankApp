#include <iostream>
#include <string>
#include "controllers/Login.h"//directory sadece mainde belirtilecek
#include "controllers/SignUp.h"
using namespace std;

int main() {

    while (true)
    {
        cout << "                                            --.                                           " << endl;
        cout << "                                        .=#@@@@#=.                                        " << endl;
        cout << "                                     :+%@@@@@@@@@@%+:                                     " << endl;
        cout << "                                  -*%@@@@@#=.:-*@@@@@@*-                                  " << endl;
        cout << "                              .=*@@@@@%+::=#@@%+--+#@@@@@#=.                              " << endl;
        cout << "                           :+%@@@@%*-:=*@@@@@@@@@@#+--*%@@@@%+:                           " << endl;
        cout << "                        -*@@@@@#=::+%@@@@@@@$@@@@@@@@%+::=#@@@@@*-.                       " << endl;
        cout << "                    .=#@@@@%+-:=#@@@@@@@@@  $  @@@@@@@@@%+--=#@@@@#=.                     " << endl;
        cout << "                 :+%@@@@#=:-*@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@#=:=*@@@@%+:                 " << endl;
        cout << "               -======:  :-=====================================:  :======-               " << endl;
        cout << "                       :%@@@@@@@%=      #%@@@@@@@#      -%@@@@@@@%=                       " << endl;
        cout << "                         @@@@@@@:        =@@@@@@*         @@@@@@@                         " << endl;
        cout << "                         @@@@@@@:        =@@@@@@*         @@@@@@@                         " << endl;
        cout << "                         @@@@@@@:        =@@@@@@*         @@@@@@@                         " << endl;
        cout << "                         @@@@@@@:        =@@@@@@*         @@@@@@@                         " << endl;
        cout << "                         @@@@@@@:        =@@@@@@*         @@@@@@@                         " << endl;
        cout << "                         @@@@@@@:        =@@@@@@*         @@@@@@@                         " << endl;
        cout << "                       .-@@@@@@@=.      -*@@@@@@#-      .-@@@@@@@-.                       " << endl;
        cout << "                       .+++++++++-      ++++++++++      :+++++++++:                       " << endl;
        cout << "                    *################################################*                    " << endl;
        cout << "                @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@:               " << endl;
        cout << "           :##################################################################-           " << endl;
        cout << endl;

        cout <<"                                  Welcome to the BankC++ "<< endl;
        cout <<"------------------------------------------------------------------------------------------"<< endl << endl;
        cout << "[1] Login" << endl;
        cout << "[2] Sign Up" << endl << endl;

        string input;
        getline(cin, input);  //düz cin kullandığımızda her harfi buffera atıyordu ve her bir harf için 1 invalid input veriyordu.
        char choice = input[0];

        switch (choice) 
        {
            case '1':
                loginMenu(); 
                break;
            case '2':
                SignUpMenu(); 
                break;
            default:
                cout << "Invalid input. Please try again." << endl;
                break;
        }
    }
    
    return 0;
}

//g++ -Icontrollers -Imodel -Iutil main.cpp controllers/Login.cpp controllers/SignUp.cpp controllers/AccountMenu.cpp controllers/sendMoneyMenu.cpp controllers/dollarAccountMenu.cpp model/User.cpp model/Repository.cpp util/Validation.cpp util/Authentication.cpp -o BankApp
//./BankApp  