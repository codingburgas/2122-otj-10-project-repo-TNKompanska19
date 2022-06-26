#include <iostream>
#include <string>
#include "..\libs\pm.dal\UserStore.h"
#include "..\libs\pm.consoleApp\mainMenu.h"
using namespace std;
int main()
{
    /*cout << "Enter first name:\n";
    string firstName;
    cin >> firstName;
    cout << "\n Enter last name: \n";
    string lastName;
    cin >> lastName;
    cout << "\n Enter email: \n";
    string username;
    cin >> username;
    cout << "\n Enter pass: \n";
    string pass;
    cin >> pass;*/

    /*cout << "Enter title\n";
    string title;
    cin >> title;
    cout << "Enter desc\n";
    string desc;
    cin >> desc;
    cout << "Enter pr name\n";
    string pr;
    cin >> pr;
    cout << "Enter username\n";
    string user;
    cin >> user;*/

    cout << "Enter username: \n";
    string username;
    cin >> username;
    cout << "Enter password: \n";
    string password;
    cin >> password;

    cout << pm::dal::getIdByUsername(username);

    
}

