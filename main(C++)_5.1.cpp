//                          ����.�������� - ��������������� ���������������� �� C++.
//                                       ������ 5. ������� �������.
//                                          �������� ������� �1.
// ���������� ��������� ������� ��� ������ ���������, ��������, ���������� ������� 
// (����� ���������� ����������), ��������� ������ � �������, ������ �������� ������� �� ���������� ��������.
#include <iostream>
#include <windows.h>
#include <time.h>
#include "class_Array.h"
using namespace std;

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand((size_t)time(0));
	int a = -1, vyb = 0;
	char str [] = "abcdefghijklmnopqrstuvwxyz";
	int i=0, f=0; double d=0; unsigned char c=0;
	size_t n=0, pos=0;
	Array <int> *arr1 = NULL;
	Array <double> *arr2 = NULL;
	Array <char> *arr3 = NULL;
	do {
		cout << "���������� ������ ������ � ������\n";
		cout << "�������� ������ �����:\n";
		cout << "1 - ������ ����;\n";
		cout << "2 - �������������� ����.\n";
		cout << "��� �����: ";
		cin >> vyb;
		if (vyb < 1 || vyb>2) {
			while (cin.get() != '\n');
			cout << "�������! ��������� ����!\n";
			system("pause");
			system("cls");
		}
	} while (vyb < 1 || vyb>2);
	switch (vyb)
	{
		// ������ ����
	case 1:
		system("cls");
		do {
			choice(vyb, "�����");
			if (vyb == 1) {
				arr1 = new Array <int>;
				arr1->init_size();
				arr1->init_arr();
				cout << "������ � ������ �������������� ���� int ������� �������!\n\n";
				system("pause");
			}
			if (vyb == 2) {
				arr2 = new Array <double>;
				arr2->init_size();
				arr2->init_arr();
				cout << "������ � ������ ������������� ���� double ������� �������!\n\n";
				system("pause");
			}
			if (vyb == 3) {
				arr3 = new Array <char>;
				arr3->init_size();
				arr3->init_arr();
				cout << "������ � ������ ����������� ���� char ������� �������!\n\n";
				system("pause");
			}
			system("cls");
		} while (vyb != 0);
		break;
		// �������������� ����
	case 2:
		system("cls");
		arr1 = new Array <int>(20, 50, 0, 1);
		cout << "������ � ������ �� 20 ��������� �������������� ���� int ������� �������!\n\n";
		arr2 = new Array <double>(20, 50, 0, 0.99);
		cout << "������ � ������ �� 20 ��������� ���� ������������� double ������� �������!\n\n";
		arr3 = new Array <char>(str);
		cout << "������ � ������ ����������� ���� char ������� �������!\n\n";
		system("pause");
		break;
	default:
		while (cin.get() != '\n');
		cout << "�������! ��������� ����!\n";
	}
	while (a) {
		int menu = -1;
		system("cls");
		cout << "1 - �������� ����������� ��������\n";
		cout << "2 - ���������� �������� � ������\n";
		cout << "3 - �������� �������� �� �������\n";
		cout << "4 - ���������� ��������� � �������\n";
		cout << "5 - ����� ������������ �������� � �������\n";
		cout << "6 - ����� ������������� �������� � �������\n";
		cout << "7 - �������� ����� � �������\n";
		cout << "8 - ������ �������� �������\n";
		cout << "0 - �����\n";
		cout << "��� �����: ";
		cin >> menu;
		switch (menu)
		{
		case 1:
			system("cls");
			do {
				choice(vyb, "�����");
				if (vyb == 1) {
					cout << "\n������ ���� int \n";
					if (arr1 != NULL) {
						cout << "������� ���������� ������� ��� ����������� �������: ";
						cin >> n;
						arr1->show_Arr(n);
					}
					else cout << "�� ���������������!\n";
					system("pause");
				}
				if (vyb == 2) {
					cout << "\n������ ���� double \n";
					if (arr2 != NULL) {
						cout << "������� ���������� ������� ��� ����������� �������: ";
						cin >> n;
						arr2->show_Arr(n);
					}
					else cout << "�� ���������������!\n";
					system("pause");
				}
				if (vyb == 3) {
					cout << "\n������ ���� char \n";
					if (arr3 != NULL) {
						cout << "������� ���������� ������� ��� ����������� �������: ";
						cin >> n;
						arr3->show_Arr(n);
					}
					else cout << "�� ���������������!\n";
					system("pause");
				}
				system("cls");
			} while (vyb != 0);
			break;
		case 2:
			system("cls");
			do {
				choice(vyb, "�����");
				if (vyb == 1) {
					cout << "\n������ ���� int \n";
					if (arr1 != NULL) {
						arr1->show_Arr(10);
						cout << "������� ����� ������� ������ ��������: ";
						cin >> pos;
						cout << "\n������� �������� ������ �������� ������� ���� int: ";
						cin >> i;
						arr1->add(i, pos);
						arr1->show_Arr(10);
					}
					else cout << "�� ���������������!\n";
					system("pause");
				}
				if (vyb == 2) {
					cout << "\n������ ���� double \n";
					if (arr2 != NULL) {
						arr2->show_Arr(10);
						cout << "������� ����� ������� ������ ��������: ";
						cin >> pos;
						cout << "\n������� �������� ������ �������� ������� ���� double: ";
						cin >> d;
						arr2->add(d, pos);
						arr2->show_Arr(10);
					}
					else cout << "�� ���������������!\n";
					system("pause");
				}
				if (vyb == 3) {
					cout << "\n������ ���� char \n";
					if (arr3 != NULL) {
						arr3->show_Arr(10);
						cout << "������� ����� ������� ������ ��������: ";
						cin >> pos;
						cout << "\n������� �������� ������ �������� ������� ���� char: ";
						cin >> c;
						arr3->add(c, pos);
						arr3->show_Arr(10);
					}
					else cout << "�� ���������������!\n";
					system("pause");
				}
				system("cls");
			} while (vyb != 0);
			break;
		case 3:
			system("cls");
			do {
				choice(vyb, "�����");
				if (vyb == 1) {
					cout << "\n������ ���� int \n";
					if (arr1 != NULL) {
						arr1->show_Arr(10);
						cout << "������� ����� ������� ���������� ��������: ";
						cin >> pos;
						arr1->del(pos);
						cout << "\n����� ������:\n";
						arr1->show_Arr(10);
					}
					else cout << "�� ���������������!\n";
					system("pause");
				}
				if (vyb == 2) {
					cout << "\n������ ���� double \n";
					if (arr2 != NULL) {
						arr2->show_Arr(10);
						cout << "������� ����� ������� ���������� ��������: ";
						cin >> pos;
						arr2->del(pos);
						cout << "\n����� ������:\n";
						arr2->show_Arr(10);
					}
					else cout << "�� ���������������!\n";
					system("pause");
				}
				if (vyb == 3) {
					cout << "\n������ ���� char \n";
					if (arr3 != NULL) {
						arr3->show_Arr(10);
						cout << "������� ����� ������� ���������� ��������: ";
						cin >> pos;
						arr3->del(pos);
						cout << "\n����� ������:\n";
						arr3->show_Arr(10);
					}
					else cout << "�� ���������������!\n";
					system("pause");
				}
				system("cls");
			} while (vyb != 0);
			break;
		case 4:
			system("cls");
			do {
				choice(vyb, "�����");
				if (vyb == 1) {
					cout << "\n������ ���� int \n";
					if (arr1 != NULL) {
						arr1->show_Arr(10);
						arr1->sort();
						cout << "����� ���������� �������:\n";
						arr1->show_Arr(10);
					}
					else cout << "�� ���������������!\n";
					system("pause");
				}
				if (vyb == 2) {
					cout << "\n������ ���� double \n";
					if (arr2 != NULL) {
						arr2->show_Arr(10);
						arr2->sort();
						cout << "����� ���������� �������:\n";
						arr2->show_Arr(10);
					}
					else cout << "�� ���������������!\n";
					system("pause");
				}
				if (vyb == 3) {
					cout << "\n������ ���� char \n";
					if (arr3 != NULL) {
						arr3->show_Arr(10);
						arr3->sort();
						cout << "����� ���������� �������:\n";
						arr3->show_Arr(10);
					}
					else cout << "�� ���������������!\n";
					system("pause");
				}
				system("cls");
			} while (vyb != 0);
			break;
		case 5:
			system("cls");
			do {
				choice(vyb, "�����");
				if (vyb == 1) {
					cout << "\n������ ���� int \n";
					if (arr1 != NULL) {
						arr1->show_Arr(10);
						cout << "����������� �������� � �������: " << arr1->arr_Min() << "\n\n";
					}
					else cout << "�� ���������������!\n";
					system("pause");
				}
				if (vyb == 2) {
					cout << "\n������ ���� double \n";
					if (arr2 != NULL) {
						arr2->show_Arr(10);
						cout << "����������� �������� � �������: " << arr2->arr_Min() << "\n\n";
					}
					else cout << "�� ���������������!\n";
					system("pause");
				}
				if (vyb == 3) {
					cout << "\n������ ���� char \n";
					if (arr3 != NULL) {
						arr3->show_Arr(10);
						cout << "����������� �������� � �������: " << arr3->arr_Min() << "\n\n";
					}
					else cout << "�� ���������������!\n";
					system("pause");
				}
				system("cls");
			} while (vyb != 0);
			break;
		case 6:
			system("cls");
			do {
				choice(vyb, "�����");
				if (vyb == 1) {
					cout << "\n������ ���� int \n";
					if (arr1 != NULL) {
						arr1->show_Arr(10);
						cout << "������������ �������� � �������: " << arr1->arr_Max() << "\n\n";
					}
					else cout << "�� ���������������!\n";
					system("pause");
				}
				if (vyb == 2) {
					cout << "\n������ ���� double \n";
					if (arr2 != NULL) {
						arr2->show_Arr(10);
						cout << "������������ �������� � �������: " << arr2->arr_Max() << "\n\n";
					}
					else cout << "�� ���������������!\n";
					system("pause");
				}
				if (vyb == 3) {
					cout << "\n������ ���� char \n";
					if (arr3 != NULL) {
						arr3->show_Arr(10);
						cout << "������������ �������� � �������: " << arr3->arr_Max() << "\n\n";
					}
					else cout << "�� ���������������!\n";
					system("pause");
				}
				system("cls");
			} while (vyb != 0);
			break;
		case 7:
			system("cls");
			do {
				choice(vyb, "�����");
				if (vyb == 1) {
					cout << "\n������ ���� int \n";
					if (arr1 != NULL) {
						arr1->show_Arr(10);
						cout << "\n������� ������� �������: ";
						cin >> i;
						arr1->binary_search(i, f);
						find(f);
					}
					else cout << "�� ���������������!\n";
					system("pause");
				}
				if (vyb == 2) {
					cout << "\n������ ���� double \n";
					if (arr2 != NULL) {
						arr2->show_Arr(10);
						cout << "\n������� ������� �������: ";
						cin >> d;
						arr2->binary_search(d, f);
						find(f);
					}
					else cout << "�� ���������������!\n";
					system("pause");
				}
				if (vyb == 3) {
					cout << "\n������ ���� char \n";
					if (arr3 != NULL) {
						arr3->show_Arr(10);
						cout << "\n������� ������� �������: ";
						cin >> c;
						arr3->binary_search(c, f);
						find(f);
					}
					else cout << "�� ���������������!\n";
					system("pause");
				}
				system("cls");
			} while (vyb != 0);
			break;
		case 8:
			system("cls");
			do {
				choice(vyb, "�����");
				if (vyb == 1) {
					cout << "\n������ ���� int \n";
					if (arr1 != NULL) {
						arr1->show_Arr(10);
						arr1->change(i, n);
						cout << "������ ��������� �������!\n";
					}
					else cout << "�� ���������������!\n";
					system("pause");
				}
				if (vyb == 2) {
					cout << "\n������ ���� double \n";
					if (arr2 != NULL) {
						arr2->show_Arr(10);
						arr2->change(d, n);
						cout << "������ ��������� �������!\n";
					}
					else cout << "�� ���������������!\n";
					system("pause");
				}
				if (vyb == 3) {
					cout << "\n������ ���� char \n";
					if (arr3 != NULL) {
						arr3->show_Arr(10);
						arr3->change(c, n);
						cout << "������ ��������� �������!\n";
					}
					else cout << "�� ���������������!\n";
					system("pause");
				}
				system("cls");
			} while (vyb != 0);
			break;
			system("pause");
			break;
		case 0:
			if (arr1 != NULL) delete arr1;
			if (arr2 != NULL) delete arr2;
			if (arr3 != NULL) delete arr3;
			quit();
			break;
		default:
			while (cin.get() != '\n');
			cout << "�������! ��������� ����!\n";
		}
	}
	system("pause");
	return 0;
}
