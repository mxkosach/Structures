//================================================================
// Заголовочный файл создан студентом группы №1 Косачем Максимом
//================================================================
#pragma once
#include <cstddef>
#pragma warning(disable : 4996)

void title(int n, char abc = NULL, int len1 = 3, int len2 = 17, char ch = '=');

void binout(char, char = '\n');

unsigned int myrnd();
int myrnd(int a, int b);
double myrnd(double x, double y, int n = 3);
void myrnd(int* M, int size, int a, int b);
void myrnd(double* M, int size, double x, double y, int n);

void myout(int* M, int size, int nc = -1, int nw = 4);
void myout(char* M, int size, int nc = -1, int nw = 1);
void myout(double* M, int size, int nc = -1, int nw = 8, int nq = 3);
void myout(int** M, int nr, int* size, int nw = 4);

bool realequal(float a, float b, double = 1e-6);
bool realequal(double a, double b, double = 1e-12);

void mysrt(int* M, int size, bool inc = true);
void mysrt(double* M, int size, bool inc = true);
void mysrt(int* X, int nx, bool inc, int* P[]);
void mysrt(double* X, int nx, bool inc, double* P[]);
void mysrt(char** X, int nx, bool inc, char** P);

int mymax(int* M, int size);
int mymax(double* M, int size);

int mymin(int* M, int size);
int mymin(double* M, int size);

int mylen(const char* s);
char* mycpy(char* s, const char* t);
char* mycpy(char* s, const char* t, int n, bool addNull = false);

char* mycat(char* s, const char* t);

bool mycmp(const char* s, const char* t, int n = 0);
char* mystr(const char* s, const char* t, int n = 0);

void mydel(char* s, int ndel);
void myins(char* s, const char* t);

int myspn(const char* s, const char* sep);
int mycspn(const char* s, const char* sep);

int myinput(char* s, const char* fname, const char sep = '\0');

char* ftoa(double d, char* str, int nf);

char* str2int(const char* s, int nw, int* X = NULL);
char* str2dbl(const char* s, int nw, double* X = NULL);