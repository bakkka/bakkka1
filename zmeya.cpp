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
int vvodx() {
    int xc=0;
    int t;
    char a;
    bool exit = true;
    cout << "\nwidth: ";
        do {

            a = _getch();
            if (a >= 48 && a <= 57) {
                t = a - 48;
                cout<<t;
                xc=xc*10+t;
            }
            else if (a == 8) {
                xc /= 10;
                printf("\b \b");
            }
        } while (a != 13);
        if (xc != 0)return xc;
    
}
int vvody() {
    int yc = 0;
    int g;
    char b;
    bool exit = true;
    cout << "\nheight: ";
   
        do {
            b = _getch();
            if (b >= 48 && b <= 57) {
                g = b - 48;
                cout << g;
                yc = yc * 10 + g;
            }
            else if (b == 8) {
                yc /= 10;
                printf("\b \b");
            }
        } while (b != 13);
        if (yc != 0)return yc;
    
}
void pole(int yc, int xc)
{
    system("cls");
    cout << "width: " << xc;
    cout << "\n";
    cout << "height: " << yc;
    cout << "\n";
    
    for (int i = 0; i < yc; i++) {
        for (int j = 0; j < xc; j++) {
            if (i != 0 && i != (yc - 1) && j != 0 && j != (xc - 1)) {
                
                cout << " ";
            }
            else {
                char xxx=(219);
                cout <<xxx ;
            }
        }
        cout << endl;
    }
    cout << "\n\n";
}


int main() {
    ShowCursor(FALSE);
    start:
    char koordwall[40][40];
    for (int i = 0; i < 40; i++) {
        for (int b = 0; b < 40; b++) {
            koordwall [i] [b] = char(32);
        }
    }
    char presentX[40];
    for (int b = 0; b < 40; b++) {
        presentX[b] = char(32);
    }
    char presentY[40];
    for (int b = 0; b < 40; b++) {
        presentY[b] = char(32);
    }
    char pastX[40];
    for (int b = 0; b < 40; b++) {
        pastX[b] = char(32);
    }
    char pastY[40];
    for (int b = 0; b < 40; b++) {
        pastY[b] = char(32);
    }

    bool exit = true;
    int xc;
    int vibor_y = 3;
    int vibor_x = 1;
    int yc;
    char q;
    cout << "enter the dimensions of the field" << endl;
    xc = vvodx();
    while (xc<=6) {
        cout << "\nretry again, width should be from 20 to 40";
        xc = vvodx();
    }
    while (xc >= 40) {
        cout << "\nretry again, width should be from 20 to 40";
        xc = vvodx();
    }


    yc = vvody();
    while (yc <= 6) {
        cout << "\nretry again, height should be from 20 to 40";
        yc = vvody();
    }
    while (yc >= 30) {
        cout << "\nretry again, height should be from 20 to 40";
        yc = vvody();
    }

    cout << "\n";
    pole(yc, xc);
    int random1, random2, random3, random4, random5, random6, random7, random8,random9,random10;
    int kolvo1 = xc - 2;
    int kolvo2 = yc - 2;
    int stena1, stena2;
    char yabloko(253);
    srand(time(NULL));
    gotoxy(0, yc + 3);
    cout << "PRESS ENTER TO PUT APPLES AND START THE GAME";
    q = _getch();
    random1 = rand() % kolvo1 + 1;
    random2 = rand() % kolvo2 + 3;
    gotoxy(random1, random2);
    cout << yabloko;
    random3 = rand() % kolvo1 + 1;
    random4 = rand() % kolvo2 + 3;
    gotoxy(random3, random4);
    cout << yabloko;
    random5 = rand() % kolvo1 + 1;
    random6 = rand() % kolvo2 + 3;
    gotoxy(random5, random6);
    cout << yabloko;
    random7 = rand() % kolvo1 + 1;
    random8 = rand() % kolvo2 + 3;
    gotoxy(random7, random8);
    cout << yabloko;
    if (((random1 == 1) && (random2 == 3)) || ((random3 == 1) && (random4 == 3)) || ((random5 == 1) && (random6 == 3))) {
        if ((random1 == 1) && (random2 == 3)) {
            random1 = rand() % kolvo1 + 1;
            random2 = rand() % kolvo2 + 3;
            gotoxy(random1, random2);
            cout << yabloko;
        }
        else
            if ((random3 == 1) && (random4 == 3)) {
                random3 = rand() % kolvo1 + 1;
                random4 = rand() % kolvo2 + 3;
                gotoxy(random3, random4);
                cout << yabloko;
            }
            else
                if ((random5 == 1) && (random6 == 3)) {
                    random5 = rand() % kolvo1 + 1;
                    random6 = rand() % kolvo2 + 3;
                    gotoxy(random5, random6);
                    cout << yabloko;
                }
    }
    if  ((random7 == 1) && (random8 == 3)) {
        
            random7 = rand() % kolvo1 + 1;
            random8 = rand() % kolvo2 + 3;
            gotoxy(random7, random8);
            cout << yabloko;
       }
    if (((random1 == random3) && (random2 == random4)) || ((random1 == random5) && (random2 == random6)) || ((random1 == random7) && (random2 == random8))) {
        if ((random1 == random3) && (random2 == random4)) {
            random1 = rand() % kolvo1 + 1;
            random2 = rand() % kolvo2 + 3;
            gotoxy(random1, random2);
            cout << yabloko;
        }
        else
            if ((random1 == random5) && (random2 == random6)) {
                random1 = rand() % kolvo1 + 1;
                random2 = rand() % kolvo2 + 3;
                gotoxy(random1, random2);
                cout << yabloko;
            }
            else
                if ((random1 == random7) && (random2 == random8)) {
                    random1 = rand() % kolvo1 + 1;
                    random2 = rand() % kolvo2 + 3;
                    gotoxy(random1, random2);
                    cout << yabloko;
                }
    }
    if (((random3 == random5) && (random4 == random6)) || ((random3 == random7) && (random4 == random8)) || ((random5 == random7) && (random6 == random8))) {
        if ((random3 == random5) && (random4 == random6)) {
            random3 = rand() % kolvo1 + 1;
            random4 = rand() % kolvo2 + 3;
            gotoxy(random3, random4);
            cout << yabloko;
        }
        else
            if ((random3 == random7) && (random4 == random8)) {
                random1 = rand() % kolvo1 + 1;
                random2 = rand() % kolvo2 + 3;
                gotoxy(random3, random4);
                cout << yabloko;
            }
            else
                if ((random5 == random7) && (random6 == random8)) {
                    random5 = rand() % kolvo1 + 1;
                    random6 = rand() % kolvo2 + 3;
                    gotoxy(random5, random6);
                    cout << yabloko;
                }
    }
    gotoxy(0, yc + 3);
    cout << "                                                      ";
    gotoxy(xc+2, 3);
    int point = 0;
    int i=0;
    int len;
    len = 1+point;
    cout << "Amount of points: " << point;
    gotoxy(xc + 2, 4);
    cout << "EARN 15 POINTS TO WIN";
    gotoxy(xc + 2, 5);
    cout << "Press Enter to put a wall";
        
    int predy1;
    int predx1;
    int predx;
    int predy;
    while (exit) {
        gotoxy(vibor_x, vibor_y);
        char b = (176);
        cout << b;
       
        int k = len;
        for (int k = len; k != 0; k--)
        {
            pastX[k + 1] = pastX[k];
            pastY[k + 1] = pastY[k];
            pastX[k] = vibor_x;
            pastY[k] = vibor_y;
        }
        q = _getch();
        if (q == 224)
            q = _getch();
        switch (q) {
        case 72:vibor_y--;
            if (koordwall[vibor_y][vibor_x] == '#') {
                system("cls");
                gotoxy(50, 15);
                cout << "GAME OVER";
                gotoxy(1, 20);
                cout << "press Enter to play again";
                int a = _getch();
                if (a == 13) {
                    system("cls");
                    goto start;
                }

            }
            presentX[0] = vibor_x;
            presentY[0] = vibor_y;
            gotoxy(presentX[0], presentY[0]);
            cout << b;
            predy1 = (vibor_y + 1);
            int predy3;
            predy3 = (predy1 + point);
            gotoxy(vibor_x, predy1);
            cout << " ";

            if (((vibor_x == random1) && (vibor_y == random2)) || ((vibor_x == random3) && (vibor_y == random4)) ||
                ((vibor_x == random5) && (vibor_y == random6)) || ((vibor_x == random7) && (vibor_y == random8))) {
                point += 1;
                len += 1;
                if ((vibor_x == random1) && (vibor_y == random2)) {
                    random1 = rand() % kolvo1 + 1;
                    random2 = rand() % kolvo2 + 3;
                    gotoxy(random1, random2);
                    cout << yabloko;
                }
                else
                    if ((vibor_x == random3) && (vibor_y == random4)) {
                        random3 = rand() % kolvo1 + 1;
                        random4 = rand() % kolvo2 + 3;
                        gotoxy(random3, random4);
                        cout << yabloko;
                    }
                    else
                        if ((vibor_x == random5) && (vibor_y == random6)) {
                            random5 = rand() % kolvo1 + 1;
                            random6 = rand() % kolvo2 + 3;
                            gotoxy(random5, random6);
                            cout << yabloko;
                        }
                        else
                            if ((vibor_x == random7) && (vibor_y == random8)) {
                                random7 = rand() % kolvo1 + 1;
                                random8 = rand() % kolvo2 + 3;
                                gotoxy(random7, random8);
                                cout << yabloko;
                            }
                gotoxy(xc + 2, 3);
                cout << "Amount of points: " << point;
               
            }
            if (((random1 == random3) && (random2 == random4)) || ((random1 == random5) && (random2 == random6)) || ((random1 == random7) && (random2 == random8))) {
                if ((random1 == random3) && (random2 == random4)) {
                    random1 = rand() % kolvo1 + 1;
                    random2 = rand() % kolvo2 + 3;
                    gotoxy(random1, random2);
                    cout << yabloko;
                }
                else
                    if ((random1 == random5) && (random2 == random6)) {
                        random1 = rand() % kolvo1 + 1;
                        random2 = rand() % kolvo2 + 3;
                        gotoxy(random1, random2);
                        cout << yabloko;
                    }
                    else
                        if ((random1 == random7) && (random2 == random8)) {
                            random1 = rand() % kolvo1 + 1;
                            random2 = rand() % kolvo2 + 3;
                            gotoxy(random1, random2);
                            cout << yabloko;
                        }
            }
            if (((random3 == random5) && (random4 == random6)) || ((random3 == random7) && (random4 == random8)) || ((random5 == random7) && (random6 == random8))) {
                if ((random3 == random5) && (random4 == random6)) {
                    random3 = rand() % kolvo1 + 1;
                    random4 = rand() % kolvo2 + 3;
                    gotoxy(random3, random4);
                    cout << yabloko;
                }
                else
                    if ((random3 == random7) && (random4 == random8)) {
                        random1 = rand() % kolvo1 + 1;
                        random2 = rand() % kolvo2 + 3;
                        gotoxy(random3, random4);
                        cout << yabloko;
                    }
                    else
                        if ((random5 == random7) && (random6 == random8)) {
                            random5 = rand() % kolvo1 + 1;
                            random6 = rand() % kolvo2 + 3;
                            gotoxy(random5, random6);
                            cout << yabloko;
                        }
            }
            if (vibor_y == 2) {
                system("cls");
                gotoxy(50, 15);
                cout << "GAME OVER";
                gotoxy(1, 20);
                cout << "press Enter to play again";
                int a = _getch();
                if (a == 13) {
                    system("cls");
                    goto start;
                }
                
            }
            for (int k = len; k != 0; k--)
            {
                if (((random1 == pastX[k]) && (random2== pastY[k])) || ((random3 == pastX[k]) && (random4 == pastY[k])) ||
                    ((random5 == pastX[k]) && (random6 == pastY[k])) || ((random7 == pastX[k]) && (random8 == pastY[k]))) {
                    if ((random1 == pastX[k]) && (random2 == pastY[k])) {
                        random1 = rand() % kolvo1 + 1;
                        random2 = rand() % kolvo2 + 3;
                        gotoxy(random1, random2);
                        cout << yabloko;
                    }
                    else
                        if ((random3 == pastX[k]) && (random4 == pastY[k])) {
                            random3 = rand() % kolvo1 + 1;
                            random4 = rand() % kolvo2 + 3;
                            gotoxy(random3, random4);
                            cout << yabloko;
                        }
                        else
                            if ((random5 == pastX[k]) && (random6 == pastY[k])) {
                                random5 = rand() % kolvo1 + 1;
                                random6 = rand() % kolvo2 + 3;
                                gotoxy(random5, random6);
                                cout << yabloko;
                            }
                            else
                                if ((random7 == pastX[k]) && (random8 == pastY[k])) {
                                    random7 = rand() % kolvo1 + 1;
                                    random8 = rand() % kolvo2 + 3;
                                    gotoxy(random7, random8);
                                    cout << yabloko;
                                }

                }
            }
            
        
            break;
        case 80:vibor_y++;
            if (koordwall[vibor_y][vibor_x] == '#') {
                system("cls");
                gotoxy(50, 15);
                cout << "GAME OVER";
                gotoxy(1, 20);
                cout << "press Enter to play again";
                int a = _getch();
                if (a == 13) {
                    system("cls");
                    goto start;
                }

            }
            presentX[0] = vibor_x;
            presentY[0] = vibor_y;
            gotoxy(presentX[0], presentY[0]);
            cout << b;
            int predy2;
            predy2 = (vibor_y - 1);

            gotoxy(vibor_x, predy2);
            cout << " ";
            if (((vibor_x == random1) && (vibor_y == random2)) || ((vibor_x == random3) && (vibor_y == random4)) ||
                ((vibor_x == random5) && (vibor_y == random6)) || ((vibor_x == random7) && (vibor_y == random8))) {
                point += 1;
                len += 2;
                if ((vibor_x == random1) && (vibor_y == random2)) {
                    random1 = rand() % kolvo1 + 1;
                    random2 = rand() % kolvo2 + 3;
                    gotoxy(random1, random2);
                    cout << yabloko;
                }
                else
                    if ((vibor_x == random3) && (vibor_y == random4)) {
                        random3 = rand() % kolvo1 + 1;
                        random4 = rand() % kolvo2 + 3;
                        gotoxy(random3, random4);
                        cout << yabloko;
                    }
                    else
                        if ((vibor_x == random5) && (vibor_y == random6)) {
                            random5 = rand() % kolvo1 + 1;
                            random6 = rand() % kolvo2 + 3;
                            gotoxy(random5, random6);
                            cout << yabloko;
                        }
                        else
                            if ((vibor_x == random7) && (vibor_y == random8)) {
                                random7 = rand() % kolvo1 + 1;
                                random8 = rand() % kolvo2 + 3;
                                gotoxy(random7, random8);
                                cout << yabloko;
                            }
                gotoxy(xc + 2, 3);
                cout << "Amount of points: " << point;
                
            }
            if (((random1 == random3) && (random2 == random4)) || ((random1 == random5) && (random2 == random6)) || ((random1 == random7) && (random2 == random8))) {
                if ((random1 == random3) && (random2 == random4)) {
                    random1 = rand() % kolvo1 + 1;
                    random2 = rand() % kolvo2 + 3;
                    gotoxy(random1, random2);
                    cout << yabloko;
                }
                else
                    if ((random1 == random5) && (random2 == random6)) {
                        random1 = rand() % kolvo1 + 1;
                        random2 = rand() % kolvo2 + 3;
                        gotoxy(random1, random2);
                        cout << yabloko;
                    }
                    else
                        if ((random1 == random7) && (random2 == random8)) {
                            random1 = rand() % kolvo1 + 1;
                            random2 = rand() % kolvo2 + 3;
                            gotoxy(random1, random2);
                            cout << yabloko;
                        }
            }
            if (((random3 == random5) && (random4 == random6)) || ((random3 == random7) && (random4 == random8)) || ((random5 == random7) && (random6 == random8))) {
                if ((random3 == random5) && (random4 == random6)) {
                    random3 = rand() % kolvo1 + 1;
                    random4 = rand() % kolvo2 + 3;
                    gotoxy(random3, random4);
                    cout << yabloko;
                }
                else
                    if ((random3 == random7) && (random4 == random8)) {
                        random1 = rand() % kolvo1 + 1;
                        random2 = rand() % kolvo2 + 3;
                        gotoxy(random3, random4);
                        cout << yabloko;
                    }
                    else
                        if ((random5 == random7) && (random6 == random8)) {
                            random5 = rand() % kolvo1 + 1;
                            random6 = rand() % kolvo2 + 3;
                            gotoxy(random5, random6);
                            cout << yabloko;
                        }
            }
            if (vibor_y == (yc + 1)) {
                system("cls");
                gotoxy(50, 15);
                cout << "GAME OVER";
                gotoxy(1, 20);
                cout << "press Enter to play again";
                int a = _getch();
                if (a == 13) {
                    system("cls");
                    goto start;
                }

            }
            for (int k = len; k != 0; k--)
            {
                if (((random1 == pastX[k]) && (random2 == pastY[k])) || ((random3 == pastX[k]) && (random4 == pastY[k])) ||
                    ((random5 == pastX[k]) && (random6 == pastY[k])) || ((random7 == pastX[k]) && (random8 == pastY[k]))) {
                    if ((random1 == pastX[k]) && (random2 == pastY[k])) {
                        random1 = rand() % kolvo1 + 1;
                        random2 = rand() % kolvo2 + 3;
                        gotoxy(random1, random2);
                        cout << yabloko;
                    }
                    else
                        if ((random3 == pastX[k]) && (random4 == pastY[k])) {
                            random3 = rand() % kolvo1 + 1;
                            random4 = rand() % kolvo2 + 3;
                            gotoxy(random3, random4);
                            cout << yabloko;
                        }
                        else
                            if ((random5 == pastX[k]) && (random6 == pastY[k])) {
                                random5 = rand() % kolvo1 + 1;
                                random6 = rand() % kolvo2 + 3;
                                gotoxy(random5, random6);
                                cout << yabloko;
                            }
                            else
                                if ((random7 == pastX[k]) && (random8 == pastY[k])) {
                                    random7 = rand() % kolvo1 + 1;
                                    random8 = rand() % kolvo2 + 3;
                                    gotoxy(random7, random8);
                                    cout << yabloko;
                                }

                }
            }
            break;

        case 75:vibor_x--;
            if (koordwall[vibor_y][vibor_x] == '#') {
                system("cls");
                gotoxy(50, 15);
                cout << "GAME OVER";
                gotoxy(1, 20);
                cout << "press Enter to play again";
                int a = _getch();
                if (a == 13) {
                    system("cls");
                    goto start;
                }

            }
            presentX[0] = vibor_x;
            presentY[0] = vibor_y;
            gotoxy(presentX[0], presentY[0]);
            cout << b;
            int predx1;
            predx1 = (vibor_x + 1);

            gotoxy(predx1, vibor_y);
            cout << " ";
            if (((vibor_x == random1) && (vibor_y == random2)) || ((vibor_x == random3) && (vibor_y == random4)) ||
                ((vibor_x == random5) && (vibor_y == random6)) || ((vibor_x == random7) && (vibor_y == random8))) {
                point += 1;
                len += 2;
                if ((vibor_x == random1) && (vibor_y == random2)) {
                    random1 = rand() % kolvo1 + 1;
                    random2 = rand() % kolvo2 + 3;
                    gotoxy(random1, random2);
                    cout << yabloko;
                }
                else
                    if ((vibor_x == random3) && (vibor_y == random4)) {
                        random3 = rand() % kolvo1 + 1;
                        random4 = rand() % kolvo2 + 3;
                        gotoxy(random3, random4);
                        cout << yabloko;
                    }
                    else
                        if ((vibor_x == random5) && (vibor_y == random6)) {
                            random5 = rand() % kolvo1 + 1;
                            random6 = rand() % kolvo2 + 3;
                            gotoxy(random5, random6);
                            cout << yabloko;
                        }
                        else
                            if ((vibor_x == random7) && (vibor_y == random8)) {
                                random7 = rand() % kolvo1 + 1;
                                random8 = rand() % kolvo2 + 3;
                                gotoxy(random7, random8);
                                cout << yabloko;
                            }

                gotoxy(xc + 2, 3);
                cout << "Amount of points: " << point;
                

            }
            if (((random1 == random3) && (random2 == random4)) || ((random1 == random5) && (random2 == random6)) || ((random1 == random7) && (random2 == random8))) {
                if ((random1 == random3) && (random2 == random4)) {
                    random1 = rand() % kolvo1 + 1;
                    random2 = rand() % kolvo2 + 3;
                    gotoxy(random1, random2);
                    cout << yabloko;
                }
                else
                    if ((random1 == random5) && (random2 == random6)) {
                        random1 = rand() % kolvo1 + 1;
                        random2 = rand() % kolvo2 + 3;
                        gotoxy(random1, random2);
                        cout << yabloko;
                    }
                    else
                        if ((random1 == random7) && (random2 == random8)) {
                            random1 = rand() % kolvo1 + 1;
                            random2 = rand() % kolvo2 + 3;
                            gotoxy(random1, random2);
                            cout << yabloko;
                        }
            }
            if (((random3 == random5) && (random4 == random6)) || ((random3 == random7) && (random4 == random8)) || ((random5 == random7) && (random6 == random8))) {
                if ((random3 == random5) && (random4 == random6)) {
                    random3 = rand() % kolvo1 + 1;
                    random4 = rand() % kolvo2 + 3;
                    gotoxy(random3, random4);
                    cout << yabloko;
                }
                else
                    if ((random3 == random7) && (random4 == random8)) {
                        random1 = rand() % kolvo1 + 1;
                        random2 = rand() % kolvo2 + 3;
                        gotoxy(random3, random4);
                        cout << yabloko;
                    }
                    else
                        if ((random5 == random7) && (random6 == random8)) {
                            random5 = rand() % kolvo1 + 1;
                            random6 = rand() % kolvo2 + 3;
                            gotoxy(random5, random6);
                            cout << yabloko;
                        }
            }
            if (vibor_x == 0) {
                system("cls");
                gotoxy(50, 15);
                cout << "GAME OVER";
                gotoxy(1, 20);
                cout << "press Enter to play again";
                int a = _getch();
                if (a == 13) {
                    system("cls");
                    goto start;
                }
            }
            for (int k = len; k != 0; k--)
            {
                if (((random1 == pastX[k]) && (random2 == pastY[k])) || ((random3 == pastX[k]) && (random4 == pastY[k])) ||
                    ((random5 == pastX[k]) && (random6 == pastY[k])) || ((random7 == pastX[k]) && (random8 == pastY[k]))) {
                    if ((random1 == pastX[k]) && (random2 == pastY[k])) {
                        random1 = rand() % kolvo1 + 1;
                        random2 = rand() % kolvo2 + 3;
                        gotoxy(random1, random2);
                        cout << yabloko;
                    }
                    else
                        if ((random3 == pastX[k]) && (random4 == pastY[k])) {
                            random3 = rand() % kolvo1 + 1;
                            random4 = rand() % kolvo2 + 3;
                            gotoxy(random3, random4);
                            cout << yabloko;
                        }
                        else
                            if ((random5 == pastX[k]) && (random6 == pastY[k])) {
                                random5 = rand() % kolvo1 + 1;
                                random6 = rand() % kolvo2 + 3;
                                gotoxy(random5, random6);
                                cout << yabloko;
                            }
                            else
                                if ((random7 == pastX[k]) && (random8 == pastY[k])) {
                                    random7 = rand() % kolvo1 + 1;
                                    random8 = rand() % kolvo2 + 3;
                                    gotoxy(random7, random8);
                                    cout << yabloko;
                                }

                }
            }
            
            for (int k = len; k != 0; k--)
            {
                if (((pastX[k] == random1) && (pastY[k] == random2)) || ((pastX[k] == random3) && (pastY[k] == random4)) ||
                    ((pastX[k] == random5) && (pastY[k] == random6)) || ((pastX[k] == random7) && (pastY[k] == random8))) {
                    if ((pastX[k] == random1) && (pastY[k] == random2)) {
                        random1 = rand() % kolvo1 + 1;
                        random2 = rand() % kolvo2 + 3;
                        gotoxy(random1, random2);
                        cout << yabloko;
                    }
                    else
                        if ((pastX[k] == random3) && (pastY[k] == random4)) {
                            random3 = rand() % kolvo1 + 1;
                            random4 = rand() % kolvo2 + 3;
                            gotoxy(random3, random4);
                            cout << yabloko;
                        }
                        else
                            if ((pastX[k] == random5) && (pastY[k] == random6)) {
                                random5 = rand() % kolvo1 + 1;
                                random6 = rand() % kolvo2 + 3;
                                gotoxy(random5, random6);
                                cout << yabloko;
                            }
                            else
                                if ((pastX[k] == random7) && (pastY[k] == random8)) {
                                    random7 = rand() % kolvo1 + 1;
                                    random8 = rand() % kolvo2 + 3;
                                    gotoxy(random7, random8);
                                    cout << yabloko;
                                }

                }
            }
            break;
        case 77:vibor_x++;
            if (koordwall[vibor_y][vibor_x] == '#') {
                system("cls");
                gotoxy(50, 15);
                cout << "GAME OVER";
                gotoxy(1, 20);
                cout << "press Enter to play again";
                int a = _getch();
                if (a == 13) {
                    system("cls");
                    goto start;
                }

            }
            presentX[0] = vibor_x;
            presentY[0] = vibor_y;
            gotoxy(presentX[0], presentY[0]);
            cout << b;
            int predx2;
            predx2 = (vibor_x - 1);

            gotoxy(predx2, vibor_y);
            cout << " ";
            if (((vibor_x == random1) && (vibor_y == random2)) || ((vibor_x == random3) && (vibor_y == random4)) ||
                ((vibor_x == random5) && (vibor_y == random6)) || ((vibor_x == random7) && (vibor_y == random8))) {
                point += 1;
                len += 2;
                if ((vibor_x == random1) && (vibor_y == random2)) {
                    random1 = rand() % kolvo1 + 1;
                    random2 = rand() % kolvo2 + 3;
                    gotoxy(random1, random2);
                    cout << yabloko;
                }
                else
                    if ((vibor_x == random3) && (vibor_y == random4)) {
                        random3 = rand() % kolvo1 + 1;
                        random4 = rand() % kolvo2 + 3;
                        gotoxy(random3, random4);
                        cout << yabloko;
                    }
                    else
                        if ((vibor_x == random5) && (vibor_y == random6)) {
                            random5 = rand() % kolvo1 + 1;
                            random6 = rand() % kolvo2 + 3;
                            gotoxy(random5, random6);
                            cout << yabloko;
                        }
                        else
                            if ((vibor_x == random7) && (vibor_y == random8)) {
                                random7 = rand() % kolvo1 + 1;
                                random8 = rand() % kolvo2 + 3;
                                gotoxy(random7, random8);
                                cout << yabloko;
                            }
                gotoxy(xc + 2, 3);
                cout << "Amount of points: " << point;
                
            }
            if (((random1 == random3) && (random2 == random4)) || ((random1 == random5) && (random2 == random6)) || ((random1 == random7) && (random2 == random8))) {
                if ((random1 == random3) && (random2 == random4)) {
                    random1 = rand() % kolvo1 + 1;
                    random2 = rand() % kolvo2 + 3;
                    gotoxy(random1, random2);
                    cout << yabloko;
                }
                else
                    if ((random1 == random5) && (random2 == random6)) {
                        random1 = rand() % kolvo1 + 1;
                        random2 = rand() % kolvo2 + 3;
                        gotoxy(random1, random2);
                        cout << yabloko;
                    }
                    else
                        if ((random1 == random7) && (random2 == random8)) {
                            random1 = rand() % kolvo1 + 1;
                            random2 = rand() % kolvo2 + 3;
                            gotoxy(random1, random2);
                            cout << yabloko;
                        }
            }
            if (((random3 == random5) && (random4 == random6)) || ((random3 == random7) && (random4 == random8)) || ((random5 == random7) && (random6 == random8))) {
                if ((random3 == random5) && (random4 == random6)) {
                    random3 = rand() % kolvo1 + 1;
                    random4 = rand() % kolvo2 + 3;
                    gotoxy(random3, random4);
                    cout << yabloko;
                }
                else
                    if ((random3 == random7) && (random4 == random8)) {
                        random1 = rand() % kolvo1 + 1;
                        random2 = rand() % kolvo2 + 3;
                        gotoxy(random3, random4);
                        cout << yabloko;
                    }
                    else
                        if ((random5 == random7) && (random6 == random8)) {
                            random5 = rand() % kolvo1 + 1;
                            random6 = rand() % kolvo2 + 3;
                            gotoxy(random5, random6);
                            cout << yabloko;
                        }
            }
            if (vibor_x == (xc - 1)) {
                system("cls");
                gotoxy(50, 15);
                cout << "GAME OVER";
                gotoxy(1, 20);
                cout << "press Enter to play again";
                int a = _getch();
                if (a == 13) {
                    system("cls");
                    goto start;
                }
            }
            for (int k = len; k != 0; k--)
            {
                if (((random1 == pastX[k]) && (random2 == pastY[k])) || ((random3 == pastX[k]) && (random4 == pastY[k])) ||
                    ((random5 == pastX[k]) && (random6 == pastY[k])) || ((random7 == pastX[k]) && (random8 == pastY[k]))) {
                    if ((random1 == pastX[k]) && (random2 == pastY[k])) {
                        random1 = rand() % kolvo1 + 1;
                        random2 = rand() % kolvo2 + 3;
                        gotoxy(random1, random2);
                        cout << yabloko;
                    }
                    else
                        if ((random3 == pastX[k]) && (random4 == pastY[k])) {
                            random3 = rand() % kolvo1 + 1;
                            random4 = rand() % kolvo2 + 3;
                            gotoxy(random3, random4);
                            cout << yabloko;
                        }
                        else
                            if ((random5 == pastX[k]) && (random6 == pastY[k])) {
                                random5 = rand() % kolvo1 + 1;
                                random6 = rand() % kolvo2 + 3;
                                gotoxy(random5, random6);
                                cout << yabloko;
                            }
                            else
                                if ((random7 == pastX[k]) && (random8 == pastY[k])) {
                                    random7 = rand() % kolvo1 + 1;
                                    random8 = rand() % kolvo2 + 3;
                                    gotoxy(random7, random8);
                                    cout << yabloko;
                                }

                }
            }
            break;
        case 13:
            
            gotoxy(xc + 2, 6);
            cout << "Press 1 to put the wall";
            gotoxy(xc + 2, 7);
            cout << "Press 2 to delete the wall for 3 points";
            int z;
            z = _getch();
            switch (z) {
            case 49:
                gotoxy(vibor_x+1, vibor_y);
                cout << "#";
                if (koordwall[vibor_y][vibor_x+1] == char(32)) {
                    koordwall[vibor_y][vibor_x+1] = '#';
                    
                }
                if ((vibor_x+1 == random1) && (vibor_y == random2)) {
                    random1 = rand() % kolvo1 + 1;
                    random2 = rand() % kolvo2 + 3;
                    gotoxy(random1, random2);
                    cout << yabloko;
                }
                else
                    if ((vibor_x+1 == random3) && (vibor_y == random4)) {
                        random3 = rand() % kolvo1 + 1;
                        random4 = rand() % kolvo2 + 3;
                        gotoxy(random3, random4);
                        cout << yabloko;
                    }
                    else
                        if ((vibor_x+1 == random5) && (vibor_y == random6)) {
                            random5 = rand() % kolvo1 + 1;
                            random6 = rand() % kolvo2 + 3;
                            gotoxy(random5, random6);
                            cout << yabloko;
                        }
                        else
                            if ((vibor_x+1 == random7) && (vibor_y == random8)) {
                                random7 = rand() % kolvo1 + 1;
                                random8 = rand() % kolvo2 + 3;
                                gotoxy(random7, random8);
                                cout << yabloko;
                            }
                break;

            case 50:
                gotoxy(vibor_x + 1, vibor_y);
                if ((koordwall[vibor_y][vibor_x+1] == '#') && (point>=3)) {
                    cout << " ";
                    koordwall[vibor_y][vibor_x + 1] = char(32);
                    point = point - 3;
                    gotoxy(xc + 2, 3);
                    cout << "                 ";
                    gotoxy(xc + 2, 3);
                    cout << "Amount of points: " << point;
                }
                break;
            }
        

            
            }
            if (vibor_x < 1) // ПРОВЕРКА НА ГРАНИЦЫ
                vibor_x = xc - 2;
            if (vibor_x > (xc - 2))
                vibor_x = 1;
            if (vibor_y < 3)
                vibor_y = yc;
            if (vibor_y > yc)
                vibor_y = 3;
            
           
            if (point >= 1) { //ОТРИСОВКА ХВОСТА
                for (int k = len; k != 0; k--)
                {
                    gotoxy(pastX[k], pastY[k]);
                    cout << b;
                }
                    gotoxy(pastX[k + 1], pastY[k + 1]);
                    cout << " ";
                
            }
            for (int k = len; k != 0; k--) // ВРЕЗАНИЕ В СЕБЯ
            {
                if ((vibor_x == pastX[k+3]) && (vibor_y == pastY[k+3]) && (point >= 1)) {
                    system("cls");
                    gotoxy(50, 15);
                    cout << "GAME OVER";
                    gotoxy(1, 20);
                    cout << "press Enter to play again";
                    int a = _getch();
                    if (a == 13) {
                        system("cls");
                        goto start;
                    }
                }
            }
            

            
            if (point == 15) {
                system("cls");
                gotoxy(50, 15);
                cout << "YOU WON";
                gotoxy(1, 20);
                cout << "press Enter to play again";
                int a = _getch();
                if (a == 13) {
                    system("cls");
                    goto start;
                }
            }
            }

            gotoxy(1, yc + 3);
            system("pause");
            }

        

    
