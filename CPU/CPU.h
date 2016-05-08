#ifndef CPU_H
#define CPU_H
#include "Memory.h"
namespace CPU_ilia
{
	class CPU
	{
	public:
		const byte startAddres; const byte endAddres;
	private:
		byte Register_0; byte Registr_1; byte Registr_2;
		byte programCounter;
		Memory* CPU_theMemory;
		bool F_Halt; bool F_error;
	public:
		CPU(Memory* takeMemory);
		~CPU();
		const byte Featch(const byte &addres);
		void Print(const byte &Register_addres, const byte &Registor_valou);
		void Add();
		void Halt();
		void error();
		void Decod(const byte &valou);
		



	};









}
#endif
