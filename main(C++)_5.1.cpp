//                          Курс.Объектно - ориентированное программирование на C++.
//                                       Модуль 5. Шаблоны функций.
//                                          Домашнее задание №1.
// Реализуйте шаблонные функции для поиска максимума, минимума, сортировки массива 
// (любым алгоритмом сортировки), двоичного поиска в массиве, замены элемента массива на переданное значение.
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
		cout << "Необходимо ввести данные в массив\n";
		cout << "Выберите способ ввода:\n";
		cout << "1 - ручной ввод;\n";
		cout << "2 - автоматический ввод.\n";
		cout << "Ваш выбор: ";
		cin >> vyb;
		if (vyb < 1 || vyb>2) {
			while (cin.get() != '\n');
			cout << "Неверно! Повторите ввод!\n";
			system("pause");
			system("cls");
		}
	} while (vyb < 1 || vyb>2);
	switch (vyb)
	{
		// ручной ввод
	case 1:
		system("cls");
		do {
			choice(vyb, "далее");
			if (vyb == 1) {
				arr1 = new Array <int>;
				arr1->init_size();
				arr1->init_arr();
				cout << "Данные в массив целочисленного типа int внесены успешно!\n\n";
				system("pause");
			}
			if (vyb == 2) {
				arr2 = new Array <double>;
				arr2->init_size();
				arr2->init_arr();
				cout << "Данные в массив вещественного типа double внесены успешно!\n\n";
				system("pause");
			}
			if (vyb == 3) {
				arr3 = new Array <char>;
				arr3->init_size();
				arr3->init_arr();
				cout << "Данные в массив символьного типа char внесены успешно!\n\n";
				system("pause");
			}
			system("cls");
		} while (vyb != 0);
		break;
		// автоматический ввод
	case 2:
		system("cls");
		arr1 = new Array <int>(20, 50, 0, 1);
		cout << "Данные в массив на 20 элементов целочисленного типа int внесены успешно!\n\n";
		arr2 = new Array <double>(20, 50, 0, 0.99);
		cout << "Данные в массив на 20 элементов типа вещественного double внесены успешно!\n\n";
		arr3 = new Array <char>(str);
		cout << "Данные в массив символьного типа char внесены успешно!\n\n";
		system("pause");
		break;
	default:
		while (cin.get() != '\n');
		cout << "Неверно! Повторите ввод!\n";
	}
	while (a) {
		int menu = -1;
		system("cls");
		cout << "1 - просмотр содержимого массивов\n";
		cout << "2 - добавление элемента в массив\n";
		cout << "3 - удаление элемента из массива\n";
		cout << "4 - сортировка элементов в массиве\n";
		cout << "5 - поиск минимального значения в массиве\n";
		cout << "6 - поиск максимального значения в массиве\n";
		cout << "7 - двоичный поиск в массиве\n";
		cout << "8 - замена элемента массива\n";
		cout << "0 - выход\n";
		cout << "Ваш выбор: ";
		cin >> menu;
		switch (menu)
		{
		case 1:
			system("cls");
			do {
				choice(vyb, "назад");
				if (vyb == 1) {
					cout << "\nМассив типа int \n";
					if (arr1 != NULL) {
						cout << "Введите количество колонок для отображения массива: ";
						cin >> n;
						arr1->show_Arr(n);
					}
					else cout << "не инициализирован!\n";
					system("pause");
				}
				if (vyb == 2) {
					cout << "\nМассив типа double \n";
					if (arr2 != NULL) {
						cout << "Введите количество колонок для отображения массива: ";
						cin >> n;
						arr2->show_Arr(n);
					}
					else cout << "не инициализирован!\n";
					system("pause");
				}
				if (vyb == 3) {
					cout << "\nМассив типа char \n";
					if (arr3 != NULL) {
						cout << "Введите количество колонок для отображения массива: ";
						cin >> n;
						arr3->show_Arr(n);
					}
					else cout << "не инициализирован!\n";
					system("pause");
				}
				system("cls");
			} while (vyb != 0);
			break;
		case 2:
			system("cls");
			do {
				choice(vyb, "назад");
				if (vyb == 1) {
					cout << "\nМассив типа int \n";
					if (arr1 != NULL) {
						arr1->show_Arr(10);
						cout << "Введите номер позиции нового элемента: ";
						cin >> pos;
						cout << "\nВведите значение нового элемента массива типа int: ";
						cin >> i;
						arr1->add(i, pos);
						arr1->show_Arr(10);
					}
					else cout << "не инициализирован!\n";
					system("pause");
				}
				if (vyb == 2) {
					cout << "\nМассив типа double \n";
					if (arr2 != NULL) {
						arr2->show_Arr(10);
						cout << "Введите номер позиции нового элемента: ";
						cin >> pos;
						cout << "\nВведите значение нового элемента массива типа double: ";
						cin >> d;
						arr2->add(d, pos);
						arr2->show_Arr(10);
					}
					else cout << "не инициализирован!\n";
					system("pause");
				}
				if (vyb == 3) {
					cout << "\nМассив типа char \n";
					if (arr3 != NULL) {
						arr3->show_Arr(10);
						cout << "Введите номер позиции нового элемента: ";
						cin >> pos;
						cout << "\nВведите значение нового элемента массива типа char: ";
						cin >> c;
						arr3->add(c, pos);
						arr3->show_Arr(10);
					}
					else cout << "не инициализирован!\n";
					system("pause");
				}
				system("cls");
			} while (vyb != 0);
			break;
		case 3:
			system("cls");
			do {
				choice(vyb, "назад");
				if (vyb == 1) {
					cout << "\nМассив типа int \n";
					if (arr1 != NULL) {
						arr1->show_Arr(10);
						cout << "Введите номер позиции удаляемого элемента: ";
						cin >> pos;
						arr1->del(pos);
						cout << "\nНовый массив:\n";
						arr1->show_Arr(10);
					}
					else cout << "не инициализирован!\n";
					system("pause");
				}
				if (vyb == 2) {
					cout << "\nМассив типа double \n";
					if (arr2 != NULL) {
						arr2->show_Arr(10);
						cout << "Введите номер позиции удаляемого элемента: ";
						cin >> pos;
						arr2->del(pos);
						cout << "\nНовый массив:\n";
						arr2->show_Arr(10);
					}
					else cout << "не инициализирован!\n";
					system("pause");
				}
				if (vyb == 3) {
					cout << "\nМассив типа char \n";
					if (arr3 != NULL) {
						arr3->show_Arr(10);
						cout << "Введите номер позиции удаляемого элемента: ";
						cin >> pos;
						arr3->del(pos);
						cout << "\nНовый массив:\n";
						arr3->show_Arr(10);
					}
					else cout << "не инициализирован!\n";
					system("pause");
				}
				system("cls");
			} while (vyb != 0);
			break;
		case 4:
			system("cls");
			do {
				choice(vyb, "назад");
				if (vyb == 1) {
					cout << "\nМассив типа int \n";
					if (arr1 != NULL) {
						arr1->show_Arr(10);
						arr1->sort();
						cout << "После сортировки массива:\n";
						arr1->show_Arr(10);
					}
					else cout << "не инициализирован!\n";
					system("pause");
				}
				if (vyb == 2) {
					cout << "\nМассив типа double \n";
					if (arr2 != NULL) {
						arr2->show_Arr(10);
						arr2->sort();
						cout << "После сортировки массива:\n";
						arr2->show_Arr(10);
					}
					else cout << "не инициализирован!\n";
					system("pause");
				}
				if (vyb == 3) {
					cout << "\nМассив типа char \n";
					if (arr3 != NULL) {
						arr3->show_Arr(10);
						arr3->sort();
						cout << "После сортировки массива:\n";
						arr3->show_Arr(10);
					}
					else cout << "не инициализирован!\n";
					system("pause");
				}
				system("cls");
			} while (vyb != 0);
			break;
		case 5:
			system("cls");
			do {
				choice(vyb, "назад");
				if (vyb == 1) {
					cout << "\nМассив типа int \n";
					if (arr1 != NULL) {
						arr1->show_Arr(10);
						cout << "Минимальное значение в массиве: " << arr1->arr_Min() << "\n\n";
					}
					else cout << "не инициализирован!\n";
					system("pause");
				}
				if (vyb == 2) {
					cout << "\nМассив типа double \n";
					if (arr2 != NULL) {
						arr2->show_Arr(10);
						cout << "Минимальное значение в массиве: " << arr2->arr_Min() << "\n\n";
					}
					else cout << "не инициализирован!\n";
					system("pause");
				}
				if (vyb == 3) {
					cout << "\nМассив типа char \n";
					if (arr3 != NULL) {
						arr3->show_Arr(10);
						cout << "Минимальное значение в массиве: " << arr3->arr_Min() << "\n\n";
					}
					else cout << "не инициализирован!\n";
					system("pause");
				}
				system("cls");
			} while (vyb != 0);
			break;
		case 6:
			system("cls");
			do {
				choice(vyb, "назад");
				if (vyb == 1) {
					cout << "\nМассив типа int \n";
					if (arr1 != NULL) {
						arr1->show_Arr(10);
						cout << "Максимальное значение в массиве: " << arr1->arr_Max() << "\n\n";
					}
					else cout << "не инициализирован!\n";
					system("pause");
				}
				if (vyb == 2) {
					cout << "\nМассив типа double \n";
					if (arr2 != NULL) {
						arr2->show_Arr(10);
						cout << "Максимальное значение в массиве: " << arr2->arr_Max() << "\n\n";
					}
					else cout << "не инициализирован!\n";
					system("pause");
				}
				if (vyb == 3) {
					cout << "\nМассив типа char \n";
					if (arr3 != NULL) {
						arr3->show_Arr(10);
						cout << "Максимальное значение в массиве: " << arr3->arr_Max() << "\n\n";
					}
					else cout << "не инициализирован!\n";
					system("pause");
				}
				system("cls");
			} while (vyb != 0);
			break;
		case 7:
			system("cls");
			do {
				choice(vyb, "назад");
				if (vyb == 1) {
					cout << "\nМассив типа int \n";
					if (arr1 != NULL) {
						arr1->show_Arr(10);
						cout << "\nВведите искомый элемент: ";
						cin >> i;
						arr1->binary_search(i, f);
						find(f);
					}
					else cout << "не инициализирован!\n";
					system("pause");
				}
				if (vyb == 2) {
					cout << "\nМассив типа double \n";
					if (arr2 != NULL) {
						arr2->show_Arr(10);
						cout << "\nВведите искомый элемент: ";
						cin >> d;
						arr2->binary_search(d, f);
						find(f);
					}
					else cout << "не инициализирован!\n";
					system("pause");
				}
				if (vyb == 3) {
					cout << "\nМассив типа char \n";
					if (arr3 != NULL) {
						arr3->show_Arr(10);
						cout << "\nВведите искомый элемент: ";
						cin >> c;
						arr3->binary_search(c, f);
						find(f);
					}
					else cout << "не инициализирован!\n";
					system("pause");
				}
				system("cls");
			} while (vyb != 0);
			break;
		case 8:
			system("cls");
			do {
				choice(vyb, "назад");
				if (vyb == 1) {
					cout << "\nМассив типа int \n";
					if (arr1 != NULL) {
						arr1->show_Arr(10);
						arr1->change(i, n);
						cout << "Замена проведена успешно!\n";
					}
					else cout << "не инициализирован!\n";
					system("pause");
				}
				if (vyb == 2) {
					cout << "\nМассив типа double \n";
					if (arr2 != NULL) {
						arr2->show_Arr(10);
						arr2->change(d, n);
						cout << "Замена проведена успешно!\n";
					}
					else cout << "не инициализирован!\n";
					system("pause");
				}
				if (vyb == 3) {
					cout << "\nМассив типа char \n";
					if (arr3 != NULL) {
						arr3->show_Arr(10);
						arr3->change(c, n);
						cout << "Замена проведена успешно!\n";
					}
					else cout << "не инициализирован!\n";
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
			cout << "Неверно! Повторите ввод!\n";
		}
	}
	system("pause");
	return 0;
}
