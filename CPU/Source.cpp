#include <iostream>
#include "Memory.h"
#include "CPU.h"
using namespace std;
using namespace CPU_ilia;
void byNumber(Memory* theMemory)
{
	int addres=0, valou=0;
	while (valou != -1||addres!=-1)
	{
		cout << "������� ����� ������\t��� �� ��������� ������� -1" << endl;
		cin >> addres;
		if (valou == -1 || addres == -1) return;
		cout << "������� ��������" << endl;
		cin >> valou;
		if (valou == -1 || addres == -1 ) return;
		theMemory->Write((byte)addres, (byte)valou);
	}
}
void turn(Memory* theMemory)
{
	int valou;
	for (int i = 1;i < theMemory->maxAddres;i++)
	{
		cout << "Addres[" << i << "] = ";
		cin >> valou;
		if (valou == -1) return;
		theMemory->Write((byte)i, (byte)valou);
		cout << "��� �� ��������� ������� -1\n";
	}
}
int main()
{
	setlocale(0, "rus");
	cout << "�������� ������..." << endl;
	Memory* theMemory = new Memory();
	cout << "������" << endl;
	cout << "������ ������ = " << (int)theMemory->maxAddres<<endl;


	cout << "���������� ������:\n1.���������������\n2.�� ������" << endl;
	char posN;
	cin >> posN;
	switch (posN)
	{
	case '1':turn(theMemory);break;
	case '2':byNumber(theMemory);break;
	}
	
	

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