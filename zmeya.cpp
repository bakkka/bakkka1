#include <iostream>
#include <stdio.h>
#include <math.h>
#include <conio.h>
#include <locale.h>
#include <windows.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

COORD coord = { 0,0 };
void gotoxy(int x, int y)
{
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}






int main() {
    int x=0, y;
    char a;
    int entered_num1 = 0, entered_num2 = 0;
    bool exit = true;
    cout << "enter the dimensions of the field" << endl;
    cout << "\nwidth: ";
    do{
    
    a = _getch();
    if (a >= 48 && a <= 57) {
        x = a - 48;
        cout << x;
        x *= 10;
        x += a - 48;
    }
    else if (a == 8) {
        x /= 10;
        printf("\b \b");
    }
    } while (a != 13);
    if (x != 0)return x;

    while (x > 11) {
        system("cls");
        cout << "enter the dimensions of the field" << endl;
        cout << "\nwidth: ";
        cin >> x;
    }
    cout << "\n";
    cout << "height: ";
    cin >> y;
    while (y > 11) {
        system("cls");
        cout << "enter the dimensions of the field" << endl;
        cout << "\nwidth: "<<x;
        cout << "\n\nheight: ";
        cin >> y;
    }



}
