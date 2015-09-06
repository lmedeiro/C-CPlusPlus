

#include <iostream>
#include <string>
using namespace std;

#ifndef FATClusterClass
#define FATClusterClass

// const def;



/** This class manages the Clusters that will be set up for the FAT System.
Thus, this performs the fundamental functions to set up for new files, direcotories, etc..
 *
 * @param void
 * @return null
 * @precondition  Windows operating system.
 */
class FATCluster
{
	// attributes
		static const int mnNumberClusters=256;	// constants for number of clusters;
		static const int mnClusterSize=4096;	// constants for cluster size
		int * mnHead;	// pointer to head
		int * mnTail;	// pointer to tail
		string working;	// Debug
		int * FAT;	// Pointer to the FAT Table
		bool setupError;


	// methods;
	public:
		/** This is a dummy description ...
		 *
		 * @param void
		 * @return null
		 * @precondition  Everything linked properly
		 */
		FATCluster();
		int getHead();
		int getTail();
		int getClusterSize();
		int getNumClusters();
		
		int newFile(int);
		bool deleteFile(int) ;
		bool addCluster(int);
		int deleteCluster(int);
		string getCluster(int);
		string dumpClusters();
		string writeClusters();
		bool readClusters(string);

		
	private:
		
		bool setupFAT( int *); // sets up the intitial FAT SYstem;

};



#endif
