#include "CPU.h"
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





}