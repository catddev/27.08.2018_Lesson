#include <iostream>
#include <iomanip>
#include<math.h>
#include<ctime>

using namespace std;

// 18.	** Напишите функцию, которая принимает вещественное число и количество знаков
// и возвращает округленное число до указанного знака

double round_num(double x, int k, int n) { // где k - изначальное количество ненулевых цифр после заятой в числе x

										   /*int k = 0;*/

										   //while (x / 10 != 0)
										   //{
										   //	x *= 10; // через отладчик видно что при умножении получается 1234.56999999
										   //	k++; // подсчет знаков после запятой изначально
										   //}
										   //int a = int(x / 10);
										   //k--;

	int a = x * pow(10, k);

	int i = n;
	while (i != 0)
	{
		if (i == 1)
		{
			if (a % 10 >= 5) a = (a / 10 + 1)*pow(10, n);
			else a = a / 10 * pow(10, n);
		}
		else a /= 10;
		i--;
	}
	x = double(a / pow(10, k));

	return x;
}

// 4. Написать функцию, которая “возвращает” (через свои аргументы) результат четырёх арифметических действий
// над своими двумя первыми аргументами вещественного типа.
// Решить задачу двумя способами.

void oper(double *a, double *b, char o, double *rez) {
	if (o == '+') *rez = *a + *b;
	else if (o == '-') *rez = *a - *b;
	else if (o == '*') *rez = (*a) * (*b);
	else if (o == '/')
	{
		if (*b == 0)
		{
			cout << "Division by zero";
			*rez = 0;
		}
		else *rez = *a / *b;
	}
}

// 5. Написать программу, которая содержит функцию, принимающую в качестве аргумента,
// указатели на три массива и размер массивов,
// Заносит в массив C суммы элементов массивов А и В. Размер массивов одинаковый.

void plus_arr(int *a, int *b, int *c, int n) {
	for (int i = 0; i < n; i++)
		c[i] = a[i] + b[i];
}

// 6. Написать программу, которая содержит функцию, принимающую в качестве аргумента,
// указатель на массив и размер массива, и заменяет отрицательные элементы на 0.

void arr_neg(int *a, int n) {
	for (int i = 0; i < n; i++)
		if (a[i] < 0) a[i] = 0;
}
// 7.Написать программу, которая содержит функцию, принимающую в качестве аргумента,
// указатели на два массива (А и В) и размеры массивов.
// Функция проверяет, является ли массив В подмножеством массива А и возвращает указатель на начало найденного фрагмента,
// если элемента нет, возвращает 0.

int *subarray(int *a, int n, int *b, int m) {
	int *p1 = a, *p2 = b;
	int k = 1;
	for (; p2 < b + m; p2++)
	{
		for (; p1 < a + n; p1++)
		{
			if (*p1 == *p2)
			{
				for (int i = 1; i < m; i++)
				{
					if (*(p1 + i) == *(p2 + i))
						k++;
				}
			}
			if (k == m) return p1;
		}
	}
	return nullptr;
}




//int* arr_under(int *a, int *b, int n, int m) {
//	int *p1 = a, *p2 = b;
//	int k = 0;
//	int c;
//
//	for (; p2<b + m; p2++)
//	{
//		for (; p1<a + n; p1++)
//		{
//			if (*p2 == *p1)
//			{
//				for (int i = p1 - a, j = 0; i<m; i++, j++)
//				{
//					if (b[j] == a[i])
//					{
//						c = p1 - a;
//						k++;
//					}
//					else
//					{
//						k = 0;
//						continue;
//					}
//				}
//				if (k == m) return p1;
//			}
//		}
//	}
//	return nullptr;
//	
//}

// 10. Написать функцию, которая получает указатель на динамический массив и его размер.
// Функция должна удалить из массива все простые числа и вернуть указатель на новый динамический массив.

void erase_pos(int *&a, int &n) {// вместо простых чисел удалим числа больше нуля
	int *tmp;
	int k = 0;
	int j = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] < 0)
			k++;
	}
	tmp = new int[k];

	for (int i = 0; i < n; i++)
		if (a[i] < 0)
			tmp[j++] = a[i];

	delete[] a; // удаляется изначальный массив, нам нужна новая область с меньшим количеством ячеек
	a = tmp;
	n = k;
}


int main()
{
	srand(time(NULL));

	setlocale(LC_ALL, "Rus");

	int tn = 0;

	while (true)
	{
		cout << "Задача № ";
		cin >> tn;

		switch (tn)
		{
		case 1:
		{
			/*double x = 123.456;
			int n = 4;
			cout << round_num(x, n) << endl << endl;*/
		}
		break;
		case 2:
		{
			double x;
			int n, k;
			cin >> x >> k >> n;

			cout << round_num(x, k, n) << endl << endl; // через отлалдчик возвращает как надо 123456.8, а на экран выводит 123457
		}
		break;
		case 3:
		{
			int a = 5, *p, **pp;

			p = &a;

			cout << p << " " << &a << endl;

			pp = &p; // двойной указатель хранит ТОЛЬКО адрес указателя и не может хранить адрес просто переменной
			cout << pp << " " << &p << endl;
			cout << *p << endl;
			cout << *pp << endl; // т.к. стоит * то извлекается значение переменной p, т.е. адрес переменной a
			cout << *(*pp) << endl; // значение значения pp, т.е. число 5 // == cout << *p << endl;
		}
		break;
		case 4:
		{
			int *p;
			int a;

			p = new int; // выделяется непосредственно МЕСТО В ПАМЯТИ для одного целого числа и в указателе хранится адрес этой ячейки
			// теперь доступ к этой переменной есть только у указателя

			//p = &a; // перезапись указатедя, теперь связь с ячейкой от new int и ее значением ПОТЕРЯНА
			//// по завершению программы эта потерянная ячейка будет сидеть в памятиб ожидая пока пользователь сам ее удалит и занимать память

			delete p; // удаляет эту ячейку из памяти
			p = nullptr; // желательно это делать, чтобы не было ошибочных обращений и для проверки в дальнейшем
		}
		break;
		case 5:
		{
			int *p;

			p = new int[10];
			delete[] p; // удалить одномерный массив
		}
		break;
		case 6:
		{
			int a[7][8];

			int k = 0;
			int *p;


			for (int i = 0; i < 7; i++) {
				for (int j = 0; j < 8; j++) {
					a[i][j] = rand() % 101 - 20; // диапозон от -20  до + 80

					if (a[i][j] < 0) k++;

					cout << setw(4) << a[i][j] << " ";
				}
				cout << endl;
			}
			cout << k << endl;
			p = new int[k];

			int n = 0; // счетчик для одномерного массива, ведь неизвсетно сколько отрицательных рандомных чисел
			for (int i = 0; i < 7; i++)
			{
				for (int j = 0; j < 8; j++)
				{
					if (a[i][j] < 0)
						p[n++] = a[i][j];
				}
			}

			for (int i = 0; i < n; i++)
				cout << p[i] << endl;

			delete[] p; // сразу писать при создании, а код между ними
		}
		break;
		case 7:
		{
			double *p;
			int n;
			cin >> n;
			p = new double[n];


			for (int i = 0; i < n; i++)
			{
				p[i] = 1.0 / (rand() % 20 + 1); // RAND только с целыми числами! Поэтому в скобках, чтобы не конфликтовал с double
				cout << p[i] << " ";
			}
			delete[] p; // обязательно удалять выделенную тобой память! сама она не удалится
			cout << endl;

		}
		break;
		case 8:
		{
			// 2.Заполнить двумерный массив размером 9*7 случайными числами в диапазоне от 
			// -50 до 150. Динамически создать одномерный массив, в который поместить все числа,
			// кратные 3, 5 и 7 из двумерного массива.

			int a[9][7];

			int k = 0;
			int *p;


			for (int i = 0; i < 9; i++) {
				for (int j = 0; j < 7; j++) {
					a[i][j] = rand() % 201 - 50;

					if (a[i][j] % 3 == 0 || a[i][j] % 5 == 0 || a[i][j] % 7 == 0) k++;

					cout << setw(4) << a[i][j] << " ";
				}
				cout << endl;
			}
			p = new int[k];

			int n = 0;
			for (int i = 0; i < 9; i++)
			{
				for (int j = 0; j < 7; j++)
				{
					if (a[i][j] % 3 == 0 || a[i][j] % 5 == 0 || a[i][j] % 7 == 0)
						p[n++] = a[i][j];
				}
			}

			cout << endl;
			for (int i = 0; i < n; i++)
				cout << p[i] << " ";
			cout << endl << endl;

			delete[] p;

		}
		break;
		case 9:
		{

			/*	cout << calc(5, 3) << endl;

				double a = 0, b = 0, c = 0, d = 0;

				calc(5, 3, a, b, c, d);
				cout << a << " " << b << " " << c << " " << d << endl;*/

			double a, b, rez = 0;
			char operation;
			cin >> a >> operation >> b;
			oper(&a, &b, operation, &rez);// адреса на указатели
			cout << rez << endl;
		}
		break;
		case 10:
		{
			int *a, *b, *c;
			int n = 5;
			a = new int[n];
			b = new int[n];
			c = new int[n];

			for (int i = 0; i < n; i++)
			{
				a[i] = rand() % 51;
				b[i] = rand() % 41;
				cout << "a[" << i << "]=" << a[i] << " " << "b[" << i << "]=" << b[i] << endl;
			}

			plus_arr(a, b, c, n);

			for (int i = 0; i < n; i++)
			{
				cout << c[i] << endl;
			}

			delete[] a, delete[] b, delete[] c; // для каждого отдельно
		}
		break;
		case 11:
		{
			int *a;
			int n = 5;
			a = new int[n];

			for (int i = 0; i < n; i++)
			{
				a[i] = rand() % 31 - 20;

				cout << a[i] << " ";
			}
			cout << endl;

			arr_neg(a, n);

			for (int i = 0; i < n; i++)
			{
				cout << a[i] << endl;
			}

			delete[] a;
		}
		break;
		case 12:
		{
			//int *a, *b;
			//int n = 10, m = 5;
			//a = new int[n];
			//b = new int[m];

			//for (int i = 0; i < n; i++)
			//{
			//	a[i] = i + 2;

			//	cout << a[i] << " ";
			//}
			//cout << endl;
			//for (int i = 0, j = 4; i < m; i++, j++)
			//{
			//	b[i] = j + 2;

			//	cout << b[i] << " ";
			//}
			//cout << endl;

			//cout << arr_under(a, b, n, m) << endl;

			//delete[] a;
			//delete[] b;

			int a[] = { 1, 3, 4, 2, 7, 5, 0, 9, 4, 2 };
			int b[] = { 4, 2, 7, 5 };

			cout << *subarray(a, 10, b, 4) << endl << endl;
		}
		break;
		case 13:
		{
			int *a;
			int n = 10;
			a = new int[n];

			for (int i = 0; i < n; i++)
			{
				a[i] = rand() % 10 - 5;
				cout << a[i] << " ";
			}
			cout << endl;

			erase_pos(a, n);

			for (int i = 0; i < n; i++)
			{
				cout << a[i] << " ";
			}
			cout << endl;
			delete[] a; // здесь удаляется уже массив переданный из функции по ссылке
		}
		break;
		case 14:
		{

		}
		break;
		case 15:
		{

		}
		break;
		case 16:
		{

		}
		break;
		default:
			cout << "нет такой задачи" << endl << endl;
		}
	}
	system("pause");
	return 0;
}