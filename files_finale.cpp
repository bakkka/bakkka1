
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
#include <cstring>
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
char a(178);
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
char xxx = (22);
char xx = (1958);
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
                    cout << xx;
                }
                cout <<" ";
            }
            else
                if (j == 0 || j == (xc - 1))
                    cout <<xx;
                else
                    if (i == 0 || i == (yc - 1))
                        cout <<xxx;               
        }
        cout << endl;       
    }
    cout << "ENTER-ОТКРЫТЬ ПАПКУ" << endl;
    cout << "ESC-ПРОСМОТР ФАЙЛА" << endl;
    cout << "BACKSPACE-ВЕРНУТЬСЯ НАЗАД" << endl;
    cout << "ВЫБЕРИТЕ ФАЙЛЫ ДЛЯ СРАВНЕНИЕ И НАЖМИТЕ ПРОБЕЛ" << endl;
    cout << "ВЫБЕРИТЕ ФАЙЛ ДЛЯ КОПИРОВАНИЯ И НАЖМИТЕ 1" << endl;
    cout << "TAB-СОЗДАНИЕ ФАЙЛА В ДАННОЙ ПАПКЕ"; 
    cout << "\n\n"; 
}
int main()
{
    setlocale(LC_ALL, "RUSSIAN");
    nachalo:
    system("cls");
    bool exit = true;
    char vibor = 1;
    int x = 1, y = 1;
    int yy = 60, xx = 130;
    int code_simvola;
    Dict* cr = 0;
    Dict* back = 0;
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
    int proverka;
    char* backk=new char;
    int num = 0;
    int prev_vibor;
    int visota_prev;
    int size1, size2;
    string strh,strh3;
    string str,str3;
    string str1, str2;
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
            num++;
            raz = 0;
            if (num != 0) {
                _chdir(backk);
                cr = spisok();
            }
            for (int a = 0; a < vibor - 1; a++) {
                cr = cr->adr;
            }
            if (num == 1) {
                backk = cr->file.name;
            }
            proverka=_chdir(cr->file.name);
            if (proverka == -1) {
                goto nachalo;
            }
            cr = spisok();
            visota_prev = visota;
            visota = dlina();
            if (visota_prev > visota) {
                visota = visota_prev;
            }
            system("cls");
            pole(visota + 2, xx);
            cout << "ОТКРЫТАЯ ПАПКА:" << cr->file.name;           
            _chdir("..\\");
            cr = spisok();
            vivod(cr, 1);
            for (int a = 0; a < vibor - 1; a++) {
                cr = cr->adr;
            }
            _chdir(cr->file.name);
            cr = spisok();
           
            visota = dlina();
            vivod(cr, 66);
            strelka = 115;       
            break;
        case backspace:
            if (num != 0) {              
                _chdir("..\\");
                raz = 0;              
                visota = dlina();
                system("cls");
                pole(visota + 2, xx);
                cr = spisok();
                
                strelka = 55;
                if (num != 1) {
                    vivod(cr, 66);
                    strelka = 115;
                }
                _chdir("..\\");
                cr = spisok();
                vivod(cr, 1);              
                num--;
            }
            break;
        case esc:
            if (raz == 0) {
                raz = 1;
                _chdir(backk);
                cr = spisok();
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
            _chdir(backk);
            cr = spisok();
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
            vivod(cr, 66);
            _chdir("..\\");
            cr = spisok();
            vivod(cr, 1);
        }
            break;       
        case space:
        {          
            _chdir(backk);
            cr = spisok();
            ifstream fin1;
            if (kol == 0) {
                prev_vibor = vibor;
                for (int a = 0; a < vibor - 1; a++) {
                    cr = cr->adr;                       //ИДУ ДО ВЫБРАННОГО АДРЕССА
                }
                kol++;
                fin1.open(cr->file.name); // ОТКРЫВАЮТ ФАЙЛ ПЕРВЫЙ ПО ВЫБРАНООМУ ФАЙЛУ
                if (fin1.is_open()) {   //ПРОВЕРКА ОТКРЫТ ЛИ ФАЙЛ                
                    while (!fin1.eof()) {
                        getline(fin1, strh);
                        str1 += strh;
                        str1 += ' ';
                        if (!fin1.eof())
                            str1 += "\n";
                    }                   
                }                              
                break;
            }
            ifstream fin2;
            if (prev_vibor < vibor) {
                vibor = vibor - prev_vibor + 1;
            }
            if (kol == 1) {               
                for (int a = 0; a < vibor - 1; a++) {
                    cr = cr->adr;                        //ИДУ ДО ВЫБРАННОГО АДРЕССА
                }
                fin2.open(cr->file.name);                   // ОТКРЫВАЮТ ФАЙЛ ПЕРВЫЙ ПО ВЫБРАНООМУ ФАЙЛУ
                if (fin2.is_open()) {                    //ПРОВЕРКА ОТКРЫТ ЛИ ФАЙЛ
                    while (!fin2.eof()) {
                        getline(fin2, strh);
                        str2 += strh;
                        str2 += ' ';
                        if (!fin2.eof())
                            str2 += "\n";
                    }
                }
            }
            if (str1 != str2) {
                gotoxy(66, visota + 2);
                cout << "non equal";
            }
            else {
                gotoxy(66, visota + 2);
                cout << "equal";
            }
            str1 = "";
            str2 = "";
            fin1.close();
            fin2.close();          
            kol = 0;
            int aa = _getch();
            system("cls");
            pole(visota + 2, xx);
            _chdir(cr->file.name);
            cr = spisok();
            visota = dlina();
            vivod(cr, 66);
            strelka = 115;
            _chdir("..\\");
            cr = spisok();
            vivod(cr, 1);
        }
            break;     
        case copy: {
            _chdir(backk);
            cr = spisok();
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
                gotoxy(0, visota+17);
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
