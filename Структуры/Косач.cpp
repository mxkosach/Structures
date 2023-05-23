#include "myfunctions.h"
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

struct session
{
	char* name; int* val; float mean;
};
struct stworker
{
	char* name;
	int otdel;
	double oklad;
	char pol;
	char* dat;
	char* adr;
	char* tel;
};

inline void str2session(const char* s, session* stud, int nval);
void session2scn(session* pstud, int nw, int nval, bool meanout = true);
float meanval(int* x, int nx);
inline void str2worker(const char* s, stworker* worker);
void worker2scn(stworker* worker, int nw);

int main()
{
	setlocale(LC_ALL, "rus");
	srand(time(0));

	{
		title(1);
		const int nname = 20, nval = 4;
		struct session
		{
			char name[nname];	int val[nval];	float mean;
		} stud1;
		session stud2 = { "�������� �.�.",8,6,9,7,7.50 };
		stud1 = stud2;
		cout << "���������� ������:\n";
		cout << "1) " << stud1.name;
		myout(stud1.val, nval, nval + 1, 4);
		cout << fixed << setprecision(2) << " (������� " << stud1.mean << ")\n";
	}

	{
		title(2);
		struct stPoint2
		{
			double x, y;
		};
		struct stCircle
		{
			stPoint2 center;	double radius;
		};
		const int nc = 20;
		stCircle crc[nc];
		for (int i = 0; i < nc; i++)
		{
			crc[i].center.x = (rand() % 18 - 9) / 10.;
			crc[i].center.y = (rand() % 18 - 9) / 10.;
			crc[i].radius = (rand() % 9 + 1) / 10.;
			cout << fixed << setprecision(1);
			cout << "(" << setw(4) << crc[i].center.x
				<< "," << setw(4) << crc[i].center.y
				<< "," << setw(4) << crc[i].radius << ")";
			if ((i + 1) % 4 == 0)
				cout << endl;
		}
		cout << "���������� � ��������� �����:\n";
		/*for (int i = 0; i < nc; i++)
		{
			double r = sqrt(pow(crc[i].center.x, 2) + pow(crc[i].center.y, 2));
			if (r + crc[i].radius <= 1)
			{
				cout << "����� = (" << setw(4) << crc[i].center.x
					<< "," << setw(4) << crc[i].center.y
					<< "), ������ = " << setw(4) << crc[i].radius << endl;
			}
		}*/

		for (stCircle* p = crc, *end = p + nc; p < end; p++)	//4
		{
			double r = sqrt(p->center.x * p->center.x + p->center.y * p->center.y);
			if (r + p->radius <= 1)
				cout << "����� = (" << setw(4) << p->center.x
				<< "," << setw(4) << p->center.y
				<< "), ������ = " << setw(4) << p->radius << endl;
		}
	}

	{
		title(3);
		const char* s = "����������� �.�. 7 5 6 5";
		cout << "�������� ������: " << s;
		session stud, * pstud = &stud;

		int nval = 4;

		/*char* p = (char*)s;
		p += myspn(p, " ");
		p += mycspn(p, " ");
		p += myspn(p, " ");
		p += mycspn(p, " ");
		p += myspn(p, " ");
		int lenfio =p-s-1;
		stud.name = new char[lenfio+1];
		mycpy(stud.name, s, lenfio, 1);
		stud.val = new int[nval];
		for (int i = 0; i < nval; i++)
		{
			stud.val[i] = atoi(p);
			p += mycspn(p, " ");
			p += myspn(p, " ");
		}
		stud.mean = 0;
		for (int i = 0; i < nval; i++)
			stud.mean += stud.val[i];
		stud.mean /= nval;*/
		str2session(s, pstud, nval);	//5

		/*pstud->mean = 0;
		for (int i = 0; i < nval; i++)
			pstud->mean += pstud->val[i];
		pstud->mean /= nval;*/
		pstud->mean = meanval(pstud->val, nval);	//6a

		cout << "\n���������� ������:\n";
		/*cout << left << setw(18) << stud.name;
		cout << right << fixed << setprecision(2);
		myout(stud.val, nval, 5);
		cout << "   ������� = " << stud.mean << endl;*/
		session2scn(pstud, 18, nval);	//5

		delete[]stud.name;
		delete[]stud.val;
	}

	{
		title(7);
		char* s = new char[1024];
		int nstud = myinput(s, "12.7.txt");
		session* stud = new session[nstud];
		int nval = 4;
		char* p = s;
		for (int i = 0; i < nstud; i++)
		{
			str2session(p, &stud[i], nval);
			stud[i].mean = meanval(stud[i].val, nval);
			p += mylen(p) + 1;
		}

		for (int i = 0; i < nstud; i++)
			session2scn(&stud[i], 20, nval, false);

		cout << "\n���������:\n";
		for (int i = 0; i < nstud; i++)
		{
			int n = mymin(stud[i].val, nval);
			if (stud[i].val[n] > 8)
				session2scn(&stud[i], 15, 0, true);
		}

		cout << "\n������������:\n";
		for (int i = 0; i < nstud; i++)
		{
			int n = mymin(stud[i].val, nval);
			if (stud[i].val[n] < 4)
				session2scn(&stud[i], 15, 0, true);
		}

		title(8);
		session** pstud = new session * [nstud];
		char** pname = new char* [20];
		for (int i = 0; i < nstud; i++)
		{
			pstud[i] = &stud[i];
			pname[i] = stud[i].name;
		}
		mysrt(pname, nstud, true, (char**)pstud);
		cout << "���������� �� �������:\n";
		for (int i = 0; i < nstud; i++)
			session2scn(pstud[i], 20, nval, false);

		double* pmean = new double[nstud];
		for (int i = 0; i < nstud; i++)
		{
			pstud[i] = &stud[i];
			pmean[i] = stud[i].mean;
		}
		mysrt(pmean, nstud, false, (double**)pstud);
		cout << "\n���������� �� ������� ������:\n";
		for (int i = 0; i < nstud; i++)
			session2scn(pstud[i], 20, 0, true);

		for (int i = 0; i < nstud; i++)
		{
			delete[]stud[i].val;
			delete[]stud[i].name;
		}
		delete[]s;
		delete[]stud;
		delete[]pstud;
		delete[]pname;
		delete[]pmean;
	}


	{
		title(10);
		const char* s = "�������� ����� ���������� 6 630,5 w 15.07.1969 33-443-55-33 ������������_����� 86 62";
		cout << "�������� ������:\n" << s;
		stworker worker, * pworker = &worker;
		str2worker(s, pworker);
		cout << "\n���� ���������:\n";
		worker2scn(pworker, mylen(worker.name));
	}

	{
		title(11);
		char* s = new char[4100];
		int nwkr = myinput(s, "608.txt");
		stworker* worker = new stworker[nwkr];
		char* p = s;

		for (int i = 0; i < nwkr; i++)
		{
			str2worker(p, &worker[i]);
			p += mylen(p) + 1;
		}

		stworker** srt = new stworker * [nwkr];
		int* otd = new int[nwkr];
		for (int i = 0; i < nwkr; i++)
		{
			srt[i] = &worker[i];
			otd[i] = worker[i].otdel;
		}
		mysrt(otd, nwkr, true, (int**)srt);

		int n = 0;
		for (int i = 0; i < nwkr; i++)
			if (otd[i] == 1)
				n++;
		char** pname = new char* [n];

		for (int i = 0; i < n; i++)
			pname[i] = srt[i]->name;
		mysrt(pname, n, true, (char**)srt);

		cout << "������ �����������, ������������� �� ������� (������ ����� - �� ���):\n";
		for (int i = 0; i < nwkr; i++)
			worker2scn(srt[i], 32);

		n = 0;
		for (int i = 0; i < nwkr; i++)
		{
			char* p = worker[i].dat;
			p = mystr(p, ".") + 1;
			p = mystr(p, ".") + 4;
			if (*p == '1')
			{
				srt[n] = &worker[i];
				pname[n] = worker[i].name;
				n++;
			}
		}
		mysrt(pname, n, true, (char**)srt);
		cout << "\n������ �����������, ������� � ������� ���� �������� ������:\n";
		for (int i = 0; i < n; i++)
			worker2scn(srt[i], 32);

		for (int i = 0; i < n; i++)
			delete[]pname[i];
		delete[]worker;
		delete[]srt;
		delete[]pname;
		delete[]s;
		delete[]otd;
	}

	cout << endl; system("pause");
	return 0;
}

//����������� ���������� ������ ����� ��������� ���� session
inline void str2session(const char* s, session* stud, int nval)
{
	char* p = (char*)s;
	p += myspn(p, " ");
	p += mycspn(p, " ");
	p += myspn(p, " ");
	p += mycspn(p, " ");
	p += myspn(p, " ");
	int lenfio = p - s - 1;
	stud->name = new char[lenfio + 1];
	mycpy(stud->name, s, lenfio, 1);
	stud->val = new int[nval];
	/*for (int i = 0; i < nval; i++)
	{
		stud->val[i] = atoi(p);
		p += mycspn(p, " ");
		p += myspn(p, " ");
	}*/
	str2int(p, nval, stud->val);	//6b
	stud->mean = atof(p);
}

void session2scn(session* pstud,
	int nw,		//������ ������� ��� ������ ���
	int nval,	//���������� �������
	bool meanout)	//�������� �� ���� mean?
{
	cout << left << setw(nw) << pstud->name;
	cout << right << fixed << setprecision(2);
	myout(pstud->val, nval, nval + 1, 4);
	if (meanout)
		cout << "	 ������� = " << pstud->mean;
	cout << endl;
}

float meanval(int* x, int nx)
{
	float sum = 0;
	for (int i = 0; i < nx; i++)
	{
		sum += x[i];
	}
	return sum / nx;
}

//����������� ���������� ������ s ����� ��������� worker ���� stWorker
inline void str2worker(const char* s, stworker* worker)
{
	char* p = str2int(s, 3);
	worker->name = new char[p - s + 1];
	mycpy(worker->name, s, p - s, 1);

	p = str2int(p, 1, &worker->otdel);
	p = str2dbl(p, 1, &worker->oklad);
	worker->pol = *p;
	p = str2int(p, 1);

	char* q = p;
	p = str2int(p, 1);
	worker->dat = new char[p - q + 1];
	mycpy(worker->dat, q, p - q, 1);

	q = p;
	p = str2int(p, 1);
	worker->tel = new char[p - q + 1];
	mycpy(worker->tel, q, p - q, 1);

	worker->adr = new char[mylen(p) + 1];
	mycpy(worker->adr, p);
}

//������� �� ����� ���� ��������� worker, 
//����������� �� ���������� �������
void worker2scn(stworker* worker, int nw)
{
	cout << left << setw(nw) << worker->name;
	cout << right << fixed << setprecision(2);
	cout << "����� �" << worker->otdel;
	cout << " �����=" << worker->oklad;
	cout << (worker->pol == 'm' ? " ���." : " ���.");
	cout << " ���." << worker->tel << endl;
	cout << "	���� ��������: " << setw(11) << worker->dat;
	cout << " �����: " << worker->adr << endl;
}
