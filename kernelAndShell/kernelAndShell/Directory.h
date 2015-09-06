#include <iostream>
#include <string>
#include <vector>
#include "File.h"

using namespace std;

#ifndef DirectoryClass
#define DirectoryClass
// const


/** This class Directory
 *
 * @param void
 * @return null
 * @precondition  Windows operating system.
 */
class Directory
{
	// attributes
		string working;
		string msName;
		string msPath;
		//string file;
		vector <Directory> moSubDir;
		vector <File> moFile;
		Directory * moParent;



	// methods;
	public:
		/** This function ...
		 *
		 * @param void
		 * @return null
		 * @precondition  Windows operating system.
		 */
		Directory();
		Directory(string);
		Directory(string, Directory *);
		string getName();
		string getPath();
		string getFile();

		bool makeSubDir(string);
		Directory changeToSubDir(string name);
		Directory getParent();
		int makeFile(string, bool, int);
		int makeFile(string, bool, int,int);
		bool delFile(string);
		int changeFile(string, int,bool);
		string dumpStructure();
		string dumpFiles();
		string listDir();
		string listFiles();
		void writeFat(string);


	private:



};



#endif