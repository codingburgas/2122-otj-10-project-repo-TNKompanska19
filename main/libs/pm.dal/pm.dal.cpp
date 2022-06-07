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
        auto const connstr = NANODBC_TEXT("Driver={ODBC Driver 17 for SQL Server};Server=.\\SQLExpress;Database=ProjectManager;Trusted_Connection=yes;"); // an ODBC connection string to your database
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


    void insertDB(string firstName, string lastName, int age, string email, string pass) try
    {
        nanodbc::connection connection("Driver={ODBC Driver 17 for SQL Server};Server=.\\SQLExpress;Database=ProjectManager;Trusted_Connection=yes;");
        nanodbc::statement statement(connection);

        prepare(statement,"INSERT INTO Users([First Name], [Last Name], Age, Email, [Password]) VALUES (?,?,?,?,?)");

        statement.bind(0, firstName.c_str());
        statement.bind(1, lastName.c_str());
        statement.bind(2, &age);
        statement.bind(3, email.c_str());
        statement.bind(4, pass.c_str());

        execute(statement);
        // execute(statement);
        //cout << "Aff rows: " << result.affected_rows();
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

}
