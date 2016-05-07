#ifndef MEMORY_H
#define MEMORY_H
namespace CPU_ilia
{
	typedef unsigned char byte;
	class Memory
	{
	public:
		const byte maxAddres;
	private:
		byte *spaceAddres;
	public:
		Memory();
		~Memory();
		void Clear();
		const byte& Read(const byte &addres);
		void Write(const byte &addres,const byte &valou);
	
	};


}



#endif
