#include "Memory.h"
namespace CPU_ilia
{
	Memory::Memory():maxAddres(255), spaceAddres(new byte[maxAddres])
	{
		Clear();
	}

	Memory::~Memory()
	{
		if (spaceAddres !=nullptr)
		{
			delete[] spaceAddres;
			spaceAddres = nullptr;
		}
	}
	void Memory::Clear()
	{
		for (int i = 0;i < maxAddres;++i)
		{
			spaceAddres[i] = 0;
		}
	}
	const byte& Memory::Read(const byte &addres)
	{
		return spaceAddres[addres];
	}
	void Memory::Write(const byte &addres,const byte &valou)
	{
		spaceAddres[addres] = valou;
	}


}