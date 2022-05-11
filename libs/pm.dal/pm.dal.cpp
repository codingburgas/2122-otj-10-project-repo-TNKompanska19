#include "pch.h"
#include "UserStore.h"


namespace pm::dal
{
    void registration()
    {
        string username, password;
        cout << "Enter your username: \n";
        getline(cin, username);
        cout << "Enter your password: \n";
        getline(cin, password);
        ofstream file("UserStore.txt", ios::app);
        file << username << ' ' << password << endl;
        file.close();
    }
}



