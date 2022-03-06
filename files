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
};
COORD coord = { 0,0 };
void gotoxy(int x, int y)
{
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
const char* katalog = "D:\\";
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
            cur->name = file.name;
            next = cur;
        } while (_findnext(File, &file) == 0);
        _findclose(File);

       
    }
    return cur;
}
void vivod(Dict* spisok) {
    Dict* start = spisok;
    int a = dlina();
    for (int i = 0; i < a; i++) {
        cout << start->name << endl;
        start = start->adr;
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
int main()
{   
    setlocale(LC_ALL, "RUSSIAN");
    bool exit = true;
    char vibor = 1;
    int code_simvola;
    Dict* cr=0;
    const int up = 72;
    const int down = 80;
    const int enter = 13;
    const int esc = 27;
    _chdir(katalog);
    cout << "D:" << endl;
    cr=spisok();
    vivod(cr);
    int visota = dlina();
    while (exit) {
        gotoxy(35, vibor);
        printf("<==");
        code_simvola = _getch();
        if (code_simvola == 224)
            code_simvola = _getch();
        switch (code_simvola) {
        case up:vibor--;
            gotoxy(35, vibor + 1);
            cout << "   ";
            break;
        case down:vibor++;
            gotoxy(35, vibor - 1);
            cout << "   ";
            break;
        case enter:
            for (int a = 0; a < vibor; a++) {             
                cr = cr->adr;
            }
            system("cls");           
            _chdir(file.name);
            cr = spisok();
            vivod(cr);
            break;
        case esc:
            system("cls");
            _chdir(katalog);
            cr = spisok();
            vivod(cr);
            break;
        }
        if (vibor < 1)
            vibor = visota-1;
        if (vibor > visota-1)
            vibor = 1;
    }
    
  
        

    return 0;
}
