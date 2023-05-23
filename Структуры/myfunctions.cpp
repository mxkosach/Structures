#include <iostream>
#include <iomanip>
#include <fstream>
#include "myfunctions.h"
using namespace std;

void title(int n, char abc, int len1, int len2, char ch)
{
	cout.flags(0);
	if (n != 1)
		cout << endl;
	for (int i = 0; i < len1; i++)
		cout << ch;
	cout << " Задание " << n << abc << " ";
	for (int i = 0; i < len2; i++)
		cout << ch;
	cout << endl;
}

//Выводит двоичное представление n
void binout(char n, char ch)
{
	int nd = sizeof(n) * 8;
	unsigned char m = n, k = 1;

	for (int i = nd - 1; i >= 0; i--)
	{
		cout << (m & (k << i) ? 1 : 0);
		if (i && i % 8 == 0) cout << ' ';
	}
	cout << ch;
}

unsigned int myrnd()
{
	unsigned int res;
	char* p = (char*)&res;
	for (int i = 0; i < 4; i++)
	{
		*p = rand() % 256;
		p++;
	}
	return res;
}

int myrnd(int a, int b)
{
	if (a > b)
		return 0;
	return a + myrnd() % (b - a + 1);
}

double myrnd(double x, double y, int n)
{
	if (x > y || n < 0)
		return 0;
	double m = pow(10, n);
	int a = x * m, b = y * m;
	return myrnd(a, b) / m;
}

void myrnd(int* M, int size, int a, int b)
{
	for (int i = 0; i < size; i++)
		M[i] = myrnd(a, b);
}

void myrnd(double* M, int size, double x, double y, int n)
{
	for (int i = 0; i < size; i++)
		M[i] = myrnd(x, y, n);
}

void myout(int* M, int size, int nc, int nw)
{
	if (nc <= 0)
		nc = size;
	for (int i = 0; i < size; i++)
	{
		cout << setw(nw) << M[i];
		if ((i + 1) % nc == 0)
			cout << endl;
	}
}

void myout(char* M, int size, int nc, int nw)
{
	if (nc <= 0)
		nc = size;
	for (int i = 0; i < size; i++)
	{
		cout << setw(nw) << M[i];
		if ((i + 1) % nc == 0)
			cout << endl;
	}
}

void myout(double* M, int size, int nc, int nw, int nq)
{
	if (nc <= 0)
		nc = size;
	for (int i = 0; i < size; i++)
	{
		cout << fixed << setw(nw) << setprecision(nq) << M[i];
		if ((i + 1) % nc == 0)
			cout << endl;
	}
}

void myout(int** M, int nr, int* size, int nw)
{
	for (int i = 0; i < nr; i++)
		if (size[i])
			myout(M[i], size[i], size[i], nw);
		else 
			cout << endl;
}

//сравнивает 2 числа a,b с учётом погрешности e
bool realequal(float a, float b, double e)
{
	if (abs(a - b) < e)
		return true;
	else
		return false;
}

bool realequal(double a, double b, double e)
{
	if (abs(a - b) < e)
		return true;
	else
		return false;
}

void mysrt(int* M, int size, bool inc)
{
	if (inc)
	{
		for (int i = size; i > 1; i--)
			for (int j = 0; j < i - 1; j++)
				if (M[j] > M[j + 1])
					swap(M[j], M[j + 1]);
	}
	else
	{
		for (int i = size; i > 1; i--)
			for (int j = 0; j < i - 1; j++)
				if (M[j] < M[j + 1])
					swap(M[j], M[j + 1]);
	}
}

void mysrt(double* M, int size, bool inc)
{
	if (inc)
	{
		for (int i = size; i > 1; i--)
			for (int j = 0; j < i - 1; j++)
				if (M[j] > M[j + 1])
					swap(M[j], M[j + 1]);
	}
	else
	{
		for (int i = size; i > 1; i--)
			for (int j = 0; j < i - 1; j++)
				if (M[j] < M[j + 1])
					swap(M[j], M[j + 1]);
	}
}

void mysrt(int* X, int nx, bool inc, int* P[])
{
	if (inc)
	{
		for (int i = nx; i > 1; i--)
			for (int j = 0; j < i - 1; j++)
				if (X[j] > X[j + 1])
				{
					swap(X[j], X[j + 1]);
					swap(P[j], P[j + 1]);
				}
	}
	else
	{
		for (int i = nx; i > 1; i--)
			for (int j = 0; j < i - 1; j++)
				if (X[j] < X[j + 1])
				{
					swap(X[j], X[j + 1]);
					swap(P[j], P[j + 1]);
				}
	}
}

void mysrt(double* X, int nx, bool inc, double* P[])
{
	if (inc)
	{
		for (int i = nx; i > 1; i--)
			for (int j = 0; j < i - 1; j++)
				if (X[j] > X[j + 1])
				{
					swap(X[j], X[j + 1]);
					swap(P[j], P[j + 1]);
				}
	}
	else
	{
		for (int i = nx; i > 1; i--)
			for (int j = 0; j < i - 1; j++)
				if (X[j] < X[j + 1])
				{
					swap(X[j], X[j + 1]);
					swap(P[j], P[j + 1]);
				}
	}
}

void mysrt(char** X, int nx, bool inc, char** P)
{
	if (inc)
	{
		for (int i = nx; i > 1; i--)
			for (int j = 0; j < i - 1; j++)
				if (strcmp(X[j], X[j + 1])>0)
				{
					swap(X[j], X[j + 1]);
					swap(P[j], P[j + 1]);
				}
	}
	else
	{
		for (int i = nx; i > 1; i--)
			for (int j = 0; j < i - 1; j++)
				if (strcmp(X[j], X[j + 1]) < 0)
				{
					swap(X[j], X[j + 1]);
					swap(P[j], P[j + 1]);
				}
	}
}

//возващает индекс max элемента
int mymax(int* M, int size)
{
	int imax = 0;
	int max = M[0];
	for (int i = 1; i < size; i++)
	{
		if (M[i] > max)
		{
			imax = i;
			max = M[i];
		}
	}
	return imax;
}

int mymax(double* M, int size)
{
	int imax = 0;
	double max = M[0];
	for (int i = 1; i < size; i++)
	{
		if (M[i] > max)
		{
			imax = i;
			max = M[i];
		}
	}
	return imax;
}

//возващает индекс min элемента
int mymin(int* M, int size)
{
	int imin = 0;
	int min = M[0];
	for (int i = 1; i < size; i++)
	{
		if (M[i] < min)
		{
			imin = i;
			min = M[i];
		}
	}
	return imin;
}

int mymin(double* M, int size)
{
	int imin = 0;
	double min = M[0];
	for (int i = 1; i < size; i++)
	{
		if (M[i] < min)
		{
			imin = i;
			min = M[i];
		}
	}
	return imin;
}

//возращает длину текста в строке s
int mylen(const char* s)
{
	char* p = (char*)s;
	while (*p != 0)
		p++;
	return p - s;
}

//копирует строку t в строку s
char* mycpy(char* s, const char* t)
{
	char* p = s, * q = (char*)t;
	while (1)
	{
		*p = *q;
		if (*q == 0)
			break;
		p++; q++;
	}
	return s;
}

//копирует n первых символов строки t в строку s
char* mycpy(char* s, const char* t, int n, bool addNull)
{
	char* p = s, * q = (char*)t;
	for (int i = 0; i < n; i++)
	{
		*p = *q;
		if (*q == 0)
			break;
		p++; q++;
	}
	if (addNull)
		*p = '\0';
	return s;
}

//объединяет строки s и t
char* mycat(char* s, const char* t)
{
	char* p = s + mylen(s), * q = (char*)t;
	while (1)
	{
		*p = *q;
		if (*q == 0)
			break;
		p++; q++;
	}
	return s;
}

//сравнивает первые n символов строк s, t
bool mycmp(const char* s, const char* t, int n)
{
	char* p = (char*)s, * q = (char*)t;
	int ns = mylen(s), nt = mylen(t);
	if (n <= 0)
		n = ns > nt ? ns : nt;
	for (int i = 0; i < n; i++, p++, q++)
		if (*p != *q)
			return true;
	return false;
}

//возращает адрес 1-го вхождения подстроки t в строку s
char* mystr(const char* s, const char* t, int n)
{
	if (n <= 0)
		n = mylen(t);
	char* end = (char*)s + mylen(s) - n;
	for (char* p = (char*)s; p <= end; p++)
		if (!mycmp(p, t, n))
			return p;
	return NULL;
}

//удаляет в начале строки s ndel символов
void mydel(char* s, int ndel)
{
	if (ndel <= 0)
		return;
	mycpy(s, s + ndel);
}

//вставляет в начало строки s строку t
void myins(char* s, const char* t)
{
	int ns = mylen(s), nt = mylen(t);
	for (char* p = s + ns; p >= s; p--)
		*(p + nt) = *p;
	mycpy(s, t, nt);
}

//определяет количество подряд идущих разделителей,
//расположенных в начале строки s
int myspn(const char* s, const char* sep)
{
	char* p = (char*)s;
	while (mystr(sep, p, 1))
		p++;
	return p - s;
}

//определяет количество подряд идущих словесных символов,
//расположенных в начале строки s
int mycspn(const char* s, const char* sep)
{
	char* p = (char*)s;
	while (*p && !mystr(sep, p, 1))
		p++;
	return p - s;
}

//чтение файла fname в строку s
int myinput(char* s, const char* fname, const char sep)
{
	ifstream fin;                   //объявляем fin - поток данных из файла
	fin.open(fname, ios_base::in);  //связываем поток fin с файлом fname
	const int nt = 256; char t[nt];   //t - для ввода одной строки файла
	int nstr = 0;                     //счетчик строк файла
	char* p = s;                    //указатель на начало строки s
	while (!fin.eof())               //выполняем цикл, пока не достигнут конец файла
	{
		fin.getline(t, nt);          //читаем в t текущую строку файла
		if (*t == '\0') break;         //если t - пустая строка, выходим из цикла
		mycpy(p, t);                //копируем строку t по адресу указателя p
		nstr++;                     //увеличиваем счетчик строк
		p += mylen(t) + 1;            //перемещаем p на новое место вставки
		*(p - 1) = sep;               //вставляем между строками разделитель sep
	}
	*p = '\0';                      //завершаем строку s
	fin.close();                    //закрываем поток fin
	return nstr;                    //возвращаем количество считанных строк
}

//преобразует вещественное число d в строчный эквивалент
//и помещает результат в выходную строку str
//(nf - длина дробной части d)
char* ftoa(double d, char* str, int nf)
{
	for (int i = 0; i < nf; i++)
		d *= 10;
	_itoa(d,str,10);
	myins(str + mylen(str) - nf, ".");
	return str;
}

//переводит nw слов строки s в целые числа
//и присваивает их значения элементам массива X
char* str2int(const char* s, int nw, int* X) {
	char* p = (char*)s;      //p -> в начало строки s
	p += myspn(s, " ");       //p -> на начальное слово s
	for (int i = 0; i < nw; i++) { //цикл по словам строки s
		if (X) //если при вызове функции указан третий параметр,
			X[i] = atoi(p);  //текущее слово -> в X[]
		p += mycspn(p, " ");  //p -> на следующее слово
		p += myspn(p, " ");
	}
	return p;                //возвращаем адрес слова №(nw+1)
}

//переводит nw слов строки s в вещественные числа
//и присваивает их значения элементам массива X
char* str2dbl(const char* s, int nw, double* X) {
	char* p = (char*)s;      //p -> в начало строки s
	p += myspn(s, " ");       //p -> на начальное слово s
	for (int i = 0; i < nw; i++) { //цикл по словам строки s
		if (X) //если при вызове функции указан третий параметр,
			X[i] = atof(p);  //текущее слово -> в X[]
		p += mycspn(p, " ");  //p -> на следующее слово
		p += myspn(p, " ");
	}
	return p;                //возвращаем адрес слова №(nw+1)
}