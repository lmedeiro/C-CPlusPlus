
#include "Directory.h"

Directory:: Directory()
{
	msName="default0";
	msPath="/";

}
/** default constructor;
		 *
		 * @param void
		 * @return null
		 * @precondition  Windows operating system.
		 */
Directory:: Directory(string name)
{
	
	msName=name;
	msPath="/";

	working="\n Directory working \n";
	cout << working;
	//file=newFile(size);
	
	
	
}
/** Passing parent through the constructor to keep track of hierarchy;
		 *
		 * @param void
		 * @return null
		 * @precondition  Windows operating system.
		 */
Directory:: Directory(string name,  Directory * parent)
{

	msName=name;
	//char * buff= new char[100];
	//buff=(&parent)->getPath();

	msPath=""+ parent->getPath()+parent->getName()+"/";
	moParent= parent;
	//moSubDir(moParent);
	//moSubDir[0]=moParent;
}
// getters
string Directory::getName()
{
	return msName;
}
// getters
string Directory::getPath()
{
	return msPath;
}
// getters
string Directory:: getFile()
{


	return "";
}

/** 'Make Sub Directory (Name)  Returns Boolean
    '   Check to see if Directory already exists
    '	    If yes – Return Error (False)
    '   Instance a new Directory class with name and parent
    '   Add to the list of Sub-Directories
    '	Return True
		 *
		 * @param string dirName
		 * @return bool
		 * @precondition  Windows operating system.
		 */
bool Directory:: makeSubDir(string dirName)
{
	
	if (moSubDir.size()==0)
	{
		
		Directory oSubDir(dirName,this);
		moSubDir.push_back(oSubDir);	// inserting the new directory into the vector;
		return true;
	}
	for (int i=0;i<moSubDir.size();i++)
	{
		
		if(moSubDir[i].getName()==dirName)
			return false;
	}
	Directory oSubDir(dirName,this);
	moSubDir.push_back(oSubDir);	// inserting the new directory into the vector;


	return true;
}
/** 'Change to Sub-Directory (Name) Return Pointer to Directory Class (or nothing/null)
    '   Go Through List of Sub-Directories
    '   If we find it, return it
    '   Otherwise return null/nothing/zippo/zilch
		 *
		 * @param string name
		 * @return Directory
		 * @precondition  Windows operating system.
		 */
Directory Directory::changeToSubDir(string name)
{
	int i=0;
	for (;i<moSubDir.size();i++)
	{
		if(moSubDir[i].getName()==name)
			return moSubDir[i];

	}
	
	Directory dummy("null");
	return dummy;
}

Directory Directory::getParent()
{
	
	return *moParent;
}

/** 'Make File (Name, Size, Read-Only Switch) Boolean (Success or Fail)
    '   See if file name already used
    '	    If Yes – Return false
    '   Instance a new class (pass in the stuff)
    '   If successful (cluster pointer is not -1)  (Need to change that)
    '	    Add to the list of files and return OK
    '   else
    '	    Return Error
    ' TODO Would we rather return an error code?
		 *
		 * @param void
		 * @return null
		 * @precondition  Windows operating system.
		 */
int Directory::makeFile(string name, bool readOnly, int size)
{
	if (moFile.size()==0)
	{
		File newFile(name,readOnly,size);
		moFile.push_back(newFile);
		
		return 0;
	}
	for (int i=0;i<moSubDir.size();i++)
	{
		if(moFile[i].getFileName()==name)
			return -2;
	}

	File newFile(name,readOnly,size);
	moFile.push_back(newFile);
	return 0; 
}

/** 'Make File (Name, Size, Read-Only Switch) Boolean (Success or Fail)
    '   See if file name already used
    '	    If Yes – Return false
    '   Instance a new class (pass in the stuff)
    '   If successful (cluster pointer is not -1)  (Need to change that)
    '	    Add to the list of files and return OK
    '   else
    '	    Return Error
    ' TODO Would we rather return an error code?
		 *
		 * @param void
		 * @return null
		 * @precondition  Windows operating system.
		 */
int Directory::makeFile(string name, bool readOnly, int size, int start)
{
	

	File newFile(name,readOnly,size,start);
	moFile.push_back(newFile);
	return 0; 
}

/** '    Del File (Name) Int (Error Code)
    '	Find the correct File Class in the File List
    '		Not Found (Return Error Code)
    '	Call the File Class Delete Method
    '		If Successful – Return OK
    'Else Return Error Code
 *
 * @param void
 * @return null
 * @precondition  Windows operating system.
 */
bool Directory::delFile(string name)
{
	for (int i=0;i<moSubDir.size();i++)
	{
		if(moFile[i].getFileName()==name)
		{
			cout << "before deletion: "<< moFile[i].getFileName()<< endl;
			moFile[i].fDeleteFile();
			moFile.erase(moFile.begin()+i);
			cout << "after deletion: "<< moFile[i].getFileName()<< endl;
			return true;
		}
			
	}
	return true;
}
/** 'Chg File (Name, Size) Int (Error Code)
    'Chg File (Name, Read-Only Flag) Int (Error Code)
    'Chg File (Name, Size, Read-Only Flag) Int (Error Code)
    '   Find the correct File Class in the File List
    '	    Not Found (Return Error Code)
    '   Call the File Class Change Method
    '	    If Successful – Return OK
    '	    Else Return Error Code
 *
 * @param void
 * @return null
 * @precondition  Windows operating system.
 */
int Directory::changeFile(string name, int size,bool readOnly)
{
	for (int i=0;i<moSubDir.size();i++)
	{
		if(moFile[i].getFileName()==name)
		{
			bool bReturn= moFile[i].changeFile(size,readOnly);
			if (bReturn==false)
				return -1;

			return 0;
		}
			
	}
	return -2; // Error, not found;
}
/** This class Directory; contains recursion; 
 *
 * @param void
 * @return null
 * @precondition  Windows operating system.
 */
string Directory::dumpStructure()
{
	string structure=""+getPath()+getName()+"\n";
	structure=structure+dumpFiles();
	for (int i=0; i<moSubDir.size();i++)
	{
		structure=structure+ moSubDir[i].dumpStructure();
	}
	return structure;
}
/** dumping the files;
 *
 * @param void
 * @return null
 * @precondition  Windows operating system.
 */
string Directory::dumpFiles()
{
	string fileList="";
	char * buffSize=new char[25];
	char * buffBool=new char[25];
	for (int i=0; i< moFile.size();i++)
	{
		itoa(moFile[i].getReadOnly(),buffBool,10);
		itoa(moFile[i].getFileSize(),buffSize,10);
		fileList=fileList+" "+ moFile[i].getFileName()+" "+ buffSize+" "+ buffBool+" "+ moFile[i].getCluster(moFile[i].getStartCluster())+"\n";
	}
	return fileList;
}
/** This class Directory
 *
 * @param void
 * @return null
 * @precondition  Windows operating system.
 */
string Directory::listDir()
{
	string structure=getPath()+getName()+"\n";

	structure=structure+listFiles();
	for ( int i=0;i<moSubDir.size();i++)
	{
		structure=structure+moSubDir[i].listDir();
	}


	return structure;
}
/** Dumping information without date of creation, because I don't have enough time :) 
 *
 * @param void
 * @return null
 * @precondition  Windows operating system.
 */
string Directory::listFiles()
{
	string fileList="";
	char * buffSize=new char[25];
	char * buffBool=new char[25];
	for (int i=0; i< moFile.size();i++)
	{
		itoa(moFile[i].getReadOnly(),buffBool,10);
		itoa(moFile[i].getFileSize(),buffSize,10);
		fileList=fileList+" "+ moFile[i].getFileName()+" "+ buffSize+" "+ buffBool+" "+ "time of creation :)" +"\n";
	}
	return fileList;
	
}
/** ' Method used to dump all information for the directory struture to disk for reloading later
    ' We will then write one line for each directory and for each file with a code at the 
    ' start to let the Read routine know what it is starting at the root directory and working 
    ' our way down.  Also, we may want to do part of this in the main program instead of 
    ' this class.
    '	Write “D”+Directory Name
    '	For each file in the current directory
    '		Write “F” + Name + Size + Mode + Starting Cluster
    '	For each directory in current directory
    '		Call Write routine in that directory
 *
 * @param void
 * @return null
 * @precondition  Windows operating system.
 */
void Directory::writeFat(string)
{
	/*
		I already have something that will test the functionality of this. Since I don't have much time left, I will leave this
		function as is, because it is just outputting things to file or to something that resembles a disk.
	*/
}