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
void pole() {
    cout << "   |   |"<< endl;
    cout << "---+---+---" << endl;
    cout << "   |   | " << endl;
    cout << "---+---+---" << endl;
    cout << "   |   |" << endl;
}
int main() {
    nachalo:
    pole();
    int hod = 1;
    int xc = 1, xy = 0;
    char q;
    char d = (42);
    char krest = (35);
    char nol = (79);
    bool exit = true;
    int i = 0;
    int j = 0;
    int aa = 0, bb = 0, cc = 0, dd = 0, ff = 0, gg = 0, hh = 0, jj = 0, kk = 0, vv = 0, mm = 0, nn = 0,w=0,e=0,r=0,t=0,u=0,o=0,ww=0,ee=0,rr=0,tt=0,uu=0,oo=0;
    while (exit) {
        int maskrest[5][2];
        int masnol[4][2];
        gotoxy(xc, xy);
        q = _getch();
        if (q == 224)
            q = _getch();
        switch (q) {
        case 72: xy--;
            xy--;
            if (xy < 0)
                xy = 4;
            gotoxy(xc, xy);
            break;
        case 80: xy++;
            xy++;
            if (xy > 4)
                xy = 0;
            gotoxy(xc, xy);
            break;
        case 75:xc--;
            xc--;
            xc--;
            xc--;
            if (xc < 1)
                xc = 9;
            gotoxy(xc, xy);
            break;
        case 77:xc++;
            xc++;
            xc++;
            xc++;
            if (xc > 9)
                xc = 1;
            gotoxy(xc, xy);
            break;
        case 13:

            if (hod % 2 != 0) {
                int k = 0;
                if (xy == masnol[k][1] && xc == masnol[k][0]) {
                    gotoxy(xc, xy);
                    cout << nol;
                }
                else if (xy == masnol[k + 1][1] && xc == masnol[k + 1][0]) {
                    gotoxy(xc, xy);
                    cout << nol;
                }
                else if (xy == masnol[k + 2][1] && xc == masnol[k + 2][0]) {
                    gotoxy(xc, xy);
                    cout << nol;
                }
                else if (xy == masnol[k + 3][1] && xc == masnol[k + 3][0]) {
                    gotoxy(xc, xy);
                    cout << nol;
                }
                else if (xy == masnol[k + 4][1] && xc == masnol[k + 4][0]) {
                    gotoxy(xc, xy);
                    cout << nol;
                }
                else {
                    maskrest[i][0] = xc;
                    maskrest[i][1] = xy;
                    i++;
                    hod++;
                    gotoxy(xc, xy);
                    cout << krest;
                    if (xy == 0)
                        aa += 1;
                    if (xy == 2)
                        bb += 1;
                    if (xy == 4)
                        cc += 1;
                    if (xc == 1)
                        dd += 1;
                    if (xc == 5)
                        ff += 1;
                    if (xc == 9)
                        gg += 1;
                    if (xy == 0 && xc == 1)
                        w += 1;
                    if (xy == 2 && xc == 5)
                        e += 1;
                    if (xy == 4 && xc == 9)
                        r += 1;
                    if (xy == 0 && xc == 9)
                        t += 1;
                    if (xy == 2 && xc == 5)
                        u += 1;
                    if (xy == 4 && xc == 1)
                        o += 1;
                }
            }
            else {
                int k = 0;
                if (xy == maskrest[k][1] && xc == maskrest[k][0]) {
                    gotoxy(xc, xy);
                    cout << krest;
                }
                else if (xy == maskrest[k + 1][1] && xc == maskrest[k + 1][0]) {
                    gotoxy(xc, xy);
                    cout << krest;
                }
                else if (xy == maskrest[k + 2][1] && xc == maskrest[k + 2][0]) {
                    gotoxy(xc, xy);
                    cout << krest;
                }
                else if (xy == maskrest[k + 3][1] && xc == maskrest[k + 3][0]) {
                    gotoxy(xc, xy);
                    cout << krest;
                }
                else if (xy == maskrest[k + 4][1] && xc == maskrest[k + 4][0]) {
                    gotoxy(xc, xy);
                    cout << krest;
                }
                else if (xy == maskrest[k + 5][1] && xc == maskrest[k + 5][0]) {
                    gotoxy(xc, xy);
                    cout << krest;
                }
                else {
                    masnol[j][0] = xc;
                    masnol[j][1] = xy;
                    j++;
                    hod++;
                    gotoxy(xc, xy);
                    cout << nol;
                    if (xy == 0)
                        hh += 1;
                    if (xy == 2)
                        jj += 1;
                    if (xy == 4)
                        kk += 1;
                    if (xc == 1)
                        vv += 1;
                    if (xc == 5)
                        mm += 1;
                    if (xc == 9)
                        nn += 1;
                    if (xy == 0 && xc == 1)
                        ww += 1;
                    if (xy == 2 && xc == 5)
                        ee += 1;
                    if (xy == 4 && xc == 9)
                        rr += 1;
                    if (xy == 0 && xc == 9)
                        tt += 1;
                    if (xy == 2 && xc == 5)
                        uu += 1;
                    if (xy == 4 && xc == 1)
                        oo += 1;
                }
            }
            if (((aa == 3) || (bb == 3) || (cc == 3) || (dd == 3) || (ff == 3) || (gg == 3)) || (w == 1 && e == 1 && r == 1) || (t == 1 && u == 1 && o == 1)) {
                system("cls");
                gotoxy(50, 15);
                cout << "POBEDA KRESTOV\n";
                system("pause");
                system("cls");
                goto nachalo;
            }
            if (((mm == 3) || (vv == 3) || (nn == 3) || (jj == 3) || (kk == 3) || (hh == 3)) || (ww == 1 && ee == 1 && rr == 1) || (tt == 1 && uu == 1 && oo == 1)) {
                system("cls");
                gotoxy(50, 15);
                cout << "POBEDA NULEY\n";
                system("pause");
                system("cls");
                goto nachalo;
            }
        }
   }        return 0;
}
