// Kernel pesudo Code
// Luiz Medeiros
/*

	initial consideration that we have 4 bytes per register ; 
	
	It follows that our nomenclature and comunnication procedures should abide to this;
	
	Handle I/O.  You can do it a byte at a time as the calls are done, or you could wait until a new line or close is performed and buffer the input/output
	
	when a file is opened, you could read a block of the file into kernel memory, and then pass back to the calling program data byte by byte or your could read the file a byte at a time and pass that byte.  Make sure you have a way to notify the calling program that the end of file was reached or that there was a newline entered on the keyboard
	
	
	

// algorithm  and pseudocode for the Kernel;

// Register 00, system call vector Register;
// Register 1 takes care of input related items; 
	// this includes storing and buffering for 
	// information coming in;
// Register 2 takes care of output related items;
	// this means information going out;
// Register 3 will take care of overflow errors;
/*
	
	In addition it should be noted that we have 4 registers of 4 bytes. 
	System calls that this kernel should support: 
		 0. Program Exit (with and without an error)
		 1. Accept one character of data from keyboard
		 2. Output one character of data to display
		 3. Create a file.
		 4. Open a file for input
		 5. Read the next byte from a file.
		 6. Close a file.
		 7. Request List Of Files in Current Directory
		 8. Display Current Directory Name
	
*/
#include "kernel.h"



// Register 1 takes care of input related items; 
	// this includes storing and buffering for 
	// information coming in;
// Register 2 takes care of output related items;
	// this means information going out;
// Register 3 will take care of overflow errors;

//fstream ioFile;

Kernel:: Kernel()
{
	buff= new char[4];
	//cout << "called kernel"<< endl;
	working=" \n kernel working \n" ;
	cout << working << endl;
	//dir=new Directory("root");
	//cout << dir->getName()<< endl;

	
}

Kernel:: ~Kernel()
{

}


int Kernel:: exit()// 0
{
	
	//int regErr=0,testErr=0;
	//regErr=~Registers(); // 0 if success, 1 if error;
	//
	//testErr=~Test(); // 0 if success, 2 if error;
	//error= regErr+testErr; // summing the error vectors;
	//// if only reg Err, error=1, if only testErr, error=2, if both, error = 3, else, error=0;
	//
	//// pass error to register 3;
	//reg[3][1]=error;
	cout << "reached exit()"<< endl;
	return 0;
	
}


int Kernel:: getChar() // 0x31
{
		char *   keyboard= new char();
		cout << "reached getChar(), insert char and press enter: "<< endl;
		/*for( int i=0;i<4;i++)
		{*/
			cin>> keyboard;
		//}
		setRegister1(keyboard);
		//// while there are no values to be retrieved, we keep going;
		////keyboard=usbPort; // usually set by hardware;
		//while (*keyboard==NULL)
		//{
		//	sleep(300); // wait 300 miliseconds;
		//		keyboard=usbPort; // usually set by hardware;
		//		// check port again; 
		//		// in our case, usb port will be a pointer to something containing the character;
		//}
		//// pass value of keyboard address to register 1;
		//reg[1]=*keyboard;
		
		return 0;
		
	
}
int Kernel:: outChar() // 0x32%
{
	cout << "reached outChar()"<< endl;
	char * buffReg2= new char[4];
	buffReg2= getRegister2(); // we buffer the content in the first register
	cout << *buffReg2 << endl; // then we allow the kernel to output the content;
	// in this case, the user only has 4 bytes of data per system Call;
	return 0;
}

int Kernel:: createF() // 0x33
{
	cout << "reached createF()"<< endl;

		//// creating file assumes an output type of behaviour;
		//// file name will be expected in reg2
		//// file location will be expected in reg 3, overflow; 
		//
		//char * fileLocation= new char[minSize];
		//char * fileName= new char[maxNameSize];
		//fileLocation= getRegister3();
		//fileName= getRegister2();
		//
		//ioFile.open(fileName,ios::out);
		//iofFile.close();
		oFile.open("newFile.txt");
		oFile << "new file text\n";
		//oFile.close();
			
		int errorCode= closeF(); // by default 0, or success;
		// perform error checking before returning erroCode;
		return errorCode;
}

int Kernel:: openInput() // 0x34
{
	cout << "reached openInput()"<< endl;
		//char * fileLocation= new char [fileSize];
		//char *fileName=new char [maxNameSize];
		//fileLocation=getRegister3();
		//fileName=getRegiser1(); // register 1 since we are going for input
		//
		//ioFile.open(fileName,ios::out);
	return 0;
	
}

int Kernel:: readB()	// 0x35
{
	cout << "reached readB()"<< endl;
		//char * location= new char[4]; // four bytes coming from the register;
		//// will access register 1 for location to read byte from;
		//location=getRegister1();
		//ioFile.seekg(location);
		//char * data=new char; // data byte pointer;
		//ioFile.get(data); // passing the byte to the data byte pointer;
		//return setRegister(data); // basically we return the error code from the data retrieved; 
		return 0;
		
	
}

int Kernel:: closeF()	//0x36
{
	cout << "reached closeF()"<< endl;
	 oFile.close();
	 return 0;
	
}

int Kernel:: getList()	//0x37
{
	cout << "reached getList()"<< endl;
		// assuming we are on a windows system;
		//string fileList=System("DIR" );
		//return setRegister1(&fileList); // we send in the address of where this information is stored, so the program may refer to it;
		return 0;
	
}

int Kernel:: displayDirName()	//0x38
{
	cout << "reached displayDirName()"<< endl;
	system("dir");
	return 0;
}

int Kernel :: systemCall (int sysVec)
{
		// switch case with different vectors in register0 to call proper system call;
		// system call vectors are processed in hex; 
		itoa(sysVec,buff,16);
		cout << "buff/sysVec: "<< buff << endl;
		switch(*buff)
		{
			case '0':
				exit();
				return 0;
			
			case '1':
				setRegister3(getChar());return 0;
			case '2':
				setRegister3(outChar());return 0;
			case '3':
				setRegister3(createF());return 0;
			case '4': 
				setRegister3(openInput());return 0;
			case '5': 
				setRegister3(readB());return 0;
			case '6': 
				setRegister3(closeF());return 0;
			case '7': 
				setRegister3(getList());return 0;
			case '8': 
				setRegister3(displayDirName());return 0;
			case '9':
				setRegister3(deleteFile());return 0;
			case '10':
				setRegister3(copyFile());return 0;
			default: 
				cout << "incorrect system Vector for System Call"<< endl;
				cout << "Entering Debug Mode;"<< endl;
				debugMode(); // an eventual debug Mode for correcting errors;
				return -1;
			
		}

}
int Kernel:: deleteFile()
{
	return 0;
}
int Kernel:: copyFile()
{
	return 0;
}
int Kernel:: getErrorCode()
{
	return 0;
}
void Kernel:: debugMode()
{

}
int Kernel:: testProgram()	
{
	//int i=0;
	//// enquire for number from the console: 
	//int n=0;
	//// we will assume a continuous array of memory for our program 
	//// we will use a variable that is called pMain, which will be an array of bytes that is sufficient for our needs;
	//char * pMain=new char[1000]; // initially 1000 bytes;
	//// we will then subdivide the pMain into out, for output items and input for input ;
	//
	//	char * output= new char[500]; // these are the temporary pointers which will then pass their values to the main pointer memory pointer int heir repsective memory location;
	//	char * input= new char[500];
	//	
	//	// since the goal is to get a char, we will follow with the necessary procedures;
	//	
	//	// First we inquire the user for a character.
	//	// This will allow us to 
	//	output= " please input a character: " ;
	//	while (n<getOutputMessageSize())
	//	{
	//	  setRegister2(output[n]); // setting the register to a respective byte to output. 
	//	  systemCall(2); // output the char to accordingly.
	//	  
	//	}
	//	
	//systemCall(1); // pickup the char and put it in the input register;
	//input=getRegister0(); // we now have the char in our memory address;
	//// Now we have the character int the pointer which signifies our internal memory input area;
	//n=getInputMessageSize(); // getting the size of the input message, which may be up to 4 bytes;
	///// now we can go on  to append something to this message and output it again;
	//
	//
	//systemCall(0);

	return 0;
	
	
}