
#include <iostream>
#include <string>
#include "FATCluster.h"

using namespace std;

#ifndef FileClass
#define FileClass
// const


/** This class File; it inherits from the FATCLuster Class;
 *	Manages files ;
 * @param void
 * @return null
 * @precondition  Windows operating system.
 */
class File: public FATCluster 
{
	// attributes
		string working;
		string msName;
		bool mbReadOnly;
		int mnSize;
		string date;
		int mnFatEntry;

	// methods;
	public:
		/** This is a dummy description ...
		 *
		 * @param void
		 * @return null
		 * @precondition  Windows operating system.
		 */
		File();
		File(string, bool, int);
		File(string,bool,int,int);

		string getFileName();
		bool getReadOnly();
		string getDate();
		int getFileSize();
		int getStartCluster();
		void fDeleteFile();
		bool changeFile(int, bool);



	private:



};



#endif