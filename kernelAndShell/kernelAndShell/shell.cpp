
// In addition, we also have the ability to access the registers;
// furthermore it should also be able to access the kernel systemCall() function;

// we will begin by defining Globals: 

// global;


//#include "Kernel.h"
#include "shell.h"

//#include "Kernel.cpp";
 




/** This is the default constructor of the Shell; It should set everything up. 
 *
 * @param void
 * @return null
 * @precondition  Windows operating system.
 */

Shell:: Shell()
{
	//sysCallNum=(0,1,2,3,4,5,6,7,8};
	sysCallNum=0;
	actionMsg=new char[100]; againMsg= new char[100];act= new char[4]; // limit act to 4 bytes;
	buff= new char[25];
	logHeap=new Log[500];	// logHeap default 500;
	//act=new char('0x0');
	error=0;	// starting the error default to 0;
     l=0;
     //display(kernelIO.getDefaultViewLocPointer()); // the kernel stores the default view location so it is // better protected;
     //// The above is almost like a startx command for something like ubuntu or BackTrack linux versions
     //display.setDate(kernelIO.getDateLocPoitner()); // Passing the location to where the hardware sends the date count. 
     //// this would depend on the system because we could also have this information stored directly in an accessible place in memory. 
	 
     ////display.startExplorer();
     //menu(); // begin the menu so we can now explow the functions. 
     
	working=" \n Shell working \n" ;
	cout << working << endl;
     
}

//Shell:: ~Shell()
//{
//     quit(); //do all primary quitting of variables;
//     // also worry about storing and logging information in a more permanent media;
//     
//     
//}
int Shell:: menu()
{
	cout << "default menu()"<< endl;
	/*
		The idea is the information is already stored within the main section of memory designated for 
		this program. Thus sets of chars that contain messages are already store and so on. 
		WHat is necessary is for those chars to be loaded into registers and outputted. 
		This is what the kernel will do. 
		SO, for example, the messages designated by the shell, are already stored, they simply 
		need to be loaded into the registers, according to their capacity,
		and outputted to screen. 
		
	*/
	
	n=0;
	
	/*while( n<100)
	{
		actionMsg[n]=NULL;
		n++;
	}*/
	n=0;
	actionMsg=NULL;
	againMsg=NULL;
	/*while( n<100)
	{
		againMsg[n]=NULL;
		n++;
	}*/
	actionMsg="which action would you like to take?\n create directory , a;\n change directory, b;\n copy file to, c;\n display ssytem date, d;\n contents of FIle, e;\n delete File, f;\n Display list of files in directory, g;\n quit, q;\n";
	cout << actionMsg<<"\t size of Msg: "<< sizeof(&actionMsg)<< endl;
	i=0;
	while (actionMsg[i]!=NULL)
	{
		/*for (int j=0;j<4;j++)
		{

		}*/
		setRegister2(actionMsg[i]);	// setting up to output message;
		systemCall(2);				// outputting message;
		cout <<actionMsg[i]<< '\t';
		i++;
	}
	
	systemCall(1);
	act=getRegister1();
	if(*act=='a')
	{
		n=0;
		/*while( n<100)
		{
			actionMsg[n]=NULL;
			n++;
		}*/
		actionMsg=NULL;
		actionMsg="Please give dir name : ";
		cout << actionMsg<<endl;//"\t size of Msg: "<< sizeof(&actionMsg)<< endl;

		error=createDir(act);
		log("a, ",error);
		return menu();

	}
	else if (*act=='b')
	{
		n=0;
		/*while( n<100)
		{
			actionMsg[n]=NULL;
			n++;
		}*/
		actionMsg=NULL;
		actionMsg="Please give dir name : ";
		cout << actionMsg<<endl;//"\t size of Msg: "<< sizeof(&actionMsg)<< endl;

		error=cd(act);
		log("b, ",error);
		return menu();
	}
	else if (*act=='c')
	{
		n=0;
		/*while( n<100)
		{
			actionMsg[n]=NULL;
			n++;
		}*/
		actionMsg=NULL;
		actionMsg="Please give path name to insert message: ";
		cout << actionMsg<<endl;//"\t size of Msg: "<< sizeof(&actionMsg)<< endl;
	
		error=copy(act);
		log("c, ",error);
		return menu();
	}
	else if (*act=='d')
	{
		cout << "system time: smiley time!  :) "<< endl;
		log("d, ",error);
		return menu();

	}
	else if (*act=='e')	//\n display contents of FIle, e;
	{
		n=0;
		/*while( n<100)
		{
			actionMsg[n]=NULL;
			n++;
		}*/
		actionMsg=NULL;
		actionMsg="Please give path name to insert message: ";
		cout << actionMsg<<endl;//"\t size of Msg: "<< sizeof(&actionMsg)<< endl;
	
		error=cat(act);	// getting the char array and setting the error variable. 
		log("e, ",error);
		return menu();
	}
	else if (*act=='f') //delete File, f;
	{
		n=0;
		/*while( n<100)
		{
			actionMsg[n]=NULL;
			n++;
		}*/
		actionMsg=NULL;
		actionMsg="Please give path name to insert message: ";
		cout << actionMsg<<endl;//"\t size of Msg: "<< sizeof(&actionMsg)<< endl;

		error=del(act);
		log("f, ",error);
		return menu();
	}
	else if (*act=='g')
	{
		n=0;
		/*while( n<100)
		{
			actionMsg[n]=NULL;
			n++;
		}*/
		actionMsg=NULL;
		actionMsg="Please give path name to insert message: ";
		cout << actionMsg<<endl;//"\t size of Msg: "<< sizeof(&actionMsg)<< endl;
		i=0;
		
		error=dir(act);	// Need to change this statement because the getCharArray Gets called 
		// first and stays in a loop;
		log("g, ",error);
		return menu();
	}
	else
	{
		return quit();
	}


	return 0;
}


int Shell:: menu(int choice)
{
	cout << "overloaded menu()"<< endl;
	return 0;

}
int Shell:: cat( char * fileName)
{
	setRegister2(fileName);
	return systemCall(5);
}

int Shell:: quit()
{
    /*itoa(error,buff,10); 
	string logInfo="";
	logInfo="errorcodes: "+*buff;
	log(logInfo);*/
     // log the information;
     // Will use a default position;
     return 0;

}

int Shell::start()
{
	return 0;
}

void Shell:: debug(int errorCode)

{
     // will go into a series of tests to log information. Based on this information
     // user is able to determine what was wrong with the system (after some anlysis);
}

void Shell:: log(string info, int err)
{
     // Throw all information, including time stamps to the top of a heap of data. This will be organized in a section of memory accessible by OS and privileged user. 
	//(*logHeap)[l]->error=err;logHeap->info=info;
	// I would write some code to dynamically expand the size of the logHeap array, but I don't have enough time to go 
	// to go that far.It's quite straight forward though;
	logHeap[l].error=err;
	logHeap[l].info=info;
	l++;

}




int Shell:: createDir(char * dirName)
{

	return 0;
}

int Shell:: cd(char * dirName)
{
	setRegister2(dirName);
	return systemCall(5);
	
}



int Shell:: dir(char * dirName)
{
	setRegister2(dirName);
	return systemCall(8);
}
 


int Shell:: copy(char * pathName)
{
	return 0;
}

int Shell:: del(char * fileName)
{
	return 0;
}


// Display 



char * Shell::  getCharArray()
{
	
		i=0;
		while (actionMsg[i]!=NULL)
		{
		
			setRegister2(actionMsg[i]);
			systemCall(2);
			cout <<actionMsg[i]<< '\t';	// testing purposes
			i++;
		}
		
		
		n=0;
		/*while( n<100)
		{
			
			againMsg[n]=NULL;
			n++;
		}*/
		act=NULL;
		againMsg=NULL;

		i=0;
		againMsg=NULL;
		while (*againMsg=='y')
		{
			systemCall(1);
			act=getRegister1();
			if (act[i]==NULL)
				*againMsg='n';
			/*else 
				*againMsg[i]='y';*/
			cout <<act[i]<< '\t';	// testing purposes
			i++;
		}
	return act;
}

void Shell:: date()
{


}
void Shell:: setdate(string date)
{


}

//char Shell:: outChar(char * charPointer)
//{
//
//	return 'a';
//}
char Shell:: outCharrAray(char * charPointer, int arraySize)
{
	return 'a';

}
