#include "Snail.h"
#include <windows.h>
#include <iostream> 
using namespace std;

int** snail;
int snailSize;
int currntNum = 0;
int x = 0;
int y = 0;
int currentDir = Right;

bool Moveable() {
    switch (currentDir)
    {
    case Right: return y < snailSize - 1 && snail[x][y + 1] == -1;
    case Down: return x < snailSize - 1 && snail[x + 1][y] == -1;
    case Left: return y > 0 && snail[x][y - 1] == -1;
    case Up: return x > 0 && snail[x - 1][y] == -1;
    }
    return false;
}

void Dot() {
    snail[x][y] = currntNum;
    currntNum++;
}

void SetupSnail() {
    cin >> snailSize;
    snail = new int* [snailSize];

    for (size_t i = 0; i < snailSize; i++)
    {
        snail[i] = new int[snailSize];
    }

    for (size_t i = 0; i < snailSize; i++)
    {
        for (size_t j = 0; j < snailSize; j++)
        {
            snail[i][j] = -1;
        }
    }
}

void PrintSnail() {
    system("cls");
    for (size_t i = 0; i < snailSize; i++)
    {
        for (size_t j = 0; j < snailSize; j++)
        {
            if (snail[i][j] == -1) {
                cout << "    ";
                continue;
            }

            const char* margin = (snail[i][j] < 10) ? "0" : "";
            cout << margin << snail[i][j] << "  ";
        }
        cout << endl;
    }
}

void Turn() {
    currentDir = (currentDir + 1) % 4;
}

int dy[] = { 1, 0, -1, 0 };
int dx[] = { 0, 1, 0, -1 };
void Crawl() {
    y += dy[currentDir];
    x += dx[currentDir];
    Dot();
}

void Snail() {
    SetupSnail();
    Dot();
    while (true)
    {
        if (currntNum > snailSize * snailSize - 1) break;

        if (Moveable() == false) Turn();

        Crawl();
        Sleep(10);
        PrintSnail();
    }

    PrintSnail();
}