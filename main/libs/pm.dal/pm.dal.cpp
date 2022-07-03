#include <iostream>
#include <string>
#include <exception>
#include "pch.h"
#include "..\nanodbc\nanodbc.h"

using namespace std;
namespace pm::dal
{
    
    auto getIdByUsername(string username) try
    {
        auto const connstr = NANODBC_TEXT("Driver={ODBC Driver 17 for SQL Server};Server=.\\SQLExpress;Database=ProjectManager;Trusted_Connection=yes;"); // an ODBC connection string to your database
        nanodbc::connection conn(connstr);

        string query = NANODBC_TEXT("SELECT Id FROM Users WHERE Username = '" + username + "'");
        auto result = nanodbc::execute(conn, query);
        for (auto i = 1; result.next(); ++i)
        {
            auto id = result.get<int>(0);
            return id;
        }
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    auto getIdByProjectName(string title) try
    {
        auto const connstr = NANODBC_TEXT("Driver={ODBC Driver 17 for SQL Server};Server=.\\SQLExpress;Database=ProjectManager;Trusted_Connection=yes;"); // an ODBC connection string to your database
        nanodbc::connection conn(connstr);

        string query = NANODBC_TEXT("SELECT Id FROM Projects WHERE Title = '" + title + "'");
        auto result = nanodbc::execute(conn, query);
        for (auto i = 1; result.next(); ++i)
        {
            auto id = result.get<int>(0);
            return id;
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

    void insertProjectsDB(string title, string description, string username) try
    {
        nanodbc::connection connection("Driver={ODBC Driver 17 for SQL Server};Server=.\\SQLExpress;Database=ProjectManager;Trusted_Connection=yes;");
        nanodbc::statement statement(connection);

        prepare(statement, "INSERT INTO Projects(Title, [Description], CreatorID) VALUES (?,?," + to_string(getIdByUsername(username)) + ")");

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

    
    bool checkAdmin(string username) try
    {

        auto const connstr = NANODBC_TEXT("Driver={ODBC Driver 17 for SQL Server};Server=.\\SQLExpress;Database=ProjectManager;Trusted_Connection=yes;"); // an ODBC connection string to your database
        nanodbc::connection conn(connstr);
        string query = NANODBC_TEXT("SELECT RoleID FROM Users WHERE Username = '" + username + "'");
        auto result = nanodbc::execute(conn, query);
        for (long i = 1; result.next(); ++i)
        {
            auto admin = result.get<int>(0);
            if (admin == 2)
            {
                return true;
            }
        }
        return false;
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    void showUserProjects(string username) try
    {
        auto const connstr = NANODBC_TEXT("Driver={ODBC Driver 17 for SQL Server};Server=.\\SQLExpress;Database=ProjectManager;Trusted_Connection=yes;"); // an ODBC connection string to your database
        nanodbc::connection conn(connstr);
        int y = 20;
        string query = NANODBC_TEXT("SELECT Title FROM Projects WHERE UserID = " + to_string(getIdByUsername(username)));
        auto result = nanodbc::execute(conn, query);
        for (long i = 1; result.next(); ++i)
        {
            auto title = result.get<std::string>(0);
            pm::tools::consoleCoordinates(45, y);
            y += 2;
            std::cout << title << "\n";
        }
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    void checkUser(string username, string password) try
    {
        auto const connstr = NANODBC_TEXT("Driver={ODBC Driver 17 for SQL Server};Server=.\\SQLExpress;Database=ProjectManager;Trusted_Connection=yes;"); // an ODBC connection string to your database
        nanodbc::connection conn(connstr);

        string query = NANODBC_TEXT("SELECT COUNT(1) FROM Users WHERE [Password] LIKE '" + password + "' AND Username LIKE '" + username + "'");
        auto result = nanodbc::execute(conn, query);
        int flag;
        for (long i = 1; result.next(); ++i)
        {
            auto count = result.get<int>(0);
            flag = count;
        }
        if (flag == 1)
        {
            if (checkAdmin(username) == true)
            {
                cout << "Admin panel";
            }
            else
            {
                system("CLS");
                pm::consoleApp::border(0, 0, 51);
                pm::consoleApp::label(30, 1);
                pm::consoleApp::border(107, 0, 51);
                pm::consoleApp::userOptions(username);
            }
        }
        else
        {
            Sleep(200);
            cout << "Wrong username or password";
            system("CLS");
            pm::consoleApp::mainMenu();
        }
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    void showUserCreatedProjects(string username)
    {
        auto const connstr = NANODBC_TEXT("Driver={ODBC Driver 17 for SQL Server};Server=.\\SQLExpress;Database=ProjectManager;Trusted_Connection=yes;"); // an ODBC connection string to your database
        nanodbc::connection conn(connstr);
        int y = 20;
        string query = NANODBC_TEXT("SELECT Title FROM Projects WHERE CreatorID = " + to_string(getIdByUsername(username)));
        auto result = nanodbc::execute(conn, query);
        for (long i = 1; result.next(); ++i)
        {
            auto title = result.get<std::string>(0);
            pm::tools::consoleCoordinates(45, y);
            y += 2;
            std::cout << title << "\n";
        }
    }

    void updateProjects(string title, string newTitle, string description, string username)
    {
        nanodbc::connection connection("Driver={ODBC Driver 17 for SQL Server};Server=.\\SQLExpress;Database=ProjectManager;Trusted_Connection=yes;");
        nanodbc::statement statement(connection);
        string result = "UPDATE Projects SET Title = '" + newTitle + "' , [Description] = '" + description + "' WHERE Title = '" + title + "' AND CreatorID = " + to_string(getIdByUsername(username));
        prepare(statement, result);
        execute(statement);
    }

    void deleteProjects(string title, string username)
    {
        nanodbc::connection connection("Driver={ODBC Driver 17 for SQL Server};Server=.\\SQLExpress;Database=ProjectManager;Trusted_Connection=yes;");
        nanodbc::statement statement(connection);
        string result = "DELETE FROM Projects WHERE Title = '" + title + "' AND CreatorID = " + to_string(getIdByUsername(username));
        prepare(statement, result);
        execute(statement);
    }

    void viewProject(string name)
    {
        auto const connstr = NANODBC_TEXT("Driver={ODBC Driver 17 for SQL Server};Server=.\\SQLExpress;Database=ProjectManager;Trusted_Connection=yes;"); // an ODBC connection string to your database
        nanodbc::connection conn(connstr);
        string query = NANODBC_TEXT("SELECT Title, [Description] FROM Projects WHERE Title = '" + name + "'");
        auto result = nanodbc::execute(conn, query);
        string title;
        string description;
        for (long i = 1; result.next(); ++i)
        {
              title = result.get<std::string>(0);
              description = result.get<std::string>(1);
            
        }
        system("CLS");
        pm::consoleApp::border(0, 0, 51);
        pm::consoleApp::label(30, 1);
        pm::consoleApp::border(107, 0, 51);
        pm::tools::consoleCoordinates(45, 20);
        cout << "Project title: " << title;
        pm::tools::consoleCoordinates(45, 21);
        cout << "Project description: ";
        pm::tools::consoleCoordinates(45, 22);
        cout << description;
        
    }

    void viewTasksInProject(string name)
    {
        auto const connstr = NANODBC_TEXT("Driver={ODBC Driver 17 for SQL Server};Server=.\\SQLExpress;Database=ProjectManager;Trusted_Connection=yes;"); // an ODBC connection string to your database
        nanodbc::connection conn(connstr);
        string query = NANODBC_TEXT("SELECT TOP 5 Title FROM Tasks WHERE ProjectID = " + to_string(getIdByProjectName(name)));
        auto result = nanodbc::execute(conn, query);
        string task;
        pm::tools::consoleCoordinates(45, 24);
        cout << "Tasks:";
        int y = 25;
        for (long i = 1; result.next(); ++i)
        {
            pm::tools::consoleCoordinates(45, y);
            task = result.get<std::string>(0);
            cout << task;
            y++;
        }
    }

    void viewTeamsInProject(string name)
    {
        auto const connstr = NANODBC_TEXT("Driver={ODBC Driver 17 for SQL Server};Server=.\\SQLExpress;Database=ProjectManager;Trusted_Connection=yes;"); // an ODBC connection string to your database
        nanodbc::connection conn(connstr);
        string query = NANODBC_TEXT("SELECT Title FROM Teams WHERE ProjectID = " + to_string(getIdByProjectName(name)));
        auto result = nanodbc::execute(conn, query);
        string team;
        pm::tools::consoleCoordinates(45, 30);
        cout << "Team:";
        for (long i = 1; result.next(); ++i)
        {
            pm::tools::consoleCoordinates(45, 31);
            team = result.get<std::string>(0);
            cout << team;
        }
    }
}


