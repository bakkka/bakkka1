#include <iostream>
#include <stdio.h>
#include <math.h>
#include <conio.h>
#include <locale.h>
#include <windows.h>
#include <stdlib.h>

COORD coord = { 0,0 };
void gotoxy(int x, int y)
{
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
using namespace std;
void menu()
{
	system("cls");
	printf("������ ��������:\n");
	printf("1.��������\n");
	printf("2.���������\n");
	printf("3.���������\n");
	printf("4.�������\n");
	printf("5.������� �� ������� �����\n");
	printf("6.������ ����� � ������� 2 �����\n");
	printf("7.������� ������� ����� �� �������\n");
	printf("8.����� �� ���������\n");
	printf("9.������ ������ �����\n");
}

int main()
{
	setlocale(LC_ALL, "Rus");
nachalo:
	printf("������� ������ ����� : \n"); // ������ 2 �����
	long long int  num1 = 0, num2 = 0, num3 = 0, k = 0;
	int entered_num1 = 0, entered_num2 = 0, znak1 = 1, znak2 = 1;
	char simvol_code;
	bool exit = true;
	int punkti = 10;
	int vibor = 1;


	while (1)
	{
	start:
		simvol_code = _getch();
		if
			(simvol_code >= 48 && simvol_code <= 57)
		{
			int num = simvol_code - 48;
			printf("%d", num);

			if
				(!entered_num1) {
				num1 = num1 * 10 + (num * znak1);
				if
					(num1 >= 1000000) {
					printf("\n������� ������� �����, ������� ��� ���\n");
					num1 = 0;
					goto start;
				}
			}
			else
				if
					(!entered_num2) {
					num2 = num2 * 10 + (num * znak2);
					if
						(num2 >= 1000000) {
						printf("\n������� ������� �����, ������� ��� ���\n");
						num2 = 0;
						goto start;
					}
				}
					
					
						
		}
		else
			if
				(simvol_code == 32 || simvol_code == 13 || simvol_code == 189) // ������ ������� ��� ENTER � ������
			{
				if
					(simvol_code == 13){
					printf("\n������� ������ �����: ");
					printf("\n");
					}
				else
					printf(" ");
				if
					(!entered_num1)
					entered_num1 = 1;
				else
					if
						(!entered_num2)
					{
						entered_num2 = 1;
						while (exit) { //exit ��� ���������� ������ true
							menu();
							printf("\n ���� �����:\n");
							printf("%ld \n", num1);
							printf("%ld", num2);
							gotoxy(40, vibor);
							printf("<==");
							simvol_code = _getch();
							if (simvol_code == 224)
								simvol_code = _getch();
							switch (simvol_code) {
							case 72:vibor--;
								break;
							case 80:vibor++; break;
							case 13:
								if (vibor == 1) {
									printf("  %lld + %lld = %lld \n", num1, num2, num1 + num2);
									simvol_code = _getch();
									system("cls");
									break;
								}
								else
									if (vibor == 2) {
										printf("  %lld - %lld = %lld\n", num1, num2, num1 - (num2));
										simvol_code = _getch();
										system("cls");
										break;
									}
									else
										if (vibor == 3) {
											printf("  %lld * %lld = %lld\n", num1, num2, num1 * num2);
											simvol_code = _getch();
											system("cls");
											break;
										}
										else
											if (vibor == 4) {
												if (num2 == 0) {
													printf("  �� ���� ������ ������\n");
													simvol_code = _getch();
													system("cls");
		
													break;
												}
												if (num2 != 0)
													printf("  %lld / %lld = %lld\n", num1, num2, (num1) / (num2));
												simvol_code = _getch();
												system("cls");
												break;
											}
											else
												if (vibor == 5) {
													if (num1 < 0) {
														printf("  ������ ����� ������ �� �������������� �����");
														simvol_code = _getch();
														system("cls");
														break;
													}
													else
														printf("  sqrt(%lld) = %lf\n", num1, sqrt(num1));
													simvol_code = _getch();
													system("cls");
													break;
												}
												else
													if (vibor == 6) {
														printf("  %lld^%lld", num1, num2);
														
														if ((pow(num1, num2) > INT_MAX)) {
															gotoxy(55, 6);
															printf("������� �������  ��������,������� ����� ������� ");
															simvol_code = _getch();
															system("cls");
															break;
														}
														else
															if (num2 == 0)
																printf("=1");
															else
																if (num1 == 0)
																	printf("=0");
																else
															printf(" = %lld\n", num3 = pow(num1, num2));
														
														simvol_code = _getch();
														system("cls");
														break;
													
													}
													
													else
														if (vibor == 7) {
															if (num2 < 0) {
																printf("������ ��������� ������� ����� ������������� �����");
																simvol_code = _getch();
																system("cls");
																break;
															}
															printf("  %lld %% %lld = %lld\n", num1, num2, (num1 * num2) / 100);
															simvol_code = _getch();
															system("cls");
															break;
														}
														else
															if (vibor == 8) {
																system("cls");
																_exit(EXIT_SUCCESS);
															}
															else
																if (vibor == 9) {
																	system("cls");
																	goto nachalo;
																}

							case 49:
								gotoxy(40, 2);
								printf("   ");
								gotoxy(40, 3);
								printf("   ");
								gotoxy(40, 4);
								printf("   ");
								gotoxy(40, 5);
								printf("   ");
								gotoxy(40, 6);
								printf("   ");
								gotoxy(40, 7);
								printf("   ");
								gotoxy(40, 1);
								printf("<==");
								printf("  %lld + %lld = %lld \n", num1, num2, num1 + num2);
								simvol_code = _getch();
								system("cls");
								break;

							case 50:
								gotoxy(40, 1);
								printf("   ");
								gotoxy(40, 3);
								printf("   ");
								gotoxy(40, 4);
								printf("   ");
								gotoxy(40, 5);
								printf("   ");
								gotoxy(40, 6);
								printf("   ");
								gotoxy(40, 7);
								printf("   ");
								gotoxy(40, 2);
								printf("<==");
								printf("  %lld - %lld = %lld\n", num1, num2, num1 - (num2));
								simvol_code = _getch();
								system("cls");
								break;
							case 51:
								gotoxy(40, 1);
								printf("   ");
								gotoxy(40, 2);
								printf("   ");
								gotoxy(40, 4);
								printf("   ");
								gotoxy(40, 5);
								printf("   ");
								gotoxy(40, 6);
								printf("   ");
								gotoxy(40, 7);
								printf("   ");
								gotoxy(40, 3);
								printf("<==");
								printf("  %lld * %lld = %lld\n", num1, num2, num1* num2);
								simvol_code = _getch();
								system("cls");
								break;
							case 52:
								gotoxy(40, 1);
								printf("   ");
								gotoxy(40, 2);
								printf("   ");
								gotoxy(40, 3);
								printf("   ");
								gotoxy(40, 5);
								printf("   ");
								gotoxy(40, 6);
								printf("   ");
								gotoxy(40, 7);
								printf("   ");
								gotoxy(40, 4);
								printf("<==");
								if (num2 == 0) {
									printf("  �� ���� ������ ������\n");
									simvol_code = _getch();
									system("cls");
									break;
								}
								if (num2 != 0)
									printf("  %lld / %lld = %lld\n", num1, num2, (num1) / (num2));
								simvol_code = _getch();
								system("cls");
								break;
							case 53:
								gotoxy(40, 1);
								printf("   ");
								gotoxy(40, 2);
								printf("   ");
								gotoxy(40, 3);
								printf("   ");
								gotoxy(40, 4);
								printf("   ");
								gotoxy(40, 6);
								printf("   ");
								gotoxy(40, 7);
								printf("   ");
								gotoxy(40, 5);
								printf("<==");
								if (num1 < 0) {
									printf("  ������ ����� ������ �� �������������� �����");
									simvol_code = _getch();
									system("cls");
									break;
								}
								else
									printf("  sqrt(%lld) = %lf\n", num1, sqrt(num1));
								simvol_code = _getch();
								system("cls");
								break;
							case 54:
								gotoxy(40, 1);
								printf("   ");
								gotoxy(40, 2);
								printf("   ");
								gotoxy(40, 3);
								printf("   ");
								gotoxy(40, 4);
								printf("   ");
								gotoxy(40, 5);
								printf("   ");
								gotoxy(40, 7);
								printf("   ");
								gotoxy(40, 6);
								printf("<==");
								printf("  %lld^%lld", num1, num2);
								if ((pow(num1, num2) > INT_MAX)) {
									gotoxy(55, 6);
									printf("������� �������  ��������,������� ����� ������� ");
									simvol_code = _getch();
									system("cls");
									break;
								}
								else 
									if (num2 == 0)
										printf("=1");
									else
										if (num1 == 0)
											printf("=0");
										else
											printf(" = %lld\n", num3 = pow(num1, num2));

									simvol_code = _getch();
									system("cls");
									break;
							case 55:
								gotoxy(40, 1);
								printf("   ");
								gotoxy(40, 2);
								printf("   ");
								gotoxy(40, 3);
								printf("   ");
								gotoxy(40, 4);
								printf("   ");
								gotoxy(40, 5);
								printf("   ");
								gotoxy(40, 6);
								printf("   ");
								gotoxy(40, 7);
								printf("<==");
								if (num2 < 0) {
									printf("������ ��������� ������� ����� ������������� �����");
									simvol_code = _getch();
									system("cls");
									goto nachalo;
								}
								printf("  %lld %% %lld = %lld\n", num1, num2, (num1 * num2) / 100);
								simvol_code = _getch();
								system("cls");
								break;
							case 56:
								system("cls");
								_exit(EXIT_SUCCESS);
							case 57:
								system("cls");
								goto nachalo;

							}
							
							if (vibor < 1)
								vibor = 9
								;
							if (vibor > punkti - 1)
								vibor = 1;
							
						}
					}
			}
			else
				if
					(simvol_code == 45) {
					printf("-");
					if
						(!entered_num1)
					{
						znak1 *= -1;
					}
					else
						if
							(!entered_num2)
						{
							znak2 *= -1;
						}
				}
				else
					if (simvol_code == 8) {
						if (!entered_num1) {
							printf("\b \b");
							num1 = num1 / 10;
							if (num1 == 0)
								znak1 = 1;
						}
						
						else
							if (!entered_num2) {
								printf("\b \b");
								num2 = num2 / 10;
								if (num2 == 0)
									znak2 = 1;
							}
					}
				

	}
	printf("\n");
	return 0;
}