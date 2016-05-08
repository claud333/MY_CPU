#include <iostream>
#include "Memory.h"
#include "CPU.h"
using namespace std;
using namespace CPU_ilia;

int main()
{
	setlocale(0, "rus");
	cout << "Создание памяти..." << endl;
	Memory* theMemory = new Memory();
	cout << "Готово" << endl;

	cout << "Размер памяти = " << (int)theMemory->maxAddres<<endl;


	cout << "Заполнение памяти:\n1.Последовательно\n2.По номеру" << endl;

	theMemory->Write(1, 1);
	

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