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
		cout << "Введите номер ячейки\tЧто бы закончить введите -1" << endl;
		cin >> addres;
		if (valou == -1 || addres == -1) return;
		cout << "Введите значение" << endl;
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
		cout << "Что бы закончить введите -1\n";
	}
}
int main()
{
	setlocale(0, "rus");
	cout << "Создание памяти..." << endl;
	Memory* theMemory = new Memory();
	cout << "Готово" << endl;
	cout << "Размер памяти = " << (int)theMemory->maxAddres<<endl;


	cout << "Заполнение памяти:\n1.Последовательно\n2.По номеру" << endl;
	char posN;
	cin >> posN;
	switch (posN)
	{
	case '1':turn(theMemory);break;
	case '2':byNumber(theMemory);break;
	}
	
	

	cout << "Показать значение ячеек памяти?\nY/N\n";
	char yesNo;
	cin >> yesNo;
	if (yesNo == 'Y' || yesNo == 'y')
	{
		for (byte i = 0;i < theMemory->maxAddres;i++)
		{
			cout << "Addres[" << (int)i << "] = " << (int)theMemory->Read(i)<<endl;
		}
	}
	cout << "Создаем процессор..." << endl;
	CPU* theCPU = new CPU(theMemory);
	cout << "Готово" << endl;

	



	cout << "Запускаем..." << endl;
	theCPU->Work();
	cout << "Завершено" << endl << endl;;

	cout << "Показать значение ячеек памяти?\nY/N\n";
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