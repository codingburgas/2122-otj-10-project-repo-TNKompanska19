#include <iostream>
#include "..\libs\pm.dal\UserStore.h"
#include "..\libs\pm.consoleApp\mainMenu.h"
using namespace std;
int main()
{
    cout << "Enter first name:\n";
    string firstName;
    cin >> firstName;
    cout << "\n Enter last name: \n";
    string lastName;
    cin >> lastName;
    cout << "\n Enter age: \n";
    int age;
    cin >> age;
    cout << "\n Enter email: \n";
    string email;
    cin >> email;
    cout << "\n Enter pass: \n";
    string pass;
    cin >> pass;

    pm::dal::insertDB(firstName, lastName, age, email, pass);
}

