/*
	Implementation of the FATCluster; 
*/

#include "FATCluster.h"

using namespace std;


// public

/** This is a function is the contructor of the FATCluster class;
	Here, everything is set up for initial run of the functions;
		 *
		 * @param void
		 * @return null
		 * @precondition  Everything linked properly
		 */
FATCluster:: FATCluster()
{
	working=" \nFAT Cluster working \n" ;
	cout << working << endl;	
	mnHead= new int(0);
	mnTail= new int(0);
	FAT=new int[mnNumberClusters];
	setupError=setupFAT(FAT);
	//cout << "setupFAT Error: "<< setupError<< endl;
	//cout << "true: "<< true<< endl;
	string clusters= dumpClusters();
	cout << "dumpClusters: "<< clusters << endl;

	


}
/** This is a function is the getter for the head;
		 *
		 * @param void
		 * @return int
		 * @precondition  Everything linked properly
		 */
int FATCluster:: getHead()
{

	return *mnHead; // returning the value of the mnHead;
}
/** This is a function is the getter for the tail;
		 *
		 * @param void
		 * @return int
		 * @precondition  Everything linked properly
		 */

int FATCluster:: getTail()
{
	return *mnTail;
}
//getter
int FATCluster:: getClusterSize()
{
	return mnClusterSize;
}
//getter;
int FATCluster:: getNumClusters()
{

	return mnNumberClusters;
}
/** This is a function Sets up the initial FAT structure; 
	As such, it you can uncomment the cout statement to see the fat structure being
	created;
		 *
		 * @param int * fat
		 * @return bool, to tell whether it was created or not;
		 * @precondition  Everything linked properly
		 */
bool FATCluster:: setupFAT(int * fat)
{
	int i=0;

	for (;i<=mnNumberClusters-2;i++)
	{
		fat[i]=i+1;
		//cout << fat[i]<<endl;
	}
	fat[mnNumberClusters-1]=-1;
	// just keep in mind the funky assigningof head to 0; 
	// I believe it should be assigning to the first item of the array.
	*mnTail=mnNumberClusters-1;	//cout << *mnTail;
	
	return false;
}

/** This function is the constructor of the class. It begins all initial functions

	'Accepts a file size in bytes, calculates the number of clusters needed.  If there are that many
    'Clusters still available, sets up the FAT for the new file and returns the first cluster number.  If there is not enough clusters, returns -1.
    '	Compute the number of clusters needed.
    '	Check to make sure that there are that many clusters available.
    '		If No, return -1 as Starting_Cluster.
    '	Set Starting_Cluster to Head
    '	Repeat Number of Clusters -1 Times
    '		Set Head to the value of the element at Head
    '   Set Hold to the value of the element at Head
    '	Set the value of the element at Head to -1
    '	//Set Head to the value of Hold
    '	If the Value of Head is -1 (we have filled up everything)
    '		Set the Value of Tail to -1 (there is also no longer a tail!!)
    '	Return Starting_Cluster
		 *
		 * @param File_Size in Bytes: int 
		 * @return null
		 * @precondition  Everything linked properly
		 */
int FATCluster:: newFile(int nBytes)
{
	int clusterNumber= int(((nBytes)-1)/mnClusterSize)+1;
	int nHold=*mnHead;
	
	for (int i=1;i<=clusterNumber;i++)
	{
		if(FAT[nHold]==-1)
		{
			return -1;	// NO clusters left to allocate for new file;
		}
		
		
		nHold=FAT[nHold];
	}
	int startingCluster=*mnHead;
	for (int i=1;i<=clusterNumber-1;i++)
		*mnHead=FAT[*mnHead];
	nHold = FAT[*mnHead];
    FAT[*mnHead] = -1;
    *mnHead = nHold;
    
	return startingCluster;
}

/** 

'DeleteFile (Starting_Cluster) Returns Boolean
    'Accepts a Starting Cluster and returns all clusters in that chain back to the free cluster linked list.
    '	If Tail is set to -1 (then there are no free clusters)
    '		Set Tail to Starting_Cluster
    '		Return True

    '	Set Hold to Starting_Cluster
    '	Repeat
    '		Set Next to Hold
    '		Set Value of Element at Tail to Next
    '		Set Tail to Next
    '		Set Hold to Value of Element at Next
    '	Until the Value of the Element at Next = -1
    '	Return True (is there anything else that could happen?)
		 *
		 * @param Starting_Cluster: int
		 * @return bool
		 * @precondition  Cluster has been set up already
		 */

bool FATCluster:: deleteFile(int startCluster)
{
	if (*mnTail==-1)
	{
		*mnTail=startCluster;
		return true;
	}
	int nHold=startCluster;
	int next=0;
	while (next!=-1)
	{
		next=nHold;
		FAT[*mnTail]=next;	// needs some debuggin;
		*mnTail=next;
		nHold=FAT[next];
		//next++;
	}
	return true;
}
	/** 
	'AddCluster (Starting_Cluster) Returns Boolean
    'Adds a cluster to the end of a file’s linked list.  First checks to see if there is an available cluster,
	if not, returns false.  Otherwise adds the new cluster.
    'If Head is set to -1 then Return False (no more clusters)
    'Set Hold to Start_Cluster
    'Repeat
    '	Set Hold to Value of Element at Hold
    'Until the value of Hold is -1
    'Set the Value of the Element at Hold equal Head
    'Set Hold to Head
    'Set Head to the value of the Element at Head
    'Set the Value of the Element at Hold = -1
    '	If the Value of Head is -1 (we have filled up everything)
    '		Set the Value of Tail to -1 (there is also no longer a tail!!)
    'Return True
		 *
		 * @param int startCluster
		 * @return bool
		 * @precondition  Everything linked properly
		 */
bool FATCluster:: addCluster( int startCluster)
{
	if(*mnHead==-1)
	{
		return false;
	}
	int nHold=startCluster;
	int prev=startCluster;
	while (FAT[nHold]!=-1)
	{
		nHold=FAT[nHold];
		//nHold++;
	}
	
	FAT[nHold]=*mnHead;
	nHold=*mnHead;
	*mnHead=FAT[*mnHead];
	FAT[nHold]=-1;
	if(*mnHead==-1)
		*mnTail=-1;


	return true;
}

/** 'DeleteCluster (Starting_Cluster) Returns Starting_Cluster or -1
    'Deletes a cluster from the end of a file’s linked list and returns it to the free cluster list.
    'What if this is the last cluster?  We are going to return a -1 as starting cluster
    'Set Hold to Start_Cluster
    'Set Previous to -1
    'Repeat Until the value of Element at Hold is -1
    '	Set Previous to Hold
    '	Set Hold to Value of Element at Hold
    'If Previous is not equal to -1 (there was more than one cluster)
    '	Set the value of the Element at Previous to -1 (end of linked list)
    'If Tail is not equal -1 (there is at least one free cluster)
    '	Set the Value of the Element at Tail to Hold
    'Set the Value of Tail to Hold
    'If Previous is equal to -1
    '	Return -1
    'Otherwise
    '	Return Starting_Cluster
		 *
		 * @param int startCluster
		 * @return int
		 * @precondition  Everything linked properly
		 */

int FATCluster:: deleteCluster(int startCluster)
{
	int nHold=startCluster;
	int nPrev=-1;
	while (FAT[nHold]!=-1)
	{
		nPrev=nHold;
		nHold=FAT[nHold];
	}
	if (nPrev!=-1)
		FAT[nPrev]=-1;
	if (*mnTail!=-1)
		FAT[*mnTail]=nHold;
	*mnTail=nHold;
	if (nPrev==-1)
		return -1;
	else 
		return startCluster;

	//return 0;
}
/** 'GetClusters (Starting_Cluster) Returns String
    'Sends back a list of all clusters that are owned by a file based on the Starting_Cluster
    'Set FileClusters to Starting_Cluster
    'Set Hold to Starting_Cluster
    'Repeat Until the value of Element at Hold is -1
    '	Set Hold to Value of Element at Hold
    '	Set FileClusters to FileClusters concatenated with “-“ concatenated with Hold
    'Return FileClusters
		 *
		 * @param int startCluster
		 * @return string
		 * @precondition  Everything linked properly
		 */
string FATCluster:: getCluster( int startCluster)
{
	string sClusters="";
	char * buff= new char[100];
	itoa(startCluster,buff,10);
	int nHold=startCluster;
	while (FAT[nHold]!=-1)
	{
		itoa(FAT[nHold],buff,10);
		sClusters=sClusters + " "+ buff;	
		nHold=FAT[nHold];
	}


	return sClusters;
}
/** 'DumpClusters() Returns String
    'Sends back a string with all free clusters
    'If Head  is -1 then
    '	Return Empty String (There are no free clusters!!)
    'Set Hold to Head
    'Set sClusters to “”
    'Repeat until the value of the Element at Hold is -1
    '	Set sClusters to sClusters & “ “ & the value of the Element at Hold
    'Return sClusters
		 * @param void
		 * @return string
		 * @precondition  Everything linked properly
		 */
string FATCluster:: dumpClusters()
{
	int hold=*mnHead;
	string sClusters="";
	char * buff=new char[100];
	while (hold!=-1)
	{
		itoa(FAT[hold],buff,10);
		sClusters=sClusters+buff+" ";
		hold=FAT[hold];	// incrementer;

	}

	

	return sClusters;
}
/** 'Write Clusters() Returns String
    'Sends back a string with the entire FAT to be written to a file.
    'Set sClusters to “”
    'For I = 0 to Number of Clusters – 1
    '	Set sClusters to sClusters & the value of the Element at I
    'Return sClusters
		 *
		 * @param void
		 * @return string
		 * @precondition  Everything linked properly
		 */
string FATCluster:: writeClusters()
{
	string sClusters="";
	char * buff= new char[100];
	
	int nHold=*mnHead;
	for (int i=0;i<mnNumberClusters;i++)
	{
		itoa(FAT[i],buff,10);
		sClusters=sClusters+ buff+ " ";
	}
	itoa(nHold,buff,10);
	sClusters=sClusters+ " "+ buff;
	itoa(*mnTail,buff,10);
	sClusters=sClusters+ " "+ buff;

	return sClusters;
}
/** 'Read Clusters(String psCluster) Returns Boolean
    'The Cluster Array from the disk is passed in and reloaded into the FAT
    'Set FAT equal to  psCluster.Split(“ “)
    '(If your selected language doesn’t include a split, you will need to go into a look an pull off the elements and store them in the FAT table.)
    'Return True if load was successful.
		 *
		 * @param string clusters
		 * @return bool
		 * @precondition  Everything linked properly
		 */
bool FATCluster:: readClusters( string clusters)
{

	return true;
}





// private

