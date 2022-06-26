#include <iostream>
#include <string>
#include <exception>
#include "pch.h"
#include "..\nanodbc\nanodbc.h"

using namespace std;
namespace pm::dal
{
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


    void insertUsersDB(string username, string firstName, string lastName, string pass) try
    {
        nanodbc::connection connection("Driver={ODBC Driver 17 for SQL Server};Server=.\\SQLExpress;Database=ProjectManager;Trusted_Connection=yes;");
        nanodbc::statement statement(connection);

        prepare(statement, "INSERT INTO Users(Username, FirstName, LastName, [Password]) VALUES (?,?,?,?)");

        statement.bind(0, username.c_str());
        statement.bind(1, firstName.c_str());
        statement.bind(2, lastName.c_str());
        statement.bind(3, pass.c_str());

        execute(statement);
        // execute(statement);
        //cout << "Aff rows: " << result.affected_rows();
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    void insertProjectsDB(string title, string description) try
    {
        nanodbc::connection connection("Driver={ODBC Driver 17 for SQL Server};Server=.\\SQLExpress;Database=ProjectManager;Trusted_Connection=yes;");
        nanodbc::statement statement(connection);

        prepare(statement, "INSERT INTO Projects(Title, [Description]) VALUES (?,?)");

        statement.bind(0, title.c_str());
        statement.bind(1, description.c_str());

        execute(statement);
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    void insertTasks(string title, string description, string projectName, string username)try
    {
        nanodbc::connection connection("Driver={ODBC Driver 17 for SQL Server};Server=.\\SQLExpress;Database=ProjectManager;Trusted_Connection=yes;");
        nanodbc::statement statement(connection);

        prepare(statement, "INSERT INTO Tasks(Title, [Description]) VALUES (?,?) DECLARE @ProjectID INT SELECT @ProjectID = Id FROM Projects WHERE Title = '" + projectName + "' UPDATE Tasks SET ProjectID = @ProjectID WHERE Title = '" + title + "' DECLARE @UserID INT SELECT @UserID = Id FROM Users WHERE Username = '" + username + "' UPDATE Tasks SET AsigneeID = @UserID WHERE Title = '" + title + "'");
        statement.bind(0, title.c_str());
        statement.bind(1, description.c_str());

        execute(statement);
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    void insertTeams(string title) try
    {
        nanodbc::connection connection("Driver={ODBC Driver 17 for SQL Server};Server=.\\SQLExpress;Database=ProjectManager;Trusted_Connection=yes;");
        nanodbc::statement statement(connection);

        prepare(statement, "INSERT INTO Teams(Title) VALUES (?) ");
        statement.bind(0, title.c_str());

        execute(statement);
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }


    void insertUsersInTeam(int users, string teamName)try
    {
        nanodbc::connection connection("Driver={ODBC Driver 17 for SQL Server};Server=.\\SQLExpress;Database=ProjectManager;Trusted_Connection=yes;");
        nanodbc::statement statement(connection);

        string username;
        for (int i = 1; i <= users; i++)
        {
            cout << "Enter username:";
            cin >> username;

            prepare(statement, "DECLARE @TeamID INT SELECT @TeamID = Id FROM Teams WHERE Title = '" + teamName + "' UPDATE Users SET TeamID = @TeamID WHERE Username = '" + username + "'");
            execute(statement);
        }

    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    void insertUsersInProject(string username, string projectName) try
    {
        nanodbc::connection connection("Driver={ODBC Driver 17 for SQL Server};Server=.\\SQLExpress;Database=ProjectManager;Trusted_Connection=yes;");
        nanodbc::statement statement(connection);
        string result = "DECLARE @ProjectID INT SELECT @ProjectID = Id FROM Projects WHERE Title = '" + projectName + "' UPDATE Users SET ProjectID = @ProjectID WHERE Username = '" + username + "'";
        prepare(statement, result);
        //statement.bind(0, username.c_str());
        //statement.bind(1, projectName.c_str());

        execute(statement);

    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    int getIdByUsername(string username) try
    {
        auto const connstr = NANODBC_TEXT("Driver={ODBC Driver 17 for SQL Server};Server=.\\SQLExpress;Database=ProjectManager;Trusted_Connection=yes;"); // an ODBC connection string to your database
        nanodbc::connection conn(connstr);

        string query = NANODBC_TEXT("SELECT Id FROM Users WHERE Username = '" + username + "'");
        auto result = nanodbc::execute(conn, query);
        for (long i = 1; result.next(); ++i)
        {
            auto id = result.get<int>(0);
            return id;
        }
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
}


