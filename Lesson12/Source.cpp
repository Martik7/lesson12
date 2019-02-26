#include <iostream>
#include <clocale>
#include <Windows.h>
#include <ctime>
using namespace std;

void allocateArray(int *&a, int N)
{
	a = new int[N];
}

void fillArray(int *a, int N)
{
	for (size_t i = 0; i < N; i++)
	{
		a[i] = rand() % 3;
	}
}

void printArray(const int *a, int N)
{
	for (size_t i = 0; i < N; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}

void AddElement(int *&a, int &N)
{
	int *tmp = new int[N + 2];
	tmp[0] = 50;
	for (size_t i = 0; i < N; i++)
	{
		tmp[i+1] = a[i];
	}
	tmp[N+1] = 50;
	cout << endl;

	delete[] a;
	a = tmp;
	N+=2;
}

int* remove0(int *a, int N, int &newSize)
{
	int* tmp, k = 0;
	for (size_t i = 0; i < N; i++)
	{
		if (a[i] != 0)
		{
			k++;
		}
	}
		tmp = new int[k];

		k = 0;
		for (size_t i = 0; i < N; i++)
		{
			if (a[i]!=0)
			{
				tmp[k++] = a[i];
			}
		
	}
	newSize = k;
	return tmp;

}

/*
Написать функцию, которая принимает указатель на массив, 
количество элементов массива и новый элемент 
и выполняет вставку нового элемента после первого отрицательного элемента в массиве.
Если такого элемента в массиве нет, то вставляет в начало массива.
*/
void procedure1(int *a, int n, int i1)
{
	int i = 0;
	i1 = 0;
	while ((i <= n) && (i1 = 0))
		if (a[i] < 0)
			i1 = i;
		else 
			i = i + 1;
	if (i1 == 0)
		cout << "В массиве нет отрицательного элемента!";
	else 
		cout << "Первый отрицательный элемент= " << a[i1] << " его индекс= " << i1;
	cout << endl;
}
void procedure2(int *a, int n, int i1, int el)
{
	int i;
	n = n + 1;
	if (i1 == n - 1)
		a[n] = el;
	else 
		for (;i = n; i1 + 2)
			a[i] = a[i - 1];
	a[i1 + 1] = el;
}

//void AddElement1(int *&a, int &N)
//{
//	int *tmp;
//	tmp = new int[N - 1];
//	int k = 0, pos = -1, index = 0;
//	for (size_t i = 0; i < N; i++)
//	{
//		if (a[i] < 0)
//		{
//			pos = i;
//			break;
//		}
//	}
//	
//
//	tmp[N + 1] = 50;
//	cout << endl;
//
//	delete[] a;
//	a = tmp;
//	N += 2;
//}

/*Написать программу, 
которая переводит введенное десятичное число в двоичное число. 
Результат перевода сохранить в массив минимально возможного размера.*/
void transferIn2(int num_10, bool* num_2)
{
	int i, j = 0; // для циклов
	/* temp - для временного хранения разряда из правой половины, которое потом перейдёт в левую половину
	   при преобрвзовании порядка по принципу от последнего к первому */
	bool temp;
	for (i = 0; i < 32; i++) //обнуляем все элементы (разряды)
		num_2[i] = 0;
	i = 0;
	while (1)
	{
		num_2[i] = num_10 % 2; // десятичное число делют по модулю на 2 (т.е. в num_2[i] записывается сам остаток от деления на 2)
		if (!(num_10 / 2)) // если деление без модуля (без остатка) на 2 стало равнятся 0, то...
		{
			while (1) // цикл, который поменяет порядок значений элементов в массиве по принципу от последнего к первому
			{
				temp = num_2[31 - j]; // в temp сохраняется разряд из правой половины
				num_2[31 - j] = num_2[j]; // в разряд из праой половины сохраняется соответствующий зеркальный разряд левой половины
				num_2[j] = temp; // в разряд левой половины сохраняется значение из temp (бывший разряд из правой половины)
				if (!i) // если i=0, то...
					break; // цикл завершается
				j++; i--;
			}
			break; // цикл завершается
		}
		num_10 /= 2; // десятичное число делют без модуля (без остатка)
		i++;
	}
}

int main()
{
	setlocale(LC_ALL, "RUS");
	srand(time(NULL));

	/*int *a;
	int N;
	cout << "Введите размерность массива ";
	cin >> N;
	allocateArray(a, N);
	fillArray(a, N);
	printArray(a, N);
	cout << "+1 элемент" << endl;
	AddElement(a, N);
	printArray(a, N);
	delete[] a;
	a = 0;
	if (a != 0)
	delete[] a;*/

	/*int *a, *b, *c;
	int N;
	cin >> N;
	a = new int[N];
	b = a;
	c = a;
	delete[] b;
	b[0] = 100;
	cout << a[0] << endl;
	delete[] a;*/

	/*int *a, *b;
	int N, M;
	cin >> N;
	allocateArray(a, N);
	fillArray(a, N);
	printArray(a, N);
	b = remove0(a, N, M);
	printArray(b, M);
	printArray(a, N);*/

	unsigned int a_10, b_10;
	int i;
	bool a_2[32], b_2[32], sum_2[32] = { NULL }, lo = 0;
	cin >> a_10 >> b_10;
	transferIn2(a_10, a_2);
	transferIn2(b_10, b_2);
	cout << endl << a_10 << "d = ";
	for (i = 0; i < 32; i++)
		cout << a_2[i];
	cout << 'b' << endl << endl;
	cout << b_10 << "d  = ";
	for (i = 0; i < 32; i++)
		cout << b_2[i];
	cout << 'b' << endl << endl;;

	system("pause");
	return 0;
}