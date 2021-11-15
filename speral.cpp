#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <Windows.h>
using namespace std;

int y = 1,  a= 1, shirina, visota;

void gotoxy(int xpos, int ypos)
{
    COORD scrn;

    HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);

    scrn.X = xpos; scrn.Y = ypos;

    SetConsoleCursorPosition(hOuput, scrn);
}

int menu() {
    printf("ьхпхмю- %d \nбшянрю - %d\n1 - хг мювюкю он вюянбни\n2 - хг мювюкю опнрхб вюянбни\n3 - хг жемрпю опнрхб вюянбни\n4 - хг жемрпю он вюянбни\n5 - ббхдхре мнбсч дкхммс\n6 - ббедхре мнбсч дкхмс\n7 - бшунд\n", shirina, visota);
    return 0;
}

int vivod(int massive[12][12]) {
    for (int x = 0; x < 12; x++) {
        for (int y = 0; y < 12; y++) {
            if (massive[x][y] != -1)
            {
                printf("%d \t", massive[x][y]);
            }
        }
        if (massive[x][0] != -1) {
            printf("\n");
        }
    }
    return 0;
}


int vvod(int f = 0) {
    int a, b = 0;
    do {
        a = _getch();
        if (f != 0) {
            system("cls");
            menu();

            if (a == 224) {
                a = _getch();
                if (a == 72) {
                    if (y == 1) {
                        y = 7;
                        gotoxy(29, y+1);
                        printf("<--");

                    }
                    else {
                        y -= 1;
                        gotoxy(29, y+1);
                        printf("<--");

                    }
                }
                else if (a == 80) {
                    if (y == 7) {
                        y = 1;
                        gotoxy(29, y+1);
                        printf("<--");


                    }
                    else {
                        y += 1;
                        gotoxy(29, y+1);
                        printf("<--");
                    }
                }
            }

        }
        if ((a >= 48) && (a <= 58)) {
            printf("%d", a - 48);
            b *= 10;
            b += a - 48;
        }
        else if (a == 8) {
            b /= 10;
            printf("\b \b");
        }
    } while (a != 13);
    if (b != 0)return b;
    else if (f != 0)return y;
}

int speral(int massive[12][12], int shirina, int visota, int start, int napr) {
    int x = 0, y = 0, maxi, count = 1, znak;
    if (start == 1) {
        maxi = visota * shirina;
        count = 1;
        znak = 1;
    }
    else {
        maxi = 1;
        count = visota * shirina;
        znak = -1;
    }
    if (napr == 1) {
        y = 0;
    }
    else {
        y = shirina - 1;
    }
    do {
        if (napr == 1) {
            do {
                if (count == maxi)break;
                massive[x][y++] = count;
                count += znak;
            } while ((massive[x][y + 1] == 0));
        }
        else {
            do {
                if ((count == maxi) || (y == 0))break;
                massive[x][y--] = count;
                count += znak;
            } while ((massive[x][y - 1] == 0));
        }
        do {
            if (count == maxi)break;
            massive[x++][y] = count;
            count += znak;
        } while ((massive[x + 1][y] == 0));
        if (napr == 1) {
            do {
                if (count == maxi)break;
                massive[x][y--] = count;
                count += znak;
            } while ((massive[x][y - 1] == 0));
        }
        else {
            do {
                if (count == maxi)break;
                massive[x][y++] = count;
                count += znak;
            } while (massive[x][y + 1] == 0);
        }
        do {
            if (count == maxi)break;
            massive[x--][y] = count;
            count += znak;
        } while ((massive[x - 1][y] == 0));
        if (massive[x][y] == 0)massive[x][y] = count;
    } while (count != maxi);
    return 0;
}


int switch_menu(int a, int massive[12][12]) {
    switch (a) {
    case 1:
        speral(massive, shirina, visota, 1, 1);
        y = 2;
        break;
    case 2:
        speral(massive, shirina, visota, 1, 2);
        y = 3;
        break;
    case 3:
        speral(massive, shirina, visota, 2, 1);
        y = 4;
        break;
    case 4:
        speral(massive, shirina, visota, 2, 2);
        y = 5;
        break;
    case 5:
        y = 6;
        do {
            printf("\nббедхре ьхпхмс\n");
            shirina = vvod();
        } while ((shirina > 12) || (shirina <= 1));
        break;
    case 6:
        y = 7;
        do {
            printf("\nббедхре бшянрс\n");
            visota = vvod();
        } while ((visota > 12) || (visota <= 1));
        break;
    case 7:
        system("cls");
        _exit(EXIT_SUCCESS);
        break;
    }
    return 0;
}


int main() {
    system("color D0");
    int a;
    setlocale(0, "RU");
    int massive[12][12];
    shirina = 12;
    visota = 12;
    do {
        printf("бБЕДХРЕ ЬХПХМС\n");
        shirina = vvod();
    } while ((shirina > 12) || (shirina <= 1));
    do {
        printf("\nбБЕДХРЕ БШЯНРС\n");
        visota = vvod();
    } while ((visota > 12) || (visota <= 1));
    for (int x = 0; x < 12; x++) {
        for (int y = 0; y < 12; y++) {
            if ((y < shirina) && (x < visota)) {
                massive[x][y] = 0;
            }
            else {
                massive[x][y] = -1;
            }
        }
    }
    system("cls");
    menu();
    do {

        switch_menu(a = vvod(1), massive);
        if (massive[0][0] != 0) {
            vivod(massive);
        };
        for (int x = 0; x < 12; x++) {
            for (int y = 0; y < 12; y++) {
                if ((y < shirina) && (x < visota)) {
                    massive[x][y] = 0;
                }
                else {
                    massive[x][y] = -1;
                }
            }
        }
        gotoxy(29, y);
        printf("<--");
    } while (a !=0);
    return 0
        ;
}