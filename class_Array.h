#pragma once
#include <iostream>
#include <windows.h>
#include <time.h>
using namespace std;
template <class A > class Array
{
private:
	size_t size = 10;
	A *arr, max, min;          // ��������� �� ������
public:
	Array();
	Array(size_t Size);
	Array(char str[]);
	Array(size_t Size, int a, A b, A c);
	void init_size();
	void init_arr();
	Array(const Array& ob);
	~Array();
	void show_Arr(size_t n);
	void sort();
	void binary_search(A search_elem, int& find);
	void change(A new_elem, int i);
	A arr_Min();
	A arr_Max();
	void del(size_t pos);
	void add(A value, size_t pos);
};

template<class A>
Array<A>::Array()                                  // ����������� �� ���������
{
	arr = new A[size];
}

template<class A>
Array<A>::Array(size_t Size)                       // ����������� 
{
	arr = new A[Size];
}

template<class A>
Array<A>::Array(char str[])
{
	size = strlen(str);
	arr = new char[size];
	for (size_t i = 0; i < size; i++) {
		arr[i] = str[i];
	}
}

template<class A>
Array<A>::Array(size_t Size, int a, A b, A c)      // ����������� 
{
	size = Size;
	arr = new A[Size];
	A n;
	for (size_t i = 0; i < size; i++) {
		n = rand() % a*c + b;
		arr[i] = n;
	}
}

template<class A>
void Array<A>::init_size()
{
	do {
		cout << "������� ������ �������: ";
		cin >> size;
		if (size < 1)
			cout << "\n������! ����� ������ 1!\n";
	} while (size < 1);
}

template<class A>
void Array<A>::init_arr()
{
	for (size_t i = 0; i < size; i++) {
		cout << "arr [" << i + 1 << "] = ";
		cin >> arr[i];
	}
}

template<class A>
Array<A>::Array(const Array& ob)                 // ����������� �����
{
	arr = new A[ob.size];
	for (size_t i = 0; i < ob.size; i++) {
		arr[i] = ob.arr[i];
	}
}

template<class A>
Array<A>::~Array()                               // ����������
{
	delete arr;
}

template<class A>
void Array<A>::show_Arr(size_t n)                // ����������� ����������� �������
{
	for (size_t i = 0; i < size; i++) {
		cout << arr[i] << "\t";
		if ((i + 1) % n == 0) cout << endl;
		if (i + 1 == size) cout << endl;
	}
}

template<class A>
void Array<A>::sort() {                          // ���������� ������� �������
	for (size_t k = 0; k < size - 1; k++) //k-����� ������� ����������� �������
	{   //����� ��������
		size_t imin = k;
		for (size_t i = k + 1; i < size; i++) //���������� �� k �� �����
			if (arr[i] < arr[imin]) {
				imin = i;
			}
		//����� �������
		//������������ k-�� � ������������
		A tmp = arr[k];
		arr[k] = arr[imin];
		arr[imin] = tmp;
	}
}

template<class A>
void Array<A>::binary_search(A search_elem, int &find)
{
	int low = 0, up = size - 1, middle;
	find = -1; //������ ���������� ��������
	do
	{
		middle = (low + up) / 2; //���������� �������
		if (search_elem == arr[middle]) //������� ������
		{
			find = middle;
			break;
		}
		if (search_elem<arr[middle]) up = middle - 1; //���� ����� � ����� ��������
		if (search_elem>arr[middle]) low = middle + 1; //���� ����� � ������ ��������
	} while (low <= up);
}

template<class A>
void Array<A>::change(A new_elem, int i)
{
	cout << "\n������� ������� �������� ����������� ������: ";
	cin >> i;
	i--;
	if (i >= 0 && i < (int) size) {
		cout << "\n������� �������� ������ ��������: ";
		cin >> new_elem;
		arr[i] = new_elem;
	}
	else cout << "\n������! � ������� ��� ����� �������\n";
}

template<class A>
A Array<A>::arr_Min() {        // ����� ������������ �������� �������
	min = *arr;
	A *a = arr;
	a++;
	for (size_t i = 1; i < size; i++, a++) {
		if (*a < min + 1e-9) {
			min = *a;
		}
	}
	return min;
}

template<class A>
A Array<A>::arr_Max() {        // ����� ������������� �������� �������
	max = *arr;
	A *a = arr;
	a++;
	for (size_t i = 1; i < size; i++, a++) {
		if (*a > max + 1e-9) {
			max = *a;
		}
	}
	return max;
}

template<class A>
void Array<A>::del(size_t pos)                        // ������� �������� ������ 
{
	bool f = false;
	if (pos <= 0 || pos > size)
	{
		cout << "[" << pos << "] ������� �����������!\n";
		f = true;
	}
	if (!f) {
		--size;
		A*ptr = new A[size];                               // �������� ������� ���������� �� ������
		size_t n = 0;
		for (size_t i = 0; i < pos - 1; i++, n++) {         // ������������ ��������� �� ������� � ����� ������ ����������
			ptr[n] = arr[i];
		}
		for (size_t i = pos; i < size + 1; i++, n++) {       // ���������� ��������� ������� � ������������ ��������� ����� �������
			ptr[n] = arr[i];
		}
		delete[] arr;                                       // ������� ������ ������ ���������� �� ���������
		arr = ptr;                                          // ������������� ������ ������ ���������� �� �����
		cout << "������� [" << pos << "] ������!\n";
	}
}

template<class A>
void Array<A>::add(A value, size_t pos)                             // ������� �������� ������ 
{
	bool f = false;
	if (pos <= 0 || pos > size + 1)
	{
		cout << "������! ������� ������ ����� �������\n";
		f = true;
	}
	if (!f) {
		++size;
		A*ptr = new A[size];                              // �������� ������� ���������� �� ������
		size_t n = 0;
		for (size_t i = 0; i < pos - 1; i++, n++) {            // ������������ ��������� �� ������� � ����� ������ ����������
			ptr[n] = arr[i];
		}
		ptr[n] = value;
		n++;
		for (size_t i = pos - 1; i < size; i++, n++) {          // ���������� ��������� ������� � ������������ ��������� ����� �������
			ptr[n] = arr[i];
		}
		delete[] arr;                                       // ������� ������ ������ ���������� �� ���������
		arr = ptr;                                          // ������������� ������ ������ ���������� �� �����
		cout << "����� ������� �������� � ������� [" << pos << "]!\n";
	}
}
void find(int find)
{
	if (find == -1)
		cout << "������� ������� �� ������\n";
	else
		cout << "������� ������� �� ����� " << find + 1 << " � �������\n";
}

void quit() {                          // ������� ������
	cout << "���������� ������!\n";
	system("pause");
	exit(0);
}

void choice(int& vyb, const char* s) {
	do {
		cout << "�������� ��� ������:\n";
		cout << "1 - ������������� ��� (int);\n";
		cout << "2 - ������������ ��� (double);\n";
		cout << "3 - ���������� ��� (char);\n";
		cout << "0 - "<<s<<";\n";
		cout << "��� �����: ";
		cin >> vyb;
		if (vyb < 0 || vyb>3) {
			while (cin.get() != '\n');
			cout << "�������! ��������� ����!\n";
			system("pause");
			system("cls");
		}
	} while (vyb < 0 || vyb>3);
}
