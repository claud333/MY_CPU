#include <iostream>
#include "Memory.h"
#include "CPU.h"
using namespace std;
using namespace CPU_ilia;

int main()
{
	setlocale(0, "rus");
	cout << "�������� ������..." << endl;
	Memory* theMemory = new Memory();
	cout << "������" << endl;

	cout << "������ ������ = " << (int)theMemory->maxAddres<<endl;


	cout << "���������� ������:\n1.���������������\n2.�� ������" << endl;

	theMemory->Write(1, 1);
	

	cout << "�������� �������� ����� ������?\nY/N\n";
	char yesNo;
	cin >> yesNo;
	if (yesNo == 'Y' || yesNo == 'y')
	{
		for (byte i = 0;i < theMemory->maxAddres;i++)
		{
			cout << "Addres[" << (int)i << "] = " << (int)theMemory->Read(i)<<endl;
		}
	}
	cout << "������� ���������..." << endl;
	CPU* theCPU = new CPU(theMemory);
	cout << "������" << endl;
	cout << "���������..." << endl;
	theCPU->Work();
	cout << "���������" << endl << endl;;

	cout << "�������� �������� ����� ������?\nY/N\n";
	yesNo=' ';
	cin >> yesNo;
	if (yesNo == 'Y' || yesNo == 'y')
	{
		for (byte i = 0;i < theMemory->maxAddres;i++)
		{
			cout << "Addres[" << (int)i << "] = " << (int)theMemory->Read(i) << endl;
		}
	}
	system("pause");
}