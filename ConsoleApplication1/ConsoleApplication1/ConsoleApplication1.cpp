// Maze.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <Windows.h>

using namespace std;

void gotoxy(int x, int y)
{
    COORD p = { x, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), p);
}

vector<string> loadMazeFiles() {
    vector<string>wholeMap;
    ifstream mazeFile("maze1.txt");

    while (!mazeFile.eof()) {
        string currLine;
        getline(mazeFile, currLine);
        wholeMap.push_back(currLine);
    }

    mazeFile.close();

    return wholeMap;
}

void stringToCord(bool& refIsX, string currCord, vector<string>& wholeMap, string toChar) {
    refIsX = true;
    string xCord, yCord, currLet;
    int column, line;
    for (int a = 0; a <= currCord.size() - 1; a++)
    {
        currLet = currCord.at(a);
        if (currLet != "," && refIsX == true) {
            xCord = xCord + currLet;
        }
        else if (currLet != "," && refIsX == false) {
            yCord = yCord + currLet;
        }
        else if (currLet == ",") {
            refIsX = false;
        }
    }
    column = stoi(xCord);
    line = stoi(yCord);
    wholeMap[line].replace(column, 1, toChar);
}

int mazeSolver(vector<string>& visited, vector<string> wholeMap, map<string, string>& previous, int line, int column, string& moneyCor) {

    string nextCor, nextPos, currCor = to_string(column) + "," + to_string(line);
    int placeHoldLine = line, placeHoldColumn = column;
    bool ifVisited;

    for (size_t i = 0; i < 4; i++)
    {
        if (moneyCor != "Not Found")
        {
            return 0;
        }
        ifVisited = false;
        column = placeHoldColumn;
        line = placeHoldLine;
        if (i == 0)
            column += 1;
        else if (i == 1)
            line += 1;
        else if (i == 2)
            column -= 1;
        else if (i == 3)
            line -= 1;

        nextCor = to_string(column) + "," + to_string(line);
        nextPos = wholeMap[line].at(column);

        for (size_t i = 0; i < visited.size(); i++)
        {
            if (nextCor == visited[i]) {
                ifVisited = true;
            }
        }

        if (ifVisited != true) {
            visited.push_back(nextCor);
            if (nextPos == "$") {
                moneyCor = to_string(column) + "," + to_string(line);
            }
            if (nextPos != "X") {
                previous[nextCor] = currCor;
                mazeSolver(visited, wholeMap, previous, line, column, moneyCor);
            }
        }
    }
    return 0;
}

void displayRoute(map<string, string> previous, string moneyCor, vector<string> wholeMap) {
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);



    bool isX = true;
    string prevCord = previous[moneyCor], null;
    vector<string> cords;
    cords.push_back(moneyCor);
    cords.push_back(prevCord);
    while (prevCord != "1,1") {
        prevCord = previous[prevCord];
        cords.push_back(prevCord);
    }

    cout << "\n";
    for (size_t i = 0; i < wholeMap.size(); i++)
    {
        cout << wholeMap[i] << endl;
    }

    cout << "Enter any key to show solution: ";
    getline(cin, null);

    system("CLS");


    for (int i = cords.size() - 1; i > 0; i--)
    {
        stringToCord(isX, cords[i], wholeMap, "*");

        //system("CLS");
        gotoxy(0, 0);
        for (size_t i = 0; i < wholeMap.size(); i++)
        {
            for (size_t l = 0; l < wholeMap[0].size(); l++)
            {
                char x = wholeMap[i][l];
                if (x == '*')
                {
                    SetConsoleTextAttribute(hConsole, 12);
                    cout << x;
                    SetConsoleTextAttribute(hConsole, 15);
                }
                else
                    cout << x;
            }
            cout << flush << endl;
        }
        Sleep(5);
    }


    /*
    for (int i = cords.size() -1; i > 0; i--)
    {
        stringToCord(isX, cords[i], wholeMap, "*");

        //system("CLS");
        gotoxy(0, 0);
        for (size_t i = 0; i < wholeMap.size(); i++)
        {
            cout << wholeMap[i] << flush << endl;
        }
        Sleep(75);
    }
    */

}

void displayCords(map<string, string> previous, string moneyCor) {
    vector<string> cords;
    cords.push_back(moneyCor);
    string prevCord = previous[moneyCor];
    cords.push_back(prevCord);
    while (prevCord != "1,1") {
        prevCord = previous[prevCord];
        cords.push_back(prevCord);
    }

    cout << "\n";
    for (size_t i = cords.size(); i > 0; i--)
    {
        cout << cords[i - 1] << endl;
    }
}

void generateMaze(vector <string>& visited, vector <string> wholeMap, int row, int column, string& moneyCor) {

    string nextCor, nextPos, currCor = to_string(column) + "," + to_string(row);
    int placeHoldLine = row, placeHoldColumn = column;
    map<int, bool>ifChecked;

    ifChecked[0] = false;
    ifChecked[1] = false;
    ifChecked[2] = false;
    ifChecked[3] = false;

    for (size_t i = 0; i < 4; i++)
    {
        bool ifVisited = false;
        column = placeHoldColumn;
        row = placeHoldLine;

        bool isChecked = true;
        int a;

        do {
            a = rand() % 10;
            if (a == 0) {
                isChecked = ifChecked[0];
            }
            else if (a == 1) {
                isChecked = ifChecked[1];
            }
            else if (a == 2) {
                isChecked = ifChecked[2];
            }
            else if (a == 3) {
                isChecked = ifChecked[3];
            }
            else if (a == 4) {
                isChecked = ifChecked[0];
            }
            else if (a == 5) {
                isChecked = ifChecked[0];
            }
            else if (a == 6) {
                isChecked = ifChecked[0];
            }
            else if (a == 7) {
                isChecked = ifChecked[1];
            }
            else if (a == 8) {
                isChecked = ifChecked[0];
            }
            else if (a == 9) {
                isChecked = ifChecked[1];
            }

        } while (isChecked == true);

        if (a == 0) {
            column += 1;
            ifChecked[0] = true;
        }
        else if (a == 1) {
            row += 1;
            ifChecked[1] = true;
        }
        else if (a == 2) {
            column -= 1;
            ifChecked[2] = true;
        }
        else if (a == 3) {
            row -= 1;
            ifChecked[3] = true;
        }
        else if (a == 4) {
            column += 1;
            ifChecked[0] = true;
        }
        else if (a == 5) {
            column += 1;
            ifChecked[0] = true;
        }
        else if (a == 6) {
            column += 1;
            ifChecked[0] = true;
        }
        else if (a == 7) {
            row += 1;
            ifChecked[1] = true;
        }
        else if (a == 8) {
            column += 1;
            ifChecked[0] = true;
        }
        else if (a == 9) {
            row += 1;
            ifChecked[1] = true;
        }

        nextCor = to_string(column) + "," + to_string(row);
        nextPos = wholeMap[row].at(column);

        for (size_t i = 0; i < visited.size(); i++)
        {
            if (nextCor == visited[i]) {
                ifVisited = true;
            }
        }

        if (ifVisited != true) {
            if (nextPos != "X") {
                bool nextNextVisited = false;
                for (int i = 0; i < 4; i++)
                {
                    int nextColumn = column, nextRow = row;
                    if (i == 0)
                        nextColumn += 1;
                    else if (i == 1)
                        nextRow += 1;
                    else if (i == 2)
                        nextColumn -= 1;
                    else if (i == 3)
                        nextRow -= 1;

                    string nextNextCor = to_string(nextColumn) + "," + to_string(nextRow);
                    string nextNextPos;
                    nextNextPos = wholeMap[nextRow].at(nextColumn);

                    for (size_t a = 0; a < visited.size(); a++)
                    {
                        if (nextNextCor == visited[a] && nextNextCor != currCor) {
                            nextNextVisited = true;
                        }
                    }
                }
                if (nextNextVisited != true) {
                    visited.push_back(nextCor);
                    generateMaze(visited, wholeMap, row, column, moneyCor);
                }
            }
        }
    }
    if (moneyCor == "0,0") {
        moneyCor = currCor;
    }
}

vector<string> generateWholeMaze() {
    string sx, sy;
    cout << "\nEnter X demensions: ";
    getline(cin, sx);
    cout << "Enter Y demensions: ";
    getline(cin, sy);

    int x = stoi(sx), y = stoi(sy);
    srand((unsigned)time(0));

    vector <string> wholeMap;
    vector <string> visited;
    string moneyCor = "0,0";
    visited.push_back("1,1");

    string firstLastRow = "X";
    string midRow = "X";

    for (size_t i = 0; i < x + 1; i++)
    {
        firstLastRow += "X";
    }
    for (size_t i = 0; i < x; i++)
    {
        midRow += " ";
    }
    midRow += "X";

    wholeMap.push_back(firstLastRow);

    for (size_t i = 0; i < y; i++)
    {
        wholeMap.push_back(midRow);
    }

    wholeMap.push_back(firstLastRow);

    generateMaze(visited, wholeMap, 1, 1, moneyCor);

    wholeMap.clear();

    for (size_t i = 0; i < (y + 2); i++)
    {
        wholeMap.push_back(firstLastRow);
    }

    bool isX = true;

    for (int i = visited.size() - 1; i >= 0; i--)
    {
        stringToCord(isX, visited[i], wholeMap, " ");
    }

    stringToCord(isX, moneyCor, wholeMap, "$");
    return wholeMap;
}

void allMaze(bool randomMaze) {
    int line = 1, column = 1;
    string nextPos, moneyCor = "Not Found";
    map<string, string>previous;
    vector<string> wholeMap;
    vector<string> visited;
    visited.push_back("1,1");

    if (randomMaze == false) {
        string mazeNum;
        cout << "\nPick the maze that you want to solve: ";
        getline(cin, mazeNum);
        wholeMap = loadMazeFiles();
    }
    else if (randomMaze == true) {
        wholeMap = generateWholeMaze();
    }

    mazeSolver(visited, wholeMap, previous, line, column, moneyCor);

    if (moneyCor != "Not Found") {
        displayRoute(previous, moneyCor, wholeMap);
    }
    else {
        cout << "Money Cannot be reached :(";
    }

    displayCords(previous, moneyCor);
}

int main()
{
    bool again = true;
    cout << "Welcome to Maze Generator/Solver" << endl;

    do {
        string userIn;
        bool randomMaze = true, isNum = false;
        do {
            cout << "\nEnter 1 to generate Pre-generated Maze" << endl << "Enter 2 to solve a Random Maze" << endl << "\nEnter your decision: ";
            getline(cin, userIn);

            if (userIn == "1") {
                isNum = true;
                allMaze(false);
            }
            else if (userIn == "2") {
                isNum = true;
                allMaze(true);
            }
            else {
                cout << "\nINVALID NUMBER!" << endl << "Please enter the number 1 or 2" << endl;
            }
        } while (isNum == false);

        cout << "Would you like to try again? ";
        getline(cin, userIn);

        if (userIn != "Y" && userIn != "y" && userIn != "Yes" && userIn != "yes") {
            again = false;
        }
    } while (again == true);
}


