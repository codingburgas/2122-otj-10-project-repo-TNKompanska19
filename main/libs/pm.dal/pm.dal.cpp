#include <iostream>
#include <string>
#include <exception>

#include "pch.h"
#include "..\nanodbc\nanodbc.h"

using namespace std;
namespace pm::dal
{

    void print()
    {
        cout << "mbruh";
    }
    void sth() try
    {
        auto const connstr = NANODBC_TEXT("Driver={ODBC Driver 17 for SQL Server};Server=(local)\\SQLExpress;Database=ProjectManager;Trusted_Connection=yes;"); // an ODBC connection string to your database
        nanodbc::connection conn(connstr);

        string query = NANODBC_TEXT("SELECT TOP 10 * FROM Users");
        auto result = nanodbc::execute(conn, query);
        while (result.next())
        {
            auto id = result.get<int>(0);
            auto firstName = result.get<std::string>(1);

            std::cout << id << " , " << firstName << "\n";
        }
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }


    void insertDB() try
    {
        auto const connstr = NANODBC_TEXT("Driver={ODBC Driver 17 for SQL Server};Server=(local)\\SQLExpress;Database=ProjectManager;Trusted_Connection=yes;"); // an ODBC connection string to your database
        nanodbc::connection conn(connstr);

        cout << "Enter name:\n";
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
        auto result = nanodbc::execute(conn, "INSERT INTO Users ([First Name], [Last Name], Age, Email, [Password]) VALUES ('" + firstName +"', '" +lastName  + "', " + to_string(age) + ", '" +email + "', '" + pass + "')");
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

}
