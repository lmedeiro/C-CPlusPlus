

#include <iostream>
#include <string>
#include "kernel.h"

using namespace std;

/** This class manages Shell functions 
 *
 * @param void
 * @return null
 * @precondition  Windows operating system.
 */
#ifndef ShellClass
#define ShellClass

struct Log
{
	string info;int error;
};

class Shell: public Kernel
{

	/* Register 00, system call vector Register;
	 Register 1 takes care of input related items; 
	 this includes storing and buffering for 
	 information coming in;
	 Register 2 takes care of output related items;
	 this means information going out;
	 Register 3 will take care of overflow errors;*/


	/*The Shell class will take care of testing and putting together the functionality 
	     of the Directory and File classes. 
	     The main goal is to provide functionality based on Kernel functions;
	     Thus, the initiated global kernel variable is a what the Shell relies on to fetch information from registers and actually output. 
	     The shell holds is a separate process altogether. 
	*/
	// attributes
	//Display display;
	string working;
	char *buff;
	int error;	// Will be used to collect errors;
	char * args;
	int sysCallNum;
	Kernel kernel;
	char * actionMsg;
	char * againMsg;
	char * act;
	int n,i,l;	// iterators;
	Log * logHeap;	// for logging the information;
	
	
	//File file;
	// methods;
	
	public: 
		Shell();
		
		/*
			which action would you like to take?
			\n create directory , a;
			\n change directory, b;
			\n copy file to, c;
			\n display ssytem date, d;
			\n display contents of FIle, e;
			\n delete File, f;
			\n Display list of files in directory, g;
			\n quit, q;\n";
			
		*/

		int quit();
		int start();
		void debug(int errorCode);
		int menu(); // will serve for utilizing menu functions and displaying the functionality;
		int menu( int choice);// overloaded with the number;
		void log(string info, int err);
		void test(); // will test the system;
		int cat(char * fileName);
		int createDir(char * dirName);
		int cd(char * dirName);
		//int dir();
		int dir(char * dirName);
		int copy( char * pathName);
		int del(char * fileName);

		
		
	private: 
		/* 
				 The following provides the functions to do the display looping and fetching information loop for the kernel and user. 
				 For example: outChar() will output only one char; outCharArray() will run a loop to direct the kernel to output a piece of information that is sitting on a block of memory;
				 For example, will will loop around for arraySize times, so to display that number of bytes. This means that the initial charPointer, which is pointing to the location where that information is, is incremented with each loop. 
				 This assumes that we are utilizing main memory to interact and allow usefulness. 
		*/
		char * getCharArray();
		void date();
		void setdate(string date); // set's the date which comes from a kernel accessible address only;
		
		//char outChar(char * charPointer); // points to the register with the info;
		char outCharrAray(char * charPointer, int arraySize); // output the array of chars and automatically updates the size of the output loop based on the arraySize input;
		// SO it will check with the register and output that many characters and update the pointer;
		

};
#endif