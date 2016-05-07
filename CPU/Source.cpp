#include <iostream>
#include "Memory.h"
using namespace std;
using namespace CPU_ilia;

int main()
{
	setlocale(0, "rus");
	cout << "Создание памяти..." << endl;
	Memory* theMemory = new Memory();
	cout << "Готово" << endl;

	cout << "Размер памяти = " << (int)theMemory->maxAddres<<endl;


	cout << "Заполнение памяти по умолчанию" << endl;
	theMemory->Write(1, 1);
	theMemory->Write(2, 1);

	// Load1 Value 2
	theMemory->Write(3, 2);
	theMemory->Write(4, 2);

	// Add
	theMemory->Write(5, 3);

	// Store to 12
	theMemory->Write(6, 5);
	theMemory->Write(7, 12);

	// Print from 12
	theMemory->Write(8, 6);
	theMemory->Write(9, 12);

	// Beep
	theMemory->Write(10, 4);

	// HALT
	theMemory->Write(11, 0);
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
	system("pause");
}