#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include <windows.h>
#include <stdlib.h>

using namespace std;
COORD coord = { 0,0 };
void gotoxy(int x, int y)
{
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void menu() {
    
    cout << "1.Создать список" << endl;
    cout << "2.Добавить элемент" << endl;
    cout << "3.Удалить элемент" << endl;
    cout << "4.Отсортировать по значению" << endl;
    cout << "5.Изменить значение элемента" << endl;
    cout << "6.Удалить весь список" << endl;
    cout << "7.Выход" << endl;
    cout << "8.Удалить часть списка" << endl;
   
}
struct Dict {
    int number;
    Dict* adr;
};
Dict* create(unsigned length,unsigned nachalo) {
    Dict* cur = nullptr,
        * next = nullptr;
    for (unsigned i = nachalo+length-1; i >=nachalo; i--) {
        cur = new Dict;
        cur->adr = next;
        cur->number = i;
        next = cur;
    }
    return cur;
}
int dlina(Dict* dell) {
    int dlina = 1;
    while (dell->adr) {
        dlina++;
        dell = dell->adr;
    }
    return dlina;
}
Dict* deletee(Dict* dell,int pos) {
    Dict* n = dell,
        *start = dell;
    if (pos == 1) {
        start = start->adr;
        delete n;
    }
    else {
        if (dlina(dell) >= pos) {
            for (int i = 1; (i < pos - 1); i++) {
                dell = dell->adr;
            }
            n = dell->adr;
            dell->adr = n->adr;
            delete n;
        }
    }
    return start;
    

}
void vivod(Dict* spisok) {
    Dict* start = spisok;
    int a = dlina(start);
    for (int i = 0; i < a;i++) {

        cout << start->number;
        cout << " ";
        start = start->adr;



    }
}
void obnov(Dict* cr) {    
    system("cls");
    menu();
    gotoxy(0, 9);
    vivod(cr);
}
Dict* izmena(Dict* dell, int pos,int znach) {
    Dict* n = dell,
        * start = dell;
    for (int i = 1; i < pos; i++) {
        n = n->adr;

    }
    n->number = znach;
    return start;
}
Dict* udalenie(Dict* dell) {
    while (dell) {
        Dict* n;
        n = dell;
        dell = dell->adr;
        delete n;

    }
    return dell;
    
}
Dict* dobav(Dict* dell, int pos, int znach, int kolvo) {
    Dict* n = dell,
        * vstavka = create(kolvo, znach),
        * k = dell;
    if (pos > 1) {
        for (int i = 1; i < pos - 1; i++) {
            n = n->adr;
        }

        k = n->adr;
        n->adr = vstavka;
    }
    else {
        dell = vstavka;
    }
    while (vstavka->adr) {
        vstavka = vstavka->adr;

    }
    vstavka->adr = k;
    return dell;
}
Dict* sorti(Dict* dell) {
    Dict* n = dell,
        * nachalo = dell;
    
    for (int i = 0; i < dlina(n); i++) {
        nachalo = dell;
        for (Dict* j = nachalo; j->adr; j=j->adr) {
            if (j->number > (j->adr)->number) {
                int b = j->number;
                j->number = (j->adr)->number;
                (j->adr)->number = b;
            }
            
        }

    }
    return nachalo;
}
int vvod() {
    nachalo:
    int x = 0;
    int t;
    char a;
    
    bool exit = true;
    
    do {
        a = _getch();
        
        if (a >= 48 && a <= 57) {
            t = a - 48;
            cout << t;
            x = x * 10 + t;
        }
        else if (a == 8) {
            x /= 10;
            printf("\b \b");
        }
        if (a == 13 && x == 0) {
            goto nachalo;
        }
    } while (a != 13);
    if (x != 0)
        return x;

}
Dict* chast(Dict* dell, int pos, int kolvo) {
    Dict* n = dell,
        * start = dell,
        *k = dell;
    if (pos >= 1) {
        for (int i = 0; i <= pos - 2; i++) {
            dell = dell->adr;
        }
        for (int i = 0; i < kolvo; i++) {           
            n = dell->adr;
            dell->adr= n->adr;
            delete n;
            
        }
    }
    return start;
}
int main() {
    setlocale(0, "RU");
    bool exit = true;
    char vibor = 0;
    int code_simvola;
    Dict* cr = 0;
    int raz = 0;
    
  menu();     
  while (exit) {
        gotoxy(35, vibor);
        printf("<==");
        code_simvola = _getch();
        if (code_simvola == 224) 
            code_simvola = _getch();
        switch (code_simvola) {
        case 72:vibor--;
            gotoxy(35, vibor + 1);
            cout << "   ";
            break;
        case 80:vibor++;
            gotoxy(35, vibor - 1);
            cout << "   ";
            break;
        case 13:
            if (vibor == 6) {
                system("cls");
                _exit(EXIT_SUCCESS);
            }
            else
                if (vibor == 0) {
                    if (raz > 0) {
                        system("cls");
                        menu();                  
                    }
                    gotoxy(0, 8);
                    unsigned length,nachalo;
                    cout << "Введите длину: ";
                    cout << "    ";
                    gotoxy(15, 8);
                    length = vvod();
                    while (length > 999) {
                        gotoxy(0, 8);
                        cout << "Введите длину:          ";
                        gotoxy(17, 8);
                        length = vvod();
                    }
                    gotoxy(25, 8);
                    cout << "Ввидите первый элемент: ";
                    nachalo = vvod();
                    while (nachalo > 1000) {
                        gotoxy(25, 8);
                        cout << "Ввидите первый элемент:        ";
                        gotoxy(50, 8);
                        nachalo = vvod();
                    }
                    cout << endl;
                    cr = create(length,nachalo);
                    gotoxy(0, 8);
                    obnov(cr);
                    raz=1;
                    int uslov = 0;
                }
                else
                    if (vibor == 2) {
                        if (raz == 1) {
                            gotoxy(0, 8);
                            cout << "Выберите элемент: ";
                            int position;
                            position = vvod();
                            while (position> 999) {
                                gotoxy(0, 8);
                                cout << "Выберите элемент:        ";
                                gotoxy(18, 8);
                                position = vvod();
                            }
                            while (position > dlina(cr)) {
                                obnov(cr);
                                gotoxy(0, 8);
                                cout << "Выберите элемент: ";
                                position = vvod();
                            }
                            cout << endl;
                            cr = deletee(cr, position);
                            obnov(cr);
                        }
                    }
                    else
                        if (vibor == 4) {
                            if (raz == 1) {
                                gotoxy(0, 8);
                                cout << "Выберите элемент: ";
                                int position;
                                position = vvod();
                                while (position > 999) {
                                    gotoxy(0, 8);
                                    cout << "Выберите элемент:     ";
                                    gotoxy(25, 8);
                                    position = vvod();                                 
                                }
                                while (position > dlina(cr)) {
                                    obnov(cr);
                                    gotoxy(0, 8);
                                    cout << "Выберите элемент: ";
                                    position = vvod();
                                }
                                gotoxy(20, 8);
                                cout << "Введите значение: ";
                                int znach;
                                znach = vvod();
                                while (znach > 999) {
                                    gotoxy(20, 8);
                                    cout << "Выберите значение :         ";
                                    gotoxy(45, 8);
                                    znach = vvod();
                                }
                                cr = izmena(cr, position, znach);
                                obnov(cr);
                            }
                        }
                        else
                            if (vibor == 5) {
                                if (cr&&raz==1) {
                                    udalenie(cr);
                                    system("cls");
                                    menu();
                                    raz=0;
                                }                              
                            }
                            else
                                if (vibor == 1) {
                                    if (raz == 1) {
                                        int position;
                                        int znach;
                                        int kolvo;                                      
                                        gotoxy(0, 8);
                                        cout << "Выберите позицию: ";
                                        position = vvod();
                                        while (position > (dlina(cr)+1)) {
                                            obnov(cr);
                                            gotoxy(0, 8);
                                            cout << "Выберите позицию: ";
                                            position = vvod();
                                        }
                                        gotoxy(21, 8);
                                        cout << "Выберете значение: ";
                                        znach = vvod();
                                        gotoxy(43, 8);
                                        cout << "Введите колво элементов: ";
                                        kolvo = vvod();
                                        while(kolvo > 999) {
                                            gotoxy(43, 8);
                                            cout << "Введите колво элементов:        ";
                                            gotoxy(68, 8);
                                            kolvo = vvod();
                                        }
                                        cr=dobav(cr, position, znach, kolvo);
                                        obnov(cr);                                      
                                    }
                                }
                                else
                                    if (vibor == 3) {
                                        if (raz == 1) {                                         
                                           cr=sorti(cr);
                                           obnov(cr);
                                        }
                                    }    
                                    else
                                        if (vibor == 7) {
                                            int position;
                                            int kolvo;
                                            int len = dlina(cr);
                                            
                                            if (raz == 1) {                                               
                                                do {
                                                    obnov(cr);
                                                    gotoxy(0, 8);
                                                    cout << "Выберите позицию: ";
                                                    position = vvod();
                                                    while (position > (dlina(cr) + 1)) {
                                                        gotoxy(0, 8);
                                                        cout << "Выберите позицию:       ";
                                                        gotoxy(18, 8);
                                                        position = vvod();
                                                    }
                                                    cout << "   Введите колво элементов: ";
                                                    kolvo = vvod();
                                                    while (kolvo > 999) {
                                                        gotoxy(43, 8);
                                                        cout << "Введите колво элементов:        ";
                                                        gotoxy(68, 8);
                                                        kolvo = vvod();
                                                    }
                                                } while (position + kolvo > len);

                                            }
                                                cr=chast(cr, position, kolvo);
                                                obnov(cr);
                                            }
                                        
        break;
        }
        if (vibor < 0)
            vibor = 7;
        if (vibor > 7)
            vibor = 0;
    }
    return 0;
 }
