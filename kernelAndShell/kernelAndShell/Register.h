

#include <iostream>
//#include <stdlib.h>
#include <string>

using namespace std;

/** This class manages Register functions 
 *
 * @param void
 * @return null
 * @precondition  Windows operating system.
 */
#ifndef RegistersClass
#define RegistersClass
class Registers
{
	// attributes
	string working;
	char *  buffer;
	char * reg[4][4]; // 4 registers by with 4 bytes each ; n x m ; n registers with m bytes;

	// Methods
	
	/* Register 00, system call vector Register;
	 Register 1 takes care of input related items; 
	 this includes storing and buffering for 
	 information coming in;
	 Register 2 takes care of output related items;
	 this means information going out;
	 Register 3 will take care of overflow errors;*/


public: 
	Registers();
	~Registers();
	void setRegister0(int);
	void setRegister1(char);
	void setRegister1(char * param);
	void setRegister2(int param);
	void setRegister2(char param);
	void setRegister2(char * param);
	void setRegister3(int param);
	void setRegister3(char param);
	void setRegister3(char * param);
	char * getRegister0 ();
	char * getRegister1 ();
	char * getRegister2 ();
	char * getRegister3 ();
	



};
#endif