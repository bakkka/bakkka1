#include <stdio.h>
#include <stdlib.h>
#include <io.h>
#include <direct.h>
#include <fcntl.h>
#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include <conio.h>
#include <locale.h>
using namespace std;

struct Dict {
    string name;
    Dict* adr;
    struct _finddata_t file;
};
COORD coord = { 0,0 };
void gotoxy(int x, int y)
{
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
const char* katalog = "E:\\";
struct _finddata_t file;
intptr_t File;
int dlina() {
    int size = 0;
    if ((File = _findfirst("*.*", &file)) == -1)
    {
        cout << "Cannot open dir";
    }
    else
    {
        do
        {
            size++;

        } while (_findnext(File, &file) == 0);
        _findclose(File);
    }
    return size;
}
Dict* spisok() {
    int size = dlina();
    Dict* cur = nullptr,
        * next = nullptr;
    if ((File = _findfirst("*.*", &file)) == -1)
    {
        cout << "Cannot open dir";
    }
    else
    {
        do
        {
            cur = new Dict;
            cur->adr = next;
            cur->file = file;
            next = cur;
        } while (_findnext(File, &file) == 0);
        _findclose(File);
    }
    return cur;
}
void vivod(Dict* spisok,int xc) {
    Dict* start = spisok;
    int a = dlina();
    int yyy = 1;
    for (int i = 0; i < a; i++) {      
        gotoxy(xc,yyy);
        cout << start->file.name << endl;
        start = start->adr;
        yyy++;
    }
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
void pole(int yc, int xc)
{
    for (int i = 0; i < yc; i++) {
        for (int j = 0; j < xc; j++) {
            if (i != 0 && i != (yc - 1) && j != 0 && j != (xc - 1)) {
                if (j == (xc / 2)) {
                    cout << "|";
                }
                cout << " ";
            }
            else
                if (j == 0 || j == (xc - 1))
                    cout << "|";
                else
                    if (i == 0 || i == (yc - 1))
                        cout << "-";               
        }
        cout << endl;       
    }
    cout << "ENTER-ОТКРЫТЬ ПАПКУ" << endl;
    cout << "ESC-ПРОСМОТР ФАЙЛА" << endl;
    cout << "BACKSPACE-ВЕРНУТЬСЯ НАЗАД" << endl;
    cout << "ВЫБЕРИТЕ ФАЙЛ ДЛЯ СРАВНЕНИЕ И НАЖМИТЕ ПРОБЕЛ";
    cout << "\n\n";
}
int main()
{
    setlocale(LC_ALL, "RUSSIAN");
   
    bool exit = true;
    char vibor = 1;
    int x = 1, y = 1;
    int yy = 60, xx = 130;
    int done;
    int code_simvola;
    Dict* cr = 0;
    const int up = 72;
    const int down = 80;
    const int enter = 13;
    const int esc = 27;
    const int backspace=8;
    const int tab = 9;
    const int space = 32;
    int raz = 0;
    int kol = 0;
    int viv =1;
    string strh;
    string str;
    _chdir(katalog);   
    cr = spisok();
    int visota = dlina();
    pole(visota+2, xx);
    gotoxy(x, y);
    vivod(cr,1);
    int strelka = 55;
    char* papka = new char;
    
    while (exit) {     
        gotoxy(strelka, vibor);
        if (raz == 0) {
            printf("<==");
        }
        code_simvola = _getch();
        if (code_simvola == 224)
            code_simvola = _getch();
        switch (code_simvola) {
        case up:vibor--;
            gotoxy(strelka, vibor + 1);
            cout << "   ";
            break;
        case down:vibor++;
            gotoxy(strelka, vibor - 1);
            cout << "   ";
            break;
        case enter:          
                raz = 0;
                system("cls");
                pole(visota + 2, xx);
                cr = spisok();
                vivod(cr, 1);
                for (int a = 0; a < vibor - 1; a++) {
                    cr = cr->adr;
                }
                _chdir(cr->file.name);
                visota = dlina();
                system("cls");
                pole(visota + 2, xx);              
                cout << "ОТКРЫТАЯ ПАПКА:"<<cr->file.name;
                cr = spisok();
              
                vivod(cr, 1);
            break;
        case backspace:
            _chdir("..\\");
            raz = 0;
            
            visota = dlina();
            system("cls");
            pole(visota+2, xx);
            cr = spisok();
            vivod(cr,1);          
            break;
        case esc:
            if (raz == 0) {
                raz = 1;
                str = "";
                system("cls");
                
                for (int a = 0; a < vibor - 1; a++) {
                    cr = cr->adr;
                }
                ifstream fin(cr->file.name);
                if (fin.is_open()) {
                    while (!fin.eof()) {
                        getline(fin, strh);
                        str += strh;
                        str += ' ';
                        if (!fin.eof())
                            str += "\n";
                    }

                    cout << str;
                  
                    _chdir(cr->file.name);
                    fin.close();
                }
            }
            break;
        case tab:
            
            gotoxy(0, visota + 6);
            cout << "Введите имя папки, которую хотите создать: ";    
            cin >> papka;
            _mkdir(papka);
            system("cls");
            visota = dlina();
            pole(visota + 2, xx);
            cr = spisok();
            vivod(cr, 1);
            break;
        case space:
            string ch1, ch2, chh1, chh2;
            ifstream fin1, fin2;
            bool result = true;
            ch1 = "";
            ch2 = "";
            if (kol == 0) {
                for (int a = 0; a < vibor - 1; a++) {
                        cr = cr->adr;
                }
                ifstream fin1(cr->file.name,ios::binary);
                kol++;     
                visota = dlina();
                system("cls");
                pole(visota + 2, xx);
                cr = spisok();
                vivod(cr, 1);
                break;               
            }
            else {            
                for (int a = 0; a < vibor - 1; a++) {
                    cr = cr->adr;
                }
                ifstream fin2(cr->file.name,ios::binary);               
                kol = 0;
            }
            while (!fin1.eof()) {
                getline(fin1, chh1);
                ch1 += chh1;
                ch1 += ' ';
                if (!fin1.eof())
                    ch1 += "\n";
            }
            while (!fin2.eof()) {
                getline(fin2, chh2);
                ch2 += chh2;
                ch2 += ' ';
                if (!fin2.eof())
                    ch2 += "\n";
            }
            if (ch1 != ch2) {
                 result = false;                       
                 break;
            }
                
            
            if (result == true) {
                system("cls");
                visota = dlina();
                pole(visota + 2, xx);
                cr = spisok();
                vivod(cr, 1);
                gotoxy(0, visota + 9);
                cout << "ОДИНАКОВЫЕ ФАЙЛЫ";
                
            }
            else {
                system("cls");
                visota = dlina();
                pole(visota + 2, xx);
                cr = spisok();
                vivod(cr, 1);
                gotoxy(0, visota + 9);
                cout << "РАЗНЫЕ ФАЙЛЫ";
            }
            break;
        }
        if (vibor < 1)
            vibor = visota ;
        if (vibor > visota)
            vibor = 1;
    }
    return 0;
}
