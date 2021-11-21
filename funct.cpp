#include <iostream>
#include <stdio.h>
#include <math.h>
#include <conio.h>
#include <locale.h>
#include <windows.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

char str1[10];
char str2[10];
COORD coord = { 0,0 };
void gotoxy(int x, int y)
{
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
int count1(char* str1)
{
    char size1 = 0;
    while (*str1 != '\0')
    {
        str1++;
        size1++;
    }
    cout << " Ваше кол-во символов: ";
    return size1;
}
int count2(char* str2)
{
    char size2 = 0;
    while (*str2 != '\0')
    {
        str2++;
        size2++;
    }
    cout << " Ваше кол-во символов: ";
    return size2;
}
void menu() {
    system("cls");
    cout << str1;
    cout << "\n";
    cout << str2;
    cout << "\n";
    cout << "ПОДСЧЕТ СИМВОЛОВ 1 СТРОКИ" << endl;
    cout << "ПОДСЧЕТ СИМВОЛОВ 2 СТРОКИ" << endl;
    cout << "СКЛЕИВАНИЕ СТРОК" << endl;
    cout << "КОПИРОВАНИЕ" << endl;
    cout << "СРАВНИВАНИЕ СТРОК" << endl;
    cout << "РЕДАКТИРОВАТЬ СТРОКУ 1" << endl;
    cout << "РЕДАКТИРОВАТЬ СТРОКУ 2" << endl;

}
void kley(char* str1, char* str2) {
    char size1 = 0;
    size1 = count1(str1);
    system("cls");
    menu();
    char size2 = 0;
    size2 = count2(str2);
    system("cls");
    menu();
    char str3[256];
    for (int i = 0; i < size1; i++) {
        str3[i] = str1[i];
    }

    for (int i = size1; i < size1 + size2; i++) {
        int p = i - size1;
        str3[i] = str2[p];
        str3[size1 + size2] = { '\0' };
       
    }
    gotoxy(30, 4);
    cout << str3;

    }
void cpy(char* str1, char* str2) {
    char size1 = 0;
    size1 = count1(str1);
    system("cls");
    menu();
    char size2 = 0;
    size2 = count2(str2);
    system("cls");
    menu();
    int i = 0;
    for (i; i < size2; i++) {
        str1[i] = str2[i];
        gotoxy(35, 4);
        cout << str1[size2];
    }
}
void cmp(char* str1, char* str2) {
    int i = 0;
    char size1 = 0;
    size1 = count1(str1);
    system("cls");
    menu();
    for (i; i < size1; i++) {
        if (str1[i] != str2[i]) {
            if (str1[i] > str2[i]) {
                gotoxy(30, 6);
                cout << '1';
                break;
            }
            else {
                gotoxy(30, 6);
                cout << "-1";
                break;
            }
        }
        else {
            gotoxy(30, 6);
            cout << "0";

        }
    
        
    }

}
int main()
{   
    bool exit = true;
    int code;
    char vibor=2;
    setlocale(LC_ALL, "Rus");

    int size1,size2;
    

    cout << "Введите 1 строку" << endl;
    cin >> str1;
    cout << "Введите 2 строку" << endl;
    cin >> str2;
    system("cls");
    cout << "\n";
    while (exit) {
        menu();
        gotoxy(28, vibor);
        printf("<==");
        code = _getch();
        if (code == 224)
            code = _getch();
        switch (code) {
        case 72:vibor--;
            break;
        case 80:vibor++;
            break;
        case 13:
            if (vibor == 2) {
                size1=count1(str1);
                cout << size1;
                code = _getch();
                system("cls");
                break;

            }
            else   
                if (vibor == 7) {
                    cout << " Введите новую строку: ";
                    cin >> str1;
             }
                else
                    if (vibor == 8) {
                        cout << " Введите новую строку: ";
                        cin >> str2;
        
                    }
                    else
                        if (vibor == 3) {
                            size2 = count2(str2);
                            cout << size2;
                            code = _getch();
                            system("cls");
                            break;
                        }
                        else
                            if (vibor == 5) {
                                cpy(str1, str2);
                                break;
                            }
                            else
                                if (vibor == 6) {
                                    cmp(str1, str2);
                                    code = _getch();
                                    system("cls");
                                    break;
                                }
                                else
                                    if (vibor == 4){
                                        kley(str1, str2);
                                        code = _getch();
                                        system("cls");
                                        break;
                                    }
           
        }
        if (vibor < 2)
            vibor = 8;

        if (vibor > 8)
            vibor = 2;

    }
   

    return 0;
}
