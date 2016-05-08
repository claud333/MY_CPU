#include "CPU.h"
#include <iostream>
namespace CPU_ilia
{
	CPU::CPU(Memory* takeMemory)
		:
		CPU_theMemory(takeMemory),
		startAddres(1),
		endAddres(253),
		programCounter(startAddres),
		F_Halt(false),
		F_error(false)
	{
	}

	CPU::~CPU()
	{
		CPU_theMemory = nullptr;
	}
		

	void CPU::Halt()
	{
		F_Halt = true;
	}

	void CPU::error()
	{
		F_error = true;
	}

	void CPU::Add()
	{
		programCounter++;
		Register_2 = CPU_theMemory->Read(programCounter);
		Register_0 = CPU_theMemory->Read(CPU_theMemory->Read(programCounter));
		programCounter++;
		Register_1 = CPU_theMemory->Read(CPU_theMemory->Read(programCounter));
		programCounter++;
		Register_0 = Register_0 + Register_1;
		CPU_theMemory->Write(Register_2, Register_0);
   }
	void CPU::Div()
	{
		programCounter++;
		Register_2 = CPU_theMemory->Read(programCounter);
		Register_0 = CPU_theMemory->Read(CPU_theMemory->Read(programCounter));
		programCounter++;
		Register_1 = CPU_theMemory->Read(programCounter);
		if (Register_1 == 0) { error(); Halt();return; }
		programCounter++;
		Register_0 = Register_0 / Register_1;
		CPU_theMemory->Write(Register_2, Register_0);
	}

	void CPU::Mul()
	{
		programCounter++;
		Register_2 = CPU_theMemory->Read(programCounter);
		Register_0 = CPU_theMemory->Read(CPU_theMemory->Read(programCounter));
		programCounter++;
		Register_1 = CPU_theMemory->Read(programCounter);
		programCounter++;
		Register_0 = Register_0 * Register_1;
		CPU_theMemory->Write(Register_2, Register_0);
	}

	void CPU::Decod(const byte &valou)
	{
		if (F_error || F_Halt) { return; }
		switch (valou)
		{
		case 1:Add();break;
		case 2:Div();break;
		case 3:Mul();break;
		}
	}
	void CPU::Work()
	{
		while (!F_Halt)
		{
			Decod(CPU_theMemory->Read(programCounter));
			programCounter++;
			if (programCounter >= endAddres) { Halt(); }
		}
		
	}
   
	void CPU::setStartAddres( byte &start)
	{
		while (start >= 254||start<0) { std::cout << "Выход за перелы памяти!";std::cin >> start; }
		startAddres = start;
		programCounter = start;
	}
	void CPU::setEndAddres( byte &end)
	{
		while (end >= 254||end<0) { std::cout << "Выход за перелы памяти!";std::cin >> end; }
		endAddres = end;

	}





}