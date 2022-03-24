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

int pos;
string vvod() {
    string x = "";
    int t;
    char a;

    bool exit = true;

    do {
        a = _getch();

        if (a >= 48 && a <= 57) {
            t = a - 48;
            cout << t;
            x += to_string(t);
            
        }
        switch (a) {
            case 8:
                cout << "\b \b";
                pos = x.size();
                x.erase(pos-1);
                break;
            case 9:
                a = _getch();
                if (a != 224) {
                    switch (a) {
                    case 54:
                        cout << "^";
                        x += '^';
                        break;
                    case 56:
                        cout << "*";
                        x += '*';
                        break;
                    case 57:
                        cout << "(";
                        x += '(';
                        break;
                    case 48:
                        cout << ")";
                        x += ')';
                        break;
                    case 47:
                        cout << "/";
                        x += '/';
                        break;
                    case 61:
                        cout << "+";
                        x += '+';
                        break;
                    case 45:
                        cout << "-";
                        x += '-';
                        break;
                    }
                }
                
        }
        
          
        
    } while (a != 13);
    if (x.empty())
        cout << endl;
        cout << endl;
        
        return x;
       
       
}

int main() {

	setlocale(LC_ALL, "RUS");
	const int max_length = 100;
	int variable[max_length];
    int buff_1=0,buff_2=0;
    char znaki[max_length];
    int marker = 0;
    int position_znak = 0;
    int position_variable = 0;
    string sign = "+-*/()^";
    string input, buff_string;
    char plus = '+',
        minus = '-',
        multiply = '*',
        divide = '/',
        left_bracket = '(',
        right_bracket = ')',
        extent = '^';

	cout << "Введите пример: " << endl;
    input = vvod();
    for (int i = 0; i <= input.length(); ++i) { //проверка на знаки в строке
        for (int j = 0; j < 7; ++j) {
            if ((input[i] != sign[j]) && marker<7) {
                marker++;
            }
            else
                if (input[i] == sign[j]) {
                    znaki[position_znak] = sign[j]; 
                    position_znak++;
                }
                
               
            }
        }
    for (int i = 0; i < 7; i++) {
        cout<<znaki[i];
    }
	return 0;
}
