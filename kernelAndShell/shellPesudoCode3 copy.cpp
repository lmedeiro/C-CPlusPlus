// This is the pesudo code for the shell;
// as noted through the design, the shell will have different classes, where the main parent class is the " Shell" class;
// So we are allowing the shell to be able to access it's portion in memory. 
// In addition, we also have the ability to access the registers;
// furthermore it should also be able to access the kernel systemCall() function;
// Let's pretend that there is already a preset API for accessing our Kernel, and this API allows us to get the systemCall() function to perform these wonderful features for us. 

// we will begin by defining Globals: 

// global;


#include "Kernel.h";

//#include "Kernel.cpp";
 
Kernel kernelIO; // declarating the kernel for IO so it may be accessed by any of the classes;

// !global;

// class declarations
class Shell 
{
	/*The Shell class will take care of testing and putting together the functionality 
	     of the Directory and File classes. 
	     The main goal is to provide functionality based on Kernel functions;
	     Thus, the initiated global kernel variable is a what the Shell relies on to fetch information from registers and actually output. 
	     The shell holds is a separate process altogether. 
	*/
	// attributes
	Display display;
	int error;
	char * args;
	
	Directory dir;
	File file;
	// methods;
	
	public: 
		Shell();
		//Shell ()
		~Shell();
		
	private: 
		int quit();
		int start();
		void debug(int errorCode);
	 int menu(); // will serve for utilizing menu functions and displaying the functionality;
	 int menu( int choice);// overloaded with the number;
		void log(string info);
		void test(); // will test the system;
		int systemCall(int call); // will take call the kernel's systemCall();
	
	
};

class Directory
{
	/*
		     The directory class will provide aid with all that has to do with directory functionality;
		     Thus we will be referring back to this object whenever it is necessary to do some operation to the directory, such as changing paths, displaying information regarding directory, or goign to a certain directory;
	*/
	// attributes
	char * name;
	char * path;
	char * fileNames; // will point to an array of bytes to store the names of the 
	// files within the given directory. May dynamically expand as needed; 
	
	// methods
	
	public: 
		Director();
		Directory(char * defaultPath);
		~Directory();
		
	private: 
		int cd();
		int cd(char * dirName);
		int dir();
		int dir(char * dirName);

		
	
};

class File
{
	
	/* 
		     This class provides the copy file and delete file functions; 
	*/
	
	// attributes
	char * name;
	
	// methods
	
	public: 
		File();
		File(char *pathName);
		~File();
	private:
		int copy( char * pathName);
		int deleteFile(char * fileName);
	
	
};

class Display
{
	/* 
		     This class provides the functions to do the display looping and fetching information loop for the kernel and user. 
		     For example: outChar() will output only one char; outCharArray() will run a loop to direct the kernel to output a piece of information that is sitting on a block of memory;
		     For example, will will loop around for arraySize times, so to display that number of bytes. This means that the initial charPointer, which is pointing to the location where that information is, is incremented with each loop. 
		     This assumes that we are utilizing main memory to interact and allow usefulness. 
	*/
	
	// attributes
	int sysCallNum;
	
	
	// methods
	
	public: 
		Display();
		Display( char * command);
		~Display();
	
	private: 
		int getCharArray();
		void date();
		void setdate(string date); // set's the date which comes from a kernel accessible address only;
		
		char outChar(char * charPointer); // points to the register with the info;
		char outCharrAray(char * charPointer, int arraySize); // output the array of chars and automatically updates the size of the output loop based on the arraySize input;
		// SO it will check with the register and output that many characters and update the pointer;
		
	
	
};


// ! class declarations





// Shell class;


void Shell:: Shell()
{
      
     Directory directory( kernelIO.getDefaultDirPointer()); // sets the current default directory;
     File file; // starting the file object;
     
     Display display; // starting the display;
     
     display(kernelIO.getDefaultViewLocPointer()); // the kernel stores the default view location so it is // better protected;
     // The above is almost like a startx command for something like ubuntu or BackTrack linux versions
     display.setDate(kernelIO.getDateLocPoitner()); // Passing the location to where the hardware sends the date count. 
     // this would depend on the system because we could also have this information stored directly in an accessible place in memory. 
	 
     //display.startExplorer();
     menu(); // begin the menu so we can now explow the functions. 
     
     
}

void Shell:: ~Shell()
{
     quit(); //do all primary quitting of variables;
     // also worry about storing and logging information in a more permanent media;
     
     
}

void Shell:: quit()
{
     log();
     // log the information;
     // Will use a default position;
     

}

int Shell::start()
{

}

void Shell:: debug()

{
     // will go into a series of tests to log information. Based on this information
     // user is able to determine what was wrong with the system (after some anlysis);
}

int Shell:: log()
{
     // Throw all information, including time stamps to the top of a heap of data. This will be organized in a section of memory accessible by OS and privileged user. 
}

int Shell:: systemCall(int callNum)
{
     return kernelIO.systemCall(callNum); // making the system call and returning any error code;
     // which is what the system call returns;
} 

// Directory Class;

Directory:: Directory()
{
     // constructor. Needs to set the default directory path in the case none have been passed as arguments. 
     path = new char();
     // above declaration will allocate enough information for a one byte address. 
     // This information may be retained by the operating system, since it will direct the shell to start at a certain path. 
     name= new char();
	    
	    fileNames=new char[256]; // points to an array of 256 bytes of info to begin the name 
	    // index storing. Thus we can use these to store the names of directories and files within this 
	    // this directory;
	
}



void Shell:: cd()
{

}

void Shell:: cd()
{

}

void Shell:: dir()
{

}

void Shell:: dir()
{

}
 

// File Class;


int Shell:: copy()
{

}

int Shell:: del()
{

}


// Display Class;

