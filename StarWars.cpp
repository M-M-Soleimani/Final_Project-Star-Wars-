#include <iostream>
#include <conio.h>
#include <windows.h>
#include<vector>
#include<string>
#include <time.h>
#include <stdlib.h>

// Defining color codes to beautify the game
#define Black "\u001b[30m"
#define Red "\u001b[31m"
#define Green "\u001b[32m"
#define Yellow "\u001b[33m"
#define Blue "\u001b[34m"
#define Magenta "\u001b[35m"
#define Cyan "\u001b[36m"
#define White "\u001b[37m"
#define Reset "\u001b[0m"
#define Bright_Black "\u001b[30;1m"
#define Bright_Red "\u001b[31;1m"
#define Bright_Green "\u001b[32;1m"
#define Bright_Yellow "\u001b[33;1m"
#define Bright_Blue "\u001b[34;1m"
#define Bright_Magenta "\u001b[35;1m"
#define Bright_Cyan "\u001b[36;1m"
#define Bright_White "\u001b[37;1m"

using namespace std;

struct Map_Components   // A data structure for the components in the game map with Initialization
{
    string name = "empty";
    int Health = 0;
    int damage = 0 ;
    int size = 1*1 ;
    string color = "White" ;
    string character = "[ ]";
};


bool Menu();    // function that displays the menu to the user
bool Game_Mode();   // function that allows the user to choose between two types of games
void Initializer_Basic(); // function for game preparation and initialization for Basic Mode
void Initializer_Advanced(); // function for game preparation and initialization for Advanced Mode
void positioning( vector <vector<Map_Components>>& map , int map_size ); // function that determines the position of elements in the map
void display( vector <vector<Map_Components>> map , int map_size ); // This function displays the game map

int main()
{
    while (Menu())
    {
        
    }

    return 0;
}

bool Menu()
{
    system("cls");  // This function clears the console
    bool Invalid_Selection = false;
    do
    {
        // In the next few lines, the menu will be displayed on the console
        cout << "1- Game Mode " << endl
         << "2- Continue Game " << endl
         << "3- Change SpacShip Character " << endl
         << "4- Save Game" << endl
         << "5- Description of SpaceShips " << endl
         << "6- History" << endl
         << "7- Exit " << endl;
        char user_selection;
        user_selection = getch();   // We get an option chosen by the user
        switch (user_selection)
        {
        case '1':
            if (Game_Mode())
            {
                return false;
            }
            else
                return true;
            break;

        case '2':
            /*code*/
            return true;
            break;

        case '3':
            /*code*/
            return true;
            break;

        case '4':
            /*code*/
            return true;
            break;

        case '5':
            /*code*/
            return true;
            break;

        case '6':
            /*code*/
            return true;
            break;

        case '7':
            /*code*/
            return false;
            break;

        default:
            Invalid_Selection = true;
            system("cls");  // This function clears the console
            cerr << Red << "Invalid Selection !" << Reset <<endl ;  // In this line, if an invalid choice is made by the user, an error will be displayed on the console
            break;
        }
    } while (Invalid_Selection);
    return false;
}

bool Game_Mode()
{
    system("cls");  // This function clears the console
    bool Invalid_Selection = false;
    do
    {
        // In the next few lines, the menu will be displayed on the console
        cout << "1- Basic Mode " << endl
         << "2- Advanced Mode " << endl
         << "3- Exit " << endl;
        char user_selection;
        user_selection = getch();   // We get an option chosen by the user
        switch (user_selection)
        {
        case '1':
            Initializer_Basic();
            return true;
            break;

        case '2':
            Initializer_Advanced();
            return true;
            break;

        case '3':
            return false;
            break;

        default:
            Invalid_Selection = true;
            system("cls");  // This function clears the console
            cerr << Red << "Invalid Selection !" << Reset <<endl ;  // In this line, if an invalid choice is made by the user, an error will be displayed on the console
            break;
        }
    } while (Invalid_Selection);
    return false;
}

void Initializer_Basic()
{
    system("cls");  // This function clears the console
    bool Invalid_Selection = false;
    int map_size ;
    do
    {
        Invalid_Selection = false;
        cout << "Enter the map size : " ;   // In these few lines, the dimensions of the playground are received from the user
        cin >> map_size ;
        if ( map_size <= 15 )
        {
            Invalid_Selection = true;
            system("cls");  // This function clears the console
            cerr << Red << "Invalid size ! (Map size should be bigger than 15) " << Reset <<endl ;  // In this line, if an invalid choice is made by the user, an error will be displayed on the console
        }
    } while (Invalid_Selection);
    vector <vector<Map_Components>> map ;
    map.resize( map_size , vector<Map_Components> (map_size) ); // Creates a two-dimensional vector with the dimensions of map size * map size

    system("cls");  // This function clears the console
    cout << "Enter the map size : " << map_size << endl ;
    cout << "Enter the quorum for the win : ";  // In these few lines, a quorum of points to win is received from the user
    int quorum_point;
    cin >> quorum_point;
    positioning( map , map_size );  // This function specifies the position of game elements
    display( map , map_size );  // This function displays the game map
}

void Initializer_Advanced()
{
    system("cls");  // This function clears the console
    bool Invalid_Selection = false;
    int map_size ;
    do
    {
        Invalid_Selection = false;
        cout << "Enter the map size : " ;   // In these few lines, the dimensions of the playground are received from the user
        cin >> map_size ;
        if ( map_size <= 15 )
        {
            Invalid_Selection = true;
            system("cls");  // This function clears the console
            cerr << Red << "Invalid size ! (Map size should be bigger than 15) " << Reset <<endl ;  // In this line, if an invalid choice is made by the user, an error will be displayed on the console
        }
    } while (Invalid_Selection);
    vector <vector<Map_Components>> map ;
    map.resize( map_size , vector<Map_Components> (map_size) ); // Creates a two-dimensional vector with the dimensions of map size * map size

    cout << "Enter the quorum for the win : ";  // In these few lines, a quorum of points to win is received from the user
    int quorum_point;
    cin >> quorum_point;

    Invalid_Selection = false;
    do
    {
        char Spaceship_Type ;
        string Spaceship_Type_name ;
        Invalid_Selection = false;
        cout << "Select the type of spaceship : " << endl   // In these few lines, we take the type of spaceship from the user
         << "1- spaceship 1" << endl
         << "2- spaceship 2" << endl
         << "3- spaceship 3" << endl ;
        Spaceship_Type = getch();
        switch (Spaceship_Type)
        {
        case '1':
            system("cls");  // This function clears the console
            cout << "Select the type of spaceship : spaceship 1 " << endl ;
            Spaceship_Type_name = "spaceship 1" ;   // In this line, we assign the name of a type of spaceship to a string variable to be used in subsequent functions.
            break;

        case '2':
            system("cls");  // This function clears the console
            cout << "Select the type of spaceship : spaceship 2 " << endl ;
            Spaceship_Type_name = "spaceship 2" ;   // In this line, we assign the name of a type of spaceship to a string variable to be used in subsequent functions.
            break;

        case '3':
            system("cls");  // This function clears the console
            cout << "Select the type of spaceship : spaceship 3 " << endl ;
            Spaceship_Type_name = "spaceship 3" ;   // In this line, we assign the name of a type of spaceship to a string variable to be used in subsequent functions.
            break;

        default:
            Invalid_Selection = true;
            system("cls");  // This function clears the console
            cerr << Red << "Invalid Selection !" << Reset <<endl ;  // In this line, if an invalid choice is made by the user, an error will be displayed on the console
            break;
        }
    } while (Invalid_Selection);
    cout << "Enter the map size : " << map_size << endl ;
    cout << "Enter the quorum for the win : " << quorum_point << endl; 
}

void positioning( vector <vector<Map_Components>>& map , int map_size )
{
    srand(time(0)); // A function that generates random numbers with an initial seed of time 0
    unsigned int row , column ;
    for (size_t i = 0; i < (map_size - 1); i++) // In these few lines, if there is no native ship, a ship will be created
    {
        if (map[map_size - 1][i].name != "Spaceship")
        {
            map[map_size - 1][(map_size - 1) / 2].name = "Spaceship" ;
            map[map_size - 1][(map_size - 1) / 2].Health = 3 ;
            map[map_size - 1][(map_size - 1) / 2].damage = 2147483647 ; // The largest possible value for an integer data type
            map[map_size - 1][(map_size - 1) / 2].size = 1 ;
            map[map_size - 1][(map_size - 1) / 2].color = "Bright_Green" ;
            map[map_size - 1][(map_size - 1) / 2].character = "[#]" ;
        break;
        }
    }
    int Enemy_Type ;
    bool Invalid_position = false ;
    Enemy_Type = rand() % 4 ;   // This function generates random numbers between 0 and 3
    switch (Enemy_Type)     // This section selects the type of enemy to create in the map
    {
    case 0:     // In each section of the switch case, a type of enemy is created
        column = rand() % map_size ;
        map[0][column].name = "Dart" ;
        map[0][column].Health = 1 ;
        map[0][column].damage = 1 ;
        map[0][column].size = 1*1 ;
        map[0][column].color = "Bright_Cyan" ;
        map[0][column].character = "[*]" ;
        break;
    
    case 1:
        do
        {
        column = rand() % map_size ;
        if (column + 2 <= map_size )
        {
            for (size_t i = 0; i < 2; i++)
            {
                for (size_t j = 0; j < 2; j++)
                {
                    map[i][column + j].name = "Striker" ;
                    map[i][column + j].Health = 2 ;
                    map[i][column + j].damage = 1 ;
                    map[i][column + j].size = 2*2 ;
                    map[i][column + j].color = "Bright_Blue" ;
                    map[i][column + j].character = "[*]" ;
                } 
            }
        }
        else
        {
            Invalid_position = true ;
        }
        } while (Invalid_position);
        break;
    
    case 2:
        Invalid_position = false ;
        do
        {
        if (column + 3 <= map_size)
        {
            for (size_t i = 0; i < 3; i++)
            {
                for (size_t j = 0; j < 3; j++)
                {
                    map[i][column + j].name = "Wraith" ;
                    map[i][column + j].Health = 4 ;
                    map[i][column + j].damage = 1 ;
                    map[i][column + j].size = 3*3 ;
                    map[i][column + j].color = "Blue" ;
                    map[i][column + j].character = "[*]" ;
                } 
            }
        }
        else
        {
            Invalid_position = true ;
        }
        } while (Invalid_position);
        break;

    case 3:
        Invalid_position = false ;
        do
        {
        if (column + 4 <= map_size)
        {
            for (size_t i = 0; i < 4; i++)
            {
                for (size_t j = 0; j < 4; j++)
                {
                    map[i][column + j].name = "Banshee" ;
                    map[i][column + j].Health = 6 ;
                    map[i][column + j].damage = 1 ;
                    map[i][column + j].size = 4*4 ;
                    map[i][column + j].color = "Magenta" ;
                    map[i][column + j].character = "[*]" ;
                } 
            }
        }
        else
        {
            Invalid_position = true ;
        }
        } while (Invalid_position);
        break;
    }
}

void display( vector <vector<Map_Components>> map , int map_size )
{
    system("cls");  // This function clears the console
    for (size_t i = 0; i < map_size; i++)
    {
        for (size_t j = 0; j < map_size; j++)
        {
            if (map[i][j].color == "Bright_Green")  // In the following conditions, the color for printing the map components is specified and they are displayed in the console
            {
                cout << Bright_Green << map[i][j].character << Reset ;
            }
            else if (map[i][j].color == "Bright_Cyan")
            {
                cout << Bright_Cyan << map[i][j].character << Reset ;
            }
            else if (map[i][j].color == "Bright_Blue")
            {
                cout << Bright_Blue << map[i][j].character << Reset ;
            }
            else if (map[i][j].color == "Blue")
            {
                cout << Blue << map[i][j].character << Reset ;
            }
            else if (map[i][j].color == "Magenta")
            {
                cout << Magenta << map[i][j].character << Reset ;
            }
            else if (map[i][j].color == "Bright_Red")
            {
                cout << Bright_Red << map[i][j].character << Reset ;
            }
            else
            {
                cout << White << map[i][j].character << Reset ;
            }
        }
        cout << endl;
    }
}