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
		byte Register_0; byte Registr_1; 
		byte saveAddres;
		byte programCounter;
		Memory* CPU_theMemory;
	public:
		CPU();
		~CPU();
		const byte Featch();
		void Decod(const byte &valou);
		



	};









}
#endif
