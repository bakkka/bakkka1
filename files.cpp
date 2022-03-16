
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
    cout << "ВЫБЕРИТЕ ФАЙЛ ДЛЯ СРАВНЕНИЕ И НАЖМИТЕ ПРОБЕЛ" << endl;
    cout << "ВЫБЕРИТЕ ФАЙЛ ДЛЯ КОПИРОВАНИЯ И НАЖМИТЕ 1" << endl;
    cout << "НАЖМИТЕ TAB ДЛЯ СОЗДАНИЯ ФАЙЛА В ДАННОЙ ПАПКЕ"; 
    cout << "\n\n";
    
}
int main()
{
    setlocale(LC_ALL, "RUSSIAN");
   
    bool exit = true;
    char vibor = 1;
    int x = 1, y = 1;
    int yy = 60, xx = 130;
    int code_simvola;
    Dict* cr = 0;
    const int up = 72;
    const int down = 80;
    const int enter = 13;
    const int esc = 27;
    const int backspace=8;
    const int tab = 9;
    const int space = 32;
    const int copy = 49;
    int raz = 0;
    int kol = 0;
    int viv =1;
    int faz = 0;
    int pol = 0;
    string strh,strh3;
    string str,str3;
    _chdir(katalog);   
    cr = spisok();
    int visota = dlina();
    pole(visota+2, xx);
    gotoxy(x, y);
    vivod(cr,1);
    int strelka = 55;
    char* papka = new char;
    char* name = cr->file.name;
    FILE* filee;
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
            cout << "ОТКРЫТАЯ ПАПКА:" << cr->file.name;           
            /*_chdir("..\\");*/
            cr = spisok();
            vivod(cr, 1);
           /* _chdir(cr->file.name);
            cr = spisok();
            vivod(cr, 66);
            strelka = 115;*/
            break;
        case backspace:
            _chdir("..\\");
            raz = 0;

            visota = dlina();
            system("cls");
            pole(visota + 2, xx);
            cr = spisok();
            
            vivod(cr, 1);
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
        {
            gotoxy(0, visota + 6);
            cout << "Введите имя папки, которую хотите создать: ";
            cin >> papka;
            strcat(papka, ".txt");
            FILE* filee = fopen(papka, "w");
            cout << (filee != NULL ? "File created\n" : "Cannot create file\n");
            fclose(filee);
            system("cls");
            visota = dlina();
            pole(visota + 2, xx);
            cr = spisok();
            vivod(cr, 1);
        }
            break;
        

        /*case space:
        {
            ifstream fin1;
            if (kol == 0) {
                for (int a = 0; a < vibor - 1; a++) {
                    cr = cr->adr;
                }

                fin1.open(cr->file.name, ios::in | ios::binary);
                if (fin1.is_open()) {
                    kol++;

                    visota = dlina();
                    system("cls");
                    pole(visota + 2, xx);
                    cr = spisok();
                    vivod(cr, 1);
                    fin1.close();
                }
                else {
                    cout << "Ошибкаааааааааааааааааа";
                    kol = 0;
                    break;
                }
                break;
            }
            ifstream fin2("122.txt", ios::in | ios::binary);
            kol = 0;
            if (fin1 && fin2)
            {
                char ch1, ch2;
                bool result = true;
                while (fin1.get(ch1) && fin2.get(ch2))
                {
                    if (ch1 != ch2)
                    {
                        result = false;
                        break;
                    }
                }
                if (result)
                    cout << "Equal" << endl;
                else
                    cout << "Unequal" << endl;
            }
            else {
                cout << "Error opening file!" << endl;
            }
            break;
        }*/

        case copy: {
            if (pol == 0) {
                for (int a = 0; a < vibor - 1; a++) {
                    cr = cr->adr;
                }
                name = cr->file.name;
                ifstream fin3(cr->file.name);
                if (fin3.is_open()) {
                    while (!fin3.eof()) {
                        getline(fin3, strh3);
                        str3 += strh3;
                        str3 += ' ';
                        if (!fin3.eof())
                            str3 += "\n";
                    }

                }
                gotoxy(0, visota + 10);
                cout << "ВЫБЕРИТЕ ПАПКУ КУДА ПОМЕСТИТЬ СКОПИРОВАННЫЙ ФАЙО И НАЖМИТЕ 1";
                pol++;
                break;
            }
            if (pol == 1) {
                FILE* file = fopen(name, "w");
                gotoxy(0, visota+11);
                cout << (file != NULL ? " ФАЙЛ СОЗДАН\n" : "Cannot create file\n");
                char* chap=new char;
                strcpy(chap, str3.c_str());
                bool ressult = fputs(chap, file);
                if (!ressult) {
                    cout << "Строка в файл успешно записана!";
                }
                pol= 0;
                fclose(file);
            }
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
