#ifndef CPU_H
#define CPU_H
#include "Memory.h"
namespace CPU_ilia
{
	class CPU
	{
	private:
		 byte startAddres; byte endAddres;
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
		void Decod(const byte &valou);
		void Work();
		void setStartAddres( byte &start);
		void setEndAddres( byte &end);
		



	};









}
#endif
