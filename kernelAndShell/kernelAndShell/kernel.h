
#include <iostream>
#include <string>
#include <fstream>
#include "Register.h"
#include "Directory.h"
using namespace std;

/** This class manages Kernel functions 
 *
 * @param void
 * @return null
 * @precondition  Windows operating system.
 */
#ifndef KernelClass
#define KernelClass
class Kernel: public Registers,public Directory
{

	// attributes
	char *  buff;
	//char reg[4][4]; // 4 registers by with 4 bytes each ; n x m ; n registers with m bytes;
	string working;
	//Directory * dir;



	// methods
	int exit();// 0x30;
	int getChar(); // 0x31
	int outChar(); // 0x32
	int createF(); // 0x33
	int openInput(); // 0x34
	int  readB();	// 0x35
	int  closeF();	//0x36
	int getList();	//0x37
	int displayDirName();	//0x38
	int deleteFile();//0x39
	int copyFile();//0xA

	int testProgram();
	void debugMode();
	ifstream iFile;
	ofstream oFile;

public: 

	Kernel();
	~Kernel();
	int systemCall(int);
	int getErrorCode();





};


#endif