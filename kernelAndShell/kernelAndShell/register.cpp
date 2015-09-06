
#include "Register.h"

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
Registers:: Registers ()
{
	buffer=new char;
	int n=0,m=0;
	working=" \n Registers working \n" ;
	cout<< working << endl;
	//while (n<4)
	//{
	//	while (m<4)
	//	{
	//		reg[n][m]=new char;
	//		*reg[n][m]=0xFF; // setting each byte to high so that the appropriate value can then be passed;
	//		// or we can change the convention by 0x0 which would be NULL in the ascii table. However, initial values are always 0xFF;
	//	}
	//	
	//}
	
}
Registers:: ~Registers ()
{
	
}

// Vector numbers range from 0x30 to 0x38 -> decimal equivalent of 0-> 8;
void Registers:: setRegister0( int param )
{
		//int n=0;
		//while( n<4)
		//{
		//	reg[0][n]=NULL;
		//	n++;
		//}// We clear the register so to guarantee a clean access. 
		//
		//itoa(callVector,buffer,10) ; // will need to do the parsing to a hex;
		//for (n=0;n<4;n++)
		//{
		//	if(reg[0][n]==NULL)
		//		*reg[0][n]=*buffer;
		//	else
		//	{
		//		 buffer="register full";
		//		 setRegister3(buffer);	// outputting the error;
		//	}
		//		
		//}
		//cout << "finished setting register" << endl;	// for debugging purposes;

		int n=0;
		char * p= new char('0');
		itoa(param,p,10);
		*p=param;
		while (n<4)
		{
			reg[0][n]=NULL;n++;
		}
		*reg[0]=p;
}	

void Registers:: setRegister1(char param)
{
	int n=0;
	char * p= new char('0');
	*p=param;
	while (n<4)
	{
		reg[1][n]=NULL;n++;
	}
	*reg[1]=p;
	
}

void Registers:: setRegister1(char * param)
{
	int n=0;
	while (n<4)
	{
		reg[1][n]=NULL;
		n++;

	}
	*reg[1]=param;
	
	
}
void Registers:: setRegister2(int param)
{
	//reg[2]=NULL;	// assuming the integer passed is 32bit. 
	//reg[2]=param; // just providing simple pseudocode
	int n=0;
	char * p= new char('0');
	itoa(param,p,10);
	*p=param;
	while (n<4)
	{
		reg[2][n]=NULL;
		n++;
	}
	*reg[2]=p;
	
	
}
void Registers:: setRegister2(char param)
{
	int n=0;
	char * p= new char('0');
	*p=param;
	while (n<4)
	{
		reg[2][n]=NULL;
		n++;
	}
	*reg[2]=p;
	
	
}
void Registers:: setRegister2(char * param)
{
	int n=0;
	while (n<4)
	{
		reg[2][n]=NULL;
		n++;
	}
	*reg[2]=param;
	
}
void Registers:: setRegister3(int param)
{
	//reg[3]=NULL;	// assuming the integer passed is 32bit. 
	//reg[3]=param; // just providing simple pseudocode
	
	
}
void Registers:: setRegister3(char param)
{
	//int n=0;
	//while (n<4)
	//	if the first byte in the reg[3] == NULL
	//		insert param in reg[3][n];
	//	else
	//		n++;
	//
	//
	
}
void Registers:: setRegister3(char * param)
{
	//int n=0;
	//while (n<4)
	//	if the first byte in the reg[3] == NULL
	//		insert *param in reg[3][n];
	//	else
	//		n++;
	//
	
}
char * Registers :: getRegister0 ()
{
	
	char * outC=new char('0');

	outC=NULL;
		
	outC=*reg[0];
	return outC;
}


char * Registers :: getRegister1 ()
{
	char * outC=new char('0');
	/*for (int i=0;i<4;i++)
	{*/
		outC=NULL;//*reg[2][i];
		
	//}
	outC=*reg[1];
	return outC; //to_int_type(reg[2]);
	//return *reg[3];// to_int_type(reg[1]);
	
}

char * Registers :: getRegister2 ()
{
	char * outC=new char('0');

	outC=NULL;
		
	outC=*reg[2];
	return outC;
	
}


char * Registers :: getRegister3 ()
{
	char * outC=new char('0');

	outC=NULL;
		
	outC=*reg[3];
	return outC;
	
}
		
