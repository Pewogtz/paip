#include <iostream>
#include <conio.h>
#include <windows.h>
#include <thread>

using namespace std;

int timer = 0;
int mapWidth = 30;
int mapHeight = 20;

void timerF()
{
    COORD t;
    t.X = 21;
    t.Y = 21;
    while(1)
    {
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), t);
        cout<<timer;
        Sleep(1000);
        timer++;

    }

}

void drawMap()
{
    while(1)
    {
        system("cls");
        for (int y = 1; y <= mapHeight; y++)
        {
            if (y == 1 || y == mapHeight)
            {
                for (int x = 1; x <= mapHeight; x++)
                {
                    cout<<"X";
                }
            }
            else
                for (int x = 1; x <= mapWidth; x++)
                {
                    if (x == 1 || x == mapWidth)
                    {
                        cout<<"X";
                    }
                    else
                        cout<<" ";

                }

            cout<<endl;
        }
    }
}

void start()
{
    std::thread threadTimer(timerF);
    drawMap();

}

void options()
{
    cout<<"Not implemented yet! Be patient!"<<endl;
}

void menu()
{
    cout<<"\n\t\t\tStart"<<endl;
    cout<<"\t\t\tOptions"<<endl;
    cout<<"\t\t\tExit"<<endl;

    int key;
    COORD menu;
    menu.X = 21;
    menu.Y = 1;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), menu);
    cout<<">";
    while(key != 13)
    {
        key = _getch();
        switch(key)
        {
        case 119:

            if (menu.Y > 1)
            {
                cout<<"\b \b";
                menu.Y--;
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), menu);
                cout<<">";
            }
            break;
        case 115:

            if (menu.Y < 3)
            {
                cout<<"\b \b";
                menu.Y++;
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), menu);
                cout<<">";
            }
            break;
        default:
            break;
        }

    }
    switch(menu.Y)
    {
    case 1:
        system("cls");
        start();
        break;
    case 2:
        system("cls");
        options();
        break;
    case 3:
        exit(1);
    }

}



int main()
{

    menu();

}
