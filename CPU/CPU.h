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
		byte Register_0; byte Register_1; byte Register_2;
		byte programCounter;
		Memory* CPU_theMemory;
		bool F_Halt; bool F_error;
	public:
		CPU(Memory* takeMemory);
		~CPU();
		void Add();
		void Div();
		void Mul();
		void Halt();
		void error();
		void BiP();
		void Decod(const byte &valou);
		void Work();
		



	};









}
#endif
