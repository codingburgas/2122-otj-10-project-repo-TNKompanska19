#include <iostream>
#include <string>
#include <exception>
#include "pch.h"
#include "..\nanodbc\nanodbc.h"

using namespace std;
namespace pm::dal
{ 
    namespace users
    {
        // Function for getting user id
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

        // Function for checking if the user exists
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
                    system("CLS");
                    pm::consoleApp::mainMenu::border(0, 0, 51);
                    pm::consoleApp::mainMenu::label(30, 1);
                    pm::consoleApp::mainMenu::border(107, 0, 51);
                    pm::consoleApp::adminView::adminOptions(username);
                }
                else
                {
                    system("CLS");
                    pm::consoleApp::mainMenu::border(0, 0, 51);
                    pm::consoleApp::mainMenu::label(30, 1);
                    pm::consoleApp::mainMenu::border(107, 0, 51);
                    pm::consoleApp::userView::userOptions(username);
                }
            }
            else
            {
                system("CLS");
                Sleep(200);
                cout << "Wrong username or password!";
                system("CLS");
                pm::consoleApp::mainMenu::mainMenu();
            }
        }
        catch (std::exception& e)
        {
            std::cerr << e.what() << std::endl;
        }

        // Function for checking if the user is admin
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

        // Function for showing all users
        void showUsers() try
        {
            auto const connstr = NANODBC_TEXT("Driver={ODBC Driver 17 for SQL Server};Server=.\\SQLExpress;Database=ProjectManager;Trusted_Connection=yes;"); // an ODBC connection string to your database
            nanodbc::connection conn(connstr);
            string query = NANODBC_TEXT("SELECT Username, FirstName, LastName FROM Users");
            auto result = nanodbc::execute(conn, query);
            string username, firstName, lastName;
            pm::tools::consoleCoordinates(45, 15);
            cout << "USERS:";
            int y = 20;
            for (long i = 1; result.next(); ++i)
            {
                pm::tools::consoleCoordinates(35, y);
                username = result.get<std::string>(0);
                firstName = result.get<std::string>(1);
                lastName = result.get<std::string>(2);
                cout << "Full name: " << firstName << " " << lastName;
                y++;
                pm::tools::consoleCoordinates(35, y);
                username = result.get<std::string>(0);
                cout << "Username: " << username;
                y += 2;
            }
        }
        catch (std::exception& e)
        {
            std::cerr << e.what() << std::endl;
        }

        // Function for making user an admin
        void makeAnAdmin(string username) try
        {
            nanodbc::connection connection("Driver={ODBC Driver 17 for SQL Server};Server=.\\SQLExpress;Database=ProjectManager;Trusted_Connection=yes;");
            nanodbc::statement statement(connection);
            prepare(statement, "UPDATE Users SET RoleID = 2 WHERE Username = '" + username + "'");
            execute(statement);
        }
        catch (std::exception& e)
        {
            std::cerr << e.what() << std::endl;
        }

        // Function for adding users
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

        // Function for adding users in team
        void insertUsersInTeam(int users, string teamName)try
        {
            nanodbc::connection connection("Driver={ODBC Driver 17 for SQL Server};Server=.\\SQLExpress;Database=ProjectManager;Trusted_Connection=yes;");
            nanodbc::statement statement(connection);
            int y = 25;
            string username;
            for (int i = 1; i <= users; i++)
            {
                pm::tools::consoleCoordinates(45, y);
                cout << "Enter username:";
                cin >> username;
                y++;
                string result = "UPDATE Users SET TeamID = " + to_string(pm::dal::teams::getIdByTeamName(teamName)) + "WHERE Username = '" + username + "'";
                prepare(statement, result);
                execute(statement);
            }
        }
        catch (std::exception& e)
        {
            std::cerr << e.what() << std::endl;
        }

        // Function for adding users in project
        void insertUsersInProject(int users, string projectName) try
        {
            nanodbc::connection connection("Driver={ODBC Driver 17 for SQL Server};Server=.\\SQLExpress;Database=ProjectManager;Trusted_Connection=yes;");
            nanodbc::statement statement(connection);
            int y = 27;
            string username;
            for (int i = 1; i <= users; i++)
            {
                pm::tools::consoleCoordinates(45, y);
                cout << "Enter username:";
                cin >> username;
                y++;
                string result = "UPDATE Users SET ProjectID = " + to_string(pm::dal::projects::getIdByProjectName(projectName)) + "WHERE Username = '" + username + "'";
                prepare(statement, result);
                execute(statement);
            }

        }
        catch (std::exception& e)
        {
            std::cerr << e.what() << std::endl;
        }

        // Function for deleting users
        void deleteUsers(string username)try
        {
            nanodbc::connection connection("Driver={ODBC Driver 17 for SQL Server};Server=.\\SQLExpress;Database=ProjectManager;Trusted_Connection=yes;");
            nanodbc::statement statement(connection);
            string result = "DELETE FROM Users WHERE Username = '" + username + "'";
            prepare(statement, result);
            execute(statement);
        }
        catch (std::exception& e)
        {
            std::cerr << e.what() << std::endl;
        }

        // Function for editing users
        void updateUsers(string username, string firstName, string lastName, string newUsername) try
        {
            nanodbc::connection connection("Driver={ODBC Driver 17 for SQL Server};Server=.\\SQLExpress;Database=ProjectManager;Trusted_Connection=yes;");
            nanodbc::statement statement(connection);
            string result = "UPDATE Users SET FirstName = '" + firstName + "' , LastName = '" + lastName + "', Username = '" + newUsername + "' WHERE Username = '" + username + "'";
            prepare(statement, result);
            execute(statement);
        }
        catch (std::exception& e)
        {
            std::cerr << e.what() << std::endl;
        }

        // Function for changing password
        void updatePassword(string username, string password) try
        {
            nanodbc::connection connection("Driver={ODBC Driver 17 for SQL Server};Server=.\\SQLExpress;Database=ProjectManager;Trusted_Connection=yes;");
            nanodbc::statement statement(connection);
            string result = "UPDATE Users SET [Password] = '" + password + "' WHERE Username = '" + username + "'";
            prepare(statement, result);
            execute(statement);
        }
        catch (std::exception& e)
        {
            std::cerr << e.what() << std::endl;
        }
    }

    namespace projects
    {
        // Function for getting project id
        int getIdByProjectName(string title) try
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


        // Function for viewing all projects
        void showProjects() try
        {
            auto const connstr = NANODBC_TEXT("Driver={ODBC Driver 17 for SQL Server};Server=.\\SQLExpress;Database=ProjectManager;Trusted_Connection=yes;"); // an ODBC connection string to your database
            nanodbc::connection conn(connstr);
            string query = NANODBC_TEXT("SELECT Title, [Description] FROM Projects");
            auto result = nanodbc::execute(conn, query);
            string title, description;
            pm::tools::consoleCoordinates(45, 15);
            cout << "PROJECTS:";
            int y = 20;
            for (long i = 1; result.next(); ++i)
            {
                pm::tools::consoleCoordinates(35, y);
                title = result.get<std::string>(0);
                description = result.get<std::string>(1);
                cout << "Title: " << title;
                y++;
                pm::tools::consoleCoordinates(35, y);
                cout << "Description: " << description;
                y += 2;
            }
        }
        catch (std::exception& e)
        {
            std::cerr << e.what() << std::endl;
        }

        // Function for adding projects
        void insertProjectsDB(string title, string description, string username) try
        {
            nanodbc::connection connection("Driver={ODBC Driver 17 for SQL Server};Server=.\\SQLExpress;Database=ProjectManager;Trusted_Connection=yes;");
            nanodbc::statement statement(connection);

            prepare(statement, "INSERT INTO Projects(Title, [Description], CreatorID) VALUES (?,?," + to_string(pm::dal::users::getIdByUsername(username)) + ")");

            statement.bind(0, title.c_str());
            statement.bind(1, description.c_str());

            execute(statement);
        }
        catch (std::exception& e)
        {
            std::cerr << e.what() << std::endl;
        }

        // Function for getting project id by username
        int getProjectIdByUsername(string username) try
        {
            auto const connstr = NANODBC_TEXT("Driver={ODBC Driver 17 for SQL Server};Server=.\\SQLExpress;Database=ProjectManager;Trusted_Connection=yes;"); // an ODBC connection string to your database
            nanodbc::connection conn(connstr);

            string query = NANODBC_TEXT("SELECT ProjectID FROM Users WHERE Username = '" + username + "'");
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

        // Function for viewing in which projects user is in
        void showUserProjects(string username) try
        {
            auto const connstr = NANODBC_TEXT("Driver={ODBC Driver 17 for SQL Server};Server=.\\SQLExpress;Database=ProjectManager;Trusted_Connection=yes;"); // an ODBC connection string to your database
            nanodbc::connection conn(connstr);
            int y = 20;
            string query = NANODBC_TEXT("SELECT Title FROM Projects WHERE Id = " + to_string(pm::dal::projects::getProjectIdByUsername(username)));
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

        // Function for viewing user created projects
        void showUserCreatedProjects(string username) try
        {
            auto const connstr = NANODBC_TEXT("Driver={ODBC Driver 17 for SQL Server};Server=.\\SQLExpress;Database=ProjectManager;Trusted_Connection=yes;"); // an ODBC connection string to your database
            nanodbc::connection conn(connstr);
            int y = 20;
            string query = NANODBC_TEXT("SELECT Title FROM Projects WHERE CreatorID = " + to_string(pm::dal::users::getIdByUsername(username)));
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

        // Function for viewing projects info
        void viewProject(string name) try
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
            pm::consoleApp::mainMenu::border(0, 0, 51);
            pm::consoleApp::mainMenu::label(30, 1);
            pm::consoleApp::mainMenu::border(107, 0, 51);
            pm::tools::consoleCoordinates(45, 20);
            cout << "Project title: " << title;
            pm::tools::consoleCoordinates(45, 21);
            cout << "Project description: ";
            pm::tools::consoleCoordinates(45, 22);
            cout << description;

        }
        catch (std::exception& e)
        {
            std::cerr << e.what() << std::endl;
        }

        // Function for editing projects
        void updateProjects(string title, string newTitle, string description, string username) try
        {
            nanodbc::connection connection("Driver={ODBC Driver 17 for SQL Server};Server=.\\SQLExpress;Database=ProjectManager;Trusted_Connection=yes;");
            nanodbc::statement statement(connection);
            string result = "UPDATE Projects SET Title = '" + newTitle + "' , [Description] = '" + description + "' WHERE Title = '" + title + "' AND CreatorID = " + to_string(pm::dal::users::getIdByUsername(username));
            prepare(statement, result);
            execute(statement);
        }
        catch (std::exception& e)
        {
            std::cerr << e.what() << std::endl;
        }

        // Function for deleting projects
        void deleteProjects(string title, string username)try
        {
            nanodbc::connection connection("Driver={ODBC Driver 17 for SQL Server};Server=.\\SQLExpress;Database=ProjectManager;Trusted_Connection=yes;");
            nanodbc::statement statement(connection);
            string result = "DELETE FROM Projects WHERE Title = '" + title + "' AND CreatorID = " + to_string(pm::dal::users::getIdByUsername(username));
            prepare(statement, result);
            execute(statement);
        }
        catch (std::exception& e)
        {
            std::cerr << e.what() << std::endl;
        }

    }
    
    namespace teams
    {
        // Function for getting team id
        int getIdByTeamName(string teamName) try
        {
            auto const connstr = NANODBC_TEXT("Driver={ODBC Driver 17 for SQL Server};Server=.\\SQLExpress;Database=ProjectManager;Trusted_Connection=yes;"); // an ODBC connection string to your database
            nanodbc::connection conn(connstr);

            string query = NANODBC_TEXT("SELECT Id FROM Teams WHERE Title = '" + teamName + "'");
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

        // Function for showing all teams
        void showTeams() try
        {
            auto const connstr = NANODBC_TEXT("Driver={ODBC Driver 17 for SQL Server};Server=.\\SQLExpress;Database=ProjectManager;Trusted_Connection=yes;"); // an ODBC connection string to your database
            nanodbc::connection conn(connstr);
            string query = NANODBC_TEXT("SELECT Title FROM Teams");
            auto result = nanodbc::execute(conn, query);
            string title;
            pm::tools::consoleCoordinates(45, 15);
            cout << "TEAMS:";
            int y = 20;
            for (long i = 1; result.next(); ++i)
            {
                pm::tools::consoleCoordinates(35, y);
                title = result.get<std::string>(0);
                cout << "Title: " << title;
                y += 2;
            }
        }
        catch (std::exception& e)
        {
            std::cerr << e.what() << std::endl;
        }

        // Function for adding teams
        void insertTeams(string title, string projectName) try
        {
            nanodbc::connection connection("Driver={ODBC Driver 17 for SQL Server};Server=.\\SQLExpress;Database=ProjectManager;Trusted_Connection=yes;");
            nanodbc::statement statement(connection);

            prepare(statement, "INSERT INTO Teams(Title, ProjectID) VALUES (?," + to_string(pm::dal::projects::getIdByProjectName(projectName)) + ")");
            statement.bind(0, title.c_str());

            execute(statement);
        }
        catch (std::exception& e)
        {
            std::cerr << e.what() << std::endl;
        }

        
        // Function for showing in which team user is 
        void showUserTeams(string username) try
        {
            auto const connstr = NANODBC_TEXT("Driver={ODBC Driver 17 for SQL Server};Server=.\\SQLExpress;Database=ProjectManager;Trusted_Connection=yes;"); // an ODBC connection string to your database
            nanodbc::connection conn(connstr);
            int y = 20;
            string query = NANODBC_TEXT("SELECT Title FROM Teams WHERE UserID = " + to_string(pm::dal::users::getIdByUsername(username)));
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

        // Function for viewing team in project
        void viewTeamsInProject(string name) try
        {
            auto const connstr = NANODBC_TEXT("Driver={ODBC Driver 17 for SQL Server};Server=.\\SQLExpress;Database=ProjectManager;Trusted_Connection=yes;"); // an ODBC connection string to your database
            nanodbc::connection conn(connstr);
            string query = NANODBC_TEXT("SELECT Title FROM Teams WHERE ProjectID = " + to_string(pm::dal::projects::getIdByProjectName(name)));
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
        catch (std::exception& e)
        {
            std::cerr << e.what() << std::endl;
        }

        // Function for editing teams
        void updateTeams(string title, string newTitle) try
        {
            nanodbc::connection connection("Driver={ODBC Driver 17 for SQL Server};Server=.\\SQLExpress;Database=ProjectManager;Trusted_Connection=yes;");
            nanodbc::statement statement(connection);
            string result = "UPDATE Teams SET Title = '" + newTitle + "' WHERE Title = '" + title + "'";
            prepare(statement, result);
            execute(statement);
        }
        catch (std::exception& e)
        {
            std::cerr << e.what() << std::endl;
        }

        // Function for deleting teams
        void deleteTeams(string title) try
        {
            nanodbc::connection connection("Driver={ODBC Driver 17 for SQL Server};Server=.\\SQLExpress;Database=ProjectManager;Trusted_Connection=yes;");
            nanodbc::statement statement(connection);
            string result = "DELETE FROM Teams WHERE Title = '" + title + "'";
            prepare(statement, result);
            execute(statement);
        }
        catch (std::exception& e)
        {
            std::cerr << e.what() << std::endl;
        }

    }
    
    namespace tasks
    {
        // Function for adding tasks
        void insertTasks(string title, string description, string projectName) try
        {
            nanodbc::connection connection("Driver={ODBC Driver 17 for SQL Server};Server=.\\SQLExpress;Database=ProjectManager;Trusted_Connection=yes;");
            nanodbc::statement statement(connection);

            prepare(statement, "INSERT INTO Tasks(Title, [Description], ProjectID) VALUES (?,?," + to_string(pm::dal::projects::getIdByProjectName(projectName)) + ")");
            statement.bind(0, title.c_str());
            statement.bind(1, description.c_str());

            execute(statement);
        }
        catch (std::exception& e)
        {
            std::cerr << e.what() << std::endl;
        }

        // Function for viewing task in project
        void viewTasksInProject(string name) try
        {
            auto const connstr = NANODBC_TEXT("Driver={ODBC Driver 17 for SQL Server};Server=.\\SQLExpress;Database=ProjectManager;Trusted_Connection=yes;"); // an ODBC connection string to your database
            nanodbc::connection conn(connstr);
            string query = NANODBC_TEXT("SELECT TOP 5 Title FROM Tasks WHERE ProjectID = " + to_string(pm::dal::projects::getIdByProjectName(name)));
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
        catch (std::exception& e)
        {
            std::cerr << e.what() << std::endl;
        }

    }
    
 

}


