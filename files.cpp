
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
    cout << "TAB-СОЗДАНИЕ ФАЙЛА В ДАННОЙ ПАПКЕ" << endl;
    cout << "НАЖМИТЕ 2 ДЛЯ СОЗДАНИЯ ПАПКИ" << endl;
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
    char* folder_name = new char;
    start:
    while (exit) {     
        gotoxy(strelka, vibor);
       
            printf("<==");
        
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
            if (pol == 1) {
                pol++;
            }
            num++;
            raz = 0;
            if (num > 1) {
                _chdir(backk);
                cr = spisok();
            }
            for (int a = 0; a < vibor - 1; a++) {
                cr = cr->adr;
            }
            if (num == 1) {
                backk = cr->file.name;
            }
            proverka = _chdir(cr->file.name);
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
            if (pol == 1) {
                pol++;
            }
            if (num == 1) {
                system("cls");
                       
                _chdir(katalog);
                cr = spisok();
                visota = dlina();
                pole(visota + 2, xx);
                vivod(cr, 1);
                strelka = 55;
                num--;
            }
            if (num >1 && raz!=1) {
                _chdir("..\\");
                raz = 0;
                cr = spisok();
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
                visota = dlina();
                if (visota < visota_prev) {
                    visota = visota_prev;
                    system("cls");
                    pole(visota + 2, xx);
                    _chdir(backk);
                    cr = spisok();
                    vivod(cr, 66);
                    
                    strelka = 115;
                    _chdir("..\\");
                }
                
                cr = spisok();
                vivod(cr, 1);
                num--;
            }
            if (num > 1 && raz == 1) {
                _chdir("..\\");
                raz = 0;
                cr = spisok();
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
                visota = dlina();
                if (visota < visota_prev) {
                    visota = visota_prev;
                    system("cls");
                    pole(visota + 2, xx);
                    _chdir(backk);
                    cr = spisok();
                    visota = dlina();
                    vivod(cr, 66);
                    strelka = 115;
                    _chdir("..\\");
                }
                else {
                    system("cls");
                    pole(visota + 2, xx);
                    _chdir(backk);
                    cr = spisok();
                    visota = dlina();
                    vivod(cr, 66);
                    strelka = 115;
                    _chdir("..\\");
                }
                cr = spisok();
                vivod(cr, 1);
                num--;
            }
            break;
        case esc:
            if ( num==1) {
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
                int a = _getch();
                system("cls");
                pole(visota + 2, xx);
                _chdir(backk);
                cr = spisok();
                visota = dlina();
                vivod(cr, 66);
                strelka = 115;
                printf("<==");
                _chdir("..\\");
                cr = spisok();
                
                if (visota < visota_prev) {
                    visota = visota_prev;
                    system("cls");
                    pole(visota + 2, xx);
                    _chdir(backk);
                    cr = spisok();
                    visota = dlina();
                    vivod(cr, 66);
                    strelka = 115;
                    _chdir("..\\");
                }
                cr = spisok();
                vivod(cr, 1);
            }
            else {
                if ( num >= 2) {
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
                    int a = _getch();
                    system("cls");
                    pole(visota + 2, xx);
                    _chdir(backk);
                    cr = spisok();
                    visota = dlina();

                    strelka = 115;
                    printf("<==");


                    if (visota < visota_prev) {
                        visota = visota_prev;
                        system("cls");
                        pole(visota + 2, xx);
                        _chdir(backk);
                        cr = spisok();
                        vivod(cr, 66);
                        strelka = 115;
                        _chdir("..\\");
                    }
                    cr = spisok();
                    vivod(cr, 1);
                }
            }  
                break;
        case tab:
        {
            int err=1;
            _chdir(backk);
            cr = spisok();
            gotoxy(66, visota + 13);
            cout << "Введите имя файла, который хотите создать: ";
            cin >> papka;
            while (strlen(papka) > 49) {
                cout << "Too long name";
                char *gets(papka);
            }
            strcat(papka, ".txt");
         
            for (int a = 0; a < dlina()-1; a++) {
                cr = cr->adr;
                int res;
                res = strcmp(papka, cr->file.name);

                if (!res) {
                    gotoxy(66, visota + 14);
                    cout << "Такое названии уже есть";
                    err = 2;
                    break;
                }
            }
            if (err != 2) {
                
                FILE* filee = fopen(papka, "w");
                if (filee) {
                    gotoxy(66, visota + 10);
                    cout << "file created";
                }
                else {
                    gotoxy(66, visota + 10);
                    cout << "error";
                }

                fclose(filee);

                int a = _getch();
                system("cls");
                if (visota < visota_prev) {
                    pole(visota_prev + 2, xx);
                }
                else {
                    pole(visota + 2, xx);
                }
                _chdir(backk);
                cr = spisok();
                visota = dlina();
                vivod(cr, 66);
                strelka = 115;
                _chdir("..\\");
                if (visota < visota_prev) {
                    visota = visota_prev;
                    system("cls");
                    pole(visota + 2, xx);
                    _chdir(backk);
                    cr = spisok();
                    vivod(cr, 66);
                    strelka = 115;
                    _chdir("..\\");
                }

                cr = spisok();
                vivod(cr, 1);

            }
        }
            break;
        case space:
        {   
            raz = 1;
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
                if (visota >= visota_prev) {
                    gotoxy(66, visota + 2);
                    cout << "non equal";
                }
                else {
                    gotoxy(66, visota_prev + 2);
                    cout << "non equal";
                }
            }
            else {
                if (visota >= visota_prev) {
                    gotoxy(66, visota + 2);
                    cout << "equal";
                }
                else {
                    gotoxy(66, visota_prev + 2);
                    cout << "non equal";
                }
                
            }
            str1 = " ";
            str2 = " ";
            fin1.close();
            fin2.close();          
            kol = 0;
            int aa = _getch();
            
            system("cls");
            pole(visota + 2, xx);
            _chdir(backk);
            cr = spisok();
            visota = dlina();
            vivod(cr, 66);
            strelka = 115;

            if (visota < visota_prev) {
                visota = visota_prev;
                system("cls");
                pole(visota + 2, xx);
                _chdir(backk);
                cr = spisok();
                vivod(cr, 66);
                strelka = 115;
                _chdir("..\\");
            }
            cr = spisok();
            vivod(cr, 1);
        }
         break;     
        case copy: {
            raz = 1;
            int errr=1;
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
                gotoxy(66, visota + 10);
                cout << "ВЫБЕРИТЕ ДРУГУЮ ПАПКУ КУДА ПОМЕСТИТЬ СКОПИРОВАННЫЙ ФАЙЛ И НАЖМИТЕ 1";
                pol++;
                break;
            }
            if (pol == 2) {
               
                int len = dlina();
                for (int a = 0; a < len-1; a++) {
                    cr = cr->adr;
                    int res;
                    res = strcmp(name, cr->file.name);

                    if (!res) {
                        gotoxy(66, visota + 3);
                        cout << "Такое названии уже есть";
                        errr = 2;
                        break;
                    }
                }
                if (errr != 2) {
                    FILE* file = fopen(name, "w");
                    gotoxy(66, visota + 14);
                    cout << (file != NULL ? " ФАЙЛ СОЗДАН\n" : "Cannot create file\n");
                    char* chap = new char;
                    strcpy(chap, str3.c_str());
                    bool ressult = fputs(chap, file);
                    fclose(file);
                    if (!ressult) {
                        cout << "Строка в файл успешно записана!";
                    }
                }
                pol= 0;
               
                int aa = _getch();
                system("cls");
                pole(visota + 2, xx);
                _chdir(backk);
                cr = spisok();
                visota = dlina();
                vivod(cr, 66);
                strelka = 115;
                
                if (visota < visota_prev) {
                    visota = visota_prev;
                    system("cls");
                    pole(visota + 2, xx);
                    _chdir(backk);
                    cr = spisok();
                    vivod(cr, 66);
                    strelka = 115;
                    _chdir("..\\");
                }
                cr = spisok();
                vivod(cr, 1);
            }
        }
            break;  
        case 50:
            gotoxy(60, visota+11);
            cout << "Введите название папки: ";
            cin >> folder_name;
            
            if (!_mkdir(folder_name)) {
                    gotoxy(60, visota+12);
                    cout << "Папка успешно созданна";
            }
            else {
                gotoxy(60, visota+12);
                cout << "Ошибка";
            }
            
            int B = _getch();
            system("cls");
            pole(visota + 2, xx);
            _chdir(backk);
            cr = spisok();
            visota = dlina();
            vivod(cr, 66);
            strelka = 115;
            _chdir("..\\");
            if (visota < visota_prev) {
                visota = visota_prev;
                system("cls");
                pole(visota + 2, xx);
                _chdir(backk);
                cr = spisok();
                vivod(cr, 66);
                strelka = 115;
                _chdir("..\\");
            }
            cr = spisok();
            vivod(cr, 1);
            break;
        }
        if (vibor < 1)
            vibor = visota ;
        if (vibor > visota)
            vibor = 1;
    }
    return 0;
}
